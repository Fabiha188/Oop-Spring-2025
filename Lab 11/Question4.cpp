#include <iostream>
#include <exception>
#include <cstring>

class DatabaseException : public std::exception {
private:
    const char* msg;
public:
    DatabaseException() : msg("data base error.") {}
    const char* what() const noexcept override {
        return msg;
    }
};

class ConnectionFailedException : public DatabaseException {};

class QueryTimeoutException : public DatabaseException {};

template <typename T>
class DatabaseConnector {
private:
    T db_name;

public:
    DatabaseConnector(T name) : db_name(name) {}

    void connect() {
        if (db_name == "invalid_db") {
            throw ConnectionFailedException();
        } else if (db_name == "slow_db") {
            throw QueryTimeoutException();
        } else {
            std::cout << "Connected to " << db_name << " successfully.\n";
        }
    }
};

int main() {
    try {
        std::cout << "Attempting to connect to invalid_db...\n";
        DatabaseConnector<std::string> conn1("invalid_db");
        conn1.connect();
    }
    catch (const ConnectionFailedException& e) {
        std::cout << "Caught ConnectionFailedException what(): " << e.what() << std::endl;
    }

    try {
        std::cout << "Attempting to connect to slow_db...\n";
        DatabaseConnector<std::string> conn2("slow_db");
        conn2.connect();
    }
    catch (const DatabaseException& e) {
        std::cout << "Caught a general DatabaseException what(): " << e.what() << std::endl;
    }

    return 0;
}
