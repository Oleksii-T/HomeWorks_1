//
//  Created by OleksiiTarbeiev on 29/12/2016.
//  Copyright © 2016 OleksiiTarbeiev. All rights reserved.
//
//  Semester 1 | PA1 | HomeWork 8 |  People database

#ifndef __PROGTEST__
#include <stdio.h>
#include <assert.h>
#include <stdlib.h>
#include <string.h>

typedef struct TResult {
   struct TResult * m_Next;
   int m_ID;
   char * m_Name;
 } TRESULT;



#endif /* __PROGTEST__ */

typedef struct ResultList {
   TRESULT * head1;
   TRESULT * tail1;
} RESULTLIST;
 
typedef struct rec {
   int ID;
   char * name;
   struct rec * par1;  /*par1 and par2 is pointers to strecture which*/
   struct rec * par2;   /* are act as parent1 and parent2 for current*/
   struct rec * next;            /* struct, respectively */
} RECORD;

typedef struct datebase {
   RECORD * head;
   RECORD * tail;
} DB;

 DB * list; /* global datebase variabal  */


	void CancelBublicates( TRESULT *head1)
	{
	  TRESULT *tmp1, *tmp2, *sapre;
	  tmp1 = head1;
 
	  while(tmp1 != NULL && tmp1->m_Next != NULL)
	  {
	   tmp2 = tmp1; 
	   while(tmp2->m_Next != NULL)
	    {
	     if(tmp1->m_ID == tmp2->m_Next->m_ID)
	      {
	       sapre = tmp2->m_Next;
	       tmp2->m_Next = tmp2->m_Next->m_Next;
	       free(sapre);
	      }
	      else
	       tmp2 = tmp2->m_Next;
	    }
	    tmp1 = tmp1->m_Next;
	  }
	}




void Init ( void )
{
	 list = (DB*) malloc ( sizeof(*list) );
 
	 list->head = NULL;
	 list->tail = NULL;
}
 
 
void Done ( void )
{
 RECORD * spare;

 while (list->head != NULL)
 {
  spare = list->head->next;
  free(list->head->name);
  free(list->head);
  list->head = spare;
 }
 list->tail = NULL;
 free(list);
}
 
 
 
 	RECORD * search (int id)
	{
	  RECORD * current = list->head;
	
	  while (current != NULL)
	  {
	    if ( id == current->ID )
	     return current;
	    current = current->next;
	  } 
	  return NULL;
	}

 
  
int Register ( int ID, const char *name, int ID1, int ID2 )
{
 RECORD * person = (RECORD*) malloc ( sizeof(RECORD) );
 RECORD * tmp = list->head;
 int l = strlen (name);
 int i=0;
 
 while (tmp != NULL)        
 {
  if (ID == tmp->ID)
  {
   free (person);
   return 0;                         /*if ID of the person is unique */
  }
  tmp = tmp->next;
 }
 
 if ( (ID1 == ID2 && ID1 != 0 && ID2 != 0) || (ID == 0) )
 {                         
  free (person);
  return 0;        /* if ID of the person is zero or parents are same*/
 }
 
  person->name = (char*) malloc ( sizeof(char) );
  
  for (i=0;i<=l;i++)
  {
   person->name = (char*) realloc (person->name, i+1*sizeof(char) );
   person->name[i] = name[i]; 
   if (i == l)
    person->name[i] = '\0';
  }

 person->ID = ID; 

 if (ID1 != 0) 
 {
  person->par1 = search(ID1); 
  if (person->par1 == NULL)
  {
   free(person->name);
   free (person);
   return 0;                           /* if there is no such parent1*/
  }
 }
 else 
  person ->par1 = 0;

 if (ID2 != 0)
 {
  person->par2 = search(ID2); 
  if (person->par2 == NULL)
  {
   free(person->name);
   free (person);
   return 0; 						   /* if there is no such parent2*/
  }
 }
 else
  person->par2 = 0;
 
 person->next = NULL;

 if (list->head == NULL)
 {
  list->head = person;
  list->tail = person;
 }
 else
 {
  list->tail->next = person;
  list->tail = person;
 } 
 return 0;
}
 
 
 
	TRESULT * FindAllAncestors (RECORD * guy, RESULTLIST * answer)
	{
	  TRESULT * tmp = (TRESULT*) malloc ( sizeof(TRESULT) );
 	
	  if (guy == NULL)
	  {
	   free (tmp);
	   return answer->head1;
	  }
	  
	  tmp->m_Name = guy->name;
 	  tmp->m_ID = guy->ID;
	  tmp->m_Next = NULL;
 	
	  if (guy->par1 != NULL)
	    answer->head1 = FindAllAncestors (guy->par1, answer);
 
	  if (guy->par2 != NULL)
	    answer->head1 = FindAllAncestors (guy->par2, answer);

	  if (answer->head1 == NULL)
	  {
	   answer->head1 = tmp;
	   answer->tail1 = tmp;
	  }
	  else
	  { 
	   answer->tail1->m_Next = tmp;
	   answer->tail1 = tmp;
	  }
	  return answer->head1;
	}

 
