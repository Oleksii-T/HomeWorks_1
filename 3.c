//
//  Created by OleksiiTarbeiev on 24/11/2016.
//  Copyright © 2016 OleksiiTarbeiev. All rights reserved.
//
//  Semester 1 | PA1 | HomeWork 3 |  Working days

#ifndef __PROGTEST__
#include <stdio.h>
#include <assert.h>
#endif /* __PROGTEST__ */

int IsWorkDay ( int y, int m, int d )
{

  int days, remainder, DaysInMonth=0, DaysInYear=0, count, count2, spare;

  if ( d < 1 || d > 31 ||
       m < 1 || m > 12 ||
       y < 2000 )
  {
   return 0; /* Invalid Input. */
  }
  

  if ( (d==1 && m==1) || (d==1 && m==5) || (d==8 && m==5) || (d==5 && m==7) || 
       (d==6 && m==7) || (d==28 && m==9) || (d==28 && m==10) || (d==17 && m==11) ||
       (d==24&& m==12) || (d==25 && m==12) || (d==26 && m==12) )
  {
 
   return 0 ; /* Non-working day. */
  }


  for ( count2 = 2000 ; count2 < y ; count2++ )
  {
   	if (count2%4!=0) 
	{ 				
 	 spare = 0 ;                  
	}
					
	else if (count2%100!=0)		
	{
 	 spare = 1 ;
	}

	else if (count2%400!=0)
	{
 	 spare = 0; 
	}

	else if (count2%4000!=0)
	{
	 spare = 1;
	}

	else
	{
  	 spare =  0;
	}
   
   if (spare == 0)
    {
     DaysInYear += 365 ;
    }
   if (spare == 1)
    {	
     DaysInYear += 366 ;
    }
  }

   	if (y%4!=0) 
	{ 				
 	 spare = 0 ;                    
	}
					 
	else if (y%100!=0)		 
	{
 	 spare = 1 ;
	}

	else if (y%400!=0)
	{
 	 spare = 0; 
	}

	else if (y%4000!=0)
	{
	 spare = 1;
	}

	else
	{
  	 spare =  0;
	}


  if ( (d > 28 && spare == 0 && m == 2) || (d > 29 && spare == 1 && m == 2) )
  {
   printf ("HERE\n");
   return 0; /* Invalid input. */
  }


  for ( count = 1 ; count < m ; count++ ) 	
  {
     if ((count==4 && d==31) || (count==6 && d==31) || (count==9 && d==31) || (count==11&&d==31))
      {
       return 0 ;  /* Invalid input. */  
      }

    if (count == 2 && spare == 0)
     {
      DaysInMonth += 28 ;
      continue ;
     } 
    else if ( count == 2 && spare == 1 )
     {
      DaysInMonth += 29 ;
      continue ;
     } 
    else if (count == 4 || count == 6 || count == 9 || count == 11 )
     {
      DaysInMonth += 30 ;
      continue ;
     }
    else
     {
      DaysInMonth += 31 ; 
     }

  } 

  days = d + DaysInMonth + DaysInYear ;

  remainder = days - ( (floor(days/7))*7 ) ;

  if ( remainder == 1 || remainder == 2 )
  {
    return 0 ; /* Non-working day. */
  }
  else 
  {
   return 1 ; /* Working day. */
  }

}






 /*******************111111111111******************/
 int CountingDays (int y, int m, int d)

