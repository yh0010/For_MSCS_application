#include <iostream>
using namespace std;
//purpose:
//Valid customer A, B and C, each starts with 0 points.
//Every purchase >= 10 will add 1 point.
////I might adjust it later, for any total purchase is divisible by 10x will add x point(s)
////I might adjust it later, for any purchase that's divisible by 10x will add x point(s)
//If 'N' appear then break the loop

int updateLoyaltyCard(int points, float purchase, char customer);
//function takes in a cumulated points of each customer, then evaluate the purchase and assign to the Customer


int main() {

   char customer;
   float purchase = 0;
   int A = 0, B = 0, C = 0;

   while (true){
     cout << "Customer: ";
     cin >> customer;

     if (customer != 'N'){
       cout << "Purchase: ";
       cin >> purchase;

     if (customer == 'A'){
       A = updateLoyaltyCard(A, purchase, customer);
     }
     else if (customer == 'B'){
       B = updateLoyaltyCard(B, purchase, customer);
     }
     else if (customer == 'C'){
       C = updateLoyaltyCard(C, purchase, customer);
     }
     }
     else {break;}
     }
    return 0;
}
int updateLoyaltyCard(int points, float purchase, char customer){

  if (purchase >= 10){
    points += 1;
    cout << customer << " now has " << points << " loyalty points." << endl;}
  else {cout << customer << " now has " << points << " loyalty points." << endl;}
  return points;
}
