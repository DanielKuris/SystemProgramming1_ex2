#include <stdio.h>
#include <stdlib.h>
#include "my_mat.h"

int main()
{
    int mat[MAT_VERTICE*MAT_VERTICE];

    char command = 'A';
    scanf("%c", &command);
    while(command != 'D' && command != EOF)
    {
        if (command == 'A') // init 'mat'
        {
            userInitMatrix(mat);
        }
        else if (command == 'B')    // check existance of path
        {
            int i = 0, j = 0;
            scanf("%d %d", &i, &j);

            if (checkForPath(mat, i, j))
                printf("True\n");
            else
                printf("False\n");
        }
        else if (command == 'C')    // find value of shortest path
        {
            int i = 0, j = 0;
            scanf("%d %d", &i, &j);

            int result = findShortestPath(mat, i, j);
            printf("%d\n", result);
        }

        scanf("%c", &command);
    }

    return 0;
}