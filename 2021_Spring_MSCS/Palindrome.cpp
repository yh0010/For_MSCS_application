/*
 * pallindrome: checks a string to see if it is a pallindrome.
 *
 *  Examples:
 *
 *  Able was I 'ere I saw Elba.
 *  Madam, I'm Adam.
 *  A man, a plan, a canal, Panama.
 *  Racecar
 *
 *  First, create a clean version of the string.
 *  	- convert all characters to lower case.
 *  	- remove all punctuation.
 *
 *  Second, create a reverse version of the string.
 *   - use reverse and swap from our lab assignment
 *   so first make a copy of the string and pass in
 *   the copy to reverse.
 *
 *  Third
 *  	- compare the two strings
 *  		if they are the same, palindrome.
 *  		else, not palindrome.
 */
#include <iostream>
#include <vector>
#include <algorithm>
#include <cctype>
#include <stdio.h>
#include <ctype.h>
// ToDo: Add include files.
using namespace std;


string removePunct(string str);
// Function: removePunct
// Precondition: a string that may or may not have punctuation.
// Postcondition: returns a (possibly shorter) string with punctuaton
// removed.

string convertToLower(string str);
// Precondition: a string that may have mixed case in it.
// Postcondition: returns a lowercase string

string reverse(string &str);
// Precondition: a string to be reversed
// Postcondition: returns a string that is the
// reverse of the input string.

void display(vector<string> vstrings);
// Precondition: a vector of strings to print
// Postcondition: strings are printed one per line.

bool isPalindrome(string str);
// Precondition: a string to be tested
// Postcondition: returns a bool that is true if the input is a palindrome
// returns false otherwise.

int main() {
  vector<string> palindromes;
  vector<string> not_palindromes;
  string word, word2;
   // ToDo: Declare two vectors of strings to save the input strings: palindromes,
   // not_palindromes.

   do{
     cout << "Enter your palindrome or type quit: "<<endl;
     getline(cin, word);
     //cout  << " first word: " << word <<endl;
     if (word.find("quit") == 0){break;}
     //else{
     else if (isPalindrome(word)){
       // word2 = removePunct(word);
       // cout << "upper remove: " << word2 <<endl;
       // word2 = convertToLower(word2);
       // //reverse(word.begin(), word.end()); //a quicker way to reverse
       // word2 = reverse(word2);

       palindromes.push_back(word);
       //cout << palindromes[0];
     }
     else {
       not_palindromes.push_back(word);
       //cout << not_palindromes[0];
     }
   } while (true);
    //cout << palindromes.size() << endl;
   //  cout <<
   //  for (int i=0; i<palindromes.size();i++){
   //   cout << palindromes[i] <<endl;
   // }
   cout << "Palindromes:" << endl;
   display(palindromes);

   cout << "NOT Palindromes:" << endl;
   display(not_palindromes);

   // ToDo: Implement a loop to read in the palindrome strings using getline until
   // the user quits. The user will enter the word "quit" to exit the loop.


   // ToDo: In the loop, call the isPalindrome function on the input string and
   // store it in the palindromes vector if true and the notPalindromes vector if
   // false.

   // ToDo: After exiting the loop, print the list of palindromes under a Palindrome
   // heading and the list that are not palindromes under a Not Palindrome heading.
   // The display function should print a tab character before printing the string.

	return 0;
}

string removePunct(string str){
  str.erase(std::remove_if(str.begin(), str.end(), ::isblank), str.end()); //something weird happened here

  str.erase(std::remove_if(str.begin(), str.end(), ::ispunct), str.end());
  return str;
}

string convertToLower(string str){
  int i=0;
  while(str[i])
  {
    str[i] = tolower(str[i]);
    //putchar(tolower(str[i])); //putchar is an amazing function but it prints automatically so i cannot use it in here
    i++;
  }
  return str;
}
void swap(int a, int b){
  int temp = a;
  a = b;
  b = temp;
}
string reverse(string &str){
  int n = str.length();
  for (int i = 0; i < n / 2; i++) {
    swap(str[i], str[n - i - 1]);
  }
  return str;
}

bool isPalindrome(string str){
  string word2, word3;
  word2 = removePunct(str);

  word2 = convertToLower(word2);

  word3 = word2;
  //reverse(word.begin(), word.end()); //a quicker way to reverse
  word2 = reverse(word2);
  // cout << "word3: " << word3 << endl;
  // cout << "word2: " << word2 << endl;

  if (word3 == word2){ return true;}
  else{ return false;}

}

void display(vector<string> vstrings){
  for (auto i : vstrings){
    cout << '\t' << i << endl;
  }
}
