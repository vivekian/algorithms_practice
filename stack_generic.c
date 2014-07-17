#include <stdio.h> 
#include <stdlib.h> 
#include <string.h> 

typedef struct Stack 
{ 
    void* ptr;
    unsigned elemSize; 
    unsigned logLength; 
    unsigned allocLength;
} Stack; 

int NewStack(Stack* S, unsigned ElemSize) 
{ 
    if (!S) 
    { 
        printf("Null Pointer Exception\n"); 
        return 1; 
    } 

    if (!ElemSize) 
    { 
        printf("Element size can't be 0\n"); 
        return 1; 
    } 

    S->elemSize = ElemSize; 
    S->logLength = 0;
    S->allocLength = 4; 
    S->ptr = malloc(S->allocLength * S->elemSize); 

    if (!S->ptr)
    { 
        printf("malloc failed\n"); 
        return 1; 
    } 

    return 0; 
}

int IsEmpty(Stack* S) 
{ 
    return (S->logLength == 0); 
} 

void PushStack(Stack* S, void* Elem) 
{
    if (S->logLength == S->allocLength) 
    {
        S->allocLength *= 2 ; 
        void* tmp = malloc(S->allocLength * S->elemSize); 
        memcpy(tmp, S->ptr, S->logLength * S->elemSize); 
        free(S->ptr); 
        S->ptr = tmp; 
    } 

    void* start = (char*)(S->ptr) + (S->elemSize * S->logLength); 
    memcpy(start, Elem, S->elemSize); 
    S->logLength++; 
    return; 
} 

int PopStack(Stack* S, void* Elem) 
{ 
    if (IsEmpty(S)) 
    { 
        printf("Stack is empty\n"); 
        return 1; 
    } 

    void* start = (char*)(S->ptr) + ((S->logLength - 1) * S->elemSize); 
    memcpy(Elem, start, S->elemSize);
    S->logLength--; 
    
    if ((S->allocLength > 4) && (S->allocLength / S->logLength) > 1)  
    { 
        S->allocLength /= 2; 
        void* tmp = malloc(S->allocLength * S->elemSize); 
        memcpy(tmp, S->ptr, S->logLength * S->elemSize); 
        free(S->ptr); 
        S->ptr = tmp; 
    } 

    return 0; 
} 

void DeleteStack(Stack* S)
{ 
    free(S->ptr); 
} 

int main() 
{
    Stack intS; 
    int i = 0; 
    int x; 

    NewStack(&intS, sizeof(int)); 

    for (i = 0; i < 16; i++) 
    { 
        PushStack(&intS, (void*)&i);
    } 

    for (i = 0; i < 16; i++) 
    { 
        PopStack(&intS, &x); 
        printf("%d\n", x); 
    } 

    DeleteStack(&intS); 
    
    Stack charS;
    char y = 'a';  

    NewStack(&charS, sizeof(char)); 
    PushStack(&charS, (void*)&y); 
    y++;
    PushStack(&charS, (void*)&y);
    y++;
    PushStack(&charS, (void*)&y);
    y++;
    PushStack(&charS, (void*)&y); 
    y++;
    PushStack(&charS, (void*)&y); 

    PopStack(&charS, &y); 
    printf("%c\n", y); 
    PopStack(&charS, &y); 
    printf("%c\n", y); 
    PopStack(&charS, &y);
    printf("%c\n", y); 
    PopStack(&charS, &y);
    printf("%c\n", y);
    PopStack(&charS, &y);
    printf("%c\n", y);
    
    DeleteStack(&charS);  
    
    return 0; 
} 