{ 
  int days, DaysInMonth=0, DaysInYear=0, count, count2, spare;

  if (d < 1 || d > 31 ||
       m < 1 || m > 12 ||
       y < 2000 )
  {
   return 0; /*INVALID*/
  }
  for ( count2 = 2000 ; count2 < y ; count2++ )
  {
   	if (count2%4!=0) 
 	 spare = 0 ;                    
	else if (count2%100!=0)		 
 	 spare = 1 ;
	else if (count2%400!=0)
 	 spare = 0; 
	else if (count2%4000!=0)
	 spare = 1;
	else
  	 spare =  0;
   if (spare == 0)
     DaysInYear += 365 ;
   if (spare == 1)
     DaysInYear += 366 ;
  }
  	if (y%4!=0) 
 	 spare = 0 ;                    	 
	else if (y%100!=0)		 
 	 spare = 1 ;
	else if (y%400!=0)
 	 spare = 0; 
	else if (y%4000!=0)
	 spare = 1;
	else
  	 spare =  0;

  if ( (d > 28 && spare == 0 && m == 2) || (d > 29 && spare == 1 && m == 2) )
   return 0; /*INVALID*/
  for ( count = 1 ; count < m ; count++ ) 	
  {
    if (count == 2 && spare == 0)
     {
      DaysInMonth += 28 ;
      continue ;
     } 
    else if ( count == 2 && spare == 1 )
     {
      DaysInMonth += 29 ;
      continue ;
     } 
    else if (count == 4 || count == 6 || count == 9 || count == 11 )
     {
      DaysInMonth += 30 ;
      continue ;
     }
    else
      DaysInMonth += 31 ; 
  } 

  days = d + DaysInMonth + DaysInYear ;
  return days ;
} /*******************111111111111******************/







/*******************22222222222******************/
 int WhatIsDayDueToAmountOfDays ( int days)
{

  int remainder; 

    remainder = days - ( (floor(days/7))*7 ) ;

return days - ( (floor(days/7))*7 ) == 0;

}/***************22222222222222*******************/









/***************333333333333333*******************/
  int IsWorkDay_WithowtHolidays (int y, int m, int d) 
  {
 
  int days, remainder, DaysInMonth=0, DaysInYear=0, count, count2, spare;

  if ( d < 1 || d > 31 ||
       m < 1 || m > 12 ||
       y < 2000 )
  {
   return 0; /* Invalid Input. ****/
  }
   

  for ( count2 = 2000 ; count2 < y ; count2++ )
  {
   	if (count2%4!=0) 
	{ 			
 	 spare = 0 ;                     
	}
					 
	else if (count2%100!=0)		 
	{
 	 spare = 1 ;
	}

	else if (count2%400!=0)
	{
 	 spare = 0; 
	}

	else if (count2%4000!=0)
	{
	 spare = 1;
	}

	else
	{
  	 spare =  0;
	}
   
   if (spare == 0)
     DaysInYear += 365 ;
   if (spare == 1)
     DaysInYear += 366 ;

  }


   	if (y%4!=0) 
 	 spare = 0 ;                    
					 
	else if (y%100!=0)		 
 	 spare = 1 ;

	else if (y%400!=0)
 	 spare = 0; 

	else if (y%4000!=0)
	 spare = 1;

	else
  	 spare =  0;

  if ( (d > 28 && spare == 0 && m == 2) || (d > 29 && spare == 1 && m == 2) )
  {
   return 0; /* Invalid input. ****/
  }


  for ( count = 1 ; count < m ; count++ ) 	
  {
     if ((count==4 && d==31) || (count==6 && d==31) || (count==9 && d==31) || (count==11&&d==31))
      {
       return 0 ;  /* Invalid input. */  
      }

    if (count == 2 && spare == 0)
     {
      DaysInMonth += 28 ;
      continue ;
     } 
    else if ( count == 2 && spare == 1 )
     {
      DaysInMonth += 29 ;
      continue ;
     } 
    else if (count == 4 || count == 6 || count == 9 || count == 11 )
     {
      DaysInMonth += 30 ;
      continue ;
     }
    else
     {
      DaysInMonth += 31 ; 
     }

  } 

  days = d + DaysInMonth + DaysInYear ;

  remainder = days - ( (floor(days/7))*7 ) ;
 
  if ( remainder == 1 || remainder == 2 )
  {
    return 0 ; /* Non-working day. */
  }
  else 
  {
   return 1 ; /* Working day. */
  }
}/***************333333333333333*******************/













