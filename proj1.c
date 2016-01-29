#include <stdio.h>
#include <stdlib.h>
#include <math.h>
#include <stdbool.h>

/*
* Name: Hoyoung Jung
* Class: CSE251
* Project: proj1.c
* Due: 10/10/13
*
*	Complete the following table:
*	a		b		n		estimate
*	-1		1		1883	1.178979838
*	0		10		2028	.489888070
*	-1000	1000	18861	.999796418
*	10		15		1015	.016860599
*	.1		.2		138		.096211811
*
*  Program Description
*  This program promts the user for an input value of a and b
*  and computes a numberical estimate of the integral.
*/

int main()
{

	double error;				/*Error value with a starting value of 1*/
	int n;						/*The number of divisions*/
	double delta;				/*The width of the divisions*/
	double a;					/*The lower limit of the integration*/
	double b;					/*The upper limit of the integration*/
	double sum;					/*The Riemman sum*/
	double integral;			/*The Integral*/
	double x;					/*The value passed through the function*/
	double func;				/*The function of the integrals*/	
	double sump;				/*The previous sum*/
	double ip;					/*The previous integral*/	
	int i;						/*Counter*/		
	bool valid;					/*Boolean Variable*/

/* This function prompts the user for the lower and upper bounds of the integration */
	do
	{	
		valid = false;
		printf("Please enter the lower limit a: ");
		scanf("%lf", &a);
		printf("Please enter the upper limit b: ");
		scanf("%lf", &b);
		if (a>b)
		{
			printf("The lower bound cannot be greater than the upper bound.\n");
			printf("Please enter new bounds.\n");
			valid = false;
		}
		else if(a==b)
		{
			printf("The bounds cannot be the same.\n");
			printf("Please enter new bounds.\n");
			valid = false;
		}
		else
		{
			valid = true;
		}
	}while(!valid);
		
		
	printf("Integral Evaluation\n");
	
/* This function is a for loop to run the integration through the rectangular method runs until 100000 divisions are made or there is an error that is less than 1e-10 between integrations and also prints out the number of divisions, the integration, and the error.
*/
	
	sump = 1;
	for(n=10; n<=100000; n++)
	{
		sum = 0;
		for(i=1; i<=n; i++)
		{
			delta = (b-a)/n;
			x = (a + ((i - (.5)) * delta));
			if(x==0)
			{
				func = 1*delta;
			}
			else
			{
				func = ((sin(M_PI * x)/(M_PI*x)) * delta);
			}
			sum += func;
		}
		error = fabs(sum - sump);
		sump = sum;
		
/* This if statement checks if the error is less than 1e-10 and prints the first term that meets the error.*/
		if(error<1e-10)
		{
			printf("%d : %.9lf		%.9le \n", n, sum, error);
			exit(0);
		}
/* The next if and else if statements determine how to print the number of divisions, integral, and if to print the error or not*/
		if(n==10)
		{
			printf("%d : %.9lf		\n", n, sum);
		}
		else if(n!=10)
		{
			printf("%d : %.9lf		%.9le \n", n, sum, error);
		}
	}
}
