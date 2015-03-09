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

#define INF 10000000
typedef unsigned long long ull;
typedef unsigned long ul;
typedef vector<int> vi;
typedef pair<int,int> ii;
typedef vector<ii> vii;

int n,a[3000];
int DP[2006][2006];

int maxPossible(int pos,int value){
	//cout<<pos<<","<<value<<endl;
	if(value<0) return -INF;
	if(pos>=n || value==0) return 0;
	
	if(DP[pos][value]) return DP[pos][value];
	//cout<<value<<",";
	return DP[pos][value]=max(a[pos] + max(maxPossible(pos+1,value-a[pos]),maxPossible(pos,value-a[pos])) , maxPossible(pos+1,value));
}
int main(){
	freopen("in.txt","rt",stdin);
	int T;
	cin>>T;
	while(T--){
		int k;
		cin>>n>>k;
		memset(DP,0,sizeof(DP));
		for(int i=0;i<n;i++)
			cin>>a[i];
		cout<<maxPossible(0,k)<<endl;

	}
	return 0;
}