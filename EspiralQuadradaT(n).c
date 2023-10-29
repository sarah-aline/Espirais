#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>

void calcularCoordenadas(int n);
void darUmPasso(int* x, int* y, int quantidade_de_vertices);
void imprimirCoordenadas(int* x, int* y);

int main() {
    int n;
    scanf("%d", &n);
    calcularCoordenadas(n);
    return 0;
}

void calcularCoordenadas(int n) {
    int x = 0, y = 0;
    int i, quantidade_de_vertices = 0, indice_da_proxima_curva = 1, tamanho_do_segmento = 1, quantidade_de_segmentos_do_mesmo_tamanho = 0;
    bool eVertice = false;
    for (i = 1; i <= n; i++) {
        eVertice = i == indice_da_proxima_curva;
        darUmPasso(&x, &y, quantidade_de_vertices);
        if (eVertice) {
            ++quantidade_de_segmentos_do_mesmo_tamanho;
            if (i > 1 && quantidade_de_segmentos_do_mesmo_tamanho == 2) {
                ++tamanho_do_segmento;
                quantidade_de_segmentos_do_mesmo_tamanho = 0;
            }
            indice_da_proxima_curva = i + tamanho_do_segmento;
            ++quantidade_de_vertices;
        }
    }
    imprimirCoordenadas(&x, &y);
}

void darUmPasso(int* x, int* y, int quantidade_de_vertices) {
    int mod = quantidade_de_vertices % 4;
    switch (mod) {
        case 0:
            ++(*y);
            break;
        case 1:
            --(*x);
            break;
        case 2:
            --(*y);
            break;
        case 3:
            ++(*x);
            break;
        default:
            break;
    }
}

void imprimirCoordenadas(int* x, int* y) {
    printf("(%d, %d)\n", *x, *y);
}
