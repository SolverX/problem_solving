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
map<ull,int> countPerfectSquare;
void precal(){
	ull total = 1;
	for(int i=1;i<=31623;i++){
		countPerfectSquare[i*i] = total++;
	}
	
}
int main(){
	freopen("in.txt","rt",stdin);
	precal();
	int T;
	cin>>T;
	while(T--){
		ull a,b;
		cin>>a>>b;
		int val1 = ceil(sqrt(a));
		int val2 = floor(sqrt(b));
		//cout<<val1*val<<" "<<val2*val2<<endl;
		if(val1<=val2){
			cout<<countPerfectSquare[val2*val2]-countPerfectSquare[val1*val1]+1<<endl;
		}else{
			cout<<0<<endl;
		}
	}
	return 0;
}