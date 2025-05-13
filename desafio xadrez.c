#include <stdio.h>
#include <stdbool.h>

// Constantes para o número de movimentos
#define MOVIMENTOS_TORRE 3
#define MOVIMENTOS_BISPO 4
#define MOVIMENTOS_RAINHA 5
#define MOVIMENTOS_CAVALO 3

// Função recursiva para movimento da Torre
void moverTorre(int casas) {
    // Caso base - quando não há mais casas para mover
    if (casas <= 0) {
        return;
    }
    
    printf("Direita\n");  // Torre move-se para a direita
    moverTorre(casas - 1); // Chamada recursiva com uma casa a menos
}

// Função recursiva para movimento do Bispo (diagonal superior direita)
void moverBispo(int casas) {
    // Caso base
    if (casas <= 0) {
        return;
    }
    
    printf("Diagonal Superior Direita\n");
    moverBispo(casas - 1); // Chamada recursiva
}

// Função para movimento do Bispo com loops aninhados
void moverBispoLoops(int casas) {
    // Loop externo para movimento vertical (cima)
    for (int i = 0; i < casas; i++) {
        // Loop interno para movimento horizontal (direita)
        for (int j = 0; j < casas; j++) {
            if (i == j) { // Apenas nas diagonais (i = j)
                printf("Diagonal Superior Direita\n");
            }
        }
    }
}

// Função recursiva para movimento da Rainha (combina torre e bispo)
void moverRainha(int casas) {
    // Caso base
    if (casas <= 0) {
        return;
    }
    
    // Rainha pode mover como torre ou bispo
    if (casas % 2 == 0) {
        printf("Direita\n"); // Movimento de torre
    } else {
        printf("Diagonal Superior Direita\n"); // Movimento de bispo
    }
    
    moverRainha(casas - 1); // Chamada recursiva
}

// Função para movimento do Cavalo com loops complexos
void moverCavalo() {
    // Loop para controlar o movimento em L (2 cima, 1 direita)
    for (int cima = 0; cima < MOVIMENTOS_CAVALO; cima++) {
        for (int direita = 0; direita < MOVIMENTOS_CAVALO; direita++) {
            // Verifica o padrão de movimento em L
            if (cima == 2 && direita == 1) {
                printf("Movimento em L: 2 cima, 1 direita\n");
                break; // Encontrou o movimento, pode sair do loop interno
            }
            
            // Condição para continuar procurando o movimento correto
            if (cima < 2) {
                continue;
            }
        }
    }
}

int main() {
    printf("Movimento da Torre (recursivo):\n");
    moverTorre(MOVIMENTOS_TORRE);
    printf("\n");
    
    printf("Movimento do Bispo (recursivo):\n");
    moverBispo(MOVIMENTOS_BISPO);
    printf("\n");
    
    printf("Movimento do Bispo (loops aninhados):\n");
    moverBispoLoops(MOVIMENTOS_BISPO);
    printf("\n");
    
    printf("Movimento da Rainha (recursivo):\n");
    moverRainha(MOVIMENTOS_RAINHA);
    printf("\n");
    
    printf("Movimento do Cavalo (loops complexos):\n");
    moverCavalo();
    printf("\n");
    
    return 0;
}