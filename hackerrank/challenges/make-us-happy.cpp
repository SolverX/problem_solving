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
typedef vector<long> vi;
typedef pair<long,long> ii;
typedef vector<ii> vii;
vector<vi> List;
long N,C;
map<long,bool> Used;
map<long,long> DP;

long findNumberOfHappyCouples(long n){
	if(n>N) return 0;
	if(DP[n]) return DP[n];
	long MaxHappy=0;
	//MaxHappy = max(MaxHappy,findNumberOfHappyCouples(n+1));
	for(long i=0;i<List[n].size();i++){
		long table = List[n][i];
		if(!Used[table]){
			Used[table]=true;
			MaxHappy = max(MaxHappy,1+findNumberOfHappyCouples(n+1));
			Used[table] = false;

		}

	}
	//MaxHappy = max(MaxHappy,findNumberOfHappyCouples(n+1));
	return DP[n]=MaxHappy;
}

int main(){
	freopen("in.txt","rt",stdin);
	long T;
	cin>>T;
	while(T--){

		cin>>N>>C;
		List.assign(N+1,vi());
		List.clear();
		Used.clear();
		DP.clear();
		long temp;
		while(cin>>temp  && temp!=-1){
			long table;
			cin>>table;
			List[temp].push_back(table);
		}
		long maxValue = 0;
		for(long i=1;i<=N;i++){
			//DP.clear();
			maxValue=max(findNumberOfHappyCouples(i),maxValue);
		}
		cout<<maxValue<<endl;
	}
	return 0;
}