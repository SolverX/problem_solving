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
string s;
bool isAnagram(string a,string b){
    sort(a.begin(),a.end());
    sort(b.begin(),b.end());
    return a==b;
}

long countAnagramPair(string s){
    int len=s.length(),cnt=0;
    for(int i=0;i<len;i++){
        for(int j=i;j<len;j++){
            int diff = j-i;
            string a = s.substr(i,diff+1);
            for(int k=i+1;k<len-diff;k++){
                string b = s.substr(k,diff+1);
                // cout<<a<<" "<<b<<endl;
                if(isAnagram(a,b))
                    cnt++;
            }
        }
    }
    return cnt;
}


int main(){
    freopen("in.txt","rt",stdin);
    int T;
    cin>>T;
    while(T--){
        cin>>s;
        cout<<countAnagramPair(s)<<endl;

    }
    return 0;
}