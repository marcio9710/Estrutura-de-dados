#include <iostream>
#include <cctype>

#define MAX 10

using namespace std;

void enfileirarChar(char v[], int& fim, char valor);
void enfileirarInt(int v[], int& fim, int valor);
void desenfileirarChar(char v[], int& ini, int fim, char& valor);
void desenfileirarInt(int v[], int& ini, int fim, int& valor);

int main() {
    char sequencia[MAX];
    cout << "Digite a sequencia de caracteres: ";
    cin.getline(sequencia, MAX);

    char filaA[MAX];
    int iniA = 0, fimA = -1;
    int filaB[MAX];
    int iniB = 0, fimB = -1;

    int i = 0;
    while (sequencia[i] != '\0') {
        if (isalpha(sequencia[i])) {
            enfileirarChar(filaA, fimA, sequencia[i]);
        } else if (isdigit(sequencia[i])) {
            int valor = sequencia[i] - '0';
            enfileirarInt(filaB, fimB, valor);
        }
        i++;
    }

    cout << "Valores desenfileirados de B e A ";
    while (iniB <= fimB) {
        int valorB;
        desenfileirarInt(filaB, iniB, fimB, valorB);
        cout << valorB << " ";
    }
    while (iniA <= fimA) {
        char valorA;
        desenfileirarChar(filaA, iniA, fimA, valorA);
        cout << valorA << " ";
    }

    return 0;
}

void enfileirarChar(char v[], int& fim, char valor) {
    fim++;
    v[fim] = valor;
}

void enfileirarInt(int v[], int& fim, int valor) {
    fim++;
    v[fim] = valor;
}

void desenfileirarChar(char v[], int& ini, int fim, char& valor) {
    valor = v[ini];
    ini++;
}

void desenfileirarInt(int v[], int& ini, int fim, int& valor) {
    valor = v[ini];
    ini++;
}
