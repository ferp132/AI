#include "Game.h"

Game::Game()
{
	MaxTurns	= 9;
	TurnsTaken  = 0;
	PlayerTurn  = 0;
	GameOver	= 0;
	Winner		= 0;
}

Game::~Game()
{
}

void Game::PickTile()
{
	int xChoice;
	int yChoice;
	bool ValidChoice = 0;

	while (!ValidChoice)
	{
	cout			<< "Pick x Tile Coord: ";
	cin	 >> xChoice;
	cout << endl	<< "Pick y Tile Coord: ";
	cin  >> yChoice;

	if (xChoice > 3 || xChoice < 1 || yChoice > 3 || yChoice < 1)
	{
		cout << "Invalid Choice, Try Again" << endl;
		continue;
	}

	xChoice--;
	yChoice--;

	if (GameBoard.GetTile(yChoice, xChoice) == 0)
	{
		GameBoard.SetTile(PlayerTurn + 1, xChoice, yChoice);
		ValidChoice = true;
	}
	else cout << "Invalid Choice, Try Again" << endl;
	}
}

void Game::PlayTurn()
{
	if		(GameMode && PlayerTurn && Difficulty)	AIPickTile();		//If PvAI and it's Hard Mode
	else if (GameMode && PlayerTurn)				RandomPickTile();	//If PvAI
	else											PickTile();			//If PvP
	TurnsTaken++;
	if (TurnsTaken == MaxTurns) GameOver = true;
	else if (CheckWin())
	{
		GameOver = true;
		Winner = PlayerTurn + 1;
	}
	PlayerTurn = !PlayerTurn;
}

void Game::GameLoop()
{
	while (!GameOver)
	{
		ClearScreen();
		GameBoard.DrawBoard();
		PlayTurn();
	}

	ClearScreen();
	GameBoard.DrawBoard();
	cout << "Game Over!" << endl;
	if		(Winner == 1) cout << "X Wins!";
	else if (Winner == 2) cout << "O Wins!";
	else				  cout << "It's A Draw!";
}

bool Game::CheckWin()
{
	unsigned int CurrentPlayer = PlayerTurn + 1;
	//Winning Conditions;
	bool Horz1 = (GameBoard.GetTile(0, 0) == CurrentPlayer) && (GameBoard.GetTile(0, 1) == CurrentPlayer) && (GameBoard.GetTile(0, 2) == CurrentPlayer); //First Row
	bool Horz2 = (GameBoard.GetTile(1, 0) == CurrentPlayer) && (GameBoard.GetTile(1, 1) == CurrentPlayer) && (GameBoard.GetTile(1, 2) == CurrentPlayer); //Second Row	
	bool Horz3 = (GameBoard.GetTile(2, 0) == CurrentPlayer) && (GameBoard.GetTile(2, 1) == CurrentPlayer) && (GameBoard.GetTile(2, 2) == CurrentPlayer); //Third Row
	bool Vert1 = (GameBoard.GetTile(0, 0) == CurrentPlayer) && (GameBoard.GetTile(1, 0) == CurrentPlayer) && (GameBoard.GetTile(2, 0) == CurrentPlayer); //First Collumn
	bool Vert2 = (GameBoard.GetTile(0, 1) == CurrentPlayer) && (GameBoard.GetTile(1, 1) == CurrentPlayer) && (GameBoard.GetTile(2, 1) == CurrentPlayer); //Second Collumn
	bool Vert3 = (GameBoard.GetTile(0, 2) == CurrentPlayer) && (GameBoard.GetTile(1, 2) == CurrentPlayer) && (GameBoard.GetTile(2, 2) == CurrentPlayer); //Third Collumn
	bool Diag1 = (GameBoard.GetTile(0, 0) == CurrentPlayer) && (GameBoard.GetTile(1, 1) == CurrentPlayer) && (GameBoard.GetTile(2, 2) == CurrentPlayer); //Diagonal From Top Left
	bool Diag2 = (GameBoard.GetTile(0, 2) == CurrentPlayer) && (GameBoard.GetTile(1, 1) == CurrentPlayer) && (GameBoard.GetTile(2, 0) == CurrentPlayer); //Diagonal From Top Right

	if (TurnsTaken > 4) //impossible to win before turn 5
	{
		if (Horz1 || Horz2 || Horz3 || Vert1 || Vert2 || Vert3 || Diag1 || Diag2)
		{
			return true;
		}
	}
	
	return false;
}

void Game::ClearScreen()
{
	COORD coordScreen = { 0, 0 };
	DWORD cCharsWritten;
	CONSOLE_SCREEN_BUFFER_INFO csbi;
	DWORD dwConSize;
	HANDLE hConsole = GetStdHandle(STD_OUTPUT_HANDLE);
	GetConsoleScreenBufferInfo(hConsole, &csbi);
	dwConSize = csbi.dwSize.X * csbi.dwSize.Y;
	FillConsoleOutputCharacter(hConsole, TEXT(' '), dwConSize,
		coordScreen, &cCharsWritten);
	GetConsoleScreenBufferInfo(hConsole, &csbi);
	FillConsoleOutputAttribute(hConsole, csbi.wAttributes, dwConSize,
		coordScreen, &cCharsWritten);
	SetConsoleCursorPosition(hConsole, coordScreen);
}

void Game::AIPickTile()
{
}

void Game::RandomPickTile()
{
	//Pick A Random Tile
	cout << "This Function Doesnt Do Anything Yet!";
}
