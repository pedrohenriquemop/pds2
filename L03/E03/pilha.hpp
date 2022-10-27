#include <iostream>

using namespace std;

template <class T>
class Pilha {
   private:
    T* _arr;
    int _max_tam;
    int _top;

   public:
    Pilha(int max_tam) {
        _arr = new T;
        _max_tam = max_tam;
        _top = -1;
    }

    ~Pilha() {
        delete _arr;
    }

    bool push(const T& novo_e) {
        if (_top + 1 >= _max_tam) return false;
        _top++;
        _arr[_top] = novo_e;
        return true;
    }

    bool pop(T& valor) {
        if (_top < 0) return false;
        valor = _arr[_top];
        _top--;
        return true;
    }

    bool get_maior(T& valor) {
        if (_top < 0) return false;
        T maior = _arr[0];
        for (int i = 1; i <= _top; i++) {
            if (_arr[i] > _arr[i - 1]) {
                maior = _arr[i];
            }
        }
        valor = maior;
        return true;
    }

    bool vazia() {
        return _top < 0;
    }

    void print() {
        for (int i = 0; i <= _top; i++) {
            cout << _arr[i] << endl;
        }
    }
};