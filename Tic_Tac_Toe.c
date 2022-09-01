/*
                                ***Tic Tac Toe Game***
    Author : Arup

    Problem Given By : C C++ DSA IOT Job Ready Bootcamp Course conducted by iNeuron

    Problem Statement:
        Program a two-person game of Tic -Tac- Toe. The game is played on a three by
    three board. Each player has a marker.
    One player has an ‘X’, the other an ‘O’. Players alternate turns to place their marker
    on the board. The first player to get three in a row either diagonally, horizontally, or
    vertically, wins the games. In the event all squares are taken on the board without a
    winner then it is a tie. The program should set up the game by asking for the names
    of the players.
    Player one should be assigned an ‘X’ as their marker, player two should be assigned
    the ‘O’.
    The players should then have the option to play again. You may not assume that any
    input the user provides you is initially valid.
    If the information provided by the user at any stage of the program is invalid, the
    program should prompt until valid information is provided.

    Here two players can be : 1) User and Smart Computer ( Who will play smartly against the user )
                              2) User and Evil Computer ( Who will play smartly against the user but it can cheat with user )
                              3) User and User's friend

    A menu is provided at the beginning of the game where user can select game mode.

    Special Thanks to : Saurabh Sir (MySirG), Prateek Sir, Aditya Sir
*/

/*---Header Files---*/
#include<stdio.h>
#include<conio.h>
#include<stdlib.h>
#include<string.h>
#include<time.h>
/*-----------------*/

/*---Function Prototypes---*/
void heading(); //To display Heading
void rules(char[][3],int); //To display Rules
void gamePlaySmartComp(char[][3],int); //Play with Smart Computer
int smartCompMove(char[][3],int); //For Smart computer's Move and return position number marked
void gamePlayEvilComp(char[][3],int); //Play with Evil Computer
int evilCompMove(char[][3],int); //For Evil computer's Move and return position number marked
void gamePlayFriend(char[][3],int); //Play with Friend
void displayBoard(char[][3],int); //To display the board
int checkIfWin(char[][3],int); //To check if any player wins or not
int checkIfDraw(char[][3],int); //To check if the match is draw or not
int checkDiagonallyToMark(char[][3],int,char); // To check diagonal elements
int checkRowWiseToMark(char[][3],int,char); // check  wise position to mark
int checkColumnWiseToMark(char[][3],int,char); // check Column wise position to mark
int checkRandomToMark(char[][3],int); // Find random position to mark
char* getPosition(char[][3],int,int); //To get the valid position to mark
int getPositionNumber(int,int); //Get position number by putting row and column index
void gotoMainMenu(); //To go to the Main menu
void terminate(); //To terminate the game
/*--------------------------------------------------------------------------------------------------------*/

