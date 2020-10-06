#include <stdio.h>
//program for matrix multiplication

int main()
{
    int a[10][10], b[10][10], result[10][10], row1, column1, row2, column2, i, j, k;

    printf("Enter rows and column for first matrix: ");
    scanf("%d %d", &row1, &column1);

    printf("Enter rows and column for second matrix: ");
    scanf("%d %d",&row2, &column2);

    // Column of first matrix should be equal to row of second matrix and
    if (column1 != row2)
    {
        printf("Error! column of first matrix not equal to row of second.\n\n");
         return 0;
    }

    // Storing elements of first matrix.
    printf("\nEnter elements of matrix 1:\n");
    for(i=0; i<row1 ; ++i)
        for(j=0; j<column1 ; ++j)
        {
            printf("Enter elements a%d%d: ",i, j);
            scanf("%d", &a[i][j]);
        }
 // Storing elements of second matrix.
    printf("\nEnter elements of matrix 2:\n");
    for(i=0; i<row2; ++i)
        for(j=0; j<column2; ++j)
        {
            printf("Enter elements b%d%d: ",i, j);
            scanf("%d",&b[i][j]);
        }

    // Initializing all elements of result matrix to 0
    for(i=0; i<row1; ++i)
        for(j=0; j<column2; ++j)
        {
            result[i][j] = 0;
        }

    // Multiplying matrices a and b and
    // storing result in result matrix  row1 x column2
    for(i=0; i<row1; ++i)
        for(j=0; j<column2; ++j)
            for(k=0; k<column1; ++k)
            {
                result[i][j]+=a[i][k]*b[k][j];  // Note i, j, k used to access elements in three matrices
            }

    // Displaying the result after matrix multiplication
    printf("\nOutput Matrix:\n");
    for(i=0; i<row1; ++i)
        for(j=0; j<column2; ++j)
        {
            printf("%d  ", result[i][j]);
            if(j == column2-1)
                printf("\n\n");
        }
    return 0;
}
