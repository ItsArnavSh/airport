#include<stdio.h>
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