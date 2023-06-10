#include <iostream>
#include <vector>
#include <fstream>
#include <iomanip>
#include <ctime>
#include <cstdlib>
#include <algorithm>




using namespace std;

const int fiveZero= 50;
const int sev = 7;
const int tw = 2;
const int thr = 3;
const int oneHun = 100;
const int fiv = 5;
const int ten = 10;
const int oneth= 1000;


vector<int> readNumbersFromFile(string fileName);

vector<int> makeSequence(int size);

int countMatchesLinearly(vector<int> data1, vector<int> data2);

void count50(vector<int> toBePrinted);

int countMatchesBinarySearch(vector<int> data1, vector<int> data2);
/*
 understanding 

 Q What is one similarity between reading from a file and reading from cin?

 A both insert value into a variable 

 Q What are two important differences between reading from a file and reading from
  cin?
 
 A file is extracting value from a file, while cin extract value from user and they are two different library

 Q Explain why the first few calls are so fast, but it seems to slow down later?

 A becasue there more value to compare when there is more elements.
 
 Q Does the time it takes to search for the values change linearly with the size of the input
 sequence? (i.e., if you double the size of the input sequence, does the time double?)

 A no, it scale exponentially.
 
 Q Analyze your results: did the binary search version find exactly the same number of
 matches as the linear search version? (If not, go fix your implementation!)
 
 A yes

 Q Analyze your results: describe the time needed with binary search (you do not need to
 understand the algorithm, just the timing results you see).

 A it take less time
 
 Q Can you find how big the sequence needs to be for it to take at least a couple seconds
 to complete all the matches? For this size, can you guess approximately how long
 linear search would take?

 A i imagine it will be anumber bigger than 100,000 and the linear search will be exponentially large than the value





*/
int main(){

    //new vector
    vector<int> numFile;
    

    // store value from text file
    numFile = readNumbersFromFile("numbers.txt");
    
    //display 50
    //count50(numFile);



 

    vector<int> sequence;
    
    //new order with inveral of 3 
    sequence= makeSequence(oneHun);

    
   
    //display 50
    //count50(sequence);

    // result of linear 
    int timeBefore = time(nullptr);
    int match = countMatchesLinearly(sequence,numFile);
    int timeTaken = time(nullptr) - timeBefore;

    cout << endl;
    cout << "linear search reult: " << match;
    cout << endl;
    cout << "time took: " << timeTaken << " s";
    cout << endl;

    timeBefore = time(nullptr);
    int num = countMatchesBinarySearch(sequence,numFile);
    timeTaken = time(nullptr) - timeBefore;

    cout << "binary search reult: " << num;
    cout << endl;
    cout << "time took: " << timeTaken << " s";
    cout << endl;
    cout << endl;
    




    return 0;
}

//print first 50 num
void count50(vector<int> toBePrinted){

    //display first 50
    for(int i = 0;i < fiveZero; i++){

        // so it start from 1 even tho the vector start from 0
        cout << setw(tw) << i+1;
        cout << setw(sev) << toBePrinted.at(i);
        cout << endl;
    
    }


}

// extract num from text file
vector<int> readNumbersFromFile(string fileName)
{
    // Open file
    ifstream file(fileName);
    if (file.fail()) {
        cout << "ERROR: Unable to open input file '" << fileName << "' (does not exist?)" << endl;
        exit(EXIT_FAILURE);
    }

    // Read file
    vector<int> nums;
    while (true) {
        int num = 0;
        file >> num;

        // check if done reading the data
        if (file.fail()) {
            break;
        }

        // push num into vector
        nums.push_back(num);
    }

    // Close file
    file.close();

    return nums;
}

// store number
vector<int> makeSequence(int size){
    

    vector<int> by3;
    
    //Multiples of 3
    for (int i=0; i<size; i++){
       
        int j= thr;
        j *= i;
        by3.push_back(j);
    }

    return by3;

}

//linear search
int countMatchesLinearly(vector<int> data1, vector<int> data2){

    int num = 0;

    for(int x:data1){
        
        for(int y:data2){
            
            // check and if it match break out of function
            if(x == y){
                num ++;
                break;
            }

        }

    }
    
    return num;
}

// binear
int countMatchesBinarySearch(vector<int> data1, vector<int> data2){

    int count =0;
    //sort
    sort(data2.begin(), data2.end());

    //compare
    for( int x: data1){

        bool found = binary_search(data2.begin(), data2.end(), x);
        
        // if the same
        if(found){

            count++;
        }
       
    }
    return count;


}

