#include<stdio.h>
#include<stdlib.h>

void powerb(int color ,int board[8][8] , int power[8][8] , float score[8][8]){
        int black, white , shart , SHART , x , y;
    float s = 0;
    if (color == 1)///aur color(color of the program plays) in this function is forced black
    {
        black = 1;
        white = 2;
    }
    else 
    {
        black = 2;
        white = 1;
    }
    for (int i = 0; i < 8; i++)
    {
        for (int j = 0; j < 8; j++)
        {
            shart = 0;
            SHART = 0;
            if (board[i][j] == 0)
            {
                for ( x = j , y = i , s = 0 , shart = 0 ; x < 8 && board[i][++x] != black && board[i][x] != 0; s++) //right
                { 
                    shart = 1;
                }
                if(board[i][x] != black || x == 8)
                    shart = 0;
                if (shart == 1)
                {
                    SHART = 1;
                    //s--;
                }
                else
                    s = 0;
                score[i][j] += s;
                for ( x = j , y = i , s = 0 , shart = 0 ; x >= 0 && board[i][--x] != black && board[i][x] != 0; s++) ////left
                {
                    shart = 1;
                }
                if(board[i][x] != black || x == -1 )
                    shart = 0;
                if (board[i][x] != black)
                    shart = 0;
                if (shart == 1)
                {
                    SHART = 1;
                    //s--;
                }
                else
                    s = 0;
                score[i][j] += s;
                for (x = j , y = i , s = 0 , shart = 0 ; y >= 0 && board[--y][j] != black && board[y][j] != 0 ; s++) ////////up
                { 
                    shart = 1;
                }
                if(board[y][j] != black || y == -1)
                    shart = 0;
                if (shart == 1)
                {
                    SHART = 1;
                    //s--;
                }
                else
                    s = 0;
                score[i][j] += s;
                for ( x = j , y = i , s = 0 , shart = 0 ; y < 8 && board[++y][j] != black && board[y][j] != 0 ; s++)//////down
                { 
                        shart = 1;
                }
                if (board[y][j] != black || y == 8)
                    shart = 0;
                if (shart == 1)
                {
                    SHART = 1;
                    //s--;
                }
                else
                    s = 0;
                score[i][j] += s;
                for ( x = j , y = i , s = 0 , shart = 0 ; y >= 0 && x < 8 && board[--y][++x] != black && board[y][x] != 0 ; s++)/////up and right
                { 
                    shart = 1;
                }
                if (board[y][x] != black || y == -1 || x == 8)
                    shart = 0;
                if (shart == 1)
                {
                    SHART = 1;
                    //s--;
                }
                else
                    s = 0;
                s = s * 1.5; /////zarib
                score[i][j] += s;
                for ( x = j , y = i , s = 0 , shart = 0 ; y >= 0 && x >= 0 && board[--y][--x] != black && board[y][x] != 0 ; s++) /////up and left
                {
                    shart = 1;
                }
                if (board[y][x] != black || y == -1 || x == -1 )
                    shart = 0;
                if (shart == 1)
                {
                    SHART = 1;
                    //s--;
                }
                else
                    s = 0;
                s = s * 1.5; /////zarib
                score[i][j] += s;
                for (  x = j , y = i , s = 0 , shart = 0 ; y < 8 && x >= 0 && board[++y][--x] != black && board[y][x] != 0 ; s++)/////down and left
                {
                    shart = 1;
                }
                if (board[y][x] != black || y == 8 || x == -1 )
                    shart = 0;
                if (shart == 1)
                {
                    SHART = 1;
                    //s--;
                }
                else
                    s = 0;
                s = s * 1.5; ///////zarib
                score[i][j] += s;
                for(  x = j , y = i , s = 0 , shart = 0 ; y < 8 && x < 8 && board[++y][++x] != black && board[y][x] != 0 ; s++)/////down and right
                { 
                        shart = 1;
                }
                if (board[y][x] != black || y == 8 || x == 8)
                    shart = 0;
                if (shart == 1)
                {
                    SHART = 1;
                    //s--;
                }
                else
                    s = 0;
                s = s * 1.5; //////zarib
                score[i][j] += s;
                s = 0;
                if ((i == 0 && j == 7) || (i == 0 && j == 0) || (i == 7 && j == 7) || (i == 7 && j == 0))   score[i][j] = score[i][j] * 10;
                else if(i==0 || j==0 || i==7 || j==7)   score[i][j] = score[i][j] * 1.5;
            }
            power[i][j] = SHART;
        }
    }
}
void PRINT(int board[8][8] , int power[8][8] , float score[8][8]){
    for(int i=0;i<8;i++){
        for(int j=0;j<8;j++){
            printf("%d ",board[i][j]);
        }
        printf("\n");
    }
    printf("\n");
     for(int i=0;i<8;i++){
        for(int j=0;j<8;j++){
            if(power[i][j]==0){
                if(board[i][j]==1) printf("%c ",2);
                else if(board[i][j]==2)printf("%c ",1);
                else printf("  ");
            }
            else printf("%d ",power[i][j]);
        }
        printf("\n");
    }
    printf("\n");
    for(int i=0;i<8;i++){
        for(int j=0;j<8;j++){
            if(power[i][j]==1){
                printf("%d,%d:%f\n",j,i,score[i][j]);
            }
        }
    }
    printf("\n");

}
void change(int a,int b,int color,int board[8][8],int board2[8][8]){
    int black,white;
    if(color==1){
        black=1;
        white=2;
    }
    else{
        black=2;
        white=1;
    }
    int x=b;
    int y=a;
    for ( x = b , y = a ; x <  8 && board[a][++x]!=black && board[a][x]==white && board[a][x]!=0 ;  ){}/////right
    if ( board[a][x] == black){
        for ( ; board[a][--x] != 0 ; board2[a][x]=black ){}
    }
    for ( x = b , y = a ; x >= 0 && board[a][--x]!=black && board[a][x]==white && board[a][x]!=0 ; ){}/////left
    if ( board[a][x] == black){
        for ( ; board[a][++x] != 0 ; board2[a][x]=black ){}
    }
    for ( x = b , y = a ; y >= 0 && board[--y][b]!=black && board[y][b]==white && board[y][b]!=0 ;  ){}/////up
    if ( board[y][b] == black){
        for ( ; board[++y][b] != 0 ; board2[y][b]=black ){}
    }
    for ( x = b , y = a ; y <  8 && board[++y][b]!=black && board[y][b]==white && board[y][b]!=0 ;  ){}/////down
    if ( board[y][b] == black){
        for ( ; board[--y][b] != 0 ; board2[y][b]=black ){}
    }
    for ( x = b , y = a ; y >= 0 && x <  8 && board[--y][++x]!=black && board[y][x]==white && board[y][x]!=0 ;  ){}/////up and right
    if ( board[y][x] == black){
        for ( ; board[++y][--x] != 0 ; board2[y][x]=black ){}
        }
    for ( x = b , y = a ; y >= 0 && x >= 0 && board[--y][--x]!=black && board[y][x]==white && board[y][x]!=0 ;  ){}/////up and left
    if ( board[y][x] == black){
        for ( ; board[++y][++x] != 0 ; board2[y][x]=black ){}
    }
    for ( x = b , y = a ; y <  8 && x >= 0 && board[++y][--x]!=black && board[y][x]==white && board[y][x]!=0 ;  ){}/////down and left
    if ( board[y][x] == black){
        for ( ; board[--y][++x] != 0 ; board2[y][x]=black ){}
    }
    for ( x = b , y = a ; y <  8 && x <  8 && board[++y][++x]!=black && board[y][x]==white && board[y][x]!=0 ;  ){}/////down and right
    if ( board[y][x] == black){
        for ( ; board[--y][--x] != 0 ; board2[y][x]=black ){}
    }
    board2[a][b]=black;
}