void FreeResult ( TRESULT *res )
{ 
 TRESULT * spare;
 while (res != NULL)
 {
  spare = res->m_Next;
  free(res);
  res = spare;
 }
 res = NULL;
 free (res);
}
 
 
TRESULT * Ancestors ( int ID )
{
	 RESULTLIST *answer = (RESULTLIST*) malloc ( sizeof(RESULTLIST) ); 
	 RECORD * aim = search (ID);
	 TRESULT * final;
	 RECORD * tmp = list->head;
	 int flag = 0;

     while (tmp != NULL)      /*  If the given person does not exist */
     {
      if (ID == tmp->ID)
      {
       flag = 1; 
       break;
	  }
      tmp = tmp->next; 
     }
	
	 if (flag != 1)
	 {
	  free (answer);
	  return 0;
	 }

	 answer->head1=NULL;
	 answer->tail1=NULL;

	 answer->head1 = FindAllAncestors (aim->par1, answer);
	 answer->head1 = FindAllAncestors (aim->par2, answer);
		
     CancelBublicates(answer->head1);       /* delete all duplicities*/
		
	 if (answer->head1 == NULL)
	 {
	  free(answer);        /* if no ancestors of the person are known*/
	  return NULL;
	 }                   
		
	 final = answer->head1;

	 free(answer);

	 return final;

}
 
 
TRESULT * CommonAncestors  ( int ID1, int ID2 )
{ 
 RESULTLIST * Alist1 = (RESULTLIST*) malloc ( sizeof(RESULTLIST) ); 
  RESULTLIST * Alist2 = (RESULTLIST*) malloc ( sizeof(RESULTLIST) ); 
 RESULTLIST * answer = (RESULTLIST*) malloc ( sizeof(RESULTLIST) ); 
 RECORD * aim;  
 TRESULT * final;
 TRESULT * spare;       /* I will burn in hell for these variables,  */
 TRESULT * tmp;               /* and for this function at all, */
 TRESULT * tmp2;              /* but I have no other ideas  :( */
 TRESULT * ForDel;
 int flag=0;

 Alist1->head1 = NULL;
  Alist1->tail1 = NULL;
 
 Alist2->head1 = NULL;
  Alist2->tail1 = NULL;

 answer->head1 = NULL;
  answer->tail1 = NULL;
 
 aim = search (ID1);
 
 if (aim == NULL)
 {
  free (Alist1);
  free (Alist2);
  free (answer);
  return NULL;                           /* if person1 does not exist*/
 }
 
 Alist1->head1 = FindAllAncestors (aim->par1, Alist1);
  Alist1->head1 = FindAllAncestors (aim->par2, Alist1);

 aim = search (ID2);

  if (aim == NULL)
 {
  free (Alist1);
  free (Alist2);
  free (answer);
  return NULL;                           /* if person2 does not exist*/
 }
 
  Alist2->head1 = FindAllAncestors (aim->par1, Alist2);
   Alist2->head1 = FindAllAncestors (aim->par2, Alist2);

 spare = Alist2->head1;

 while (Alist1->head1 != NULL)
 {
   tmp = Alist1->head1->m_Next;
   tmp2 = answer->tail1;
   flag = 0;
   while (Alist2->head1 != NULL)
   {
     if (Alist1->head1->m_ID == Alist2->head1->m_ID)
     {
       if (answer->head1 == NULL)
       {
         answer->head1 = Alist1->head1;
         answer->head1->m_Next = NULL;

         answer->tail1 = Alist1->head1;
         answer->tail1->m_Next = NULL;
       }
       else
       {
         answer->tail1->m_Next = Alist1->head1;
         answer->tail1 = Alist1->head1;
         answer->tail1->m_Next = NULL;
       }
     }
     Alist2->head1 = Alist2->head1->m_Next;
   }
   if (tmp2 == answer->tail1)
   {
    ForDel = Alist1->head1;
    flag = 1; 
   }
   Alist2->head1 = spare;
   Alist1->head1 = tmp;
   if (flag == 1)
    free (ForDel);
 }
 
 CancelBublicates(answer->head1);		    /* delete all duplicities*/
 
 final = answer->head1;

 free (Alist1);
 FreeResult(Alist2->head1);
 free (Alist2);
 free(answer);
 
 if (final == NULL)
  return NULL;             /* if no ancestors of the person are known*/
 
 return final; 
}
 
 



