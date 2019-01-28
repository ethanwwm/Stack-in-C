// C program for linked list implementation of stack 
#include <limits.h> 
#include <stdio.h> 
#include <stdlib.h> 

/*
Error codes:
0: Unable to push onto stack
1: Unable to pop from stack
*/
  
// A structure to represent a stack 
struct stack_t { 
    struct node* top; 
};

struct node {
    int value;
    struct node* next;
};

struct stack_t *Stack_new() {
    struct stack_t* stack_t = (struct stack_t*)malloc(sizeof(struct stack_t)); 
    stack_t -> top = NULL;
      
    return stack_t;
  }

void Stack_push(struct stack_t *stack, int value, int *error) { 
    struct node* newNode = (struct node*)malloc(sizeof(struct node)); 
    newNode -> value = value;
    
    if(stack->top == NULL) {
        stack -> top = newNode;
    } else {
        struct node* temp = (struct node*)malloc(sizeof(struct node));
        temp = stack -> top;
        newNode -> next = temp;
        stack -> top = newNode;
    }
    
    if(stack -> top != newNode) {
        *error = 1;
        printf("Error code %d: Unable to push onto stack", *error);
        exit(0);
    }
    
    printf("Pushed %d\n", stack->top->value);
} 
  
int Stack_pop(struct stack_t *stack, int *error) { 
    int popped = stack -> top -> value;
    
    if(popped != stack -> top -> value) {
        *error = 2;
        printf("Error code %d: Unable to pop from stack", *error);
        exit(0);
    }
    
    stack -> top = stack -> top -> next;
    
    return popped;
} 
  

void Stack_delete(struct stack_t *stack) {
    stack -> top = NULL;
    
    
}
  
int main() { 
    struct stack_t* newStack = Stack_new(); 
  
    Stack_push(newStack, 10, 0); 
    Stack_push(newStack, 20, 0); 
    Stack_push(newStack, 30, 0); 
  
    printf("%d popped from stack\n", Stack_pop(newStack, 0)); 
    
    Stack_delete(newStack);

    return 0; 
} 
