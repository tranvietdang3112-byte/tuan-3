#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#define size 10

int main(void){
    char buffer [1000];
    char *data;

    FILE *f;
    f =fopen("C:\\vscode\\Book1.csv", "r");
    if (f == NULL) {
        printf("ERROR\n");
        return 1;
    }
    printf("I was able to open the file\n");

    //doc dong dau
    fgets(buffer,sizeof(buffer), f);
    printf("%s\n",buffer);

    //cu phap
    data = strtok(buffer,",");
    printf("first token is %s\n", data);

    data = strtok(NULL, ",");
    printf("second token is %s\n", data);

     data = strtok(NULL, ",");
    printf("second token is %s\n", data);
    
     data = strtok(NULL, ",");
    printf("second token is %s\n", data);




    return 0;
}
