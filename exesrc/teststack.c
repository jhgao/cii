#include "stack.h"

int main(int argc, char * argv[])
{
        Stack_T stk = Stack_new();
        Stack_free(&stk);

        return 0;
}
