#include <iostream>
#include <cstdio>
#include <algorithm>
#include <cmath>
using namespace std;
int main(){
    freopen("in.txt","r",stdin);
    int T;
    cin>>T;
    while(T--){
        int N;
        cin>>N;
        int arr[N+1];
        for(int i=0;i<N;i++){
            cin>>arr[i];
        }

        sort(arr,arr+N);
        int moves=0;
        arr[N]=1006;
        for(int i=0;i<N;i++){
            moves++;
            if(arr[i]+1==arr[i+1]){
                i++;
            }
        }
        cout<<moves<<endl;
    }
    return 0;
}