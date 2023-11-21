#include<stdio.h>
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