int CountWorkDays ( int y1, int m1, int d1,
                    int y2, int m2, int d2,
                    int * cnt )
{

  int days1, days2, count, holidays=0;

  *cnt=0;
  
     if ( (m1==4 && d1==31) || (m1==6 && d1==31) || (m1==9 && d1==31) || (m1==11 && d1==31) ||
          (m2==4 && d2==31) || (m2==6 && d2==31) || (m2==9 && d2==31) || (m2==11 && d2==31) ||
	  (y1>y2) || (y1==y2 && m1>m2) || (y1==y2 && m1==m2 && d1>d2) )
      {
       return 0 ;  /*INVALID*/   
      }

  if ( CountingDays (y1, m1, d1) == 0 || CountingDays (y2, m2, d2) == 0 )
  {
   return 0; /*UNSECCES*/
  }

  days1 = CountingDays (y1, m1, d1) ;

  days2 = CountingDays (y2, m2, d2) ;


  if (CountingDays (y2, m2, d2) == CountingDays (y1, m1, d1) 
       && IsWorkDay (y1, m1, d1) == 1 )
  {
   *cnt = 1 ;
   return 1; /* *cnt */
  }
  else if   (CountingDays (y2, m2, d2) == CountingDays (y1, m1, d1) 
             && WhatIsDayDueToAmountOfDays (days1) == 0 )
  {
   *cnt = 0 ;
   return 1; /* *cnt */
  }


  while ( days1 <= days2 )
  { 
    if ( WhatIsDayDueToAmountOfDays (days1) == 1 )
    {
     days1++ ;
     (*cnt)++ ;
     continue ;
    }
    if ( WhatIsDayDueToAmountOfDays (days1) == 0 )
    {
      days1++ ;
      continue ;
    } 
  }
  





if ( y1 != y2)
 { 
   
   for ( count = y1+1 ; count<=y2 ; count++ )
    {     
    			 
  /**/ if ( IsWorkDay_WithowtHolidays (count, 1, 1) == 1 )
	    holidays++ ;
	       	
	    	if ( (count==y2) && (m2 < 5)  )    	 
	    	 break ;


	    
  /**/ if ( IsWorkDay_WithowtHolidays (count, 5, 1) == 1 )
	    holidays++ ;
	    	    	
	    	if ( (count==y2) && (m2 <= 5) && (d2 < 8) )  
	    	 break ; 	


	    	    	
  /**/ if ( IsWorkDay_WithowtHolidays (count, 5, 8) == 1 )
	    holidays++ ;
	    
	        if ( (count==y2) && (m2 <= 7) && (d2 < 5) )
	         break ;  
	

	
  /**/ if ( IsWorkDay_WithowtHolidays (count, 7, 5) == 1 )
	    holidays++ ;
	    
	    	if ( (count==y2) && (m2 <= 7) && (d2 < 6) )
	         break ;   


	    
  /**/ if ( IsWorkDay_WithowtHolidays (count, 7, 6) == 1 )
	    holidays++ ;
	    
	    	if ( (count==y2) && (m2 <= 9) && (d2 < 28) )
	         break ;   


	    	
  /**/ if ( IsWorkDay_WithowtHolidays (count, 9, 28) == 1 )
	    holidays++ ;
	    
	    	if ( (count==y2) && (m2 <= 10) && (d2 < 28) )
	         break ;  


	    	
  /**/ if ( IsWorkDay_WithowtHolidays (count, 10, 28) == 1 )
	    holidays++ ;
	    
		    if ( (count==y2) && (m2 <= 11) && (d2 < 17) )
	         break ;   


	    	
  /**/ if ( IsWorkDay_WithowtHolidays (count, 11, 17) == 1 )
	    holidays++ ;

	    	if ( (count==y2) && (m2 <= 12) && (d2 < 24) )
	         break ;  
	    	


  /**/ if ( IsWorkDay_WithowtHolidays (count, 12, 24) == 1 )
	    holidays++ ;

	    	if ( (count==y2) && (m2 <= 12) && (d2 < 25) )
	         break ;   
	     	


  /**/ if ( IsWorkDay_WithowtHolidays (count, 12, 25) == 1 )
	    holidays++ ;	
	    
	    	if ( (count==y2) && (m2 <= 12) && (d2 < 26) )
	         break ;  	    
	    

  /**/ if ( IsWorkDay_WithowtHolidays (count, 12, 26) == 1 )
	    holidays++ ;
	
 
    }

   if ( (m1 < 1 && IsWorkDay_WithowtHolidays (y1, 1, 1) == 1) ||
        (m1 == 1 && d1 <= 1 && IsWorkDay_WithowtHolidays (y1, 1, 1) == 1) )
     holidays++ ;
  			     			  
   if ( (m1 < 5 && IsWorkDay_WithowtHolidays (y1, 5, 1) == 1) ||
        (m1 == 5 && d1 <= 1 && IsWorkDay_WithowtHolidays (y1, 5, 1) == 1) )
     holidays++ ;
 
   if (  (m1 < 5 && IsWorkDay_WithowtHolidays (y1, 5, 8) == 1) || 			
         (m1 == 5 && d1 <= 8 && IsWorkDay_WithowtHolidays (y1, 5, 8) == 1) )		
     holidays++ ;			 
 
   if (  (m1 < 7 && IsWorkDay_WithowtHolidays (y1, 7, 5) == 1) ||
	 (m1 == 7 && d1 <= 5 && IsWorkDay_WithowtHolidays (y1, 7, 5) == 1) )
     holidays++ ;	
 
   if (  (m1 < 7 && IsWorkDay_WithowtHolidays (y1, 7, 6) == 1) ||
	 (m1 == 7 && d1 <= 6 && IsWorkDay_WithowtHolidays (y1, 7, 6) == 1) )
     holidays++ ;
 
   if (  (m1 < 9 && IsWorkDay_WithowtHolidays (y1, 9, 28) == 1) ||
	 (m1 == 9 && d1 <= 28 && IsWorkDay_WithowtHolidays (y1, 9, 28) == 1) )
     holidays++ ;
      
   if (  (m1 < 10 && IsWorkDay_WithowtHolidays (y1, 10, 28) == 1) ||
	 (m1 == 10 && d1 <= 28 && IsWorkDay_WithowtHolidays (y1, 10, 28) == 1) )
     holidays++ ;
  
   if (  (m1 < 11 && IsWorkDay_WithowtHolidays (y1, 11, 17) == 1) ||
	 (m1 == 11 && d1 <= 17 && IsWorkDay_WithowtHolidays (y1, 11, 17) == 1) )
     holidays++ ;
 
   if (  (m1 < 12 && IsWorkDay_WithowtHolidays (y1, 12, 24) == 1) ||
	 (m1 == 12 && d1 <= 24 && IsWorkDay_WithowtHolidays (y1, 12, 24) == 1) )
     holidays++ ;
  
   if (  (m1 < 12 && IsWorkDay_WithowtHolidays (y1, 12, 25) == 1) ||
	 (m1 == 12 && d1 <= 25 && IsWorkDay_WithowtHolidays (y1, 12, 25) == 1) )
     holidays++ ;
 
   if (  (m1 < 12 && IsWorkDay_WithowtHolidays (y1, 12, 26) == 1) || 
  	 (m1 == 12 && d1 <= 26 && IsWorkDay_WithowtHolidays (y1, 12, 26) == 1) )
     holidays++ ;
     
 }
 else
 {
  if (  ( (m1==1 && d1<=1) || (m1 < 1) ) && 
	m2>=1 && d2>=1 && IsWorkDay_WithowtHolidays (y1, 1, 1) == 1 )
    holidays++ ;

  if (  ( (m1==5 && d1<=1) || (m1 < 5) ) && 
	m2>=5 && d2>=1 && IsWorkDay_WithowtHolidays (y1, 5, 1) == 1 )
    holidays++ ;

  if (  ( (m1==5 && d1<=8) || (m1 < 5) ) && 
        m2>=5 && d2>=8 && IsWorkDay_WithowtHolidays (y1, 5, 8) == 1 ) 
    holidays++ ;

  if (  ( (m1==7 && d1<=5) || (m1 < 7) ) && 
	m2>=7 && d2>=5 && IsWorkDay_WithowtHolidays (y1, 7, 5) == 1 )
    holidays++ ;

  if (  ( (m1==7 && d1<=6) || (m1 < 7) ) && 
	m2>=7 && d2>=6 && IsWorkDay_WithowtHolidays (y1, 7, 6) == 1 )
    holidays++ ;

  if (  ( (m1==9 && d1<=28) || (m1 < 9) ) && 
	m2>=9 && d2>=28 && IsWorkDay_WithowtHolidays (y1, 9, 28) == 1 )
    holidays++ ;

  if (  ( (m1==10 && d1<=28) || (m1 < 10) ) && 
	m2>=10 && d2>=28 && IsWorkDay_WithowtHolidays (y1, 10, 28) == 1 )
    holidays++ ;

  if (  ( (m1==11 && d1<=17) || (m1 < 11) ) && 
	m2>=11 && d2>=17 && IsWorkDay_WithowtHolidays (y1, 11, 17) == 1 )
    holidays++ ;

  if (  ( (m1==12 && d1<=24) || (m1 < 12) ) && 
	m2>=12 && d2>=24 &&  IsWorkDay_WithowtHolidays (y1, 12, 24) == 1 )
    holidays++ ;

  if (  ( (m1==12 && d1<=25) || (m1 < 12) ) && 
	m2>=12 && d2>=25 && IsWorkDay_WithowtHolidays (y1, 12, 25) == 1 )
    holidays++ ;

  if (  ( (m1==12 && d1<=26) || (m1 < 12) ) &&  
	m2>=12 && d2>=26 && IsWorkDay_WithowtHolidays (y1, 12, 26) == 1 )
    holidays++ ;


 }

*cnt = *cnt - holidays ;

 return 1;/* *cnt */
}



