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

class Cost{
public:
    int Spent;
    int Refund;
    bool operator < (const Cost O)const{
        if ( (Refund - Spent) == (O.Refund - O.Spent)){
            return Spent < O.Spent;
        }
        return ( (Refund - Spent) > (O.Refund - O.Spent));
    }
};
int T;
long findMinimumCost(int pos){
    if(pos>=T) return false;
}

int main(){
    freopen("in.txt","rt",stdin);
    
    cin>>T;
    
    Cost cost[T];
    for(int i=0;i<T;i++){
        cin>>cost[i].Spent>>cost[i].Refund;
    }
    sort(cost,cost+T);
    long initialAmount=1,balance=1;
    for(int i=0;i<T;i++){

        int S=cost[i].Spent;
        int R=cost[i].Refund;
        // cout<<S<<" "<<R<<endl;
        if(balance-S <0){
            balance = S-balance;
            initialAmount += (S-balance);
        }else{
            balance-=S;
        }
        balance+=R;
    }
    cout<<initialAmount<<endl;
    return 0;
}