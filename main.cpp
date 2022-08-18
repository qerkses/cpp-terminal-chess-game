#include <iostream>
#include <string>
#include <vector>
using namespace std;

class ChessPiece
{
public:
	virtual ~ChessPiece() {}
	virtual char getColor() = 0;
	virtual string getName() = 0;
	virtual bool Movement(int posX1, int posY1, int posX2, int posY2, ChessPiece* cboard[8][8]) = 0;
};

class Pawn : public ChessPiece
{
private:
	bool firstMove = true;
	char color;

public:

	Pawn(char color)
	{
		this->color = color;
	}

	~Pawn() {}

	char getColor()
	{
		return color;
	}

	string getName()
	{
		return " Pawn ";
	}

	bool Movement(int posX1, int posY1, int posX2, int posY2, ChessPiece* cboard[8][8])
	{
		if (posX1 == posX2 && cboard[posY2][posX2] == 0)
		{
			if ((posY1 + 2 == posY2 && getColor() == 'B') || (posY1 - 2 == posY2 && getColor() == 'W'))
			{
				if (firstMove)
				{
					firstMove = false;
					return true;
				}
				return false;
			}

			if ((posY1 + 1 == posY2 && getColor() == 'B') || (posY1 - 1 == posY2 && getColor() == 'W'))
			{
				return true;
			}
			return false;
		}

		if ((posY1 + 1 == posY2 && getColor() == 'B') || (posY1 - 1 == posY2 && getColor() == 'W'))
		{
			if (posX1 + 1 == posX2 || posX1 - 1 == posX2)
			{
				if (cboard[posY2][posX2] != 0)
				{
					firstMove = false;
					return true;
				}
			}
			return false;
		}
		return false;
	}
};

class Rook : public ChessPiece
{
private:
	char color;

public:

	Rook(char color)
	{
		this->color = color;
	}

	~Rook() {}

	char getColor()
	{
		return color;
	}

	string getName()
	{
		return " Rook ";
	}

	bool Movement(int posX1, int posY1, int posX2, int posY2, ChessPiece* cboard[8][8])
	{
		if (posX1 == posX2)
		{
			if (posY1 > posY2)
			{
				for (int y = posY2 + 1; y < posY1; y++)
				{
					if (cboard[y][posX1] != 0)
					{
						return false;
					}
				}
				return true;
			}
			else
			{
				for (int y = posY1 + 1; y < posY2; y++)
				{
					if (cboard[y][posX1] != 0)
					{
						return false;
					}
				}
				return true;
			}
			return false;
		}

		if (posY1 == posY2)
		{
			if (posX1 > posX2)
			{
				for (int x = posX2 + 1; x < posX1; x++)
				{
					if (cboard[posY1][x] != 0)
					{
						return false;
					}
				}
				return true;
			}
			else
			{
				for (int x = posX1 + 1; x < posX2; x++)
				{
					if (cboard[posY1][x] != 0)
					{
						return false;
					}
				}
				return true;
			}
			return false;
		}
		return false;
	}
};

class Knight : public ChessPiece
{
private:
	char color;

public:

	Knight(char color)
	{
		this->color = color;
	}

	~Knight() {}

	char getColor()
	{
		return color;
	}

	string getName()
	{
		return "Knight";
	}

	bool Movement(int posX1, int posY1, int posX2, int posY2, ChessPiece* cboard[8][8])
	{
		if ((posY1 - 2 == posY2) || (posY1 + 2 == posY2))
		{
			if ((posX1 + 1 == posX2) || (posX1 - 1 == posX2))
			{
				return true;
			}
		}

		if ((posY1 - 1 == posY2) || (posY1 + 1 == posY2))
		{
			if ((posX1 + 2 == posX2) || (posX1 - 2 == posX2))
			{
				return true;
			}
		}
		return false;
	}
};

class Bishop : public ChessPiece
{
private:
	char color;

public:

	Bishop(char color)
	{
		this->color = color;
	}

	char getColor()
	{
		return color;
	}

	~Bishop() {}

	string getName()
	{
		return "Bishop";
	}

