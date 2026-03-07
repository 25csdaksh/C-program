#include<stdio.h>
void main()
{

    printf("--------------WELCOME TO HDFC BANK---------------");
    printf("\n");

int age,count;
char gender,choice;
daksh:
    printf("\nWanna continue further(y/n):");
    scanf("\n %c", &choice);
    if(choice=='y')
    {

    printf("Kindly enter your age:");
    scanf("%d", &age);

    if(age<0)
    {
        printf("\nInvalid Age, Kindly enter valid age: ");
        goto daksh;
    }

    printf("\nEnter customer gender:");
    printf("\nEnter 'm' for male gender:");
    printf("\nEnter 'f' for female gender:");
    scanf(" %c", &gender);

    if(age<18 && gender=='m')
    {
        printf("\nSorry Sir,You are underage for opening an account");
        printf("\nYou are eligible once you complete 18 years");
        printf("\n\t***THANK YOU***");
    }
    if(age<18 && gender=='f')
    {
        printf("\nSorry ma'am,You are underage for opening an account");
        printf("\nYou are eligible once you complete 18 years");
        printf("\n\t***THANK YOU***");
    }
    else if(age>=18 && gender=='m' && age<60)
    {
         printf("\nWelcome Sir to our Bank for registration for regular saving account");
         printf("\nKindly fill the bank slip for the further procedure");
         printf("\n\t***THANK YOU***");count++;
    }
    else if(age>=18 && gender=='f' && age<60)
    {
         printf("\nWelcome Ma'am to our Bank for registration for regular saving account");
         printf("\nKindly fill the bank slip for the further procedure");
         printf("\n\t***THANK YOU***");count++;
    }
    else
    {
        printf("\nWelcome To Our Bank for registration for senior citizen account");
        printf("\n\t***THANK YOU***");
    }
    goto daksh;
    }
    else
    {
        printf("Total number of customers registerd today are: %d",count);
    }
}
