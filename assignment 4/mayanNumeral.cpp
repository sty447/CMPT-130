#include<iostream>
#include<ctime>
#include<iomanip>
#include<cstdlib>
#include<vector>
#include<cmath>
using namespace std;

// constant
const int EXITCON = 10;
const int Max = 1.5;
const int MIN = 0.5;
const int UNDERLINE = 30;
const int TWOZERO = 20;

// setup the display vaule 
const string BAR = "\u2580";
const string ZERO = "@@\n";
const string ONE = "o\n";
const string TWO = "oo\n";
const string THREE = "ooo\n";
const string FOUR = "oooo\n";
const string FIVE = "\u2580\u2580\u2580\u2580\n";
const string SEPERATOR = "------\n";


vector<string> displayValueMayan(int num);

void printBar(int barNum);

void gameLoop();

int power(int base, int power);

int intro();

int randCorrectValue(int userInput);

vector<int> incorrectValue(int correct);

vector<int> pickOptionRan(int correct, int firstIncorrect, int secondIncorrect);

int newGame();

int powerFunction(int base,int power);

void printMayanNumber(int num);

void conversion(int num, vector<int> & convert);


int main(){

    
    // random 
    srand(time(nullptr));

    // spacing
    cout << endl;

    //game loop
    gameLoop();

    cout << endl;

    return 0;


}
//print the amout of bar asked
void printBar(int barNum){

    for(int i = 0; i < barNum; i++){

        cout << BAR;

    }

}

//powerFunction

int powerFunction(int base, int power){
    
    
    if (power == 0){
        return 1;
    }

    int outCome = base;

    for (int i = 1; i < power; i++){
        outCome *= base;
    }
    return outCome;

}

// vector that store number of 1 - 20 in 
vector<string> displayValueMayan(){

    vector<string> mayan;

    //change num to mayan

    //0 to 4
    mayan.push_back(ZERO);
    mayan.push_back(ONE);
    mayan.push_back(TWO);
    mayan.push_back(THREE);
    mayan.push_back(FOUR);

    //5 to 9
    mayan.push_back(FIVE);
    mayan.push_back(ONE + FIVE);
    mayan.push_back(TWO + FIVE) ;
    mayan.push_back(THREE + FIVE);
    mayan.push_back(FOUR + FIVE);

    //10 to 14
    mayan.push_back(FIVE + FIVE);
    mayan.push_back(ONE + FIVE + FIVE);
    mayan.push_back(TWO + FIVE + FIVE);
    mayan.push_back(THREE + FIVE + FIVE);
    mayan.push_back(FOUR + FIVE + FIVE);

    //15 to 20
    mayan.push_back(FIVE + FIVE + FIVE);
    mayan.push_back(ONE + FIVE + FIVE + FIVE);
    mayan.push_back(TWO + FIVE + FIVE + FIVE);
    mayan.push_back(THREE + FIVE + FIVE + FIVE);
    mayan.push_back(FOUR + FIVE + FIVE + FIVE);
    mayan.push_back(FIVE + FIVE + FIVE + FIVE);
    
    return mayan;

}

//print the MayanNumber
void printMayanNumber(int num){

    //make new function to store the value in displayMayan
    vector<string> display = displayValueMayan();

    // create empty vector
    vector<int> converted;
    conversion(num, converted);
 
    //
    for (unsigned int i = 0; i <= converted.size(); i++){
        
        cout << display[converted[i]];

        if (i < converted.size()){
            cout << SEPERATOR;
        }
    }

}



// converting arabic to mayan
void conversion(int num, vector<int> &convert){


    
    int highestPower = 0;
    //i here is equal to 20
    int i = TWOZERO;

    // find heighest power
    while(i <= num){

        highestPower++;
        i *= TWOZERO;

    }

    // using highest power and work it way down 
    for (int i = highestPower; i >= 0; i--)
    {
        int power = pow(TWOZERO,i);
        if (num > power)
        {
            convert.push_back(num / power);
            num -= (num / power) * power ;
        }
        else if (num == power)
        {
            convert.push_back(1);
            num -= (num / power) * power;
        }
        else
        {
            convert.push_back(0);
        }
    }

    convert.pop_back();
    
}


int intro(){

    int userInput = 0;


    // welcome statment and game rule
    cout << "Hello welcome to Mayan number guessing game";
    cout << endl;
    cout << endl;
    cout << "Please enter a number no less than 10.";
    cout << endl; 
    cout << "The game will pick a random number less than or equal to that number you picked";
    cout << endl;
    cout << "and you need to guess the correct mayan numeral for that value,";
    cout << endl;
    cout << "if you enter less than 10 the program will exit.";
    cout << endl;
    cout << "Enter the value: ";
    cin >> userInput;

    return userInput;

}

// random a value for the correct ansnwer
int randCorrectValue(int userInput){

    // generate a random num

    int correct = rand()%userInput + 1;

    // keep generate number if the number is less than 4;
    while(correct < 4){

        correct = rand()%userInput + 1;
    }

    return correct;

}
// asking for new game 
int newGame(){

    int userInput = 0;

    // request for a newgame 
    cout << endl;
    cout << "Do you want to play again?";
    cout << endl;
    cout << "Enter a new value that is no less then 10";
    cout << endl;
    cout << "If you don't want to play again then enter less than 10";
    cout << endl;

    // ask for userinput
    cout << "Enter value: ";
    cin >> userInput;

    return userInput;

}

