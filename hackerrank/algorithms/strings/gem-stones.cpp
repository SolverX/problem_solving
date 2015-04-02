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
    int T;
    int final[27];
    memset(final,1,sizeof(final));
    cin>>T;
    while(T--){
        string s;
        cin>>s;
        int a[27];
        memset(a,0,sizeof(a));
        for(int i=0;i<s.length();i++){
            char c=s[i]-'a';
            if(!a[c]){
                a[c]++;
            }
        }
        for(int i=0;i<27;i++){
            final[i] &= a[i];
        }
    }
    int sum=0;
    for(int i=0;i<27;i++)
        sum+=final[i];
    cout<<sum<<endl;
    return 0;
}