#include <iostream>
#include <vector>
#include <string>
using namespace std;

// phrase enter and display function
vector<string> createPhraseVector();
void displayPhrase(vector<string> phraseResult);

//find the the longest and shortest indexs
int findShortestIdx(vector<string> data);
int findLongestIdx(vector<string> data);

// swap min and max place
void swapValue(vector<string>&swap,int longest, int shortest,vector<string> data);


// understanding num 6
/*
Q: What is the difference between an element in a vector, and the element’s index? What
is the data type of the index? What is the data type of the element (for this lab)?

A:index is the place where the element is stored and a element is what and it stores, data type for a index is int 
and data type for the element for this lab is string

Q:How can we pass a vector to a function so it can be changed by the function? If you
did this incorrectly (and the vector could not change the actual function), how would
this bug be visible while testing the program?

A: using a single & this make it a pass by referece allowing the function to change it 

*/


int main(){

    cout << endl;

    // create vector and store the vector inputed
    vector<string> phraseStored;
    phraseStored = createPhraseVector();

    // print the vector
    displayPhrase(phraseStored);

    cout << endl;

    vector<string> data;
    data = phraseStored;

    // find and display shortest index plus print it
    int shortIndexNum = findShortestIdx(data);
    cout << "Shortest index = " 
         << shortIndexNum << " = "
         << "\""<< data.at(shortIndexNum) << "\"";
    
    cout << endl; 

    //find and display longest index num plus print it
    int longIdxNum = findLongestIdx(data);

    cout << "Longest index  = "
         << longIdxNum << " = "
         << "\"" << data.at(longIdxNum) << "\"";
    cout << endl;
    
    cout << endl;


    // swaping longest and shortest index
    vector<string> swap;
    swap = phraseStored;

    swapValue(swap,longIdxNum, shortIndexNum, data);

    cout << endl;



}

// ask user and store the input 
vector<string> createPhraseVector(){

    //creating a vector
    vector<string> v1; 
    string phrase;
    cout << "Enter a phrase: ";
    getline(cin, phrase);

    // if the input is not empty 
    while(phrase.length() != 0 ){

        v1.push_back(phrase);
        cout << "Enter a phrase: ";
        getline(cin, phrase);
        

    }

    // return vector 1
    return v1;

}
// take the stored value and print it 
void displayPhrase(vector<string> phraseResult){

    // header
    cout << "Phrase: ";
    cout << endl;

    // display all the value in the vector
    for(unsigned int i = 0;i < phraseResult.size(); i++){

        cout << "\t";
        cout << "\"" <<phraseResult.at(i) << "\"" ;
        cout << endl;

    }


}
// find the shortest value and the index number that store it 
int findShortestIdx(vector<string> data){

    int currentShortIndex = 0;

    int daFirstLength = data.at(0).size();

    currentShortIndex = daFirstLength;

    int length = 0;
    
    int indexNum = 0; 

    for( unsigned int i = 1; i < data.size(); i++){

        length = data.at(i).size();

        if( currentShortIndex > length){

            currentShortIndex = length;
            indexNum = i;
        }

    }

    return indexNum;

}

//find longest and the indx number of it
int findLongestIdx(vector<string> data){

    int longestIdx = 0; 
    
    int firstIdxSize= data.at(0).size();

    longestIdx = firstIdxSize;

    int currentLength = 0;

    int numIndex = 0;

    for( unsigned int i = 1; i < data.size(); i ++){

        currentLength = data.at(i).size();

        if( currentLength > longestIdx){

            longestIdx = currentLength;
            numIndex = i;
        }
    }


    return numIndex;

}

// swap longest and shortest index
void swapValue(vector<string> &swap, int longest, int shortest,vector<string> data){
     
    //swaping index
    swap.at(longest) = data.at(shortest);
    swap.at(shortest) = data.at(longest);

    displayPhrase(swap);

}
