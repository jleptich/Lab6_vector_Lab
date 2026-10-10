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

        //initializes the input array and the 5 string tokens
        char input[30];
        char* token1;
        char* token2;
        char* token3;
        char* token4;
        char* token5;
        printf("Enter your command:");
        fgets(input, 30, stdin);

        //all the tokens scan from input
        token1 = strtok(input, " \n");
        token2 = strtok(NULL, " \n");
        token3 = strtok(NULL, " \n");
        token4 = strtok(NULL, " \n");
        token5 = strtok(NULL, " \n");
        

        //if only token1 has a input
        if(token2 == NULL && token3 == NULL && token4 == NULL && token5 == NULL){
            //checks to see if the user wants to quit
            if(!strcmp(token1,"QUIT")){
                printf("Thank you for using the VECTOR CALCULATOR\n");
                return 0;
            }

            //checks to see if the user raised the help flag
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

            //checks to see if the user wanted a list of all vectors created
            else if(!strcmp(token1, "list")){
                if(index > 0){
                 for(int i = 0; i<index; i++){
                    printf("%s = < %d, %d, %d >\n",vect_list[i].name,vect_list[i].x,vect_list[i].y,vect_list[i].z);
            }
        }
                else{
                    printf("No vectors have been created\n\n");
                }
            }
            //checks to see if the user wanted a single vector printed
            //for(int i = 0; i<index; i++){
                //if(!strcmp(vect_list[i].name,token1)){
                   // printf("%s = < %d, %d, %d >\n",vect_list[i].name,vect_list[i].x,vect_list[i].y,vect_list[i].z);
                    //break;
                //}
            }

        
        //No such operators that only use token1 and token2
        else if(token3 == NULL && token4 == NULL && token5 == NULL){
            printf("THIS IS NOT A VALID COMMAND TYPE IN -h IF YOU NEED HELP\n");
        }

        //Used to check if only vector arithmetic is being used without being inputted to a new vector
        else if(token4 == NULL && token5 == NULL){
            vector *hold1 = NULL;
            vector *hold2 = NULL;
            int hold3 = 0;  //if a vector is being multiplied by an integer 
            
            for(int i = 0; i<index; i++){
                if(!strcmp(vect_list[i].name,token1)){
                    hold1 = &vect_list[i];
                    break;
                }
            }
                if(hold1 == NULL){
                    if(atoi(token1) != 0){
                        hold3 = atoi(token1);
                    }
                    else{
                        printf("YOU'VE ENTERED A INVALID COMMAND\n\n");
                        continue;
                    }
                }
            
            for(int i = 0; i<index; i++){
                if(!strcmp(vect_list[i].name,token3)){
                    hold2 = &vect_list[i];
                    break;
                }
            }

            if(hold2 == NULL){
                    if(atoi(token3) != 0){
                        hold3 = atoi(token3);
                    }
                    else{
                        printf("YOU'VE ENTERED A INVALID COMMAND\n");
                        continue;
                    }
                }
            char op;
            op = assignment(token2);
            if(op == 'a'){
                printf("Invalid assignment character used\n");
                continue;
            }
            vector temp = check_operation(*hold1, *hold2, op,hold3);
            printf("%s = < %d, %d, %d >\n",temp.name, temp.x, temp.y, temp.z);
        }

        //No commands have only 4 inputs
        else if(token5 == NULL){
            printf("NO COMMAND ONLY HAS 4 INPUTS: INVALID COMMAND\n");
        }

        //uses all five tokens
        else{
            char assign = assignment(token2);   //token2 has to be a equals sign '='
            char operator = assignment(token4); //token4 has to be some symbol for arithmetic

                vector *hold1 = NULL;
                vector *hold2 = NULL; 
                vector *hold3 = NULL;
                int mult = 0;

                //sees if token1, token3, or token5 are prexisting vectors in the vect_list array
                for(int i = 0; i<index; i++){

                if(!strcmp(vect_list[i].name,token1)){
                    hold1 = &vect_list[i];
                }

                if(!strcmp(vect_list[i].name,token3)){
                    hold2 = &vect_list[i];
                }

                if(!strcmp(vect_list[i].name,token5)){
                    hold3 = &vect_list[i];
                }

            }

            //If vector hold1 doesn't have a name then it needs to be set up as a new vector
            if(hold1 == NULL){
                if(index >= 10){
                printf("You cannot create more vectors, please clear your vector list if you want to create new vectors\n\n");
                continue;
            }
            else{
                hold1 = &vect_list[index];
                strcpy(hold1->name, token1);
                index++;
            }
            }

            //Statement for if token2 and token5 are not vectors and are assigning values to a new/prexisting vector
            if(hold2 == NULL && hold3 == NULL && operator == 'a' && assign == '='){
                hold1->x = atoi(token3);
                hold1->y = atoi(token4);
                hold1->z = atoi(token5);
            }

             //looks to see if a vector is being multiplied by a scalar
            if(hold2==NULL && operator == '*'){
                mult = atoi(token3);
            }
            

            
            //checks to see if token3 is a scalar multiplier
            if(hold3 ==NULL && operator == '*'){
                mult = atoi(token3);
            }
            
            //If vector arithmetic is being done
            if(operator != 'a' && assign == '='){
            vector temp = check_operation(*hold2, *hold3, operator, mult);
            hold1->x = temp.x;
            hold1->y = temp.y;
            hold1->z = temp.z;
            }
    }
}
    return 0;

}