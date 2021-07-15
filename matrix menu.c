write a menu-driven program to read and display an m X n matrices

#include<stdio.h>
#include<conio.h>
void read_matrix(int mat[2][2],int,int);
void sum_matrix(int mat1[2][2],int mat2[2][2],int,int);
void display_matrix(int mat[2][2],int,int);
void mul_matrix(int mat1[2][2],int mat2[2][2],int,int);
void transpose_matrix(int mat[2][2],int,int);
void main()
{
    int option,rows,cols;
    int mat1[2][2], mat2[2][2];

    do{
        printf("\n ********** MAIN MENU **********");
        printf("\n 1. Read the two matrices");
        printf("\n 2. Add the matrices");
        printf("\n 3. Multiply the matrices");
        printf("\n 4.Transpose the matrices");
        printf("\n 5. Exit");

        printf("\n\n Enter your option: ");
        scanf("%d",&option);

        switch(option)
        {
            case 1:
               printf("\n Enter the number of rows and coloumns: ");
               scanf("%d %d",&rows, &cols);
               printf("\n Entr the first matrix: ");
               read_matrix(mat1,rows,cols);
               printf("\n Entr the second matrix: ");
               read_matrix(mat2,rows,cols);
               break;

            case 2:
               sum_matrix(mat1,mat2,rows,cols);
               break;

            case 3:
            if (cols == rows)
                mul_matrix(mat1, mat2, rows, cols);
            else
                printf("\n To multiply two matrices, number of coloumns in the first matrix must be equal to number of rows in the second matrix.");
            break;

            case 4:
            transpose_matrix(mat1,rows,cols);
            break;

        }
    }while(option != 5);
    getch();
}

void read_matrix(int mat[2][2],int r,int c)
{
    int i,j;
        for(i=0;i<r;i++)
        {
            printf("\n");
            for(j=0;j<c;j++)
            {
                printf("\t mat[%d][%d] = ",i,j);
                scanf("%d",&mat[i][j]);
            }
        }
}

void sum_matrix(int mat1[2][2],int mat2[2][2],int r, int c)
{
        int i,j,sum[2][2];
        for(i=0;i<r;i++)
        {
            for(j=0;j<c;j++)
            sum[i][j] = mat1[i][j] + mat2[i][j];
        }

        display_matrix(sum,r,c);
}

void display_matrix(int mat[2][2], int r, int c)
{
        int i,j;
        for(i=0;i<r;i++)
        {
            printf("\n ");
            for(j=0;j<c;j++)
            {
                printf("\t mat[%d][%d] = %d",i,j,mat[i][j]);
            }
        }
}

void mul_matrix(int mat1[2][2], int mat2[2][2], int r, int c)
{
    int i,j,prod[2][2],k;
    for(i=0;i<r;i++)
    {
        j=0;
        for(j=0;j<c;j++)
        {
            prod[i][j] = 0;
            for(k=0;k<c;k++)
            prod[i][j] += mat1[i][k] * mat2[k][j];
        }
        display_matrix(prod,r,c);

    }
}
void transpose_matrix(int mat[2][2], int r, int c)
{
    int i,j,tp_mat[2][2];
    for(i=0;i<r;i++)
    {
        for(j=0;j<c;j++)
        {
            tp_mat[i][j] = mat[j][i];
        }
    }
    display_matrix(tp_mat,r,c);
}
