#include <stdio.h>
#include <conio.h>
#include <stdlib.h>

int length = 30, width = 30, gameOver, flag;
int x, y ,foodX, foodY, score;
int tailX[100], tailY[100];
int CountTail = 0;

void setUp()

{
    //  int foodX , foodY ,x ,y , score;
    gameOver = 0;
    score = 0;
    x = length / 2;
    y = width / 2;
label1:
    foodX = rand() % 30;
    if (foodX == 0)
    {
        goto label1;
    }
label2:
    foodY = rand() % 30;
    if (foodY == 0)
    {
        goto label2;
    }
}
int draw()
{
    // int foodX , foodY ,x ,y;
  int i, j, k, countTail;
    system("cls");
      
    
    for (i = 0; i < length; i++)
    {
        for (j = 0; j < width; j++)
        {
            if (i == 0 || i == length - 1 || j == 0 || j == width - 1)
            {
                printf("=");
            }
            else
            {
                if (i == x && j == y)
                {
                    printf("O");
                }
                else if (i == foodX && j == foodY)
                {
                    printf("F");
                }
                else
                {
                    int ch = 0;
                    for (k = 0; k < CountTail; k++)
                    {
                        if (i == tailX[k] && j == tailY[k])
                        {
                            printf("o");
                            ch =1;
                        }
                    }
                    if(ch ==  0)

                    printf(" ");
                }
            }
        }
        printf("\n");
    }
}

void input()
{

    if (kbhit())
    {
        switch (getch())
        {
        case 'a':
            flag = 1;
            break;
        case 's':
            flag = 2;
            break;
        case 'w':
            flag = 3;
            break;
        case 'z':
            flag = 4;
            break;
        case 'x':
            gameOver = 1;
            break;
        }
    }
}
void MakeLogic()
{
    int i;
    int prevX = tailX[0];
    int prevY = tailY[0];
    int prev2X, prev2Y;
 tailX[0] = x;
 tailY[0] = y;
    for (i = 1; i < CountTail; i++)
    {
        prev2X = tailX[i];
        prev2Y = tailY[i];
        tailX[i] = prevX;
        tailY[i] = prevY;
        prevX = prev2X;
        prevY = prev2Y;
    }

    switch (flag)
    {
    case 1:
        y--;
        break;
    case 2:
        y++;
        break;
    case 3:
        x--;
        break;
    case 4:
        x++;
        break;
    default:
        break;
    }
    if (x < 0 || x > length || y < 0 || y > width)
        gameOver = 1;
    if (x == foodX && y == foodY)
    {
    label3:
        foodX = rand() % 30;
        if (foodX == 0)
        {
            goto label3;
        }
    label4:
        foodY = rand() % 30;
        if (foodY == 0)
        {
            goto label4;
            score += 10;
            CountTail++;
        }
    }
}

int main()
{
    int m, n;
    setUp();
    while (gameOver != 1)
    {
        draw();
        input();
        MakeLogic();
        for (m = 0; m < 1000; m++)
        {
            for (n = 0; n < 10000; n++)
            {
            }
        }
    }

    return 0;
}
