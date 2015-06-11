#include <iostream>
#include <cstdio>
#include <cstring>
#include <cstdlib>
#include <string>
#include <algorithm>
#include <vector>
#include <cctype>
#include <stack>
#include <map>
#include <utility>
#include <cmath>
using namespace std;

typedef pair<int,int> ii;
typedef vector<int> vi;
typedef vector<ii> vii;

map<int,int> Result;
void preCompute(){

    for(int i=5;i<=100000;i++){
        int tmp = i;
        while(tmp>0){
            if(tmp-5 == (tmp^5)){
                Result[i]++;
                // if(i<=22){
                //     cout<<i<<endl;
                // }
            }
            // if(i==21){
            //     cout<<(tmp^5)<<" ";
            //     cout<<(tmp-5 == (tmp^5))<<" "<<endl;;
            // }
            tmp=tmp>>2;

        }
    }
}

int main(){
    freopen("in.txt","r",stdin);
    int T;
    preCompute();
    cin>>T;
    while(T--){
        int R,K;
        cin>>R>>K;
        int cnt=0;
        for(int i=0;i<=R;i++){
            // cout<<Result[i]<<" ";
            if(Result[i]>=K){
                cnt++;
            }
        }
        cout<<cnt<<endl;
    }
    return 0;
}