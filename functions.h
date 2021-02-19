#ifndef UNTITLED17_FUNCTIONS_H
#define UNTITLED17_FUNCTIONS_H
typedef struct line {
    int n;
    double* arr;
} line;


typedef struct matrix {
    int m;
    line* pt;
} matrix;

int GetInt(int* a);
double Getdouble(double* b);
int countermax(matrix * matrix);
int countermin(matrix * matrix);
void mysort(int len,double* A);
void mysort2(int len,double* A);
void sortirovka(int k,int t,matrix* matrix);
void destroym(matrix* matrix);
void printvector(matrix* matrix,int k);
void printmatrix(matrix* matrix);
void input(matrix* matrix);
#endif
