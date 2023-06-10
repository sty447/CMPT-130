 // Program using global variables.
// TASK: Convert all global variables into local variables.
//       You may change the parameters to functions as needed.
#include <iostream>
#include <iomanip>

using namespace std;

// *******************************************
// Global constants (these are fine!).
// *******************************************
const double MAX_HEIGHT = 8.0;
const double MIN_HEIGHT = 1.0;

// *******************************************
// Global variables to get rid of.
// *******************************************


//fuction prototype
double readHeight();
void printCustomerInfo(int customerAge, int customerHeight) ;
bool askToDoAnother();




// Ask for a customer's info, and display it to the screen.
int main() {

    bool keepReading = 1;
    int customerAge = 0;
    
    while (keepReading) {
        // Read in the customer info:
        // ... Read the height
        double customerHeight = readHeight();

        // ... Read Age
        cout << "Enter their age: ";
        cin >> customerAge;

        // Display a summary:
        printCustomerInfo(customerAge,customerHeight);

        // Do another?
        keepReading = askToDoAnother();
    }

    return 0;
}

// understanding 
//Q: What is the advantage of removing global variables?
//A: you can reuse the name of the varible 

//Q: Did you have any functions which accept no parameters? Which one(s)? What does
//   this tell you about how the data flows into/out-of the function?
//A: yes askToDoAnother and readHeight doesn't have a parameter, it ouput data indenpently without requiring extental varibable to depend on

//Q: Did you have any functions which accepted multiple parameters? Which one(s)? What
//   does this tell you about how the data flows into/out-of the function?
//A: yes printCustomerInfo had multiple parameteres, its output is depended on the parameteres(input)

//Q: What technique did you use when a function was writing to a global variable?
//A: I initalize the variable to the function within int main

// *******************************************
// Functions
// *******************************************

// Read in the user's height
double readHeight() {
    double customerHeight = 0;
    cout << "Enter customer height (feet): ";
    cin >> customerHeight;

    while (customerHeight > MAX_HEIGHT || customerHeight < MIN_HEIGHT) {
        cout << fixed << setprecision(1);
        cout << "ERROR: Height must be between " << MIN_HEIGHT
             << " and " << MAX_HEIGHT << " feet.\n";
        cout << "Enter customer height (feet): ";
        cin >> customerHeight;
    }

    return customerHeight;
}

// Print the customer's info to the screen.
void printCustomerInfo(int customerAge, int customerHeight) {
    
    
    cout << fixed << setprecision(1);
    cout << "\n";
    cout << "Customer summary: \n";
    cout << "\tHeight: " << customerHeight << " feet\n";
    cout << "\tAge:    " << customerAge << endl;
    cout << "\n";
}

// Ask the user if they want to enter more data.
bool askToDoAnother() {
    char choice = ' ';
    // Read in the user's selection
    cout << "Enter another customer? (Y/N) ";
    cin >> choice;
    return (choice == 'Y' || choice == 'y');
}
