
	//Rossler equation  using RK4

	#include <stdio.h>

	#include <math.h>


	/*equation of motion */

	#define g1(x1,x2,x3,t) -x2-x3

	#define g2(x1,x2,x3,t) x1+a*x2

	#define g3(x1,x2,x3,t) b+x3*(x1-c)

	#define randomize() srand ((unsigned) time (NULL))

	FILE *output;  

	int random_condition(void)

	{

	     int ran;

	     ran =rand()%10;

	     printf("generated random angle  is %d\n",ran);

	     return ran;
	
	}


	main()

		{

		int i,np,n,p,iteration;

		double pi,h,h2,h6,t,t0,dk11,dk21,dk31,dk41,dk12,dk22,dk32,dk42,dk13,dk23,dk33,dk43,dk14,dk24,dk34,dk44;

		double y1,y2,y3,y4,a,b,c,mu,omega;

		double x,y,z,x0,y0,z0;

		a=.2;	b=.20;	mu=-0.2;	

		omega=4.0;	pi =4*atan(1);	h=.001;

		h2=h/2.0;	h6=h/6.0;	iteration=1000;c=5.7;


	//printf("the value of h is %f\n",h);

	randomize(); 



	/* Runge-Kutta algorithm */

	output=fopen("rosslersystem.dat", "w"); 

	for(p=0;p<100;p++){

	x0 = 1*random_condition();

	y0 = 1*random_condition();

	z0=  1*random_condition();


	for (n=0;n<iteration;n++)  {

 
	  y1 = x0;

	  y2 = y0;

	  y3 = z0;

	  t=h*(n+1);


	//printf("the value of y1 is %f\n",y1);

	  dk11 = g1(y1,y2,y3,t);

	  dk21 = g2(y1,y2,y3,t);

	  dk31 = g3(y1,y2,y3,t);

	  dk12 = g1((y1+h2*dk11),(y2+h2*dk21),(y3+h2*dk31),(t+h2));

	  dk22 = g2((y1+h2*dk11),(y2+h2*dk21),(y3+h2*dk31),(t+h2));

	  dk32 = g3((y1+h2*dk11),(y2+h2*dk21),(y3+h2*dk31),(t+h2));


	  dk13 = g1((y1+h2*dk12),(y2+h2*dk22),(y3+h2*dk32),(t+h2));

	  dk23 = g2((y1+h2*dk12),(y2+h2*dk22),(y3+h2*dk32),(t+h2));

	  dk33 = g3((y1+h2*dk12),(y2+h2*dk22),(y3+h2*dk32),(t+h2));

	  dk14 = g1((y1+h2*dk13),(y2+h2*dk23),(y3+h2*dk33),(t+h2));

	  dk24 = g2((y1+h2*dk13),(y2+h2*dk23),(y3+h2*dk33),(t+h2));

	  dk34 = g3((y1+h2*dk13),(y2+h2*dk23),(y3+h2*dk33),(t+h2));


	  x    =x0+h6*(dk11+2.0*(dk12+dk13)+dk14);

	  y    =y0+h6*(dk21+2.0*(dk22+dk23)+dk24);

	  z    =z0+h6*(dk31+2.0*(dk32+dk33)+dk34);
  

	 if((n%100)==0){

	  // printf("the %dth loop\n ",n);

	  fprintf(output,"%f\t%f\t%f\t%f\n",t,x,y,z);

			}

	x0=x;

	y0=y;

	z0=z;

	  }

	fprintf(output,"\n"); 

	}
	
	  fclose(output);

	}	
