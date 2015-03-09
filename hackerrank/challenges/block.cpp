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
		string s;
		cin>>s;
		int len = s.len();
		for(int i=0;i<len/2;i++){
			for(int j=0;j<len;j++){
				int start = j;
				for(int k=i;k<len;k++){
					if(s[j]==s[j]){
						
					}

				}
			}
		}
	}
	return 0;
}