#include <iostream>
#include <vector>
using namespace std;

class Tick_tack_toe{
    private:
        vector<vector<char>> board;
        char currentplayer;

    public:
        Tick_tack_toe(){
            board = {{' ',' ',' '},{' ',' ',' '},{' ',' ',' '}};
            currentplayer= 'X';
        }
    
    void displayBoard(){
        int row= board.size();
        int column = board[0].size();
        for(int i=0; i<row;i++){
            cout<<endl;
            cout<<"|";

            for(int y=0; y<board[i][y];y++){
                cout<< board[i][y];
                cout<<"|";
            }
         
            cout<<"\n";
            
            if(i<2) cout<<"-------";

        };
        
    }

    void makeMove(){
        int row;
        int column;
        bool move=true;

        while (move)
        {
        cout<< "Player " << currentplayer<< ": Enter coordinates to play";
        cout<< "\nRow: (0-2) ";
        cin>> row;
        cout<< "\nColumn: (0-2)";
        cin>> column;
            if(row>2 || row<0 || column<0 || column>2){
                cout<<"\n Choose again the row or column is the wrong dimension";
                continue;
            }
            
  
            if(board[row][column]=='X' || board[row][column]=='O'){
                cout<< "This spot is already taken!";
            } else {
                board[row][column]=currentplayer;
                move=false;
            }  
        }
    };

    void player_switch(){
        if (currentplayer=='X'){
            currentplayer='O';
        } else{
            currentplayer='X';
        }
    };

    bool checkWin(){
        for(int i=0;i<board.size();i++){
            if((board[i][0]==currentplayer && board[i][1]==currentplayer && board[i][2]==currentplayer) ||
            (board[0][i]==currentplayer && board[1][i]==currentplayer && board[2][i]==currentplayer)) {
                return true;
            } 
        }

        if((board[0][0]==currentplayer && board[1][1]==currentplayer && board[2][2]==currentplayer )|| 
        (board[0][2]==currentplayer && board[1][1]==currentplayer && board[2][0]==currentplayer )){
        return true;
        }
        return false;
    }

    bool isDraw() {
        for (int i = 0; i < 3; i++) {
            for (int j = 0; j < 3; j++) {
                if (board[i][j] == ' ') {
                    return false;  
                }
            }
        }
        return true;  
    }

    char getCurrentPlayer(){
        return currentplayer;
    }

};

int main(){
    Tick_tack_toe board;

    while(true){
    board.displayBoard();
    cout<<endl;
    board.makeMove();
    
    
    if(board.checkWin()){
        cout<<"Player "<< board.getCurrentPlayer() << " wins!";
        break;
    }
    
    
    if(board.isDraw()){
        cout<<"It's a draw!";
        break;
    }

    board.player_switch();
    }
    return 0;

};