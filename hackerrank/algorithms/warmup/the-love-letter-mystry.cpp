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

int solveMystry(string s){
	int countChances = 0;
	for(int i=0,j=s.length()-1;i<j;i++,j--){
		if(s[i]>s[j]){
			countChances += s[i]-s[j];
			s[i]=s[j];
		}else{
			countChances += s[j]-s[i];
			s[j]=s[i];
		}
	}
	return countChances;
}
int main(){
	freopen("in.txt","rt",stdin);
	int T;
	cin>>T;
	while(T--){
		string s;
		cin>>s;
		cout<<solveMystry(s)<<endl;
	}
	return 0;
}