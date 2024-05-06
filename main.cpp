#include<iostream>
#include<cstdlib>
#include<ctime>

using namespace std;

int box[3][3] = {{0, 1, 2}, {3, 4, 5}, {6, 7, 8}};

void board()
{
    cout << "     |    |    " << endl;
    cout << "  " << (char)box[0][0] << "  |  " <<(char) box[0][1] << " |  " << (char)box[0][2] << endl;

    cout << "_____|____|____" << endl;

    cout << "     |    |    " << endl;
    cout << "  " << (char)box[1][0] << "  |  " << (char)box[1][1] << " |  " <<(char) box[1][2] << endl;
    cout << "_____|____|____" << endl;

    cout << "     |    |    " << endl;
    cout << "  " << (char)box[2][0] << "  |  " <<(char) box[2][1] << " |  " <<(char) box[2][2] << endl;
    cout << "     |    |    " << endl;
}

bool checkWin(char player)
{
    for (int i = 0; i < 3; i++)
    {
        if ((box[i][0] == player && box[i][1] == player && box[i][2] == player) ||
            (box[0][i] == player && box[1][i] == player && box[2][i] == player) ||
            (box[0][0] == player && box[1][1] == player && box[2][2] == player) ||
            (box[0][2] == player && box[1][1] == player && box[2][0] == player))
        {
            return true;
        }
    }
    return false;
}

bool checkTie()
{
    for (int i = 0; i < 3; i++)
    {
        for (int j = 0; j < 3; j++)
        {
            if (box[i][j] != 'X' && box[i][j] != 'O')
            {
                return false;
            }
        }
    }
    return true;
}

char randomizeToken()
{
	return(rand()%2==0)?'X':'O';
}

int main()
{
    string p1, p2;

    cout << "Enter the Player 1's Name: ";
    getline(cin, p1);

    cout << "Enter the Player 2's Name: ";
    getline(cin, p2);

	srand(static_cast<unsigned int>(time(nullptr)));
	char player1,player2;

	player1=randomizeToken();
	player2=(player1=='X')?'O':'X';

	cout<<p1<<" is "<<player1;
	cout<<endl;
	cout<<p2<<" is "<<player2;
	cout<<endl;

	cout<<endl;

	bool player1Turn = true;

	char currentPlayer = player1;

	while(true)
	{
		cout<<(player1Turn?p1:p2)<<"'s turn,Enter the position(0-8) : ";
		int pos;
		cin>>pos;

		int row = pos/3;
		int col = pos%3;

		if(box[row][col] != 'X' && box[row][col] !='0')
		{
			box[row][col]=currentPlayer;
			board();

			if(checkWin(currentPlayer))
			{
				cout<<(player1Turn?p1:p2)<<" wins!"<<endl;
				break;
			}
			if(checkTie())
			{
				cout<<"Its Tie"<<endl;
				break;
			}
			currentPlayer = (currentPlayer=='X')?'O':'X';
			player1Turn = !player1Turn;
		}
		else
		{
			cout<<"Invalid Position"<<endl;
		}


	}
    

	
	return 0;
}
    

	
	return 0;
}