	bool Movement(int posX1, int posY1, int posX2, int posY2, ChessPiece* cboard[8][8])
	{
		if (posX1 == posX2 || posY1 == posY2)
		{
			return false;
		}

		if (posX1 > posX2)
		{
			if (posY1 > posY2)
			{
				int i = 1;
				while (true)
				{
					if (posX1 - i == posX2 && posY1 - i == posY2)
					{
						return true;
					}
					if (posX1 - i < 0 || posY1 - i < 0)
					{
						return false;
					}
					if (cboard[posY1 - i][posX1 - i] != 0)
					{
						return false;
					}
					i++;
				}
				return false;
			}
			else
			{
				int i = 1;
				while (true)
				{
					if (posX1 - i == posX2 && posY1 + i == posY2)
					{
						return true;
					}
					if (posX1 - i < 0 || posY1 + i > 7)
					{
						return false;
					}
					if (cboard[posY1 + i][posX1 - i] != 0)
					{
						return false;
					}
					i++;
				}
				return false;
			}
			return false;
		}
		else
		{
			if (posY1 > posY2)
			{
				int i = 1;
				while (true)
				{
					if (posX1 + i == posX2 && posY1 - i == posY2)
					{
						return true;
					}
					if (posX1 + i > 7 || posY1 - i < 0)
					{
						return false;
					}
					if (cboard[posY1 - i][posX1 + i] != 0)
					{
						return false;
					}
					i++;
				}
				return false;
			}
			else
			{
				int i = 1;
				while (true)
				{
					if (posX1 + i == posX2 && posY1 + i == posY2)
					{
						return true;
					}
					if (posX1 + i > 7 || posY1 + i > 7)
					{
						return false;
					}
					if (cboard[posY1 + i][posX1 + i] != 0)
					{
						return false;
					}
					i++;
				}
				return false;
			}
			return false;
		}	
		return false;
	}
};

class Queen : public ChessPiece
{
private:
	char color;

public:

	Queen(char color)
	{
		this->color = color;
	}

	~Queen() {}

	char getColor()
	{
		return color;
	}

	string getName()
	{
		return " Queen";
	}

	bool Movement(int posX1, int posY1, int posX2, int posY2, ChessPiece* cboard[8][8])
	{
		ChessPiece* tbishop = new Bishop(getColor());
		ChessPiece* trook = new Rook(getColor());

		if (tbishop->Movement(posX1, posY1, posX2, posY2, cboard))
		{
			delete tbishop, trook;
			return true;
		}

		if (trook->Movement(posX1, posY1, posX2, posY2, cboard))
		{
			delete tbishop, trook;
			return true;
		}
		delete tbishop, trook;
		return false;
	}
};

class King : public ChessPiece
{
private:
	char color;

public:

	King(char color)
	{
		this->color = color;
	}

	~King() {}

	char getColor()
	{
		return color;
	}

	string getName()
	{
		return " King ";
	}

	bool Movement(int posX1, int posY1, int posX2, int posY2, ChessPiece* cboard[8][8])
	{
		if ((posX2 - posX1) >= -1 && (posX2 - posX1) <= 1)
		{
			if ((posY2 - posY1) >= -1 && (posY2 - posY1) <= 1)
			{
				return true;
			}
		}
		return false;
	}
};

class ChessBoard
{
private:
	bool playerTurn=true, isGameRunning=true;
	vector <string> moves;

	int TranslateLetter(char letter, bool mode)
	{
		if (mode)
		{
			switch (letter)
			{
			case 'A':
				return 0;
			case 'B':
				return 1;
			case 'C':
				return 2;
			case 'D':
				return 3;
			case 'E':
				return 4;
			case 'F':
				return 5;
			case 'G':
				return 6;
			case 'H':
				return 7;
			default:
				return -1;
			}
		}
		else
		{
			switch (letter)
			{
			case '1':
				return 7;
			case '2':
				return 6;
			case '3':
				return 5;
			case '4':
				return 4;
			case '5':
				return 3;
			case '6':
				return 2;
			case '7':
				return 1;
			case '8':
				return 0;
			default:
				return -1;
			}
		}
	}

