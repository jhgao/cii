#include <stdio.h>
#include <stdlib.h>
#include "assert.h"
#include "struct.h"
#include "stack.h"

typedef struct notS {
        int data;
} NotS;

int main(int argc, char * argv[])
{
        Stack_T stk = Stack_new();

        NotS *ns = (NotS*) malloc( sizeof(NotS) );

        Struct_T sct = Struct_new();

        if ( Struct_isTypePtr(sct) )
                printf("sct is Struct_T\n");
        else 
                printf("sct is NOT Struct_T\n");


        if ( Struct_isTypePtr(stk) )
                printf("stk is Struct_T\n");
        else 
                printf("stk is NOT Struct_T\n");

        if ( Struct_isTypePtr(ns) )
                printf("ns is Struct_T\n");
        else 
                printf("ns is NOT Struct_T\n");
        
        return 0;
}

