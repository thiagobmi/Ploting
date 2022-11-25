#include <stdio.h>
#include <stdlib.h>
#include <time.h>
#include <math.h>

struct ponto
{
    int *X;
    int *Y;
};

typedef struct ponto Ponto;

struct centroF
{
    float *X;
    float *Y;
};

typedef struct centroF CentroF;

CentroF *alocaMemCentroF(int k)
{

    CentroF *centroF = malloc(sizeof(float) * k * 5);
    if (centroF == NULL)
    {
        printf("ERRO\n");
        exit(0);
    }
    for (int i = 0; i < k; i++)
    {
        centroF[i].X = (float *)malloc(sizeof(float) * 2);
        if (centroF[i].X == NULL)
        {
            printf("ERRO\n");
            exit(0);
        }
    }
    for (int i = 0; i < k; i++)
    {
        centroF[i].Y = (float *)malloc(sizeof(float) * 2);
        if (centroF[i].Y == NULL)
        {
            printf("ERRO\n");
            exit(0);
        }
    }
    return centroF;
}

Ponto *alocamemoria(int n)
{

    Ponto *pontos = (Ponto *)malloc(sizeof(Ponto) * n);
    if (pontos == NULL)
    {
        printf("ERRO\n");
        exit(0);
    }

    for (int i = 0; i < n; i++)
    {
        pontos[i].X = (int *)malloc(sizeof(int));
        if (pontos[i].X == NULL)
        {
            printf("ERRO\n");
            exit(0);
        }
    }
    for (int i = 0; i < n; i++)
    {
        pontos[i].Y = (int *)malloc(sizeof(int));
        if (pontos[i].Y == NULL)
        {
            printf("ERRO\n");
            exit(0);
        }
    }
    return pontos;
}

void liberamemoria(float *menordistancia, float **distancias, int k)
{

    free(distancias);
    free(menordistancia);
}

Ponto *geraPontos(Ponto *pontos, int n)
{


    for (int i = 0; i < n; i++)
    {
        scanf("%d %d",pontos[i].X,pontos[i].Y);
    }


    // for (int i = 0; i < n; i++)
    // {
    //     *pontos[i].X = -20000 + rand() % 50000;
    //     *pontos[i].Y = -20000 + rand() % 50000;
    // }

    return pontos;
}

int **agrupaPontos(Ponto *pontos, int n, int k, int *contador, Ponto *centrosmain)
{
    int i, j, pontoaleatorio, vetrand[k], contrand = 0;
    float menor;

    float *menordistancia = (float *)malloc(sizeof(float) * n);
    if (menordistancia == NULL)
    {
        printf("ERRO\n");
        exit(0);
    }

    float **distancias = (float **)malloc(sizeof(float) * n * 2);
    if (distancias == NULL)
    {
        printf("ERRO\n");
        exit(0);
    }

    int **arrponto = (int **)malloc(sizeof(int) * k * 2 * 2);
    if (arrponto == NULL)
    {
        printf("ERRO\n");
        exit(0);
    }
    for (i = 0; i < k; i++)
    {
        arrponto[i] = (int *)malloc(sizeof(int) * n * 2);
        if (arrponto == NULL)
        {
            printf("ERRO\n");
            exit(0);
        }
    }
    for (i = 0; i < k; i++)
    {
        distancias[i] = (float *)malloc(sizeof(float) * n );
        if (menordistancia == NULL)
        {
            printf("ERRO\n");
            exit(0);
        }
    }

    Ponto *centros = alocamemoria(k);

    for (i = 0; i < k; i++)
    {
        pontoaleatorio = rand() % n;

        for (j = 0; j < contrand; j++)
            while (pontoaleatorio == vetrand[j])
                pontoaleatorio = rand() % n;

        contrand++;
        vetrand[i] = pontoaleatorio;

        *centros[i].X = *pontos[pontoaleatorio].X;
        *centrosmain[i].X = *pontos[pontoaleatorio].X;
        *centros[i].Y = *pontos[pontoaleatorio].Y;
        *centrosmain[i].Y = *pontos[pontoaleatorio].Y;
    }

    for (j = 0; j < k; j++)
    {

        for (i = 0; i < n; i++)
            distancias[j][i] = sqrt(pow(((float)*pontos[i].X - (float)*centros[j].X), 2) + pow(((float)*pontos[i].Y - (float)*centros[j].Y), 2));
    }

    for (i = 0; i < n; i++)
    {
        menor = 9999;
        for (j = 0; j < k; j++)
        {
            if (distancias[j][i] < menor)
            {
                menordistancia[i] = distancias[j][i];
                menor = distancias[j][i];
            }
        }
    }

    for (i = 0; i < k; i++)
        contador[i] = 0;

    for (j = 0; j < k; j++)
        for (i = 0; i < n; i++)
        {

            if (distancias[j][i] == menordistancia[i])
            {
                contador[j]++;
                arrponto[j][i] = i;
            }
            else
                arrponto[j][i] = -20;
        }

    for (int i = 0; i < k; i++)
        free(distancias[i]);
    liberamemoria(menordistancia, distancias, k);

    return arrponto;
}

