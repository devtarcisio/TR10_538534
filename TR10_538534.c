#include <stdio.h>
#include <stdlib.h>

int main()
{
    // Variáveis Utilizadas
    unsigned int x[200];
    int y;
    int z;
    int k;
    int w;
    int j;
    int i;

    //#########################
    for (int i = 0; i < 200; i++)
        x[i] = 0; // -> setar o valor 0 para determinada casa do vetor

    i = 0;
    printf("Digite números entre 0 e 5000: \n");

    while (y != -1)
    {                    // a partir disto o programa repetirá enquanto y não for -1
        scanf("%d", &y); // guardar o numero que o usuário digita
        j = y / 32;      // vai alcançar casa do vetor que será alocado
        if (y >= 0 && y <= 5000)
        { // essa funçao observa se é igual ou maior que 0 e menor ou igual a 5000
            printf("Digite outro números\n");
            x[j] = x[j] | (1 << (y - (32 * j))); //"soma" o novo bit com o anterior
            if (y > i)
                i = y; // se y for maior que i, então i é igualado a  y para saber até qual número foi digitado
        }
        else if (y == -1)
            printf("Fim!\n"); // se y for iguala -1, então o looping é encerrado
    }
    y = 0; //  y recebe 0
    w = 0; // w recebe 0
    printf("Números Digitados: \n");
    while (y <= i)
    { // repetiá enquanto y for menor ou igual a i desse ponto
        if ((x[w] >> (y - (32 * w))) & 1)
            printf("%d\n", y); // verificra se já existe um bit na posição desejada,
        //caso afirmativo, ele printa quantas vezes o y andou para chegar lá
        y++;        // y soma mais um
        w = y / 32; // encontrar a posição do vetor a ser alocado
    }
    //#########################

    return 0;
}
