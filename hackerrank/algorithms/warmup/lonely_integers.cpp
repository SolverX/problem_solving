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

int main(){
	freopen("in.txt","rt",stdin);
	int N;
	cin>>N;
	map<int,int> counts;
	while(N--){
		int n;
		cin>>n;
		counts[n]++;
	}	
	for(int i=0;i<=100;i++){
		if(counts[i]==1){
			cout<<i<<endl;
			break;
		}
	}
	return 0;
}