int **agrupapontos2(CentroF *centroF, Ponto *pontos, int k, int n, int *contador)
{

    int i, j, menor = 9999;

    float *menordistancia = (float *)malloc(sizeof(float) * n * 2);
    if (menordistancia == NULL)
    {
        printf("ERRO\n");
        exit(0);
    }
    float **distancias = (float **)malloc(sizeof(float) * n * 2);
    if (distancias == NULL)
    {
        printf("ERRO\n");
        exit(0);
    }

    int **arrponto = (int **)malloc(sizeof(int) * k * 2 * 2);
    if (arrponto == NULL)
    {
        printf("ERRO\n");
        exit(0);
    }

    for (i = 0; i < k; i++)
    {
        arrponto[i] = (int *)malloc(sizeof(int) * n * 2);
        if (arrponto[i] == NULL)
        {
            printf("ERRO\n");
            exit(0);
        }
    }

    for (i = 0; i < k; i++)
    {
        distancias[i] = (float *)malloc(sizeof(float) * n);
        if (distancias == NULL)
        {
            printf("ERRO\n");
            exit(0);
        }
    }

    for (j = 0; j < k; j++)
        for (i = 0; i < n; i++)
            distancias[j][i] = sqrt(pow(((float)*pontos[i].X - *centroF[j].X), 2) + pow(((float)*pontos[i].Y - *centroF[j].Y), 2));

    for (i = 0; i < n; i++)
    {
        menor = 9999;
        for (j = 0; j < k; j++)
        {
            if (distancias[j][i] < menor)
            {
                menordistancia[i] = distancias[j][i];
                menor = distancias[j][i];
            }
        }
    }

    for (i = 0; i < k; i++)
        contador[i] = 0;

    for (j = 0; j < k; j++)
        for (i = 0; i < n; i++)
        {

            if (distancias[j][i] == menordistancia[i])
            {
                contador[j]++;
                arrponto[j][i] = i;
            }
            else
                arrponto[j][i] = -20;
        }

    for (int i = 0; i < k; i++)
        free(distancias[i]);
    liberamemoria(menordistancia, distancias, k);

    return arrponto;
}

