#include <iostream>
using namespace std;

//The purpose of this code is to calculate the average inflation rates through avg=sum/count
//Requires user input and the code is designed to against invalid inputs
//If the user enter string or char instead of digits, the program will ask user to input again
//If the user enter anything else but 'y' or 'Y' respond to the "try again?", the program will exit the while loop


//declaration
double getInflationRate(float old_cpi, float new_cpi);
void transition();

float OldCpi, NewCpi;
char confirm;
bool Checkpoint = true, Checkpoint2 = true;
int counter = 0;
double result1, result2;

//main
int main(){

  while (Checkpoint) {

    while (Checkpoint2){
      cout << "Enter the old and new consumer price indices: ";
      cin >> OldCpi >> NewCpi; //store inputs in consecutive order

      if (cin.fail()){
        cout << "Invalid input" << endl; // prompt to alert user
        cin.clear(); //clear the error input so the new start can take in new inputs
      } else {
        Checkpoint2 = false; //if the inputs were valid then exit this loop
      }
  }



    if (OldCpi > 0 && NewCpi > 0 && OldCpi != NewCpi){ //to calculate valid inflation rates, the inputs are only allowed to be positive and different numbers
      result1 = getInflationRate(OldCpi, NewCpi);

      cout << "Inflation rate is " << result1 << endl;

      counter++;
      result2 = result1 + result2;

      transition();}

      else {

        cout << "Inflation rate is " << 0 << endl;

        transition();
    }
  }

  return 0;
}

//defnition
double getInflationRate(float old_cpi, float new_cpi){
  try {
    return (new_cpi - old_cpi)/old_cpi * 100;
  } catch (const char*) {
    return 0;
  }
}
//use void function to decrease runtime
void transition(){
  cout << "Try again? (y or Y): ";//promt to ask if the user need to calculate again
  cin >> confirm;
  Checkpoint2 = true;//restore the Checkpoint2 to be true, so that the program is again enable to ask user for inputs

  if (confirm != 'y' && confirm != 'Y'){
    cout << "Average rate is " << result2/counter << endl;
    Checkpoint = false;
    }

}

///////////////////////////////

//Description of the Homework

///////////////////////////////
// DESCRIPTION
// This lab is Part 2 of a 2 Part Lab called InflationRate. Please complete the instructions. Here is sample output for one run of the program when it's complete. Match the output EXACTLY.
// 
// 
// 
// Enter the old and new consumer price indices: 238.343 238.250
// Inflation rate is -0.0390204
// Try again? (y or Y): y
// Enter the old and new consumer price indices: 238.250 237.852
// Inflation rate is -0.167049
// Try again? (y or Y): n
// Average rate is -0.103035
// 
// 
// 
// Part 2
// 
// 1. Here are the original instructions from Part 1.
// 
// 
// 
// // TODO #1: declare two float variables for the old consumer price index (cpi) and the new cpi
// 
// 
// // TODO #2: Read in two float values for the cpi and store them in the variables
// 
// 
// // TODO #3: call the function InflationRate with the two cpis
// 
// 
// // TODO #4: print the results
// 
// 
// 
// 2. Put the logic in TODO #2-4 into a loop that asks the user to enter 'y' (or 'Y') if there's more data to be entered.
// 
// 
// 
// 3. Keep a running total of the valid inflation rates and the number of computed rates to calculate the average rate.
// 
// 
// 
// 4. Print the results after the loop

