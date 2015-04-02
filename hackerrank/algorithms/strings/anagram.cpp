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
    cin>>T;
    while(T--){
        string s;
        cin>>s;
        int len = s.length();
        if(len&1){
            cout<<(-1)<<endl;
            continue;
        }
        char a,b;
        int mid = len/2;
        int anagram[27];
        memset(anagram,0,sizeof(anagram));
        for(int i=0;i<mid;i++){
            a = s[i]-'a';
            b = s[mid+i]-'a';
            anagram[a]++;
            anagram[b]--;

        }
        int sum=0;
        for(int i=0;i<='z'-'a';i++){
            sum+=abs(anagram[i]);
        }
        cout<<sum/2<<endl;
    }
    return 0;
}