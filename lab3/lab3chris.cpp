#include <iostream>

using namespace std;

void displayWelcome()
{
    cout << "Hello and welcome to Lab functions! " << endl;
    cout << "Hello and welcome to Lab functions! " << endl;
    cout << endl;
}

void runLoopPart(int userNum, int i, int j, int k)
{
    // All Even numbers

    cout << "All Even Numbers " << userNum << ". ."
         << "0 = ";

    while (i >= 0)
    {
        if (i % 2 == 0)
        {
            cout << i << ", ";
        }
        i--;
    }

    cout << endl;

    // Sum from stuff to stuff (lol)

    cout << "Sum 0 . ." << j << "= ";

    int sumOfAllNumbers = 0;

    while (j >= 0)
    {
        sumOfAllNumbers = sumOfAllNumbers + j;

        j--;
    }
    cout << sumOfAllNumbers << endl;

    // Product Calculator

    cout << "Product "
         << "1"
         << ". ." << k << " = ";

    int totalProduct = 1;
    while (0 < k)
    {

        totalProduct = totalProduct * k;

        k--;
    }
    cout << totalProduct << endl;
}

// Return S of Square Values
int getSumOfSquaresUpToN(int userNum)
{
     int sum = 0; 
    for (int i = 1; i <= userNum; i++) 
        sum += (i * i); 

    return sum;
}

// Display S of Squares Values
void displaySumOfSquaresUptoN(int userNum)
{
  
  int sum = getSumOfSquaresUpToN( userNum );

    cout << "Sum of squares"
         << "1 .." << userNum << " = " << sum <<
        endl;
}


// Printing out stars 
void printNumOfStarsToSumOfSquares (int sum)
{
    int i = 1;
    while (i <= sum){
        cout <<"*";
        i++;
    }
}


int main()
{

    // Display Welcome Header

    displayWelcome();

    // User Input

    cout << " Enter N: ";

    int userNum = 0;
    cin >> userNum;
    cout << endl;

    // Creating a new set of variables to hold values

    int i = userNum;
    int j = userNum;
    int k = userNum;

    runLoopPart(userNum, i, j, k);

    displaySumOfSquaresUptoN(userNum);

    int sum = getSumOfSquaresUpToN(userNum);
    cout << "Returned sum of squares is: " << sum << endl;

    printNumOfStarsToSumOfSquares (sum);



}