//
//  Created by OleksiiTarbeiev on 17/11/2016.
//  Copyright © 2016 OleksiiTarbeiev. All rights reserved.
//
//  Semester 1 | PA1 | HomeWork 2 |  Land lots

#include<stdio.h>
#include<stdlib.h>
#include<math.h>


int main () 
{

 
	double x, y; 

/*for1*/double spare1=0, spare2=0, mult1, mult2, sum1, sum2, sum3, substr1, substr2, area1,
               perimetr1, first1, first2;
	int n1=0;

/*for2*/double spare3=0, spare4=0, mult3, mult4, sum4, sum5, sum6, substr3, substr4, area2,
               perimetr2, first3, first4;
	int n2=0;








  /*  --------$$$$$$$&&&&&&&--------##---- Land lot #1 ----##-----------&&&&&&&$$$$$$$$--------  */

printf ("Land lot #1:\n") ;
while ( 1 )
{

	if ( scanf ("%lf %lf", &x, &y ) != 2 )
	{
 	 printf ("Invalid input.\n");
	 return 1;
	}



		/*
  		printf ("x: %lf\n", x);
  		printf ("y: %lf\n", y);
		*/

  n1++;





 	  	   			       /*  -----##---- Finding perimetr1 ----##-----------  */

  substr1 = x - spare2;
  substr2 = y - spare1;

  sum3 = substr1*substr1 + substr2*substr2;

  if (n1 == 1)
  {
   perimetr1 = 0 ;
  }
  else
  {
   perimetr1 += sqrt(sum3);
  }

		/*
 		 printf ("Perimetr: %lf \n", perimetr1);
		*/		

 	  	 			        /*  --------##---- Finding area1 ----##-----------  */

  mult1 = x * spare1;
  mult2 = y * spare2;

  sum1 += mult1;
  sum2 += mult2;

  spare1 = y;
  spare2 = x;


area1 = (sum2 - sum1)/2;

if ( area1 < 0 )
{
 area1 *= -1;
}


		/*
 		 printf ("Area1: %.20lf\n", area1);
		*/

 	  			               /*  -----##---- Cheking first variable ----##----  */ 

  if ( x == first1 && y == first2 )
  {
	if (n1 == 1 || n1 == 2 || n1 == 3)
	{
	 printf ("Invalid input.\n");
	 return 1;
	}	
   break ; 
  }


  if ( n1 == 1 )
  {
   first1 = x;
   first2 = y;
		/*
  		 printf ("If (n ==1)\n" );
		 printf ("first1: %lf\n", x);
		 printf ("first2: %lf\n\n", y);
		*/
  }

}
 	  	   			        /*  -----##---- Finding perimetr ----##-----------  */





  /*  --------$$$$$$$&&&&&&&--------##---- Land lot #2 ----##-----------&&&&&&&$$$$$$$$--------  */



printf ("Land lot #2:\n");
while ( 1 )
{
	
	if ( scanf ("%lf %lf", &x, &y ) != 2 )
	{
 	 printf ("Invalid input.\n");
	 return 1;
	}


		/*
  		printf ("x: %lf\n", x);
  		printf ("y: %lf\n", y);
		*/

  n2++;


  substr3 = x - spare4;
  substr4 = y - spare3;

  sum6 = substr3*substr3 + substr4*substr4;

  if (n2 == 1)
  {
   perimetr2 = 0 ;
  }
  else
  {
   perimetr2 += sqrt(sum6);
  }

		/*
 		 printf ("Perimetr(2): %lf \n", perimetr2);
		*/		

 	  	 			        /*  --------##---- Finding area ----##-----------  */ 

  mult3 = x * spare3;
  mult4 = y * spare4;

  sum4 += mult3;
  sum5 += mult4;

  spare3 = y;
  spare4 = x;
    

  area2 = (sum5 - sum4)/2;

if ( area2 < 0 )
{
 area2 *= -1;
}

		/*
 		 printf ("Area: %lf\n\n", (sum2 - sum1)/2);
		*/

 	  			               /*  -----##---- Cheking first variable ----##----  */ 

  if ( x == first3 && y == first4 )
  {
	if (n2 == 1 || n2 == 2 || n2 == 3 )
	{
	 printf ("Invalid input.\n");
	 return 1;
	}
   break ; 
  }


  if ( n2 == 1 )
  {
   first3 = x;
   first4 = y;
		/*
  		 printf ("If (n ==1)\n" );
		 printf ("first1: %lf\n", x);
		 printf ("first2: %lf\n\n", y);
		*/
  }

}



   						    /*  -----##---- Cheking third lot ----##----  */ 
									


	if ( scanf ("%lf %lf", &x, &y ) == 2 )
	{
 	 printf ("Invalid input.\n");
	 return 1; 
	}

  /*  ------$$$$$$$&&&&&&&--------##---- Conclusion of area----##---------&&&&&&&$$$$$$$$--------  */

if ( area1 < area2 && area2 - area1 < 0.001 )
{
area1 = area2 ;
}

if ( area2 < area1 && area1 - area2 < 0.001 )
{
area1 = area2 ;
}

if ( area1 == area2 )
{
  printf ("The areas are of the same size: %g\n", area1);
}
else if ( area1 < area2 )
{
  printf ("Area of land lot #2 (= %g) is greater than the area of land lot #1 (= %g).\n", area2, 
  area1);
}
else
{
  printf ("Area of land lot #1 (= %g) is greater than area of land lot #2 (= %g).\n", area1, area2);
}



  /*  ------$$$$$$$&&&&&&&-------##---- Conclusion of perimetr----##--------&&&&&&&$$$$$$$$-------  */

if ( perimetr1 < perimetr2 && perimetr2 - perimetr1 < 0.001 )
{
perimetr1 = perimetr2 ;
}

if ( perimetr2 < perimetr1 && perimetr1 - perimetr2 < 0.001 )
{
perimetr1 = perimetr2;
}

if  ( perimetr1 == perimetr2 )
{
  printf ("The perimeters are of equal length: %g\n", perimetr1);
}
else if ( perimetr1 < perimetr2 )
{
  printf ("Perimeter #2 (= %g) is longer than perimeter #1 (= %g).\n", perimetr2, perimetr1);
}
else
{
  printf ("Perimeter #1 (= %g) is longer than perimeter #2 (= %g).\n", perimetr1, perimetr2);
}



return 0;

}

