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
	int N,M;
	cin>>N>>M;
	ull sum=0;
	while(M--){
		ull a,b,candies;
		cin>>a>>b>>candies;
		sum += (b-a+1)*candies;
	}
	cout<<(sum/N)<<endl;
	return 0;
}