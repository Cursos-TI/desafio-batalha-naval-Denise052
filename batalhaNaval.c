#include <stdio.h>

#define TAMANHOTABULEIRO 10
#define TAMANHONAVIO 3

// Função para inicializar o tabuleiro com água (0)
void inicializatabuleiro(int tabuleiro[TAMANHOTABULEIRO][TAMANHOTABULEIRO]) {
    for (int i = 0; i < TAMANHOTABULEIRO; i++) {
        for (int j = 0; j < TAMANHOTABULEIRO; j++) 
        {
            tabuleiro[i][j] = 0;
        }
    }
}

// Função para posicionar um navio horizontalmente no tabuleiro
void posicionanaviohorizontal(int tabuleiro[TAMANHOTABULEIRO][TAMANHOTABULEIRO], int linha, int coluna) {
    for (int i = 0; i < TAMANHONAVIO; i++) 
    {
        tabuleiro[linha][coluna + i] = 3;
    }
}

// Função para posicionar um navio verticalmente no tabuleiro
void posicionanaviovertical(int tabuleiro[TAMANHOTABULEIRO][TAMANHOTABULEIRO], int linha, int coluna) {
    for (int i = 0; i < TAMANHONAVIO; i++) 
    {
        tabuleiro[linha + i][coluna] = 3;
    }
}

// Função para exibir o tabuleiro no console
void exibetabuleiro(int tabuleiro[TAMANHOTABULEIRO][TAMANHOTABULEIRO]) {
    printf("  ");
    for (char c = 'A'; c <= 'J'; c++ )
    {
        printf("%c ", c);
    }
    printf("\n");
    for (int i = 0; i < TAMANHOTABULEIRO; i++) {
        printf("%d ", i + 1);
        for (int j = 0; j < TAMANHOTABULEIRO; j++)
            {
            printf("%d ", tabuleiro[i][j]);
        }
        printf("\n");
    }
}

int main() {
    int tabuleiro[TAMANHOTABULEIRO][TAMANHOTABULEIRO];

    // Inicializa o tabuleiro com água (0)
    inicializatabuleiro(tabuleiro);

    // Posiciona os navios
    int linhanaviohorizontal = 5;
    int colunanaviohorizontal = 2;
    posicionanaviohorizontal(tabuleiro, linhanaviohorizontal, colunanaviohorizontal);

    int linhanaviovertical = 2;
    int colunanaviovertical = 8;
    posicionanaviovertical(tabuleiro, linhanaviovertical, colunanaviovertical);

    // Exibe o tabuleiro
    exibetabuleiro(tabuleiro);

    return 0;
}
