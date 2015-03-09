#include <iostream>
#include <cstdio>
#include <cstring>
#include <cstdlib>
#include <string>
#include <algorithm>
#include <vector>
#include <cctype>
#include <stack>
#include <map>
#include <utility>
#include <cmath>
using namespace std;

typedef pair<int,int> ii;
typedef vector<int> vi;
typedef vector<ii> vii;

// Tree Traversal init
vector<vi>	AdjList;

//	0	->	1 , 2 , 3
//	1 	->	2 , 3
//	2	->	0 , 1
//	3	->	1 , 2

void PreTraversal(int u){
	cout<<"->"<<u;
	for(int i=0;i<AdjList[u].size();i++){
		PreTraversal()	
	}
	
}
int main(){
	AdjList[0].push_back(1);
	AdjList[0].push_back(2);
	AdjList[0].push_back(3);

	AdjList[1].push_back(2);
	AdjList[1].push_back(3);

	AdjList[2].push_back(0);
	AdjList[2].push_back(1);

	AdjList[3].push_back(1);
	AdjList[3].push_back(2);


	return 0;
}