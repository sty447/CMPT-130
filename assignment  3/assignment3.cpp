#include <iostream>
#include <iomanip>
#include <ctime>

using namespace std;

// constants 
const int CARDWIDTH = 5;
const int CARDVALUE = 3;
const int CARDSUIT  = 9;
const int CONNECTWORD = 3;
const int WIN = 1;
const int LOST = -1;
const int DRAW = 0;
const int MAXSCORE = 21;
const int DEALERMIN = 17;
const int DISPLAYVALUE = 5;



//function prototype

//diplay intro and request
int welcome();

// get random card 
int getCard();

// display the random card plus the suits
void displayCard(int card);

// diplay card value 
int cardScore(int card);

//dealing cards
int deal(bool isPlayer, bool isShown);

// display player scroe

int playerScore();



// game start
int playHand();

int playerScoreStart(int playerFirstCard, int playerSecCard);

int winConBefore(int playerHand, int dealerHand);

int askhitOrStand(int playerHand, int dealerHand);

void resultingValue(int playerHand, int dealerHand);

int actionStand(int hitOrStand,int playerHand, int dealerHand);

int resultConversion(int result);

void gameLoop();



int main(){

    //run random seed
    srand(time(nullptr));
    
    // spaceing 
    cout << endl;
    
    // starter function
    welcome();

    cout << endl;

    // start game loop
    gameLoop();

    cout << endl;



    return 0;



}





//out put intro statment and request for game(tested)
int welcome(){

    char yes = 'Y';
    char no = 'N';
    char userInput;
    int userWish = 0;
  
    // display msg and ask for input 
    cout << "Welcome, would you like to play BlackJack ";
    cout << endl;
    cout << "Enter Y for yes and N for No: " ;
    cin  >> userInput;

    // if the user enter an incorrect charcator
    while (userInput != yes && userInput != no){

        cout << endl;
        cout << "The input is not correct trying to turning it off and on to fix it";
        cout << endl;
        cout << "It didn't work but please enter the requested charactors";
        cout << endl;
        cout << "Enter Y for yes and N for No: " ;
        cin  >>  userInput;
        cout << endl;

    }


   
    if(userInput == yes){
        
        // start rest of the code
   
        return userWish;

    }
    else {

        // end code 


        return 0;
 
    }



}

// generate rand card(tested)
int getCard(){

    int cardNumber = rand()% 13 + 1;
    return cardNumber;

}

// display the rand card with a suits(tested)
void displayCard(int card){

    
    
    


    //display the rand card from numbers to letter letter 

     
    if(card == 1){

        cout << setw(CARDWIDTH-2) << "Ace";

    }
    else if(card == 2){

        cout << setw(CARDWIDTH-2) << "Two";

    }
    else if(card == 3){

        cout << setw(CARDWIDTH) << "Three";
        
    }
    else if(card == 4){

        cout << setw(CARDWIDTH-1) << "Four";
        
    }
     else if(card == 5){

        cout << setw(CARDWIDTH) << "Five";

    }
    else if(card == 6){

        cout << setw(CARDWIDTH-2) << "Six";
        
    }
    else if(card == 7){

        cout << setw(CARDWIDTH) << "Seven";
        
    }
     else if(card == 8){

        cout << setw(CARDWIDTH) << "Eight";

    }
    else if(card == 9){

        cout << setw(CARDWIDTH-1) << "Nine";
        
    }
    else if(card == 10){

        cout << setw(CARDWIDTH-2) << "Ten";
        
    }
     else if(card == 11){

        cout << setw(CARDWIDTH-1) << "Jack";

    }
    else if(card == 12){

        cout << setw(CARDWIDTH) << "Queen";
        
    }
    else if(card == 13){

        cout << setw(CARDWIDTH-1) << "King";
        
    }

    // looks nicer
    cout << setw(CONNECTWORD) << "of";


    // randoming the suit of the card
    int cardSuit = rand()%4 +1;

    if(cardSuit == 1){

        cout << setw(CARDSUIT) << "Diamonds";

    }
    else if(cardSuit == 2){

        cout << setw(CARDSUIT-2) << "Hearts";

    }
    else if(cardSuit == 3){

        cout << setw(CARDSUIT-2) << "Spades";
        
    }
    else if(cardSuit == 4){

        cout << setw(CARDSUIT-3) << "Clubs";
        
    }

}

// display the card value(tested)
int cardScore(int card){

    int cardValue = 0;
    
    if(card == 1){

        cardValue = 11;

    }
    else if(card == 2){

        cardValue = 2;

    }
    else if(card == 3){

        cardValue = 3;
        
    }
    else if(card == 4){

        cardValue = 4;
        
    }
     else if(card == 5){

        cardValue = 5;

    }
    else if(card == 6){

        cardValue = 6;
        
    }
    else if(card == 7){

        cardValue = 7;
        
    }
     else if(card == 8){

        cardValue = 8;

    }
    else if(card == 9){

        cardValue = 9;
        
    }
    else if(card == 10){

        cardValue = 10;
        
    }
     else if(card == 11){

        cardValue = 10;

    }
    else if(card == 12){

        cardValue = 10;
        
    }
    else if(card == 13){

        cardValue = 10;
        
    }

    return cardValue;

}

