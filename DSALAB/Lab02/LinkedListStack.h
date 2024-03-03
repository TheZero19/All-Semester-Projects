#pragma once
#include "interfaceClass.h"
#include<iostream>

//creating a Node class.
class Node{
  public:
    int data;
    Node* next;

    //constructor
    Node(int val){
      data = val;
      next = NULL;
    }
};

//inheriting from the Stack class.
class LinkedListStack : public Stack{
    int top, size;
    int *stack;

    public:
        LinkedListStack(){
            
        }
        LinkedListStack(int size){

        }
        ~LinkedListStack(){

        }
        void push(int element);
        int pop();
        bool isEmpty();
        bool isFull();
        int topElement();
};

void LinkedListStack::push(int element){

}

int LinkedListStack::pop(){

}

bool LinkedListStack::isEmpty(){

}

bool LinkedListStack::isFull(){

}

int LinkedListStack::topElement(){

}
