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

#define MOD 1000000007

int main(){
    freopen("in.txt","rt",stdin);
    string s;
    cin>>s;
    long len = s.length();
    long sum = 0,tmp=0;
    for(int i=0;i<len;i++){
       tmp = ((s[i]-'0')*(i+1))+ ((10*(tmp)))%MOD;
       sum= (sum+tmp)%MOD;
       // cout<<tmp<<endl;
    }
    cout<<sum<<endl;
    return 0;
}