#include <stdio.h>
int main(){
    int A[3][3],B[3][3],C[3][3];
    int i,j,k;
    printf("enter the first matrix:\n");
    for(i=0;i<3;i++)
{
    for(j=0;j<3;j++)
    {scanf("%d",&A[i][j]);}
}
printf("enter the second matrix:\n");
    for(i=0;i<3;i++)
{
    for(j=0;j<3;j++)
    {scanf("%d",&B[i][j]);}
}
for(i=0;i<3;i++)
{
    for(j=0;j<3;j++)
{    C[i][j]=0;
 for(k=0;k<3;k++)
{ C[i][j]+=A[i][k]*B[k][j];}}}
printf("the resultent matrix:\n");
    for(i=0;i<3;i++)
{
    for(j=0;j<3;j++)
    {printf("%d\t",C[i][j]);}
    printf("\n");
}
return 0;
}