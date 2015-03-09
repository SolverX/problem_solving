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
typedef vector<long> vi;
typedef pair<long,long> ii;
typedef vector<ii> vii;

long avg,a[21],D,C;
long getMinimalDeviation(long pos,long rem,long sum){
	if(rem==1 && pos==C) return abs(avg-sum);
	if(pos>=C) return 99999;
	
	//cout<<sum<<endl;
	long val1=abs(sum-avg)+getMinimalDeviation(pos+1,rem-1,a[pos]);
	long val2=getMinimalDeviation(pos+1,rem,sum+a[pos]);

	return min(val1,val2);

}
int main(){
	freopen("in.txt","rt",stdin);
	long T;
	cin>>T;
	while(T--){
		long sum=0;
		cin>>D>>C;
		for(long i=0;i<C;i++){
			cin>>a[i];
			sum+=a[i];
		}
		avg=sum/D;
		long result = getMinimalDeviation(0,D,0);
		//cout<<endl;
		cout<<result<<endl;

	}
	return 0;
}