#include <iostream>
#include <cstring>
#include <cstdio>
#include <string>
#include <algorithm>
#include <cstdlib>
#include <cmath>
#include <utility>
#include <cctype>
#include <stack>
#include <queue>
#include <list>
#include <vector>
using namespace std;

#define FILE_INPUT false

#define SIZE 5000

typedef pair<int,int> ii;
typedef vector<int> vi;
typedef vector<ii> vii;

int dx[]={-1,0,0,1};
int dy[]={0,-1,1,0};

char s[SIZE][SIZE];
int length = 0,cnt = 0;

void floodFill(int x,int y){
	if(x<0 || y<0 || x>=length || y>=length){
		return;
	}
	s[x][y]='*';
	for(int i=0;i<4;i++){
		int tx=x+dx[i],ty=y+dy[i];
		if(tx>=0 && ty>=0 && tx<length && ty<length){
			if(s[tx][ty]==' '){
				floodFill(tx,ty);
			}else if(s[tx][ty]!='#' && s[tx][ty]!='*' && s[tx][ty]!='\0' && s[tx][ty]!='_'){
				s[x][y]= '#';
			}
		}
	}
}

int main(){
	// if(FILE_INPUT)
	// 	freopen("in.txt","r",stdin);
	int T;
	cin>>T;
	gets(s[0]);
	while(T--){
		length=cnt=0;
		int sx=0,sy=0;
		while(gets(s[cnt]) && s[cnt][0]!='_')
		{
			//cout<<s[cnt]<<endl;
			length = length<strlen(s[cnt])?strlen(s[cnt]):length;
			for(int j=0;j<strlen(s[cnt]);j++){
				if(s[cnt][j]=='*')
					sx=cnt,sy=j;
			}
			cnt++;
		}
		length+=1;
		for(int i=0;i<cnt;i++){
			for(int j=strlen(s[i]);j<length;j++){
				s[i][j]=' ';
			}
			s[i][length]='\0';
		}
		
		floodFill(sx,sy);
		//cout<<length<<endl;
		for(int i=0;i<cnt+1;i++){
			bool done = false;
			for(int j=length-1;j>=0;j--){
				if(s[i][j]=='*')
					s[i][j]=' ';
				if(!done && s[i][j]==' '){
					s[i][j]='\0';
				}else{
					done=true;
				}
			}
		}
		for(int i=0;i<cnt+1;i++){
			cout<<s[i]<<endl;
		}
	}

	return 0;
}