	void BoardDraw()
	{
		system("cls");

		int k = 8;
		for (int y = 0; y < 8; y++)
		{
			cout << "-+------+------+------+------+------+------+------+------+" << endl;
			cout << " ";
			for (int x = 0; x < 8; x++)
			{
				if (gameBoard[y][x] != 0)
				{
					if (gameBoard[y][x]->getColor() == 'B')
					{
						cout << "|" << "\033[1;34m" << gameBoard[y][x]->getName() << "\033[0m";
					}
					else
					{
						cout << "|" << gameBoard[y][x]->getName();
					}
				}
				else
				{
					cout << "|" << "      ";
				}
			}
			cout << "|" << endl;
			cout << k;

			for (int x = 0; x < 8; x++)
			{
				if (gameBoard[y][x] != 0)
				{
					if (gameBoard[y][x]->getColor() == 'B')
					{
						cout << "|  ";
						cout << "\033[1;34m" << gameBoard[y][x]->getColor() << "\033[0m";
						cout << "   ";
					}
					else
					{
						cout << "|  " << gameBoard[y][x]->getColor() << "   ";
					}
				}
				else
				{
					cout << "|      ";
				}
			}
			cout << "|" << endl;
			k--;
		}
		cout << "-+------+------+------+------+------+------+------+------+" << endl;
		cout << " |  A   |  B   |  C   |  D   |  E   |  F   |  G   |  H   |" << endl;
		cout << endl;
		cout << "Type: exit, to stop game" << endl;
		cout << "Turn: ";
		if (playerTurn)
		{
			cout << 'W' << endl;
		}
		else
		{
			cout << "\033[1;34mB\033[0m" << endl;;
		}
		cout << "Next move: ";
	}


	string UserMove()
	{
		string userInput;
		bool flag = true;
		do
		{
			flag = true;
			cin >> userInput;
			if (userInput.length() != 5)
			{
				if (userInput == "exit")
				{
					isGameRunning = false;
					break;
				}
				flag = false;
				continue;
			}
			if ((char)userInput[2] != ':')
			{
				flag = false;
				continue;
			}
		} while (flag == false);
		return userInput;
	}

public:
	ChessPiece* gameBoard[8][8];

	ChessBoard()
	{
		for (int y = 0; y < 8; y++)
		{
			for (int x = 0; x < 8; x++)
			{
				gameBoard[y][x] = 0;
			}
		}

		for (int x = 0; x < 8; x++)
		{
			gameBoard[1][x] = new Pawn('B');
			gameBoard[6][x] = new Pawn('W');
		}

		gameBoard[7][3] = new Queen('W');
		gameBoard[7][4] = new King('W');
		gameBoard[7][2] = new Bishop('W');
		gameBoard[7][5] = new Bishop('W');
		gameBoard[7][1] = new Knight('W');
		gameBoard[7][6] = new Knight('W');
		gameBoard[7][0] = new Rook('W');
		gameBoard[7][7] = new Rook('W');

		gameBoard[0][3] = new Queen('B');
		gameBoard[0][4] = new King('B');
		gameBoard[0][2] = new Bishop('B');
		gameBoard[0][5] = new Bishop('B');
		gameBoard[0][1] = new Knight('B');
		gameBoard[0][6] = new Knight('B');
		gameBoard[0][7] = new Rook('B');
		gameBoard[0][0] = new Rook('B');
	}

	void StartGame()
	{
		while (isGameRunning)
		{
			BoardDraw();

			string userInput = UserMove();

			int posX1 = TranslateLetter((char)userInput[0], true);
			int posX2 = TranslateLetter((char)userInput[3], true);
			int posY1 = TranslateLetter((char)userInput[1], false);
			int posY2 = TranslateLetter((char)userInput[4], false);

			if (posX1 == -1 || posX2 == -1 || posY1 == -1 || posY2 == -1)
			{
				continue;
			}

			if (gameBoard[posY1][posX1] == 0)
			{
				continue;
			}
			if (gameBoard[posY2][posX2] != 0)
			{
				if (gameBoard[posY2][posX2]->getColor() == gameBoard[posY1][posX1]->getColor())
				{
					continue;
				}
			}

			if (playerTurn)
			{
				if (gameBoard[posY1][posX1]->getColor() != 'W')
				{
					continue;
				}
			}
			else
			{
				if (gameBoard[posY1][posX1]->getColor() != 'B')
				{
					continue;
				}
			}

			if (gameBoard[posY1][posX1]->Movement(posX1, posY1, posX2, posY2, gameBoard))
			{
				gameBoard[posY2][posX2] = gameBoard[posY1][posX1];
				gameBoard[posY1][posX1] = 0;
				moves.push_back(userInput);
				playerTurn = !playerTurn;
			}
			else
			{
				continue;
			}
		}
	};

	~ChessBoard()
	{
		for (int y = 0; y < 8; y++)
		{
			for (int x = 0; x < 8; x++)
			{
				delete gameBoard[y][x];
				gameBoard[y][x] = 0;
			}
		}
	}
};

int main() 
{
	ChessBoard Cboard;
	Cboard.StartGame();
	

	return 0;
}