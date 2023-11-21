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
    dm1.condition = 1;
    dm1.code = 11111;
    strcpy(dm1.name, "DM1");
    strcpy(dm1.to, "Mumbai");
    strcpy(dm1.company, "Indigo");
    dm1.price = 4900;
    dm1.rating = 5;

dm2.condition = 1;
    dm2.code = 11112;
    strcpy(dm2.name, "DM1");
    strcpy(dm2.to, "Mumbai");
    strcpy(dm2.company, "Air india");
    dm2.price = 4700;
    dm2.rating = 3;

dm3.condition = 1;
    dm3.code = 11113;
    strcpy(dm3.name, "DM1");
    strcpy(dm3.to, "Mumbai");
    strcpy(dm3.company, "Spicejet");
    dm3.price = 4600;
    dm3.rating = 2;

dm4.condition = 1;
    dm4.code = 11114;
    strcpy(dm4.name, "DM1");
    strcpy(dm4.to, "Mumbai");
    strcpy(dm4.company, "Air India Exxpress");
    dm4.price = 4500;
    dm4.rating = 1;

dm5.condition = 1;
    dm5.code = 11115;
    strcpy(dm5.name, "DM1");
    strcpy(dm5.to, "Mumbai");
    strcpy(dm5.company, "Vistara");
    dm5.price = 4800;
    dm5.rating = 4;

//-----------------------------------------------------------------------------------------------------------------------------------------------------

    dj1.condition = 1;
    dj1.code = 22221;
    strcpy(dj1.name, "DJ1");
    strcpy(dj1.to, "Jaipur");
    strcpy(dj1.company, "Indigo");
    dj1.price = 3400;
    dj1.rating = 5;

    dj2.condition = 1;
    dj2.code = 22222;
    strcpy(dj2.name, "DJ2");
    strcpy(dj2.to, "Jaipur");
    strcpy(dj2.company, "Air India");
    dj2.price = 3200;
    dj2.rating = 3;

    dj3.condition = 1;
    dj3.code = 22223;
    strcpy(dj3.name, "DJ3");
    strcpy(dj3.to, "Jaipur");
    strcpy(dj3.company, "Spicejet");
    dj3.price = 3100;
    dj3.rating = 2;

    dj4.condition = 1;
    dj4.code = 22224;
    strcpy(dj4.name, "DJ4");
    strcpy(dj4.to, "Jaipur");
    strcpy(dj4.company, "Air India Express");
    dj4.price = 3000;
    dj4.rating = 1;

    dj5.condition = 1;
    dj5.code = 22225;
    strcpy(dj5.name, "DJ5");
    strcpy(dj5.to, "Jaipur");
    strcpy(dj5.company, "Vistara");
    dj5.price = 3300;
    dj5.rating = 4;

//-------------------------------------------------------------------------------------------------------

    db1.condition = 1;
    db1.code = 33331;
    strcpy(db1.name, "DB1");
    strcpy(db1.to, "Banglore");
    strcpy(db1.company, "Indigo");
    db1.price = 4400;
    db1.rating = 5;

    db2.condition = 1;
    db2.code = 33332;
    strcpy(db2.name, "DB2");
    strcpy(db2.to, "Banglore");
    strcpy(db2.company, "Air India");
    db2.price = 4200;
    db2.rating = 3;

    db3.condition = 1;
    db3.code = 33333;
    strcpy(db3.name, "DB3");
    strcpy(db3.to, "Banglore");
    strcpy(db3.company, "Spicejet");
    db3.price = 4100;
    db3.rating = 2;

    db4.condition = 1;
    db4.code = 33334;
    strcpy(db4.name, "DB4");
    strcpy(db4.to, "Banglore");
    strcpy(db4.company, "Air India Express");
    db4.price = 4000;
    db4.rating = 1;

    db5.condition = 1;
    db5.code = 33335;
    strcpy(db5.name, "DB5");
    strcpy(db5.to, "Banglore");
    strcpy(db5.company, "Vistara");
    db5.price = 4300;
    db5.rating = 4;

//--------------------------------------------------------------------------------------------------------------

    dc1.condition = 1;
    dc1.code = 44441;
    strcpy(dc1.name, "DC1");
    strcpy(dc1.to, "Chennai");
    strcpy(dc1.company, "Indigo");
    dc1.price = 5;
    dc1.rating = 5;

    dc2.condition = 1;
    dc2.code = 44442;
    strcpy(dc2.name, "DC2");
    strcpy(dc2.to, "Chennai");
    strcpy(dc2.company, "Air India");
    dc2.price = 5200;
    dc2.rating = 3;

    dc3.condition = 1;
    dc3.code = 44443;
    strcpy(dc3.name, "DC3");
    strcpy(dc3.to, "Chennai");
    strcpy(dc3.company, "Spicejet");
    dc3.price = 5100;
    dc3.rating = 2;

    dc4.condition = 1;
    dc4.code = 44444;
    strcpy(dc4.name, "DC4");
    strcpy(dc4.to, "Chennai");
    strcpy(dc4.company, "Air India Express");
    dc4.price = 5000;
    dc4.rating = 1;

    dc5.condition = 1;
    dc5.code = 44445;
    strcpy(dc5.name, "DC5");
    strcpy(dc5.to, "Chennai");
    strcpy(dc5.company, "Vistara");
    dc5.price = 5300;
    dc5.rating = 4;

