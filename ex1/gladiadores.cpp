#include <iostream>
#include <string>
#include <cmath>
using namespace std;

struct Gladiadores
{
    string nome;
    int forca;
    int habilidade;
    int idade;
};

bool combate(Gladiadores g1, Gladiadores g2) {
    int vida1 = 100;
    int vida2 = 100;

    int dano1 = g1.forca + pow(2, g1.habilidade);
    int dano2 = g2.forca + pow(2, g2.habilidade);

    while (vida1 > 0 && vida2 > 0) {
        vida2 -= dano1;
        if (vida2 <= 0)
            return 0;

        vida1 -= dano2;
        if (vida1 <= 0)
            return 1;
    }
    return false;
}

int main() {

    Gladiadores gladiador[5];
    int escolha1, escolha2;


    cin.ignore();
    for (int i = 0; i < 5; i++)
    {
        getline(cin, gladiador[i].nome);
        cin >> gladiador[i].forca;
        cin >> gladiador[i].habilidade;
        cin >> gladiador[i].idade;
        cin.ignore();
    }

    while (true)
    {
        cin >> escolha1;
        if(escolha1 == -1){
            break;
        }
        cin >> escolha2;
        if (escolha2 == -1)
        {
            break;
        }
        else {
            bool venceu = combate(gladiador[escolha1], gladiador[escolha2]);

            if (venceu)
                cout << gladiador[escolha1].nome << " ganhou a batalha contra " << gladiador[escolha2].nome << endl;
            else
                cout << gladiador[escolha2].nome << " ganhou a batalha contra " << gladiador[escolha1].nome << endl;
        }
    }

    return 0;

    //Complexidade total do programa O(n) para ler os dados dos gladiadores e O(1) para cada combate, resultando em O(n) + O(1) = O(n) no pior caso, onde n é o número de gladiadores.
    
}