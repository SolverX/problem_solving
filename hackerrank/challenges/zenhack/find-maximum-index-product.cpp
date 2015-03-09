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

long long A[100005],N,Left[100005],Right[100005];

int findLeft(int n){
    if(n<=1)
        return Left[n]=0;
   // cout<<n<<endl;
    if(Left[n]!=-1) return Left[n];
    int pos=n-1;
    if(A[pos]>A[n]) return Left[n]=pos;
    else{
       // cout<<pos<<endl;
        pos=findLeft(pos);
        while(pos!=0 && A[pos]<=A[n]){
             // cout<<pos<<endl;
            pos=findLeft(pos);
        }
        if(A[pos]<=A[n])
            pos=-2;
    }

    return Left[n]=pos;

}
long long findRight(int n){
    if(n>=N)
        return Right[n]=0;
    //\\ cout<<n<<endl;
    if(Right[n]!=-1) return Right[n];
    int pos=n+1;
    if(A[pos]>A[n]) return Right[n]=pos;
    else{
       
        pos=findRight(pos);
        while(pos!=0 && A[pos]<=A[n]){
             // cout<<pos<<endl;
            pos=findRight(pos);
        }
        if(A[pos]<=A[n])
            pos=-2;
    }

    return Right[n]=pos;

}
int main(){
   freopen("in.txt","rt",stdin);
    cin>>N;
    for(int i=1;i<=N;i++){
        cin>>A[i];
        Left[i]=-1;
        Right[i]=-1;
    }
    Left[0]=Right[0]=-1;
    for(int j=N;j>=1;j--){
        if(Left[j]==-1)
            int temp = findLeft(j);
        if(Right[j]==-1)
            int temp = findRight(j);
    }
    //temp = findRight(1);
    long long maxValue = 0;
    // cout<<N<<endl;
    for(int i=1;i<=N;i++){
        if(Right[i]>0 && Left[i]>0)
            maxValue=max(maxValue,Right[i]*Left[i]);
        // cout<<Left[i]<<" "<<Right[i]<<endl;
    }
    cout<<maxValue<<endl;
    return 0;
}