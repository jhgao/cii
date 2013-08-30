#include <stdio.h>
#include <stdint.h>
#include "assert.h"
#include "mem.h"
#include "struct.h"

#define T Struct_T
struct T {
        uint8_t patternByte;
        int data;
};

T Struct_new(void) {
	T sct;
	NEW(sct);
	sct->data = 0;
	sct->patternByte = 0xa;
	return sct;
}

int Struct_isTypePtr(T t){
        assert( t != NULL );
        printf("pattern byte = %x\n", *(uint8_t*)&t->patternByte );
        return t->patternByte == 0xa ;
}

#undef T

