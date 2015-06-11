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
    int T;
    cin>>T;
    while(T--){
        unsigned long long result=1;
        unsigned long long len,TOP[1000005];
        cin>>len;
        for(long i=0;i<len-1;i++){
            cin>>TOP[i];
        }
        for(int j=0;j<len-1;j++){
            unsigned long long tmp;
            cin>>tmp;
            long required = max(tmp,TOP[j]);
            // if(required)
            //     required--;
            if( required >0 && result< (required+j+1)){
                result = required+j+1;
            }
            

        }
        result = max(len,result);
        cout<<result<<endl;


    }
    return 0;
}