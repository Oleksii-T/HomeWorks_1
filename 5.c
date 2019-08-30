//
//  Created by OleksiiTarbeiev on 08/12/2016.
//  Copyright © 2016 OleksiiTarbeiev. All rights reserved.
//
//  Semester 1 | PA1 | HomeWork 5 |  Highway

#include <stdio.h>
#include <stdlib.h>
#include <limits.h>


int DefineWorlds (char a[10])
{
  if ( a[0] == 'c' && a[1] == 'o' && a[2] == 'n' &&  a[3] == 's' && a[4] == 't' &&
       a[5] == 'r' && a[6] == 'u' && a[7] == 'c' && a[8] == 't' && a[9] == '\0' ) 
    return 0;/*Entered world is 'construct'*/

  else if ( a[0] == 'l' && a[1] == 'i' && a[2] == 'm' &&  a[3] == 'i' && a[4] == 't' &&
    		a[5] == 's' && a[6] == '\0' )
    return 1;/*Entered world is 'limits'*/ 

  else if (a[0] == 'l' && a[1] == 'o' && a[2] == 'a' &&  a[3] == 'd' && a[4] == '\0' )
    return 2;/*Entered world is 'load'*/ 

  else 
    return 3;/*Invalid*/    
}

int DefineSqBrOpen (char a[1]) 
{
  if (a[0] == '[')
   return 0;/* entered symbol is '[' */
  else  
   return 1;/* Invalid input */
}

int DefineComaSqBrClose (char a[1])
{
  if (a[0] != ',')
  {
   if (a[0] == ']')
    return 0;/* entered symbol is ']'*/
   return 1;/* Invalid input. */
  }
  return 2;/* entered symbol is ',' */
}

int main ()
{

  int *a, i=-1, x, y, j, l, limits, min=0, tmp, spare1=0, ForRealloc=1;
  char string[10];
  
  
  printf ("Commands:\n");
  
     a =  (int*) calloc (ForRealloc, sizeof (int) ) ;    
 
while ( (tmp = scanf ("%9s", string)) == 1 )
{  
  spare1++;
  /****colculating wrong world************/ 
  if (DefineWorlds(string) == 3 )
  {
   printf ("Invalid input.\n");
   free(a);
   return 0;
  }
  
  /****colculating construct*************/   
  if (DefineWorlds(string) == 0)
  {
   	 scanf ("%1s", string);
     if (DefineSqBrOpen (string) != 0 )
     {
      printf ("Invalid input.\n");
      free(a);
      return 0;
     }
        
     
   	 for (i=i+1;;i++)
     {       
       if (scanf ("%d", &a[i] ) != 1 )
        { 
         printf ("Invalid input.\n");
         free(a);
         return 0;
        } 
        
       if (a[i] < 0)
       {
        printf ("Invalid input.\n");
        free(a);
        return 0;
       }
       
       
       scanf ("%1s", string);
       if ( DefineComaSqBrClose (string) == 0 )
       {
        ForRealloc++;
        a = (int*) realloc (a, ForRealloc*sizeof (int) );   
        break;
       }
       else if ( DefineComaSqBrClose (string) == 1 )
        {
         printf ("Invalid input.\n");
         free(a);
         return 0;
        }        
       ForRealloc++;
       a = (int*) realloc (a, ForRealloc*sizeof (int) );   
     }	
     /*for (spare=0;spare<=i;spare++)
      printf ("->Elements: %d[%d]\n", a[spare], spare);  */   
  }	
   
  
   
   
   
  /****colculating limits**************/
  else if (DefineWorlds(string) == 1 )
  {
	 if (scanf ("%d", &limits) != 1 )
	 {
	  printf ("Invalid input.\n");
	  free (a);
	  return 0;
	 }
	 
	 if ( limits > i || limits < 0)
	 {
	  printf ("Invalid input.\n");
	  free (a);
	  return 0;
	 }
	 
	 scanf ("%1s", string);
	 
     if (DefineSqBrOpen (string) != 0 )
     {
      printf ("Invalid input.\n");
      free(a);
      return 0;
     }
	 
	 for (j=0;;j++)
	 {
       if ( limits+j > i )
       {
        printf ("Invalid input.\n");
        free(a);
        return 0;
       }
	   if ( scanf ("%d", &y) != 1 )
	   {
	    printf ("Invalid input.\n");
	    free(a);
	    return 0;
	   }
	    
	   if (y < 0)
       {
        printf ("Invalid input.\n");
        free(a);
        return 0;
       }
    
       scanf ("%1s", string);	
       if ( DefineComaSqBrClose (string) == 0 )
       {
        a[limits+j] = y;
        /*printf (" Break. limits:%d   j:%d   limits+j:%d>\n", limits, j, limits+j);*/
        /*for (spare=0;spare<=i;spare++)
        printf ("->Elements(in limits break): %d[%d]\n", a[spare], spare); */ 
        break;
       }
       else if ( DefineComaSqBrClose (string) == 1 )
       {
        printf ("Invalid input.\n");
        free(a);
        return 0;
       }
       a[limits+j] = y;
	   /*printf (" limits:%d   j:%d   limits+j:%d>\n", limits, j, limits+j);*/
	  /*for (spare=0;spare<=i;spare++)
      printf ("->Elements(in limits): %d[%d]\n", a[spare], spare); */   
	 }
  }
  
  
  
  
  
  
  
  /****colculating load*****************/ 
  else if ( DefineWorlds(string) == 2 )
  {
    if ( scanf ("%d", &x) != 1 )
    {
     printf ("Invalid input.\n");
     free(a);
     return 0;
    }
    
    if ( scanf ("%d", &y) != 1 )
    {
     printf ("Invalid input.\n");
     free(a);
     return 0;
    }
    
    if (x > i || y > i || x > y || x < 0 || y < 0)
    {
     printf ("Invalid input.\n");
     free(a);
     return 0;
    }
    for (l=x;l<=y;l++)
    {
     if (l==x)
      min = a[l]; 
     /*printf ("\tl: %d\n", l); */
     if (a[l] < min)
      min = a[l]; 
     
    } 
     printf ("Max load: %d\n", min);      
  }

}  
if (tmp == -1)
{
 free(a);
 return 1;
}
if (tmp != 2)
{
 printf ("Invalid input.\n");
 free(a);
 return 0; 
}
	
return 1;
}

