// Exercise: Make this piece of code use functions!
#include <iostream>
#include <iomanip>
#include <ctime>
using namespace std;

const int MAX_VAL_IN_TABLE = 20;
const int DISPLAY_WIDTH = 10;
const int DISPLAY_WIDTH_WIDE = 14;


// // set w 
// // making this function reduce the amount of time need to rewrite the same lines of code
// THIS FUNCTION IS NOT NEED FOR THE LAB AND ALSO NEED TUNING SO PLEASE IGNORE THE COMMENTED OUT FUNCTION
// void setwFunction(string one , string two ,string three ,string four,string five ,string six){
    
//     cout << setw(DISPLAY_WIDTH) << one
//          << setw(DISPLAY_WIDTH) << two
//          << setw(DISPLAY_WIDTH) << three
//          << setw(DISPLAY_WIDTH) << four
//          << setw(DISPLAY_WIDTH) << five
//          << setw(DISPLAY_WIDTH_WIDE) << six
//          << endl;
// }


// Calculate sum 1..n
int calculateSum(int n){

    int sum1toN = 0;
    int i = 0;
    while (i <= n) {
        sum1toN += i;
        i++;
    }

    return sum1toN;


}

// Calculate 2^n (without using pow())
int calculate2PowerN(int n){
    
    int twoToTheN = 1;
    int j = 1;
    while (j <= n) {
        twoToTheN *= 2;
        j++;
    }
    
    return twoToTheN;

}

//Calcuate N squared
int calculateNsquared(int n){

    int nSquard = n*n ;

    return nSquard;

}

// Calculate mock exam score out of 100
int scoreOfMockE(){
    
    int score = rand() % 100;

    return score;


}

// Calculate 1/(n^2)
// this is a double because you went the return value to be a double 
double oneOverNSquaredFunction(int n){
    
    double oneOverNSquared = 1.0 / (n * n);
    
    return oneOverNSquared;

}
// generate tables
void generateTable(){
    
    // interger value n (here is 1 can be changed) 
    int n = 1;

    while (n <= MAX_VAL_IN_TABLE) {
        

        // call functions and set the functions return value as a new value 
        int twoToTheN = calculate2PowerN(n);
        // double because it has decimal places
        double oneOverNSquared = oneOverNSquaredFunction(n);
        int nSquared = calculateNsquared(n);
        int score = scoreOfMockE();
        int sum1toN = calculateSum(n);





        

        // Display the values.
        cout << setw(DISPLAY_WIDTH) << n
                << setw(DISPLAY_WIDTH) << nSquared
                << setw(DISPLAY_WIDTH) << sum1toN
                << setw(DISPLAY_WIDTH) << twoToTheN
                << setw(DISPLAY_WIDTH) << score
                << setw(DISPLAY_WIDTH_WIDE) << oneOverNSquared
                << endl;
        n++;
    }
}













int main()
{
    // // "Simple" Bug
    // cout << "Enter a number: ";
    // int x = 0;
    // cin >> x;
    // if (x == 42) {
    //     cout << "Great choice!" << endl;
    // }

    // Randomize
    srand(time(nullptr));
    
    // to make it look nicer
    cout << endl; 

    // Output headings:
    cout << setw(DISPLAY_WIDTH) << "n"
         << setw(DISPLAY_WIDTH) << "n^2"
         << setw(DISPLAY_WIDTH) << "1..n"
         << setw(DISPLAY_WIDTH) << "2^n" 
         << setw(DISPLAY_WIDTH) << "Score" 
         << setw(DISPLAY_WIDTH_WIDE) << "1/(n^2)" 
         << endl;
    cout << setw(DISPLAY_WIDTH) << "---"
         << setw(DISPLAY_WIDTH) << "----"
         << setw(DISPLAY_WIDTH) << "-----"
         << setw(DISPLAY_WIDTH) << "--------"
         << setw(DISPLAY_WIDTH) << "--------"
         << setw(DISPLAY_WIDTH_WIDE) << "--------"
         << endl;

    // call the function
    generateTable();

    // to make it look nicer

    cout << endl;


    return 0;
}