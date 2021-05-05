#include <iostream>
#include <fstream>
#include <string>
#include <limits>
using namespace std;

class Customer {
  public:
      // Constructor
      Customer(string name="no name", string address="no address") : cust_name(name), cust_address(address)
      {
           acct_number = this->getNextAcctNumber();
      }

      // Accessor to get the account number
      const int getAcctNumber() { return acct_number; }

      // Accessor to get the customer name
      string getCustName() const { return cust_name; }

      // Accessor to get the customer  address
      string getCustAddress() const { return cust_address; }

      // Set a customer name and address
      void set(string name, string address);

      // Set a customer address
      void setAddress(string cust_address) {  this->cust_address = cust_address; }

      // Get the next account number for the next customer.
      static const unsigned long getNextAcctNumber() { return ++nextAcctNum; }

      // input operator
      friend Customer operator>> (istream& ins, Customer& cust);

      // output operator
      friend void operator<< ( ostream& outs, Customer &cust);

  private:
      string cust_name;                           // customer name

      unsigned long acct_number;                  // account number

      string cust_address;                        // customer address

      static unsigned long nextAcctNum;
};

const int MAX_CUSTOMERS=20; // Change this to a smaller number to test. 20

// Declare the class variable nextAcctNum
unsigned long Customer::nextAcctNum=10000;

// set the customer name and address
// @param name: the customer name
// @param address: the account address
void Customer::set(string name, string address)
{
    cust_name = name;
    cust_address= address;
}

// input operator reads customer as a name and address on two separate lines.
// name
// address1
Customer operator>>(istream& ins, Customer& cust)
{
     getline(ins, cust.cust_name, '\n');
     //ins.clear();
     getline(ins, cust.cust_address, '\n');
     return cust;
}

// output operator
void operator<<( ostream& out, Customer& cust)
{
     out << cust.acct_number << ": " << cust.cust_name << "\n" << cust.cust_address << endl;
}

int main()
{
    Customer custList[MAX_CUSTOMERS];
    ifstream infile;
    string filename;

    cout << "Enter the name of the file for input: ";
    cin >> filename;

    infile.open(filename);
    if (infile.fail()) {
        cout << "Error: failed to open file: " << filename;
        exit(1);
    }
    // cout << "open file\n";
    // infile.open("u.txt");

    // Read in customer list.
    int size = 0;
    while (size < MAX_CUSTOMERS) {
      operator>>(infile, custList[size]);
      //operator<<(cout, custList[size]);
      if (++size == MAX_CUSTOMERS)
            break;
    }

    //Get customer address changes
    string input;
    for (int i = 0;  i < MAX_CUSTOMERS; i++)
    {
        char answer;
        cout << "Address change for " << custList[i].getAcctNumber()<< "? (y or n) : ";
        cin >> answer;
        if (answer == 'y') {
            cin.ignore();  // newline
            getline(cin, input);
            custList[i].setAddress(input);
            break;
          }else{
            cin.clear();
            cin.ignore(numeric_limits<streamsize>::max(), '\n');}
    }

    // Write out customer list.
    for (int i = 0; i < MAX_CUSTOMERS; i++)
    {
      if (custList[i].getCustAddress() != "no address")
        cout << custList[i];
        //operator<<(cout, custList[i]);

    }


    return 0;
}
