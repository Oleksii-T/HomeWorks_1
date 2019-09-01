//
//  Created by OleksiiTarbeiev on 07/11/2016.
//  Copyright © 2016 OleksiiTarbeiev. All rights reserved.
//
//  Semester 1 | PA1 | Home Work 1 | Sails

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


/*
The task is to develop a program to compute how to produce a sail using standardized sheets of fabric.

We assume there is a fabric produced in rectangular sheets, the size of the sheet is known (width and height).
Next, there is a request to produce a rectangular sail (again, width and height is given). The program reads the
dimensions and computes the number of fabric sheets needed to produce the sail.

The computation is slightly more complicated, we assume there is an overlap needed in the places where the sheets are
sewed. Thus the program reads the size of the fabric, the size of the sail and compares them. If the fabric sheets
must be sewed, the program further asks for the width of the required overlap.

We assume the fabric sheets are sewed in a rectangular grid, i.e. all the rectangles are aligned in the same
orientation. Moreover, we assume that the extra material (that exceeds the size of the sail) must be discarded
(cannot be re-used).

The task is to develop a program to compute how to produce a sail using standardized sheets of fabric.

We assume there is a fabric produced in rectangular sheets, the size of the sheet is known (width and height).
Next, there is a request to produce a rectangular sail (again, width and height is given). The program reads the
dimensions and computes the number of fabric sheets needed to produce the sail.

The computation is slightly more complicated, we assume there is an overlap needed in the places where the
sheets are sewed. Thus the program reads the size of the fabric, the size of the sail and compares them. If
the fabric sheets must be sewed, the program further asks for the width of the required overlap.

We assume the fabric sheets are sewed in a rectangular grid, i.e. all the rectangles are aligned in the same
orientation. Moreover, we assume that the extra material (that exceeds the size of the sail) must be discarded
(cannot be re-used).

Sample program runs:

Sheet dimensions:
2.5 3
Sail dimensions:
12 5
Overlap:
0
Sheets: 8
--------------------------------
Sheet dimensions:
2.5 3
Sail dimensions:
12 5
Overlap:
0.2
Sheets: 12
--------------------------------
Sheet dimensions:
4 3
Sail dimensions:
5 4
Overlap:
0.1
Sheets: 2
--------------------------------
Sheet dimensions:
3 4
Sail dimensions:
2 2
Sheets: 1
--------------------------------
Sheet dimensions:
1e100 1e100
Sail dimensions:
3e100 3e100
Overlap:
1e99
Sheets: 16
--------------------------------
Sheet dimensions:
0.71 1
Sail dimensions:
4.91 1.7
Overlap:
0.01
Sheets: 14
--------------------------------
Sheet dimensions:
2 2
Sail dimensions:
5 1
Overlap:
1.5
Sheets: 7
--------------------------------
Sheet dimensions:
2 1
Sail dimensions:
5 1
Overlap:
1.5
Sheets: 7
--------------------------------
Sheet dimensions:
1 1
Sail dimensions:
5 1
Overlap:
1.5
No solution.
--------------------------------
Sheet dimensions:
3 abcd
Invalid input.
--------------------------------
Sheet dimensions:
-5 1
Invalid input.







Advice:

    Do not forget the newline (\n) after the last output line.
    Use double data type to represent the values. Do not use float, the precision of float is not always sufficient.
    The program can be developed without additional functions (i.e. in one big main). However, if divided into
    functions, the program is readable and easier to debug.
    All numeric values in the input fit into the range of double data type, the result fits into int data type.
    Please strictly adhere to the format of the output. The output must exactly match the output of the reference
    program. The comparison is done by a machine, the machine requires an exact match. If your program provides output
    different from the reference, the program is considered malfunctioning. Be very careful, the machine is sensitive
    event to whitespace characters (spaces, newlines, tabulators). Please note that all output lines are followed by
    a newline character (\n). This applies even to the last line of the output, moreover, this applies even to the
    error message. Download the enclosed archive. The archive contains a set of testing inputs and the expected outputs.
    Read Progtest FAQ to learn how to use input/output redirection and how to simplify testing of your programs.

    Your program will be tested in a restricted environment. The testing environment limits running time and available
    memory. The exact time and memory limits are shown in the reference solution testing log. However, neither time nor
    memory limit could cause a problem in this simple program. Next, the testing environment prohibits the use of
    functions which are considered "dangerous" (functions to execute other processes,
    functions to access the network, ... ). If your program uses such functions, the testing environment
    refuses to execute the program. Your program may use something like the code below:

       int main ( int argc, char * argv [] )
       {
        
         ...
            
         system ( "pause" );  prevent program window from closing 
         return 0;
       }
       

    This will not work properly in the testing environment - it is prohibited to execute other programs.
    (Even if the function were allowed, this would not work properly. The program would infinitely wait for a
    key to be pressed, however, no one will press any key in the automated testing environment. Thus, the program
    would be terminated on exceeded time limit.) If you want to keep the pause for your debugging and you want the
    program to be accepted by the Progtest, use the following trick:

       int main ( int argc, char * argv [] )
       {
        
         ...
       
       #ifndef __PROGTEST__
         system ( "pause" );  this is ignored by Progtest 
       #endif  __PROGTEST__ 
         return 0;
       } 
       

    Textual description of valid input data structure is not 100% exact. Since some students complained about it,
    we provide input language specification in EBNF:

        input      ::= { whiteSpace } fabric { whiteSpace } sail { whiteSpace } [ overlap { whiteSpace } ]
        whiteSpace ::= ' ' | '\t' | '\n' | '\r'
        fabric     ::= decimal { whiteSpace } decimal
        sail       ::= decimal { whiteSpace } decimal
        overlap    ::= decimal
        decimal    ::= [ '+' ] integer [ '.' integer [ ( 'e' | 'E' ) [ '+' | '-' ] integer ] ]  |
                       [ '+' ] '.' integer [ ( 'e' | 'E' ) [ '+' | '-' ] integer ]
        integer    ::= digit { digit }
        digit      ::= '0' | '1' | '2' | '3' | '4' | '5' | '6' | '7' | '8' | '9'
       



Submission deadline: 	2016-11-13 23:59:59 	 
Evaluation: 	4.5719
Max. assessment: 	5.0000 (Without bonus points)
Submissions: 	7 / 20 Free retries + 10 Penalized retries (-10 % penalty each retry)
Advices: 	1 / 2 Advices for free + 2 Advices with a penalty (-10 % penalty each advice)

*/

