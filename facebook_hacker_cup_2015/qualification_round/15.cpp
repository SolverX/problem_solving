#include<iostream>
#include<cstdio>
#include<cstring>
#include<algorithm>
#include<cstdlib>
#include<string>
#include<cmath>
#include<map>
#include<vector>
using namespace std;

int main(){

	freopen("in.txt","r",stdin);
	int T,Case=0;
	cin>>T;
	while(T--){
		string s;
		cin>>s;
		string actual=s;
		bool foundResult=false;
		int swapPos = 0;
		for(int i=0;i<s.length() && !foundResult;i++){
			swapPos=i;
			for(int j=i+1;j<s.length();j++){
				if(s[swapPos]<s[j]){
					swapPos=j;
					foundResult=true;
				}
				if(foundResult && s[swapPos]==s[j]){
					swapPos=j;
				}
			}
			if(foundResult){
				char c = s[i];
				s[i]=s[swapPos];
				s[swapPos]=c;
			}
		}
		printf("Case #%d: ",++Case);
		cout<<actual<<" "<<s<<endl;
	}
	return 0;
}
