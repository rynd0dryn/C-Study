#include "minesweeper.h"

void minesweeper(string commands, string output){

	ifstream fin(commands);
	ofstream fout(output);
	ifstream finBoard;
	bool gameover = false;
	string str;
	string temp;
	int x,y;
	int touchCount = 0;

	string board[8][8];

	while (!gameover){
		while(!fin.eof()) {
			fin >> str;
			temp = str;
			if(str == "load") {
				fin >> str;
				finBoard.open(str);
				fout << "Commamd: " << temp << " ";
				fout << str << endl;
				
				for(int i = 0; i<8; i++) {
					finBoard >> temp;
					for(int j = 0; j<8; j++) {
						board[i][j] = temp[j];
						fout << board[i][j];
						if (board[i][j]=="*"){
							board[i][j]="@";
						}
					}
					fout << endl;
				}
			}
			else if(str == "touch") {
				fin >> str;
				x = stoi(str);
				fin >> str;
				y = stoi(str);

				if (board[x][y] == "@"){
					board[x][y] = "*";
					touchCount ++;
					gameover = true;
				}
				if (board[x][y] == "."){
					touchCount ++;
					int num = 0;

					for(int i = 0; i<3; i++){
						for (int j = 0; j < 3; j++){
							num ++;
							board[i-1][j-1] += num;
						}
					}
					continue;
				}

			}
		}
	}
	
	if(gameover){
		fout << "GameOver" << endl;
		fout << "~~~~~~~~~" << endl;
		fout << "Final Board" << endl;

		for(int i = 0; i < 8; i++){
			for (int j = 0; j < 8; j++){
				fout << board[i][j];
			}
			fout << endl;
			fout << "Space touched: " << touchCount << endl;
		}
	}
	fin.close();
	fout.close();
	finBoard.close();
}

int main() {
	cout << "Testing minesweeper" << endl;
	cout << "야 임ㅁ마" << endl;
	minesweeper("test1commands.txt", "test1_output_mine.txt");
	minesweeper("test2commands.txt", "test2_output_mine.txt");
	minesweeper("test3commands.txt", "test3_output_mine.txt");
	minesweeper("test4commands.txt", "test4_output_mine.txt");
	minesweeper("test5commands.txt", "test5_output_mine.txt");
	minesweeper("test6commands.txt", "test6_output_mine.txt");
	minesweeper("test7commands.txt", "test7_output_mine.txt");
	minesweeper("test8commands.txt", "test8_output_mine.txt");
	minesweeper("test9commands.txt", "test9_output_mine.txt");
	minesweeper("test10commands.txt", "test10_output_mine.txt");
	
	return 0;
}
