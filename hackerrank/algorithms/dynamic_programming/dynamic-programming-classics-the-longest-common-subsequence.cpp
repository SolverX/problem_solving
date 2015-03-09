#include <iostream>
#include <algorithm>
#include <vector>
#include <map>
#include <string>
#include <utility>
#include <cstdio>
#include <cstring>
#include <cmath>
#include <cctype>
#include <cstdlib>
using namespace std;
#define VISITED 2
#define EXPLORED 1
#define UN_VISISTED 0

typedef unsigned long long ull;
typedef unsigned long ul;
typedef vector<int> vi;
typedef pair<int,int> ii;
typedef vector<ii> vii;
int m,n;
int A[2001];
int B[2001];
int DP[2001][2001];
std::vector<int> v;
void backtrack(int i,int j){
	if(i==m+1 || j==n+1);
	else if (A[i]==B[j]){ 
		v.push_back(A[i]);
		backtrack(i+1,j+1);
		return;
	}
	else{
		if(DP[i][j+1] > DP[i+1][j]){
			backtrack(i,j+1);
			return;
		}
		else{
			 backtrack(i+1,j);
			return;
		}
	}
}
int main(){
	freopen("in.txt","rt",stdin);
	cin>>m>>n;
	for(int i=1;i<=m;i++)
		cin>>A[i];
	for(int j=1;j<=n;j++)
		cin>>B[j];

	memset(DP,0,sizeof(DP));
	for(int i=1;i<=m;i++)
		for(int j=1;j<=n;j++) {
			if(A[i]==B[j]) DP[i][j] = DP[i-1][j-1] + 1;
			else DP[i][j]= max(DP[i][j-1],DP[i-1][j]);
		}

	backtrack(1,1);
	for(int i=0;i<v.size();i++){
		if(i)
			cout<<" ";
		cout<<v[i];
	}
	cout<<endl;
	return 0;
}