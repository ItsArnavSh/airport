//Creating the Airport Management System
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <ctype.h>
#include <unistd.h>
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
long randomNumber;
int cond;
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
flight da1;
flight da2;
flight da3;
flight da4;
flight da5;
//--------------
//Functions
void start();
void cls();
void initialize();
int booked(long, flight); 
// returns 1 if boarding pass found else 0
void cancelled(long pass, char name[3]); 
//removes a boarding pass from the file
int ticket(long, flight); 
//add a new user
void cancel();
void choose();
void book();
void help();
void check();
int mumbai();
int jaipur();
int bangalore();
int chennai();
int kolkata();
int ahemdabad();
void sorrycancel();
void survey();
//--------------
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
    while(1==1)
    {
    cls();
    printf("Please choose one of the following options:\n");
    printf("1. Book a new flight\n");
    printf("2. Cancel a flight\n");
    printf("3. Check your flight status\n");
    printf("4. Add a review\n");
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
        survey();
        break;
    case 5:
        exit(0);
        break;
    default:
        printf("Invalid choice\n");
        break;
    }
    }
}
//To initialize all the structures
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
    strcpy(dm2.name, "DM2");
    strcpy(dm2.to, "Mumbai");
    strcpy(dm2.company, "AirInd");
    dm2.price = 4700;
    dm2.rating = 3;

dm3.condition = 1;
    dm3.code = 11113;
    strcpy(dm3.name, "DM3");
    strcpy(dm3.to, "Mumbai");
    strcpy(dm3.company, "Spicj");
    dm3.price = 4600;
    dm3.rating = 2;

dm4.condition = 1;
    dm4.code = 11114;
    strcpy(dm4.name, "DM4");
    strcpy(dm4.to, "Mumbai");
    strcpy(dm4.company, "AIndEx");
    dm4.price = 4500;
    dm4.rating = 1;

dm5.condition = 1;
    dm5.code = 11115;
    strcpy(dm5.name, "DM5");
    strcpy(dm5.to, "Mumbai");
    strcpy(dm5.company, "Vistra");
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
    strcpy(dj2.company, "AirInd");
    dj2.price = 3200;
    dj2.rating = 3;

    dj3.condition = 1;
    dj3.code = 22223;
    strcpy(dj3.name, "DJ3");
    strcpy(dj3.to, "Jaipur");
    strcpy(dj3.company, "Spicj");
    dj3.price = 3100;
    dj3.rating = 2;

    dj4.condition = 1;
    dj4.code = 22224;
    strcpy(dj4.name, "DJ4");
    strcpy(dj4.to, "Jaipur");
    strcpy(dj4.company, "AIndEx");
    dj4.price = 3000;
    dj4.rating = 1;

    dj5.condition = 1;
    dj5.code = 22225;
    strcpy(dj5.name, "DJ5");
    strcpy(dj5.to, "Jaipur");
    strcpy(dj5.company, "Vistra");
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
    strcpy(db2.company, "AirInd");
    db2.price = 4200;
    db2.rating = 3;

    db3.condition = 1;
    db3.code = 33333;
    strcpy(db3.name, "DB3");
    strcpy(db3.to, "Banglore");
    strcpy(db3.company, "Spicj");
    db3.price = 4100;
    db3.rating = 2;

    db4.condition = 1;
    db4.code = 33334;
    strcpy(db4.name, "DB4");
    strcpy(db4.to, "Banglore");
    strcpy(db4.company, "AIndEx");
    db4.price = 4000;
    db4.rating = 1;

    db5.condition = 1;
    db5.code = 33335;
    strcpy(db5.name, "DB5");
    strcpy(db5.to, "Banglore");
    strcpy(db5.company, "Vistra");
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
    strcpy(dc2.company, "AirInd");
    dc2.price = 5200;
    dc2.rating = 3;

    dc3.condition = 1;
    dc3.code = 44443;
    strcpy(dc3.name, "DC3");
    strcpy(dc3.to, "Chennai");
    strcpy(dc3.company, "Spicj");
    dc3.price = 5100;
    dc3.rating = 2;

    dc4.condition = 1;
    dc4.code = 44444;
    strcpy(dc4.name, "DC4");
    strcpy(dc4.to, "Chennai");
    strcpy(dc4.company, "AIndEx");
    dc4.price = 5000;
    dc4.rating = 1;

    dc5.condition = 1;
    dc5.code = 44445;
    strcpy(dc5.name, "DC5");
    strcpy(dc5.to, "Chennai");
    strcpy(dc5.company, "Vistra");
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
    strcpy(dk2.company, "AirInd");
    dk2.price = 3700;
    dk2.rating = 3;

    dk3.condition = 1;
    dk3.code = 55553;
    strcpy(dk3.name, "DK3");
    strcpy(dk3.to, "Kolkata");
    strcpy(dk3.company, "Spicj");
    dk3.price = 3600;
    dk3.rating = 2;

    dk4.condition = 1;
    dk4.code = 55554;
    strcpy(dk4.name, "DK4");
    strcpy(dk4.to, "Kolkata");
    strcpy(dk4.company, "AIndEx");
    dk4.price = 3500;
    dk4.rating = 1;

    dk5.condition = 1;
    dk5.code = 55555;
    strcpy(dk5.name, "DK5");
    strcpy(dk5.to, "Kolkata");
    strcpy(dk5.company, "Vistra");
    dk5.price = 3800;
    dk5.rating = 4;
