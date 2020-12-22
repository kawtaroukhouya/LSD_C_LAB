#include <stdio.h>
#include <stdlib.h>
#include <math.h>
#define N 4


  /*
  ** What are you looking for ? \
  ** go ahead and code the solution by yourself. \
  ** you can always ask for help on slack.
  */


float cholesky(float c[N][N], float a[N][N],int n){
	//cholesky algorithm
	for(int j=0;j<n;j++){
		for(int i=j;i<n;i++){
			if(i==j){
				float sum1=0;
				for(int k=0;k<j;k++){
					sum1+=c[i][k]*c[i][k];
				}
				c[i][j]=sqrt(a[i][j]-sum1);
			}
			else{
				float sum2=0;
				for(int k=0;k<j;k++){
					sum2+=c[i][k]*c[j][k];
				}
				c[i][j]=(a[i][j]-sum2)/c[j][j];
			}
		}
	}
	return c[N][N];
}

int main(){
	int n;
	float a[N][N];
	float b[N];
	float x[N];
	float y[N];
	float c[N][N];
	printf("enter the dimension of the matrix ");
	scanf("%d", &n);
	for(int i=0;i<n; i++)
		for(int j=0; j<n;j++){
			printf("enter the value of a[%d][%d]=", i, j);
			scanf("%f", &a[i][j]);
			}

	for(int i=0;i<n;i++){
		printf("enter the value of b[%d]=", i);
		scanf("%f", &b[i]);
		}

	for(int i=0; i<n; i++){
		for(int j=0; j<n; j++){
			c[i][j]=0;
		}
	}

	printf("the c matric \n");

	//find the cholesky matrix
	c[N][N]=cholesky(c, a, 4);
	//printing  c
	for(int i=0;i<n;i++){
		for(int j=0;j<n;j++){
		printf("c[%d][%d] = %f\t",i, j, c[i][j]);
		}
		printf("\n");
	}
	//solve c(Transose)*y=b

	y[0]=b[0]/c[0][0];
	for(int i=1;i<n;i++){
		float sum1=0;
		for(int j=0;j<=i-1;j++){
			sum1+=c[i][j]*y[j];
		}
		y[i]=(b[i]-sum1)/c[i][i];
	}
	//printing y
	for(int i=0;i<n;i++){
		printf("y[%d]=%f\t",i, y[i]);
	}

	//sovle c*x=y

	x[n-1]=y[n-1]/c[n-1][n-1];

	for(int i=n-2;i>=0;i--){
		float sum2=0;
		for(int j=i;j<n;j++){
			sum2+=c[j][i]*x[j];
		}
		x[i]=(y[i]-sum2)/c[i][i];
	}
	//printing x
	printf("\n the final solution is :\n");
	for(int i=0; i<n;i++)
		printf("x[%d]=%f\t",i, x[i]);
}
