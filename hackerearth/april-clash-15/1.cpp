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

string reverse(string s){
    reverse(s.begin(),s.end());
    return s;
}
int main(){
    freopen("in.txt","rt",stdin);
    int T;
    cin>>T;
    while(T--){
        int N,Q;
        cin>>N>>Q;
        string S[101],TR[101];
        for(int i=0;i<N;i++)
            cin>>S[i];
        TR[0]=S[0];
        for(int i=1;i<N;i++){
            TR[i] = TR[i-1] + reverse(TR[i-1]) + S[i];
            // cout<<TR[i]<<endl;
        }
        // cout<<TR[N-1]<<endl;
        while(Q--){
            int tmp;
            cin>>tmp;
            cout<<TR[N-1][tmp];
        }
        cout<<endl;
    }
    return 0;
}