#ifndef __PROGTEST__
int main ( int argc, char * argv [] )
 {
   char name[100];
   TRESULT * l;

   Init ();
   assert ( Register ( 1, "John", 0, 0 ) == 1 );
   strncpy ( name, "Jane", sizeof ( name ) );
   assert ( Register ( 2, name, 0, 0 ) == 1 );
   assert ( Register ( 3, "Caroline", 0, 0 ) == 1 );
   assert ( Register ( 4, "Peter", 0, 0 ) == 1 );
   assert ( Register ( 5, "George", 1, 2 ) == 1 );
   assert ( Register ( 6, "Martin", 1, 2 ) == 1 );
   assert ( Register ( 7, "John", 3, 4 ) == 1 );
   assert ( Register ( 8, "Sandra", 3, 4 ) == 1 );
   assert ( Register ( 9, "Eve", 1, 2 ) == 1 );
   assert ( Register ( 10, "Douglas", 1, 4 ) == 1 );
   strncpy ( name, "Phillipe", sizeof ( name ) );
   assert ( Register ( 11, name, 6, 8 ) == 1 );
   strncpy ( name, "Maria", sizeof ( name ) );
   assert ( Register ( 12, name, 5, 8 ) == 1 );
   l = Ancestors ( 11 );
   /*
    * ID=1, name="John"
    * ID=2, name="Jane"
    * ID=3, name="Caroline"
    * ID=4, name="Peter"
    * ID=6, name="Martin"
    * ID=8, name="Sandra"
    */
   FreeResult ( l );
   assert ( Ancestors ( 3 ) == NULL );
   assert ( Ancestors ( 13 ) == NULL );
   l = CommonAncestors ( 11, 12 );
   /*
    * ID=1, name="John"
    * ID=2, name="Jane"
    * ID=3, name="Caroline"
    * ID=4, name="Peter"
    * ID=8, name="Sandra"
    */
   FreeResult ( l );
   l = CommonAncestors ( 10, 9 );
   /*
    * ID=1, name="John"
    */
   FreeResult ( l );
   assert ( CommonAncestors ( 7, 6 ) == NULL );
   l = CommonAncestors ( 7, 10 );
   /*
    * ID=4, name="Peter"
    */
   FreeResult ( l );
   assert ( Register ( 13, "Quido", 12, 11 ) == 1 );
   l = Ancestors ( 13 );
   /*
    * ID=1, name="John"
    * ID=2, name="Jane"
    * ID=3, name="Caroline"
    * ID=4, name="Peter"
    * ID=5, name="George"
    * ID=6, name="Martin"
    * ID=8, name="Sandra"
    * ID=11, name="Phillipe"
    * ID=12, name="Maria"
    */
   FreeResult ( l );
   l = CommonAncestors ( 9, 12 );
   /*
    * ID=1, name="John"
    * ID=2, name="Jane"
    */
   FreeResult ( l );
   assert ( Register ( 1, "Francois", 0, 0 ) == 0 );
   Done ();

   Init ();
   assert ( Register ( 10000, "John", 0, 0 ) == 1 );
   assert ( Register ( 10000, "Peter", 0, 0 ) == 0 );
   assert ( Register ( 20000, "Jane", 10000, 0 ) == 1 );
   assert ( Register ( 30000, "Maria", 10000, 10000 ) == 0 );
   assert ( Register ( 40000, "Joe", 10000, 30000 ) == 0 );
   assert ( Register ( 50000, "Carol", 50000, 20000 ) == 0 );
   Done ();

   return 0;
 }
