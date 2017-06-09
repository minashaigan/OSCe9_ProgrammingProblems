/**
 * writing a simple program to read data from one file and copy them to another file.
 * input : directory , input and output file names
 * programmer : Mina Shaigan
 */

#include <stdio.h>
#include <stdlib.h>
#include <string.h>
int main()
{
    printf("please enter files directory or use the default: [directory/default]\n");
    char dir[255];
    scanf("%s",&dir);
    if(strcmp(dir,"default")){
        chdir(dir);
    }
    char command[50];
    strcpy( command, "dir" );
    system(command);
    printf("Please enter name of input and output files : \n");
    char input[225];
    char output[225];
    printf("input : ");
    scanf("%s",&input);

    strcpy( command,"type ");
    strcat(command,input);

    int flag = system(command);
    while(flag == 1){
        printf("please enter the right name : ");
        scanf("%s",&input);

        strcpy( command,"type ");
        strcat(command,input);

        flag = system(command);
    }
    printf("\noutput : ");
    scanf("%s",&output);
    strcpy( command,"type ");
    strcat(command,output);

    flag = system(command);
    int first = 0;
    while(flag == 1){
        printf("The file output does not exist \n");
        printf("Do you want to exist this file [y/n] : ");
        char ans[1];
        scanf("%s",&ans);
        if(!strcmp(ans,"y"))
        {
            printf("\noutput : ");
            scanf("%s",&output);
            FILE *fo;
            FILE *fi;
            char buff[255];

            fi = fopen(input, "r");
            fo = fopen(output, "w");
            while (fgets(buff, 255, fi) != NULL)
            {
                fputs(buff, fo);
            }
            if (feof(fi))
            {
                printf("Finish");
            }
            else
            {
                printf("Error to read file");
            }
            fclose(fi);
            fclose(fo);
            flag = 0;
        }
        else{
            printf("please enter another output file name : ");
                scanf("%s",&output);
                strcpy( command,"type ");
                strcat(command,output);

                flag = system(command);
        }
        first = 1;
    }
    while(flag == 0 && first == 0){
        char text[225];
        strcpy(text,"The file ");
        strcat(text,output);
        strcat(text," exist \n");
        printf("%s",&text);
        printf("Do you want delete existing file and create new one [y/n] : ");
        char ans[1];
        scanf("%s",&ans);
        if(!strcmp(ans,"y"))
        {
            FILE *fo;
            FILE *fi;
            char buff[255];

            fi = fopen(input, "r");
            fo = fopen(output, "w");
            while (fgets(buff, 255, fi) != NULL)
            {
                fputs(buff, fo);
            }
            if (feof(fi))
            {
                printf("Finish");
            }
            else
            {
                printf("Error to read file");
            }
            fclose(fi);
            fclose(fo);
            flag = 1;
        }
        else
        {
            printf("please enter another output file name : ");
                scanf("%s",&output);
                strcpy( command,"type ");
                strcat(command,output);

                flag = system(command);
        }
    }
    return 0;
}
