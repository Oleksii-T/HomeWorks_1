//
//  Created by OleksiiTarbeiev on 01/12/2016.
//  Copyright © 2016 OleksiiTarbeiev. All rights reserved.
//
//  Semester 1 | PA1 | HomeWork 4 |  Land ivestments

#include <stdio.h>
#include <assert.h>


int main_body_for_list ( int a[][2000], int parameter, int x, int y )
{

  int i, j, i0, j0, count=0;
  static int s[2000][2000];
  
          /***************************************/ 
  	 /*****#Begining of main solurion#*******/
  for (j0=0 ;j0<y ;j0++ )
  { /*-1-*/
    for (i0=0 ;i0<x ;i0++ )
    { /*-2-*/
 
         /*******************************/ 
  	 /*****#Clarifying Middle#*******/
      s[i0][j0] = a[i0][j0];
      if (s[i0][j0] == parameter)
        {
         printf ("%d @ (%d,%d) - (%d,%d)\n", parameter, i0, j0, i0, j0);
         count++;
        }   

        /***************************/ 
  	/*****#Filling edges#*******/ 

      for (i=1+i0 ;i<x ;i++)
      {	    
        s[i][j0] = s[i-1][j0] + a[i][j0] ;
        if (s[i][j0] == parameter)
        {
         printf ("%d @ (%d,%d) - (%d,%d)\n", parameter, i0, j0, i, j0);
         count++;
        }
      }   	     

      for (j=1+j0 ;j<y ;j++)
      {	     
        s[i0][j] = s[i0][j-1] + a[i0][j] ;
        if (s[i0][j] == parameter)
        {
         printf ("%d @ (%d,%d) - (%d,%d)\n", parameter, i0, j0, i0, j);
         count++;  	    
        }
      }	    
        /******************************/
	/*****#Filling the rest#*******/ 
	
      for (j=1+j0;j<y;j++)
      {
        for (i=1+i0;i<x;i++)
        {
          s[i][j] = s[i-1][j] + s[i][j-1] - s[i-1][j-1] + a[i][j] ;
          if (s[i][j] == parameter)
          {
           printf ("%d @ (%d,%d) - (%d,%d)\n", parameter, i0, j0, i, j);
           count++;
          }
        }   
      }
   } /*-2-*/

  } /*-1-*/    
  return count;
}

int main_body_for_count ( int a[][2000], int parameter, int x, int y )
{
  
  int i, j, i0, j0, count=0;
  static int s[2000][2000];
    
         /***************************************/ 
  	 /*****#Begining of main solurion#*******/
  for (j0=0 ;j0<y ;j0++ )
  { /*-1-*/
    for (i0=0 ;i0<x ;i0++ )
    { /*-2-*/
 
         /*******************************/ 
  	 /*****#Clarifying Middle#*******/
      s[i0][j0] = a[i0][j0];
      if (s[i0][j0] == parameter)
         count++;

        /***************************/ 
  	/*****#Filling edges#*******/ 

      for (i=1+i0 ;i<x ;i++)
      {	    
        s[i][j0] = s[i-1][j0] + a[i][j0] ;
        if (s[i][j0] == parameter)
         count++;
      }   	     

      for (j=1+j0 ;j<y ;j++)
      {	     
        s[i0][j] = s[i0][j-1] + a[i0][j] ;
        if (s[i0][j] == parameter)
         count++;  	    
      }	    
        /******************************/
	/*****#Filling the rest#*******/ 
	
      for (j=1+j0;j<y;j++)
      {
        for (i=1+i0;i<x;i++)
        {
          s[i][j] = s[i-1][j] + s[i][j-1] - s[i-1][j-1] + a[i][j] ;
          if (s[i][j] == parameter)
           count++;
        }   
      }
   } /*-2-*/

  } /*-1-*/    
  return count;  
}

int DefineWorldList (char a[7])
{
  if ( a[0] == 'l' && a[1] == 'i' && a[2] == 's' &&  a[3] == 't' && a[4] == '\0' ) 
    return 0;/*Entered world is 'list'*/
  else 
    return 1;/*Invalid*/    
}


int DefineWorldCount (char a[7])
{
  if ( a[0] == 'c' && a[1] == 'o' && a[2] == 'u' &&  a[3] == 'n' && a[4] == 't' && a[5] == '\0' ) 
    return 0;/*Entered world is 'count'*/
  else 
    return 1;/*Invalid*/    
}









