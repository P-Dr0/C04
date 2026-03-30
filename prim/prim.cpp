#include <iostream>
#include <list>
#define INF 999999
using namespace std;
struct Aresta{
  int origem, destino, peso;
};

int prim_lista(list<Aresta> grafo[], int vertices, int origem){  // 6 vertices, origem em 0
  bool visitado[vertices];// vai controlar se foi visitado ou não
  int pai[vertices], distancia[vertices], atual;
  for(int i=0; i<vertices; i++){
    visitado[i] = false;// começa com todas as posições não visitadas
    pai[i] = -1;// indicando que esse vértice de origem não tem pai, não venho ninguém antes
    distancia[i] = INF;// porque ainda não tenho a distante de um nó ao outro
  }
  atual = origem;
  distancia[atual] = 0;// posição da distância a origem é 0, sem distância
  while(!visitado[atual]){ // verifica se foi visitado ou não
    visitado[atual] = true;// visita o nó na origem, posição 0
    list<Aresta>::iterator it;
    for(it=grafo[atual].begin();it!=grafo[atual].end();it++){// verifica as adjacências do numero atual
      int d = it->destino, p = it->peso;// d é o nó para qual o nó vai, e o p guarda o peso dessa aresta
      if(!visitado[d] && p < distancia[d]){// se não foi visitado e o peso for menor do que a distancia
        distancia[d] = p;
        pai[d] = atual;// recebe o vértice atual
      }
    }
    int menor_distancia = INF;
    for(int i=0; i<vertices; i++){
      if(!visitado[i] && distancia[i] < menor_distancia){
        menor_distancia = distancia[i];
        atual = i;
      }
    }
  }
  int peso_mst = 0;
  for(int i=0; i<vertices; i++){
    peso_mst += distancia[i];
  }
  return peso_mst;
}



int main(){
  int vertices, arestas, origem, destino, peso;
  cin >> vertices;
  list<Aresta> grafo[vertices];
  cin >> arestas;
  for(int i=0; i<arestas; i++){
    cin >> origem >> destino >> peso;
    grafo[origem].push_back({origem, destino, peso});
    grafo[destino].push_back({destino, origem, peso});
  }
  for(int i=0; i<vertices; i++){
    list<Aresta>::iterator it;
    cout << i << ": ";
    for(it = grafo[i].begin(); it != grafo[i].end(); it++){
      cout << "(";
      cout << it->destino << "," << it->peso;
      cout << "), ";
    }
    cout<<endl;
  }

  cout << prim_lista(grafo, vertices, 0);
}

/**
6 -- vertice
10 -- arestas
origem, destino, peso: -- grafo
0 1 6  
0 2 1
0 3 5
1 2 2
1 4 5
2 3 2
2 4 6
2 5 4
3 5 4
4 5 3

*/