#include <iostream>
#include <string>

#include "map.hpp"

using namespace std;

int main() {
    Map map;

    string opcao;

    while (cin >> opcao) {
        if (opcao == "i") {
            try {
                int key, val;
                cin >> key >> val;
                map.insert(key, val);
            } catch (map_exc::key_in_use& e) {
                cout << e.what() << " key = " << e.get_key() << endl;
            }
        }
        if (opcao == "f") {
            int key, val;
            cin >> key;
            if (map.find(key, val))
                cout << "found " << val << " in key " << key << endl;
            else
                cout << "key " << key << " not found" << endl;
        }
        if (opcao == "r") {
            try {
                int key;
                cin >> key;
                map.remove(key);
            } catch (map_exc::key_not_found& e) {
                cout << e.what() << " key = " << e.get_key() << endl;
            }
        }
        if (opcao == "p") {
            map.print();
        }
        if (opcao == "r_f") {
            try {
                string filename;
                cin >> filename;
                map.read_from_file(filename);
            } catch (map_exc::invalid_map_in_file& e) {
                cout << e.what() << " " << e.get_file_name() << " Key " << e.get_key() << " in line " << e.get_line() << endl;
            } catch (map_exc::file_not_found& e) {
                cout << e.what() << " " << e.get_file_name() << endl;
            }
        }
    }
    return 0;
}