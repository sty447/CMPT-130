//Stanley Yang #301429346
//Christopher Yee #301411599


#include <iostream>
#include <iomanip>
#include<string>
using namespace std;



// convert binary to decimal
int binaryToDecimal (string n)
{
  for (char i : n)
    {
        if (!isdigit(i))
        {
            return -1;
        }
    }

  string num = n;

    int dec_value = 0;
    int base = 1; // start at base value  
    int len = num.length(); // get length of string for loop

    for (int i = len - 1; i >= 0; i--)
    { 
        if (num[i] == '1')
        {
            dec_value += base;
        }    
        base = base * 2;
    }
  
    return dec_value;
}

// convert decimal and binary
string decimaltoBinary( int n)
{
  
  string j; 
  if (n < 0)
  {
    return j; // return empty string 
  }
    while(n!=0)
    { 
     j=(n%2==0 ?"0":"1")+j; // Conditional operator 
     n/=2;                  
    }
    
    return j;
  //https://stackoverflow.com/questions/22746429/c-decimal-to-binary-converting
}


// checking 
bool sorted(int *arr,int size )
{ 
  bool isSorted =true;
  for (int i = 0 ; i < size; i++)
  {
    if(i != size)
    {
      if(arr[i] > arr[i+1])
      {
        isSorted = false;
      }
    }
    else if(i != size)
    {
      if (arr[i] < arr[i - 1])
            {
               isSorted = false;
            }
    }
  }
  return isSorted;
}

//print arr in row
void printRow (double *arr, int size, int columns, int width, int decimalPlaces){
  
  // to prevent it from printing extra number off the for loop 
  int counter = 0;

  for (int i = 0; i < size; i++){
    
    for(int j = 0; j < columns; j++){

      if( counter < size){ 

        cout << fixed << setprecision(1) << setw(width) << arr[i+j];

      } 
      counter++; 
    }

    i++;
    cout << endl;
    
  }

}

// print the columns
void printColumns (double *arr, int size, int columns, int width, int decimalPlaces)
{
  cout << fixed << setprecision(decimalPlaces);

    for(int j = 0; j < columns; j++)
    {
       for( int i = 0; i < size; i++)
       {
          if(i % columns ==j)
          {
            cout << setw(width) << arr[i];
          }
       }
    cout << endl;
  }
}

// find largest sum in the array
int maximumBenefit(int *arr, int size){

  int current = 0;
  int currentTop = 0;


    //run comparasion of the combination 
    for (int i = 0; i < size; i++) 
    {
        for (int b = size; b > i; b--)
        {
            current = 0;
            if (b == i)
            {
                current = arr[i];
            }
            else if (b > i)
            {
                for (int j = i; j < b; j++)
                {
                    current += arr[j];
                    
                }
            }

            if (current > currentTop)
            {
                currentTop = current;
            }
        }


    }
    // for edge case where all element of the array is all negative we can only tell that to the user in main function so
    // we assume that the user will always give aleast one postive value in the array

    return currentTop;

}

