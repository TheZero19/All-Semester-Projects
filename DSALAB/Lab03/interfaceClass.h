#pragma once

class Queue{
    public:
        virtual void enqueue(int element) = 0;
        virtual int dequeue() = 0;
        virtual bool isEmpty() = 0;
        virtual bool isFull() = 0;
        virtual int frontElement() = 0;
        virtual int backElement() = 0;
};
