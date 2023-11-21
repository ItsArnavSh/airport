#include<stdio.h>
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