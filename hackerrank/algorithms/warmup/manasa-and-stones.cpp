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
	//freopen("in.txt","rt",stdin);
	int T;
	cin>>T;
	while(T--){
		int N,a,b;
		cin>>N>>a>>b;
        if(a>b){
            int temp=b;
            b=a;
            a=temp;
        }
		int start = (N-1)*a;
		cout<<start;
		while(--N && a!=b){
			start += (b-a);
			cout<<" "<<start;

		}
		cout<<endl;
	}
	return 0;
}