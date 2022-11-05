#include "minesweeper.h"

void minesweeper(string commands, string output){

	ifstream fin(commands);
	ofstream fout(output);
	ifstream finBoard;
	bool gameover = false;
	string str;   //line -> str
	string temp;   //stringline -> temp
	int x,y;
	int touchCount = 0;

	string board[8][8];
    bool touchBoard[8][8]; // touchedBoard = touchBoard
    vector<string> boardVector; //x = boardVector;
    
    while(getline(fin,str)){
        istringstream strstring(str);
        fout << "Command: " << str << endl;
        boardVector.clear();
        while(getline(strstring,temp,' ')){
            boardVector.push_back(temp);
        }
        if(boardVector[0] == "load"){
            countBoard(board,boardVector[1]);           //countBoard == initBoard
            isTouched(touchBoard);
        }
        else if (boardVector[0] == "display"){
            displayBoard(fout,board, touchBoard,gameover);
        }
        else if (boardVector[0] == "touch"){
            touchCount ++;
            x = stoi(boardVector[1]);
            y = stoi(boardVector[2]);
            touchedBoard(touchBoard, x, y); // touchBoard -> touchedBoard 
            if(board[x-1][y-1] == "*"){
                break;
            }
        }
    }
    gameover = true;
    fout << "Game Over" << endl;
    fout << "~~~~~~~~~" << endl;
    fout << "Final Board" << endl;
    displayBoard(fout, board,touchBoard,gameover);
    fout << "Spaces touched: " << touchCount << endl;
}

void countBoard(string board[][8], string BoardFile){
    ifstream finBoard(BoardFile);
    string str;
    int x = 0;
    int y = 0;
    int num = 0;

    while(getline(finBoard,str)){
        for (int y = 0; y < 8; y++){
            if(str[y] == "."){
                board[x][y] = "0";
            }
            else{
                board[x][y] = str[y];
            }
        }
        x++;
    }
    for(int i = 0; i < 8; i++){
        for (int j = 0; j < 8; j++){
            if(board[i][j] == "0"){
                if (i != 0){
                    if(j != 0){

                        if(board[i-1][j-1] == "*"){
                            num ++;
                            board[i][j] = "0" + num;
                        }
                        if (board[i-1][j] == "*") {
                            num ++;
						    board[i][j] = "0" + num;
					    }
                        if (j != 7) {
						    if (board[i-1][j+1] == "*") {
							    num ++;
						        board[i][j] = "0" + num;
						    }
                        }
                    }
                }
                 if (j != 0){
                    if(board[i][j-1] == "*"){
                        num++;
                        board[i][j] = "0"+ num;
                    }
                }
                 if (j != 7) {
					if (board[i][j + 1] == "*") {
						num++;
                        board[i][j] = "0"+ num;
					}
				}
				if (i != 7) {
					if (j != 0) {
						if (board[i + 1][j - 1] == "*") {
							num++;
                            board[i][j] = "0"+ num;
						}
					}
					if (board[i + 1][j] == "*") {
						num++;
                        board[i][j] = "0"+ num;
					}
					if (j != 7) {
						if (board[i + 1][j + 1] == "*") {
							num++;
                            board[i][j] = "0"+ num;
						}
                    }   
                }
            }
        }
    }
    finBoard.close();
}

void displayBoard(ostream& ffout, string board[][8], bool touchBoard, bool gameover){
    for(int i = 0; i < 8; i++){
        for(int j = 0; j < 8; j++){
            if(gameover){
                if(touchBoard[i][j] == true){
                    ffout << board[i][j];
                }
                else{
                    if (board[i][j] == "*"){
                        ffout << "@";
                    }
                    else {
                        ffout << ".";
                    }
                }
            }
            else{
                if (touchBoard[i][j] == true){
                    ffout << board[i][j];
                }
                else {
                    ffout << ".";
                }
            }
        }
        ffout << endl;
    }
}

void touchedBoard(bool touchBoard[][8],int x, int y){
    touchBoard[x-1][y-1] = true;
}


void isTouched(bool touchBoard[][8]){
    for (int i = 0; i < 8; i++){
        for ( int j = 0; j < 8; j++){
            touchBoard[i][j] = false;
        }
    }
}

int main(){
    cout << "minesweeper" << endl;
    minesweeper("test1commands.txt","tes1_output_mine.txt");

    return 0;
}