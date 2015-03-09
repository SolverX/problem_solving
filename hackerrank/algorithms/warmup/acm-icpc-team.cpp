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
int countBits(string a,string b){
	int cnt=0;
	for(int i=0;i<a.length();i++){
		if(a[i]=='1' || b[i]=='1')
			cnt++;
	}
	return cnt;
}
int main(){
	freopen("in.txt","rt",stdin);
	int N,M;
	cin>>N>>M;
	vector<string> list;
	//cout<<sizeof(ull)*8<<endl;
	for(int i=0;i<N;i++){
		string s;
		cin>>s;
		list.push_back(s);
	}
	int maxBitCount = 0;
	int maxCount = 0;
	for(int i=0;i<N;i++){
		for(int j=i+1;j<N;j++){
			int bitCount = countBits(list[i],list[j]);
			
			if(bitCount>maxBitCount){
				maxBitCount=bitCount;
				maxCount = 0;
			}
			if(bitCount==maxBitCount){
				maxCount++;
			}
		}
	}
	cout<<maxBitCount<<endl;
	cout<<maxCount<<endl;
	return 0;
}