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
    cin>>T:
    while(T--){
        int S:
        string P,Q;
        cin>>S>>P>>Q;
        int maxLen = P.length();
        for(int len=maxLen;len>=1;len--){
            for(int i=0;i<len;i++){
                for(int j=0;j<maxLen-len;j++){
                    int cnt=0;
                    for(int k=0;k<len && cnt<=S;k++){
                        if(P[i+k]!=Q[j+k]){
                            cnt++;
                        }
                    }

                }
            }
        }
    }
    return 0;
}