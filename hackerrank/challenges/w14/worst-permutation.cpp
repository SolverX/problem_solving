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

void swap(int *a,int *b){
    int *tmp=a;
    a=b;
    b=tmp;
}
int main(){
    freopen("in.txt","rt",stdin);
    int T,K;
    cin>>T>>K;
    int A[100004];
    map<int,int> POS;
    for(int i=0;i<T;i++){
        cin>>A[i];
        POS[A[i]]=i;
        // cout<<A[i]<<endl;
    }
    int pos=0,req=T;
    while(K-- && pos<T){
        int val=POS[req];
        while(val==pos){
            pos++;
            req--;
            val=POS[req];

        }
        if(pos>=T || req<1)
            break;
        // cout<<pos<<" "<<req<<endl;
        swap(A[pos],A[POS[req]]);
        POS[A[POS[req]]]=POS[A[pos]];
        POS[req]=pos;
        pos++;
        req--;
        //cout<<POS[A[pos]]<<endl;
    }
    for(int i=0;i<T;i++){
        if(i)
            cout<<" ";
        cout<<A[i];
    }
    cout<<endl;
    return 0;
}