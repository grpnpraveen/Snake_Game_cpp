#include<iostream>
#include<stdlib.h>
#include<Windows.h>
#include<conio.h>
using namespace std;
bool gameover;
int tailx[50], taily[50];
int ntail;
const int height = 20;
const int width = 20;
int x, y, fruitx, fruity, score;
enum eDirection { STOP = 0,LEFT,UP,RIGHT,DOWN,};
eDirection dir;


//settings
void settings()
{
	gameover = false;
	score = 0;
	//dir = STOP;
	x = width / 2;
	y = height / 2;
	fruitx = rand() % width;
	fruity = rand() % height;
}
//visuals
void visuals()
{
	system("cls");
	for (int i = 0;i < width+1;i++)
	{
		cout << "#";
	}
	cout<<endl;

	for (int i = 0;i < height;i++)
	{
		for (int j = 0;j < width;j++)
		{

			if (j == 0)
			{
				cout << "#";
			}
			else if (i == x && j == y)
			{
				cout << "O";
			}
			else if (fruitx == i && fruity == j)
			{
				cout << "*";
			}
			else {
				bool printtail = false;
				for (int k = 0;k < ntail;k++)
				{
					if (tailx[k] == i && taily[k] == j)
					{
						cout << "o";
						printtail = true;
					}
				}
				if (!printtail) {
					cout << " ";
				}
				
			}
			if(j==width-1)
			{
				cout << "#"<<endl;
				
			}
		}
	}

	for (int i = 0;i < width+1;i++)
	{
		cout << "#";
	}
	cout << endl;
	cout << endl;
	cout << "SCORE IS :   \" " << score <<" \" "<<endl;

	cout << endl;
	cout << endl;
	cout << endl;
	cout << endl;
	cout <<"Game By GALI_RAVI_PRAVEEN "<< endl;
}
//logic
void logic()
{
	int prevx = tailx[0];
	int prevy = taily[0];
	int prev2x;
	int prev2y;
	tailx[0] = x;
	taily[0] = y;
	for (int i = 1;i < ntail;i++)
	{
		prev2x = tailx[i];
		prev2y = taily[i];
		tailx[i] = prevx;
		taily[i] = prevy;
		prevx = prev2x;
		prevy = prev2y;
	}





	switch (dir)
	{
	case UP:
		x--;
		break;
	case DOWN:
		x++;
		break;
	case LEFT:
		y--;
		break;
	case RIGHT:
		y++;
		break;
	default:
		break;
	}
	if (x >= width) {
		x = 0;
	}
	else if (x < 0)
	{
		x = width - 1;
	}
	if (y>= height) {
		y = 0;
	}
	else if (y < 0)
	{
		y = height - 1;
	}
	for (int i = 0;i < ntail;i++)
	{
		if (tailx[i] == x && taily[i] == y)
		{
			gameover = true;
		}
	}
	if (x == fruitx && y == fruity)
	{
		score++;
		fruitx = rand() % (width-1);
		fruity = rand() % (height-1);
		ntail++;
	}
}
//input
void input()
{
	if (_kbhit())
	{
		switch (_getch())
		{
		case 'a':
			dir = LEFT;
			break;
		case 'd':
			dir = RIGHT;
			break;
		case 'w':
			dir = UP;
			break;
		case 's':
			dir = DOWN;
			break;
		case 'o':
			gameover=true;
			break;
		default:
			break;

		}

	}

}

int main()
{
	settings();
	while (!gameover) {
		visuals();
		input();
		logic();
		//Sleep(20);
	}


	return 0;
}