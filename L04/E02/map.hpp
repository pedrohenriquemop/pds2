#ifndef MAP_H
#define MAP_H

#include <fstream>
#include <iostream>
#include <list>
#include <string>

#include "map_exceptions.hpp"

using namespace std;

class Map {
   private:
    ifstream _file;
    list<int> _list;

   public:
    void read_from_file(string filename);

    bool find(int key, int &found_val);

    void insert(int key, int val);

    void remove(int key);

    void print();
};

#endif