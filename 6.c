//
//  Created by OleksiiTarbeiev on 15/12/2016.
//  Copyright © 2016 OleksiiTarbeiev. All rights reserved.
//
//  Semester 1 | PA1 | HomeWork 6 |  Phone book

#include <stdio.h>
#include <string.h>
#include <stdlib.h>


void  removeNewLine    ( char * string )
{
  int l = strlen ( string );
  if ( l > 0 && string[l-1] == '\n' ) 
    string[l-1] = 0;
}


void  RemovingSpaces ( char * string )
{
 char * dst, * src;
 int    inSpaces;

  inSpaces = 1;
  dst     = string;
  src     = string;
  while ( *src )
  {
    if ( inSpaces )
    { 
      if ( *src != ' ' )
      {
        *dst++ = *src;
        inSpaces = 0;
      }
    }
    else
    {
      *dst++ = *src;
      if ( *src == ' ' ) 
        inSpaces = 1;
    } 
    src ++;
  }
  if ( inSpaces && dst > string ) 
    dst --; 
  *dst = 0;
}


struct LineStructure {
  char phone[22]; 
  char *name; 
};

int compare (char *s, char *p)
{
  int i;
  for (i=0;;i++)
  {
   if (p[i] == '\0')
     return 0;
   if (s[i] == p[i])
     continue;
   else 
    break;
  }
  return 1;
}

int T9 (char *s, char *p )     /* s - record(name or phone)  */
{                         /*       p - pattern          */

  int i;

  for (i=0;;i++)
  {
/*   printf ("i - %d\n", i);*/
    if (p[i] == '\0')
      return 0;
      
    else if ( (p[i] == '2') && (s[i] == 'a' || s[i] == 'b' || s[i] == 'c' ||
                                s[i] == 'A' || s[i] == 'B' || s[i] == 'C' ) )
       continue;    
    else if ( (p[i] == '3') && (s[i] == 'd' || s[i] == 'e' || s[i] == 'f' ||
			        s[i] == 'D' || s[i] == 'E' || s[i] == 'F') )
       continue;    
    else if ( (p[i] == '4') && (s[i] == 'g' || s[i] == 'h' || s[i] == 'i' ||
				s[i] == 'G' || s[i] == 'H' || s[i] == 'I') )
       continue;    
    else if ( (p[i] == '5') && (s[i] == 'j' || s[i] == 'k' || s[i] == 'l' ||
				s[i] == 'J' || s[i] == 'K' || s[i] == 'L') )
       continue;    
    else if ( (p[i] == '6') && (s[i] == 'm' || s[i] == 'n' || s[i] == 'o' ||
				s[i] == 'M' || s[i] == 'N' || s[i] == 'O') )
       continue;    
    else if ( (p[i] == '7') && (s[i] == 'p' || s[i] == 'q' || s[i] == 'r' || s[i] == 's'||
				s[i] == 'P' || s[i] == 'Q' || s[i] == 'R' || s[i] == 'S') )
       continue;    
    else if ( (p[i] == '8') && (s[i] == 't' || s[i] == 'u' || s[i] == 'v' || 
				s[i] == 'T' || s[i] == 'U' || s[i] == 'V') )
       continue;    
    else if ( (p[i] == '9') && (s[i] == 'w' || s[i] == 'x' || s[i] == 'y' || s[i] == 'z'||
				s[i] == 'W' || s[i] == 'X' || s[i] == 'Y' || s[i] == 'Z') )
       continue;    
    else if ( (p[i] == '1') && (s[i] == ' ') )
       continue;    
    else
    {
/*printf ("1. p[%d] - %c ; s[%d] - %c\n",i, p[i], i, s[i]);  */
      return 1;
    }

  }
/*printf ("2. p[%d] - %c ; s[%d] - %c\n",i, p[i], i, s[i]);  */
  return 0;
}


int CheckDigit (char * a)
{
 int l, i;
 l = strlen (a);
 for (i=0;i<l;i++)
 {
  if ( a[i]=='0' || a[i]=='1' || a[i]=='2' || a[i]=='3' || a[i]=='4' ||
       a[i]=='5' || a[i]=='6' || a[i]=='7' || a[i]=='8' || a[i]=='9' )
   continue;
  return 0;
 }
return 1;
}



int CheckLetters (char * a)
{
 int l, i;
 l = strlen (a);
 for (i=0;i<l;i++)
 {
  if ( (a[i] >= 'A' && a[i] <= 'Z') || (a[i] >= 'a' && a[i] <= 'z') || a[i] == ' ' )
   continue;
  return 1; /*OK*/
 }
return 0; /*Invalid*/
}




