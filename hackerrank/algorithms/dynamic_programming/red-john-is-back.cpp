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
#include <bitset>
using namespace std;
#define VISITED 2
#define EXPLORED 1
#define UN_VISISTED 0

typedef unsigned long long ull;
typedef unsigned long ul;
typedef vector<int> vi;
typedef pair<int,int> ii;
typedef vector<ii> vii;
int countWays(int M){
	//cout<<M<<endl;
	if(M<0) return 0;
	if(M==0) return 1;
	//cout<<N<<" "<<M<<endl;
	return countWays(M-1)+countWays(M-4);
}
bitset<217287> isPrime;
map<ull,int> primeCount;
void sieve(){
isPrime.set(); // set all bits to 1
isPrime[0] = isPrime[1] = 0;
primeCount[0]=primeCount[1]=0;
int cnt=0;
	for(ull i=2;i<=217286;i++){
		if(isPrime[i]){
			for(ull j=i*i;j<=217286;j+=i){
				isPrime[j]=0;
			}
			cnt++;
			//cout<<i<<endl;
		}
		primeCount[i]=cnt;
	}
}
int main(){
	freopen("in.txt","rt",stdin);
	sieve();
	int T;
	cin>>T;
	while(T--){
		int M;
		cin>>M;
		//cout<<M<<endl;
		int ways = countWays(M);
		cout<<primeCount[ways]<<endl;
	}
	return 0;
}