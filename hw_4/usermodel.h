#ifndef USERMODEL_H
#define USERMODEL_H

#include <pqxx/pqxx>

#include <string>
#include <vector>

class UserModel
{
public:
    UserModel();

    std::tuple<bool,std::string> create_table();

    std::tuple<bool,std::string> drop_table();

    std::tuple<bool, std::string> add_user(const std::string& first_name,
                                           const std::string& family_name,
                                           const std::string& email,
                                           std::string& id);

    std::tuple<bool, std::string> update_user(const std::string& id, const std::string& field, const std::string&value);

    std::tuple<bool, std::string> get_all(std::vector<std::vector<std::string>>& data);

    std::tuple<bool, std::string> find_by(const std::string& field,
                                          const std::string& value,
                                          std::vector<std::vector<std::string>>& data);

    std::tuple<bool, std::string> delete_user(const std::string& id);

};

#endif // USERMODEL_H
