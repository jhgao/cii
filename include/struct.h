#ifndef STRUCT_H
#define STRUCT_H

#define T Struct_T
typedef struct T *T;

extern T Struct_new(void);
extern int Struct_isTypePtr(T t);
#undef T
#endif