#ifndef __PROGTEST__
int main ( int argc, char * argv [] )
{
  int cnt;

  assert (   IsWorkDay ( 2016, 11, 11 ) );
  assert ( ! IsWorkDay ( 2016, 11, 12 ) );
  assert ( ! IsWorkDay ( 2016, 11, 17 ) );
  assert ( ! IsWorkDay ( 2016, 11, 31 ) );
  assert (   IsWorkDay ( 2016,  2, 29 ) );
  assert ( ! IsWorkDay ( 2004,  2, 29 ) );
  assert ( ! IsWorkDay ( 2001,  2, 29 ) );
  assert ( ! IsWorkDay ( 1996,  1,  1 ) );

assert ( CountWorkDays ( 2016, 11, 1, 2016, 11, 30, &cnt ) == 1 && cnt == 21 ); /*0*/
  
assert ( CountWorkDays ( 2016, 11, 1, 2016, 11, 17, &cnt ) == 1 && cnt == 12 ); /*1*/
  
assert ( CountWorkDays ( 2016, 11, 1, 2016, 11,  1, &cnt ) == 1 && cnt == 1 ); /*2*/
  
assert ( CountWorkDays ( 2016, 11, 17, 2016, 11, 17, &cnt ) == 1 && cnt == 0 ); /*3*/
  
assert ( CountWorkDays ( 2016,  1, 1, 2016, 12, 31, &cnt ) == 1 && cnt == 254 ); /*4*/

assert ( CountWorkDays ( 2015,  1, 1, 2015, 12, 31, &cnt ) == 1 && cnt == 252 ); /*5*/
  
assert ( CountWorkDays ( 2000,  1, 1, 2016, 12, 31, &cnt ) == 1 && cnt == 4302 ); /*6*/
  
assert ( CountWorkDays ( 2001,  2, 3, 2016,  7, 18, &cnt ) == 1 && cnt == 3911 ); /*7*/
  
assert ( CountWorkDays ( 2014,  3, 27, 2016, 11, 12, &cnt ) == 1 && cnt == 666 ); /*8*/
  
assert ( CountWorkDays ( 2001,  1, 1, 2000,  1,  1, &cnt ) == 0 ); /*9*/
  
assert ( CountWorkDays ( 2001,  1, 1, 2015,  2, 29, &cnt ) == 0 ); /*10*/



  return 0;
}
#endif /* __PROGTEST__ */

