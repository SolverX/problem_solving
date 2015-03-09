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
		int N;`
		cin>>N;
		int value,maxValue=-100000;
		long long actualSum=0;
		long long subArraySum = 0;
		long long maxSubArraySum = 0;
		for(int i=0;i<N;i++){
			cin>>value;
			if(value>0)
				actualSum += value;
			subArraySum +=value;
			//cout<<value<<endl;
			if(subArraySum<0){
				subArraySum = 0;
			}
			maxSubArraySum = max(subArraySum,maxSubArraySum);
			maxValue = max(maxValue,value);
		}
		if(actualSum==0 && maxSubArraySum==0){
			actualSum = maxValue;
			maxSubArraySum = maxValue;
		}
		cout<<maxSubArraySum<<" "<<actualSum<<endl;
	}
	return 0;
}