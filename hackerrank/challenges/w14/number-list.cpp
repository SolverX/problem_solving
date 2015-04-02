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
        ull N,K;
        cin>>N>>K;
        ull cnt=0;
        ull prev=0,sum=0;
        for(ull i=0;i<N;i++){
            ull tmp;
            cin>>tmp;
            if(tmp>K){    
                prev = i+1;
            }
            sum += prev;
        }
        // ull sum=0;
        // while(cnt--){
        //     sum+=(N--);
        // }
        cout<<sum<<endl;

    }
    return 0;
}