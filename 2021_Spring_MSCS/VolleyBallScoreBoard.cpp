#include <iostream>
#include <string>
using namespace std;
//purpose:
//calculate the individual total of team A and team B, when the user input is 'A', team A gets 1 score, vice versa
//when either of the team wins, or when they have a tie, the while loop breaks
//if a team wins, the loop breaks because of a false return created by the bool function, if there's a tie, loop breaks on break statement

bool weHaveAWinnder(int aPoints, int bPoints, string input);

int main() {
    int aPoints = 0;
    int bPoints = 0;
    string input;
    int x = 1;

    while (x == 1){

      cin >> input;

      if (input == "A"){
        aPoints += 1;
        x = weHaveAWinnder(aPoints, bPoints, input);
      }

      else if ( input == "B"){
        bPoints += 1;
        x = weHaveAWinnder(aPoints, bPoints, input);
      }
      else if ((input == "end")&&(aPoints == bPoints)&&(aPoints >= 21)){
          cout << "Game ended as a draw. (" << aPoints << "-" << bPoints << ")" << endl;
          break;
      }
    }
    return 0;
}

bool weHaveAWinnder(int aPoints, int bPoints, string input){
    if((aPoints > bPoints + 1) && (aPoints >= 21))
    {
        cout << "Team A won! (" << aPoints << "-" << bPoints << ")" << endl;
        return false;
    }
    else if(bPoints > aPoints + 1 && bPoints >= 21)
    {
        cout << "Team B won! (" << aPoints << "-" << bPoints << ")" << endl;
        return false;
    }
    return true;
}

////Here I present another way to calculate the scores, unfortunately my assignment prefer the function is used within the loop
////this method is to first calculate all the score, instead of checking the individual total after every inputs
////This method also 100% pass the auto grading system

// while (true){
//
//   cin >> input;
//
//   if (((aPoints - bPoints == 2) && (aPoints >= 21)) || ((bPoints - aPoints == 2) && (bPoints >= 21))){
//
//     break;
//   } else {
//     // cout << "a - b: " << aPoints - bPoints << endl;
//     // cout << "b - a: " << bPoints - aPoints << endl;
//
//     if (input == "A"){
//       aPoints += 1;
//       // cout << "current a is: " << aPoints << endl;
//   }
//     else if ( input == "B"){
//       bPoints += 1;
//       // cout << "current b is: " << bPoints << endl;
//   }
//     else if (input == "end"){
//       break;
//   }
//
//   }
//
//
// }
// weHaveAWinnder(aPoints, bPoints);


// void weHaveAWinnder(int aPoints, int bPoints){
//   if (aPoints > bPoints){
//     cout << "Team A won! (" << aPoints << "-" << bPoints << ")" << endl;
//
//   }
//   else if (bPoints > aPoints){
//     cout << "Team B won! (" << aPoints << "-" << bPoints << ")" << endl;
//
//   }
//   else{
//     cout << "Game ended as a draw. (" << aPoints << "-" << bPoints << ")" << endl;
//   }
// }
