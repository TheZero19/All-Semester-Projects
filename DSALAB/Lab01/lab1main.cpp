#include "lab1.h"

//testing stuffs.
int main(){
  //creating head node, initialized as NULL to indicate the linked list at the moment is empty.
  Node* head = NULL;

  //adding nodes to tail.
  addToTail(head, 1);
  addToTail(head, 2);
  addToTail(head, 3);

  //checking the "isEmpty() function"
  if(isEmpty(head)){
    cout<<"Linked list empty."<<endl;
  }else{
    cout<<"Linked list not empty."<<endl;
  }

  //displaying contents of the linked list.
  traverse(head);

  //inserting at add.
  addToHead(head, 4);
  addToHead(head, 5);
  traverse(head);

  //inserting after a predecessor.
  add(head, 1, 0);
  traverse(head);

  //trying out removeFromHead().
  removeFromHead(head);
  traverse(head);

  //trying to remove node based on node data.
  remove(head, 2);
  traverse(head);

  //trying out the search() function.
  search(head, 5);
  search(head, 1);

  //trying out the retrieve funtion.
  retrieve(head, 4);
  retrieve(head, 100);

  return 0;
}
