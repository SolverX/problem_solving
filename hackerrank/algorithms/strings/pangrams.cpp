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
#include <bitset>
using namespace std;
#define VISITED 2
#define EXPLORED 1
#define UN_VISISTED 0

typedef unsigned long long ull;
typedef unsigned long ul;
typedef vector<int> vi;
typedef pair<int,int> ii;
typedef vector<ii> vii;
int to_lower(char c){
    if(c>='A' && c<='Z'){
        return 'a'+ (c-'A');
    }
    return c;
}

int main(){
    freopen("in.txt","rt",stdin);
    char s[10000];
    gets(s);
    bool dp[27];
    for(int i=0;i<27;i++) dp[i]=false;
    int sum=0;
    for(int i=0;i<strlen(s);i++){
        char c=to_lower(s[i]);
        int pos = c-'a';
        if(c!=' ' && !dp[pos]){
            sum++;
            dp[pos]=true;
            // cout<<sum<<endl;
        }
    }
    // cout<<sum<<endl;
    
    if(sum==26)
        cout<<"pangram"<<endl;
    else
        cout<<"not pangram"<<endl;
    return 0;
}