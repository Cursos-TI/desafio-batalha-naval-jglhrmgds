#include <stdio.h>
#include <locale.h>

//Função para verificar se é possivel colocar o navio e não tem sobreposição
int pode_posicionar (int tabuleiro[10][10], int linha, int coluna, int tamanho, char orientacao){

    if (orientacao == 'H')
    {
        if (coluna + tamanho > 10)
        {
            printf("Navio fora dos limites\n");
            return 0;
        } else{
            for (int i = 0; i < tamanho; i++)
            {
                if (tabuleiro[linha][coluna + i] != 0)
                {
                    printf("Ja existe um navio nessa posição\n");
                    return 0;
                }
                
            }
            
        }
        
    } else if (orientacao == 'V')
    {
        if (linha + tamanho > 10)
        {
            printf("Navio fora dos limites\n");
            return 0;
        } else {
            for (int i = 0; i < tamanho; i++)
            {
                if (tabuleiro[linha + i][coluna] != 0)
                {
                    printf("Ja existe um navio nessa posição\n");
                    return 0;
                }
                
            }
            
        }
    } else if (orientacao != 'V' && orientacao != 'H')
    {
        printf("Orientação inválida\n");
        return 0;
    } else{
        return 1;
    }     
    }




//Função para posicionar no navio
void posicionar_navio(int tabuleiro[10][10], int linha, int coluna, int tamanho, char orientacao){
    if (orientacao == 'H')
    {
        for (int i = 0; i < tamanho; i++)
        {
            tabuleiro[linha][coluna + i] = 3;
        }
        
    } else if (orientacao == 'V'){
        for (int i = 0; i < tamanho; i++)
        {
            tabuleiro[linha + i][coluna] = 3;
        }
    }
}

int main() {
    setlocale(LC_ALL, "pt_BR.UTF-8");
    
    //Declarando e inicializando o tabuleiro
    int tabuleiro [10][10];
    for (int i = 0; i < 10; i++)
    {
        for (int j = 0; j < 10; j++)
        {
            tabuleiro [i][j] = 0;
        } 
    }


    //Posicionando os navios
    if (pode_posicionar(tabuleiro, 5, 7, 3, 'H'))
    {
        posicionar_navio(tabuleiro, 5, 7, 3, 'H');
    }
    
    if (pode_posicionar(tabuleiro, 4, 1, 3, 'V'))
    {
        posicionar_navio(tabuleiro, 4, 1, 3, 'V');
    }

    if (pode_posicionar(tabuleiro, 1, 4, 3, 'H'))
    {
        posicionar_navio(tabuleiro, 1, 4, 3, 'H');
    }
    
    if (pode_posicionar(tabuleiro, 6, 3, 3, 'V'))
    {
        posicionar_navio(tabuleiro, 6, 3, 3, 'V');
    }
    

    //Exibindo o tabuleiro
    printf("  ");
    for (char letra = 'A'; letra <= 'J'; letra++)
    {
        printf("%3c", letra);
    }
    printf("\n");

    for (int i = 0; i < 10; i++)
    {
        printf("%2d ", i + 1);

        for (int j = 0; j < 10; j++)
        {
            printf(" %d ", tabuleiro[i][j]);
        }
        printf("\n");
    }

    return 0;
}

    // Nível Mestre - Habilidades Especiais com Matrizes
    // Sugestão: Crie matrizes para representar habilidades especiais como cone, cruz, e octaedro.
    // Sugestão: Utilize estruturas de repetição aninhadas para preencher as áreas afetadas por essas habilidades no tabuleiro.
    // Sugestão: Exiba o tabuleiro com as áreas afetadas, utilizando 0 para áreas não afetadas e 1 para áreas atingidas.

    // Exemplos de exibição das habilidades:
    // Exemplo para habilidade em cone:
    // 0 0 1 0 0
    // 0 1 1 1 0
    // 1 1 1 1 1
    
    // Exemplo para habilidade em octaedro:
    // 0 0 1 0 0
    // 0 1 1 1 0
    // 0 0 1 0 0

    // Exemplo para habilidade em cruz:
    // 0 0 1 0 0
    // 1 1 1 1 1
    // 0 0 1 0 0