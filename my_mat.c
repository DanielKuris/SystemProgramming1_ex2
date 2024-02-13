#include "my_mat.h"
#include <stdio.h>

void userInitMatrix(int* mat)
{
    for (int i = 0; i < MAT_VERTICE; i++)
    {
        for (int j = 0; j < MAT_VERTICE; j++)
        {
            int temp = 0;
            scanf("%d", &temp);
            mat[MAT_CELL(i, j)] = temp;

            if (mat[MAT_CELL(i, j)] == 0)
                mat[MAT_CELL(i, j)] = -1;
        }
    }

    /*
    for (int i = 0; i < MAT_VERTICE; i++)
    {
        for (int j = 0; j < MAT_VERTICE; j++)
        {
            if (mat[MAT_CELL(i, j)] > -1)
                printf(" %d ", mat[MAT_CELL(i, j)]);
            else
                printf("%d ", mat[MAT_CELL(i, j)]);
        }
        printf("\n");
    }
    printf("\n");
    */
}

void copyArray(int* source, int* destination, int cell_count)
{
    for (int i = 0; i < cell_count; i++)
    {
        destination[i] = source[i];
    }
}

int findShortestPath(int* mat, int i, int j)
{
    if (i == j)
        return -1;

    int temp[MAT_VERTICE*MAT_VERTICE];
    copyArray(mat, temp, MAT_VERTICE*MAT_VERTICE);

    for (int k = 0; k < MAT_VERTICE; k++)
    {
        for (int p = 0; p < MAT_VERTICE; p++)
        {
            for (int t = 0; t < MAT_VERTICE; t++)
            {
                if ( !((temp[MAT_CELL(p, k)] == -1) || (temp[MAT_CELL(k, t)] == -1)) )
                {
                    if (temp[MAT_CELL(p, t)] == -1 || temp[MAT_CELL(p, t)] > temp[MAT_CELL(p, k)] + temp[MAT_CELL(k, t)])
                    {
                        temp[MAT_CELL(p, t)] = temp[MAT_CELL(p, k)] + temp[MAT_CELL(k, t)];
                        //printf("(p,t,k) = (%d,%d,%d) ; p-t = %d p-k = %d ; k-t = %d\n", p, t, k, temp[MAT_CELL(p, t)], temp[MAT_CELL(p, k)], temp[MAT_CELL(k, t)]);
                    }
                }
            }
        }
    }

    int result = temp[MAT_CELL(i, j)];

    return result;
}

int checkForPath(int* mat, int i, int j)
{
    int result = findShortestPath(mat, i, j);
    if (result == -1)
        return 0;
    else
        return 1;
}