int main ()
{
  struct LineStructure *record;
  int i=0, j=-1, MallocName=0, MallocRecord=0, MallocPattern, tmp, spare;
  int total=0, total1=0, dublicates=0, j0, hell;
  char command, *pattern, spare1, therest;
  
  MallocRecord = 8;
  record = (struct LineStructure*) malloc ( MallocRecord*sizeof(struct LineStructure) );


while ( (tmp = scanf ("%c", &command)) == 1 )
{
/*  printf ("Command - '%c'\n", command);*/
  hell = 0;
/*******************************************************************************/
/*********************** Entered Command is invalid ****************************/

  if ( command != '+' && command != '?')
  {
   printf ("Invalid input.\n");
   therest = '#';
   while ( therest != '\n')
    scanf ("%c", &therest);
   continue;
  }


/***************************************************************************/
/*********************** Entered Command is '+' ****************************/

  else if ( command == '+' )
  {  
    MallocName = 0;

                  /* --> scaning one symbol and cheking is that '_' <-- */

    scanf ("%c", &spare1);
    if ( spare1 != ' ' )
  {
   if ( spare1 == '\n')
   {
    printf ("Invalid input.\n");
    continue;
   }
   printf ("Invalid input.\n");
   therest = '#';
   while ( therest != '\n')
    scanf ("%c", &therest);
   continue;
  }

                          /* --> scaning record[j].phone till '_' <-- */
    j++;

    if (j+1 > MallocRecord)
    {
     MallocRecord *= 2;    
record = (struct LineStructure*) realloc (record, MallocRecord * sizeof(struct LineStructure) );
    }

    for (i=0;;i++)
    { 
     scanf ("%c", &record[j].phone[i]);     

     if ((i==0 && record[j].phone[i] == ' ') || (i > 20) )
     {
      printf ("Invalid input.\n");
      j--;
      therest = '#';
      while ( therest != '\n')
       scanf ("%c", &therest);
/*    scanf ("%c", &therest); printf ("The Rest - %c\n", therest);*/
      hell = 666;
      break;
     }
     
     if (record[j].phone[i] == '\n')
     {
      printf ("Invalid input.\n");
      j--;
      hell = 666;
      break;
     }
     
     else if (i != 0 &&  record[j].phone[i] == ' ')
     {
      record[j].phone[i] = '\0';
      break; 
     }
    }
    
    if (hell == 666)
     continue ;
 
    if ( CheckDigit (record[j].phone) == 0)
     {
      printf ("Invalid input.\n");
      j--;
      therest = '#';
      while ( therest != '\n')
       scanf ("%c", &therest);
      continue ;
     }
    
                            /* --> scaning record[j].name <-- */

    MallocName = 8;
    record[j].name=(char*) malloc (MallocName*sizeof(char) ) ;

    for (i=0;;i++)
    {
      if (i+1 > MallocName)
      {
       MallocName *= 2;
       record[j].name= (char*)realloc(record[j].name,MallocName*sizeof(char));          
      } 

      scanf ("%c", &spare1);

      if ( i==0  && (spare1 == '\n' || spare1 == ' ') )
      {
        printf ("Invalid input.\n");
        free (record[j].name);
        j--;
        therest = '#';
        while ( therest != '\n')
         scanf ("%c", &therest);
        hell = 666;
        break;
      }

      if (spare1 == '\n') 
      {
        if (record[j].name[i-1] == ' ')
        {
          printf ("Invalid input.\n");
          free (record[j].name);
          j--;
          hell = 666;
          break;
        }
        record[j].name[i] = '\0';
        break; 
      }
      record[j].name[i] = spare1;
    }
    
    if (hell == 666)
     continue;

    if ( CheckLetters (record[j].name) == 1 )
      {
        printf ("Invalid input.\n");
        free (record[j].name);
        j--;
        continue;
      }

    RemovingSpaces (record[j].name); 
/* printf ("Name - '%s'\n", record[j].name);*/

                            /* --> cheking for dublicates <-- */

    for (i=j-1;i>=0;i--) 
    {
     if ( strcmp (record[j].phone, record[i].phone) == 0 && 
	  strcmp (record[j].name, record[i].name) == 0 )
     {
      dublicates++;
      break;
     }
    }
    
    if (dublicates == 0)
    {
      printf ("OK\n");
    }
    else if (dublicates != 0)  
    {
      printf ("Duplicate contact.\n");
      free (record[j].name);
      j--;
    }

    dublicates=0;
    continue ;  
  }


/***************************************************************************/
/*********************** Entered Command is '?' ****************************/
   
  else if ( command == '?' )
  {
    
               /* --> scaning one symbol and cheking is that '_' <-- */
    
    scanf ("%c", &spare1);
    if (spare1 != ' ')
    {
      if (spare1 == '\n')
      {
        printf ("Invalid input.\n");
        continue;
      }
      printf ("Invalid input.\n\n");
      therest = '#';
      while ( therest != '\n')
       scanf ("%c", &therest);
      continue;
    }
 
                            /* --> scaning pattern <-- */
                            
    MallocPattern = 8;
    pattern = (char*) malloc (MallocPattern * sizeof(char) ) ;

    for (i=0;;i++)
    {
      if (i+1 > MallocPattern)
      {
       MallocPattern *= 2;
       pattern = (char*) realloc (pattern, MallocPattern * sizeof(char) );
      } 

      scanf ("%c", &spare1);

      if ( i==0  && (spare1 == '\n' || spare1 == ' ') )
      {
        printf ("Invalid input.\n");
        free (pattern);
        therest = '#';
        while ( therest != '\n')
         scanf ("%c", &therest);
        hell = 666;
        break;
      }
      
      if (spare1 == '\n') 
      {
        pattern[i] = '\0';
        break; 
      }
      
      pattern[i] = spare1 ;
      
    }

    if (hell == 666 )
     continue;

    if ( CheckDigit (pattern) == 0 )
    {
      printf ("Invalid input.\n");
      free(pattern);
/*  printf ("Last rest - '%c'", therest);
      scanf ("%c", &therest);
      printf ("One more scanf - '%c'", therest);*/
      continue;
    }
   
   
         /* --> comparing pattern with each entered record and printing final answer<-- */

    for (spare=0;spare<=j;spare++)
    {
      if (compare(record[spare].phone,pattern)==0 || T9(record[spare].name,pattern) == 0)
        total++;     
      else
       continue; 
    }

    if (total<=10)
    {
      for (spare=0;spare<=j;spare++)
      {
       if (compare(record[spare].phone,pattern)==0||T9(record[spare].name,pattern) == 0)
       {
        printf ("%s %s\n", record[spare].phone, record[spare].name);
	    total1++;     
       }
       else
        continue; 
     }
     printf ("Total: %d\n", total1);
    }  
    else if (total>10)
      printf ("Total: %d\n", total);
    total1=0;
    total=0;
    free(pattern);
  }  
}



        /* --> a bit specifying of invalid input or correct reaching to the EOF <-- */
   
  if (tmp == -1) 
  {
   for (j0 = 0;j0 <= j;j0++) 
    free (record[j0].name);
   free (record);
   return 1;
  }
  if (tmp != 1)
  {
   printf ("Invalid input.\n");
   for (j0 = 0;j0 <= j;j0++) 
    free (record[j0].name);
   free (record);
   return 0; 
  }

 



return 1;
}

