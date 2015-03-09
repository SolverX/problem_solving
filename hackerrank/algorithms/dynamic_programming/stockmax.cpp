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

#define SIZE 50000
typedef unsigned long long ull;
typedef unsigned long ul;
typedef vector<long> vi;
typedef pair<long,long> ii;
typedef vector<ii> vii;
long a[SIZE+1],N;
int main(){
	freopen("in.txt","rt",stdin);
	long T;
	cin>>T;
	while(T--){
		cin>>N;
		for(long i=0;i<N;i++){
			cin>>a[i];
		}
		long profit=0;
		long element = a[N-1]; 
		for(int i=N-2;i>=0;i--){
			if(a[i]<element){
				profit += element-a[i];
				//element--;
			}else if(a[i]>=element){
				element = a[i];
			}

		}
		cout<<profit<<endl;

	}
	return 0;
}