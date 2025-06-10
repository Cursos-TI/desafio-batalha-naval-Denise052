#include <stdio.h>
#include <stdlib.h>

#define TAMANHO_TABULEIRO 10
#define TAMANHO_HABILIDADE 5
#define TAMANHONAVIO 3

// Função para inicializar o tabuleiro com água (0)
void inicializatabuleiro(int tabuleiro[][TAMANHO_TABULEIRO]) {
    for (int i = 0; i < TAMANHO_TABULEIRO; i++) {
        for (int j = 0; j < TAMANHO_TABULEIRO; j++) {
            tabuleiro[i][j] = 0;
        }
    }
}

// Função para criar a matriz de habilidade em forma de cone
void criarCone(int habilidade[][TAMANHO_HABILIDADE]) {
    for (int i = 0; i < TAMANHO_HABILIDADE; i++) {
        for (int j = 0; j < TAMANHO_HABILIDADE; j++) {
            if (j >= TAMANHO_HABILIDADE / 2 - i && j <= TAMANHO_HABILIDADE / 2 + i) {
                habilidade[i][j] = 1; // Área afetada
            } else {
                habilidade[i][j] = 0; // Área não afetada
            }
        }
    }
}

// Função para criar a matriz de habilidade em forma de cruz
void criarCruz(int habilidade[][TAMANHO_HABILIDADE]) {
    for (int i = 0; i < TAMANHO_HABILIDADE; i++) {
        for (int j = 0; j < TAMANHO_HABILIDADE; j++) {
            if (i == TAMANHO_HABILIDADE / 2 || j == TAMANHO_HABILIDADE / 2) {
                habilidade[i][j] = 1; // Área afetada
            } else {
                habilidade[i][j] = 0; // Área não afetada
            }
        }
    }
}

// Função para criar a matriz de habilidade em forma de octaedro
void criarOctaedro(int habilidade[][TAMANHO_HABILIDADE]) {
    for (int i = 0; i < TAMANHO_HABILIDADE; i++) {
        for (int j = 0; j < TAMANHO_HABILIDADE; j++) {
            if (abs(i - TAMANHO_HABILIDADE / 2) + abs(j - TAMANHO_HABILIDADE / 2) <= TAMANHO_HABILIDADE / 2) {
                habilidade[i][j] = 1; // Área afetada
            } else {
                habilidade[i][j] = 0; // Área não afetada
            }
        }
    }
}

// Função para sobrepor a habilidade no tabuleiro
void sobreporHabilidade(int tabuleiro[][TAMANHO_TABULEIRO], int habilidade[][TAMANHO_HABILIDADE], int x, int y) {
    for (int i = 0; i < TAMANHO_HABILIDADE; i++) {
        for (int j = 0; j < TAMANHO_HABILIDADE; j++) {
            if (x + i - TAMANHO_HABILIDADE / 2 >= 0 && x + i - TAMANHO_HABILIDADE / 2 < TAMANHO_TABULEIRO && y + j - TAMANHO_HABILIDADE / 2 >= 0 && y + j - TAMANHO_HABILIDADE / 2 < TAMANHO_TABULEIRO) {
                if (habilidade[i][j] == 1) {
                    tabuleiro[x + i - TAMANHO_HABILIDADE / 2][y + j - TAMANHO_HABILIDADE / 2] = 5; // Área afetada
                }
            }
        }
    }
}

// Função para posicionar um navio horizontalmente no tabuleiro
void posicionanaviohorizontal(int tabuleiro[][TAMANHO_TABULEIRO], int linha, int coluna) {
    for (int i = 0; i < TAMANHONAVIO; i++) {
        if (coluna + i < TAMANHO_TABULEIRO) {
            tabuleiro[linha][coluna + i] = 3;
        }
    }
}

// Função para posicionar um navio verticalmente no tabuleiro
void posicionanaviovertical(int tabuleiro[][TAMANHO_TABULEIRO], int linha, int coluna) {
    for (int i = 0; i < TAMANHONAVIO; i++) {
        if (linha + i < TAMANHO_TABULEIRO) {
            tabuleiro[linha + i][coluna] = 3;
        }
    }
}

// Função para posicionar um navio diagonalmente no tabuleiro (direção superior-esquerda para inferior-direita)
void posicionanaviodiagonalprincipal(int tabuleiro[][TAMANHO_TABULEIRO], int linha, int coluna) {
    for (int i = 0; i < TAMANHONAVIO; i++) {
        if (linha + i < TAMANHO_TABULEIRO && coluna + i < TAMANHO_TABULEIRO) {
            tabuleiro[linha + i][coluna + i] = 3;
        }
    }
}

// Função para posicionar um navio diagonalmente no tabuleiro (direção superior-direita para inferior-esquerda)
void posicionanaviodiagonalsecundaria(int tabuleiro[][TAMANHO_TABULEIRO], int linha, int coluna) {
    for (int i = 0; i < TAMANHONAVIO; i++) {
        if (linha + i < TAMANHO_TABULEIRO && coluna - i >= 0) {
            tabuleiro[linha + i][coluna - i] = 3;
        }
    }
}

// Função para exibir o tabuleiro  
void exibetabuleiro(int tabuleiro[][TAMANHO_TABULEIRO]) {
    printf("  ");
    for (char c = 'A'; c < 'A' + TAMANHO_TABULEIRO; c++) {
        printf("%c ", c);
    }
    printf("\n");
    for (int i = 0; i < TAMANHO_TABULEIRO; i++) {
        printf("%d ", i + 1);
        for (int j = 0; j < TAMANHO_TABULEIRO; j++) {
            if (tabuleiro[i][j] == 3) {
                printf("3 "); // Navio
            } else if (tabuleiro[i][j] == 5) {
                printf("5 "); // Habilidade
            } else {
                printf("0 "); // Água
            }
        }
        printf("\n");
    }
}

int main() {
    int tabuleiro[TAMANHO_TABULEIRO][TAMANHO_TABULEIRO];
    int habilidadeCone[TAMANHO_HABILIDADE][TAMANHO_HABILIDADE];
    int habilidadeCruz[TAMANHO_HABILIDADE][TAMANHO_HABILIDADE];
    int habilidadeOctaedro[TAMANHO_HABILIDADE][TAMANHO_HABILIDADE];

    // Inicializa o tabuleiro com água (0)
    inicializatabuleiro(tabuleiro);

    // Cria as habilidades
    criarCone(habilidadeCone);
    criarCruz(habilidadeCruz);
    criarOctaedro(habilidadeOctaedro);

    // Posiciona os navios
    posicionanaviohorizontal(tabuleiro, 2, 3);
    posicionanaviovertical(tabuleiro, 5, 8);
    posicionanaviodiagonalprincipal(tabuleiro, 1, 1);
    posicionanaviodiagonalsecundaria(tabuleiro, 4, 8);

    // Aplica as habilidades
    sobreporHabilidade(tabuleiro, habilidadeCone, 3, 3);
    sobreporHabilidade(tabuleiro, habilidadeCruz, 7, 7);
    sobreporHabilidade(tabuleiro, habilidadeOctaedro, 2, 2);

    // Exibe o tabuleiro
    printf("•• Jogo de Batalha Naval! ••\n");
    exibetabuleiro(tabuleiro);

    return 0;
}
