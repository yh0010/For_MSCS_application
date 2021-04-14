#include <cstdlib>
#include <iostream>
#include <string>

using namespace std;

class hash{
private:
  static const int tablesize = 10; //

  struct item{
    string name;
    string drink;
    item* next;
  };

  item* HashTable[tablesize];
public:
  hash();
  int Hash(string key);
  void AddItem(string name, string drink);
  int NumOfItems(int index);
  void DisplayTable();
  void DisplayTableList(int index);
  void FindDrink(string name);
};
////declaration
int main(){
  ::hash hashObj;
  hashObj.AddItem("Paul", "Locha");
  hashObj.AddItem("Pauk", "Mocha");
  hashObj.AddItem("Yaogui", "Cola");
  hashObj.AddItem("Yaogui", "Pipe");
  hashObj.AddItem("Alex", "Juice");
  hashObj.AddItem("Alex", "Tea");
  hashObj.AddItem("Yijie", "Latte");
  hashObj.AddItem("Kate", "Coffee");
  hashObj.AddItem("Bob", "Water");
  hashObj.DisplayTable();


  return 0;
}

////definition
int ::hash::Hash(string key){
  int index, val = 0;
  for(int i=0; i<key.length(); i++){
    val = val + (int)key[i];
  }

  index = val % tablesize;
  return index;
};

::hash::hash(){
  for(int i=0; i<tablesize; i++){
    HashTable[i] = new item;
    HashTable[i] -> name = "empty";
    HashTable[i] -> drink = "empty";
    HashTable[i] -> next = NULL;
  }
};

void ::hash::AddItem(string name, string drink){
  int index = Hash(name);
  if(HashTable[index]->name == "empty"){
    HashTable[index]->name = name;
    HashTable[index]->drink = drink;
    HashTable[index]->next = NULL;
  }

  else{
    item* Ptr = HashTable[index];
    item* n = new item();
    n->name = name;
    n->drink = drink;
    n->next = NULL;
    while(Ptr->next != NULL){
      Ptr = Ptr->next;
    }
    Ptr->next = n;
  }
};

int ::hash::NumOfItems(int index){
  int counter=0;
  if(HashTable[index]->name == "empty"){return counter;}
  else{
    counter++;
    item* Ptr = HashTable[index];
    while(Ptr->next != NULL){
      counter++;
      Ptr = Ptr->next;
    }
    return counter;
  }
};

void ::hash::DisplayTable(){
  int num;
  for(int i=0; i<tablesize; i++){
    cout << "================"<<endl;
    cout << "Table index: "<< i << endl;
    cout << "Name: "<< HashTable[i]->name<< endl;
    cout << "Drink: "<< HashTable[i]->drink<< endl;
    num = NumOfItems(i);
    cout << "Total persons in the list: "<< num<< endl;
    //cout << "==============="<<endl;
    DisplayTableList(i);

  }
};

void ::hash::DisplayTableList(int index){
  item* Ptr = HashTable[index];
  if (HashTable[index]->name == "empty"){cout<< "End of the list.\n";}
  else{
  while( Ptr->next != NULL){
    cout << "From the list as the following: \n";
    cout << Ptr->next->name << endl;
    cout << Ptr->next->drink << endl;
    Ptr = Ptr->next;
    cout << "---------------"<<endl;
  }
  cout << "End of the list.\n";}

};

void ::hash::FindDrink(string name){
  int index = Hash(name);
  bool foundName = false;
  string drink;

  item* Ptr = HashTable[index];
  while(Ptr != NULL){
    if(Ptr->name == name){
      foundName = true;
      drink = Ptr -> drink;
    }
    Ptr = Ptr->next;
  }
  if(foundName){
    cout << "Favorite drink = "<< drink<<endl;
  }
  else{cout << name << "'s info was not found in the Hash Table.\n";}
};