/*
The task is to develop a program that finds the maximum possible weight of a truck that drives on a highway.

We assume a single highway. The highway is divided by entrance ramps into individual sections. There is a maximum possible load assigned to each highway section. The load is defined either when the highway is constructed, or is changed later (e.g. when the highway is repaired). Transport companies need to follow the weight limits. I.e. the trucks may be loaded such that the weight does not exceed any limit of the highway section the truck drives. The program will help this computation, i.e. it will find the maximum possible load of a truck given a range of highway sections.

The program is interactive. It processes individual commands until it reaches end-of-file (EOF) in the standard input. The commands are of three kinds:

    construct [x,y,z, ...] This command is used to when new section(s) of the highway are constructed. There is a comma separated list of numbers in the square brackets, each number represent the maximum load of the newly constructed highway section. The loads in the list are positive integers. Naturally, this command extends the valid range of sections in the highway,
    limits x [u,v,w, ...] This command updates the loads of the referenced highway sections. The first section to update is section x (max load set to u), second updated section is x+1 (max load set to v), next updated section is x+2 (max load set to w), ...
    load x y This command finds the maximum load load of a truck that drives highway sections x, x+1, x+2, ..., y.

The output consists of answers to the load commands in the input.

The program must validate input data. If the input is invalid, the program must detect it, it shall output an error message (see below) and terminate. If displayed, the error message must be displayed to the standard output (do not send it to the error output) and the error message must be terminated by a newline (\n). The input is considered invalid, if:

    the input commend is neither construct, limits, nor load,
    the list of sections in construct command is invalid (missing square brackets, missing commas, invalid section loads - not positive integers, empty list),
    the parameters of limits command are invalid. Either the first section to update is not a valid section (not an integer, does not fit into the range of sections in the existing highway), or the list of loads is invalid (missing square brackets, missing commas, invalid section loads - not positive integers, empty list), or the command attempts to update the load of a section that is not constructed yet.
    the parameters of load command are invalid (must be integers in the range from 0 to the last section of the highway, the first section number must be smaller or equal to the last section number).

Invest some time to think up the structure of the program. There is not any explicit upper limit on the number of sections. Do not try to allocate some high fixed number of sections - such solution will not pass even the basic test (there are strict memory limits in the basic test). Your program memory requirements must be proportional to the size of the input.

The searching may be rather slow, especially if the number of highway sections is very high. The time limits are adjusted such that basic searching algorithm passes all tests except the bonus. An advanced algorithm is required to pass the bonus test. You may assume that the load commands are quite frequent. On the other hand construct and limits commands are rare. Thus it makes sense to invest some time to preprocess the input data.

Sample program runs:


Commands:
construct [10, 250, 30, 40]
load 0 3
Max load: 10
load 2 2
Max load: 30
limits 0 [100]
load 0 3
Max load: 30
load 0 1
Max load: 100
construct [90,30]
load 0 5
Max load: 30
limits 1 [ 80 , 60
,
30 , 10 ]
load 0 5
Max load: 10
-----------------------------------
Commands:
construct [10, 20, 30]
limits 3 [10]
Invalid input.
-----------------------------------
Commands:
construct [10, 20, 30]
load 2 1
Invalid input.
-----------------------------------
Commands:
construct [10, 20, 30]
load  0 abcd
Invalid input.
-----------------------------------
Commands:
load 0 0
Invalid input.




Advice:

    Do not forget the newline (\n) after the last output line.
    Use int data type to represent the loads/weights.
    The program requires dynamic memory allocation.
    Use C libraries to solve the problem. Do not use C++ (STL).
    The program requires a reasonable implementation of the input processing. If your implementation needs to increase the size of an array, do not increase the size by just one element.
    Textual description of valid input data structure is not 100% exact. Since some students complained about it, we provide input language specification in EBNF:

        input      ::= { whiteSpace } { command { whiteSpace } }
        whiteSpace ::= ' ' | '\t' | '\n' | '\r'
        command    ::= 'load' { whiteSpace } integer { whiteSpace } integer 
                     | 'limits' { whiteSpace } integer { whiteSpace } list 
                     | 'construct' { whiteSpace } list 
        list       ::= '[' { whiteSpace } integer { listRest } { whiteSpace } ']' { whiteSpace }             
        listRest   ::= { { whiteSpace } ','  { whiteSpace } integer }
        integer    ::= ['+' | '-'] digit { digit }
        digit      ::= '0' | '1' | '2' | '3' | '4' | '5' | '6' | '7' | '8' | '9'
      



Submission deadline: 	2016-12-11 23:59:59 	 
Evaluation: 	3.3000
Max. assessment: 	3.0000 (Without bonus points)
Submissions: 	12 / 20 Free retries + 10 Penalized retries (-10 % penalty each retry)
Advices: 	2 / 2 Advices for free + 2 Advices with a penalty (-10 % penalty each advice)
*/


