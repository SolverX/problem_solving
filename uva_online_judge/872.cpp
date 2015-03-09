#include <iostream>
#include <cstring>
#include <cstdio>
#include <string>
#include <algorithm>
#include <cstdlib>
#include <cmath>
#include <map>
#include <utility>
#include <cctype>
#include <stack>
#include <queue>
#include <list>
#include <vector>
using namespace std;

#define FILE_INPUT true

typedef pair<int,int> ii;
typedef vector<int> vi;
typedef vector<ii> vii;

#define MAX(a,b) a>b?a:b

map<char,int> LocationToNumber;
map<int,char> NumberToLocation;

int numberCount = 0;
vector<vi> ADJList;
map<ii,bool> isConnected;
map<int,bool> isVisited;
vi path;

void backtrack(int u){
	if(path.size() == numberCount){
		for(int i=0;i<path.size();i++){
			cout<<path[i]<<" ->";
		}
		cout<<endl;
		return;
	}
	
	//cout<<path.size()<<endl;
	for(int i=0;i<ADJList[u].size();i++){
		int v = ADJList[u][i];
		if(!isVisited[v]){
			isVisited[v]=true;
			path.push_back(v);
			backtrack(v);
			isVisited[v]=false;
			path.pop_back();
		}

	}
	//isVisited[u]=false;
}

bool isReachable(int u,int goal){
	if(u==goal){
		return true;
	}
	if(isVisited[u]){
		return false;
	}
	isVisited[u]=true;
	int result = false;
	for(int i=0;i<ADJList[u].size();i++){
		int v = ADJList[u][i];
		if(!isVisited[v]){
			
			//path.push_back(v);
			result = MAX(result,isReachable(v,goal));
			//isVisited[v]=false;
			//path.pop_back();
		}

	}
	isVisited[u]=false;
	return result;
}

int main(){
	if(FILE_INPUT)
		freopen("in.txt","r",stdin);
	int T;
	char line[10000];
	scanf("%d\n",&T);
	while(T--){
		gets(line);
		//puts(line);
		char *pch = strtok(line," ");

		while(pch!=NULL){
			numberCount++;
			LocationToNumber[pch[0]] = numberCount;
			NumberToLocation[numberCount] = pch[0];
			pch=strtok(NULL," ");
		}
		gets(line);
		cout<<numberCount<<endl;
		ADJList.assign(numberCount+1,vi());
		pch = strtok(line," ");

		while(pch!=NULL){
			int a = LocationToNumber[pch[0]];
			int b = LocationToNumber[pch[2]];
			ADJList[a].push_back(b);
			isConnected[ii(a,b)]=true;
			pch=strtok(NULL," ");
		}
		cout<<isReachable(2,4)<<endl;
		for(int i=1;i<=numberCount;i++){
			for(int j=i+1;j<=numberCount;j++){
				if(!isConnected[ii(i,j)] && !isConnected[ii(j,i)] && !isReachable(i,j) ){
					isConnected[ii(i,j)] = true;
					isConnected[ii(j,i)] = true;
					ADJList[i].push_back(j);
					ADJList[j].push_back(i);
				}
			}
		}
		
		//isVisited[1]=true;
		for(int i=1;i<=numberCount;i++){
			isVisited[i]=true;
			path.push_back(i);
			backtrack(i);
			isVisited[i]=false;
			path.pop_back();
		}

		//puts(line);
	}

	return 0;
}