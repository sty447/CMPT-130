#include <string>
#include <iostream>
#include <iomanip>
#include <vector>
#include <algorithm>
#include <fstream>
using namespace std;

const int PUBLIC = 0;
const int SPACE = 10;


// creat structs
struct post_t{
  
  int authorID;
  int targetID;
  string message;  

};

void displayPost(const post_t & post);

vector<post_t> readPostsFromFile(string fileName);

void displayAllPosts(const vector<post_t>& posts);

// for some reason public can be a viable name so i used shown
int shown(const vector<post_t>& posts);

int numPost(const vector<post_t>& posts, int current);

int mostPost(const vector<post_t>& posts);

int countPublicPostsRecursive(const vector<post_t>& posts, int lastIdx);





int main(){

  vector<post_t> postFile;
  
  cout << endl;

  //testing 
  post_t test = {101, 9999, "Just a test"};
  displayPost(test);
  cout << endl;

  //toss the file content into vector
  postFile = readPostsFromFile("postfile.txt");



  
  //display num of public post
  cout << "Total public post: ";
  cout << shown(postFile);
  cout << endl;

  //diplay most posted author
  cout << "Author with most post: ";
  cout << mostPost(postFile);
  cout << endl;

  //display num of public post done in a not smart way
  cout << "Number of Public Posts done Recursive: ";
  cout << countPublicPostsRecursive(postFile, postFile.size()-1);
  cout << endl;

  cout << endl;

  displayAllPosts(postFile);
  cout << endl;


}

// display struct
void displayPost(const post_t & post){

  cout << setw(SPACE) << post.authorID;
  cout << setw(SPACE) << post.targetID;
  cout <<  " " << post.message;
  cout << endl;

}

// extract files
vector<post_t> readPostsFromFile(string fileName)
{
  vector<post_t> posts;
  ifstream file(fileName);

  if (file.fail()) {
    cout << "Unable to open data file.\n" ;
    exit(EXIT_FAILURE);
  }
  // Read file data
  while (true) {
    post_t post;
    file >> post.authorID;
    // Check if there is in fact data:
    if (file.fail() && file.eof()) {
      break;
    }
    // Read rest of struct
    file >> post.targetID;
    getline(file, post.message);
    posts.push_back(post);
    // Check for errors
    if (file.fail()) {
      cout << "Unable to read course info from file.\n";
      exit(EXIT_FAILURE);
    }
  }

  file.close();
  return posts;

}

// display all post
void displayAllPosts(const vector<post_t>& posts)
{   
  // set title
    cout << setw(SPACE) << "AuthorID";
    cout << setw(SPACE) << "TargetID";
    cout << setw(SPACE) << "Message";
    cout << endl;
    cout << setw(SPACE) << "--------";
    cout << setw(SPACE) << "--------";
    cout << setw(SPACE) << "--------";
    cout << endl;

  // print all
    for(post_t x : posts){
      displayPost(x);
    }
}

// return the total number of id 0
int shown(const vector<post_t>& posts){
  int num = 0;

  for(post_t x : posts){
    if(x.targetID == PUBLIC){

      num++;

    }

  }

  return num;
}

//find num of post of author
int numPost(const vector<post_t>& posts, int current){

  int num = 0;

  for(post_t x : posts){

    if(x.authorID == current){

      num++;

    }

  }

  return num;

}




//find most post author
int mostPost(const vector<post_t>& posts){

 
  int author = 0;
  int currentTop = 0;
  int totalPost = 0;

  //find most posting 
  for(post_t x : posts){
    totalPost = numPost(posts, x.authorID);
    if(totalPost > currentTop){
      currentTop = totalPost;
      author = x.authorID;
    }
  }

 return author;

}

//not a smart way to count 
int countPublicPostsRecursive(const vector<post_t>& posts, int lastIdx){

  int isPublic = 0;

  //end if finish scanning
  if(lastIdx == -1){
    return 0;
  }
  // if it's public
  else if(posts.at(lastIdx).targetID == PUBLIC){
    
    isPublic = 1; 
  }
  //Recursive 
  return countPublicPostsRecursive(posts, lastIdx - 1) + isPublic;

}