/*---Function Definitions---*/
int main()
{
    char mat[3][3]={'1','2','3','4','5','6','7','8','9'};
    char ch;
    int flag=1;
    while(flag)
    {
        heading();
        printf("\n .__MAIN_MENU_____________________________.");
        printf("\n | >> Press 1 to play with Smart Computer |");
        printf("\n | >> Press 2 to play with Evil Computer  |");
        printf("\n | >> Press 3 to play with Friend         |");
        printf("\n | >> Press 4 to Exit from the game       |");
        printf("\n |________________________________________|");
        printf("\n   Enter your choice : ");
        ch=getch();
        system("cls");
        switch(ch)
        {
            case '1':
                rules(mat,3);
                system("cls");
                flag=0;
                gamePlaySmartComp(mat,3);
                break;
            case '2':
                rules(mat,3);
                system("cls");
                flag=0;
                gamePlayEvilComp(mat,3);
                break;
            case '3':
                rules(mat,3);
                system("cls");
                flag=0;
                gamePlayFriend(mat,3);
                break;
            case '4':
                terminate();
        }
    }
    return 0;
}
void heading()
{
    printf("\n       ---------- OXOXOXO ----------");
    printf("\n       |        TIC TAC TOE        |");
    printf("\n       ------------3 x 3------------");
}
void rules(char m[][3],int n)
{
    heading();
    printf("\n\n                   *****");
    printf("\n             Rules of the game");
    printf("\n                   *****");
    printf("\n  >> Enter position number as shown in\n     the board to mark your desired position.");
    displayBoard(m,n);
    printf("\n     Press any key to continue ...");
    getch();
}
void gotoMainMenu()
{
    char ch;
    printf("\n       >> Press \'Y\' or \'y\' to go to main menu. ");
    printf("\n       >> Press \'N\' or \'n\' to exit from the game. ");
    while(1)
    {
        ch=getch();
        switch(ch)
        {
            case 'Y':
            case 'y':
                system("cls");
                main();
                break;
            case 'N':
            case 'n':
                terminate();
        }
    }
}
void terminate()
{
    system("cls");
    heading();
    printf("\n\n   Thank you for playing... See You Soon !");
    getch();
    system("cls");
    exit(0);
}
void gamePlaySmartComp(char mat[][3],int n)
{
    char name[30],name1[30],name2[30];
    heading();
    strcpy(name2,"Smart Computer");
    printf("\n       Enter Player\'s Name : ");
    fflush(stdin);
    fgets(name1,30,stdin);
    name1[strlen(name1)-1]='\0';
    /*--------------------------------------------------------------*/
    int pos,lastpos=-1;
    char lastName[30];
    char mark='X';
    strcpy(name,name1);
    while(!checkIfWin(mat,3) && !checkIfDraw(mat,3))
    {
        system("cls");
        heading();
        printf("\n       Player 1 : %s ( X )",name1);
        printf("\n       Player 2 : %s ( O )",name2);
        displayBoard(mat,3);
        printf("\n       %s\'s Turn -> %c ",name,mark);
        if(mark=='X')
        {
            while(1)
            {
                system("cls");
                heading();
                printf("\n       Player 1 : %s ( X )",name1);
                printf("\n       Player 2 : %s ( O )",name2);
                displayBoard(mat,3);
                if(lastpos!=-1)
                    printf("\n       %s has marked at position %d ",lastName,lastpos);
                printf("\n       %s\'s Turn -> %c ",name,mark);
                printf("\n       Enter position number : ");
                scanf("%d",&pos);
                if(getPosition(mat,n,pos))
                {
                    *getPosition(mat,n,pos)=mark;
                    break;
                }
            }
            mark='O';
            strcpy(lastName,name);
            strcpy(name,name2);
        }
        else if(mark=='O')
        {
            lastpos=smartCompMove(mat,n);
            mark='X';
            strcpy(lastName,name);
            strcpy(name,name1);
        }

    }
    if(checkIfWin(mat,3))
    {
        system("cls");
        heading();
        printf("\n       Player 1 : %s ( X )",name1);
        printf("\n       Player 2 : %s ( O )",name2);
        displayBoard(mat,3);
        printf("\n       %s Wins \n",lastName);
    }
    if(checkIfDraw(mat,3))
    {
        system("cls");
        heading();
        printf("\n       Player 1 : %s ( X )",name1);
        printf("\n       Player 2 : %s ( O )",name2);
        displayBoard(mat,3);
        printf("\n       Match Draw \n");
    }
    gotoMainMenu();
}
int smartCompMove(char m[][3],int n)
{
    int i,j,cO,cX,flag,pos;
    /*---Check the possibility to win---*/
    pos=checkRowWiseToMark(m,n,'O');
    if(pos!=-1)
        return pos;

    pos=checkColumnWiseToMark(m,n,'O');
    if(pos!=-1)
        return pos;

    pos=checkDiagonallyToMark(m,n,'O');
    if(pos!=-1)
        return pos;
    /*---Check the possibility to defend---*/
    pos=checkRowWiseToMark(m,n,'X');
    if(pos!=-1)
        return pos;

    pos=checkColumnWiseToMark(m,n,'X');
    if(pos!=-1)
        return pos;

    pos=checkDiagonallyToMark(m,n,'X');
    if(pos!=-1)
        return pos;

    /*---If there is no possibility to win or defend---*/
    return(checkRandomToMark(m,n));

}
void gamePlayEvilComp(char mat[][3],int n)
{
    char name[30],name1[30],name2[30];
    heading();
    strcpy(name2,"Evil Computer");
    printf("\n       Enter Player\'s Name : ");
    fflush(stdin);
    fgets(name1,30,stdin);
    name1[strlen(name1)-1]='\0';
    /*--------------------------------------------------------------*/
    int pos,lastpos=-1;
    char lastName[30];
    char mark='X';
    strcpy(name,name1);
    while(!checkIfWin(mat,3) && !checkIfDraw(mat,3))
    {
        system("cls");
        heading();
        printf("\n       Player 1 : %s ( X )",name1);
        printf("\n       Player 2 : %s ( O )",name2);
        displayBoard(mat,3);
        printf("\n       %s\'s Turn -> %c ",name,mark);
        if(mark=='X')
        {
            while(1)
            {
                system("cls");
                heading();
                printf("\n       Player 1 : %s ( X )",name1);
                printf("\n       Player 2 : %s ( O )",name2);
                displayBoard(mat,3);
                if(lastpos!=-1)
                    printf("\n       %s has marked at position %d ",lastName,lastpos);
                printf("\n       %s\'s Turn -> %c ",name,mark);
                printf("\n       Enter position number : ");
                scanf("%d",&pos);
                if(getPosition(mat,n,pos))
                {
                    *getPosition(mat,n,pos)=mark;
                    break;
                }
            }
            mark='O';
            strcpy(lastName,name);
            strcpy(name,name2);
        }
        else if(mark=='O')
        {
            lastpos=evilCompMove(mat,n);
            mark='X';
            strcpy(lastName,name);
            strcpy(name,name1);
        }

    }
    if(checkIfWin(mat,3))
    {
        system("cls");
        heading();
        printf("\n       Player 1 : %s ( X )",name1);
        printf("\n       Player 2 : %s ( O )",name2);
        displayBoard(mat,3);
        printf("\n       %s Wins \n",lastName);
    }
    if(checkIfDraw(mat,3))
    {
        system("cls");
        heading();
        printf("\n       Player 1 : %s ( X )",name1);
        printf("\n       Player 2 : %s ( O )",name2);
        displayBoard(mat,3);
        printf("\n       Match Draw \n");
    }
    gotoMainMenu();
}
int evilCompMove(char m[][3],int n)
{
    int i,j,cO,cX,flag,ifMarked=0,pos;
    /*---Check the possibility to win---*/
    pos=checkRowWiseToMark(m,n,'O');
    if(pos!=-1)
        return pos;

    pos=checkColumnWiseToMark(m,n,'O');
    if(pos!=-1)
        return pos;

    pos=checkDiagonallyToMark(m,n,'O');
    if(pos!=-1)
        return pos;
    /*---Check the possibility to defend---*/
    //Check Row-wise
    for(i=0;i<n;i++)
    {
        cX=0;
        for(j=0;j<3;j++)
        {
            if(m[i][j]=='X')
                cX++;
        }
        if(cX==2)
        {
            for(j=0;j<3;j++)
            {
                if(m[i][j]!='X')
                    break;
            }
            if(m[i][j]!='O')
            {
                m[i][j]='O';
                ifMarked=1;
                pos=getPositionNumber(i,j);
            }
        }
    }
    //Check Column-wise
    for(i=0;i<n;i++)
    {
        cX=0;
        for(j=0;j<3;j++)
        {
            if(m[j][i]=='X')
                cX++;
        }
        if(cX==2)
        {
            for(j=0;j<3;j++)
            {
                if(m[j][i]!='X')
                    break;
            }
            if(m[j][i]!='O')
            {
                m[j][i]='O';
                ifMarked=1;
                pos=getPositionNumber(j,i);
            }
        }
    }
    //Check Left Diagonal
    cX=0;
    for(i=0;i<n;i++)
    {
        if(m[i][i]=='X')
            cX++;
    }
    if(cX==2)
    {
        for(i=0;i<3;i++)
        {
            if(m[i][i]!='X')
                break;
        }
        if(m[i][i]!='O')
        {
            m[i][i]='O';
            ifMarked=1;
            pos=getPositionNumber(i,i);
        }
    }
    //Check Right Diagonal
    cX=0;
    for(i=0;i<n;i++)
    {
        for(j=0;j<3;j++)
        {
            if(i+j==2)
            {
                if(m[i][j]=='X')
                    cX++;
            }
        }
    }
    if(cX==2)
    {
        flag=0;
        for(i=0;i<n;i++)
        {
            for(j=0;j<3;j++)
            {
                if(i+j==2)
                {
                    if(m[i][j]!='X')
                    {
                        flag=1;
                        break;
                    }
                }
            }
            if(flag==1)
                break;
        }
        if(m[i][j]!='O')
        {
            m[i][j]='O';
            ifMarked=1;
            pos=getPositionNumber(i,j);
        }
    }
    if(ifMarked==1)
        return pos;
    /*---If there is no possibility to win or defend---*/
   return(checkRandomToMark(m,n));
}
void gamePlayFriend(char mat[][3],int n)
{
    char name1[30],name2[30];
    /* First Time*/
    heading();
    printf("\n       Enter Player 1\'s Name : ");
    fflush(stdin);
    fgets(name1,30,stdin);
    name1[strlen(name1)-1]='\0';
    printf("       Enter Player 2\'s Name : ");
    fflush(stdin);
    fgets(name2,30,stdin);
    name2[strlen(name2)-1]='\0';
    /*-----------------------------------------------------*/
    int pos,lastpos=-1;
    char mark='X';
    char name[30],lastName[30];
    strcpy(name,name1);
    while(!checkIfWin(mat,3) && !checkIfDraw(mat,3))
    {
        system("cls");
        heading();
        printf("\n       Player 1 : %s ( X )",name1);
        printf("\n       Player 2 : %s ( O )",name2);
        displayBoard(mat,3);
        if(lastpos!=-1)
            printf("\n       %s has marked at position %d ",lastName,lastpos);
        printf("\n       %s\'s Turn -> %c ",name,mark);
        printf("\n       Enter position number : ");
        scanf("%d",&pos);
        if(getPosition(mat,n,pos))
        {
            *getPosition(mat,n,pos)=mark;
            lastpos=pos;
            if(mark=='X')
            {
                mark='O';
                strcpy(lastName,name);
                strcpy(name,name2);
            }
            else if(mark=='O')
            {
                mark='X';
                strcpy(lastName,name);
                strcpy(name,name1);
            }
        }
    }
    if(checkIfWin(mat,3))
    {
        system("cls");
        printf("Player 1");
        heading();
        printf("\n       Player 1 : %s ( X )",name1);
        printf("\n       Player 2 : %s ( O )",name2);
        displayBoard(mat,3);
        printf("\n       %s Wins \n",lastName);
    }
    if(checkIfDraw(mat,3))
    {
        system("cls");
        heading();
        printf("\n       Player 1 : %s ( X )",name1);
        printf("\n       Player 2 : %s ( O )",name2);
        displayBoard(mat,3);
        printf("\n       Match Draw \n");
    }
    gotoMainMenu();
}
void displayBoard(char m[][3],int n)
{
    int i,j;
    printf(" \n\t ._______._______._______.\n");
    for(i=0;i<n;i++)
    {
        printf("\t |       |       |       |\n\t ");
        for(j=0;j<n;j++)
            printf("|   %c   ",m[i][j]);
        printf("|\n\t |_______|_______|_______|\n");
    }
}
int checkIfWin(char m[][3],int n)
{
     int i,j;
    //Diagonals
    if(m[0][0]==m[1][1] && m[1][1]==m[2][2])
        return 1;
    if(m[0][2]==m[1][1] && m[1][1]==m[2][0])
        return 1;
    //Rows
    if(m[0][0]==m[0][1] && m[0][1]==m[0][2])
        return 1;
    if(m[1][0]==m[1][1] && m[1][1]==m[1][2])
        return 1;
    if(m[2][0]==m[2][1] && m[2][1]==m[2][2])
        return 1;
    //Columns
    if(m[0][0]==m[1][0] && m[1][0]==m[2][0])
        return 1;
    if(m[0][1]==m[1][1] && m[1][1]==m[2][1])
        return 1;
    if(m[0][2]==m[1][2] && m[1][2]==m[2][2])
        return 1;
    //Else
    return 0;
}
int checkIfDraw(char m[][3],int n)
{
    int i,j,c=0;
    for(i=0;i<3;i++)
    {
        for(j=0;j<3;j++)
        {
            if(m[i][j]=='X' || m[i][j]=='O')
                c++;
        }
    }
    if(c==9 && !checkIfWin(m,n))
        return 1;
    return 0;
}
int checkDiagonallyToMark(char m[][3],int n,char mark)
{
    int i,j,c=0,flag;
    char mark2;
    if(mark=='X')
        mark2='O';
    if(mark=='O')
        mark2='X';
    //Check Left Diagonal
    for(i=0;i<n;i++)
    {
        if(m[i][i]==mark)
            c++;
    }
    if(c==2)
    {
        for(i=0;i<3;i++)
        {
            if(m[i][i]!=mark)
                break;
        }
        if(m[i][i]!=mark2)
        {
            m[i][i]='O';
            return  getPositionNumber(i,i);
        }
    }
    //Check Right Diagonal
    c=0;
    for(i=0;i<n;i++)
    {
        for(j=0;j<3;j++)
        {
            if(i+j==2)
            {
                if(m[i][j]==mark)
                    c++;
            }
        }
    }
    if(c==2)
    {
        flag=0;
        for(i=0;i<n;i++)
        {
            for(j=0;j<3;j++)
            {
                if(i+j==2)
                {
                    if(m[i][j]!=mark)
                    {
                        flag=1;
                        break;
                    }
                }
            }
            if(flag==1)
                break;
        }
        if(m[i][j]!=mark2)
        {
            m[i][j]='O';
            return  getPositionNumber(i,j);
        }
    }
    return -1;
}
int checkColumnWiseToMark(char m[][3],int n,char mark)
{
    int i,j,c=0;
    char mark2;
    if(mark=='X')
        mark2='O';
    if(mark=='O')
        mark2='X';
    for(i=0;i<n;i++)
    {
        c=0;
        for(j=0;j<3;j++)
        {
            if(m[j][i]==mark)
                c++;
        }
        if(c==2)
        {
            for(j=0;j<3;j++)
            {
                if(m[j][i]!=mark)
                    break;
            }
            if(m[j][i]!=mark2)
            {
                m[j][i]='O';
                return  getPositionNumber(j,i);
            }
        }
    }
    return -1;
}
int checkRowWiseToMark(char m[][3],int n,char mark)
{
    int i,j,c=0;
    char mark2;
    if(mark=='X')
        mark2='O';
    if(mark=='O')
        mark2='X';
    for(i=0;i<n;i++)
    {
        c=0;
        for(j=0;j<3;j++)
        {
            if(m[i][j]==mark)
                c++;
        }
        if(c==2)
        {
            for(j=0;j<3;j++)
            {
                if(m[i][j]!=mark)
                    break;
            }
            if(m[i][j]!=mark2)
            {
                m[i][j]='O';
                return  getPositionNumber(j,i);
            }
        }
    }
    return -1;
}
int checkRandomToMark(char m[][3],int n)
{
    int pos;
    srand(time(NULL));
    int upper=9;
    int lower=1;
    while(1)
    {
        pos=(rand()%(upper-lower+1))+lower;
        if(getPosition(m,n,pos))
        {
            *getPosition(m,n,pos)='O';
            return pos;
        }
    }
    return -1;
}
char* getPosition(char m[][3],int n,int pos)
{
    int i,j;
    if(pos<1 || pos>9)
        return NULL;
    for(i=0;i<n;i++)
    {
        for(j=0;j<n;j++)
        {
            if(m[i][j]==(char)48+pos)
                return &m[i][j];
        }
    }
    return NULL;
}
int getPositionNumber(int row,int col)
{
    int i,j,p=0;
    if(row<0 || row>2 || col<0 || col>2)
        return -1;
    for(i=0;i<3;i++)
    {
        for(j=0;j<3;j++)
        {
            p++;
            if(i==row && j==col)
                return p;
        }
    }
}
/*----------------------------------------------------------------------*/
