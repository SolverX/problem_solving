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

#define SIZE 1000
// #define MOD 1000000993
// bitset<100000000000> test;
bool isPrime(ull num){
    if(num%2==0) return false;
    for(ull i=3;i<=sqrt(num);i+=2){
        if(num%i==0) return false;
    }
    return true;
}
vector<ull> Prime;
void sieve(){
    ull x =1000000000;
    ull y = 1000;
    ull sum=0;
    for(ull i=x;i<=x+y;i++){
        if(isPrime(i)){
            // sum += (num%i);
            //cnt++;
             Prime.push_back(i);
        }
    }
    // cout<<sum<<endl;
}


int main(){
    // freopen("in.txt","rt",stdin);
    sieve();
    ull sum=0;
    ull prev = 1;
    for(int i=0;i<Prime.size();i++){
        ull MOD = Prime[i];
        prev = 1;
        for(ull j=2;j<=SIZE;j++){
            prev = ((6 * (prev*prev)%MOD)%MOD + (10 * prev)%MOD + 3)%MOD;
        }
        sum+=prev;
    }
    cout<<sum<<endl;
    // sieve(prev+MOD);
    // cout<<Prime[Prime.size()-1]<<endl;
    return 0;
}