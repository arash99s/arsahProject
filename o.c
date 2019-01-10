#include<stdio.h>
#include<stdlib.h>
int board[8][8],power[8][8];
float score[8][8];
void powerBlack(int color){
    int black,white;
    if(color==1){
        black=1;
        white=2;
    }
    else{
        black=2;
        white=1;
    }
    for(int i=0;i<8;i++){
        for(int j=0;j<8;j++){
            int shart=0,SHART=0;
            if(board[i][j]==0){
                int x=j;
                int y=i;
                float s=0;
                while(x<8 && board[i][x]!=black){/////right
                    if(board[i][x]==white) shart=1;
                    x++;
                    s++;
                    if(board[i][x]==0){
                        shart=0;
                        break;
                    }
                }
                if(board[i][x]!=black) shart=0;
                if(shart==1){
                    SHART=1;
                    s--;
                } 
                else s=0;
                score[i][j]+=s;
                s=0;
                x=j;

                while(x>=0 && board[i][x]!=black){/////left
                    if(board[i][x]==white) shart=1;
                    x--;
                    s++;
                    if(board[i][x]==0){
                        shart=0;
                        break;
                    }
                }
                if(board[i][x]!=black) shart=0;
                if(shart==1){
                    SHART=1;
                    s--;
                }
                else s=0;
                score[i][j]+=s;
                s=0;
                
                while(y>=0 && board[y][j]!=black){/////up
                    if(board[y][j]==white) shart=1;
                    y--;
                    s++;
                    if(board[y][j]==0){
                        shart=0;
                        break;
                    }
                }
                if(board[y][j]!=black) shart=0;
                if(shart==1){
                    SHART=1;
                    s--;
                }
                else s=0;
                score[i][j]+=s;
                s=0;
                y=i;

                while(y<8 && board[y][j]!=black){/////down
                    if(board[y][j]==white) shart=1;
                    y++;
                    s++;
                    if(board[y][j]==0){
                        shart=0;
                        break;
                    }
                }
                if(board[y][j]!=black) shart=0;
                if(shart==1){
                    SHART=1;
                    s--;
                }
                else s=0;
                score[i][j]+=s;
                s=0;
                x=j;
                y=i;
                
                while(y>=0 && x<8 && board[y][x]!=black){/////up and right
                    if(board[y][x]==white) shart=1;
                    x++;
                    y--;
                    s++;
                    if(board[y][x]==0){
                        shart=0;
                        break;
                    }
                }
                if(board[y][x]!=black) shart=0;
                if(shart==1){
                    SHART=1;
                    s--;
                }
                else s=0;
                s=s*1.5;/////zarib
                score[i][j]+=s;
                s=0;
                x=j;
                y=i;

                while(y>=0 && x>=0 && board[y][x]!=black){/////up and left
                    if(board[y][x]==white) shart=1;
                    x--;
                    y--;
                    s++;
                    if(board[y][x]==0){
                        shart=0;
                        break;
                    }
                }
                if(board[y][x]!=black) shart=0;
                if(shart==1){
                    SHART=1;
                    s--;
                }
                else s=0;
                s=s*1.5;/////zarib
                score[i][j]+=s;
                s=0;
                x=j;
                y=i;

                while(y<8 && x>=0 && board[y][x]!=black){/////down and left
                    if(board[y][x]==white) shart=1;
                    x--;
                    y++;
                    s++;
                    if(board[y][x]==0){
                        shart=0;
                        break;
                    }
                }
                if(board[y][x]!=black) shart=0;
                if(shart==1){
                    SHART=1;
                    s--;
                }
                else s=0;
                s=s*1.5;///////zarib
                score[i][j]+=s;
                s=0;
                x=j;
                y=i;

                while(y<8 && x<8 && board[y][x]!=black){/////down and right
                    if(board[y][x]==white) shart=1;
                    x++;
                    y++;
                    s++;
                    if(board[y][x]==0){
                        shart=0;
                        break;
                    }
                }
                if(board[y][x]!=black) shart=0;
                if(shart==1){
                    SHART=1;
                    s--;
                }
                else s=0;
                s=s*1.5;//////zarib
                score[i][j]+=s;
                s=0;
                
                if((i==0 && j==7) || (i==0 && j==0) || (i==7 && j==7) || (i==7 && j==0)) score[i][j]=score[i][j]*10;
            }
            power[i][j]=SHART;
        }
    }
}
void PRINT(){
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
}

int main(int argc,char **argv)
{
    for(int i=0;i<8;i++){
        for(int j=0;j<8;j++){
            board[i][j]=argv[i+1][j]-48;
            score[i][j]=0;
        }
    }
    int color=argv[9][0]-48;
    /////////////////////////////////////////////////////////////
        powerBlack(color);
        PRINT();
        int maxScoreI=0,maxScoreJ=0;
        for(int i=0;i<8;i++){
            for(int j=0;j<8;j++){
                if(score[maxScoreI][maxScoreJ]<score[i][j]){
                    maxScoreI=i;
                    maxScoreJ=j;
                } 
            }
        }
        printf("maxScore= %d,%d",maxScoreJ,maxScoreI);
        //printf("%d %d",maxScoreJ,maxScoreI);

    return 0;
}