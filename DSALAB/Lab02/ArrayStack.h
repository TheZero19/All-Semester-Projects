#pragma once
#include "interfaceClass.h"
#include<iostream>

//FOR DEFAULT CONSTRUCTOR AND TO SPECIFY THE DEFAULT SIZE OF STACK:
#define defaultSize 10


class ArrayStack : public Stack{
    int top, size;
    int *stack;

    public:
        ArrayStack(){
            top = -1;
            this->size = defaultSize;
            stack = new int[size];
        }
        ArrayStack(int size){
            top = -1;
            this->size = size;
            stack = new int[size];
        }
        ~ArrayStack(){
            delete[] stack;
        }
        void push(int element);
        int pop();
        bool isEmpty();
        bool isFull();
        int topElement();
};

bool ArrayStack::isEmpty(){
    if(top == -1){
        return true;
    }
    return false;
}

bool ArrayStack::isFull(){
    if(top == this->size - 1){
        return true;
    }
    return false;
}

void ArrayStack::push(int element){
    if(isFull()){
        std::cout<<"Stack Overflow!"<<std::endl;
        return;
    }else{
        top++;
        stack[top] = element;
        return;
    }
}

int ArrayStack::topElement(){
    return stack[top];
}

int ArrayStack::pop(){
    if(isEmpty()){
      std::cout<<"Stack Underflow!"<<std::endl;
      return 0;
    }else{
      return stack[top--]; //return the topmost element and then decrease the top by 1(post increment).
    }
}
