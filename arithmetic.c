#include <string.h>
#include <stdio.h>
#include "vect.h"



vector add(vector a, vector b){
    vector assign;
    assign.x = a.x + b.x;
    assign.y = a.y + b.y;
    assign.z = a.z + b.z;

    return assign;
}

vector sub(vector a, vector b){
    vector assign;
    assign.x = a.x - b.x;
    assign.y = a.y - b.y;
    assign.z = a.z - b.z;

    return assign;
}

vector scalar_mult(vector a, int x){
    vector assign;
    assign.x = a.x*x;
    assign.y = a.y*x;
    assign.z = a.z*x;
    return assign;
}


vector check_operation(vector a, vector b, char arith, int mult){
    switch(arith){
        case '+':
        return add(a, b);
        case '-':
        return sub(a,b);
        case '*':
        return scalar_mult(a, mult);
        default:
        printf("UNKOWN INPUT: RETURNING BACK TO TERMINAL\n");
        vector empty;
        return empty;
    }
}


char assignment(char* token){
            char op;
            if(!strcmp(token,"+")){
                op = '+';
            }
            else if(!strcmp(token,"-")){
                op = '-';
            }
            else if(!strcmp(token,"*")){
                op = '*';
            }
            else{
                op = 'a';
            }
            return op;
}






