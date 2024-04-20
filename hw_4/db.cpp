#include "db.h"

#include <string>
#include <sstream>

std::string get_connection_string() {
    std::stringstream ss;
    ss << "host=" << HOST << " ";
    ss << "port=" << PORT << " ";
    ss << "dbname=" << DB_NAME << " ";
    ss << "user=" << USER << " ";
    ss << "password=" << PASSWORD;
    return ss.str();
}
