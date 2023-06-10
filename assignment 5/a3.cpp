// Assginment 5 cmpt 
// Stanley Yang
// Chris Yee 


#include <iostream>
#include <vector>
#include <fstream>
#include <cstdlib>
#include <algorithm>
using namespace std;

string getfilename();
void fileToVector(string fileName, vector<string> &unchangedVector);
void permute(vector<vector<char>> & result, vector<char> & v, int left, int right);
vector<char> split(const string& str);
void swap(vector<char> &v, int i, int j );
vector<string> toLowerVec (vector<string>inputFileVector);




int main() 
{
  
  string fileName = getfilename();

  // note we want 2 vectors one holding a copy we always refer to and a vector holding the contents of the txt file we have chosen 

  vector <string> list; 

  ifstream wordlist("wordlist.txt");
  while(true)
  {
    string nextline;
    getline (wordlist, nextline);

    if(wordlist.fail()){
      break;
    }

    list.push_back(nextline);
  }
  
  wordlist.close();

  vector <string> inputFileVector; 

  fileToVector (fileName, inputFileVector);
  
  // we now have two vectors reference and input vector
  inputFileVector = toLowerVec(inputFileVector);

  // this is used to remove duplicates in a file 
  //*******************************************************************
  unsigned int i, x;
  bool newValue; 
  i = 1;
  while ( i < inputFileVector.size() )
  {
    newValue = true;
    x = -1;
    while ( ++x < i && newValue )
    {
      if ( inputFileVector[x] == inputFileVector[i] )
      {
        inputFileVector.erase( inputFileVector.begin()+i );
        newValue = false;
      }
    }
    if ( newValue )
    {
      i++;
    }
  }

  // for(int i= 0; i < referenceVector.size();i++){

  //   cout << referenceVector[i];
  //   cout << endl;
  // }
  // references
  // http://www.cplusplus.com/forum/beginner/203059/
  // ******************************************************************
    
  // trying to split then permute then reform then store then binary search 
  
  vector<char> seperatedString;
  vector<vector<char>> master;
  for (unsigned int i = 0; i < inputFileVector.size(); i++){;
    
    //create file
    ofstream outfile(inputFileVector[i]+".txt");
    string singleWord = inputFileVector[i]; // bat , cinema , dragon , abacus

    int sizeOfstring = singleWord.size();
    
    for(int i = 0; i < sizeOfstring; i++){
      
      seperatedString = split(singleWord);
 
    }

    vector<string> result;

    int left = 0;
    int right = seperatedString.size()-1;
    permute(master, seperatedString, left, right);
    for (vector<char> row : master) 
    {
      for (char x : row) {
        outfile << x ;
      }
      outfile << endl;
    }

    master.clear(); 
    outfile << "*" << endl;
    
    string name = singleWord +".txt";

    fileToVector(name,result);

    vector<string> anagram;
    //sort(toSort.begin(),toSort.end());
    sort(result.begin(),result.end());
    

    for(string x : result)
    { 
      if(binary_search(list.begin(),list.end(), x))// if found which means if a match is found add to counter 
      { 
        anagram.push_back(x);
      }
    }

    cout << anagram.size();

    for (string current : anagram)
    { 
      
      outfile << current << endl;
    }

    outfile.close();

       
    // clear master vector
    
  }
}
//break string into char
vector<char> split(const string& str)
{
    vector<char> result;

    // For each character in the string
    for (char ch : str)
    {
        // Copy only alphabetical characters and numeric digits
      if (isalnum(ch))
      {
        result.push_back(ch);
      }
    }
  return result;
}

string getfilename(){ 

  string filename;
 
  ifstream newfile; // we initalize new file 

  while (!newfile.is_open())
  { 
    cout << " Enter your file name: ";
    cin >> filename;

    ifstream newfile(filename); // 

    if (!newfile.is_open())
    {
        cout << "Invalid output " << endl;
    }
    else 
    {
      break;
    }
    newfile.close();
  }
  return filename;
}

// lower the letter
vector<string> toLowerVec (vector<string>inputFileVector)
{
  // This ensures the values in the vector are now lower case 
  for ( unsigned int i = 0; i < inputFileVector.size(); i++)
  {
      
    string holdingval = inputFileVector[i];

    int j = 0;
    while (holdingval[j])
    {
      holdingval[j] = tolower(holdingval[j]);
      j++;
    }
    inputFileVector[i] = holdingval; // input file vector is now all lowercased 

  }
  return inputFileVector;
}

// store file data in vector
void fileToVector(string fileName, vector<string> &vector)
{

  ifstream file (fileName);
    
  while (true)
  {
    string nextline;
    getline(file, nextline);
    
    if (file.fail())
    { 
      break; 
    }
    vector.push_back(nextline);
  }
  file.close();
}

// You may copy-and-paste the following code into your submission, without citation
// Generates all the permutations of the integers store in v
// USAGE: values of left and right in initial call should be 0 and v.size()-1
// PRE: result is empty
// 0 <= left, right < v.size()
// PARAM: result - vector to contain the permutations
// v - input vector of integers
// left, right - indexes of current subarray
// POST: Stores the permutations of the input vector v in result
void permute(vector<vector<char>> &result, vector<char> &v, int left, int right)
{
  if (left == right)
  {
    result.push_back(v);
  }
  else
  {
    for (int i = left; i <= right; i++)
    {
      swap(v, i, left);
      permute(result, v, left + 1, right);
      swap(v, i, left);
    }
  }
}
void swap(vector<char> &v, int i, int j)
{
  int temp = v.at(i);
  v.at(i) = v.at(j);
  v.at(j) = temp;
}