/*
The task is to develop a program that manipulates an electronic phone book.

Assume a simple phone book. The phone book keeps pairs phone number - name. The program further searches the phone book. The searches search either the phone number, or the name. Moreover, we do not have to specify complete phone/name, instead, we may only specify a prefix of the phone/name. The program searches the phone book and selects all records that match the given filter.

We assume the searches are in the form of a numbers. The numbers either denote (a prefix of) the phone number, or (a prefix of) a name in the T9 notation. That is, a search for name Vagner will look like 824637.

The program is interactive. It processes individual input lines until it reaches end-of-file (EOF) in the standard input. Each line represents one command. The commands are:

    + phone name This command adds a new record to the phone book. The number is a sequence of digits 0 to 9, the length of the phone is between 1 and 20 digits. Caution: leading zeroes are important. The number is any sequence of letters and spaces. The name cannot be empty, it must not start/end with a space. The character +, the phone and the name must be separated by exactly one space.
    ? number This command searches the phone book. The number is any sequence of digits 0-9, the length is at least one character (there is not an explicit upper limit). The character ? and the number are separated by exactly one space.

The output consists of answers to the commands in the input. The add command may result in:

    an error it the format is invalid,
    an error if the command adds a record that already exists in the phone book (an exact match of phone and name, including matching upper/lower case letters),
    OK if the new record has been inserted to the phone book.

The search command may result in:

    an error if the format is invalid,
    the list of matching records and the number of matching records. This format will be used if there is at most 10 matching results,
    the number of matching results (i.e. the records are not printed). This format will be used if there is more than 10 matching results.

The program must validate input data. If the input is invalid, the program must detect it, it shall output an error message (see below) and skip the processing of that command (proceed to the next input line). If displayed, the error message must be displayed to the standard output (do not send it to the error output) and the error message must be terminated by a newline (\n). The input is considered invalid, if:

    an unknown command (command does not start with + or ?),
    phone or name is missing in the add command,
    number is missing in the search command,
    phone / number does not consist of digits,
    name does not consist of letters / spaces,
    name starts or ends with a space,
    missing/extra spaces separating commands/phone/name,
    phone in the add command is longer than 20 digits.

Invest some time to think up the structure of the program. There is not any explicit upper limit on the number of records/length of the name. Use dynamic memory allocation and structures.

The searching may be rather slow, especially if the number of records is high. The time limits are adjusted such that basic searching algorithm passes all tests except the bonus. An advanced algorithm is required to pass the bonus test.

Sample program runs:

+ 123456 Vagner Ladislav
OK
+ 987654321 Vanerka Jiri
OK
+ 824637 Vagner Jiri
OK
+ 8244278 Balik Miroslav
OK
+ 8243245 Vaclavik
OK
+ 192837 Taggart John
OK
+ 98244212 Vogel Josef
OK
? 824
123456 Vagner Ladislav
824637 Vagner Jiri
8244278 Balik Miroslav
8243245 Vaclavik
192837 Taggart John
Total: 5
? 82
123456 Vagner Ladislav
987654321 Vanerka Jiri
824637 Vagner Jiri
8244278 Balik Miroslav
8243245 Vaclavik
192837 Taggart John
Total: 6
? 37
Total: 0
+ 1000001 Vacatko
OK
+ 1000002 Vaclavek
OK
+ 1000003 Vaclavkova
OK
+ 1000006 Vagner Ladislav
OK
+ 1000007 Vacek
OK
+ 1000008 Vachek
OK
+ 1000009 Varga
OK
? 824
123456 Vagner Ladislav
824637 Vagner Jiri
8244278 Balik Miroslav
8243245 Vaclavik
192837 Taggart John
1000006 Vagner Ladislav
Total: 6
? 82
Total: 13
+ 123456 Novakova
OK
? 123
123456 Vagner Ladislav
123456 Novakova
Total: 2
? 123456
123456 Vagner Ladislav
123456 Novakova
Total: 2
? 1234567
Total: 0
? 10000
1000001 Vacatko
1000002 Vaclavek
1000003 Vaclavkova
1000006 Vagner Ladislav
1000007 Vacek
1000008 Vachek
1000009 Varga
Total: 7
+ 123456 Novakova Jana
OK
+ 234567 Novakova Jana
OK
+ 123456 Novakova Jana
Duplicate contact.
+ 123456 Novakova Jana
Duplicate contact.
+ 123456 novakova Jana
OK
? 123456
123456 Vagner Ladislav
123456 Novakova
123456 Novakova Jana
123456 novakova Jana
Total: 4
-----------------------------------
+ 123456 test
OK
+ 1234567 test
OK
+ 123456 testtest
OK
+ 123456 test
Duplicate contact.
+ 123456    test
Invalid input.
+ 123456789012345678901234567890 foo
Invalid input.
? test
Invalid input.
?
Invalid input.
test
Invalid input.




Advice:

    The listings above (sample runs) use regular font to display user inputs and bold font to display program output. This formatting exists only here, on the WWW page, to increase readibility of the listings. The actual program must output just the text without any markup, see the attached files.
    Do not forget the newline (\n) after the last output line.
    Do not use int data type to represent phone numbers.
    The program requires dynamic memory allocation.
    Use C libraries to solve the problem. Do not use C++ (STL).
    The program requires a reasonable implementation of the input processing. If your implementation needs to increase the size of an array, do not increase the size by just one element.
    It is recommended to read the individual input lines and process them as strings.
    T9 codes (both lower and upper case letters):

       ABC    2
       DEF    3
       GHI    4
       JKL    5
       MNO    6
       PQRS   7
       TUV    8
       WXYZ   9
       space  1   
      

    The order of the phones in the answer is not specified. The testing environment adjusts the order of the lines before it actually compares the results.
    Textual description of valid input data structure is not 100% exact. Since some students complained about it, we provide input language specification in EBNF:

        input      ::= { command '\n' }
        command    ::= '+' ' ' phone ' ' name 
                     | '?' ' ' phone
        phone      ::= digit { digit }
        name       ::= letter { letter | ' ' } letter 
                     | letter
        digit      ::= '0' | '1' | '2' | '3' | '4' | '5' | '6' | '7' | '8' | '9'
        letter     ::= 'A' | 'B' | ... | 'Z' | 'a' | 'b' | ... | 'z'
      






Submission deadline: 	2016-12-18 23:59:59
Evaluation: 	5.5000
Max. assessment: 	5.0000 (Without bonus points)
Submissions: 	12 / 20 Free retries + 10 Penalized retries (-10 % penalty each retry)
Advices: 	2 / 2 Advices for free + 2 Advices with a penalty (-10 % penalty each advice)
*/









