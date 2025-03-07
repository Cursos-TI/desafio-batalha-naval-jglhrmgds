#include <stdio.h>
#include <locale.h>
#include <stdlib.h>

#define HABILIDADE_TAM 5

// Função para verificar se é possível posicionar o navio
int pode_posicionar(int tabuleiro[10][10], int linha, int coluna, int tamanho, char orientacao) {
    if (orientacao == 'H') {
        if (coluna + tamanho > 10) {
            printf("Navio fora dos limites\n");
            return 0;
        }
        for (int i = 0; i < tamanho; i++) {
            if (tabuleiro[linha][coluna + i] != 0) {
                printf("Já existe um navio nessa posição\n");
                return 0;
            }
        }
    } else if (orientacao == 'V') {
        if (linha + tamanho > 10) {
            printf("Navio fora dos limites\n");
            return 0;
        }
        for (int i = 0; i < tamanho; i++) {
            if (tabuleiro[linha + i][coluna] != 0) {
                printf("Já existe um navio nessa posição\n");
                return 0;
            }
        }
    } else {
        printf("Orientação inválida\n");
        return 0;
    }

    return 1;
}

// Função para posicionar o navio
void posicionar_navio(int tabuleiro[10][10], int linha, int coluna, int tamanho, char orientacao) {
    if (orientacao == 'H') {
        for (int i = 0; i < tamanho; i++) {
            tabuleiro[linha][coluna + i] = 3;
        }
    } else if (orientacao == 'V') {
        for (int i = 0; i < tamanho; i++) {
            tabuleiro[linha + i][coluna] = 3;
        }
    }
}

// Função para criar a habilidade em cone
void criarCone(int cone[HABILIDADE_TAM][HABILIDADE_TAM]) {
    for (int i = 0; i < HABILIDADE_TAM; i++) {
        for (int j = 0; j < HABILIDADE_TAM; j++) {
            cone[i][j] = (j >= HABILIDADE_TAM / 2 - i && j <= HABILIDADE_TAM / 2 + i) ? 1 : 0;
        }
    }
}

// Função para criar a habilidade em cruz
void criarCruz(int cruz[HABILIDADE_TAM][HABILIDADE_TAM]) {
    for (int i = 0; i < HABILIDADE_TAM; i++) {
        for (int j = 0; j < HABILIDADE_TAM; j++) {
            cruz[i][j] = (i == HABILIDADE_TAM / 2 || j == HABILIDADE_TAM / 2) ? 1 : 0;
        }
    }
}

// Função para criar a habilidade em octaedro
void criarOctaedro(int octaedro[HABILIDADE_TAM][HABILIDADE_TAM]) {
    for (int i = 0; i < HABILIDADE_TAM; i++) {
        for (int j = 0; j < HABILIDADE_TAM; j++) {
            int distancia = abs(i - HABILIDADE_TAM / 2) + abs(j - HABILIDADE_TAM / 2);
            octaedro[i][j] = (distancia <= HABILIDADE_TAM / 2) ? 1 : 0;
        }
    }
}

// Função para aplicar uma habilidade no tabuleiro
void aplicarHabilidade(int tabuleiro[10][10], int habilidade[HABILIDADE_TAM][HABILIDADE_TAM], int origemX, int origemY) {
    for (int i = 0; i < HABILIDADE_TAM; i++) {
        for (int j = 0; j < HABILIDADE_TAM; j++) {
            int x = origemX + i - HABILIDADE_TAM / 2;
            int y = origemY + j - HABILIDADE_TAM / 2;

            if (x >= 0 && x < 10 && y >= 0 && y < 10 && habilidade[i][j] == 1) {
                tabuleiro[x][y] = 5;
            }
        }
    }
}

int main() {
    setlocale(LC_ALL, "pt_BR.UTF-8");

    // Declarando e inicializando o tabuleiro
    int tabuleiro[10][10] = {0};

    // Criando as matrizes de habilidades
    int cone[HABILIDADE_TAM][HABILIDADE_TAM];
    int cruz[HABILIDADE_TAM][HABILIDADE_TAM];
    int octaedro[HABILIDADE_TAM][HABILIDADE_TAM];

    criarCone(cone);
    criarCruz(cruz);
    criarOctaedro(octaedro);

    // Posicionando os navios
    if (pode_posicionar(tabuleiro, 5, 7, 3, 'H')) {
        posicionar_navio(tabuleiro, 5, 7, 3, 'H');
    }

    if (pode_posicionar(tabuleiro, 4, 1, 3, 'V')) {
        posicionar_navio(tabuleiro, 4, 1, 3, 'V');
    }

    if (pode_posicionar(tabuleiro, 1, 4, 3, 'H')) {
        posicionar_navio(tabuleiro, 1, 4, 3, 'H');
    }

    if (pode_posicionar(tabuleiro, 6, 3, 3, 'V')) {
        posicionar_navio(tabuleiro, 6, 3, 3, 'V');
    }

    // Aplicar as habilidades
    aplicarHabilidade(tabuleiro, cone, 2, 4);
    aplicarHabilidade(tabuleiro, cruz, 5, 5);
    aplicarHabilidade(tabuleiro, octaedro, 7, 7);

    // Exibindo o tabuleiro
    printf("   ");
    for (char letra = 'A'; letra <= 'J'; letra++) {
        printf("%3c", letra);
    }
    printf("\n");

    for (int i = 0; i < 10; i++) {
        printf("%2d ", i + 1);
        for (int j = 0; j < 10; j++) {
            printf(" %d ", tabuleiro[i][j]);
        }
        printf("\n");
    }

    return 0;
}
