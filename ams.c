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
void booked(long, flight); // returns 1 if boarding pass found else 0
void cancelled(long, char); //removes a boarding pass from the file
int ticket(long, flight); //add a new user
void cancel();
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
    //Initialize DM1
    dm1.condition = 1;
    dm1.code = 2341;
    strcpy(dm1.name, "DM1");
    strcpy(dm1.to, "Mumbai");
    strcpy(dm1.company, "Indigo");
    dm1.price = 4900;
    dm1.rating = 5;
}
void book()
{
    printf("Press 1 to see flights for Mumbai\n");
    printf("Press 2 to see flights for Jaipur\n");
    printf("Press 3 to see flights for Bangalore\n");
    printf("Press 4 to see flights for Chennai\n");
    printf("Press 5 to see flights for Kolkata\n");
    printf("Press 6 to go back\n");
    int choice;
    scanf("%d", &choice);
    switch (choice)
    {
    case 1:
        cls();
        mumbai();
        break;
    case 2:
        cls();
        jaipur();
        break;
    case 3:
        cls();
        bangalore();
        break;
    case 4:
        cls();
        chennai();
        break;
    case 5:
        cls();
        kolkata();
        break;
    case 6:
        cls();
        choose();
        break;
    default:
        printf("Invalid choice\n");
        break;
    }
}
void mumbai()
{
    printf("Following is the data for the flights for mumbai:\n");
    printf("code\tname\tcompany\tprice\trating\n");
    printf("%d\t%s\t%s\t%d\t%d\n", dm1.code, dm1.name, dm1.company, dm1.price, dm1.rating);
    printf("%d\t%s\t%s\t%d\t%d\n", dm2.code, dm2.name, dm2.company, dm2.price, dm2.rating);
    printf("%d\t%s\t%s\t%d\t%d\n", dm3.code, dm3.name, dm3.company, dm3.price, dm3.rating);
    printf("%d\t%s\t%s\t%d\t%d\n", dm4.code, dm4.name, dm4.company, dm4.price, dm4.rating);
    printf("%d\t%s\t%s\t%d\t%d\n", dm5.code, dm5.name, dm5.company, dm5.price, dm5.rating);
    printf("Enter the code of the flight you want to book\n");
    int code;
    scanf("%d",code);
    switch (code)
    {
    case 11111:
        cls();
        printf("You have booked the flight DM1\n");
        long randomNumber;
        srand(time(NULL)); // Seed the random number generator with current time
        randomNumber = rand() % (999999999 - 100000000 + 1) + 100000000;
        return(booked(randomNumber,dm1));
        break;
    }
}
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
int ticket(long pass, flight x)
{
    char path[15], data[10], p[10];
    sprintf(p, "%ld", pass);
    strcpy(path, "flights\\");
    strcat(path, x.name); 
    FILE *file = fopen(path, "r");
    if(file == NULL)
        printf("File Not Found\n");
    while(fgets(data, sizeof(data), file))
    {
        if(!strcmp(p, data))
            return 1;
    }
    return 0;
}
void cancelled(long pass, char name)
{
    char path[15], data[10], p[10];
    sprintf(p, "%ld", pass);
    strcpy(path, "flights\\");
    strcat(path, name); 
    FILE *file = fopen(path, "r");
    if(file == NULL)
        printf("File Not Found\n");
    FILE *temp = fopen("temp.txt", "a");
    if(temp == NULL)
        printf("File Not Found\n");
    while(fgets(data, sizeof(data), file))
    {
        if(!strcmp(p, data))
            continue;
        fprintf(temp, "%s", data);
    }
    fclose(file);
    fclose(temp);
    remove(path);
    rename("temp.txt", path);
}
void booked(long pass, flight x)
{
    char path[15];
    strcpy(path, "flights\\");
    strcat(path, x.name); 
    FILE *file = fopen(path, "a");
    if(file == NULL)
        printf("File Not Found\n");
    fprintf(file, "%ld", pass);
    fclose(file);
    return 1;
}