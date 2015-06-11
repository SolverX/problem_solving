#include <iostream>
#include <cstdio>
#include <algorithm>
#include <cmath>
using namespace std;
int arr[101];
int method1(int a,int b){
    int result = 0;
    for(int i=a+1;i<b;i++){
        result += (arr[a]-arr[i])*3;
    }
    return result;
}
int method2(int a,int b){
    int result = 0;
    int median =0;
    for(int i=a;i<b;i++){
        median += arr[i];
    }
    median = floor(median*1.00/(b-a)*1.00);
    for(int i=a;i<b;i++){
        if(arr[i]>median){
            result += (arr[i]-median)*5;
        }else{
            result += (median-arr[i])*3;
        }
    }
    // cout<<median<<endl;
    return result;
}
int dp[5555];
int ar[1000];
int br[1000];
int minSteps(int a,int b){
    for(int i=0;i<(b-a);i++){
        ar[i]=arr[a+i];
        br[i]=ar[i];
        dp[i]=99999;
    } 
    int n=b-a;
    dp[0]=0;
    // memset(dp,,sizeof(dp));
    for(int i=0;i<n;i++)
    {
        for(int j=0;j<n;j++)
        {
            dp[j]+= abs(ar[i]-br[j])* 3;
            // cout<<dp[j]<<endl;
            if(j!=0 && dp[j]!=0 &&dp[j-1]!=0)
            {
                dp[j]=min(dp[j-1],dp[j]);
            }
        }
    }
    return dp[n-1];
}
bool rev(int a,int b){
    return a>b;
}
int main(){
    freopen("in.txt","r",stdin);
    int T;
    cin>>T;
    while(T--){
        int K,N;
        cin>>N>>K;
        
        for(int i=0;i<N;i++){
            cin>>arr[i];
        }

        sort(arr,arr+N,rev);
        int minVal = 5000;


        for(int i=0;i<=N-K;i++){
            // int result1 = method1(i,i+K);
            // int result2 = method2(i,i+K);
            //  cout<<result1<<" "<<result2<<endl;
            minVal = min(minVal,minSteps(i,i+K));

        }
        cout<<minVal<<endl;
    }
    return 0;
}