#include <stdio.h>
#include <stdlib.h>
#include <math.h>

double f(double x)
{
  return x*x;
}

double leftrect(double from, double to, int n, double (*f)(double))
{
	/*
   double h = (to-from)/n;
   double sum = 0, x;
   for(x=from; x <= (to-from); x += h)
      sum += f(x);
   return h*sum;
*/
   double  h=(to-from)/n;
   double  x=from;
   double sum=0;
   int i;
    for( i=0;i<=n;i++)
        sum+=f(x);
        x+=h;
    return h*sum;

}


double rightrect(double from, double to, int n, double (*f)(double))
{
/*
   double h = (to-from)/n;
   double sum = 0, x;
   for(x=from; x <= (to-h); x += h)
     sum += f(x+h);
   return h*sum;
   */

   double sum=0;
   double  h=(to-from)/n;
   double x=from+h;
   int i;
   for(i=0;i<=n;i++)
        sum+=f(x);
        x+=h;
    return h*sum;

   }



double trapez(double from, double to, int n, double (*f)(double))
{
   /*double h = (to - from) / n;
   double sum = f(from) + f(to);
   int i;
   for(i = 1;i < n;i++)
       sum += 2*f( i * h);

   return  h * sum / 2;
   */
    double sum=0.5*(f(from)+f(to));
    double h=(to-from)/n;
    double  x=from+h;
    int i;
    for(i=0;i<n;i++)
        sum+=f(x);
        x=x+h;
    return h*sum;

}


double simpson(double from, double to, int n, double (*f)(double))
{
	/*
   double h = (to - from) / n;
   double sum1 = 0;
   double sum2 = 0;
   int i;

   double x;

   for(i = 0;i < n;i++)
      sum1 += f(from + h * i + h / 2);

   for(i = 1;i < n;i++)
      sum2 += f(from + h * i);

   return h / 6 * (f(from) + f(to) + 4 * sum1 + 2 * sum2);
   */
    double h=(to-from)/n;
    double x=from+h;
    double  z=from+h/2;
    double  sum1=0;
    double sum2=f(z);
    int i;
    for(i=0;i<n;i++){
	    z+=h;
            sum1+=f(x);
            sum2+=f(z);
            x+=h;
    }
    return (h/6)*(f(from)+f(to)+2*sum1+4*sum2);
}


int main()
{

        double from ;
        printf("Donner from :\n");
        scanf("%lf",&from);
        double to;
        printf("donner to:\n");
        scanf("%lf",&to);
        int n;
        printf("donner n:\n");
        scanf("%d",&n);
        printf("%lf\n",rightrect(from,to,n,f));
        printf("%lf\n",leftrect(from,to,n,f));
        printf("%lf\n",trapez(from,to,n,f));
 	printf("%lf\n",simpson(from,to,n,f));

	return 0;
}

