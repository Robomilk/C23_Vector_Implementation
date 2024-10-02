/* Type your code here, or load an example. */
#include "stddef.h"
#include "stdlib.h"
#include "stdio.h"


#define vec(type) struct vec_##type {size_t capacity; size_t size; type* data}*
#define vec_new() {calloc(sizeof(vec(void)),0)} 
#define vec_init(vector) {vector->capacity = 0;vector->size = 0; vector->data = (void*)0;} 
#define vec_push(vector,value) {\
                                if(vector->capacity<=vector->size)\
                                {\
                                    if(vector->capacity == 0)\
                                    {vector->capacity=20;}\
                                    else\
                                    {vector->capacity<<=1;}\
                                    vector->data = realloc(vector->data,vector->capacity*sizeof(&vector->data[0]));\
                                }\
                                vector->data[vector->size]=value; vector->size++;}
#define vec_pop(vector,variable) ({vector->size-=1; variable = vector->data[vector.size];} )
#define vec_get(vector, index) (vector->data[index])
#define vec_size(vector) (vector->size)
#define vec_destroy(vector) {free(vector->data);}
#define vec_foreach_val(vector,val, expr){for(size_t iteration = 0;iteration < vector->size;iteration++){typeof(vector->data[0]) val = vector->data[iteration]; {expr}}}
#define vec_foreach_ref(vector,ref, expr){for(size_t iteration = 0;iteration < vector->size;iteration++){typeof(vector->data) ref = &vector->data[iteration]; {expr}}}

int f(vec(double) vector)
{
    vec_foreach_ref(vector, number,
    {
        (*number)*=2;
    })
}

int main()
{
   vec(double) vector = vec_new(); 

   for(int i =0; i< 100; i++)
   {
    vec_push(vector,i);
   }
   
    f(vector);

    vec_foreach_val(vector, value,
    {
        printf("%f\n",value);
    })
   
   vec_destroy(vector)
}