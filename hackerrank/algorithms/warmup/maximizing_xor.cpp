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

int maxXor(int l, int r) {
	int maxValue = 0;
	for(int i=l;i<=r;i++){
		for(int j=i;j<=r;j++){
			maxValue=max(maxValue,i^j);
		}
	}	
	return maxValue;
}

int main(){
	freopen("in.txt","rt",stdin);
	int res;
    int _l;
    cin >> _l;
    
    int _r;
    cin >> _r;
    
    res = maxXor(_l, _r);
    cout << res;
    
	
	return 0;
}