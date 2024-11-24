#include<stdio.h>
#include<stdlib.h>

#define MAX_ROW 15
#define MAX_COL 15
#define BLACK 1
#define WHITE -1

void Drawmap();
void Gamestart();
void initialize();
void Put();
int Checkmap();
void Showcursor();

int map_num[MAX_ROW*2-1][MAX_COL*2-1] = {{0}};
char map[MAX_ROW*2-1][MAX_COL*2-1];

int main()
{
    system("title 五子棋");
    while(1)
    {
        Gamestart();
    }
    return 0;
}

void initialize()
{
    for (int i = 0; i < MAX_ROW*2; i++)
    {
        for (int j = 0; j < MAX_COL*2; j++)
        {
            if (i == 0&&j == 0) map[i][j] == "┏"; 
            else if (i == MAX_ROW*2-1&&j == 0) map[i][j] = "┗";
            else if (i == 0&&j == MAX_COL*2-1) map[i][j] = "┓";
            else if (i == MAX_ROW*2-1&&j == MAX_COL*2-1) map[i][j] = "┛";
            else if (i == 0&&j%2 == 0) map[i][j] = "┯";
            else if (i == MAX_ROW*2-1&&j%2 == 0) map[i][j] = "┷";
            else if (i%2 == 0&&j == 0) map[i][j] = "┠";
            else if (i%2 == 0&&j == MAX_COL*2-1) map[i][j] = "┨";
            else if ((i == 0||i == MAX_ROW*2-1)&&j%2 == 1) map[i][j] = "━";
            else if ((j==0||j==MAX_COL*2-1)&&i%2==1) map[i][j] = "┃";
            else if (i%2==0&&j%2==0) map[i][j] = "┼";
            else if (i%2==0&&j%2==1) map[i][j] = "—";
            else if (i%2==1&&j%2==0) map[i][j] = "│";
            else map[i][j] = " ";
        }
    }
}

void Gamestart()
{
    int input;
    initialize();
    while (1)
    {
        Drawmap();
        input=getch();
        if(input==27)exit(0);
	}
}

void Drawmap()
{
    for (int i = 0; i < MAX_ROW*2-1; i++)
    {
        for (int j = 0; j < MAX_COL*2-1; j++)
        {
            printf("%s",map[i][j]);
        }
    }
}
