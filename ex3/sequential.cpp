#include <iostream>
#include <string>
using namespace std;

struct Produtos {
    string tipo;
    int quantidade;
};

int buscaSequencial(Produtos v[], int n, string chave) {
    for (int i = 0; i < n; i++) {
        if (v[i].tipo == chave) {
            return i; // posição onde encontrou
        }
    }
    return -1; // não encontrou
}

int main() {

    int n;
    string procurado;
    cin >> n;

    Produtos* produtos = new Produtos[n];

    cin.ignore(); // limpa o buffer

    for (int i = 0; i < n; i++) {
        getline(cin, produtos[i].tipo);
        cin >> produtos[i].quantidade;
        cin.ignore(); // limpa para próxima leitura
    }

    getline(cin, procurado);

    int posicao = buscaSequencial(produtos, n, procurado);

    if (posicao != -1) {
        cout << produtos[posicao].tipo << " em estoque" << endl;
    } else {
        cout << "Nao existe " << procurado << " em estoque" << endl;
    }

    delete[] produtos; // libera memória

    return 0;
}