// find two incorrect answer
vector<int> incorrectValue(int correct){

    // new vector
    vector<int> incorrect;

    // find the range of the incorrect num
    int lowest = correct * MIN;
    int highest = correct * Max;

    // generate random number
    int first = rand()%highest + 1;
    int second = rand()%highest + 1;

    // check if the first incorrect is not lower than minimum and not the same as correct number
    while(first < lowest || first == correct){

        first = rand()%highest + 1;

    }

    // check if the first incorrect is not lower than minimum and not the same as correct number and the first incorrected
    while(second < lowest || second == correct || second == first){

        second = rand()%highest + 1;

    }
    
    //add the two value to the vector
    incorrect.push_back(first);
    incorrect.push_back(second);

    return incorrect;

}


// randomize the order
vector<int> pickOptionRan(int correct, int firstIncorrect, int secondIncorrect){

    //correct vector to store the value 
    vector<int> option;
    option.push_back(correct);
    option.push_back(firstIncorrect);
    option.push_back(secondIncorrect);

    int optionA = rand()%3;
    int optionB = rand()%3;
    int optionC = rand()%3;

    // make sure the option don't repeat
    while(optionB == optionA){

        optionB = rand()%3;

    }
    while(optionC == optionA || optionC == optionB){

        optionC = rand()%3;

    }

    // set the new order 
    int newA = option.at(optionA);
    int newB = option.at(optionB);
    int newC = option.at(optionC);


    //create new vectot to store the new option

    vector<int> newOrder;
    
    // store the new order plus the location of the correct answer
    newOrder.push_back(newA);
    newOrder.push_back(newB);
    newOrder.push_back(newC);

    return newOrder;


}



// loop game

void gameLoop(){

    int userInput = intro();

    while(userInput >= EXITCON){

        // get the random correct number
        int correct = randCorrectValue(userInput);
        

        cout << endl;
        
        // display the the value that need to be match
        cout << "The number generated: ";
        cout << correct;
        cout << endl;
        cout << "Find the matching mayan numeral";
        cout << endl;
        printBar(UNDERLINE);
        cout << endl;
        
        // make new vector to store the value received
        vector<int> incorrect = incorrectValue(correct);

        vector<string> mayan = displayValueMayan();


        // bring out values in the vector
        int firstIncorrect = incorrect.at(0);
        int secondIncorrect = incorrect.at(1);

        // make new vector to store the value received(0,1,2 and 3 being correct answer location)
        vector<int> newOptionOrder =  pickOptionRan(correct,firstIncorrect,secondIncorrect);

        int A = newOptionOrder.at(0);
        int B = newOptionOrder.at(1);
        int C = newOptionOrder.at(2);
        
        int correctValueLocation = 0;
        //find where the correct answer is located
        if(A == correct){

            correctValueLocation = 0;

        }
        else if(B == correct){

            correctValueLocation = 1;
        }
        else if(C == correct){

            correctValueLocation = 2;
        }

        // //print the options 
        cout << "A: ";
        cout << endl;

        printMayanNumber(A);

        cout << endl;
        cout << endl;

        cout << "B: ";
        cout << endl;

        printMayanNumber(B);

        cout << endl;
        cout << endl;

        cout << "C: ";
        cout << endl;

        printMayanNumber(C);

        cout << endl;
        cout << endl;

        //create the option value
        string userAnswer ="S";
        string optionA ="A";
        string optionB ="B";
        string optionC ="C";

        // ask for user answer
        cout << "Please enter the letter that your think right(in capital letter)";
        cout << endl;
        cout << "Enter letter: ";
        cin >> userAnswer;
        cout << endl;


        // check if it a valide option
        while(userAnswer != optionA && userAnswer != optionB && userAnswer != optionC ){
            
            cout << endl;
            cout << "You didn't not enter an option listed";
            cout << endl;
            cout << "Enter a option represented by it's Capital Letter";
            cout << endl;
            cout << "Enter letter: ";
            cin >> userAnswer;
            cout << endl;

        }

        cout << endl;

        int userNum = 0;

        //covert letter into numbers
        if(userAnswer == optionA){
            
            userNum = 0;

        }
        else if(userAnswer == optionB){

            userNum = 1;
        }
        else if(userAnswer == optionC){

            userNum = 2;
        }

        //check if correct 

        if(userNum == correctValueLocation){
            
            cout <<"Your are correct this mayan numeral is " << correct ;
            cout << endl;
        }
        else if( userNum != correctValueLocation){
                
            cout <<"You are incorrect this not mayan numeral of "<< correct;
            cout << endl;
            cout <<"The correct mayan numeral of "<< correct << " is";
            cout << endl;
        }


        // show corrcect mayan numeral


        printMayanNumber(correct);


        cout << endl;


        // call new game function to continue the loop or end it depend on user input
        int playAgain = newGame();
        userInput = playAgain;
        
    }

}

