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
	string s;
    cin>>s;
     
    int flag = 1;
    map<char,int> list;
    for(int i=0;i<s.length();i++){
    	char c = s[i];
    	list[c]++;
    }
    //int total=0;
    bool alreadyFoundOdd = false;
    for(char c='a';c<='z';c++){
    	if(list[c]){
    		if(list[c]%2!=0 && s.length()%2==0){
    			flag = 0;
    			break;
    		}
    		if(list[c]%2!=0 && s.length()%2!=0){
    			if(alreadyFoundOdd==true){
    				flag = 0;
    				break;
    			}
    			alreadyFoundOdd=true;
    		}
    	}
    }

    if(flag==0)
        cout<<"NO";
    else
        cout<<"YES";
	return 0;
}