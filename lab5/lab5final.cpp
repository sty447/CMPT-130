#include <iostream>

using namespace std;


const int HEIGHT = 5;
const int WIDTH = 5;


// output to include the drawsideways fucntion
// output C
void outputC(){

    cout <<"C ";

}
// output M
void outputM(){

    cout <<"M ";

}
// output P
void outputP(){

    cout <<"P ";

}
// output T
void outputT(){

    cout <<"T ";

}
// output one 
void output1(){

    cout <<"1 ";

}
// output three
void output3(){

    cout <<"3 ";

}
// output zero
void output0(){

    cout <<"0 ";

}



// drawing width
void drawSideWays(int value){


    // w is just variable 
    int w = 0; 
    while( w < WIDTH ){

        if(value == 1){
            
            outputC();

        }
        else if (value == 2){

            outputM();
        }
        else if ( value == 3 ){

            outputP();
        }
        else if (value == 4){

            outputT();
        }
        else if ( value == 5){

            output1();
        }
        else if (value == 6){

            output3();
        }
        else{
            
            output0();
        }

        w++;

    }
}

// drawing part of M with spaces
void drawMsidwayWithSpace(){
    
    int n = 0;

    //repeat till break
    while (n < 3){
        
        // call function 
        outputM();

        // add spacing
        cout << "   ";

        n++;

    }

}

//drawing part of P with spaces
void drawPsidwayWithSpace(){
    
    int n = 0;

    //repeat till break
    while (n < 1){
        

        // add spacing
        cout << "         ";

        // call function 
        outputP();

        

        n++;

    }


}

// Draw part of T
void drawTsidwayWithSpace(){
    
    int n = 0;

    //repeat till break
    while (n < 1){
        

        // add spacing
        cout << "     ";
        // call function 
        outputT();



        n++;

    }





}

//draw top part of one 
void draw1sidwayWithSpaceT(int value){

    int w = 0;
    while( w < WIDTH-3){

        if(value == 5){
            
            output1();
        }
        w++;
    }




}

//draw middle part of one 
void draw1sidwayWithSpaceM(){

        
    int n = 0;

    //repeat till break
    while (n < 1){
        

        // add spacing
        cout << "     ";
        // call function 
        output1();



        n++;
    }




}

//draw 3 
void draw3sidwayWithSpace(){

    
    int n = 0;

    //repeat till break
    while (n < 1){
        

        // add spacing
        cout << "         ";

        // call function 
        output3();

        

        n++;

    }


}

//draw 0
void draw0sidwayWithSpace(){
    
    int n = 0;

    //repeat till break
    while (n < 1){
        

        // add spacing
        cout << "        ";

        // call function 
        output0();

        n++;

    }


}

// draw c
void drawC(){

    int h = 0;
    int printFirstN = 1;
    while(h < HEIGHT ){

        cout << "C ";
        
        if(h == 0 || h == HEIGHT - 1){

          drawSideWays(printFirstN);

        }
        cout << endl;
        h++;
    }

}

// draw m
void drawM(){

    int h = 0;
    int printSecN = 2;

    cout << "M ";


    while(h < HEIGHT){
        
        if(h == 0 ){

          drawSideWays(printSecN);

        }
        else if (h>0){

            drawMsidwayWithSpace();
        
        }
        cout << endl;
        h++;
        
    }

}

// draw p
void drawP(){

    int h = 0;
    int printThirN = 3;


    while(h < HEIGHT + 4){

        cout << "P ";
        
        if(h == 0 || h == HEIGHT - 1){

          drawSideWays(printThirN);

        }
        else if (h >0 && h < HEIGHT -1 ){

            drawPsidwayWithSpace();

        }
        cout << endl;
        h++;
    }
}

// draw t 
void drawT(){

    int h = 0;
    int printForN = 4;

    cout << "T ";

    while(h < HEIGHT + 1 ){

        
        
        if(h == 0){

          drawSideWays(printForN);

        }
        else if (h >0){

            drawTsidwayWithSpace();

        }
        cout << endl;
        h++;
    }

    







}

// draw 1
void drawOne(){


    int h = 0;
    int printFivN = 5;
    cout << "1 ";

    while(h < HEIGHT+ 1){

       
        
        if(h == HEIGHT ){

          drawSideWays(printFivN);

        }
        else if(h == 0){

            int value = HEIGHT;
            draw1sidwayWithSpaceT(value);

        }
        else{
        
            draw1sidwayWithSpaceM();

        }
        cout << endl;
        h++;
    }




}

// draw 3
void drawThree(){

    int h = 0;
    int printSixN = 6;

    while(h < HEIGHT ){

       
        
        if(h == 0 || h == HEIGHT - 1 || h == HEIGHT - 3){

          drawSideWays(printSixN);

        }
        else if (h == 1  || h == HEIGHT -2 ){

            draw3sidwayWithSpace();

        }
        cout << endl;
        h++;
    }





}

//draw 0
void drawZero(){


    int h = 0;
    int printSevN = 7;


    while(h < HEIGHT ){

        cout << "0 ";
        
        if(h == 0 || h == HEIGHT - 1){

          drawSideWays(printSevN);

        }
        else if (h >0 && h < HEIGHT -1 ){

            draw0sidwayWithSpace();

        }
        cout << endl;
        h++;
    }
}






int main(){

    //look nicer 
    cout << endl;
    
    // call function
    drawC();

    // spacing 
    cout << endl;


    drawM();


    cout << endl; 


    drawP(); 

    cout << endl; 

    drawT();

    cout << endl;

    drawOne();


    //spaceing
    cout << endl;

    drawThree();

    //spaceing
    cout << endl;

    drawZero();

    cout << endl;

    return 0;
}