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
typedef vector<intx> vi;
typedef pair<int,int> ii;
typedef vector<ii> vii;


int main(){
    freopen("in.txt","rt",stdin);
    int T;
    cin>>T;
    while(T--){
        string s,ordered;
        cin>>s;
        //sort(ordered.begin(),ordered.end(),cmp);
        if(next_permutation(s.begin(),s.end())){
            cout<<s<<endl;
        }else{
            cout<<"no answer"<<endl;
        }
    }
    return 0;
}