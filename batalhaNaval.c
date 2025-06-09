#include <stdio.h>

#define TAMANHONAVIO 3
#define LINHAS 10
#define COLUNAS 10

// Função para inicializar o tabuleiro com água (0)
void inicializatabuleiro(int tabuleiro[][COLUNAS]) {
    for (int i = 0; i < LINHAS; i++) {
        for (int j = 0; j < COLUNAS; j++) {
            tabuleiro[i][j] = 0;
        }
    }
}

// Função para posicionar um navio horizontalmente no tabuleiro
void posicionanaviohorizontal(int tabuleiro[][COLUNAS], int linha, int coluna) {
    for (int i = 0; i < TAMANHONAVIO; i++) {
        if (coluna + i < COLUNAS) {
            tabuleiro[linha][coluna + i] = 3;
        }
    }
}

// Função para posicionar um navio verticalmente no tabuleiro
void posicionanaviovertical(int tabuleiro[][COLUNAS], int linha, int coluna) {
    for (int i = 0; i < TAMANHONAVIO; i++) {
        if (linha + i < LINHAS) {
            tabuleiro[linha + i][coluna] = 3;
        }
    }
}

// Função para posicionar um navio diagonalmente no tabuleiro (direção superior-esquerda para inferior-direita)
void posicionanaviodiagonalprincipal(int tabuleiro[][COLUNAS], int linha, int coluna) {
    for (int i = 0; i < TAMANHONAVIO; i++) {
        if (linha + i < LINHAS && coluna + i < COLUNAS) {
            tabuleiro[linha + i][coluna + i] = 3;
        }
    }
}

// Função para posicionar um navio diagonalmente no tabuleiro (direção superior-direita para inferior-esquerda)
void posicionanaviodiagonalsecundaria(int tabuleiro[][COLUNAS], int linha, int coluna) {
    for (int i = 0; i < TAMANHONAVIO; i++) {
        if (linha + i < LINHAS && coluna - i >= 0) {
            tabuleiro[linha + i][coluna - i] = 3;
        }
    }
}

// Função para exibir o tabuleiro no console
void exibetabuleiro(int tabuleiro[][COLUNAS]) {
    printf("  ");
    for (char c = 'A'; c < 'A' + COLUNAS; c++) {
        printf("%c ", c);
    }
    printf("\n");
    for (int i = 0; i < LINHAS; i++) {
        printf("%d ", i + 1);
        for (int j = 0; j < COLUNAS; j++) {
            printf("%d ", tabuleiro[i][j]);
        }
        printf("\n");
    }
}

int main() {
    int tabuleiro[LINHAS][COLUNAS];

    // Inicializa o tabuleiro com água (0)
    inicializatabuleiro(tabuleiro);

    // Posiciona os navios
    int linhanaviohorizontal = 2;
    int colunanaviohorizontal = 3;
    posicionanaviohorizontal(tabuleiro, linhanaviohorizontal, colunanaviohorizontal);

    int linhanaviovertical = 5;
    int colunanaviovertical = 8;
    posicionanaviovertical(tabuleiro, linhanaviovertical, colunanaviovertical);

    int linhanaviodiagonalprincipal = 1;
    int colunanaviodiagonalprincipal = 1;
    posicionanaviodiagonalprincipal(tabuleiro, linhanaviodiagonalprincipal, colunanaviodiagonalprincipal);

    int linhanaviodiagonalsecundaria = 4;
    int colunanaviodiagonalsecundaria = 8;
    posicionanaviodiagonalsecundaria(tabuleiro, linhanaviodiagonalsecundaria, colunanaviodiagonalsecundaria);

    // Exibe o tabuleiro
    printf("•• Jogo de Batalha naval! ••\n");
    exibetabuleiro(tabuleiro);

    return 0;
}
