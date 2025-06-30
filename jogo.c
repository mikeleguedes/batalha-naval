#include <stdio.h>
#include <string.h>

#define TAM_TABULEIRO 10
#define TAM_HABILIDADE 5

// Função para inicializar o tabuleiro com água (0)
void inicializarTabuleiro(int tabuleiro[TAM_TABULEIRO][TAM_TABULEIRO]) {
    for (int i = 0; i < TAM_TABULEIRO; i++) {
        for (int j = 0; j < TAM_TABULEIRO; j++) {
            tabuleiro[i][j] = 0;
        }
    }

    // Adiciona alguns navios (3) para visualização
    tabuleiro[2][3] = 3;
    tabuleiro[2][4] = 3;
    tabuleiro[5][5] = 3;
    tabuleiro[7][7] = 3;
}

// Gera matriz em forma de cone
void gerarCone(int matriz[TAM_HABILIDADE][TAM_HABILIDADE]) {
    for (int i = 0; i < TAM_HABILIDADE; i++) {
        for (int j = 0; j < TAM_HABILIDADE; j++) {
            // Cone com base larga e topo estreito
            if (j >= (TAM_HABILIDADE - 1) / 2 - i && j <= (TAM_HABILIDADE - 1) / 2 + i) {
                matriz[i][j] = 1;
            } else {
                matriz[i][j] = 0;
            }
        }
    }
}

// Gera a matriz em forma de cruz
void gerarCruz(int matriz[TAM_HABILIDADE][TAM_HABILIDADE]) {
    for (int i = 0; i < TAM_HABILIDADE; i++) {
        for (int j = 0; j < TAM_HABILIDADE; j++) {
            if (i == TAM_HABILIDADE / 2 || j == TAM_HABILIDADE / 2) {
                matriz[i][j] = 1;
            } else {
                matriz[i][j] = 0;
            }
        }
    }
}


// Gera a matriz em forma de octaedro
void gerarOctaedro(int matriz[TAM_HABILIDADE][TAM_HABILIDADE]) {
    int centro = TAM_HABILIDADE / 2;
    for (int i = 0; i < TAM_HABILIDADE; i++) {
        for (int j = 0; j < TAM_HABILIDADE; j++) {
            if (abs(i - centro) + abs(j - centro) <= centro) {
                matriz[i][j] = 1;
            } else {
                matriz[i][j] = 0;
            }
        }
    }
}


// Aplica uma habilidade no tabuleiro com ponto de origem
void aplicarHabilidade(int tabuleiro[TAM_TABULEIRO][TAM_TABULEIRO], int habilidade[TAM_HABILIDADE][TAM_HABILIDADE], int origemX, int origemY) {
    int offset = TAM_HABILIDADE / 2;

    for (int i = 0; i < TAM_HABILIDADE; i++) {
        for (int j = 0; j < TAM_HABILIDADE; j++) {
            int tabX = origemX + i - offset;
            int tabY = origemY + j - offset;

            // Garante que a sobreposição fique dentro dos limites do tabuleiro
            if (tabX >= 0 && tabX < TAM_TABULEIRO && tabY >= 0 && tabY < TAM_TABULEIRO) {
                if (habilidade[i][j] == 1) {
                    // Marca como área afetada pela habilidade
                    tabuleiro[tabX][tabY] = 5;
                }
            }
        }
    }
}

// Imprime o tabuleiro com legenda
void exibirTabuleiro(int tabuleiro[TAM_TABULEIRO][TAM_TABULEIRO]) {
    printf("\n=== TABULEIRO ===\n\n");
    for (int i = 0; i < TAM_TABULEIRO; i++) {
        for (int j = 0; j < TAM_TABULEIRO; j++) {
            switch (tabuleiro[i][j]) {
                case 0:
                    printf("~ "); // água
                    break;
                case 3:
                    printf("N "); // navio
                    break;
                case 5:
                    printf("* "); // habilidade
                    break;
                default:
                    printf("? ");
            }
        }
        printf("\n");
    }
    printf("\nLegenda: ~ Água | N Navio | * Área Afetada\n");
}

int main() {
    int tabuleiro[TAM_TABULEIRO][TAM_TABULEIRO];
    int cone[TAM_HABILIDADE][TAM_HABILIDADE];
    int cruz[TAM_HABILIDADE][TAM_HABILIDADE];
    int octaedro[TAM_HABILIDADE][TAM_HABILIDADE];

    inicializarTabuleiro(tabuleiro);

    gerarCone(cone);
    gerarCruz(cruz);
    gerarOctaedro(octaedro);

    // Aplica habilidades em posições fixas
    aplicarHabilidade(tabuleiro, cone, 2, 3);       // cone no topo
    aplicarHabilidade(tabuleiro, cruz, 5, 5);       // cruz no centro
    aplicarHabilidade(tabuleiro, octaedro, 7, 7);   // octaedro no canto inferior

    exibirTabuleiro(tabuleiro);

    return 0;
}