// dealing cards(tested)
int deal(bool isPlayer, bool isShown){




    int cardOutput = 0;
    // if it player show hand 

    if(isPlayer == true && isShown == true){
        
        cout << "Player was dealt:";
        

        //genrate card and show it
        int card = getCard();
        displayCard(card);
        cardOutput = cardScore(card);

        cout << endl;
    
    }

    // if it dealer and show card
    else if(isPlayer == false && isShown == true){
        
        cout << "Dealer was dealt:";
        

        // generate cards
        int card = getCard();
        
        // display the card
        displayCard(card);
        cardOutput = cardScore(card);

        cout << endl;
    
        
    }
    // if it dealer and a hidden card
    else if(isPlayer == false && isShown == false){


        cout << "Dealer was dealt: unknown";
       
        // generate cards
        int card = getCard();
        
        // does not display the card but still output value
        cardOutput = cardScore(card);

        cout << endl;

    }
    
    return cardOutput;

}

//display starting score(tested)
int playerScoreStart(int playerFirstCard, int playerSecCard){

    // adding player hand + shown
    int playerHand = playerFirstCard + playerSecCard;
    cout << endl;
    cout << "Player score: " << playerHand;

    return playerHand;


}


// display the resulting value for the card after the round stop(tested) 
void resultingValue(int playerHand, int dealerHand){

    cout << endl;
    cout << "Dealer reveals their hidden card!";
    cout << endl;
    cout << "Player score: " << playerHand;
    cout << endl;
    cout << "Dealer score: " << dealerHand;
    cout << endl;
    cout << endl;


}

//check for win condition before hit or stand(tested)

int winConBefore(int playerHand, int dealerHand){

    // if player have 21 and dealer does not
    if(playerHand == MAXSCORE && dealerHand < MAXSCORE){

        cout << "you won!";
        cout << endl;

        resultingValue(playerHand,dealerHand);

        // becasue i want these to prevent ask for hit function to start
        return 'W';
    }
    // if dealer have 21 and player doen't
    else if(dealerHand == MAXSCORE && playerHand < MAXSCORE){

        cout << "you lose";
        cout << endl;

        resultingValue(playerHand,dealerHand);
         // becasue i want these to prevent ask for hit function to start
        return 'L';
    }
    // if player goes busts super rare have to get 2 aces
    else if (playerHand > MAXSCORE){

        cout << "you lose";
        cout << endl;
        
        resultingValue(playerHand,dealerHand);

         // becasue i want these to prevent ask for hit function to start
        return 'L';
    }
    //if player and dealer both have 21
    else if(dealerHand == MAXSCORE && playerHand == MAXSCORE){

        cout << "Draw";
        cout << endl;

        resultingValue(playerHand,dealerHand);

         // becasue i want these to prevent ask for hit function to start
        return 'D';
    }
    

    // return a value that doesn't matter casuse all the condition is match in the if statement
    return 'U';
}

// if player chose to stand (tested)
int actionStand(int hitOrStand,int playerHand, int dealerHand){

    

    //dealer revall hand 
    resultingValue(playerHand, dealerHand);

    //if it under 17 draw more
    while(dealerHand < DEALERMIN){

        int newCard = deal(false,true);

        cout << endl;
            
        dealerHand = dealerHand + newCard;

        cout << "Player score: " << playerHand;
        cout << endl;
        cout << "Dealer score: " << dealerHand;
        cout << endl;
        cout << endl;

    }
    // dealer get 21 and player doesn't player lose 
    if(dealerHand == MAXSCORE && playerHand < MAXSCORE){

     
        cout << "you lose";
        cout << endl;
        cout << endl;
        cout << "Player score: " << playerHand;
        cout << endl;
        cout << "Dealer score: " << dealerHand;
        cout << endl;
        cout << endl;

        return LOST;

    }
    // dealer goes bust 
    else if (dealerHand > MAXSCORE){


        cout << "You Win";
        cout << endl;
        cout << endl;
        cout << "Player score: " << playerHand;
        cout << endl;
        cout << "Dealer score: " << dealerHand;
        cout << endl;
        cout << endl;

        return WIN;

    }
    // dealer and player have same value
    else if( dealerHand == playerHand){

  
        cout << "It a Draw";
        cout << endl;
        cout << endl;
        cout << "Player score: " << playerHand;
        cout << endl;
        cout << "Dealer score: " << dealerHand;
        cout << endl;
        cout << endl;

        return DRAW;

    }
    //dealer value bigger than player 
    else if (dealerHand > playerHand){
        
      
        cout << "you lose";
        cout << endl;
        cout << endl;
        cout << "Player score: " << playerHand;
        cout << endl;
        cout << "Dealer score: " << dealerHand;
        cout << endl;
        cout << endl;

        return LOST;

    }
    // dealer value smaller than player
    else if( dealerHand < playerHand){
        
      
        cout << "You Win";
        cout << endl;
        cout << endl;
        cout << "Player score: " << playerHand;
        cout << endl;
        cout << "Dealer score: " << dealerHand;
        cout << endl;
        cout << endl;

        return WIN;

    }
    // placehold value it doesn't do anything but let it debug with out an warning
    return 'U';

}

