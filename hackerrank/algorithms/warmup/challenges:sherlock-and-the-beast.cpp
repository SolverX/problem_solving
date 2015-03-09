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

#define INF 1000000

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
		int N;
		cin>>N;
		int result = N>2?N%3:4;
		int fiveCount = 0;
		int threeCount = 0;
		switch(result){
			case 0:
				fiveCount = N;
				break;
			case 1:
				if(N>=10){
					threeCount = 10;
					fiveCount =  N-10;
				}
				break;
			case 2:
				fiveCount = N-5;
				threeCount = 5;
				break;
			default:
				fiveCount = 0;
				threeCount=0;
				break;

		}
		if(fiveCount ==0 && threeCount ==0){
			cout<<-1;
		}else{
			for(int i=0;i<fiveCount;i++)
				cout<<5;
			for(int j=0;j<threeCount;j++)
				cout<<3;
		}
		cout<<endl;
	}
	return 0;
}