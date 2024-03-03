#pragma once

class Stack{
    public:
        virtual void push(int element) = 0;
        virtual int pop() = 0;
        virtual bool isEmpty() = 0;
        virtual bool isFull() = 0;
        virtual int topElement() = 0;
};
