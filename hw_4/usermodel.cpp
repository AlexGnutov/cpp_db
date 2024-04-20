#include "usermodel.h"

#include <sstream>
#include <iostream>

#include "db.h"


UserModel::UserModel()
{

}

std::tuple<bool, std::string> UserModel::create_table() {
    try {
        pqxx::connection db_connection(get_connection_string());
        pqxx::work tx{db_connection};

        std::stringstream ss;
        ss << "CREATE TABLE users (";
        ss << "id serial primary key,";
        ss << "first_name varchar(255),";
        ss << "family_name varchar(255),";
        ss << "email varchar(255))";

        pqxx::result res = tx.exec(ss.str());
        tx.commit();

        return {true, "CREATE TABLE users"};
    } catch(std::exception const &e) {
        return {false, e.what()};
    }
}

std::tuple<bool, std::string> UserModel::drop_table() {
    try {
        pqxx::connection db_connection(get_connection_string());
        pqxx::work tx{db_connection};

        pqxx::result res = tx.exec("DROP TABLE IF EXISTS users");
        tx.commit();

        return {true, "DROP TABLE users"};
    } catch(std::exception const &e) {
        return {false, e.what()};
    }
}

std::tuple<bool, std::string> UserModel::add_user(const std::string &first_name,
                                                  const std::string &family_name,
                                                  const std::string &email,
                                                  std::string& id) {
    try {
        pqxx::connection db_connection(get_connection_string());
        pqxx::work tx{db_connection};

        pqxx::result res = tx.exec("INSERT INTO users (first_name, family_name, email) values ("
                                   + tx.quote(first_name) + ","
                                   + tx.quote(family_name) + ","
                                   + tx.quote(email) + ") RETURNING id");
        tx.commit();

        if (res.empty()) {
            return {false, "Пустой ответ"};
        }

        for (auto row : res) {
            id = row[0].c_str();
        }

        return {true, "пользователь добавлен"};
    } catch(std::exception const &e) {
        return {false, e.what()};
    }
}

std::tuple<bool, std::string> UserModel::update_user(const std::string &id, const std::string &field, const std::string &value) {
    try {
        pqxx::connection db_connection(get_connection_string());
        pqxx::work tx{db_connection};

        pqxx::result res = tx.exec("UPDATE users SET " + tx.esc(field) + "=" + tx.quote(value) + " WHERE id=" + tx.esc(id));
        tx.commit();

        return {true, "пользователь изменен"};
    } catch(std::exception const &e) {
        return {false, e.what()};
    }
}

std::tuple<bool, std::string> UserModel::get_all(std::vector<std::vector<std::string>>& data) {
    try {
        pqxx::connection db_connection(get_connection_string());
        pqxx::work tx{db_connection};

        pqxx::result res = tx.exec("SELECT * FROM users");
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


std::tuple<bool, std::string> UserModel::find_by(const std::string& field,
                                                 const std::string& value,
                                                 std::vector<std::vector<std::string>>& data) {
    try {
        pqxx::connection db_connection(get_connection_string());
        pqxx::work tx{db_connection};

        pqxx::result res = tx.exec("SELECT * FROM users WHERE " + tx.esc(field) + "=" + tx.quote(value));
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

std::tuple<bool, std::string> UserModel::delete_user(const std::string &id) {
    try {
        pqxx::connection db_connection(get_connection_string());
        pqxx::work tx{db_connection};

        pqxx::result res = tx.exec("DELETE FROM users WHERE id=" + tx.esc(id));
        tx.commit();

        return {true, "пользователь удалён"};
    } catch(std::exception const &e) {
        return {false, e.what()};
    }
}
