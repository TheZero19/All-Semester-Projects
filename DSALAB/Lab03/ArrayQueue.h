#pragma once
#include "interfaceClass.h"
#include<iostream>

#define defaultSize 10

class ArrayQueue : public Queue{
    int front, rear, size;
    int *queue;

    public:
        ArrayQueue(){
            front = -1;
            rear = -1;
            this->size = defaultSize;
            queue = new int[size];
        }
        ArrayQueue(int size){
            front = -1;
            rear = -1;
            this->size = size;
            queue = new int[size];
        }
        ~ArrayQueue(){
            delete[] queue;
        }
        void enqueue(int element);
        int dequeue();
        bool isEmpty();
        bool isFull();
        int frontElement();
        int backElement();
};

bool ArrayQueue::isEmpty(){
    if(front == rear){
        return true;
    }
    return false;
}

bool ArrayQueue::isFull(){
    if(rear == this->size - 1){
        return true;
    }
    return false;
}

void ArrayQueue::enqueue(int element){
    if(isFull()){
        std::cout<<"Queue Overflow!"<<std::endl;
        return;
    }else{
        rear++;
        queue[rear] = element;
    }
}

int ArrayQueue::frontElement(){
    return queue[front + 1];
}

int ArrayQueue::backElement(){
    return queue[rear];
}

int ArrayQueue::dequeue(){
    if(isEmpty()){
      std::cout<<"Queue Underflow!"<<std::endl;
      return 0;
    }else{
      front = front + 1;
      return queue[front - 1];
    }
}
