/* Working with arrays and functions
 * Author: Elaina Huang
 * Last modified on: Feb 18, 2021
 * Known bug
 */
#include <iostream>
using namespace std;

//Function Declaration
const int CAPACITY = 20;

// void print(const int &i);
void fillArray(int array[], int &numberElements);
//Precondition: function expects an array and a variable that will be stored as a call-by-reference
//Postcondition: function executes an array, and will calculate a new value be stored as a call-by-reference
bool insertElement(int array[], int &numberElements, int position, int target);
//Precondition: function expects an array and a variable that will be stored as a call-by-reference, int position expect a non-negative integer, int target also expects a non-negative integer for input
//Postcondition: function executes an array, and will calculate a new value be stored as a call-by-reference, for int position && int target the function could be passed in a random entry for initialization purpose, later on inside the functions
//the cin will take the user inputs to overwrite both the position and targer
bool removeElement(int array[], int &numberElements, int position);
//Precondition: function expects an array and a variable that will be stored as a call-by-reference, int position expect a non-negative integer
//Postcondition: function executes an array, and will calculate a new value be stored as a call-by-reference, for int position the function could be passed in a random entry for initialization purpose, later on inside the functions
//the cin will take the user inputs to overwrite the position
void appendElement(int array[], int &numberElements, int value);
//Precondition: function expects an array and a variable that will be stored as a call-by-reference, int value expect a non-negative integer
//Postcondition: function executes an array, and will calculate a new value be stored as a call-by-reference, for int value the function could be passed in a random entry for initialization purpose, later on inside the functions
//the cin will take the user inputs to overwrite the value


int main(){
  int NumArray[CAPACITY] = {};	// an int array with a given CAPACITY
  int numberElements = 0;

  // int len = sizeof(NumArray)/sizeof(NumArray[0]);
  // cout << "The length of the array is: " << len;


  fillArray(NumArray, numberElements);
  insertElement(NumArray, numberElements, 0, 0);
  removeElement(NumArray, numberElements, 0);
  appendElement(NumArray, numberElements, 0);

  //cout << "final print out: " << for_each(begin(arr), end(arr), print) << endl;
  return 0;
}

//Function Definition
void displayArray(int array[], int numElems)
{
    for (int i = 0; i < numElems; i++)
        cout << array[i] << " ";
    cout << endl;
}
///
//******the way that I do not use call-by-reference to achieve same result as the other fill function does
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
///
void fillArray(int array[], int &numberElements){
  cout << "Enter a list of up to 20 integers or -1 to end the list" << endl;
  int next, index = 0;
  cin >> next; //whatever the output datatype is defined, cin could only take in 1 valid value at a time
  //much like the breakout/brick breaker's moveable bar, whereas the valid input is a ball
  while ((next >=0) && (index < CAPACITY)){
    array[index] = next;
    index++;
    if (index != 20){ cin >> next; }
    else{ break; }

    //because this happens inside the while loop, so that the line 81 cin will theoretically forever asking
    //user for new inputs untill user enter an negative number, then program moves on to line 88
  }
  numberElements = index;

  displayArray(array, numberElements); //here we print
}
///
//the method I learn from class which is opposite to removeElement(), by array[i+1] = array[i], this way will push everything from the target index move 1 step further to create empty space without loosing any data
bool insertElement(int array[], int &numberElements, int position, int target){
  cout << "Enter a value and a position to insert: ";
  cin >> target >> position;

  if ((numberElements < CAPACITY) && (position <= numberElements) && (position >= 0)){
    for (int i = numberElements; i >= position - 1; i--){
      array[i+1] = array[i];
    }

    array[position] = target;
    numberElements++;
    displayArray(array, numberElements); //here we print
    return true;
  } else {
    displayArray(array, numberElements);
    return false; }
}
///
int searchElement(int array[], int numberElements, int target){

  for(int i = 0; i <= numberElements; i++){
    if (array[i] == target) {
      return i;
    }
  }
  return -1;
}
///
//if the target element exist, which means the searchElement() do not return -1, then this function could proceed
bool removeElement(int array[], int &numberElements, int position){
  int target;
  cout << "Enter a value to delete from the array: ";
  cin >> target;

  int t = searchElement(array, numberElements, target);
  if (t != -1){
    for (int i = t; i <= numberElements - 1; i++){
      array[i] = array[i+1];
    }
    numberElements--;
    displayArray(array, numberElements); //here we print
    return true;
  } else {
    cout << "Value not found!" << endl;
    return false; }
}
///
//any number(expect non-negative digits) could append, as long as the CAPACITY is not full then the displayArray could ++ to display one more element
void appendElement(int array[], int &numberElements, int value){

  cout << "Enter a value to append: ";
  cin >> value;

  if (numberElements != CAPACITY){
  array[numberElements] = value;
  displayArray(array, numberElements+1);
} else {
  displayArray(array, numberElements);
}
}
