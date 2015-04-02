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

int main(){
    freopen("in.txt","rt",stdin);
    string a,b;
    cin>>a>>b;
    int ax[27],bx[27];
    memset(ax,0,sizeof(ax));
    memset(bx,0,sizeof(bx));

    for(int i=0;i<a.length();i++){
        int pos = a[i]-'a';
        ax[pos]++;
        // cout<<('a'-a[i])<<endl;
    }
    for(int i=0;i<b.length();i++){
        int pos = b[i]-'a';
        bx[pos]++;
    }
    int sum=0;
    for(int i=0;i<27;i++){
        sum += abs(bx[i]-ax[i]);
        // cout<<bx[i]<<" "<<ax[i]<<endl;
    }
    cout<<sum<<endl;
    return 0;
}