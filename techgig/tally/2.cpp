#include <iostream>
#include <cstring>
#include <cstdio>
#include <algorithm>
using namespace std;
// #define INT_MAX 10000007
int bottle[]={1,5,7,10};
int len =4;
static int DP[4][INT_MAX];
long requiredBottles(int pos,int rem){
    if(rem==0) return 0;
    if(pos>=len || rem<0) return INT_MAX;
    if(DP[pos][rem]) return DP[pos][rem];
    return DP[pos][rem]=min(requiredBottles(pos,rem-bottle[pos])+1l,requiredBottles(pos+1,rem));
}
int minimumBottles(int input1)
{
    // for(int i=0;i<len;i++){
    //     for(int j=0;j<input1+1;j++){

    //     }
    // }
    return requiredBottles(0,input1);
}



int main(){
    cout<<minimumBottles(27)<<endl;
    return 0;
}