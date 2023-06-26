#include <iostream>
#include <cctype>

#define MAX 15

using namespace std;

void enfileirar(char v[], int& fim, char valor);
char desenfileirar(char v[], int& ini, int fim);
void empilhar(char pilha[], int& topo, char valor);
char desempilhar(char pilha[], int& topo);

int main() {
    char sequencia[MAX];
    cout << "Digite a sequencia de caracteres: ";
    cin.getline(sequencia, MAX);

    char fila[MAX];
    int iniFila = 0, fimFila = -1;
    char pilha[MAX];
    int topoPilha = -1;

    int i = 0;
    while (sequencia[i] != '\0') {
        enfileirar(fila, fimFila, sequencia[i]);
        i++;
    }

    while (iniFila <= fimFila) {
        char caractere = desenfileirar(fila, iniFila, fimFila);
        if (isalpha(caractere)) {
            caractere = toupper(caractere);
        }
        empilhar(pilha, topoPilha, caractere);
    }

    cout << "Valores desempilhados: ";
    while (topoPilha >= 0) {
        char caractere = desempilhar(pilha, topoPilha);
        cout << caractere << " ";
    }

    return 0;
}

void enfileirar(char v[], int& fim, char valor) {
    fim++;
    v[fim] = valor;
}

char desenfileirar(char v[], int& ini, int fim) {
    char valor = v[ini];
    ini++;
    return valor;
}

void empilhar(char pilha[], int& topo, char valor) {
    topo++;
    pilha[topo] = valor;
}

char desempilhar(char pilha[], int& topo) {
    char valor = pilha[topo];
    topo--;
    return valor;
}
