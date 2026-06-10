//////  Tic Tac Toe game
#include<iostream>
using namespace std;
//map
void printBoard(char map[3][3]){
        for(int i=0; i<3; i++){
        cout<<"|";
        for(int j=0; j<3; j++){
            cout<<map[i][j]<< "|";
        }
        cout<<endl;
    }
}
    //it defines the print function above the main 
    //here only | this is printed not the element of the array

    ///wincheck function 
 //checkwin is a function defined here
 //map and player are data elements 
 //the whole checkwin function is defind here befre the man code
    bool checkwin(char map[3][3], char player){
        //rows
        for(int i=0; i < 3; i++){
            if (map[i][0] == player && map[i][1] == player && map[i][2] == player){
                return true;
            } 
        }
        //coloums
        for(int j=0; j<3 ; j++){
            if (map[0][j] == player && map[1][j] == player && map[2][j] == player){
            return true;
            }
        }
        //diagnols
        if (map[0][0] == player && map[1][1] ==  player && map[2][2] == player){
            return true;
        }
        if (map[0][2] == player && map[1][1] == player && map[2][0] == player){
            return true;
        }
        return false;
        }
    

int main(){
    char again;
    do{
    char map[3][3] ={
        {' ', ' ', ' '},             //array initialized with spaces
        {' ', ' ', ' '},
        {' ', ' ', ' '}
    };
    //all cells are empty but the map is not printed yet
    // printBoard(map);
    //taking the input
    int row , col;
    char currentplayer = 'X';
    bool gameover = false; //it become true when someone wins or draw
    //taking the inputs
    for(int turns = 0;turns<9;turns++)
    {
        printBoard(map); // showing board at starting of the each turn
    cout<<"Player "<<currentplayer<<" Enter row from 1 to 3 : ";
    cin>>row;
    cout<<"Player "<<currentplayer<<" Enter col from 1 to 3 : ";
    cin>>col;

        if( row <1 || row >3 || col <1 || col >3 || map[row -1][col -1] != ' '){
                cout<<"Invalid input try again"<<endl;
                        turns--; // avoids the wastage of input
                continue; // go back to start of the loop
        }
    map[row -1][col -1] = currentplayer; //X or O is printed


    //checking the win
            if( turns >= 4){
    if ( checkwin(map ,currentplayer)){
       printBoard(map);
       cout<<"Player "<<currentplayer<<" won :)"<<endl;
       //return 0; it ends the code
       gameover = true; // gameover is assingend as true
       break; // jumps the for loop
    }
            }
    ////here we check for win by the checkwin that we have defined alrdy before main code
    ////so if checkwin is true by any manner[row,col,dia] it will give true and if condition is true then the if statement will run

    //switching the players
    if(currentplayer == 'O'){
       currentplayer = 'X';
    }
    else{
        currentplayer = 'O';
    }  
}
    if (!gameover){
        cout<<"It's a draw"<<endl;
    }

      //ask to play again
    cout<<"Play again ? (y/n) : ";
    cin>>again;
    }

    while(again == 'y'); //for char ' ' and for strings " "
if (again == 'n'){
    cout<<" ////// Thanks for playing //////";
}
  return 0;
}
