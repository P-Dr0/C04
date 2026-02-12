#include <iostream>
using namespace std;

struct Inseto {
    string nome;
    int tamanho;
};

void insertionSort(Inseto insetos[], int n) {
    for (int i = 1; i < n; i++) {
        Inseto chave = insetos[i];
        int j = i - 1;

        while (j >= 0 && insetos[j].tamanho > chave.tamanho) {
            insetos[j + 1] = insetos[j];
            j--;
        }
        insetos[j + 1] = chave;
    }
}

int main() {
    int n;
    cin >> n;
    cin.ignore();

    Inseto* insetos = new Inseto[n];

    for (int i = 0; i < n; i++) {
        getline(cin, insetos[i].nome);
        cin >> insetos[i].tamanho;
        cin.ignore();
    }

    insertionSort(insetos, n);

    for (int i = 0; i < n; i++) {
        cout << insetos[i].nome << endl;
    }

    delete[] insetos;
    
    return 0;
}
