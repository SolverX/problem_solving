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

string wobbly(int N,int K){
    string res;
    if(K>81){
        return "-1";
    }
    for(int i=1;i<=9;i++){
        for(int j=0;j<=9;j++){
            if(i!=j){
                if(--K) continue;
                    int pos=0;
                    while(N>pos){
                        char put[2];
                        if(pos&1){
                            put[0]= j+'0';
                            put[1]='\0';
                        }else{
                            put[0]= i+'0';
                            put[1]='\0';
                        }
                        pos++;
                        res+=put;
                    }
                    return res;
                }

            }
        }
    return "-1";
}
int main(){
    freopen("in.txt","rt",stdin);
    int T;
    cin>>T;
    while(T--){
         int N,K;
         cin>>N>>K;
         cout<<wobbly(N,K)<<endl;


    }
    return 0;
}