int main ()
{

  int x, y, i, j, parameter, tmp;
  char string[7];
  static int ar[2000][2000];
   
  printf ("Map size:\n");
   
  if (scanf ("%d %d", &x, &y) != 2)
  {
   printf ("Invalid input.\n");
   return 1;
  }
  
  if (x > 2000 || y > 2000 || x < 1 || y < 1 )
  {
   printf ("Invalid input.\n");
   return 1;
  }

  printf ("Price map:\n");

  for (j=0;j<y;j++)
    for (i=0;i<x;i++)  
       if ( scanf ("%d", &ar[i][j]) != 1)
       {
        printf ("Invalid input.\n");
        return 1;   
       }


 printf ("Queries:\n");

while ( (tmp = scanf ("%6s %d", string, &parameter)) == 2 )
{  
 if ( DefineWorldList (string) == 0 )
  printf ("Total: %d\n", main_body_for_list (ar, parameter, x, y) );
  
 else if ( DefineWorldCount (string) == 0 )
  printf ("Total: %d\n", main_body_for_count(ar, parameter, x, y) );

 else 
 {
  printf ("Invalid input.\n");
  return 1;
 }
}

if (tmp == -1)
 return 0;
if (tmp != 2)
{
 printf ("Invalid input.\n");
 return 1; 
}



  return 0;
}





