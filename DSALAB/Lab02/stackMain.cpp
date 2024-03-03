#include<iostream>
#include "ArrayStack.h"

using namespace std;

int main(){
    //Creating a Stack of size 10.
    ArrayStack as1(10);

    //trying out isEmpty().
    if(as1.isEmpty()){
        cout<<"Stack empty.."<<endl;
    }

    //trying out isFull().
    if(as1.isFull()){
        cout<<"Stack Full..."<<endl;
    }else{
        cout<<"Stack not Full..."<<endl;
    }

    //pushing element(s) into the stack.
    as1.push(10);
    as1.push(20);
    as1.push(30);
    as1.push(40);
    as1.push(50);

    //testing out top().
    cout<<"Top Element: "<<as1.topElement()<<endl;

    //checking out pop().
    cout<<"Popped Element: "<<as1.pop()<<endl;
    as1.pop();
    as1.pop();
    as1.pop();
    as1.pop();
    as1.pop();
    as1.pop();
    as1.pop();
}
