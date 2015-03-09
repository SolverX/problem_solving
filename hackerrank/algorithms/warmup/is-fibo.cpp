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
map<ull,bool> isFibonacci;
void precal(){
	ull a=0,b=1;
	ull fib = a+b;
	isFibonacci[a]=true;
	isFibonacci[b]=true;
	while(fib<=10000000000){
		a = b;
		b = fib;
		fib = a+b;
		isFibonacci[fib]=true;
		//cout<<fib<<endl;
	}
}
int main(){
	freopen("in.txt","rt",stdin);
	int T;
	precal();
	cin>>T;
	while(T--){
		ull N;
		cin>>N;
		if(isFibonacci[N]){
			cout<<"IsFibo"<<endl;
		}else{
			cout<<"IsNotFibo"<<endl;
		}
	}
	return 0;
}