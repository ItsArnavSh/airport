//Creating the Airport Management System
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <ctype.h>
//------------------
//Structure for flight
typedef struct flight
{
    int code;
    int condition;//0 for cancelled, 1 for on time, 2 for delayed,3 for dispatched
    char name[20];
    char to[20];
    char company[20];
    unsigned int price;
    unsigned int rating;
}flight;
//--------------
//Declaring all the structs
flight dm1;
flight dm2;
flight dm3;
flight dm4;
flight dm5;
flight dj1;
flight dj2;
flight dj3;
flight dj4;
flight dj5;
flight db1;
flight db2;
flight db3;
flight db4;
flight db5;
flight dc1;
flight dc2;
flight dc3;
flight dc4;
flight dc5;
flight dk1;
flight dk2;
flight dk3;
flight dk4;
flight dk5;
//--------------
//Functions
void start();
void cls();
void initialize();
int main()
{
    start();
}
void cls()
{
    system("clear");
}
void start()
{
    initialize();
    printf("Welcome to the Airport Management System\n");
    printf("Press 1 to continue\n");
    printf("Press 2 for help\n");
    printf("Press 3 to exit\n");
    int choice;
    scanf("%d", &choice);
    switch (choice)
    {
    case 1:
        cls();
        choose();
        break;
    case 2:
        cls();
        help();
        break;
    case 3:
        exit(0);
        break;
    default:
        printf("Invalid choice\n");
        break;
    }
}
void choose()
{
    printf("Please choose one of the following options:\n");
    printf("1. Book a new flight\n");
    printf("2. Cancel a flight\n");
    printf("3. Check your flight status\n");
    printf("4. View all flights\n");
    printf("5. Exit\n");
    int choice;
    scanf("%d", &choice);
    switch (choice)
    {
    case 1:
        cls();
        book();
        break;
    case 2:
        cls();
        cancel();
        break;
    case 3:
        cls();
        check();
        break;
    case 4:
        cls();
        view();
        break;
    case 5:
        exit(0);
        break;
    default:
        printf("Invalid choice\n");
        break;
    }
}
void initialize()
{
    dm1.condition = 1;
    dm1.code = 2341;
    strcpy(dm1.name, "DM1");
    strcpy(dm1.to, "Mumbai");
    strcpy(dm1.company, "Indigo");
    dm1.price = 4900;
}