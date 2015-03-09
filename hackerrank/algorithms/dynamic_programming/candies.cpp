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

int main(){
	freopen("in.txt","rt",stdin);
	int T;
	cin>>T;
	int a[T+1],candies[T+1];
	for(int i=0;i<T;i++){
		cin>>a[i];
		candies[i]=1;
	}
	for(int i=1;i<T;i++)
		if(a[i-1]<a[i])
			candies[i] = candies[i-1] + 1;

	ull sum=0;
	for(int i=T-1;i>=0;i--)
		if(a[i] > a[i+1])
			candies[i] = max(candies[i],candies[i+1]+1);

	for(int i=0;i<T;i++)
		sum+=candies[i];
	cout<<sum<<endl;

	return 0;
}