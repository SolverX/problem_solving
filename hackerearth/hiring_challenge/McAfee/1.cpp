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

int shuffle(string s)
{
    
    int counts[27];
    memset(counts,0,sizeof(counts));
    for (int i = 0; i<s.length();  i++)
        counts[s[i]-'a']++;
    int result = 0;
    for (int i = 0; i < 27; i++){
        int cnt = counts[i]>>1;
        counts[i] -= cnt<<1;
       result+=counts[i]; 

    }
    if(result>1)
        result--;
    return result;
}

int main()
{
    freopen("in.txt","rt",stdin);
    int T;
    cin>>T;
    while(T--){
        string s;
        cin>>s;
        cout<<shuffle(s)<<endl;
    }
    return 0;
}