#include <iostream>

#include "usermodel.h"
#include "userphonemodel.h"

#include <string>
#include <vector>


int main()
{
    std::cout << "Databases HW4" << std::endl;

    UserModel users;
    UserPhoneModel userphones;

    bool ok;
    std::string msg;

    // Удаление таблиц
    std::tie(ok, msg) = userphones.drop_table();
    std::cout << ok << " " << msg << std::endl;

    std::tie(ok, msg) = users.drop_table();
    std::cout << ok << " " << msg << std::endl;

    // Создание таблиц
    std::tie(ok, msg) = users.create_table();
    std::cout << ok << " " << msg << std::endl;

    std::tie(ok, msg) = userphones.create_table();
    std::cout << ok << " " << msg << std::endl;

    // Добавление пользователя
    {
        std::string id;
        std::string n = "Ivan";
        std::string fn = "Bravy";
        std::string em = "ib@ib.ru";
        std::tie(ok, msg) = users.add_user(n, fn, em, id);
        std::cout << ok << " " << msg << " " << id << std::endl;
    }

    // Добавление и модификация пользователя
    {
        std::string id;
        std::string n = "Maria";
        std::string fn = "List";
        std::string em = "ml@ml.ru";
        std::tie(ok, msg) = users.add_user(n, fn, em, id);
        std::cout << ok << " " << msg << " " << id << std::endl;

        std::string f = "first_name";
        std::string nn = "Nadya";
        std::tie(ok, msg) = users.update_user(id, f, nn);
        std::cout << ok << " " << msg << std::endl;
    }

    // Поиск пользователя
    {
        std::vector<std::vector<std::string>> data = {};
        std::string f = "first_name";
        std::string v = "Nadya";
        std::tie(ok, msg) = users.find_by(f,v,data);
        std::cout << ok << " " << msg << std::endl;
        for (auto& row : data) {
            for (auto& cell : row) {
                std::cout << cell.c_str() << " ";
            }
            std::cout << std::endl;
        }
    }

    // Удаление пользователя
    {
        std::vector<std::vector<std::string>> data = {};
        std::tie(ok, msg) = users.get_all(data);
        std::cout << ok << " " << msg << " пользователей: " << data.size() << std::endl;

        std::string id = "2";
        std::tie(ok, msg) = users.delete_user(id);
        std::cout << ok << " " << msg << std::endl;

        data.clear();
        std::tie(ok, msg) = users.get_all(data);
        std::cout << ok << " " << msg << " пользователей: " << data.size() << std::endl;
    }

    // Добавление телефонов
    {
        std::string user_id = "1";

        std::string id_1;
        std::string phone_1 = "322-223";
        std::tie(ok, msg) = userphones.add_phone(user_id, phone_1, id_1);
        std::cout << ok << " " << msg << " " << id_1 << std::endl;

        std::string id_2;
        std::string phone_2 = "3-15-10-20";
        std::tie(ok, msg) = userphones.add_phone(user_id, phone_2, id_2);
        std::cout << ok << " " << msg << " " << id_2 << std::endl;
    }

    // Получение телефонов
    {
        std::vector<std::vector<std::string>> data = {};
        std::string user_id = "1";
        std::tie(ok, msg) = userphones.get_phones_by_user_id(user_id, data);

        std::cout << ok << " " << msg << std::endl;
        for (auto& row : data) {
            for (auto& cell : row) {
                std::cout << cell.c_str() << " ";
            }
            std::cout << std::endl;
        }
    }

    // Удаление телефона
    {
        std::string id_2 = "2";

        std::tie(ok, msg) = userphones.delete_phone(id_2);
        std::cout << ok << " " << msg << std::endl;

        std::vector<std::vector<std::string>> data = {};
        std::string user_id = "1";

        std::tie(ok, msg) = userphones.get_phones_by_user_id(user_id, data);
        std::cout << ok << " " << msg << std::endl;

        for (auto& row : data) {
            for (auto& cell : row) {
                std::cout << cell.c_str() << " ";
            }
            std::cout << std::endl;
        }
    }



    return 0;
}
