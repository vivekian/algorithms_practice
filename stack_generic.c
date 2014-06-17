#include <stdio.h> 
#include <stdlib.h> 
#include <string.h> 

typedef struct vector 
{ 
    void* ptr;
    unsigned elemSize; 
    unsigned logLength; 
    unsigned allocLength;
} Vector; 

int NewVector(Vector* V, unsigned ElemSize) 
{ 
    if (!V) 
    { 
        printf("Null Pointer Exception\n"); 
        return 1; 
    } 

    if (!ElemSize) 
    { 
        printf("Element size can't be 0\n"); 
        return 1; 
    } 

    V->elemSize = ElemSize; 
    V->logLength = 0;
    V->allocLength = 4; 
    V->ptr = malloc(V->allocLength * V->elemSize); 

    if (!V->ptr)
    { 
        printf("malloc failed\n"); 
        return 1; 
    } 

    return 0; 
}

int IsEmpty(Vector* V) 
{ 
    return (V->logLength == 0); 
} 

void PushVector(Vector* V, void* Elem) 
{
    if (V->logLength == V->allocLength) 
    {
        V->allocLength *= 2 ; 
        void* tmp = malloc(V->allocLength * V->elemSize); 
        memcpy(tmp, V->ptr, V->logLength * V->elemSize); 
        free(V->ptr); 
        V->ptr = tmp; 
    } 

    void* start = (char*)(V->ptr) + (V->elemSize * V->logLength); 
    memcpy(start, Elem, V->elemSize); 
    V->logLength++; 
    return; 
} 

int PopVector(Vector* V, void* Elem) 
{ 
    if (IsEmpty(V)) 
    { 
        printf("Stack is empty\n"); 
        return 1; 
    } 

    void* start = (char*)(V->ptr) + ((V->logLength - 1) * V->elemSize); 
    memcpy(Elem, start, V->elemSize);
    V->logLength--; 
    
    if ((V->allocLength > 4) && (V->allocLength / V->logLength) > 1)  
    { 
        V->allocLength /= 2; 
        void* tmp = malloc(V->allocLength * V->elemSize); 
        memcpy(tmp, V->ptr, V->logLength * V->elemSize); 
        free(V->ptr); 
        V->ptr = tmp; 
    } 

    return 0; 
} 

void DeleteVector(Vector* V)
{ 
    free(V->ptr); 
} 

int main() 
{
    Vector intV; 
    int i = 0; 
    int x; 

    NewVector(&intV, sizeof(int)); 

    for (i = 0; i < 16; i++) 
    { 
        PushVector(&intV, (void*)&i);
    } 

    for (i = 0; i < 16; i++) 
    { 
        PopVector(&intV, &x); 
        printf("%d\n", x); 
    } 

    DeleteVector(&intV); 
    
    Vector charV;
    char y = 'a';  

    NewVector(&charV, sizeof(char)); 
    PushVector(&charV, (void*)&y); 
    y++;
    PushVector(&charV, (void*)&y);
    y++;
    PushVector(&charV, (void*)&y);
    y++;
    PushVector(&charV, (void*)&y); 
    y++;
    PushVector(&charV, (void*)&y); 

    PopVector(&charV, &y); 
    printf("%c\n", y); 
    PopVector(&charV, &y); 
    printf("%c\n", y); 
    PopVector(&charV, &y);
    printf("%c\n", y); 
    PopVector(&charV, &y);
    printf("%c\n", y);
    PopVector(&charV, &y);
    printf("%c\n", y);
    
    DeleteVector(&charV);  
    
    return 0; 
} 
