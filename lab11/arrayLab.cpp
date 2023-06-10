#include <iostream>
#include <iomanip>

using namespace std;

void displayArray(int arr[], int size);

void populateSequence(int arr[], int size, int start, int gap);

int minValue(int arr[], int size);

bool hasNegative(double *arr, int size);

void zeroDissimilarPrefix(int *pA, int *pB);

void testZeroPrefix(int a, int b);

const int NUM_DIGITS = 10;

const int SPACEING =8;

/*
    Q:Most functions use a return value to pass back information. However,
    populateSequence() has a void return type, yet it is able to give the calling code
    (in this case main()) some values in the array. Explain how this happens. Why can
    this function use the void return type?

    A:populate tell the array the value it contains and the array remember
    it so if the array is call it will give the value it's stored, therefore not need for a return type


    Q:For the minValue() function, why start the “smallest” variable at arr[0] instead
    of the number 0?

    A: because zero might not be a value in the array

    ◦ What happens in your program when there are multiple values which have the same
    minimum value? Does this cause a problem? Why or why not?

    A:nothing happen it stiil display the lowest, this becasue not matter what it will 
    always display the lowest value so if the lowest is the same it doesn't matter

    ◦ Explain why the minValue() function has a return type instead of using the same
    method to pass back information as populateSequence().

    A:because you want the one of the lowst value in array and  not the array

    ◦ Explain what the output (to the screen) of the following code is:
    int arr[] = {10, 20, 0};
    minValue(arr, 3);

    A: take array check for the lowest value one by one 
    if a new lowest value occur, change the output of the min value to that 
    and becasue it is't printed nothing display on the screen

    ▪ Explain what changes are needed to display the answer it computes to the screen.

    A: print it so cout << minValue(arr, 3);

    ▪ Why is it better to have the function return a value, rather than directly print the
    value to the screen?

    A: the coder can use the value later for something else

    What two ways (syntax) can an array be passed to a function? i.e., if you want to pass
    an array to a function, which are the two ways you can write the function? (Think
    about pointers).


    A: using pointer and/ or the array it self, see populateSequence for using the array 
    and see hasNegative for using a pointer 

*/



int main(){

    // // test diplay function
    // int arr0[] = {42, 0, 1, 101, 58};
    // displayArray(arr0, 5);

    // cout << endl;

    // //test populate array function
    // int arr1[4];
    // populateSequence(arr1, 4, 7, 2);
    // displayArray(arr1, 4);

    // cout << endl;

    // //test populate array function
    // int arr2[3];
    // populateSequence(arr2, 3, 2, -3);
    // displayArray(arr2, 3);

    // cout << endl;

    // find min
    // int arr3[] = {17, 3, 12, 11, 4};
    // int val1 = minValue(arr3, 5);
    // cout << "Min1: " << val1 << "\n";

    //find min
    // int arr4[] = {1, 0, 7, 23, 2, -1};
    // cout << "Min2: " << minValue(arr4, 6) << "\n";

    // test two same lowest value if it matter(it doesn't)
    // int arr5[] = {-1, 0, 7, 23, 2, -1};
    // cout << "Min2: " << minValue(arr5, 6) << "\n";

    cout << endl;

    double arr1[] = {2, 5.2, 6, 8, 6, 10, 325532, 0};
    cout << "Has negative #1?: " << hasNegative(arr1, 8) << endl;

    double arr2[] = {2, 7.2, 0.1, -2, 5};
    cout << "Has negative #2?: " << hasNegative(arr2, 5) << endl;

    double arr3[] = {-1, -5, -153};
    cout << "Has negative #3?: " << hasNegative(arr3, 3) << endl;

    cout << endl;

    testZeroPrefix(123456789, 122456789);

    cout << endl;


    return 0;




}

//display the value in the array
void displayArray(int arr[], int size){

    for(int i = 0;i<size; i++){

        cout << arr[i];
        cout << endl;
    }


}

// add vallue to the array
void populateSequence(int arr[], int size, int start, int gap){

    int value = 0;
    int current = 0;
    for( int i =0; i < size; i++){
        
        current = i*gap;
        value = start + current;
        arr[i] = value;

    }

}

// find the lowest value in the array
int minValue(int arr[], int size){

    int currentLow = arr[0];
    int testValue = 0;

    for(int i = 0; i < size; i++){

        testValue = arr[i];

        if(testValue < currentLow){

            currentLow = testValue;
        }

    }

    return currentLow;

}
//check for negative number
bool hasNegative(double *arr, int size){

    bool has = false;
    int current;

    for(int i = 0; i < size; i++){

        current = arr[i];

        if(current < 0){

            has = true;
        }

    }

    return has;

}

// find the similar Prefix
void zeroDissimilarPrefix(int *pA, int *pB){
  
  //power of 10
  int currentPow = NUM_DIGITS; 
  int current1; 
  int current2;
  
  // number to change pa and pb
  int matchVal = 0;

    while(true){

        // take remainder
        current1 = *pA % currentPow;
        current2 = *pB % currentPow;

        //check if match
        if (current1 == current2){  
            matchVal = current1;
            currentPow = currentPow*NUM_DIGITS;
        }
        // if not match return the last number that did match and exit loop
        else{
            *pA = matchVal;
            *pB = matchVal;
            break;
        }
    }

}
//testing the prefix
void testZeroPrefix(int a, int b)
{
    cout << "Test on " << setw(NUM_DIGITS) << a
         << " and " << setw(NUM_DIGITS) << b << endl;
    zeroDissimilarPrefix(&a, &b);
    cout << setw(SPACEING) << " = " << setw(NUM_DIGITS) << a
    << " and " << setw(NUM_DIGITS) << b << endl;
}

