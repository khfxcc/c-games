#include<stdio.h>
#include<stdlib.h>
#include<conio.h>

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

int map[MAX_ROW*2-1][MAX_COL*2-1] = {{0}};
const char *symbols[] = {
    "©³", "©»", "©·", "©¿", "©Ó", "©Û", 
    "©Ä", "©Ì", "©¥", "©§", "©à", "¡ª", "©¦", " "
};

int main()
{
    system("title Îå×ÓÆå");
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
            if (i == 0 && j == 0) map[i][j] = 0;          // "©³"
            else if (i == MAX_ROW * 2 - 2 && j == 0) map[i][j] = 1;   // "©»"
            else if (i == 0 && j == MAX_COL * 2 - 2) map[i][j] = 2;   // "©·"
            else if (i == MAX_ROW * 2 - 2 && j == MAX_COL * 2 - 2) map[i][j] = 3; // "©¿"
            else if (i == 0 && j % 2 == 0) map[i][j] = 4;  // "©Ó"
            else if (i == MAX_ROW * 2 - 2 && j % 2 == 0) map[i][j] = 5;  // "©Û"
            else if (i % 2 == 0 && j == 0) map[i][j] = 6;  // "©Ä"
            else if (i % 2 == 0 && j == MAX_COL * 2 - 2) map[i][j] = 7;  // "©Ì"
            else if ((i == 0 || i == MAX_ROW * 2 - 2) && j % 2 == 1) map[i][j] = 8;  // "©¥"
            else if ((j == 0 || j == MAX_COL * 2 - 2) && i % 2 == 1) map[i][j] = 9;  // "©§"
            else if (i % 2 == 0 && j % 2 == 0) map[i][j] = 10; // "©à"
            else if (i % 2 == 0 && j % 2 == 1) map[i][j] = 11; // "¡ª"
            else if (i % 2 == 1 && j % 2 == 0) map[i][j] = 12; // "©¦"
            else map[i][j] = 13; // " "
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
            printf("%s",symbols[map[i][j]]);
        }
        printf("\n");
    }
}
