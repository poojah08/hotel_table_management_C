//  ---- Table Management at hotel ---

/*
		## steps
	. decide table no with no of chairs	
	. take input - no. of people in group
	. assign customer table (with table no)  *using hash table--- 
	. assigned table busy (do not reassign until vacated) 
	. vacate table after use
*/

#include<stdio.h>
#include<stdlib.h>

#define total_table 25
int table[total_table];	// global declaration

//  --- functions ---

void assign(int no)
{
	int i,k,f=0;
	if (no<=2)
	k=0;
	else if (no<=4)
	k=8;
	else if (no<=6)
	k=16;
	else if (no<=8)
	k=21;
	else if (no<=12)
	k=23;
	
	for(i=k;i<total_table;i++)
	{
		if(table[i]!=1)
		{
		 table[i]=1;
		 f=1;
		 break;	
		}	
	}
	if(f==1)
	printf("\n Your table no is %d ",i+1);	
}
//vacate
void vacate(int no)
{
	if(table[no-1]!=1)
	printf("\n Table is already vacant ");
	else
	{
		if(no<=8)
		table[no-1]=2;
		else if(no<=16)
		table[no-1]=4;
		else if(no<=21)
		table[no-1]=6;
		else if(no<=23)
		table[no-1]=8;
		else if(no<=25)
		table[no-1]=12;
		printf("Table no %d vacated",no);
	}
}

// main----
int main()
{
	int i,no,ch;
			/*  index wise tables
            0 - 7 for 2 
					  8 - 15 for 4
					  16 -20 for 6
					  21, 22 for 8
					  23,24 for 12
       */
	
	for(i=0;i<total_table;i++)
	{
		if(i<8)
		table[i]=2;
		else if(i<16)
		table[i]=4;
		else if(i<21)
		table[i]=6;
		else if(i<23)
		table[i]=8;
		else
		table[i]=12;
	}
	while(1)
	{
		printf("\n\n 1.Assign table \t 2.Vacate Table \t 98.exit \n choose : ");
		scanf("%d",&ch);
		switch(ch)
		{
			case 1 :
			printf("Enter number of people in group: ");
			scanf("%d",&no);
			assign(no);
			break;
			
			case 2 :
			printf("enter table no to vacate: ");
			scanf("%d",&no);
			vacate(no);
			break;
				
			case 98 :
			return 0; 
			break;
		}
	}
}
