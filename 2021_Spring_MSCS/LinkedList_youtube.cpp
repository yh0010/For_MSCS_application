#include <iostream>
#include <cstdlib>
using namespace std;

//linked list practice

// struct Node{
//   int data;
//   Node* next;
// };
//
// int main(){
//
//   Node* head;
//   Node* temp;
//   Node* tail;
//
//   temp = new Node;
//   temp -> data = 1;
//   tail = temp;
//   head = temp;
//
//   temp = new Node;
//   temp -> data = 2;
//   tail -> next = temp;
//   tail = tail -> next;
//
//   temp = new Node;
//   temp -> data = 3;
//   tail -> next = temp;
//   temp -> next = NULL;
//
//   while(head != NULL){
//     cout << head -> data << endl;
//     head = head -> next;
//   };
//
//   return 0;
// }

class List{
private:
  struct node{
    int data;
    node* next;
  };

  node* head;
  node* temp;
  node* tail;

public:
  List();
  void AddNode(int addData);
  void DeleteNode(int delData);
  void DisplayList();
};

int main(){

  List linkedLst;
  linkedLst.AddNode(1);
  linkedLst.AddNode(12);
  linkedLst.AddNode(123);
  linkedLst.DisplayList();

  linkedLst.DeleteNode(1);
  linkedLst.DisplayList();

  return 0;
}

List::List(){
  head = NULL;
  temp = NULL;
  tail = NULL;
};

void List::AddNode(int addData){
  node* n = new node();
  n->next = NULL;
  n->data = addData;

  if (head != NULL){
    tail = head;
    while(tail->next != NULL){
      tail = tail->next;
    }
    tail->next = n;
  }

  else{
    head = n;
  }
};

void List::DeleteNode(int delData){
  node* delPtr = NULL;
  temp = head;
  tail = head;
  while(tail != NULL && tail->data != delData){
    temp = tail;
    tail = tail->next;
  }
  if(tail == NULL){
    cout << delData << " was not in the list.\n";
    delete delPtr;
  }
  else{
    delPtr = tail;
    tail = tail->next;
    temp->next = tail;
    if(delPtr == head){
      head = head->next;
      temp = NULL;
    }
    delete delPtr;
    cout << "The value " << delData << " was deleted.\n";
  }
};

void List::DisplayList(){
  tail = head;
  while(tail != NULL){
    cout << tail->data << endl;
    tail = tail->next;
  }
};
//////
// #include <iostream>
//
// class A
// {
// public:
//     A()
//     {
//         std::cout << "A::A: constructed at " << this << std::endl;
//     }
//
//     void SayHello()
//     {
//         std::cout << "Hi! I am the instance of A at " << this << std::endl;
//     }
// };

int main(int, char **)
{
    // A a1;
    // cout << "above is a1.\n";
    // A a2;
    //
    // a1.SayHello();
    // a2.SayHello();

    int x = 052;
    cout <<x<<endl;

    return 0;
}
