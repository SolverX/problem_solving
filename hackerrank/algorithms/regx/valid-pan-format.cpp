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
#define EXPLORED 1w1
#define UN_VISISTED 0

typedef unsigned long long ull;
typedef unsigned long ul;
typedef vector<int> vi;
typedef pair<int,int> ii;
typedef vector<ii> vii;
bool ischar(char c){
    return (c>='A' && c<='Z');
}
bool isdigit(char c){
    return c>='0' && c<='9';
}

int main(){
    freopen("in.txt","rt",stdin);
    int T;
    cin>>T;
    while(T--){
        string s;
        cin>>s;
        if(ischar(s[0]) && ischar(s[1]) && ischar(s[2]) &&ischar(s[3]) && ischar(s[4]) &&  isdigit(s[5]) &&  isdigit(s[6]) &&  isdigit(s[7]) &&  isdigit(s[8]) && ischar(s[9])){
            cout<<"YES"<<endl;
        }else{
            cout<<"NO"<<endl;
        }

    }
    return 0;
}