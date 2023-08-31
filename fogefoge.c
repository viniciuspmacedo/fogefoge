#include <stdio.h>
#include <stdlib.h>
#include "fogefoge.h"

int **mapa;
int linhas, colunas;

void alocamapa()
{
    mapa = malloc(sizeof(char *) * linhas);
    for (int i = 0; i < linhas; i++)
    {
        mapa[i] = malloc(sizeof(char *) * (colunas + 1));
    }
}

void lemapa()
{
    FILE *f;
    f = fopen("mapa.txt", "r");
    if (f == 0)
    {
        printf("Erro ao carregar o mapa.");
        exit(1);
    }

    fscanf(f, "%d %d", &linhas, &colunas);

    alocamapa();

    // carrega mapa
    for (int i = 0; i < linhas; i++)
    {
        fscanf(f, "%s", mapa[i]);
    }

    fclose(f);
}

void liberamapa()
{
    for (int i = 0; i < linhas; i++)
    {
        free(mapa[i]);
    }

    free(mapa);
}

int main()
{

    lemapa();

    for (int i = 0; i < linhas; i++)
    {
        printf("%s\n", mapa[i]);
    }

    liberamapa();
    return 0;
}