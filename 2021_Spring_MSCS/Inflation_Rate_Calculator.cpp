#include <iostream>
#include <sstream> //to read buffer
#include <limits> //mimir did not compile without this header so I have to include it
using namespace std;

//The purpose of this code is to calculate the average inflation rates through avg=sum/count
//Requires user input and the code is designed to against invalid inputs
//If the user enter string or char or fraction, instead of digits, the program will ask user to input again
//If the user enter anything else but 'y' or 'Y' respond to the "try again?", the program will exit the while loop


//declaration
double getInflationRate(float old_cpi, float new_cpi);
void transition();

float OldCpi = 1.0, NewCpi = 1.0;
char confirm;
bool Checkpoint = true, Checkpoint2 = true;
int counter = 0;
double result1, result2;

//main
int main(){
  while (Checkpoint) {
    
    while (Checkpoint2){
      cout << "Enter the old and new consumer price indices: " << endl;
      cin >> OldCpi >> NewCpi; //store inputs in consecutive order

      if (cin.fail()){
        cout << "Invalid input" << endl; // prompt to alert user
        cout << "OldCpi: " << OldCpi << ", NewCpi: " << NewCpi << endl;

        auto* buf = cin.rdbuf(); //try to read the buffer
        cout << "before, sgetc: " << buf->sgetc() << endl;

        cin.clear();

        cout << "after clear, sgetc: " << buf->sgetc() << endl;

        cin.ignore(numeric_limits<streamsize>::max(), '\n'); //ignore the maximum allowed streamsize untill and include the new line 
        
        cout << "after ignore, sgetc: " << buf->sgetc() << endl;
        //Discoveries: sgetc() will print out the space askii code when enter 'a ' 'b ' 'c ' 'd ' 'e ' 'f ' but stops at 'g '
        //Thoughts: the compiler might initially assume I tried to enter hexadecimal, because cin stored those letters and thus the OldCpi was changed to 0
        //Dicoveries: if the input is '2/3', then 2 will be stored but the sgetc() will print backward slash askii code, and at this point both OldCpi and NewCpi both turned into 0
        //Thoughts: Since 2 is a valid value, the cin might tried to pass this value to both variables thus resulted both variables turned into 0

//----------------previous notes-----------------------
        // my understanding is that, cin.clear() clears the error flag..
        //and cin.ignore(....) extract maximum allowed characters in the stream(buffer?) until is reached the \n then discard all of them
        //so the buffer is empty that will allow the prompt to reappear and to ask for new inputs

        //after running lldb, it is clear that in case1: inputs are a and 1, a will be erased by cin.clear() when line 32 is disabled, 1 will be stored in buffer,
        //the program then goes back to the prompt and asking for new input, after new input entered, the old input 1 will be stored into OldCpi no matter what,
        //the program will check again if the new input qualify to be stored into the NewCpi, if not, program starts again

        //however, when case2: input is 2/3, 2 will be stored into OldCpi but nothing will be stored into NewCpi; thus trigger the cin.fail(), after cin.clear(),
        //seems like the 2 is erased from the OldCpi, at this point both OldCpi and NewCpi print out as 0, and maybe becuase the /3 are still in the buffer,
        //that's why it triggers the infinite while loop - theoretically speaking
//------------------------------------------------------
        
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
// //This program calculates the inflation rate given two Consumer Price Index values and prints it to the monitor.
//
// #include <iostream>
// using namespace std;
//
// /*
//  * getInflationRate - calculates the inflation rate given the old and new consumer price index
//  * @param old_cpi: is the consumer price index that it was a year ago
//  * @param new_cpi: is the consumer price index that it is currently
//  * @returns the computed inflation rate or 0 if inputs are invalid.
//  */
// double getInflationRate(float old_cpi, float new_cpi);
//
// int main()   //C++ programs start by executing the function main
// {
//    // TODO #1: declare two float variables for the old consumer price index (cpi) and the new cpi
//
//
//    // TODO #2: Read in two float values for the cpi and store them in the variables
//
//
//    // TODO #3: call the function InflationRate with the two cpis
//
//
//    // TODO #4: print the results
//
//
//    return 0;
// }
//
//
// // double getInflationRate(float old_cpi, float new_cpi)
// // precondition:   both prices must be greater than 0.0
// // postcondition:  the inflation rate is returned or 0 for invalid inputs
// double getInflationRate(float old_cpi, float new_cpi)
// {
//    // TODO: Implement InflationRate to calculate the percentage increase or decrease
//    // Use (new_cpi - old_cpi) / old_cpi * 100
//
// }
