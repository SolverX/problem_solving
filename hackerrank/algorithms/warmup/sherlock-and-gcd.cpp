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

int gcd(int a,int b){
	return b==0?a:gcd(b,a%b);
}
int main(){
	freopen("in.txt","rt",stdin);
	int T;
	cin>>T;
	while(T--){
		int N;
		cin>>N;
		int gcdValue;
		for(int i=0;i<N;i++){
			int A;
			cin>>A;
			if(i==0){
				gcdValue = A;
			}
			if(gcdValue!=1){
				gcdValue = gcd(A,gcdValue);
			}
		}
		if(gcdValue==1){
			cout<<"YES"<<endl;
		}else{
			cout<<"NO"<<endl;
		}

	}
	return 0;
}