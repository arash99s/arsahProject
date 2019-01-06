#include<stdio.h>
#include<stdlib.h>
int board[8][8],power[8][8],score[8][8];
void powerBlack(){
    for(int i=0;i<8;i++){
        for(int j=0;j<8;j++){
            int shart=0,SHART=0;
            if(board[i][j]==0){
                int x=j;
                int y=i;
                
                while(x<8 && board[i][x]!=1){/////right
                    if(board[i][x]==2) shart=1;
                    x++;
                    if(board[i][x]==0){
                        shart=0;
                        break;
                    }
                }
                if(board[i][x]!=1) shart=0;
                if(shart==1) SHART=1;
                x=j;
                while(x>=0 && board[i][x]!=1){/////left
                    if(board[i][x]==2) shart=1;
                    x--;
                    if(board[i][x]==0){
                        shart=0;
                        break;
                    }
                }
                if(board[i][x]!=1) shart=0;
                if(shart==1) SHART=1;
                
                while(y>=0 && board[y][j]!=1){/////up
                    if(board[y][j]==2) shart=1;
                    y--;
                    if(board[y][j]==0){
                        shart=0;
                        break;
                    }
                }
                if(board[y][j]!=1) shart=0;
                if(shart==1) SHART=1;
                y=i;
                while(y<8 && board[y][j]!=1){/////down
                    if(board[y][j]==2) shart=1;
                    y++;
                    if(board[y][j]==0){
                        shart=0;
                        break;
                    }
                }
                if(board[y][j]!=1) shart=0;
                if(shart==1) SHART=1;
                x=j;
                y=i;
                
                while(y>=0 && x<8 && board[y][x]!=1){/////up and right
                    if(board[y][x]==2) shart=1;
                    x++;
                    y--;
                    if(board[y][x]==0){
                        shart=0;
                        break;
                    }
                }
                if(board[y][x]!=1) shart=0;
                if(shart==1) SHART=1;
                x=j;
                y=i;
                while(y>=0 && x>=0 && board[y][x]!=1){/////up and left
                    if(board[y][x]==2) shart=1;
                    x--;
                    y--;
                    if(board[y][x]==0){
                        shart=0;
                        break;
                    }
                }
                if(board[y][x]!=1) shart=0;
                if(shart==1) SHART=1;
                x=j;
                y=i;
                while(y<8 && x>=0 && board[y][x]!=1){/////down and left
                    if(board[y][x]==2) shart=1;
                    x--;
                    y++;
                    if(board[y][x]==0){
                        shart=0;
                        break;
                    }
                }
                if(board[y][x]!=1) shart=0;
                if(shart==1) SHART=1;
                x=j;
                y=i;
                while(y<8 && x<8 && board[y][x]!=1){/////down and right
                    if(board[y][x]==2) shart=1;
                    x++;
                    y++;
                    if(board[y][x]==0){
                        shart=0;
                        break;
                    }
                }
                if(board[y][x]!=1) shart=0;
                if(shart==1) SHART=1;
                
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
    powerBlack();
    PRINT();
    for(int i=0;i<8;i++){
        for(int j=0;j<8;j++){
            if(power[i][j]==1){
                //printf("%d %d",j,i);
                i=8;
                j=8;
            } 
        }
    }


    return 0;
}
