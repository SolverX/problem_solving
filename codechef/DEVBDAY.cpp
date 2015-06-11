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
#define SIZE 100005
typedef long long ull;
typedef pair<int,int> ii;
typedef vector<int> vi;
typedef vector<ii> vii;
int A[SIZE],AMT[SIZE];
bool invited[SIZE];
bool invi[SIZE];
ull DP[SIZE];
int N;
void uninvite(int j){
            

            while(invited[j] && AMT[j-1]>=0){
                invited[j]=false;
                j=A[j-1];
            }

}
int countAmount(int i){
    int tmp = 0;
    // memset(invi,false,sizeof(invi));
    if(!invited[i] && AMT[i-1]>0){
            
            int j=i;
            while(!invited[j]){
                invited[j]=true;
                tmp+= AMT[j-1];
                j=A[j-1];
            }
            if(tmp<=0){
                uninvite(i);
                tmp=0;
            }

        }
    return tmp;
}

ull findMaximumAmount(int pos){
    if(pos>=N) return 0;
    if(DP[pos]!=-1) return DP[pos];
    ull sum = countAmount(pos+1)+ findMaximumAmount(pos+1);
    uninvite(pos);
    ull total = findMaximumAmount(pos+1);
    return DP[pos]=max(sum,total);
}
int main(){
    if(FILE_INPUT)
        freopen("in.txt","r",stdin);
    int T;
    cin>>T;
   while(T--){
    cin>>N;
    for(int i=0;i<N;i++){
        cin>>A[i];
        DP[i]=-1;
    }
    for(int i=0;i<N;i++){
        cin>>AMT[i];
    }
    memset(invited,false,sizeof(invited));
    long total=findMaximumAmount(0);
    cout<<total<<endl;

   }
return 0;
}