//---------------------------------------------------------------------------------------------

     dk1.condition = 1;
    dk1.code = 55551;
    strcpy(dk1.name, "DK1");
    strcpy(dk1.to, "Kolkata");
    strcpy(dk1.company, "Indigo");
    dk1.price = 3900;
    dk1.rating = 5;

    dk2.condition = 1;
    dk2.code = 55552;
    strcpy(dk2.name, "DK2");
    strcpy(dk2.to, "Kolkata");
    strcpy(dk2.company, "Air India");
    dk2.price = 3700;
    dk2.rating = 3;

    dk3.condition = 1;
    dk3.code = 55553;
    strcpy(dk3.name, "DK3");
    strcpy(dk3.to, "Kolkata");
    strcpy(dk3.company, "Spicejet");
    dk3.price = 3600;
    dk3.rating = 2;

    dk4.condition = 1;
    dk4.code = 55554;
    strcpy(dk4.name, "DK4");
    strcpy(dk4.to, "Kolkata");
    strcpy(dk4.company, "Air India Express");
    dk4.price = 3500;
    dk4.rating = 1;

    dk5.condition = 1;
    dk5.code = 55555;
    strcpy(dk5.name, "DK5");
    strcpy(dk5.to, "Kolkata");
    strcpy(dk5.company, "Vistara");
    dk5.price = 3800;
    dk5.rating = 4;
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
        int cond = mumbai();
        if(cond==1)
        {
            printf("Successfully Booked the ticket");
        }
        else
        {
            printf("Unable to book your ticket.\n");
        }
        break;
    case 2:
        cls();
        int cond = jaipur();
        if(cond==1)
        {
            printf("Successfully Booked the ticket");
        }
        else
        {
            printf("Unable to book your ticket.\n");
        }
        break;
    case 3:
        cls();
        int cond = bangalore();
        if(cond==1)
        {
            printf("Successfully Booked the ticket");
        }
        else
        {
            printf("Unable to book your ticket.\n");
        }
        break;
    case 4:
        cls();
        int cond = chennai();
        break;
    case 5:
        cls();
        int cond = kolkata();
        if(cond==1)
        {
            printf("Successfully Booked the ticket");
        }
        else
        {
            printf("Unable to book your ticket.\n");
        }
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
int mumbai()
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
    case 11112:
        cls();
        printf("You have booked the flight DM2\n");
        long randomNumber;
        srand(time(NULL)); // Seed the random number generator with current time
        randomNumber = rand() % (999999999 - 100000000 + 1) + 100000000;
        return(booked(randomNumber,dm2));
        break;
    case 11113:
        cls();
        printf("You have booked the flight DM3\n");
        long randomNumber;
        srand(time(NULL)); // Seed the random number generator with current time
        randomNumber = rand() % (999999999 - 100000000 + 1) + 100000000;
        return(booked(randomNumber,dm3));
        break;
    case 11114:
        cls();
        printf("You have booked the flight DM4\n");
        long randomNumber;
        srand(time(NULL)); // Seed the random number generator with current time
        randomNumber = rand() % (999999999 - 100000000 + 1) + 100000000;
        return(booked(randomNumber,dm4));
        break;
    case 11115:
        cls();
        printf("You have booked the flight DM5\n");
        long randomNumber;
        srand(time(NULL)); // Seed the random number generator with current time
        randomNumber = rand() % (999999999 - 100000000 + 1) + 100000000;
        return(booked(randomNumber,dm5));
        break;
    default:
    printf("There is not flight by that code\n");
        break;
    }
}
int jaipur()
{
    printf("Following is the data for the flights for jaipur:\n");
    printf("code\tname\tcompany\tprice\trating\n");
    printf("%d\t%s\t%s\t%d\t%d\n", dj1.code, dj1.name, dj1.company, dj1.price, dj1.rating);
    printf("%d\t%s\t%s\t%d\t%d\n", dj2.code, dj2.name, dj2.company, dj2.price, dj2.rating);
    printf("%d\t%s\t%s\t%d\t%d\n", dj3.code, dj3.name, dj3.company, dj3.price, dj3.rating);
    printf("%d\t%s\t%s\t%d\t%d\n", dj4.code, dj4.name, dj4.company, dj4.price, dj4.rating);
    printf("%d\t%s\t%s\t%d\t%d\n", dj5.code, dj5.name, dj5.company, dj5.price, dj5.rating);
    printf("Enter the code of the flight you want to book\n");
    int code;
    scanf("%d",code);
    switch (code)
    {
    case 22221:
        cls();
        printf("You have booked the flight DJ1\n");
        long randomNumber;
        srand(time(NULL)); // Seed the random number generator with current time
        randomNumber = rand() % (999999999 - 100000000 + 1) + 100000000;
        return(booked(randomNumber,dj1));
        break;
    case 22222:
        cls();
        printf("You have booked the flight DJ2\n");
        long randomNumber;
        srand(time(NULL)); // Seed the random number generator with current time
        randomNumber = rand() % (999999999 - 100000000 + 1) + 100000000;
        return(booked(randomNumber,dj2));
        break;
    case 22223:
        cls();
        printf("You have booked the flight DJ3\n");
        long randomNumber;
        srand(time(NULL)); // Seed the random number generator with current time
        randomNumber = rand() % (999999999 - 100000000 + 1) + 100000000; 
        return(booked(randomNumber,dj3));
        break;
    case 22224:
        cls();
        printf("You have booked the flight DJ4\n");
        long randomNumber;
        srand(time(NULL)); // Seed the random number generator with current time
        randomNumber = rand() % (999999999 - 100000000 + 1) + 100000000; 
        return(booked(randomNumber,dj4));
        break;
    case 22225:
        cls();
        printf("You have booked the flight DJ5\n");
        long randomNumber;
        srand(time(NULL)); // Seed the random number generator with current time
        randomNumber = rand() % (999999999 - 100000000 + 1) + 100000000; 
        return(booked(randomNumber,dj5));
        break;
        default:
        printf("There is not flight by that code\n");
            break;
    }
}
int bangalore()
{
    printf("Following is the data for the flights for bangalore:\n");
    printf("code\tname\tcompany\tprice\trating\n");
    printf("%d\t%s\t%s\t%d\t%d\n", db1.code, db1.name, db1.company, db1.price, db1.rating);
    printf("%d\t%s\t%s\t%d\t%d\n", db2.code, db2.name, db2.company, db2.price, db2.rating);
    printf("%d\t%s\t%s\t%d\t%d\n", db3.code, db3.name, db3.company, db3.price, db3.rating);
    printf("%d\t%s\t%s\t%d\t%d\n", db4.code, db4.name, db4.company, db4.price, db4.rating);
    printf("%d\t%s\t%s\t%d\t%d\n", db5.code, db5.name, db5.company, db5.price, db5.rating);
    printf("Enter the code of the flight you want to book\n");
    int code;
    scanf("%d",code);
    switch (code)
    {
    case 33331:
        cls();
        printf("You have booked the flight DB1\n");
        long randomNumber;
        srand(time(NULL)); // Seed the random number generator with current time
        randomNumber = rand() % (999999999 - 100000000 + 1) + 100000000; 
        return(booked(randomNumber,db1));
        break;
    case 33332:
        cls();
        printf("You have booked the flight DB2");
        long randomNumber;
        srand(time(NULL)); // Seed the random number generator with current time
        randomNumber = rand() % (999999999 - 100000000 + 1) + 100000000; 
        return(booked(randomNumber,db2));
        break;
    case 33333:
        cls();
        printf("You have booked the flight DB3");
        long randomNumber;
        srand(time(NULL)); // Seed the random number generator with current time
        randomNumber = rand() % (999999999 - 100000000 + 1) + 100000000; 
        return(booked(randomNumber,db3));
        break;
    case 33334:
        cls();
        printf("You have booked the flight DB4");
        long randomNumber;
        srand(time(NULL)); // Seed the random number generator with current time
        randomNumber = rand() % (999999999 - 100000000 + 1) + 100000000; 
        return(booked(randomNumber,db4));
        break;
    case 33335:
        cls();
        printf("You have booked the flight DB5");
        long randomNumber;
        srand(time(NULL)); // Seed the random number generator with current time
        randomNumber = rand() % (999999999 - 100000000 + 1) + 100000000; 
        return(booked(randomNumber,db5));
        break;
    default:
    printf("There is not flight by that code\n");
    break;
}
}
int chennai()
{
    printf("Following is the data for the flights for bangalore:\n");
    printf("code\tname\tcompany\tprice\trating\n");
    printf("%d\t%s\t%s\t%d\t%d\n", dc1.code, dc1.name, dc1.company, dc1.price, dc1.rating);
    printf("%d\t%s\t%s\t%d\t%d\n", dc2.code, dc2.name, dc2.company, dc2.price, dc2.rating);
    printf("%d\t%s\t%s\t%d\t%d\n", dc3.code, dc3.name, dc3.company, dc3.price, dc3.rating);
    printf("%d\t%s\t%s\t%d\t%d\n", dc4.code, dc4.name, dc4.company, dc4.price, dc4.rating);
    printf("%d\t%s\t%s\t%d\t%d\n", dc5.code, dc5.name, dc5.company, dc5.price, dc5.rating);
    printf("Enter the code of the flight you want to book\n");
    int code;
    scanf("%d",code);
    switch (code)
    {
    case 44441:
        cls();
        printf("You have booked the flight DC1\n");
        long randomNumber;
        srand(time(NULL)); // Seed the random number generator with current time
        randomNumber = rand() % (999999999 - 100000000 + 1) + 100000000; 
        return(booked(randomNumber,dc1));
        break;
    case 44442:
        cls();
        printf("You have booked the flight DC2");
        long randomNumber;
        srand(time(NULL)); // Seed the random number generator with current time
        randomNumber = rand() % (999999999 - 100000000 + 1) + 100000000; 
        return(booked(randomNumber,dc2));
        break;
    case 44443:
        cls();
        printf("You have booked the flight DC3");
        long randomNumber;
        srand(time(NULL)); // Seed the random number generator with current time
        randomNumber = rand() % (999999999 - 100000000 + 1) + 100000000; 
        return(booked(randomNumber,dc3));
        break;
    case 44444:
        cls();
        printf("You have booked the flight DC4");
        long randomNumber;
        srand(time(NULL)); // Seed the random number generator with current time
        randomNumber = rand() % (999999999 - 100000000 + 1) + 100000000; 
        return(booked(randomNumber,dc4));
        break;
    case 44445:
        cls();
        printf("You have booked the flight DC5");
        long randomNumber;
        srand(time(NULL)); // Seed the random number generator with current time
        randomNumber = rand() % (999999999 - 100000000 + 1) + 100000000; 
        return(booked(randomNumber,dc5));
        break;
    default:
    printf("There is not flight by that code\n");
    break;
}
}
int kolkata()
{
    printf("Following is the data for the flights for bangalore:\n");
    printf("code\tname\tcompany\tprice\trating\n");
    printf("%d\t%s\t%s\t%d\t%d\n", dk1.code, dk1.name, dk1.company, dk1.price, dk1.rating);
    printf("%d\t%s\t%s\t%d\t%d\n", dk2.code, dk2.name, dk2.company, dk2.price, dk2.rating);
    printf("%d\t%s\t%s\t%d\t%d\n", dk3.code, dk3.name, dk3.company, dk3.price, dk3.rating);
    printf("%d\t%s\t%s\t%d\t%d\n", dk4.code, dk4.name, dk4.company, dk4.price, dk4.rating);
    printf("%d\t%s\t%s\t%d\t%d\n", dk5.code, dk5.name, dk5.company, dk5.price, dk5.rating);
    printf("Enter the code of the flight you want to book\n");
    int code;
    scanf("%d",code);
    switch (code)
    {
    case 55551:
        cls();
        printf("You have booked the flight DK1\n");
        long randomNumber;
        srand(time(NULL)); // Seed the random number generator with current time
        randomNumber = rand() % (999999999 - 100000000 + 1) + 100000000; 
        return(booked(randomNumber,dk1));
        break;
    case 55552:
        cls();
        printf("You have booked the flight DK2");
        long randomNumber;
        srand(time(NULL)); // Seed the random number generator with current time
        randomNumber = rand() % (999999999 - 100000000 + 1) + 100000000; 
        return(booked(randomNumber,dk2));
        break;
    case 55553:
        cls();
        printf("You have booked the flight DK3");
        long randomNumber;
        srand(time(NULL)); // Seed the random number generator with current time
        randomNumber = rand() % (999999999 - 100000000 + 1) + 100000000; 
        return(booked(randomNumber,dk3));
        break;
    case 55554:
        cls();
        printf("You have booked the flight DK4");
        long randomNumber;
        srand(time(NULL)); // Seed the random number generator with current time
        randomNumber = rand() % (999999999 - 100000000 + 1) + 100000000; 
        return(booked(randomNumber,dk4));
        break;
    case 55555:
        cls();
        printf("You have booked the flight Dk5");
        long randomNumber;
        srand(time(NULL)); // Seed the random number generator with current time
        randomNumber = rand() % (999999999 - 100000000 + 1) + 100000000; 
        return(booked(randomNumber,dk5));
        break;
    default:
    printf("There is not flight by that code\n");
    break;
}    }
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