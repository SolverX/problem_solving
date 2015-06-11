#include <iostream>
#include <cstring>
#include <cstdio>
#include <string>
#include <algorithm>
#include <map>
#include <cstdlib>
#include <cmath>
#include <utility>
#include <cctype>
#include <stack>
#include <queue>
#include <list>
#include <vector>
using namespace std;

#define FILE_INPUT true

typedef pair<int,int> ii;
typedef vector<int> vi;
typedef vector<ii> vii;

int main(){
    if(FILE_INPUT)
        freopen("in.txt","r",stdin);
    int T;
    cin>>T;
    while(T--){
        int N;
        cin>>N;
        int A[N];
        long sum=0;
        for(int i=0;i<N;i++){
            cin>>A[i];
        }
        int pos=(N/2);
        sort(A,A+N);
        bool first=true;
        sum = A[(pos+N)/2]-1;
        for(;pos<N;pos++){
            if(!first){
                // sum+=(A[pos]-1);
            }
            sum+=(A[pos]-1);
            first=false;
            // cout<<A[pos]<<endl;
        }
        cout<<sum<<endl;
    }

    return 0;
}