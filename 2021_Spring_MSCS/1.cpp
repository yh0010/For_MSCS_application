#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

//Declaration
const int CAPACITY = 20;

// void print(const int &i);
void fillArray(int array[], int &numberElements);
void displayArray(int array[], int numElems);
bool insertElement(int array[], int numberElements, int position, int target);


int main(){
  int NumArray[CAPACITY];	// an int array with a given CAPACITY
  int numberElements = 0;



  // cout << "Enter a list up to 20 integers or -1 to end the list" << endl;
  // cin >> NumArray;
  // int len = sizeof(NumArray)/sizeof(NumArray[0]);
  // cout << "The length of the array is: " << len;


  fillArray(NumArray, numberElements);
  insertElement(NumArray, numberElements, 0, 0);
  displayArray(NumArray, numberElements+1);

  // for (int i = 0; i < CAPACITY; i++){
  //   if (arr[i] != 0){
  //     cout << arr[i] << ' ';
  //   }
  //   }
  //cout << "final print out: " << for_each(begin(arr), end(arr), print) << endl;



  return 0;
}

//Definition
// void print(const int &i) {
//     cout << i << ' ';
// }
void displayArray(int array[], int numElems)
{
    for (int i = 0; i < numElems; i++)
        cout << array[i] << " ";
    cout << endl;
}
//******
// void fillArray(int array[]){
//   int test[CAPACITY];
//   int total = 0;
//
//   cout << "Enter a list up to 20 integers or -1 to end the list" << endl;
//
//   for (int i = 0; i < CAPACITY; i++){
//     cin >> test[i];
//     //cout << "before break" << array[i] << endl;
//     if (test[i] != -1){
//       total += 1;
//       array[i] = test[i];
//     } else { break; }
//     // cout << "after break" << array[i] <<endl;
//   }
//******

void fillArray(int array[], int &numberElements){
  cout << "Enter a list up to 20 integers or -1 to end the list" << endl;
  int next, index = 0;
  cin >> next;
  while ((next >=0) && (index < CAPACITY)){
    array[index] = next;
    index++;
    cin >> next;
  }
  // for (int i = 0; i < numberElements; i++){
  //   cin >> array[i];
  // }
  numberElements = index;

  displayArray(array, numberElements);

  // for (int i = 0; i < total; i++){
  //   cout << array[i] << ' ';


    // if (array[i] != 0){
    //   cout << array[i] << ' ';
    // }
  //}
}

bool insertElement(int array[], int numberElements, int position, int target){
  cout << "Enter a value and a position to insert: ";
  int next1, next2, index = 0;
  cin >> next1 >> next2;
  target = next1;
  position = next2;
  for (int i = numberElements; i >= position - 1; i--){
    array[i+1] = array[i];
  }
  array[position] = target;
  if (array[position] == target){
    
    return true;
  } else {return false;}

}
