#include <stdio.h>
#include <stdlib.h>
#include "functions.h"
int countermin(matrix * matrix)
{
    double* c;
    double sum=0;
    double sum_min;
    int t;
    for (int i=0;i<((matrix->m));i++)
    {

        c = matrix->pt[i].arr;
        for (int j=0;j<matrix->pt[i].n;j++)
        {
            sum=sum+(*c);
            c++;
        }
        if((sum<sum_min) || (i==0))
        {
            sum_min=sum;
            t=i;
        }
        sum=0;
    }
    return t;
}

void mysort(int len,double* A)   // убывание
{
    double *ptr=A;
    int i = 0;
    while (i < len)
    {
        double x = *ptr;
        int j = i - 1;
        while ((j >= 0) && (x >= A[j]))
        {
            A[j + 1] = A[j];
            j--;
        }
        A[j + 1] = x;
        i++;
        ptr++;
    }
}
void mysort2(int len,double* A)
{
    double *ptr=A;
    int i = 0;
    while (i < len)
    {
        double x = *ptr;
        int j = i - 1;
        while ((j >= 0) && (x < A[j]))
        {
            A[j + 1] = A[j];
            j--;
        }
        A[j + 1] = x;
        i++;
        ptr++;
    }
}


//void mysortirovka(int k,matrix* matrix)
//{
//
//    double *ptr=matrix->pt[k].arr;
//    int i = 0;
//    while (i < matrix->pt[k].n)
//    {
//        double x = *ptr;
//        int j = i - 1;
//        while ((j >= 0) && (x < matrix->pt[k].arr[j]))
//        {
//            matrix->pt[k].arr[j + 1] = matrix->pt[k].arr[j];
//            j--;
//        }
//        matrix->pt[k].arr[j + 1] = x;
//        i++;
//        ptr++;
//    }
//}
//
//void mysortirovka2(int k,matrix* matrix)
//{
//    double *ptr=matrix->pt[k].arr;
//    int i = 0;
//    while (i < matrix->pt[k].n)
//    {
//        double x = *ptr;
//        int j = i - 1;
//        while ((j >= 0) && (x >= matrix->pt[k].arr[j]))
//        {
//            matrix->pt[k].arr[j + 1] = matrix->pt[k].arr[j];
//            j--;
//        }
//        matrix->pt[k].arr[j + 1] = x;
//        i++;
//        ptr++;
//    }
//
//
//}


int GetInt(int* a)
{
    int p;
    do {
        p = scanf("%d",a);
        if (p == 0) {
            printf("Error, try again.\n");
            scanf("%*[^\n]%*c");
        }
    }while(p==0);
    return p<0 ? 1 : 0;
}

double Getdouble(double* b)
{
    int i;

    i=scanf("%lf",b);
    while(i!=1)
    {
        printf("Error,try again.\n");
        scanf("%*[^\n]%*c");
        i=scanf("%lf",b);
    }
    return 0;
}

int countermax(matrix * matrix)
{
    double* c;
    double sum=0;
    double sum_max;
    int k;
    for (int i=0;i<((matrix->m));i++)
    {

        c = matrix->pt[i].arr;
        for (int j=0;j<matrix->pt[i].n;j++)
        {
            sum=sum+(*c);
            c++;
        }
        if((sum>sum_max) || (i==0))
        {
            sum_max=sum;
            k=i;
        }
        sum=0;
    }
    return k;
}


void sortirovka(int k,int t,matrix* matrix)
{
    int lenmax=matrix->pt[k].n;
    int lenmin=matrix->pt[t].n;
    mysort2(lenmax,(matrix->pt[k].arr));
    mysort(lenmin,(matrix->pt[t].arr)); //не к
//    if(*p<=0) //убывание
//    {
//        mysort(len,(matrix->pt[k].arr));
//    }
//    else{
//        mysort2(len,(matrix->pt[k].arr));
//    }
printf("/ / / / / /\n");
}

void destroym(matrix* matrix)
{
    double* ptr;
    for (int i=0;i<(matrix->m);i++)
    {
        ptr=matrix->pt[i].arr;
        free(ptr);
    }
    free(matrix->pt);
}

void printvector(matrix* matrix,int k)
{
    double* s=matrix->pt[k].arr;
    printf("Your vector is:\t");
    for (int i=0;i<(matrix->pt[k].n);i++)
    {
        printf(" %lf ",(*s));
        s++;
    }
    printf("\n");
}


void printmatrix(matrix* matrix)
{
    double* ptr;
    printf("Your matrix is:\n");
    for (int i=0;i<(matrix->m);i++)
    {
        ptr=(matrix->pt[i].arr);
        for (int j=0;j<(matrix->pt[i].n);j++,ptr++)
        {
            printf("%lf\t",(*ptr));
        }
        printf("\n");
    }
}

void input(matrix* matrix)
{
    int n;
    int m;
    double *ptr;
    do {
        printf("Enter number of strings.\n");
        GetInt(&m);
        if (m <= 0) {
            printf("Error, try again.\n");
        }
    } while (m <= 0);
    matrix->m = m;
    matrix->pt = (line *)malloc(sizeof(line) * m);
    for (int i = 0; i < m; i++) {
        do {
            printf("Number of elements in %d row.\n", i+1);
            GetInt(&n);
            if (n <= 0) {
                printf("Error, try again.\n");
            }
        } while (n <= 0);

        matrix->pt[i].n = n;
        matrix->pt[i].arr = (double *)malloc(sizeof(double) * n);
        ptr = matrix->pt[i].arr;
        for (int j = 0; j < n; j++,ptr++) {
            printf("Enter number of %d case of %d string.\n",j+1,i+1);
            Getdouble(ptr);
        }
    }
}
