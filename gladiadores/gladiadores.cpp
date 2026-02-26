#include<iostream>
using namespace std;

struct Gladiador{
   	string nome;
   	int forca, habilidade, idade, vida;
};

int potencia(int base, int exp) {
	if (exp == 0) return 1;
	if (exp == 1) return base;
	return base * potencia(base, exp - 1);
}

int ataque(Gladiador gladiador) {
	return gladiador.forca + potencia(2, gladiador.habilidade);
}

bool combate(Gladiador gladiador1, Gladiador gladiador2) {
	while (gladiador1.vida > 0 && gladiador2.vida > 0) {
		gladiador2.vida -= ataque(gladiador1);
		gladiador1.vida -= ataque(gladiador2);
	}
	if (gladiador2.vida <= 0) return true;
	else return false;
}

int main(){
	string nome;
	int forca, habilidade, idade, tamanho=0, gladiador1, gladiador2,x;
	Gladiador gladiadores[1000];

    cin >> x;
    while (x != 3)
    {
        if (x == 1)
        {
            cin >> nome >> forca >> habilidade >> idade;
            gladiadores[tamanho] = {nome, forca, habilidade, idade, 100};
            tamanho++;
        }
        else if (x == 2)
        {
            if(tamanho < 2){
                cout << "Adicione pelo menos 2 gladiadores." << endl;
                cin >> x;
                continue;
            }

            cin >> gladiador1 >> gladiador2;
            if (combate(gladiadores[gladiador1], gladiadores[gladiador2])) {
                cout << gladiadores[gladiador1].nome << " ganhou batalha contra ";
                cout << gladiadores[gladiador2].nome << "." << endl;
            } else {
                cout << gladiadores[gladiador2].nome << " ganhou batalha contra ";
                cout << gladiadores[gladiador1].nome << "." << endl;
            }
        }
        else {
            cout << "Comando invalido." << endl;
        }

        cin >> x;

    }
    
	return 0;

}