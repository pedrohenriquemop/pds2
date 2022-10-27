#include <iostream>

using namespace std;

class Item {
   private:
    int _key, _val;

   public:
    Item() : Item(0, 0) {}

    Item(int key, int val) {
        _key = key;
        _val = val;
    }

    friend bool operator>(const Item &i1, const Item &i2) {
        return i1._val > i2._val;
    }

    friend ostream &operator<<(ostream &out, const Item &i) {
        return out << "(" << i._key << "," << i._val << ")";
    }
};
