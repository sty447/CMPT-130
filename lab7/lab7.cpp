#include <iostream>

using namespace std;


bool isProperFactor(int num, int divisor);

int sumProperFactors(int n);

bool isPerfectNumber(int n);

void perfectNumOutput(bool perfect);

void perfectNumBetween(int lowerNum, int higherNum);

/* understanding 

    Q: Describe what your algorithm would look like if you implemented it without using
    functions. What is the advantage of using functions?

    A: every line of code in all the function will be in the int main function, using function make the code look neater,
    and also reduce the amount of memoery required to run the code.

    Q:What would happen if the function isProperFactor() displayed the answer
    instead of returned the answer? Would your program work

    A: it will not work beacuse other function calls in the isProperFactor function and requires an value being outputed by the isProperFactor function,
    therefore it would need to return an value instead printing it.

    Q:Inside sumProperFactor(), why is a for loop a good type of loop to use?

    A: it is a good loop to use beacuse we know for certain that when the loop will end and will not end up at a random number.

    Q:Why are the following two lines of code interchangeable? Which is better? Why?

    A: if (isProperFactor(n, i)) {...} is better, beacuse it is clearer to read and it is more concise than if (isProperFactor(n, i) == true) {...}



*/
int main(){


    
    int checkNum = 0;


    cout << endl;

    // check isproperfactor function
    cout << "3 proper factor of 6? " << isProperFactor(6, 3) << endl;
    cout << "4 proper factor of 6? " << isProperFactor(6, 4) << endl;
    cout << "1 proper factor of 6? " << isProperFactor(6, 1) << endl;
    cout << "6 proper factor of 6? " << isProperFactor(6, 6) << endl;

    cout << endl;

    // ask number
    cout << "Enter a number: ";
    cin >> checkNum;

    // find the sum of the factor of the number
    int sumOfFactor = sumProperFactors(checkNum);
    cout << "Sum of proper factors: " << sumOfFactor << endl;
    cout << endl;

    // check if it a perfect number 
    bool perfect = isPerfectNumber(checkNum);
    perfectNumOutput(perfect);

    cout << endl;
    cout << endl;

    // the perfect number between 
    perfectNumBetween(490,500);
    perfectNumBetween(1,10000);



    return 0;




}
// check if divisor is a factor of num
bool isProperFactor(int num, int divisor){

    if(divisor < num && num % divisor == 0){

        return true;

    }
    
    return false;

}
// taking the sum of all the factors
int sumProperFactors(int n){

    int sum = 0;

    for(int i = 1 ; i < n ; i++){

        bool factor = isProperFactor(n,i);
        if (factor){

            sum += i;

        }

    }

    return sum;


}
// checking if it a perfect number
bool isPerfectNumber(int n){

    if(sumProperFactors(n)==n){

        return true;
    }

    return false;

}
//output word depending if it's a perfect number
void perfectNumOutput(bool perfect){

    if(perfect){

        cout << "Amazing! It's perfect!";

    }
    else {

        cout <<"I'm sorry, that's not a perfect number.";
    }

}
// checking number between lower and higer num
void perfectNumBetween(int lowerNum, int higherNum){

    cout << "perfect numbers from "<< lowerNum <<" to " << higherNum;
    cout << endl;

    int numPerfect = 0;

    // adding the amount of factor in between the numbers 
    for(int i = lowerNum; i <= higherNum; i++){
        
        bool isPerfect = isPerfectNumber(i);
        
        if(isPerfect){

            // dispaling the perfect number
            cout <<"perfect number: "<< i;
            cout << endl;

            numPerfect += 1;

        }
    }

    // display the number of perfect numbers  
    cout << "total Number of perfect numbers from "<< lowerNum <<" to " << higherNum << " : "<< numPerfect << endl;
    cout << endl;

}

