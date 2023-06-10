#include <iostream>
using namespace std;


// fuction welcome messsage
void displayWelcome(){

    cout << "Hello and welcome to the lab on functions" << endl;
}


// fucnction diplay even, sum and factorial 
void runLoopPart (int entN, int sumN, int sumAll, int productF, int productN){


    // display even numbers
    cout << "Entered N" << endl;
    cout << "All even numbers ";
    
    while( entN >= 0){

        if (entN % 2 == 0){

            cout << entN << ",";

        }
        
        entN -- ;
          
    }
    cout << endl;

    cout << "Sum 0. ." << sumAll << " = " ;

    while( sumAll >= 0){

        sumN = sumN + sumAll ;
        sumAll -- ;
            
    }
    
    cout << sumN << endl ;
    
    // product 
    cout << "Product 1. ." << productN << " = ";

    while (0 < productN){

        productF = productF * productN;
        productN -- ;

    }
    cout << productF << endl << endl ;

    // q7 answer because it over flow the 32bit system


}


int getSumOfSquaresUpToN (int entN){


    int sum = 0; 
    int value = 1;
    while (value <= entN ) {
        
        sum += (value * value);
        value ++; 

    }
   

    return sum;





}

void displaySumOfSquaresUptoN(int entN){

    int resultS = getSumOfSquaresUpToN(entN);
    cout << "Sum of squares ";
    cout << "1 .. " << entN << " = " << resultS ;
    cout << endl;

}

// print star
void printNumOfStarsToSumOfSquares (int sumS){

    
    int star = 1;
    while (star <= sumS){
        cout <<"*";
        star++;
    }

   
}
// requesting fav number
void requestInpt(){

    cout << "Enter favorite number: " ;

}

int main (){

    //part 1
    // request number 
    //int entN = 0;
    //cout << "Enter an interger " << endl;
    //cin >> entN;

    //int sumN = 0;
    //int sumAll = entN;
    //int productF = 1;
    //int productN = entN;
    //runLoopPart(ent,sumN,sumAll,productF,productN);

    displayWelcome();
    displayWelcome();
    requestInpt();
    int favN = 0;
    cin >> favN;


    displaySumOfSquaresUptoN(favN);

    int sum = getSumOfSquaresUpToN(favN);
    cout << "Returned sum of squares is: " << sum << endl;

    printNumOfStarsToSumOfSquares ( sum );


    

    // q9 
    // 1 answer return value can be resused, dispalying the value can't be reuse 
    // 2 getSumOfSquaresUpToN can used for the star fuction, becasue it can be use to reduce the amount of code needed
    // 3 yes



   
    

    


}