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

int N;
string S;
bool isAllEqual(){
    for(int i=0;i<N-1;i++){
        if(S[i]!=S[i+1]){
            return false;
        }
    }
    return true;
}
void invert(int from,int to){
    for(int i=from;i<=to;i++){
        if(S[i]=='W'){
            S[i]='B';
        }else{
            S[i]='W';
        }
    }
}
int swapCount = 0,minSwapCount=20*20;
void backtrack(int u){
    if(u>=N-2){
        return 0;
    }
    if(isAllEqual()){
        minSwapCount = min(swapCount,minSwapCount);
        return;
    }
    // cout<<S<<endl;
    for(int i=u;i<N-2;i++){
        swapCount++;
        invert(i,i+1);
        backtrack(i+1);
        invert(i,i+1);
        invert(i,i+2);
        backtrack(i+1);
        invert(i,i+2);
        swapCount--;
    }
    

}
int main(){
    freopen("in.txt","rt",stdin);
    cin>>N>>S;
    backtrack(0);
    cout<<minSwapCount<<endl;
    return 0;
}