#endif /* __PROGTEST__ */











/*
The task is to develop a set of functions that implement a database of people.

The database shall hold records representing people. Each person in the database is represented by an ID (unique, int) and a name. Moreover, we will store the link to the parents (when known). The database will support insertions and searches.

The database will be accessible via functions:

typedef struct TResult
 {
   TResult   * m_Next;
   int         m_ID;
   char      * m_Name;
 } TRESULT;

void      Init             ( void );
void      Done             ( void );
int       Register         ( int               ID,
                             const char      * name,
                             int               ID1,
                             int               ID2 );
TRESULT * Ancestors        ( int               ID );
TRESULT * CommonAncestors  ( int               ID1,
                             int               ID2 );
void      FreeResult       ( TRESULT         * res );

TRESULT
    is a structure representing one person in a result. The results are returned in the form of a singly linked list, where TRESULT is an element. The fields are:

        m_Next a link to the next element in the list. The last element in the list has this field set to NULL,
        m_ID is the ID of the person,
        m_Name is the name of the person (ASCIIZ string).

Init
    is a function to initialize the database and set its internal structures. The function is called before any other function.
Done
    is a function to free the resources when the database is no longer needed. The testing environment calls the function at the end of the testing. Moreover, functions Init/Done may be called several times. However, they are always called in pairs Init Done Init Done ... Init Done.
Register
    is a function to add a new person to the database. The parameters are ID and the name of the person being added, and the IDs of both parents. The functions modifies the database and returns a return value 0 (failure) or 1 (success). To succeed, the following is required:

        ID of the person is unique and non-zero,
        parent ID is either 0 (the parent is not known) or non-zero (identifying a known person in the database),
        parent #1 and parent #2 must not be the same person.

Ancestors
    the function searches all ancestors of the given person. The result is a linked list of the people found. The ordering of the list is not specified, however, duplicities are not allowed. If the given person does not exist or if no ancestors of the person are known, the return value shall be NULL.
CommonAncestors
    the function searches all known ancestors that are common for the two give persons. The result is a linked list of the persons found. The ordering of the list is not specified, however, duplicities are not allowed. If either of the given persons does not exist, or if no ancestors of the given person are known, or if there are no common ancestors, the return value shall be NULL.
FreeResult
    function frees resources allocated by the linked list. The function is called by the testing environment when the result returned by either Ancestors or CommonAncestors is not longer needed.

Submit a source file with the implementation of the above functions. The interface of the functions/structure is fixed and cannot be modified in any way. If the interface is modified, the program will not compile. Use the attached archive as a basis of your solution. The attached source contains the required interface and an example main function with the code that are used in the basic test. Note: the conditional compile directives must not be modified. If modified, the compilation may fail.

The internal database implementation is not specified. Based on the data, some linked structure is recommended.











Submission deadline: 	2017-01-01 23:59:59 	 
Evaluation: 	5.5000
Max. assessment: 	5.0000 (Without bonus points)
Submissions: 	3 / 20 Free retries + 10 Penalized retries (-10 % penalty each retry)
Advices: 	0 / 2 Advices for free + 2 Advices with a penalty (-10 % penalty each advice)
*/