// request for hit or stand(tested)
int askhitOrStand(int playerHand, int dealerHand, int dealerShown ){
    

    char hitOrStand = 0;
    char hit = 'H';
    char stand = 'S';
    
    // ask if player want more cards
    cout << "Enter H for hit and S for stand: ";
    cin >> hitOrStand;

    // request for new letter
    while (hitOrStand != hit && hitOrStand != stand){

        cout << "You did not enter right letter";
        cout << endl;
        cout << "Please enter the right letter: ";
        cin >> hitOrStand;
        cout << endl;
        
    }
    
    // if the answer is hit then creat new card for it 
    while(hitOrStand != stand){


        
        // generate a new card and add it to the value of the player
        int newCard = deal(true,true);
        
        playerHand = playerHand + newCard;
        cout << "Player score: " << playerHand;
        cout << endl;
        cout << "Dealer score: " << dealerShown;
        cout << endl;
        cout << endl;

        // if player goes bust
        if(playerHand > MAXSCORE){

            hitOrStand = 'S';
            cout << "You losted";

            cout << endl;

            resultingValue(playerHand,dealerHand);

            return LOST;
        }
        // if player has 21 and dealer doesn't have 21
        else if(playerHand == MAXSCORE && dealerHand != MAXSCORE){

            hitOrStand = 'S';
            cout << "You Won!";
            cout << endl;
            
            resultingValue(playerHand,dealerHand);

            return WIN;
        }

        // ask for hit or stand
        cout << "Enter H for hit and S for stand: ";
        cin >> hitOrStand;

        cout << endl;



        // if user is enter the wrong number
        while(hitOrStand != hit && hitOrStand != stand){

            cout << "You did not enter right letter";
            cout << endl;
            cout << "Please enter the right letter: ";
            cin >> hitOrStand;

        }




    }

    // run the function action stand
    int resultOfStand = actionStand(hitOrStand, playerHand, dealerHand);

    return resultOfStand;

}

// covert letter of reslut to number(tested)
int resultConversion(int results){

    char win ='W';
    char lost ='L';
    char draw = 'D';

    //for letter to numbers
    if(results == win)
    {
        return WIN;
    }
    else if( results == lost){

        return LOST;
    }
    else if(results == draw){

        return DRAW;
    }

    // placehold value it doesn't do anything but let it debug with out an warning
    return 'U';

}

// start game (tested)
int playHand(){

    char win ='W';
    char lost ='L';
    char draw = 'D';



    // player hand
    int playerFirstCard = deal(true,true);
    int playerSecCard = deal(true, true);
    int dealerShown = deal(false, true);
    int dealerNotShown = deal(false,false);

    
    

    int playerHand = playerScoreStart(playerFirstCard,playerSecCard);

    cout << endl;

    // add the dealer hand + shown the known card
    int dealerHand = dealerShown + dealerNotShown;

    cout << "Dearler score: " << dealerShown;

    cout << endl;
    cout << endl;

    // check for win condition before hit and stand phase
    char results = winConBefore(playerHand, dealerHand);
    
    int outcome = resultConversion(results);
    
    // if the result conversion doesn't meet requridmnet run ask hit or stand
    if(results != win && results != lost && results != draw){

        outcome = askhitOrStand(playerHand,dealerHand,dealerShown);

    }
 

    return outcome;



}

// looping game(tested)
void gameLoop(){

    int wins = 0;
    int lose = 0;
    int draws = 0;
    int playAgain = 1;
    char yes = 'Y';
    char no = 'N';
    char userResponse = 0;

    while(playAgain == 1){



        int gameOutCome = playHand();

        // counting win and lost 
        if( gameOutCome == WIN){

            wins++;

        }
        else if(gameOutCome == LOST){

            lose++;
        }
        else if(gameOutCome == DRAW){

            draws++;
        }

        // request to play again
        cout << "Do you want to play again?";
        cout << endl;
        cout << "Enter Y for yes and N for No: ";
        cin >> userResponse;

        // if you user asnswer incorrectly ask again
        while (userResponse != yes && userResponse != no){

            cout << endl;
            cout << endl;
            cout << "It didn't work, please enter the requested charactors";
            cout << endl;
            cout << "Enter Y for yes and N for No: " ;
            cin  >>  userResponse;
            cout << endl;

        }

        if(userResponse == no){

            playAgain =0;

        }
        cout << endl;

    }

    // display win and loses
    
    cout << "Outcome of the entire game";
    cout << endl;
    cout << "Wins:"  << setw(DISPLAYVALUE+1) << wins;
    cout << endl;
    cout << "Lost:"  << setw(DISPLAYVALUE+1) << lose;
    cout << endl;
    cout << "Draws:" << setw(DISPLAYVALUE) << draws;
    cout << endl;







}