/*

The task is to implement two functions (not a whole program, just two functions) which handle working day
computations. The required functions are:

int IsWorkDay ( int y, int m, int d )
    The function decides whether the date (given in the parameters) is a working day, or not. The parameters are year,
    month, and day to test. Return value is integer 1 if the date is a working day, or integer 0 otherwise (the date is
    Sunday, Saturday, a national holiday, or the date is invalid).
int CountWorkDays ( int y1, int m1, int d1, int y2, int m2, int d2, int * cnt )
    The function shall count working days in the given interval of days. The interval is given by the start and end
    dates. Start date is formed by year, month, and day y1, m1, and d1, end date is formed by y2, m2, and d2. The
    interval is considered closed, i.e. both boundary days are included in the computation. Return value is either 1
    to indicate success or 0 to indicate an error. If the function succeeds, it places the resulting number of working
    days into the output parameters cnt. The function fails if the input parameters are invalid (see below).

The input parameters must define a valid date. To be valid, the input must satisfy the following restrictions:

    year must be greater than or equal to 2000 (i.e. all dates before 2000-01-01 are invalid),
    month is valid (1 to 12),
    day is valid (1 to the number of days in the month),
    in CountWorkDays: the end timestamp must not precede the start timestamp.

Submit a source file with the implementation of both required functions (IsWorkDay and CountWorkDays). Further, the
source file must include your auxiliary functions which are called from the required functions.The function will be
called from the testing environment, thus, it is important to adhere to the required interface. Use the attached sample
code as a basis for your development, complete the required functions and add your required auxiliary functions. There is
an example main with some test in the attached code. These values will be used in the basic test. Please note the header
files as well as main is nested in a conditional compile block (#ifdef/#endif). Please keep these conditional compile
block in place. They are present to simplify the development. When compiling on your computer, the headers and main will
be present as usual. On the other hand, the header and main will "disappear" when compiled by Progtest. Thus, your testing
main will not interfere with the testing environment's main.

Your function will be executed in a limited environment. There are limits on both time and memory. The exact limits
are shown in the test log of the reference. The time limits are set such that a correct implementation of the naive
solution passes all mandatory tests. Thus, the solution may be awarded nominal 100%. The algorithm must be improved
to pass the bonus tests and gain the extra points. There are long intervals tested in the bonus tests (years exceed
4000 several orders of magnitude).






Advice:

    Monday to Friday are considered working days. Moreover, national holidays are not considered working days. We use
    the following list of national holidays (actually the national holidays in the Czech Republic):

        1.1, 1.5, 8.5, 5.7, 6.7, 28.9, 28.10, 17.11, 24.12, 25.12, and 26.12
       

    Please note Easter is not included in the list. The computation of Easter is a bit more complicated (Moon phase is
    required), thus Easter is not used in this homework.

    We assume standard Gregorian calendar when counting days. Thus, there is a fixed number of days (30/31) in a month,
    with the exception of February. February is either 28 days (non-leap year) or 29 days (a leap year). The leap year
    rules of Gregorian calendar are:
        years are not leap years in general,
        except multiples of 4 which are leap years,
        except multiples of 100 which are not leap years,
        except multiples of 400 which are leap years,
        except multiples of 4000 which are not leap years.

    Thus, years 2001, 2002, 2003, 2005, ... are not leap years (rule #1), years 2004, 2008, ..., 2096, 2104, ... are
    leap years (rule #2), years 2100, 2200, 2300, 2500, ... are not leap years (rule #3), years 2000, 2400, ..., 3600,
    4400, ... are leap years (rule #4), and years 4000, 8000, ... are not leap years (rule #5).
    Download the attached sample code and use it as a base for your development.
    The main function in your program may be modified (e.g. a new test may be included). The conditional compile block
    must remain, however.
    It is difficult to handle 3-tuples like (year, month, day). It is a good idea to convert the 3-tuple into some other
    representation, e.g. into a single integer.
    There will be a lot of computation done twice in the program: for the start and end timestamps. Thus, it is a good
    idea to prepare auxiliary functions and call them twice.
    The years in the mandatory tests do not exceed 2200.
    There is macro assert used in the example main function. If the value passed to assert is nonzero (true), the macro
    does nothing. On the other hand, if the parameter is zero, the macro stops the execution and reports line, where
    the test did not match (and shall be fixed). Thus, the program ends silently when your implementation passes the
    tests correctly.



 Submission deadline:    2016-11-27 23:59:59
 Evaluation:    4.9641
 Max. assessment:    5.0000 (Without bonus points)
 Submissions:    4 / 20 Free retries + 10 Penalized retries (-10 % penalty each retry)
 Advices:    0 / 2 Advices for free + 2 Advices with a penalty (-10 % penalty each advice)
*/
