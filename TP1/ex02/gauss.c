#include <stdio.h>
#include <stdlib.h>
#define N 10

float *remontee(float A[N][N], float B[N], int n)
{

  /******Implement the solution here******/
  /***************************************/
  float* x;
  x=malloc(sizeof(float)* n);
  x[n-1]=B[n-1]/A[n-1][n-1];
  
               for(int i=n-2;i>=0;i--){
		       float sum=0;
		       for(int j=i-1;j<n;j++){
	                       sum=sum+A[i][j]*x[j];
                         }
            x[i]=(B[i]-sum)/A[i][i];
    }
  return x;
}

float *gauss(float A[N][N] ,float B[N], int n)
{
  /******Implement the Gaussian elimination******/
  /**********************************************/
  

  /**********************************************/
  /*Resolve the system using the back substitution method*/
  /*You can use your solution of the exercice 1-b*/
	float *x;
	for(int k=0;k<n;k++){
		for(int i=k+1;i<n;i++){
			float q=A[i][k]/A[k][k];
			for(int j=k+1;j<n;j++){
				A[i][j]=A[i][j]-q*A[k][j];
			}
			B[i]=B[i]-q*B[k];
		}
	}
  x = remontee(A, B, n);
  return(x);
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
  x = gauss(A, B, n);

  /* Printing the results */
  printf("\nThe resulting vector: [");
  for (int i = 0; i < n; i++)
    printf("%f%c", x[i], ",]"[i == n - 1]);
}

