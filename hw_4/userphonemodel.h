#ifndef USERPHONEMODEL_H
#define USERPHONEMODEL_H

#include <pqxx/pqxx>

#include <string>
#include <vector>


class UserPhoneModel
{
public:
    UserPhoneModel();

    std::tuple<bool, std::string> create_table();

    std::tuple<bool, std::string> drop_table();

    std::tuple<bool, std::string> add_phone(const std::string& user_id,
                                            const std::string& value,
                                            std::string id);

    std::tuple<bool, std::string> get_phones_by_user_id(const std::string& user_id,
                                                        std::vector<std::vector<std::string>>& data);

    std::tuple<bool, std::string> delete_phone(const std::string& id);
};

#endif // USERPHONEMODEL_H