//--------------------------------------------------------------------------------------------------
    da1.condition = 1;
    da1.code = 66661;
    strcpy(da1.name, "DA1");
    strcpy(da1.to, "Ahemdabad");
    strcpy(da1.company, "Indigo");
    da1.price = 5900;
    da1.rating = 4;

    da2.condition = 1;
    da2.code = 66662;
    strcpy(da2.name, "DA2");
    strcpy(da2.to, "Ahemdabad");
    strcpy(da2.company, "AirInd");
    da2.price = 5700;
    da2.rating = 3;

    da3.condition = 1;
    da3.code = 66663;
    strcpy(da3.name, "DA3");
    strcpy(da3.to, "Ahemdabad");
    strcpy(da3.company, "Spijet");
    da3.price = 5600;
    da3.rating = 2;

    da4.condition = 1;
    da4.code = 66664;
    strcpy(da4.name, "DA4");
    strcpy(da4.to, "Ahemdabad");
    strcpy(da4.company, "AIndEx");
    da4.price = 5500;
    da4.rating = 1;

    da5.condition = 1;
    da5.code = 66665;
    strcpy(da5.name, "DA5");
    strcpy(da5.to, "Ahemdabad");
    strcpy(da5.company, "Vistra");
    da5.price = 5800;
    da5.rating = 4;
}
void book()
{
    printf("Press 1 to see flights for Mumbai\n");
    printf("Press 2 to see flights for Jaipur\n");
    printf("Press 3 to see flights for Bangalore\n");
    printf("Press 4 to see flights for Chennai\n");
    printf("Press 5 to see flights for Kolkata\n");
    printf("Press 6 to see flights for Ahemdabad\n");
    printf("Press 7 to go back\n");
    int choice;
    scanf("%d", &choice);
    switch (choice)
    {
    case 1:
        cls();
        cond = mumbai();
        if(cond==1)
        {
            printf("Successfully Booked the ticket");
            printf("\nYOUR BOARDING PASS NUMBER IS: %ld",randomNumber);
        }
        else
        {
            printf("Unable to book your ticket.\n");
        }
        break;
    case 2:
        cls();
        cond = jaipur();
        if(cond==1)
        {
            printf("Successfully Booked the ticket");
            printf("\nYOUR BOARDING PASS NUMBER IS: %ld",randomNumber);
        }
        else
        {
            printf("Unable to book your ticket.\n");
            printf("\nYOUR BOARDING PASS NUMBER IS: %ld",randomNumber);
        }
        break;
    case 3:
        cls();
        cond = bangalore();
        if(cond==1)
        {
            printf("Successfully Booked the ticket");
            printf("\nYOUR BOARDING PASS NUMBER IS: %ld",randomNumber);
        }
        else
        {
            printf("Unable to book your ticket.\n");
            printf("\nYOUR BOARDING PASS NUMBER IS: %ld",randomNumber);
        }
        break;
    case 4:
        cls();
        cond = chennai();
        break;
    case 5:
        cls();
        cond = kolkata();
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
        cond = ahemdabad();
        if(cond==1)
        {
            printf("Successfully Booked the ticket");
        }
        else
        {
            printf("Unable to book your ticket.\n");
        }
        break;
    case 7:
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
    scanf("%d",&code);
    //To help book a flight
    switch (code)
    {
    case 11111:
        cls();
        printf("You have booked the flight DM1\n");
        //To help book a flight
        srand(time(NULL));
     // Seed the random number generator with current time_t
        randomNumber = rand() % (999999999 - 100000000 + 1) + 100000000;
        return(booked(randomNumber,dm1));
        break;
    case 11112:
        cls();
        printf("You have booked the flight DM2\n");
        //To help book a flight
        srand(time(NULL));
     // Seed the random number generator with current time_t
        randomNumber = rand() % (999999999 - 100000000 + 1) + 100000000;
        return(booked(randomNumber,dm2));
        break;
    case 11113:
        cls();
        printf("You have booked the flight DM3\n");
        //To help book a flight
        srand(time(NULL));
     // Seed the random number generator with current time_t
        randomNumber = rand() % (999999999 - 100000000 + 1) + 100000000;
        return(booked(randomNumber,dm3));
        break;
    case 11114:
        cls();
        printf("You have booked the flight DM4\n");
        //To help book a flight
        srand(time(NULL));
     // Seed the random number generator with current time_t
        randomNumber = rand() % (999999999 - 100000000 + 1) + 100000000;
        return(booked(randomNumber,dm4));
        break;
    case 11115:
        cls();
        printf("You have booked the flight DM5\n");
        //To help book a flight
        srand(time(NULL));
     // Seed the random number generator with current time_t
        randomNumber = rand() % (999999999 - 100000000 + 1) + 100000000;
        return(booked(randomNumber,dm5));
        break;
    default:
    printf("There is not flight by that code\n");
        break;
    }
    return 0;
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
    scanf("%d",&code);
    switch (code)
    {
    case 22221:
        cls();
        printf("You have booked the flight DJ1\n");
        //To help book a flight
        srand(time(NULL));
     // Seed the random number generator with current time_t
        randomNumber = rand() % (999999999 - 100000000 + 1) + 100000000;
        return(booked(randomNumber,dj1));
        break;
    case 22222:
        cls();
        printf("You have booked the flight DJ2\n");
        //To help book a flight
        srand(time(NULL));
     // Seed the random number generator with current time_t
        randomNumber = rand() % (999999999 - 100000000 + 1) + 100000000;
        return(booked(randomNumber,dj2));
        break;
    case 22223:
        cls();
        printf("You have booked the flight DJ3\n");
        //To help book a flight
        srand(time(NULL));
     // Seed the random number generator with current time_t
        randomNumber = rand() % (999999999 - 100000000 + 1) + 100000000; 
        return(booked(randomNumber,dj3));
        break;
    case 22224:
        cls();
        printf("You have booked the flight DJ4\n");
        //To help book a flight
        srand(time(NULL));
     // Seed the random number generator with current time_t
        randomNumber = rand() % (999999999 - 100000000 + 1) + 100000000; 
        return(booked(randomNumber,dj4));
        break;
    case 22225:
        cls();
        printf("You have booked the flight DJ5\n");
        //To help book a flight
        srand(time(NULL));
     // Seed the random number generator with current time_t
        randomNumber = rand() % (999999999 - 100000000 + 1) + 100000000; 
        return(booked(randomNumber,dj5));
        break;
        default:
        printf("There is not flight by that code\n");
            break;
    }
    return 0;
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
    scanf("%d",&code);
    switch (code)
    {
    case 33331:
        cls();
        printf("You have booked the flight DB1\n");
        //To help book a flight
        srand(time(NULL));
     // Seed the random number generator with current time_t
        randomNumber = rand() % (999999999 - 100000000 + 1) + 100000000; 
        return(booked(randomNumber,db1));
        break;
    case 33332:
        cls();
        printf("You have booked the flight DB2");
        //To help book a flight
        srand(time(NULL));
     // Seed the random number generator with current time_t
        randomNumber = rand() % (999999999 - 100000000 + 1) + 100000000; 
        return(booked(randomNumber,db2));
        break;
    case 33333:
        cls();
        printf("You have booked the flight DB3");
        //To help book a flight
        srand(time(NULL));
     // Seed the random number generator with current time_t
        randomNumber = rand() % (999999999 - 100000000 + 1) + 100000000; 
        return(booked(randomNumber,db3));
        break;
    case 33334:
        cls();
        printf("You have booked the flight DB4");
        //To help book a flight
        srand(time(NULL));
     // Seed the random number generator with current time_t
        randomNumber = rand() % (999999999 - 100000000 + 1) + 100000000; 
        return(booked(randomNumber,db4));
        break;
    case 33335:
        cls();
        printf("You have booked the flight DB5");
        //To help book a flight
        srand(time(NULL));
     // Seed the random number generator with current time_t
        randomNumber = rand() % (999999999 - 100000000 + 1) + 100000000; 
        return(booked(randomNumber,db5));
        break;
    default:
    printf("There is not flight by that code\n");
    break;
}
return 0;
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
    scanf("%d",&code);
    switch (code)
    {
    case 44441:
        cls();
        printf("You have booked the flight DC1\n");
        //To help book a flight
        srand(time(NULL));
     // Seed the random number generator with current time_t
        randomNumber = rand() % (999999999 - 100000000 + 1) + 100000000; 
        return(booked(randomNumber,dc1));
        break;
    case 44442:
        cls();
        printf("You have booked the flight DC2");
        //To help book a flight
        srand(time(NULL));
     // Seed the random number generator with current time_t
        randomNumber = rand() % (999999999 - 100000000 + 1) + 100000000; 
        return(booked(randomNumber,dc2));
        break;
    case 44443:
        cls();
        printf("You have booked the flight DC3");
        //To help book a flight
        srand(time(NULL));
     // Seed the random number generator with current time_t
        randomNumber = rand() % (999999999 - 100000000 + 1) + 100000000; 
        return(booked(randomNumber,dc3));
        break;
    case 44444:
        cls();
        printf("You have booked the flight DC4");
        //To help book a flight
        srand(time(NULL));
     // Seed the random number generator with current time_t
        randomNumber = rand() % (999999999 - 100000000 + 1) + 100000000; 
        return(booked(randomNumber,dc4));
        break;
    case 44445:
        cls();
        printf("You have booked the flight DC5");
        //To help book a flight
        srand(time(NULL));
 // Seed the random number generator with current time_t
        randomNumber = rand() % (999999999 - 100000000 + 1) + 100000000; 
        return(booked(randomNumber,dc5));
        break;
    default:
    printf("There is not flight by that code\n");
    break;
}
return 0;
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
    scanf("%d",&code);
    switch (code)
    {
    case 55551:
        cls();
        printf("You have booked the flight DK1\n");
        //To help book a flight
        srand(time(NULL));
 // Seed the random number generator with current time_t
        randomNumber = rand() % (999999999 - 100000000 + 1) + 100000000; 
        return(booked(randomNumber,dk1));
        break;
    case 55552:
        cls();
        printf("You have booked the flight DK2");
        //To help book a flight
        srand(time(NULL));
     // Seed the random number generator with current time_t
        randomNumber = rand() % (999999999 - 100000000 + 1) + 100000000; 
        return(booked(randomNumber,dk2));
        break;
    case 55553:
        cls();
        printf("You have booked the flight DK3");
        //To help book a flight
        srand(time(NULL));
     // Seed the random number generator with current time_t
        randomNumber = rand() % (999999999 - 100000000 + 1) + 100000000; 
        return(booked(randomNumber,dk3));
        break;
    case 55554:
        cls();
        printf("You have booked the flight DK4");
        //To help book a flight
        srand(time(NULL));
     // Seed the random number generator with current time_t
        randomNumber = rand() % (999999999 - 100000000 + 1) + 100000000; 
        return(booked(randomNumber,dk4));
        break;
    case 55555:
        cls();
        printf("You have booked the flight Dk5");
        //To help book a flight
        srand(time(NULL)); // Seed the random number generator with current time
        randomNumber = rand() % (999999999 - 100000000 + 1) + 100000000; 
        return(booked(randomNumber,dk5));
        break;
    default:
    printf("There is not flight by that code\n");
    break;
}
return 0;
}
int ahemdabad()
{
    printf("Following is the data for the flights for ahemdabad:\n");
    printf("code\tname\tcompany\tprice\trating\n");
    printf("%d\t%s\t%s\t%d\t%d\n", da1.code, da1.name, da1.company, da1.price, da1.rating);
    printf("%d\t%s\t%s\t%d\t%d\n", da2.code, da2.name, da2.company, da2.price, da2.rating);
    printf("%d\t%s\t%s\t%d\t%d\n", da3.code, da3.name, da3.company, da3.price, da3.rating);
    printf("%d\t%s\t%s\t%d\t%d\n", da4.code, da4.name, da4.company, da4.price, da4.rating);
    printf("%d\t%s\t%s\t%d\t%d\n", da5.code, da5.name, da5.company, da5.price, da5.rating);
    printf("Enter the code of the flight you want to book\n");
    int code;
    scanf("%d",&code);
    switch (code)
    {
    case 66661:
        cls();
        printf("You have booked the flight DA1\n");
        //To help book a flight
        srand(time(NULL)); // Seed the random number generator with current time
        randomNumber = rand() % (999999999 - 100000000 + 1) + 100000000; 
        return(booked(randomNumber,da1));
        break;
    case 66662:
        cls();
        printf("You have booked the flight DA2");
        //To help book a flight
        srand(time(NULL)); // Seed the random number generator with current time
        randomNumber = rand() % (999999999 - 100000000 + 1) + 100000000;
        return(booked(randomNumber,da2));
        break;
    case 66663:
        cls();
        printf("You have booked the flight DA3");
        //To help book a flight
        srand(time(NULL)); // Seed the random number generator with current time
        randomNumber = rand() % (999999999 - 100000000 + 1) + 100000000;
        return(booked(randomNumber,da3));
        break;
    case 66664:
        cls();
        printf("You have booked the flight DA4");
        //To help book a flight
        srand(time(NULL)); // Seed the random number generator with current time
        randomNumber = rand() % (999999999 - 100000000 + 1) + 100000000;
        return(booked(randomNumber,da4));
        break;
    case 66665:
        cls();
        printf("You have booked the flight DA5");
        //To help book a flight
        srand(time(NULL)); // Seed the random number generator with current time
        randomNumber = rand() % (999999999 - 100000000 + 1) + 100000000;
        return(booked(randomNumber,da5));
        break;
    default:
    printf("There is not flight by that code\n");
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
    scanf("%s",name);
    for(int i = 0; i < 2; i++)
        name[i] = tolower(name[i]);
    cancelled(pass, name);
    printf("Your flight has been cancelled\n");
    printf("We are sorry to see you go\n");
    sorrycancel();
}
//To register a new passenger
int ticket(long pass, flight x)
{
    char path[15], data[10], p[10];
    sprintf(p, "%ld", pass);
    strcpy(path, "flights/");
    strcat(path, x.name); 
    FILE *file = fopen(path, "r");
    if(file == NULL)
        printf("File Not Found/");
    while(fgets(data, sizeof(data), file))
    {
        if(!strcmp(p, data))
            return 1;
    }
    return 0;
}
//Cancel
void cancelled(long pass, char name[3])
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
//To check if the person is booked for sure
int booked(long pass, flight x)
{
    char path[20];
    strcpy(path, "flights/");
    strcat(path, x.name);
    strcat(path, ".txt"); 
    printf("%s",path);
    FILE *file = fopen(path, "a");
    if(file == NULL)
        printf("File Not Found\n");
    fprintf(file, "%ld\n", pass);
    fclose(file);
    return 1;
}
void help()
{
    //All the help here
    int tem;
    printf("Welcome to the help section of Airport management system");
    printf("\nEnter any number to continue: ");
    scanf("%d",&tem);
    cls();
    printf("We support flights to 5 major cities:");
    printf("\nMumbai");
    printf("\nJaipur");
    printf("\nBengaluru");
    printf("\nKolkata");
    printf("\nChennai");
    printf("\nAhemdabad");
    printf("\nEnter any number to continue: ");
    scanf("%d",&tem);
    cls();
    printf("5 companies provide their service at our airport: \n");
    printf("\nAir India");
    printf("\nAir India Express");
    printf("\nSpiceJet");
    printf("\nVistara");
    printf("\nIndigo");
    printf("\nEnter any number to continue: ");
    scanf("%d",&tem);
    cls();
    printf("You are presented with a menu for booking a ticket, cancelling your ticket and checking your booking status\n");
    printf("\nEnter any number to continue: ");
    scanf("%d",&tem);
    cls();
    printf("When you book a new ticket, you are given a booking pass, and you must remember it\n");
    printf("\nEnter any number to continue: ");
    scanf("%d",&tem);
    cls();
    printf("You can check your booking details simply from the menu by entering your flight name in CAPS and the booking pass id\n");
    printf("\nEnter any number to continue: ");
    scanf("%d",&tem);
    cls();
    printf("You can cancel the flight if you want from the menu\n");
    printf("\nEnter any number to continue: ");
    scanf("%d",&tem);
    cls();
    printf("Hope this helps");
    printf("\nHappy Flying\n");
    printf("\nEnter any number to continue: ");
    scanf("%d",&tem);
    cls();

    return;
}
void check()
{
    ask:
    //To check all the bookings in the flight
    printf("Please Enter your flight name: ");
    char name[3];
    scanf("%s",name);
    printf("Please enter your boarding pass: ");
    char pass[20];
    scanf("%s", pass);
    //Now we will make a string of the path
    char path[20];
    strcpy(path, "flights/");
    strcat(path, name);
    strcat(path,".txt");
    FILE *file = fopen(path, "r");
    if(file == NULL)
    {
        printf("File Not Found\n");
        printf("Please ensure you entered the correct flight name\n");
        cls();
        goto ask;
    }
    char data[10];
    while(fgets(data, sizeof(data), file))
    {
        if(!strcmp(pass, data))
        {
            printf("Your flight is confirmed\n");
            return;
        }
        else
        {
            printf("Your flight is not confirmed\n");
            return;
        }
    }
}
void sorrycancel()
{
    printf("We are really disappointed to see you go\n");
    printf("Before you go, please give us a quick survey\n");
    printf("Press 1 if you are satisfied with our service\n");
    printf("Press 2 if you are not satisfied with our service\n");
    int choice;
    scanf("%d",&choice);
    switch (choice)
    {
    case 1:
        printf("Thank you for your feedback\n");
        break;
    case 2:
        printf("We are sorry for the inconvenience caused\n");
        break;
    default:
        printf("Invalid choice\n");
        break;
    }
    printf("Can you describe your experience in one word?\n");
    char word[20];
    scanf("%s",word);
    printf("Thank you for your feedback\n");
    printf("Can you please tell us what we can do to improve our service?\n");
    char feedback[100];
    scanf("%s",feedback);
    printf("We hope to see you again\n");
}
void survey()
{
    printf("We are glad to see you here\n");
    printf("We would like to ask you a few questions\n");
    //Ask about the customer service
    printf("How would you rate our customer service on a scale of 1 to 5?\n");
    int service;
    scanf("%d",&service);
    if(service<1 || service>5)
    {
        printf("Invalid choice\n");
        printf("Please enter a number between 1 and 5\n");
        scanf("%d",&service);
    }
    if(service>=4)
    {
        printf("We are glad you liked our service\n");
    }
    else
    {
        printf("We are sorry you did not like our service\n");
    }
    //Ask about the cleanliness
    printf("How would you rate our cleanliness on a scale of 1 to 5?\n");
    int clean;
    scanf("%d",&clean);
    if(clean<1 || clean>5)
    {
        printf("Invalid choice\n");
        printf("Please enter a number between 1 and 5\n");
        scanf("%d",&clean);
    }
    if(clean>=4)
    {
        printf("We are glad you liked our cleanliness\n");
    }
    else
    {
        printf("We are sorry you did not like our cleanliness\n");
    }
    //Ask about the food
    printf("How would you rate our food on a scale of 1 to 5?\n");
    int food;
    scanf("%d",&food);
    if(food<1 || food>5)
    {
        printf("Invalid choice\n");
        printf("Please enter a number between 1 and 5\n");
        scanf("%d",&food);
    }
    if(food>=4)
    {
        printf("We are glad you liked our food\n");
    }
    else
    {
        printf("We are sorry you did not like our food\n");
    }
    //Ask about the comfort
    printf("How would you rate our comfort on a scale of 1 to 5?\n");
    int comfort;
    scanf("%d",&comfort);
    if(comfort<1 || comfort>5)
    {
        printf("Invalid choice\n");
        printf("Please enter a number between 1 and 5\n");
        scanf("%d",&comfort);
    }
    if(comfort>=4)
    {
        printf("We are glad you liked our comfort\n");
    }
    else
    {
        printf("We are sorry you did not like our comfort\n");
    }
    //Ask about the entertainment
    printf("How would you rate our entertainment on a scale of 1 to 5?\n");
    int entertainment;
    scanf("%d",&entertainment);
    if(entertainment<1 || entertainment>5)
    {
        printf("Invalid choice\n");
        printf("Please enter a number between 1 and 5\n");
        scanf("%d",&entertainment);
    }
    if(entertainment>=4)
    {
        printf("We are glad you liked our entertainment\n");
    }
    else
    {
        printf("We are sorry you did not like our entertainment\n");
    }
    //Ask about the overall experience
    printf("How would you rate your overall experience on a scale of 1 to 5?\n");
    int overall;
    scanf("%d",&overall);
    if(overall<1 || overall>5)
    {
        printf("Invalid choice\n");
        printf("Please enter a number between 1 and 5\n");
        scanf("%d",&overall);
    }
    if(overall>=4)
    {
        printf("We are glad you liked your overall experience\n");
    }
    else
    {
        printf("We are sorry you did not like your overall experience\n");
    }
    printf("Thank you for your feedback\n");
    printf("We hope to see you again\n");
}
/*
Submitted BY
Prakshi Jain
-
Vijaya Singh
-
Saara Goyal
-
Krishna Gupta
-
Batch of 2027
Jaypee Institute of Information Technology
Noida, Sector 62
*/