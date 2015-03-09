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
		int N,cnt,most;
		cin>>N>>cnt;
		for(int i=31;i>=0;i--)
			if( (N&(1<<i) )>0)
			{
				most = i;
				break;
			}
		if(cnt==1){
			cout<<1<<endl;
			continue;
		}
		if(most==1 || cnt>most || most==0 || cnt==0){
			cout<<-1<<endl;
			continue;
		}
		int val= (1<<most) | (1<<0);
		if(val>N){
			most--;
			val= (1<<most) | (1<<0);
			//cout<< val<<endl;
		}
		most--;
		cnt-=2;
		//cout<<val<<endl;
		while(cnt--){
			//cout<<(val | (1<< (most-2) ))<<endl;
			while( (val | (1<<most) ) >N ){
				most--;
			}
			val=val | (1<<most);
			most--;
		}
		
	//	int bitCount = __builtin_popcount(N);
		cout<<val<<endl;
	}
	return 0;
}