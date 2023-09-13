#include<iostream>

using namespace std;

string board [9]={ " " ,  " " ," " ," " ," " ," " ," " ," "," "};

int player=1;
int position=0;


void intro(){

    cout<<"welcome to tic tac toe press enter to continue"<<endl;
    getchar();
    cout<<"\n";

    cout<<"Player 1: x "<<endl;
    cout<<"player 2: O "<<endl;

    cout<<"the grid :-\n"<<endl;

    cout<<"     |     |      \n";
    cout<<"  1  |  2  |  3   \n";
    cout<<"     |     |      \n";
    cout<<"------------------\n";
    cout<<"     |     |      \n";
    cout<<"  4  |  5  |  6   \n";
    cout<<"     |     |      \n";
    cout<<"------------------\n";
    cout<<"     |     |      \n";
    cout<<"  7  |  8  |  9   \n";
    cout<<"     |     |      \n\n";
    



}
bool is_winner()
{
    //diagonal
    if( board[0]==board[4] && board[4]==board[8] && board[0]!=" " ){
        return true;
    }
     
    else if( board[2]==board[4] && board[4]==board[6] && board[2]!=" " ){
        return true;
    }

    

   
    //row
   else if( board[0]==board[3] && board[3]==board[6] && board[0]!=" "  ){
        return true;
    }
     
   else if( board[1]==board[4] && board[4]==board[7] && board[1]!=" "  ){
        return true;
    }

   else if( board[2]==board[5] && board[5]==board[8] && board[2]!=" "  ){
        return true;
    }

    //column
    else if( board[0]==board[1] && board[1]==board[2] && board[0]!=" " ){
        return true;
    }
     
   else if( board[3]==board[4] && board[4]==board[5] && board[3]!=" " ){
        return true;
    }

  else  if( board[6]==board[7] && board[7]==board[8] && board[6]!=" " ){
        return true;
    }

    else{ return false; }
    
}
bool filled_up(){
    bool t=true;
    for(int i=0;i<9;i++){
        if(board[i]==" "){
            t=false;
            break;
        }
    }
    return t;
}
void draw(){
    cout<<"     |     |      \n";
    cout<<"  "<<board[0]<<"  |  "<<board[1]<<"  |  "<<board[2]<<"   \n";
    cout<<"     |     |      \n";
    cout<<"------------------\n";
    cout<<"     |     |      \n";
     cout<<"  "<<board[3]<<"  |  "<<board[4]<<"  |  "<<board[5]<<"   \n";
    cout<<"     |     |      \n";
    cout<<"------------------\n";
    cout<<"     |     |      \n";
     cout<<"  "<<board[6]<<"  |  "<<board[7]<<"  |  "<<board[8]<<"   \n";
    cout<<"     |     |      \n\n";
}
void set_position(){
    cin>>position;
    cout<<"\n"; 
}
bool update_board(){
    if(player % 2 == 1  && board[position-1]==" "){
        board[position-1]="x";
        return true;
    }
    else if (player % 2 == 0  && board[position-1]==" "){
        board[position-1]="O"; 
        return true;
    }
    cout<<"invalid move please enter valid move"<<endl;
    return false;
}
void change_player(){
    if(player==1){
        player++;
    }
    else{
        player--;
    }
}
void take_step(){
    if(!is_winner() && !filled_up()){
        set_position();
        if(update_board()){
        change_player();
        draw();}
        take_step();
    }

}
void end_game(){
    if(is_winner()){
        cout<<"we have a winner"<<endl;
    }
    else{
        cout<<"its a tie"<<endl;

    }
}



int main(){

    intro();
    while(!filled_up() && !is_winner()){
    take_step();}

    end_game();
    
    return 0;
}