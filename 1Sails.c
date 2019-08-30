//
//  Created by OleksiiTarbeiev on 07/11/2016.
//  Copyright © 2016 OleksiiTarbeiev. All rights reserved.
//

#include<stdio.h>
#include<stdlib.h>
#include<math.h>


int main () 
{

	double a, b, c, d, e, count1, count2, count3, count4, count1form, count2form, count3form, 
               count4form; 
	int case1, case2;
	
	

 printf ("Sheet dimensions:\n");
 
	if ( scanf ("%lf %lf", &a, &b ) != 2  || a <= 0 || b <= 0 )
	{
	  printf ("Invalid input.\n");
	  return 1;
	}

 printf ("Sail dimensions:\n");
 
	if ( scanf ("%lf %lf", &c, &d ) != 2 || c <= 0 || d <= 0  )
	{
	  printf ("Invalid input.\n");
	  return 1;
	}

		if (a*b > c*d)    
		{
 		 printf ("Sheets: 1\n");
         	 return 1;
		} 

 printf ("Overlap:\n");

 		if ( e < 0 || scanf ("%lf", &e ) != 1 )
		{
		 printf ("Invalid input.\n");
		 return 1;
		}

	if ( e >= a*b )
        {
         printf ("No solution.\n");
	 return 1;
        }



			 /* ####-----------------case 1-----------------#### */

						/* (1) */


 count1form = (c-e) / (a-e) ;
if ( fabs( (double)count1form - floor(count1form) ) < 0.00000000001 * floor(count1form)  )
{ 
count1 = floor (count1form);

}
else
{
count1 = ceil (count1form);
}
	/*Cheking
	printf ("count1: %d\n", count1);
	*/


						/* (2) */

count2form = (d-e) / (b-e);
if ( fabs( (double) count2form - floor (count2form) ) < 0.00000000001 * floor (count2form) )
{ 
count2 = floor (count2form);
}
else
{
count2 = ceil (count2form);
}
	/*Cheking
	printf ("count2: %d\n", count2);
	*/

						/* (3) */

case1 = count1 * count2 ;


	if (case1 < 0 )
	{
	case1 = case1 * (-1) ;
	}

	/*Cheking
	printf ("(case1)Sheets: %d\n", case1);
	*/


			/* ####-----------------case 2-----------------#### */
						/* (1) */

count3form = (c-e) / (b-e) ;

if ( fabs( (double)count3form - floor (count3form) ) < 0.00000000001 * floor (count3form) )
{ 
count3 = floor (count3form);
}
else
{
count3 = ceil (count3form);
}

	/*Cheking
	printf ("%d\n", count3);
	*/

						/* (2) */

count4form =  (d-e) / (a-e) ;
if ( fabs( (double)count4form - floor(count4form) ) < 0.00000000001 * floor(count4form) )
{ 
count4 = floor(count4form);
}
else
{
count4 = ceil (count4form);
}

	/*Cheking
	printf ("%d\n", count4);
	*/

						/* (3) */

case2 = count3 * count4 ;

	if (case2 < 0 )
	{
	case2 = case2 * (-1) ;
	}

		/* ####-----------------Clarify the result-----------------#### */


		if (case1 <= case2 )
		{
		printf ("Sheets: %d\n", case1);
		}
		else
		{
		printf ("Sheets: %d\n", case2);
		}




return 0;

}