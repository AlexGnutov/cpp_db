#ifndef DB_H
#define DB_H

#include <string>
#include <sstream>

const std::string HOST = "localhost";
const std::string PORT = "5432";
const std::string DB_NAME = "hw4_db";
const std::string USER = "postgres";
const std::string PASSWORD = "postgres";

std::string get_connection_string();

#endif // DB_H
