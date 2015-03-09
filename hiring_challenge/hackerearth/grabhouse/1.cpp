#include <iostream>
#include <cstring>
#include <cstdio>
#include <string>
#include <algorithm>
#include <map>
#include <cstdlib>
#include <cmath>
#include <utility>
#include <cctype>
#include <stack>
#include <queue>
#include <list>
#include <vector>
using namespace std;

#define FILE_INPUT true

typedef pair<int,int> ii;	
typedef vector<int> vi;
typedef vector<ii> vii;

int main(){
	if(FILE_INPUT)
		freopen("in.txt","r",stdin);
	int T;
	cin>>T;
	while(T--){
		int N;
		cin>>N;
		long sum=0;
		long j = (N%2)==0?N/2:(N+1)/2;
		j+=1;
		//cout<<j<<endl;
		for(long i=1;j<=N;i++,j++){
			sum += j-i  + (i>1? (j-(i-1)):0);
			//cout<<j<<"-"<<i<<" "<<(i>1? (j-(i-1)):0)<<endl;;	
		}
		if(N%2!=0)
			sum+=1;
		cout<<sum<<endl;
	}

	return 0;
}