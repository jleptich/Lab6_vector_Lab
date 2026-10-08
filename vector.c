/*
    REQUIREMENTS:
        Be able to add, subtract, scalar multply vectors
        these can be stored in a new vector or a vector already created

        Must have a list, clear, -h(help), and quit commands
        
        a MAX of 10 vectors
*/
#include <stdio.h>
#include <string.h>
#include "vect.h"
#include <stdlib.h>
#include "arithmetic.h"


int main(){
    vector vect_list[10];
    int index = 0;

    printf("WELCOME TO VECTOR CALCULATOR: YOU CAN QUIT BY SAYING QUIT AND GET HELP BY SAYING -h.\n ELSE CREATE A VECTOR LIMIT COMMANDS TO 30 CHARACTERS\n");

    while(1){
        char input[30];
        char* token1;
        char* token2;
        char* token3;
        char* token4;
        char* token5;
        printf("Enter your command:");
        fgets(input, 30, stdin);
        token1 = strtok(input, " \n");
        token2 = strtok(NULL, " \n");
        token3 = strtok(NULL, " \n");
        token4 = strtok(NULL, " \n");
        token5 = strtok(NULL, " \n");
        
        if(token2 == NULL && token3 == NULL && token4 == NULL && token5 == NULL){
            if(!strcmp(token1,"QUIT")){
                printf("Thank you for using the VECTOR CALCULATOR\n");
                return 0;
            }

            else if(!strcmp(token1,"-h")){
                printf("-------------HELP------------------\n");
                printf("REMEMBER NEVER USE , WHEN CREATING A NEW VECTOR\n\n");
                printf("TO ADD TWO VECTORS YOU CAN DO VEC1 + VEC2: THIS WILL PRINTOUT THE TWO VECTORS ADDED TOGETHER\n\n");
                printf("YOU CAN ALSO ASSIGN A VECTOR BY ADDING TWO VECTORS BY DOING VEC = VEC1 + VEC2\n\n");
                printf("YOU CAN DO SUBTRACTION WITH VEC1 - VEC2 AND ASSIGN A VECTOR WITH ABOVE MENTION NOTATION\n\n");
                printf("YOU CAN DO SCALAR MULTIPICATION BY MULTIPLING A VECTOR BY AN INT: VEC1*2\n\n");
                printf("IF YOU WISH TO SEE ALL THE VECTORS CREATED ENTER LIST\n\n");
                printf("IF YOU WISH TO LEAVE ENTER QUIT\n\n");
            
            }

            else if(!strcmp(token1, "list")){
                if(index > 0){
                 for(int i = 0; i<index; i++){
                    printf("%s = < %.2f, %.2f, %.2f >\n",vect_list[i].name,vect_list[i].x,vect_list[i].y,vect_list[i].z);
            }
        }
                else{
                    printf("No vectors have been created\n\n");
                }
            }

            for(int i = 0; i<index; i++){
                if(!strcmp(vect_list[i].name,token1)){
                    printf("%s = < %.2f, %.2f, %.2f >\n",vect_list[i].name,vect_list[i].x,vect_list[i].y,vect_list[i].z);
                    break;
                }
            }

        }
        else if(token3 == NULL && token4 == NULL && token5 == NULL){
            printf("THIS IS NOT A VALID COMMAND TYPE IN -h IF YOU NEED HELP\n");
        }
        else if(token4 == NULL && token5 == NULL){
            vector hold1;
            vector hold2;
            int hold3 = 0;
            for(int i = 0; i<index; i++){
                if(!strcmp(vect_list[i].name,token1)){
                    hold1.name = vect_list[i].name;
                    hold1.x = vect_list[i].x;
                    hold1.y = vect_list[i].y;
                    hold1.z = vect_list[i].z;
                    break;
                }
            }
                if(hold1.name == NULL){
                    if(atoi(token1) != 0){
                        hold3 = atoi(token1);
                    }
                    else{
                        printf("YOU'VE ENTERED A INVALID COMMAND\n");
                        break;
                    }
                }
            
            for(int i = 0; i<index; i++){
                if(!strcmp(vect_list[i].name,token3)){
                    hold2.name = vect_list[i].name;
                    hold2.x = vect_list[i].x;
                    hold2.y = vect_list[i].y;
                    hold2.z = vect_list[i].z;
                    break;
                }
            }
            if(hold2.name == NULL){
                    if(atoi(token3) != 0){
                        hold3 = atoi(token3);
                    }
                    else{
                        printf("YOU'VE ENTERED A INVALID COMMAND\n");
                        break;
                    }
                }
            char op;
            op = assignment(token2);
            if(op == 'a'){
                printf("Invalid assignment character used\n");
                break;
            }
            vector temp = check_operation(hold1, hold2, op,hold3);
            printf("%s = < %.2f, %.2f, %.2f >\n",temp.name, temp.x, temp.y, temp.z);
        }
        else if(token5 == NULL){
            printf("NO COMMAND ONLY HAS 4 INPUTS: INVALID COMMAND\n");
        }
        else{
            char assign = assignment(token2);
            char operator = assignment(token4);

                vector hold1;
                vector hold2; 
                vector hold3;
                int mult = 0;
                int stop = 1;
                for(int i = 0; i<index; i++){
                if(!strcmp(vect_list[i].name,token1)){
                    hold1.name = vect_list[i].name;
                    hold1.x = vect_list[i].x;
                    hold1.y = vect_list[i].y;
                    hold1.z = vect_list[i].z;
                }

                if(!strcmp(vect_list[i].name,token3)){
                    hold2.name = vect_list[i].name;
                    hold2.x = vect_list[i].x;
                    hold2.y = vect_list[i].y;
                    hold2.z = vect_list[i].z;
                }

                if(!strcmp(vect_list[i].name,token5)){
                    hold3.name = vect_list[i].name;
                    hold3.x = vect_list[i].x;
                    hold3.y = vect_list[i].y;
                    hold3.z = vect_list[i].z;
                }

            }

            if(hold1.name == NULL){
                if(index >= 10){
                printf("You cannot create more vectors, please clear your vector list if you want to create new vectors\n");
                stop = 0;
            }
            else{
                strcpy(hold1.name, token1);
            }
            }
            if(hold2.name == NULL && operator == '*' && stop == 1){
                mult = atoi(token3);
            }
            else if(operator != 'a' && stop == 1){
                printf("invalid command, type in -h for help\n");
            }
            if(hold2.name == NULL && hold3.name == NULL && operator == 'a' && assign == '=' && stop == 1){
                hold1.x = atoi(token3);
                hold1.y = atoi(token4);
                hold1.z = atoi(token5);

                strcpy(vect_list[index].name,hold1.name);
                vect_list[index].x = hold1.x;
                vect_list[index].y = hold1.y;
                vect_list[index].z = hold1.z;
                index++;
            }
            if(hold3.name == NULL && operator == '*' && stop == 1){
                mult = atoi(token3);
            }
            else if (operator != 'a' && stop == 1){
                printf("invalid command, type in -h for help\n");
            }
            if(operator != 'a' && assign == '=' && stop == 1){
            vector temp = check_operation(hold1, hold2, operator, mult);
            vect_list[index].name = hold1.name;
            vect_list[index].x = temp.x;
            vect_list[index].y = temp.y;
            vect_list[index].z = temp.z;
            index++;
            }
            }
            
    }
    return 0;
}