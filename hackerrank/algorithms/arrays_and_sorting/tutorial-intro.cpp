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
	int V;
	int N;
	cin>>V>>N;
	int location=-1;
	for(int i=0;i<N;i++){
		int temp;
		cin>>temp;
		if(temp==V && location==-1){
			location = i;
		}
	}
	cout<<i<<endl;
	return 0;
}