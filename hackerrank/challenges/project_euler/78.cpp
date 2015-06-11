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

int CoinPartition(int N){
    if (N == 0)
        return 1;
    int S = 0; 
    int J = N-1; 
    int k = 2;
    while (J>0){
        int T = CoinPartition(J);
        if ( (k/2) & 1){
            S+=T;
        }else{
            S-=T;
        }
        
        if ( (k) & 1){
            J-=k;
        }else{
            J=k/2;
        }
        k += 1;
    }
    return S;
}
int main(){
    freopen("in.txt","rt",stdin);
    cout<< CoinPartition(5)<<endl;
    return 0;
}