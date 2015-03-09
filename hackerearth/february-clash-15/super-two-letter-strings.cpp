#include <iostream>
#include <cstdio>
#include <cstring>
#include <cstdlib>
#include <cmath>
using namespace std;
int main(){
    freopen("in.txt","r",stdin);
    int T;
    cin>>T;
    while(T--){
        int N,P;
        cin>>N>>P;
        //int another = pow(2,N)/2;
        unsigned long long sum=0;
        for(long i=P,j=1;i<N;i++,j*=2){
            j%=1000000007;
            sum= (sum+j)%1000000007;
        }
        long result = 1;
        for(int i=0;i<N;i++){
            result = (result * 2)%1000000007;
        }
        result/=2;
        //cout<<result<<endl;
        cout<< (result-sum) <<endl;

    }
    return 0;
}