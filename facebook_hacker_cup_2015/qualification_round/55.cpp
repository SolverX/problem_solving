#include <iostream>
#include <cstring>
#include <cstdio>
#include <cstdlib>
#include <string>
#include <cmath>
#include <algorithm>
#include <map>
using namespace std;
#define SIZE 101
string Map[SIZE];
int M,N;
int startX,startY,endX,endY;
int dx[]={-1,0,0,1},dy[]={0,-1,1,0};


bool isLaserKilled(){
	for(int i=0;i<M;i++)
		for(int j=0;j<N;j++){
			if(Map[i][j]>=0 && Map[i][j]<4)
			{
				switch(Map[i][j]){
					case 0:
						for(int k=j-1;k>=0;k--){
							if(Map[i][k]>=0 && Map[i][k]<4)
								return false;
							if(Map[i][k]=='#')
								return false;
							if(Map[i][k]>'.' && Map[i][k]<='.'+4){
								cout<<"Killed in case 0"<<endl;
								return true;
							}

						}
						break;
					case 1:
						for(int k=i-1;k>=0;k--){
							if(Map[k][j]>=0 && Map[k][j]<4)
								return false;
							if(Map[k][j]=='#')
								return false;
							if(Map[k][j]>'.' && Map[k][j]<='.'+4){
								cout<<"Killed in case 1"<<endl;
								return true;
							}

						}
						break;
					case 2:
						for(int k=j+1;k<N;k++){
							if(Map[i][k]>=0 && Map[i][k]<4)
								return false;
							if(Map[i][k]=='#')
								return false;
							if(Map[i][k]>'.' && Map[i][k]<='.'+4){
								cout<<"killed in case 2"<<endl;
								return true;
							}

						}
						break;
					case 3:
						for(int k=i+1;k<M;k++){
							if(Map[k][j]>=0 && Map[k][j]<4)
								return false;
							if(Map[k][j]=='#')
								return false;
							if(Map[k][j]>'.' && Map[k][j]<='.'+4){
								cout<<"killed in case 3"<<endl;
								//cout<<k<<" "<<j<<endl;
								return true;
							}

						}
						break;
				}
			}	
		}
	return false;
}
void rotateClockwise(){
	for(int i=0;i<M;i++)
		for(int j=0;j<N;j++){
			if(Map[i][j]>=0 && Map[i][j]<4)
				Map[i][j]=(Map[i][j]+1)%4;
		}
}

void rotateAntiClockwise(){
	for(int i=0;i<M;i++)
		for(int j=0;j<N;j++){
			if(Map[i][j]>=0 && Map[i][j]<4)
				Map[i][j]=(4+Map[i][j]-1)%4;
		}
}


int goNext(int x,int y){
	//cout<<x<<" "<<y<<endl;
	if(x==endX && y==endY){
		//rotateAntiClockwise();
		//cout<<"reached"<<endl;
		return 0;
	}
	rotateClockwise();

	if(isLaserKilled()){
		rotateAntiClockwise();
		return 9999;
	}
	
	int steps=99999;
	Map[x][y]++;
	bool nextStepMade=false;
	for(int i=0;i<4;i++){
		int tx=x+dx[i],ty=y+dy[i];
		if(tx>=0 && ty>=0 && tx<M && ty<N && Map[tx][ty]!='#' && Map[tx][ty]!=0 && Map[tx][ty]!=1 && Map[tx][ty]!=2 && Map[tx][ty]!=3  &&Map[tx][ty]<='.'+4 && Map[tx][ty]<Map[x][y]){
			//nextStepMade=true;
			
			steps=min(steps,goNext(tx,ty)+1);
		}

	}
	if(!nextStepMade){
		cout<<"reverse"<<endl;
	}
	rotateAntiClockwise();
	return steps;

}

int main(){
	freopen("in.txt","r",stdin);
	int T,Case=0;
	cin>>T;
	while(T--){
		cin>>M>>N;
		for(int i=0;i<M;i++)
			for(int j=0;j<N;j++){
				cin>>Map[i][j];
				char tmp=Map[i][j];
				switch(tmp){
					case '<':
						Map[i][j]=0;break;
					case '^':
						Map[i][j]=1;break;
					case '>':
						Map[i][j]=2;break;
					case 'v':
						Map[i][j]=3;break;
					case 'S':
						startX=i;startY=j;break;
					case 'G':
						endX=i;endY=j;break;
				}
			}
		Map[startX][startY]='.';
		Map[endX][endY]='.';
		//cout<<char('.'+2)<<endl;
		cout<<goNext(startX,startY)<<endl;
	}
	return 0;
}
