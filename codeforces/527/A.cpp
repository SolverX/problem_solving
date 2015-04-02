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

ull find(ull a,ull b){
    if(a==0 || b==0)
        return 0;
    ull val = a/b;
    ull mod = a%b;
    return val+find(b,mod);
}

int main(){
    freopen("in.txt","rt",stdin);
    ull A,B;
    cin>>A>>B;
    cout<<find(A,B)<<endl;
    return 0;
}