#include <iostream>
using namespace std;
#define MAX 10

int enfileirar(int fila[], int &ffila, int valor);
int desenfileirar(int fila[], int &ifila, int ffila, int &valor);
void ImpriMultCinco(int fila[], int ifila, int ffila);

int main(void) {

    
    int fila[MAX];
    int ifila = 0;
    int ffila = -1;

    int escolha, valor;

    do {
        cout << "Menu:\n";
        cout << "1. Enfileirar um numero inteiro positivo\n";
        cout << "2. Desenfileirar todos e imprimir múltiplos de 5\n";
        cout << "3. Finalizar programa\n";
        cout << "Escolha uma opcao: ";
        cin >> escolha;

        switch (escolha) {
            case 1:
                cout << "Informe um numero: ";
                cin >> valor;
                if (valor > 0) {
                    if (enfileirar(fila, ffila, valor) == 1) {
                        cout << "A fila esta cheia\n";
                    }
                } else {
                    cout << "Numero invalido. informe um numero inteiro positivo.\n";
                }
                break;
            case 2:
                ImpriMultCinco(fila, ifila, ffila);
                break;
            case 3:
                cout << "Programa finalizado.\n";
                break;
            default:
                cout << "Opcao invalida. Escolha novamente.\n";
                break;
        }

        cout << endl;
    } while (escolha != 3);
}

int enfileirar(int fila[], int &ffila, int valor) {
    if (ffila >= MAX-1) return 1;
    ffila++;
    fila[ffila] = valor;

    return 0;
}

int desenfileirar(int fila[], int &ifila, int ffila, int &valor) {
    if (ffila < ifila) return 1;

    valor = fila[ifila];
    ifila++;

    return 0;
}

void ImpriMultCinco(int fila[], int ifila, int ffila) {
    cout << "Múltiplos de 5:\n";
    int valor;
    while (desenfileirar(fila, ifila, ffila, valor) == 0) {
        if (valor % 5 == 0) {
            cout << valor << endl;
        }
    }
}