/*
The task is to develop a program to compare two land lots.

We assume land lots in the shape of a convex polygon. A land lot is described by the vertices of the polygon. The vertices along the polygon's border are given in a sequence. The sequence starts in some vertex and ends in the starting vertex. Each vertex consists of two decimal numbers - vertex x and y coordinates.

The input of the program consists of two land lots - polygons. The program reads the polygons and computes the area and perimeter length of both input polygons.

The output of the program is the comparison of the polygons, i.e. the program compares the perimeter length and area of the input polygons (see below).

The program must validate input data. If the input is invalid, the program must detect it, it shall output an error message (see below) and terminate. If displayed, the error message must be displayed to the standard output (do not send it to the error output) and the error message must be terminated by a newline (\n). The input is considered invalid, if:

    any coordinate is not a decimal number,
    an input polygon is incomplete (does not reach the start point),
    there were fewer than 3 coordinates in an input polygon.

Please strictly adhere to the format of the output. The output must exactly match the output of the reference program. The comparison is done by a machine, the machine requires an exact match. If your program provides output different from the reference, the program is considered malfunctioning. Be very careful, the machine is sensitive event to whitespace characters (spaces, newlines, tabulators). Please note that all output lines are followed by a newline character (\n). This applies even to the last line of the output, moreover, this applies even to the error message. Download the enclosed archive. The archive contains a set of testing inputs and the expected outputs. Read Progtest FAQ to learn how to use input/output redirection and how to simplify testing of your programs.

Your program will be tested in a restricted environment. The testing environment limits running time and available memory. The exact time and memory limits are shown in the reference solution testing log. However, neither time nor memory limit could cause a problem in this simple program. Next, the testing environment prohibits the use of functions which are considered "dangerous" (functions to execute other processes, functions to access the network, ... ). If your program uses such functions, the testing environment refuses to execute the program. Your program may use something like the code below:

int main ( int argc, char * argv [] )
{
 
  ...
     
  system ( "pause" );  prevent program window from closing 
  return 0;
}

This will not work properly in the testing environment - it is prohibited to execute other programs. (Even if the function were allowed, this would not work properly. The program would infinitely wait for a key to be pressed, however, no one will press any key in the automated testing environment. Thus, the program would be terminated on exceeded time limit.) If you want to keep the pause for your debugging and you want the program to be accepted by the Progtest, use the following trick:

int main ( int argc, char * argv [] )
{
 
  ...

#ifndef __PROGTEST__
  system ( "pause" );  this is ignored by Progtest 
#endif  __PROGTEST__ 
  return 0;
} 

Sample program runs:

Land lot #1:
1 1
4 1
1 5
1 1
Land lot #2:
10 10
10 12
13 12
13 10
10 10
The areas are of the same size: 6
Perimeter #1 (= 12) is longer than perimeter #2 (= 10).
------------------------------------------
Land lot #1:
10 10
10 11
15 11
15 10
10 10
Land lot #2:
1 1
4 1
1 5
1 1
Area of land lot #2 (= 6) is greater than the area of land lot #1 (= 5).
The perimeters are of equal length: 12
------------------------------------------
Land lot #1:
0 0
-3 4
-3 9
1 12
11 12
6 0
0 0
Land lot #2:
0 0
0 20
10 20
10 0
0 0
Area of land lot #2 (= 200) is greater than the area of land lot #1 (= 126).
Perimeter #2 (= 60) is longer than perimeter #1 (= 44).
------------------------------------------
Land lot #1:
10 10
10 12.4
17 10
17 7.6
10 10
Land lot #2:
100 100
100 102.4
107.4 102.4
107.4 100
100 100
Area of land lot #2 (= 17.76) is greater than the area of land lot #1 (= 16.8).
The perimeters are of equal length: 19.6
------------------------------------------
Land lot #1:
10 10
10 12.4
17 10
17 7.6
10 10
Land lot #2:
100 100
100 102.4
107 102.4
107 100
100 100
The areas are of the same size: 16.8
Perimeter #1 (= 19.6) is longer than perimeter #2 (= 18.8).
------------------------------------------
Land lot #1:
0 0
0 1e100
1e100 0
0 0
Land lot #2:
0 0
0 1e100
-1e100 0
0 0
The areas are of the same size: 5e+199
The perimeters are of equal length: 3.41421e+100
------------------------------------------
Land lot #1:
1 1
2 1
1 2
1 hello
Invalid input.
------------------------------------------
Land lot #1:
1 1
2 1
1 2
1 hello
Invalid input.
------------------------------------------
Land lot #1:
0 0
1 0
0 1
0 0
Land lot #2:
0 0
0 -1
-1 test
Invalid input.












Advice:

    Do not forget the newline (\n) after the last output line.
    Use double data type to represent the values. Do not use float, the precision of float is not always sufficient.
    The program can be developed without additional functions (i.e. in one big main). However, if divided into functions, the program is readable and easier to debug.
    All input values as well as the output values fit into the range of double data type. The range of double is enough even if your program uses Heron's formula to compute the area. However, the formula must be modified to avoid overflow/underflow when multiplying.
    The resulting area and perimeter length may vary a bit based on the algorithm used. The testing environment accepts small differences up to 0.1 ‰
    The problem does not require any arrays. When used, the arrays just make the problem more difficult. Both the area and perimeter may be computed on-the-fly as the input coordinates are read. The input is a convex polygon. Thus it may be arbitrarily divided into a non-overlapping triangle fan. The area of individual triangles may be computed and aggregated.
    You do not need to test the convexity of the input polygons. Non-convex polygons are not tested.
    Textual description of valid input data structure is not 100% exact. Since some students complained about it, we provide input language specification in EBNF:

        input      ::= { whiteSpace } polygon { whiteSpace } polygon { whiteSpace } 
        whiteSpace ::= ' ' | '\t' | '\n' | '\r'
        polygon    ::= coord { whiteSpace } coord { whiteSpace } coord { { whiteSpace } coord }
        coord      ::= decimal { whiteSpace } decimal
        decimal    ::= [ '+' | '-' ] integer [ '.' integer [ ( 'e' | 'E' ) [ '+' | '-' ] integer ] ]  |
                       [ '+' | '-' ] '.' integer [ ( 'e' | 'E' ) [ '+' | '-' ] integer ]
        integer    ::= digit { digit }
        digit      ::= '0' | '1' | '2' | '3' | '4' | '5' | '6' | '7' | '8' | '9'
       



Submission deadline: 	2016-11-20 23:59:59 	 
Evaluation: 	2.4444
Max. assessment: 	3.0000 (Without bonus points)
Submissions: 	15 / 20 Free retries + 10 Penalized retries (-10 % penalty each retry)
Advices: 	2 / 2 Advices for free + 2 Advices with a penalty (-10 % penalty each advice)
*/