/*
The task is to develop a program to optimize parcel investments.

We assume a grid of land parcels. The size of the grid is known (1 to 2000 rows/columns), moreover, the price of the individual parcels is known. The price is an integer, it may be positive, zero, or negative. A negative (zero) price is acceptable, e.g. the land is an easement.

We want to invest money into the parcels. The investment is tricky, however. We may only invest into adjacent parcels that form a rectangular (square) shape. Moreover, we are searching for an investment where the sum of parcel prices is exactly equal to the invested money.

The program must understand two kinds of query. First, a query of type count x finds the total number of possible investments. Second, query of type list x is an extension of count x. It lists the individual parcels that match the query and the total number of possible investments.

The input of the program is:

    the size of the grid (width, height), both dimensions in the range 1 to 2000,
    the price of individual parcels in the grid. The prices are listed in a row-major order in the input,
    the queries.

A query is either count x or list x, where x is the amount of money to invest.

The output of the program are answers to the queries:

    count x answer is the total number of possible parcel allocations such that the allocations form a rectangle/square in the grid and the sum of parcel prices equals to x,
    list x delivers the list of possible parcel allocations plus the total number of allocations (like count x). The list of possible allocations consists of lines, each line represents one possible allocation:

        x @ (x1,y1) - (x2,y2) 
        

    where x1,y1 is upper left corner of the allocation and x2,y2 is the lower right corner of the allocation.

The program must validate input data. If the input is invalid, the program must detect it, it shall output an error message (see below) and terminate. If displayed, the error message must be displayed to the standard output (do not send it to the error output) and the error message must be terminated by a newline (\n). The input is considered invalid, if:

    grid dimensions are not numbers, or is outside the boundaries (1 to 2000),
    parcel price is not an integer,
    query is neither 'count' nor 'list',
    query parameter is not an integer.

Invest some time to think up the structure of the program. There is an upper limit of the grid size, thus static allocation may be adequate for the task. Next, the searching. A naive searching algorithm may require up to n6 time, there are improvements that decrease the searching time dramatically. The time limits in the testing environment are very benevolent. A sensible implementation of the naive algorithm passes all but bonus tests.

Sample program runs:

Map size:
5 6
Price map:
-13   9 -16  14   3
 11   7  -5  14   9
 -2  -5   9  -9  -4
 11  13   3   8 -16
 -1 -15   1  -4   2
  3   7  -8   0  27
Queries:
list 12
12 @ (0,3) - (2,4)
12 @ (0,4) - (4,5)
12 @ (2,2) - (2,3)
12 @ (4,0) - (4,1)
Total: 4
count 12
Total: 4
count 11
Total: 10
list 11
11 @ (0,1) - (0,1)
11 @ (0,3) - (0,3)
11 @ (0,2) - (0,5)
11 @ (0,1) - (1,2)
11 @ (0,2) - (1,5)
11 @ (0,2) - (3,5)
11 @ (1,0) - (1,2)
11 @ (1,1) - (3,2)
11 @ (2,2) - (3,3)
11 @ (2,3) - (3,3)
Total: 10
count -3
Total: 2
list -3
-3 @ (0,0) - (4,0)
-3 @ (2,4) - (3,4)
Total: 2
list 9
9 @ (0,1) - (0,2)
9 @ (0,2) - (0,3)
9 @ (0,0) - (0,5)
9 @ (0,0) - (2,5)
9 @ (0,2) - (3,4)
9 @ (1,0) - (1,0)
9 @ (1,0) - (1,4)
9 @ (1,2) - (4,5)
9 @ (2,2) - (2,2)
9 @ (2,1) - (3,1)
9 @ (2,1) - (3,2)
9 @ (2,1) - (3,5)
9 @ (2,0) - (4,4)
9 @ (2,1) - (4,3)
9 @ (2,2) - (4,5)
9 @ (3,1) - (3,4)
9 @ (3,1) - (3,5)
9 @ (4,1) - (4,1)
9 @ (4,2) - (4,5)
Total: 19
list 0
0 @ (1,1) - (1,4)
0 @ (1,2) - (1,5)
0 @ (1,0) - (2,5)
0 @ (1,2) - (3,5)
0 @ (2,1) - (2,5)
0 @ (2,2) - (3,2)
0 @ (2,2) - (3,5)
0 @ (2,3) - (3,5)
0 @ (3,5) - (3,5)
0 @ (3,1) - (4,4)
Total: 10
count 10000
Total: 0
------------------------------
Map size:
4 3
Price map:
1 -1 1 -1
-1 1 -1 1
1 -1 1 -1
Queries:
count 0
Total: 36
list 0
0 @ (0,0) - (1,0)
0 @ (0,0) - (3,0)
0 @ (2,0) - (3,0)
0 @ (1,0) - (2,0)
0 @ (0,0) - (0,1)
0 @ (0,0) - (1,1)
0 @ (1,0) - (1,1)
0 @ (0,0) - (2,1)
0 @ (1,0) - (2,1)
0 @ (2,0) - (2,1)
0 @ (0,0) - (3,1)
0 @ (1,0) - (3,1)
0 @ (2,0) - (3,1)
0 @ (3,0) - (3,1)
0 @ (0,0) - (1,2)
0 @ (0,0) - (3,2)
0 @ (2,0) - (3,2)
0 @ (1,0) - (2,2)
0 @ (1,1) - (2,1)
0 @ (0,1) - (1,1)
0 @ (0,1) - (3,1)
0 @ (2,1) - (3,1)
0 @ (0,1) - (0,2)
0 @ (0,1) - (1,2)
0 @ (1,1) - (1,2)
0 @ (0,1) - (2,2)
0 @ (1,1) - (2,2)
0 @ (2,1) - (2,2)
0 @ (0,1) - (3,2)
0 @ (1,1) - (3,2)
0 @ (2,1) - (3,2)
0 @ (3,1) - (3,2)
0 @ (0,2) - (1,2)
0 @ (0,2) - (3,2)
0 @ (2,2) - (3,2)
0 @ (1,2) - (2,2)
Total: 36
---------------------------
Map size:
1 12
Price map:
1 2 3
4 1 2 3 4 1 2
3 4
Queries:
count 0
Total: 0
list 9
9 @ (0,1) - (0,3)
9 @ (0,5) - (0,7)
9 @ (0,9) - (0,11)
Total: 3
count 10
Total: 9
list 10
10 @ (0,0) - (0,3)
10 @ (0,1) - (0,4)
10 @ (0,2) - (0,5)
10 @ (0,3) - (0,6)
10 @ (0,4) - (0,7)
10 @ (0,5) - (0,8)
10 @ (0,6) - (0,9)
10 @ (0,7) - (0,10)
10 @ (0,8) - (0,11)
Total: 9
buy 10
Invalid input.
---------------------------
Map size:
2 2
Price map:
1 2 3 test
Invalid input.




Advice:

    Do not forget the newline (\n) after the last output line.
    Use int data type to represent the prices.
    Coordinates (0,0) correspond to the upper left corner, x ccordinate grows to the right, y coordinate grows downwards.
    There is no need to dynamically allocate memory in this homework. Memory limits are big enough to allocate the price maps statically. However, there may not be enough space in the stack to allocate the price maps as local variables. An allocation in the data segment may solve the problem, see static keyword.
    The newlines in the input price maps do not have to follow the shape of the grid. In fact, the program may ignore the input newlines since the dimensions of the grid are known in advance.
    The number of parcel allocations may be huge in the bonus tests. The printing of all matching parcel allocations slows down the program. Therefore, the bonus tests only use count queries for huge inputs.
    There is not any exact rule how to order of the lines in the list answers. Your implementation may print the allocations in any order, the testing environment fixes the order before the comparison. For example input:

       Map size:
       4 3
       Price map:
       1 -1 1 -1
       -1 1 -1 1
       1 -1 1 -1
       Queries:
       list 0
       

    may result in:

       0 @ (0,0) - (1,0)
       0 @ (0,0) - (3,0)
       0 @ (2,0) - (3,0)
       0 @ (1,0) - (2,0)
       0 @ (0,0) - (0,1)
       0 @ (0,0) - (1,1)
       0 @ (1,0) - (1,1)
       0 @ (0,0) - (2,1)
       0 @ (1,0) - (2,1)
       0 @ (2,0) - (2,1)
       0 @ (0,0) - (3,1)
       0 @ (1,0) - (3,1)
       0 @ (2,0) - (3,1)
       0 @ (3,0) - (3,1)
       0 @ (0,0) - (1,2)
       0 @ (0,0) - (3,2)
       0 @ (2,0) - (3,2)
       0 @ (1,0) - (2,2)
       0 @ (1,1) - (2,1)
       0 @ (0,1) - (1,1)
       0 @ (0,1) - (3,1)
       0 @ (2,1) - (3,1)
       0 @ (0,1) - (0,2)
       0 @ (0,1) - (1,2)
       0 @ (1,1) - (1,2)
       0 @ (0,1) - (2,2)
       0 @ (1,1) - (2,2)
       0 @ (2,1) - (2,2)
       0 @ (0,1) - (3,2)
       0 @ (1,1) - (3,2)
       0 @ (2,1) - (3,2)
       0 @ (3,1) - (3,2)
       0 @ (0,2) - (1,2)
       0 @ (0,2) - (3,2)
       0 @ (2,2) - (3,2)
       0 @ (1,2) - (2,2)
       Total: 36 
       

    or:

       0 @ (0,0) - (0,1)
       0 @ (0,0) - (1,0)
       0 @ (0,0) - (1,1)
       0 @ (0,0) - (1,2)
       0 @ (0,0) - (2,1)
       0 @ (0,0) - (3,0)
       0 @ (0,0) - (3,1)
       0 @ (0,0) - (3,2)
       0 @ (0,1) - (0,2)
       0 @ (0,1) - (1,1)
       0 @ (0,1) - (1,2)
       0 @ (0,1) - (2,2)
       0 @ (0,1) - (3,1)
       0 @ (0,1) - (3,2)
       0 @ (0,2) - (1,2)
       0 @ (0,2) - (3,2)
       0 @ (1,0) - (1,1)
       0 @ (1,0) - (2,0)
       0 @ (1,0) - (2,1)
       0 @ (1,0) - (2,2)
       0 @ (1,0) - (3,1)
       0 @ (1,1) - (1,2)
       0 @ (1,1) - (2,1)
       0 @ (1,1) - (2,2)
       0 @ (1,1) - (3,2)
       0 @ (1,2) - (2,2)
       0 @ (2,0) - (2,1)
       0 @ (2,0) - (3,0)
       0 @ (2,0) - (3,1)
       0 @ (2,0) - (3,2)
       0 @ (2,1) - (2,2)
       0 @ (2,1) - (3,1)
       0 @ (2,1) - (3,2)
       0 @ (2,2) - (3,2)
       0 @ (3,0) - (3,1)
       0 @ (3,1) - (3,2)
       Total: 36 
       

    or any other of the remaining 371993326789901217467999448150835199999998 permutations.
    Textual description of valid input data structure is not 100% exact. Since some students complained about it, we provide input language specification in EBNF:

        input      ::= { whiteSpace } gridSize { whiteSpace } priceMap { whiteSpace } queryList 
        whiteSpace ::= ' ' | '\t' | '\n' | '\r'
        gridSize   ::= integer { whiteSpace } integer
        priceMap   ::= integer { { whiteSpace } integer }
        queryList  ::= { query { whiteSpace } }
        query      ::= ( 'list' | 'count' ) { whiteSpace } integer  
        integer    ::= ['+' | '-'] digit { digit }
        digit      ::= '0' | '1' | '2' | '3' | '4' | '5' | '6' | '7' | '8' | '9'
      






Submission deadline: 	2016-12-04 23:59:59 	 
Evaluation: 	7.2600
Max. assessment: 	5.0000 (Without bonus points)
Submissions: 	2 / 20 Free retries + 10 Penalized retries (-10 % penalty each retry)
Advices: 	2 / 2 Advices for free + 2 Advices with a penalty (-10 % penalty each advice)

*/
