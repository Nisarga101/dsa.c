#include <stdio.h>

void sparse(int a[10][10], int m, int n)
{
    int s[100][3], t[100][3];
    int i, j, k = 1, p = 1;

    // Convert matrix into triplet
    for(i = 0; i < m; i++)
    {
        for(j = 0; j < n; j++)
        {
            if(a[i][j] != 0)
            {
                s[k][0] = i;
                s[k][1] = j;
                s[k][2] = a[i][j];
                k++;
            }
        }
    }

    s[0][0] = m;
    s[0][1] = n;
    s[0][2] = k - 1;

    printf("\nTriplet Representation:\n");

    for(i = 0; i < k; i++)
    {
        for(j = 0; j < 3; j++)
            printf("%d\t", s[i][j]);

        printf("\n");
    }

    // Transpose
    t[0][0] = s[0][1];
    t[0][1] = s[0][0];
    t[0][2] = s[0][2];

    for(i = 0; i < n; i++)
    {
        for(j = 1; j < k; j++)
        {
            if(s[j][1] == i)
            {
                t[p][0] = s[j][1];
                t[p][1] = s[j][0];
                t[p][2] = s[j][2];
                p++;
            }
        }
    }

    printf("\nTranspose of Sparse Matrix:\n");

    for(i = 0; i < k; i++)
    {
        for(j = 0; j < 3; j++)
            printf("%d\t", t[i][j]);

        printf("\n");
    }
}

int main()
{
    int a[10][10], m, n, i, j;

    printf("Enter rows and columns: ");
    scanf("%d%d", &m, &n);

    printf("Enter matrix elements:\n");

    for(i = 0; i < m; i++)
    {
        for(j = 0; j < n; j++)
            scanf("%d", &a[i][j]);
    }

    sparse(a, m, n);

    return 0;
}