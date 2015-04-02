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
        int len = s.length()-1;
        int half_len = len/2;
        int problem=-1;
        for(int i=0;i<half_len;i++){
            if(s[i]!=s[len-i]){
                if(problem!=-1){
                    problem = (len+1)-problem;
                    break;
                }
                problem = len-i;
                len--;
                i--;
            }
        }
        cout<<problem<<endl;
    }
    return 0;
}