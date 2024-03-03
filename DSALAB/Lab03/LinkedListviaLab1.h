#pragma once
#include<iostream>
using namespace std;

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

//check if the linked list is empty.
bool isEmpty(Node* head){
  if(head == NULL){
    return true;
  }
  return false;
}

//function to add node at the head of the linked list.
void addToHead(Node* &head, int val){
    Node* newNode = new Node(val);
    newNode->next = head;
    head = newNode;
}

//function to add node at the end of the linked list.
void addToTail(Node* &head, int val){
  Node* newNode = new Node(val);

  //if we have no nodes, just make the new node as head node.
  if(head == NULL){
    head = newNode;
    return;
  }

  //else when there are nodes, traverse till the end and add the new node at the end of the linked list.
  Node* temp = head;
  while(temp->next != NULL){
    temp = temp->next;
  }
  temp->next = newNode;
}

//adding node after the given predecessor node.
void add(Node* &head, int predecessorData, int newNodeVal){
  Node* newNode = new Node(newNodeVal);

  Node* temp = head;
  while(temp->next != NULL){
    if(temp->data == predecessorData){
      newNode->next = temp->next;
      temp->next = newNode;
      return;
    }
    temp = temp->next;
  }
}

//remove the head node.
void removeFromHead(Node* &head){
  if(head == NULL){
    cout<<"NULL";
    return;
  }
  Node* temp = head;
  head = head->next;
  delete temp;
}

//function to remove the node with the given value.
void remove(Node* &head, int NodeData){
  Node* temp = head;
  Node* temp2 = head->next;

  if(isEmpty(head)){
      cout<<"Linked list empty!"<<endl;
      return;
  }

  if(temp->data == NodeData){
    head = temp->next;
    delete temp;
    return;
  }

  while(temp2->next != NULL){
    if(temp2->data == NodeData){
      temp->next = temp2-> next;
      delete temp2;
      return;
    }
    temp = temp->next;
    temp2 = temp2->next;
  }
}

//function to return pointer to the node with the requested data.
Node* retrieve(Node* &head, int NodeData){
  Node* temp = head;
  while(temp->next != NULL){
    if(temp->data == NodeData){
      cout<<"The node with the provided data was found!"<<endl;
      return temp;
    }
    temp= temp->next;
  }
  cout<<"No nodes matched with the provided data."<<endl;
  return NULL;
}

//searching if there is the given data in at least on of the nodes.
void search(Node* &head, int NodeData){
  Node* temp = head;
  while(temp->next != NULL){
    if(temp->data == NodeData){
      cout<<"Available in the linkedlist."<<endl;
      return;
    }
    temp= temp->next;
  }
  cout<<"Not Available in the linkedlist."<<endl;
  return;
}

//function to display all the nodes in the linked list, traversing through each nodes and displaying the data of the nodes.
void traverse(Node* head){
  Node* temp = head;
  while(temp!=NULL){
    cout<<temp->data<<"->";
    temp = temp->next;
  }
  cout<<"NULL"<<endl;
}
