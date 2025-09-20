#include <stdio.h>

int main() {
    int matrix_Tabuleiro[10][10];
    char linha []= {'A','B','C','D','E','F','G','H','I','J'};
    int tamanhoNavio = 3;
    
    // Inicializar tabuleiro com 0 (água)
    for(int i = 0; i < 10; i++){
        for(int j = 0; j < 10; j++){
            matrix_Tabuleiro[i][j] = 0;
        }
    }
    printf("\n");

    // Coordenadas iniciais
    int navioHorizontalLinha = 2;
    int navioHorizontalColuna = 4;
    int navioVerticalLinha = 7;
    int navioVerticalColuna = 7;

    // --- Posicionar navio horizontal com verificação de sobreposição e limites---
    int sobreposicao1 = 0;
    int sobreposicao2 = 0;
    int limiteUltrapassado = 0;
    
    // Validar se navio horizontal cabe no tabuleiro
    if (navioHorizontalLinha < 0 || navioHorizontalLinha > 10){
        printf("Erro: A definição da linha do navio horizontal precisa estar entre 0 e 9.\n");
        limiteUltrapassado = 1;
    } 
    if(navioHorizontalColuna < 0 || (navioHorizontalColuna + tamanhoNavio) > 10){
        printf("A definição da coluna do navio horizontal precisa estar entre 0 e 7.\n");
        limiteUltrapassado = 1;
    }
   
    // Validar se navio verical cabe no tabuleiro
    if (navioVerticalLinha < 0 || navioVerticalLinha + tamanhoNavio > 10 ){
        printf("Erro: A definição da linha do navio vertical precisa estar entre 0 e 7.\n");
        limiteUltrapassado = 1;
    } 

    if(navioVerticalColuna < 0 || navioVerticalColuna + tamanhoNavio > 10){
        printf("A definição da coluna do navio vertical precisa estar entre 0 e 9.\n");
        limiteUltrapassado = 1;
    }

    for(int j = 0; j < tamanhoNavio; j++){
        if(matrix_Tabuleiro[navioHorizontalLinha][navioHorizontalColuna + j] != 0){
            sobreposicao1 = 1; // detectou sobreposição
            break;
        }
    }

    for(int j = 0; j < tamanhoNavio; j++){
        if(matrix_Tabuleiro[navioVerticalLinha + j][navioVerticalColuna] != 0){
            sobreposicao2 = 1; // detectou sobreposição
            break;
        }
    }

    if(!sobreposicao1){
        for(int j = 0; j < tamanhoNavio; j++){
            matrix_Tabuleiro[navioHorizontalLinha][navioHorizontalColuna + j] = 3;
        }
        } else {
            printf("Erro: navio horizontal não pode ser posicionado (sobreposição)\n");
        }
     
    if(!sobreposicao2){
        for(int j = 0; j < tamanhoNavio; j++){
            matrix_Tabuleiro[navioVerticalLinha + j][navioVerticalColuna] = 3;
        }
        } else {
            printf("Erro: navio vertical não pode ser posicionado (sobreposição)\n");
        }
   
    if(!sobreposicao1 && !sobreposicao2 && !limiteUltrapassado){
        printf("    ");
        for(int l = 0; l < 10 ; l++){
            printf("%c  ", linha[l]);
        }
        printf("\n");
        for(int i = 0; i < 10; i++){
            printf("%2d ", i + 1);
            for(int j = 0; j < 10; j++){
                printf("%2d ", matrix_Tabuleiro[i][j]);
            }
            printf("\n");
        }
    }

    return 0;
}
