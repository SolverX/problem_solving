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
#define len(x) sizeof(x)
#define null NULL
#define nil NULL

#define MAX 2147483647

typedef unsigned long long ull;
typedef unsigned long ul;
typedef vector<int> vi;
typedef pair<int,int> ii;
typedef vector<ii> vii;

bitset<MAX> isPrime;
vector<long> Prime;
void sieve(){
    Prime.push_back(2);
    for(long i=3;i<=MAX;i+=2){
        if(!isPrime[i]){

            for(long j=i*i;j<=MAX;j+=i){
                isPrime[j]=true;
            }
            Prime.push_back(i);
        }
    }

}
long sum(long n){
    long total=0;
    int pos=0;
    while(n>=0){
        long divisor = Prime[pos];
        while(n%divisor==0 && n){
            total+=divisor;
            n/=divisor;
        }
        pos++;
    }
    return total;

}
int main(){
    freopen("in.txt","rt",stdin);
    sieve();
    long N;
    cin>>N;
    long tmp=N;
    long total=0;
    while(tmp>=0){
        total += tmp%10;
        tmp/=10;
    }
    cout<<1<<endl;
    return 0;
}