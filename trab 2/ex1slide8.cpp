#include <iostream>

using namespace std;

const int MAX_SIZE = 10;

int enfileirar(int fila[], int& ffila, int valor);
int desenfileirar(int fila[], int& ifila, int ffila, int& valor);
void exibirFila(const int fila[], int ifila, int ffila);

int main() {
    int fila[MAX_SIZE];
    int ifila = 0;
    int ffila = 0;
    int opcao;

    do {
        cout << "\nMenu:\n";
        cout << "1. Enfileirar um numero inteiro positivo\n";
        cout << "2. Desenfileirar um numero e imprimir o seu dobro\n";
        cout << "3. Desenfileirar tudo, exibindo os valores sem alteracoes\n";
        cout << "4. Terminar o programa\n";
        cout << "Escolha uma opcao: ";
        cin >> opcao;

        switch (opcao) {
            case 1: {
                int numero;
                cout << "Digite um numero inteiro positivo: ";
                cin >> numero;
                if (numero > 0) {
                    enfileirar(fila, ffila, numero);
                } else {
                    cout << "Numero invalido. Apenas numeros inteiros positivos sao permitidos.\n";
                }
                break;
            }
            case 2: {
                int valor;
                desenfileirar(fila, ifila, ffila, valor);
                break;
            }
            case 3:
                exibirFila(fila, ifila, ffila);
                break;
            case 4:
                cout << "Programa encerrado.\n";
                break;
            default:
                cout << "Opcao invalida. Por favor, escolha uma opcao valida.\n";
                break;
        }
    } while (opcao != 4);

    return 0;
}

int enfileirar(int fila[], int& ffila, int valor) {
    if (ffila < MAX_SIZE) {
        fila[ffila] = valor;
        ffila++;
        cout << "Numero enfileirado com sucesso!\n";
        return 1;
    } else {
        cout << "A fila esta cheia. Nao e possivel enfileirar mais elementos.\n";
        return 0;
    }
}

int desenfileirar(int fila[], int& ifila, int ffila, int& valor) {
    if (ifila < ffila) {
        valor = fila[ifila];
        ifila++;
        cout << "O dobro do numero desenfileirado eh: " << (valor * 2) << endl;
        return 1;
    } else {
        cout << "A fila esta vazia. Nao ha elementos para desenfileirar.\n";
        return 0;
    }
}

void exibirFila(const int fila[], int ifila, int ffila) {
    if (ifila < ffila) {
        cout << "Elementos da fila: ";
        for (int i = ifila; i < ffila; i++) {
            cout << fila[i] << " ";
        }
        cout << endl;
    } else {
        cout << "A fila esta vazia.\n";
    }
}