int main(int argc, char *argv[])
{

    int n = 0, k = 0, **grupos, contapontos = 0, j = 0, x = 10, i = 0;

    n = 6000000;
    k = 200;

    srand(time(NULL));

    FILE *pont_arq;
    pont_arq = fopen("arquivo.txt", "w");
  
    int *contador = malloc(sizeof(int) * k * 2);
    Ponto *pontos = alocamemoria(n);
    
    CentroF *centroF = alocaMemCentroF(k);
    
    CentroF *centroF2 = alocaMemCentroF(k);
    
    Ponto *centrosmain = alocamemoria(k);
    

    pontos = geraPontos(pontos, n);
    
    grupos = agrupaPontos(pontos, n, k, contador, centrosmain);

    int **gruposR = (int **)malloc(sizeof(int) * k * 7 * 2);
    if (gruposR == NULL)
    {
        printf("ERRO\n");
        exit(0);
    }

    for (i = 0; i < k; i++)
    {
        gruposR[i] = (int *)malloc(sizeof(int) * contador[i] * 5 * 2);
        if (gruposR[i] == NULL)
        {
            printf("ERRO\n");
            exit(0);
        }
    }
    
    for (i = 0; i < k; i++)
    {
        contapontos = 0;
        while (contapontos < contador[i])
            for (int j = 0; j < n; j++)
            {
                if (grupos[i][j] != -20)
                {
                    gruposR[i][contapontos] = grupos[i][j];
                    contapontos++;
                }
            }
    }

    float *mediaX = (float *)malloc(sizeof(double) * k * 7);
    if (mediaX == NULL)
    {
        printf("ERRO\n");
        exit(0);
    }

    float *mediaY = (float *)malloc(sizeof(double) * k * 7);
    if (mediaY == NULL)
    {
        printf("ERRO\n");
        exit(0);
    }

    for (i = 0; i < k; i++)
        for (j = 0; j < contador[i]; j++)
        {
            mediaX[i] += (float)*pontos[gruposR[i][j]].X;
            mediaY[i] += (float)*pontos[gruposR[i][j]].Y;
        }

    for (i = 0; i < k; i++)
        free(gruposR[i]);

    for (i = 0; i < k; i++)
    {
        *centroF[i].X = (mediaX[i] / (float)contador[i]);
        *centroF2[i].X = *centroF[i].X;
        *centroF[i].Y = (mediaY[i] / (float)contador[i]);
        *centroF2[i].Y = *centroF[i].Y;
    }

    for (i = 0; i < k; i++)
        free(grupos[i]);

    for (int l = 0; l < x; l++)
    {
        printf("\nL = %d\n", l);
        grupos = agrupapontos2(centroF, pontos, k, n, contador);
        for (i = 0; i < k; i++)
        {
            gruposR[i] = (int *)malloc(sizeof(int) * contador[i] * 5);
            if (gruposR[i] == NULL)
            {
                printf("ERRO\n");
                exit(0);
            }
        }
        for (i = 0; i < k; i++)
        {
            contapontos = 0;
            while (contapontos < contador[i])
                for (int j = 0; j < n; j++)
                {
                    if (grupos[i][j] != -20)
                    {
                        gruposR[i][contapontos] = grupos[i][j];
                        contapontos++;
                    }
                }
        }

        if (l == x - 1)
        {
            for (i = 0; i < k; i++)
            {
                for (j = 0; j < contador[i]; j++)
                    fprintf(pont_arq, "%d;%d;%.2f;%.2f;%.2f;%.2f;%d;%d\n", *pontos[gruposR[i][j]].X, *pontos[gruposR[i][j]].Y, *centroF[i].X, *centroF[i].Y, *centroF2[i].X, *centroF2[i].Y, *centrosmain[i].X, *centrosmain[i].Y);
            }
        }

        for (i = 0; i < k; i++)
            free(grupos[i]);

        for (i = 0; i < k; i++)
        {
            mediaX[i] = 0;
            mediaY[i] = 0;
        }

        for (i = 0; i < k; i++)
            for (j = 0; j < contador[i]; j++)
            {
                mediaX[i] += (float)*pontos[gruposR[i][j]].X;
                mediaY[i] += (float)*pontos[gruposR[i][j]].Y;
            }

        for (i = 0; i < k; i++)
        {
            *centroF[i].X = (mediaX[i] / (float)contador[i]);
            *centroF[i].Y = (mediaY[i] / (float)contador[i]);
        }

        for (i = 0; i < k; i++)
            free(gruposR[i]);
    }
}