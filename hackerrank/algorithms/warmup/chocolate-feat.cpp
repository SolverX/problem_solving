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
	int T;
	cin>>T;
	while(T--){
		int N,C,M;
		cin>>N>>C>>M;
		long long totalChocolates = 0;
		long long wrappers = 0;
		while(N>=C){
			totalChocolates += (N/C);
			wrappers += (N/C);
			N-= (N/C) * C;
			N += (wrappers/M)*C;
			wrappers -= (wrappers/M)*M;
			//cout<<N<<endl;
		}
		cout<<totalChocolates<<endl;
	}
	
	return 0;
}