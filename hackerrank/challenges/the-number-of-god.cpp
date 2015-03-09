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
#include <stack>
#include <queue>
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
		string s,stemp;
		cin>>s;
		int len=s.length();

		int total = 0;
		while(len>9){
			for(int i=0;i<len;i+=9){
				int value = 0;
				string temp="";
				for(int j=0;j<9 && i+j < len;j++){
					value = (value*10) + (s[i+j]-'0');
				}
				char a[2];
				a[0]=value%9+'0';
				a[1]='\0';
				stemp+=a;
			}
			//cout<<stemp<<endl;
			s=stemp;
			len=s.length();
			stemp="";
		}
		int value=0;
		for(int j=0;j<len;j++){
			value = (value*10) + (s[j]-'0');
		}
		//cout<<value<<endl;
		cout<<value%9<<endl;

	}
	return 0;
}