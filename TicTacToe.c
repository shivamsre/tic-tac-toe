#include <stdio.h>
#include <conio.h>
#include<stdio.h>
char square[10] = { 'o', '1', '2', '3', '4', '5', '6', '7', '8', '9' };
int checkforwin();
void board();
int main()
{
    int player = 1, i,x=0, choice;
    char mark,ch,strx[50],stro[50],str[50],a[3][3];
    printf("\nenter name for X player : ");
    gets(strx);
    printf("\nenter name for O player : ");
    gets(stro);
    do
    {
        board();
        while(x==0){
        printf("\nwho want to play first %s or %s  : ",strx,stro);
        gets(str);
        if(strcmp(str,strx)==0){
            x=player=1;
            break;}
        else if(strcmp(str,stro)==0){
            x=player=2;
            break;}
        else
            printf("%s is not registered",str);
        }
        player = (player % 2) ? 1 : 2;
        printf("Player %d, enter a number:  ", player);
        scanf("%d", &choice);
        mark = (player == 1) ? 'X' : 'O';
        if (choice == 1 && square[1] == '1')
            square[1] = mark;
        else if (choice == 2 && square[2] == '2')
            square[2] = mark;
        else if (choice == 3 && square[3] == '3')
            square[3] = mark;
        else if (choice == 4 && square[4] == '4')
            square[4] = mark;
        else if (choice == 5 && square[5] == '5')
            square[5] = mark;
        else if (choice == 6 && square[6] == '6')
            square[6] = mark;
        else if (choice == 7 && square[7] == '7')
            square[7] = mark;
        else if (choice == 8 && square[8] == '8')
            square[8] = mark;
        else if (choice == 9 && square[9] == '9')
            square[9] = mark;
        else
        {
            printf("Invalid move ");
            player--;
            getch();
        }
        i=checkforwin();
        player++;
    }while(i==-1);
    board();
    if (i==1)
        printf("\aPlayer %d win ", --player);
    else
        printf("\aGame draw");
    getch();
    return 0;
}
int checkforwin()
{
    if (square[1] == square[2] && square[2] == square[3])
        return 1;
    else if (square[4] == square[5] && square[5] == square[6])
        return 1;
    else if (square[7] == square[8] && square[8] == square[9])
        return 1;
    else if (square[1] == square[4] && square[4] == square[7])
        return 1;
    else if (square[2] == square[5] && square[5] == square[8])
        return 1;
    else if (square[3] == square[6] && square[6] == square[9])
        return 1;
    else if (square[1] == square[5] && square[5] == square[9])
        return 1;
    else if (square[3] == square[5] && square[5] == square[7])
        return 1;
    else if (square[1] != '1' && square[2] != '2' && square[3] != '3' &&
        square[4] != '4' && square[5] != '5' && square[6] != '6' && square[7]
        != '7' && square[8] != '8' && square[9] != '9')
        return 0;
    else
        return  - 1;
}
void board()
{
    system("cls");
    printf("\nMADE BY SHIVAM GUPTA CS-A\n");
    printf("\n\n\tTic Tac Toe\n\n");
    printf("Player 1 (X)  -  Player 2 (O)\n\n\n");
    printf("     .     .     \n");
    printf("  %c  .  %c  .  %c \n", square[1], square[2], square[3]);
    printf("................ \n");
    printf("  %c  .  %c  .  %c \n", square[4], square[5], square[6]);
    printf("................ \n");
    printf("  %c  .  %c  .  %c \n", square[7], square[8], square[9]);
    printf("     .     .     \n\n");
}

