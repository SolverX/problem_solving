#include <iostream>
#include <cstring>
#include <cstdio>
#include <cstdlib>
#include <cmath>
#include <vector>
#include <algorithm>
#include <map>
#include <stack>
using namespace std;

#define SIZE 10000000
typedef vector<int> vi;

map<int,bool> isnotprime;
map<int,int> primeCount;
vi prime;
void sieve(){
	for(int i=2;i<=SIZE;i++){
		if(!isnotprime[i]){
			for(int j=i+i;j<=SIZE;j+=i)
				isnotprime[j]=true;
		prime.push_back(i);
		}
		//cout<<i<<endl;
	}
}

void primeFactorCount(){

	for(int i=2;i<=SIZE;i++){
		int tmp=i;
		int pos=0;
		int PF = prime[pos];
		while(tmp!=1 && (PF*PF <= tmp) ){
			if(tmp%PF==0) primeCount[i]++;
			while(tmp%PF==0){tmp/=PF;}
			pos++;
			PF = prime[pos];
		}
		if(tmp!=1) primeCount[i]++;
		//if(i==550)
			//cout<<i<<" "<<primeCount[i]<<endl;
		//break;
	}
}
int main(){
	sieve();
	primeFactorCount();
	freopen("in.txt","r",stdin);
	long A,B,K;
	int T,tcase=0;
	cin>>T;
	while(T--){
		int cnt=0;
		cin>>A>>B>>K;
		for(;A<=B;A++)
			cnt+=(primeCount[A]==K);
		printf("Case #%d: %d\n",++tcase,cnt );
	}

}