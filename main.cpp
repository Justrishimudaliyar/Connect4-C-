#include <iostream>
#include "printAscii.hpp"
#include "basicRules.hpp"
using namespace std;


struct playerDetails
{
	char playerName[81];
	char playerID;
  playerDetails() {
    int LetterDrop(char board[][10], playerDetails activePlayer);
    void Check (char board[][10], playerDetails activePlayer, int dropChoice);
    void BoardDisplay (char board[][10]);
    int CheckFour (char board[][10], playerDetails activePlayer);
    int BoardFull(char board[][10]);
    void WinCondition (playerDetails activePlayer);
    int restart (char board[][10]);
  }
};



int LetterDrop (char board[][10], playerDetails activePlayer) {
	int dropChoice;
	do {
		cout << activePlayer.playerName << "'s Turn ";
		cout << "Please enter a number between 1 and 7: ";
		cin  >> dropChoice;
    cout << "\e[2J\e[H";
		while (board[1][dropChoice] == 'X' || board[1][dropChoice] == 'O') {
			cout << "That row is full, please enter a new row: ";
			cin  >> dropChoice;
		}

	} while (dropChoice < 1 || dropChoice > 7);

return dropChoice;
}


void Check (char board[][10], playerDetails activePlayer, int dropChoice) {
	int length, turn;
	length = 6;
	turn = 0;

	do {
		if (board[length][dropChoice] != 'X' && board[length][dropChoice] != 'O') {
			board[length][dropChoice] = activePlayer.playerID;
			turn = 1;
		}
		else
		--length;
	} while (turn != 1);
}



void BoardDisplay (char board[][10]) {
	int rows = 6, columns = 7, i, ix;
	
	for(i = 1; i <= rows; i++) {
		for(ix = 1; ix <= columns; ix++) {
			if(board[i][ix] != 'X' && board[i][ix] != 'O')
				board[i][ix] = '_';
        cout << RED;
        cout << "|";
        cout << BLUE;
			cout << board[i][ix];
      cout << RED;
			cout << "|";
      cout << WHITE;
		}
		cout << " " << endl;
	}
}



int CheckFour (char board[][10], playerDetails activePlayer) {
	char XO;
	int win;
	
	XO = activePlayer.playerID;
	win = 0;

	for(int i = 8; i >= 1; --i) {
		for(int ix = 9; ix >= 1; --ix) {
			if(board[i][ix] == XO    &&
				board[i-1][ix-1] == XO &&
				board[i-2][ix-2] == XO &&
				board[i-3][ix-3] == XO ) {
				win = 1;
			}
			
			if( board[i][ix] == XO   &&
				board[i][ix-1] == XO &&
				board[i][ix-2] == XO &&
				board[i][ix-3] == XO ) {
				win = 1;
			}
					
			if( board[i][ix] == XO   &&
				board[i-1][ix] == XO &&
				board[i-2][ix] == XO &&
				board[i-3][ix] == XO ) {	
				win = 1;
			}
					
			if( board[i][ix] == XO     &&
				board[i-1][ix+1] == XO &&
				board[i-2][ix+2] == XO &&
				board[i-3][ix+3] == XO ) {
				win = 1;
			}
						
			if ( board[i][ix] == XO   &&
				 board[i][ix+1] == XO &&
				 board[i][ix+2] == XO &&
				 board[i][ix+3] == XO ) {
				win = 1;
			}
		}
	}
return win;
}



int BoardFull( char board[][10] ) {
	int full;
	full = 0;
	for ( int i = 1; i <= 7; ++i )
	{
		if ( board[1][i] != '_' )
			++full;
	}
return full;
}


void WinCondition ( playerDetails activePlayer ) {
	cout << endl << activePlayer.playerName << " Connected Four, You Win, rejoice, your dream is now complete!" << endl;
}


int restart ( char board[][10] ) {
	int restart;

	cout << "Would you like to try again?\nyes(1)\nno(2): ";
	cin  >> restart;
	if ( restart == 1 ) {
		for(int i = 1; i <= 6; i++) {
			for(int ix = 1; ix <= 7; ix++) {
				board[i][ix] = '_';
			}
		}
	}
	else
		cout << "May the force be with you!" << endl;
return restart;
}



int main() {
  
  string fileName = "Connect4.txt";
  printAscii(fileName);
  cin.get();

  fileName = "1.txt";
  printAscii(fileName);
  cin.get();
  cout << "\e[2J\e[H";

  fileName = "2.txt";
  printAscii(fileName);
  cout << "Press Enter to continue";
  cin.get();
    
  BasicRules();

	playerDetails playerOne, playerTwo;
	char board[9][10]; 
	int trueWidth = 7; 
	int trueLength = 6; 
	int dropChoice, win, full, again;
  cout << BLUE;
  cout << "\e[2J\e[H";

  cout << GREEN;
	cout << "Warrior, please enter your name: ";
	cin  >> playerOne.playerName;
	playerOne.playerID = 'X';

  cout << RED;
	cout << "Nemesis, please enter your name: ";
	cin  >> playerTwo.playerName;
	playerTwo.playerID = 'O';

  cout << WHITE;
	
	full = 0;
	win = 0;
	again = 0;
	BoardDisplay( board );
	do {
		dropChoice = LetterDrop(board, playerOne);
		Check (board, playerOne, dropChoice);
		BoardDisplay (board);
		win = CheckFour (board, playerOne);
		if (win == 1) {
			WinCondition(playerOne);
			again = restart(board);
			if (again == 2) {
				break;
			}
		}

		dropChoice = LetterDrop(board, playerTwo);
		Check(board, playerTwo, dropChoice);
		BoardDisplay(board);
		win = CheckFour(board, playerTwo);
		if (win == 1) {
			WinCondition(playerTwo);
			again = restart(board);
			if (again == 2) {
				break;
			}
		}

		full = BoardFull(board);
		if (full == 7) {
			cout << "It looks like the space time continuum is full, we'll have to delay this battle after some time" << endl;
			again = restart(board);
		}

	} while (again != 2);

return 0;
}