#include "userphonemodel.h"

#include <sstream>
#include <iostream>

#include "db.h"


UserPhoneModel::UserPhoneModel()
{

}

std::tuple<bool, std::string> UserPhoneModel::create_table()
{
    try {
        pqxx::connection db_connection(get_connection_string());
        pqxx::work tx{db_connection};

        std::stringstream ss;
        ss << "CREATE TABLE userphones (";
        ss << "id serial primary key,";
        ss << "user_id serial references users(id) ON DELETE CASCADE,";
        ss << "phone varchar(255) NOT NULL)";

        pqxx::result res = tx.exec(ss.str());
        tx.commit();

        return {true, "CREATE TABLE userphones"};
    } catch(std::exception const &e) {
        return {false, e.what()};
    }
}

std::tuple<bool, std::string> UserPhoneModel::drop_table() {
    try {
        pqxx::connection db_connection(get_connection_string());
        pqxx::work tx{db_connection};

        pqxx::result res = tx.exec("DROP TABLE IF EXISTS userphones");
        tx.commit();

        return {true, "DROP TABLE user"};
    } catch(std::exception const &e) {
        return {false, e.what()};
    }
}

std::tuple<bool, std::string> UserPhoneModel::add_phone(const std::string &user_id,
                                                        const std::string &value,
                                                        std::string id)
{
    try {
        pqxx::connection db_connection(get_connection_string());
        pqxx::work tx{db_connection};

        pqxx::result res = tx.exec("INSERT INTO userphones (user_id, phone) values ("
                                   + tx.quote(user_id) + ","
                                   + tx.quote(value) + ") RETURNING id");
        tx.commit();

        if (res.empty()) {
            return {false, "Пустой ответ"};
        }

        for (auto row : res) {
            id = row[0].c_str();
        }

        return {true, "телефон добавлен"};
    } catch(std::exception const &e) {
        return {false, e.what()};
    }


}

std::tuple<bool, std::string> UserPhoneModel::get_phones_by_user_id(const std::string &user_id,
                                                                    std::vector<std::vector<std::string>> &data)
{
    try {
        pqxx::connection db_connection(get_connection_string());
        pqxx::work tx{db_connection};

        pqxx::result res = tx.exec("SELECT * FROM userphones WHERE user_id=" + tx.esc(user_id));
        tx.commit();

        for (auto row : res) {
            std::vector<std::string> line = {};
            for (auto cell : row) {
                line.push_back(cell.c_str());
            }
            data.push_back(line);
        }

        return {true, ""};
    } catch(std::exception const &e) {
        return {false, e.what()};
    }
}

std::tuple<bool, std::string> UserPhoneModel::delete_phone(const std::string &id)
{
    try {
        pqxx::connection db_connection(get_connection_string());
        pqxx::work tx{db_connection};

        pqxx::result res = tx.exec("DELETE FROM userphones WHERE id=" + tx.esc(id));
        tx.commit();

        return {true, "телефон удалён"};
    } catch(std::exception const &e) {
        return {false, e.what()};
    }
}
