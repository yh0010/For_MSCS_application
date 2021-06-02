#include <iostream>
#include <string>
#include <cctype>
#include <vector>
using namespace std;
/*
Hi Professor Hernandez..I'm very tired so I cannot add every precondition+postcondition comment in here
basically what this program does is that it uses 2-D array as the base for tic tac toe Game
program also checks if the user input is overlapping or did not input correct number
if any 3 cells is the same marker, then the program declares user with such a marker wins

program uses a vector to store unique input values, if the vector size reaches 9, which is the max capacity of this game, then program declares the tie result
I hope this program satisfies the extra credit requirment, thanks and have a good night
*/

class TicTacToe{
private:
  string tictactoe[3][3];
  string player;
  vector<int> entryRecord;
public:
  TicTacToe(){
    player = "X";
    int pos=1;
    for (int i=0; i<3; i++){
      for (int j=0; j<3; j++){
        tictactoe[i][j] = to_string(pos);
        pos++;
      }
    }
  };

  friend ostream& operator <<(ostream& outs, TicTacToe obj){
    for (int i=0; i<3; i++)
      {
      outs<< endl;
      for (int j=0; j<3; j++)
        {outs << " | " << obj.tictactoe[i][j] ;}
      outs << " | \n";
      outs << endl;
      }
      return outs;
  };

  string RecordLocation(int loc){
    string comment = "empty";
    if (loc == 1&&tictactoe[0][0]=="1"){
      tictactoe[0][0] = player;
      return player;
    }
    else if (loc == 2&&tictactoe[0][1]=="2"){
      tictactoe[0][1] = player;
      return player;
    }
    else if (loc == 3&&tictactoe[0][2]=="3"){
      tictactoe[0][2] = player;
      return player;
    }
    else if (loc == 4&&tictactoe[1][0]=="4"){
      tictactoe[1][0] = player;
      return player;
    }
    else if (loc == 5&&tictactoe[1][1]=="5"){
      tictactoe[1][1] = player;
      return player;
    }
    else if (loc == 6&&tictactoe[1][2]=="6"){
      tictactoe[1][2] = player;
      return player;
    }
    else if (loc == 7&&tictactoe[2][0]=="7"){
      tictactoe[2][0] = player;
      return player;
    }
    else if (loc == 8&&tictactoe[2][1]=="8"){
      tictactoe[2][1] = player;
      return player;
    }
    else if (loc == 9&&tictactoe[2][2]=="9"){
      tictactoe[2][2] = player;
      return player;
    }
    else {
      if (loc >= 1){
        cout<< endl;
        comment = "This location is pre-occupied, please re-enter.\n";
        cout << comment;
        return comment;
      }
      return comment;
    }
  };

  void SwitchPlayer(){
    if (player == "X"){
      player = "O";
    }
    else {player = "X";}
  };

  bool CheckWinner(){
    if (tictactoe[0][0]==player && tictactoe[0][1]==player && tictactoe[0][2]==player){
      cout << endl;
      cout << "Player " << player << " wins the game!\n";
      return true;
    }
    if (tictactoe[1][0]==player && tictactoe[1][1]==player && tictactoe[1][2]==player){
      cout << endl;
      cout << "Player " << player << " wins the game!\n";
      return true;
    }
    if (tictactoe[2][0]==player && tictactoe[2][1]==player && tictactoe[2][2]==player){
      cout << endl;
      cout << "Player " << player << " wins the game!\n";
      return true;
    }
    if (tictactoe[0][0]==player && tictactoe[1][0]==player && tictactoe[2][0]==player){
      cout << endl;
      cout << "Player " << player << " wins the game!\n";
      return true;
    }
    if (tictactoe[0][1]==player && tictactoe[1][1]==player && tictactoe[2][1]==player){
      cout << endl;
      cout << "Player " << player << " wins the game!\n";
      return true;
    }
    if (tictactoe[0][2]==player && tictactoe[1][2]==player && tictactoe[2][2]==player){
      cout << endl;
      cout << "Player " << player << " wins the game!\n";
      return true;
    }
    if (tictactoe[0][0]==player && tictactoe[1][1]==player && tictactoe[2][2]==player){
      cout << endl;
      cout << "Player " << player << " wins the game!\n";
      return true;
    }
    if (tictactoe[0][2]==player && tictactoe[1][1]==player && tictactoe[2][0]==player){
      cout << endl;
      cout << "Player " << player << " wins the game!\n";
      return true;
    }
    else {
      cout << endl;
      cout << "Game continues...\n";
      return false;
    }
  };

  bool IfTie(int location){
    for (int i=0; i<entryRecord.size(); i++){
      if (location == entryRecord[i]){
        return false;
      }
    }

    entryRecord.push_back(location);
    if (entryRecord.size()==9){
      cout << "It's a tie.\n";
      return true;
    }
    return false;
  };

};


int main(){

  TicTacToe obj;
  int location=0;
  bool winStatus=false;

  cout<< endl;
  cout << "Welcome to the Tic Tac Toe game!\n";
  cout << obj;
  while(winStatus==false){
  cout << "Please enter location number to continue:";

  cin >> location;
  if (cin.fail()||location >9 || location <=0){
    cout << endl;
    cout << "Warning: Invalid input. Please re-enter.\n";
    cin.clear();
    cin.ignore();
    location = 0;
  }

  string comment = obj.RecordLocation(location);
  cout << obj;
  winStatus = obj.IfTie(location);
  winStatus = obj.CheckWinner();

  if (comment.length() == 1){  obj.SwitchPlayer();}

}
  return 0;
}
