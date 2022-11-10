#include "map.hpp"

void Map::read_from_file(string filename) {
    _file.open(filename);

    if (!_file.is_open()) throw map_exc::file_not_found(filename.c_str());

    int key, val, line = 1, aux;
    list<int> temp;

    while (_file >> key >> val) {
        try {
            if (find(key, aux)) throw map_exc::key_in_use(key);
            for (list<int>::iterator it = temp.begin(); it != temp.end(); advance(it, 2)) {
                if (*it == key) {
                    throw map_exc::key_in_use(key);
                }
            }

            temp.push_back(key);
            temp.push_back(val);
            line++;
        } catch (map_exc::key_in_use& e) {
            _file.close();
            throw map_exc::invalid_map_in_file(filename.c_str(), line, key);
        }
    }

    _list.insert(_list.end(), temp.begin(), temp.end());

    _file.close();
}

bool Map::find(int key, int& found_val) {
    for (list<int>::iterator it = _list.begin(); it != _list.end(); advance(it, 2)) {
        if (*it == key) {
            found_val = *(next(it, 1));
            return true;
        }
    }

    return false;
}

void Map::insert(int key, int val) {
    int aux;
    if (find(key, aux)) throw map_exc::key_in_use(key);
    _list.push_back(key);
    _list.push_back(val);
}

void Map::remove(int key) {
    int aux_val;
    if (!find(key, aux_val)) throw map_exc::key_not_found(key);

    for (list<int>::iterator it = _list.begin(); it != _list.end(); advance(it, 2)) {
        if (*it == key) {
            _list.erase(next(it, 1));
            _list.erase(it);
            return;
        }
    }
}

void Map::print() {
    cout << "========================" << endl;
    for (list<int>::iterator it = _list.begin(); it != _list.end(); advance(it, 2)) {
        cout << "<" << *it << "," << *(next(it, 1)) << ">" << endl;
    }
    cout << "========================" << endl;
}