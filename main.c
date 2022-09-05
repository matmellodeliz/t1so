#include <windows.h>
#include<stdio.h>
#include<stdlib.h>

int main(){
int a[10][10],b[10][10],mul[10][10],linha,coluna,i,j,k;
system("cls");
printf("digite o numero de linhas=");
scanf("%d",&linha);
printf("digite o numero de colunas=");
scanf("%d",&coluna);
printf("digite os elementos da primeira matriz\n");
for(i=0;i<linha;i++)
{
for(j=0;j<coluna;j++)
{
scanf("%d",&a[i][j]);
}
}
printf("digite os elementos da segunda matriz\n");
for(i=0;i<linha;i++)
{
for(j=0;j<coluna;j++)
{
scanf("%d",&b[i][j]);
}
}

printf("matriz final da multiplicacao=\n");
for(i=0;i<linha;i++)
{
for(j=0;j<coluna;j++)
{
mul[i][j]=0;
for(k=0;k<coluna;k++)
{
mul[i][j]+=a[i][k]*b[k][j];
}
}
}
//for printing result
for(i=0;i<linha;i++)
{
for(j=0;j<coluna;j++)
{
printf("%d\t",mul[i][j]);
}
printf("\n");
}
return 0;
}
