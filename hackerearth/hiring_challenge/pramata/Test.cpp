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

long SUB[2][100002];
long ANS[2][100002];
int main(){
    freopen("in.txt","rt",stdin);
    int N,Q;
    cin>>N>>Q;
    for(int i=0;i<N;i++){
        cin>>SUB[0][i];
    }
    for(int i=0;i<N;i++){
        cin>>SUB[1][i];
    }
    ANS[0][0]=SUB[0][0];
    ANS[1][0]=SUB[1][0];
    // cout<<ANS[0][0]<<endl;
    for(int i=1;i<N;i++){
        
        ANS[0][i]=ANS[0][i-1] + SUB[i%2][i];
        ANS[1][i]=ANS[1][i-1] + SUB[!(i%2)][i];
        // cout<<ANS[1][i]<<endl;
    }
    // for(int i=0;i<N;i++){
    //     cout<<ANS[0][i]<<"\t";
    // }
    // cout<<endl;
    // for(int i=0;i<N;i++){
    //     cout<<ANS[1][i]<<"\t";
    // }
    // cout<<endl;
    while(Q--){
        int type,start,end;
        cin>>type>>start>>end;
        start--,end--;
        if(start>end){
            int tmp=start;
            start = end;
            end = tmp;
        }
        long sum = 0;
        for(;start<=end;start++){
            sum+= SUB[(++type)%2][start];
            // cout<<SUB[(type)%2][start]<<endl;
        }
        cout<<sum<<endl;
    }


    return 0;
}