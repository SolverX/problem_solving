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

int main(){
    freopen("in.txt","rt",stdin);
    string s;
    cin>>s;
    int a[27];
    memset(a,0,sizeof(a));
    for(int i=0;i<s.length();i++){
        char c = s[i]-'a';
        a[c]++;
    }
    for(int i=0;i<27;i++){
        a[i]/=2;
        while(a[i]--){
            cout<<char('a'+i);
        }
    }
    cout<<endl;
    return 0;
}