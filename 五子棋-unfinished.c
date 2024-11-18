#include<stdio.h>
#include<stdlib.h>

#define MAX_ROW 16
#define MAX_COL 16
#define BLACK 1
#define WHITE -1

void draw_map(char [][]);
void game_start();
void initialize(char[][]);

int main()
{
    while(1)
    {
        printf("Press Enter to begin,other to exit.\n");
        if (getchar() == '\n')
        {
            game_start();
        }else
        {
            printf("Bye.");
            break;
        }
    }
    return 0;
}

void initialize(char map[][])
{
    for (int i = 0; i < MAX_ROW*2; i++)
    {
        for (int j = 0; j < MAX_COL*2; j++)
        {
            if (i == 0&&j == 0) printf("┌"); 
            else if (i == MAX_ROW*2-1&&j == 0) printf("└");
        }
    }
}

void game_start()
{
    int map_num[MAX_ROW*2-1][MAX_COL*2-1] = {{0}};
    char map[MAX_ROW*2-1][MAX_COL*2-1];
    initialize(map[][]);
    draw_map(map[][]);
}

void draw_map(char map[][])
{
    
}