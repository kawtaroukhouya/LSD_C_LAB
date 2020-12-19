#include <stdlib.h>
#include <stdio.h>
#define N 10

float *lu(float A[N][N], float B[N], int n)
{

  /******Implement the solution here******/
  /***************************************/
    //ly=B
	float *descente(float l[N][N],float B[N],int n)
	{
		float *x;
		x=malloc(sizeof(float) * n);
		x[0]=B[0]/l[0][0];

		for(int i=1;i<n;i++){
			float sum=0;
			for(int j=0;j<=i-1;j++){
				sum=sum+l[i][j]*x[j];
			}
			x[i]=(B[i]-sum)/l[i][i];
		}

  return (x);
}
//ux=Y
 float *remontee(float u[N][N],float y[N],int n)
{
	float *x;
	x=malloc(sizeof(float) * n);
	x[n-1]=y[n-1]/u[n-1][n-1];
	
	for(int i=n-2;i>=0;i--){
		float sum=0;
		for(int j=i;j<n;j++){
			sum=sum+u[i][j]*x[j];
		}
	x[i]=(y[i]-sum)/u[i][i];
	}
return x;
}

 float *lu(float a[N][N],float B[N],int n)
 {
	 float u[N][N];
	 float l[N][N];
	 float *y;
	 float *x;
	 for(int i=0;i<n;i++){
		 for(int j=0;j<n;j++){
			 if(i==j)
				 l[i][j]=1;
		 }
	 }
	 for(int i=0;i<n;i++){
		 u[0][i]=a[0][i];
	 }
	 for(int k=0;k<n-1;k++){
		 for(int i=k+1;i<n;i++){
			 l[i][k]=a[i][k]/a[k][k];
			 for(int j=k+1;j<n;j++){
				 a[i][j]=a[i][j]-l[i][k]*a[k][j];
				 if(i<=j)
					 u[i][j]=a[i][j];
			 }
		 
		 }
	 }
		 y=descente(l,B,n);
		 x=remontee(u,y,n);

 }

} 


int main()
{
  float   A[N][N], B[N];
  float   *x;
  int     n;

  printf("Enter the size of the matrix: ");
  scanf("%d", &n);

  /* Filling the matrix A */
  printf("Filling the matrix A\n");
  for(int i = 0; i < n; i++)
  {
    for(int j = 0; j < n; j++)
    {
      printf("A[%d][%d] = ", i, j);
      scanf("%f", &A[i][j]);
    }
  }

  /* Filling the vector B*/
  printf("Filling the matrix B\n");
  for (int i = 0; i < n; i++)
  {
    printf("B[%d] = ", i);
    scanf("%f", &B[i]);
  }

  /* The calculation of the result */
  x = lu(A, B, n);

  /* Printing the results */
  printf("\nThe resulting vector: [");
  for (int i = 0; i < n; i++)
    printf("%f%c", x[i], ",]"[i == n - 1]);
}

