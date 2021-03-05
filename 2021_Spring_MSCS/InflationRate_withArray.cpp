#include <iostream>
#include <cmath>
using namespace std;

void getCPIValues(float old_cpi, float new_cpi);
//precondition: get cpi take in 2 floats to generate a InflationRate
//postcondition: functions prompts for user inputs, and will alet user if input is not greater than 0
double getInflationRate(float old_cpi, float new_cpi);
//precondition: function takes in 2 floats, calculate inflation rates
//postcondition: function returns a double
void sort_array(double a[], int a_num);
//precondition: function takes in a double array and an int
//postcondition: function uses swap method to sort the array
double findMedianRate(double a[], int numRates);
//precondition: function takes in a double array and an int
//postcondition: function does calculation to find the median of the sorted array

float old_cpi=0, new_cpi=0;
int const MAX_RATES = 20;
double arr[MAX_RATES];

char confirm;
int counter = 0;
double result1, result2 = 0;

int main(){
  getCPIValues(old_cpi, new_cpi);
  //compute values when only greater than 0, append computed values into an array, set a counter to count total elements inside the array
  //requested to use do/while, execute do first no matter while is true or false, as long as inputs are digits, cin.good() stands

  for (int i=0;i<counter;i++){
    result2 += arr[i];
  }

  sort_array(arr, counter);
  cout << "Average rate is " << result2/counter << endl;

  double x = findMedianRate(arr, counter);
  cout << "Median rate is " << x << endl;
  
  return 0;
}

void getCPIValues(float old_cpi, float new_cpi){
  do{
    cout << "Enter the old and new consumer price indices: ";
    cin >> old_cpi >> new_cpi; //store inputs in consecutive order
    if (old_cpi > 0 && new_cpi > 0){
      result1 = getInflationRate(old_cpi, new_cpi);
      cout << "Inflation rate is " << result1 << endl;
      arr[counter] = result1;
      counter ++;

      cout << "Try again? (y or Y): ";//promt to ask if the user need to calculate again
      cin >> confirm;

      if (confirm != 'y' && confirm != 'Y' || counter == MAX_RATES){
        break;
        }
    } else {cout << "Error: CPI values must be greater than 0" << endl;}
  } while(cin.good());

}

double getInflationRate(float old_cpi, float new_cpi){
  try {
    return (new_cpi - old_cpi)/old_cpi * 100;
  } catch (const char*) {
    return 0;
  }
}

void swap_values(double &a, double &b){
  double temp = a;
  a = b;
  b = temp;
}

void sort_array(double a[], int a_num){
  int index;
  for(int i=0;i<a_num-1;i++){
    index = i;
    for(int j=i+1;j<a_num;j++){
      if (a[j] < a[index]){
        index = j;
      }
    }swap_values(a[index], a[i]);
  }
}

double findMedianRate(double a[], int numRates){ //if number of elements is even, return middle 2's average
  if(numRates%2==0){
    return (a[numRates/2]+a[numRates/2-1])/2;
  }
  int y = floor(numRates/2.0); //if number of elements is odd, return floored index of the arrary
  return a[y];
}
