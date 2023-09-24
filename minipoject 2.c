#include<stdio.h>
#include<conio.h>
#include<stdlib.h>
#define max 100
struct ATM
{
	long long int acno; char name[50]; int amount;
};struct ATM A1;

void design();
void createaccount();
void deposit();
void withdraw();
void balance();

int main()
{
	int choice=0,i,count=0;
	char ch1,ch2,ch3,ch4;
	printf("\nEnter your four digit pin : ");
	ch1=getch(); printf("*");
	ch2=getch(); printf("*");
	ch3=getch(); printf("*");
	ch4=getch(); printf("*");
	if(ch1=='2'&&ch2=='5'&&ch3=='5'&&ch4=='3')
	{
		do
		{
			design();
			printf("\nEnter your choice = ");
			scanf("%d",&choice);
			switch(choice)
			{
				case 1: createaccount(); break;
				case 2: deposit(); break;
				case 3: withdraw(); break;
				case 4: balance(); break;
				case 5: exit(0);
				default: printf("Invalid choice....");
			}printf("\n");
		}while(choice!=5);
	}
	else
		printf("\nInvalid pin...");
}

void createaccount()
{ 
	long long int n=0,number;
	printf("Enter 11 digit account number = ");
	scanf("%lld",&A1.acno);  number=A1.acno;
	while(A1.acno!=0)
	{
		A1.acno=A1.acno/10;
		n++;
	}
	if(n==11)
	{
		A1.acno=number;
		fflush(stdin);
		printf("enter the account holder name = ");
		gets(A1.name);
		fflush(stdin);
		printf("Enter amount = ");
		scanf("%d",&A1.amount);
	}
	else
	{
		printf("you didn't enter 11 digits...\n");
		createaccount();
	}
}

void design()
{
	printf("\n------ATM banking management system------");
	printf("\n\t 1 create account");
	printf("\n\t 2 deposit amount");
	printf("\n\t 3 withdrawal amount");
	printf("\n\t 4 check balance");
	printf("\n\t 5 Exit");
	printf("\n-----------------------------------------");
}

void deposit()
{
	int amt;
	printf("\nEnter an amount for deposit = ");
	scanf("%d",&amt);
	if(amt<0)
		printf("\nInvalid amount...");
	else
		A1.amount=A1.amount+amt;
}
void withdraw()
{
	int amt;
	printf("\nEnter an amount for withdrawal = ");
	scanf("%d",&amt);
	if(amt<0)
		printf("\nInvalid amount...");
	if(amt>A1.amount)
		printf("\nInsufficient balance...");
	else
		A1.amount=A1.amount-amt;
}
void balance()
{
	printf("\naccount no : %lld",A1.acno);
	printf("\naccount holder name = ");
	puts(A1.name);
	printf("balance : %d",A1.amount);
}
