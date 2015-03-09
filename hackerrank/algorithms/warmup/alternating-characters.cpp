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

int countDeletion(string s){
	int deletionCount = 0;
	for(int i=s.length()-1;i>=1;i--){
		if(s[i]==s[i-1]){
			s[s.length()-1]='\0';

			deletionCount++;
		}
	}
	return deletionCount;
}
int main(){
	freopen("in.txt","rt",stdin);
	int T;
	cin>>T;
	while(T--){
		string s;
		cin>>s;
		cout<<countDeletion(s)<<endl;
	}
	return 0;
}