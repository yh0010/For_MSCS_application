#include <iostream>
using namespace std;

void sendEmail(string recipient, string prize, int status);

int main() {
    sendEmail("Shauna", "stuffed giraffe", 1);
    return 0;
}

void sendEmail(string recipient, string prize, int status){
    if( (recipient == "Shauna") || (recipient == "Jorge")) {
        cout << "Dear " << recipient << "," << endl;
        if (status == 1){
            cout << "You are the winner of our raffle for charity." << endl;
        }

        cout << "The prize was: a " << prize << endl;
        cout << "Thank you for giving to charity!" << endl;
        cout << "Sincerely," << endl;
        cout << "The Boolean Foundation" << endl;
        cout << endl;
    } else {
        cout << "Dear " << recipient << "," << endl;
        if (status == 0){
            cout << "We're sorry that you did not win our raffle for charity" << endl;
        }

        cout << "Thank you for your participation!" << endl;
        cout << "Sincerely," << endl;
        cout << "The Boolean Foundation" << endl;
        cout << endl;
    }
}
