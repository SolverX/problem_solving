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
		int N,temp;
		cin>>N;
		temp=N;
		int counts = 0;
		while(temp!=0){
			int rem = temp%10;
			temp/=10;
			if(rem!=0){
				counts += (N%rem)==0;
			}
		}
		cout<<counts<<endl;
	}
	return 0;
}