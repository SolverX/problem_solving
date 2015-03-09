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
	vi list;
	int N,K;
	cin>>N>>K;
	
	while(N--){
		int value;
		cin>>value;
		list.push_back(value);
	}
	K--;
	sort(list.begin(),list.end());
	int minValue = 	1000000000;
	for(int i=0;i+K <list.size();i++){
		minValue = min (list[i+K]-list[i],minValue);
	}
	cout<<minValue<<endl;
	return 0;
}