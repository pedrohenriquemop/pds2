#ifndef MAP_EXC_H
#define MAP_EXC_H

#include <string>

using namespace std;

namespace map_exc {

class key_in_use {
   private:
    int _key;

   public:
    key_in_use(int key) {
        _key = key;
    }
    const char* what() const throw() {
        return "Key in use";
    }
    int get_key() {
        return _key;
    }
};

class key_not_found {
   private:
    int _key;

   public:
    key_not_found(int key) {
        _key = key;
    }
    const char* what() const throw() {
        return "Key not found";
    }
    int get_key() {
        return _key;
    }
};

class file_not_found {
   private:
    string _file_name;

   public:
    file_not_found(const char* file_name) {
        _file_name = file_name;
    }
    const char* what() const throw() {
        return "File not found";
    }
    const char* get_file_name() {
        return _file_name.c_str();
    }
};

class invalid_map_in_file {
   private:
    int _line, _key;
    string _file_name;

   public:
    invalid_map_in_file(const char* file_name, int line, int key) {
        _line = line;
        _key = key;
        _file_name = file_name;
    }
    const char* what() const throw() {
        return "Invalid Map in File";
    }
    const char* get_file_name() {
        return _file_name.c_str();
    }
    int get_line() {
        return _line;
    }
    int get_key() {
        return _key;
    }
};

}  // namespace map_exc

#endif