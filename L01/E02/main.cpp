#include <iostream>
#include <string>
#include <algorithm> 

using namespace std;

int main()
{
    int qtd;
    cin >> qtd;
    char letters[qtd];
    int occurences[qtd];
    fill_n(occurences, qtd, 0);
    for(int i = 0; i < qtd; i++){
        cin >> letters[i];
    }
    getchar();
    string word;
    getline(cin, word);
    for(int i = 0; (unsigned) i < word.length(); i++){
        for(int j = 0; j < qtd; j++){
            if(letters[j] == word[i]){
                word[i] = '#';
                occurences[j]++;
            }
        }
    }
    cout << word << endl;
    for(int i = 0; i < qtd; i++){
        cout << letters[i] << " " << occurences[i] << endl;
    }
}