int main(int argc,char **argv)
{
    int board[8][8],power[8][8],board2[8][8];
    float score[8][8];
    int power2[8][8];
    float score2[8][8];

    for(int i=0;i<8;i++){
        for(int j=0;j<8;j++){
            board[i][j]=argv[i+1][j]-48;
            board2[i][j]=argv[i+1][j]-48;
            score[i][j]=0;
            score2[i][j]=0;
        }
    }
    int color=argv[9][0]-48;
    /////////////////////////////////////////////////////////////
        powerb(color,board,power,score);
        //PRINT(board,power,score);
        int maxScoreI=0,maxScoreJ=0;
        for(int i=0;i<8;i++){
            for(int j=0;j<8;j++){
                if(score[maxScoreI][maxScoreJ]<score[i][j]){
                    maxScoreI=i;
                    maxScoreJ=j;
                } 
            }
        }
        //printf("maxScore= %d,%d\n",maxScoreJ,maxScoreI);

        for(int i=0;i<8;i++){
            for(int j=0;j<8;j++){
                if(power[i][j]==1) {
                    for(int m=0;m<8;m++){
                        for(int n=0;n<8;n++){
                            board2[m][n]=board[m][n];
                        }
                    }
                    change(i,j,color,board,board2);
                    ///////////////////////////////////////print
                    /*
                    for(int m=0;m<8;m++){
                        for(int n=0;n<8;n++){
                            printf("%d ",board2[m][n]);
                        }
                        printf("\n");
                    }
                    printf("\n");
                    */
                    /////////////////////////////////////////
                    int c;
                    if(color==1) c=2;
                    else c=1;
                    powerb(c,board2,power2,score2);
                    int maxScore2I=0,maxScore2J=0;
                    for(int m=0;m<8;m++){
                        for(int n=0;n<8;n++){
                            if(score2[maxScore2I][maxScore2J]<score2[m][n]){
                                maxScore2I=m;
                                maxScore2J=n;
                            }
                        }
                    }
                    score[i][j]=score[i][j]-score2[maxScore2I][maxScore2J];
                    //printf("maxScore= %d,%d = %f ,,,,, %f\n",maxScore2J,maxScore2I,score2[maxScore2I][maxScore2J],score[i][j]);
                    for(int m=0;m<8;m++){
                        for(int n=0;n<8;n++){
                            score2[m][n]=0;
                        }
                    }
                }
            }
        }
        int maxI=0,maxJ=0;
        for(int i=0;i<8;i++){
            for(int j=0;j<8;j++){
                if(power[i][j]==0) score[i][j]-=100;
                if(score[maxI][maxJ]<=score[i][j]){
                    maxI=i;
                    maxJ=j;
                }
            }
        }
        printf("%d %d",maxJ,maxI);

    return 0;
}