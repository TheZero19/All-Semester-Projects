#include<iostream>
#include "ArrayQueue.h"

using namespace std;

int main(){
    //Creating a Queue of size 10.
    ArrayQueue aq1(10);

    //trying out isEmpty().
    if(aq1.isEmpty()){
        cout<<"Queue empty.."<<endl;
    }

    //trying out isFull().
    if(aq1.isFull()){
        cout<<"Queue Full..."<<endl;
    }else{
        cout<<"Queue not Full..."<<endl;
    }

    //enqueuing element(s).
    aq1.enqueue(10);
    aq1.enqueue(20);
    aq1.enqueue(30);
    aq1.enqueue(40);
    aq1.enqueue(50);

    //testing out front() and rear().
    cout<<"Front Element: "<<aq1.frontElement()<<endl;
    cout<<"Rear Element: "<<aq1.backElement()<<endl;

    //checking out dequeue().
    aq1.dequeue();
    cout<<"Front Element: "<<aq1.frontElement()<<endl;

}
