#include<stdio.h>
void cancel()
{
    long pass;
    char name[3];
    printf("Please enter your boarding pass number: ");
    scanf("%ld", &pass);
    printf("PLease enter the flight name: ");
    gets(name);
    for(int i = 0; i < 2; i++)
        name[i] = tolower(name[i]);
    cancelled(pass, name);
}