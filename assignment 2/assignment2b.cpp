#include <iostream>
#include <iomanip>
using namespace std;



// constants
int const spacing = 4;
int const spacingForPrime = 3;
int const primeFactor = 2;








// starting statement 
void startingStatement(){

    cout << "Input two value between 1 and 200 that is an whole number"<< endl;

}

// while checking function for N2
int requestNumTwo(){
    
    // varibles
    int inputN2 = 0;
   

   // ask for input for second value 
    cout << "Second value: ";
    cin >> inputN2 ;

    //repeat till break loop
    while ( inputN2 < 1 || inputN2 > 200){

        cout << "Input two value between 1 and 200 that is an whole number" << endl ;
        cout << "please enter it again" << endl ;
        cout << "Second value: " ;
        cin >> inputN2;

    }

    return inputN2;

}

// first number
int requestNumOne(){

    // varible
    int inputN1 = 0;
   
    //ask for input for first value
    cout << "First value: ";
    cin >> inputN1;

    //repeat till break loop
    while ( inputN1 < 1 || inputN1 > 200){

        cout << "Input two value between 1 and 200 that is an whole number" << endl ;
        cout << "please enter it again" << endl ;
        cout << "First value: " ;
        cin >> inputN1;

    }
    
    return inputN1;


}




// finding the primefactor
void findPrimeFactors ( int startingVariable ){
    
    int nInital = startingVariable;
    int prime = 0;
   
   // Counting prime factors from startvariable to nInital

    while ( nInital >= 1 ) {
    
        if ( startingVariable % nInital == 0 ){
        
            cout << nInital << setw(spacing);
            
            prime ++;
        }
        
    nInital--;
        
    }

    // Display amount of prime factor

    cout << setw(spacingForPrime);

    cout << "(" << prime << ")"; 

    //Check whether nintial is prime or not (2)

    if ( prime == primeFactor ){
    
    cout << "  **PRIME** "; 
    
    } 
    cout << endl;

}

// find the smaller number and set that as the start
// find the larger number and set that as the end 
// run findprimefactor
void startAndFinish(int resultN1, int resultN2){

    int startingVarible = resultN1;
    int finishVarible  = resultN2;

    // if N1 is bigger than N2
    if(resultN1 > resultN2){
        
        startingVarible = resultN2;
        finishVarible = resultN1;


    }
    //printing number 
    while (startingVarible<= finishVarible){

        findPrimeFactors(startingVarible);
        startingVarible++;





    }

}







int main (){

    // request number
    startingStatement();

    // checking number 1 and 2
    int resultN1 = requestNumOne();
    int resultN2 = requestNumTwo();

    // spacing 
    cout << endl;

    //redisplay so it looks nicer
    cout <<"First value: "<< resultN1 << endl;
    cout <<"Second value: "<< resultN2 << endl;


    //run the and display prime factors
    startAndFinish( resultN1, resultN2);

    // spacing
    cout << endl;
    


    return 0; 





}