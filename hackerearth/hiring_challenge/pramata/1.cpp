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
    int T;
    cin>>T;
    while(T--){
        string A,B;
        bool exists=false;
        cin>>A>>B;
        map<char,bool> SUB;
        SUB.clear();
        for(int i=0;i<A.length();i++)
            SUB[A[i]]=true;
        for(int i=0;i<B.length();i++)
            if(SUB[B[i]]){
                exists=true;
                break;
            }
        if(exists)
            cout<<"YES"<<endl;
        else
            cout<<"NO"<<endl;
    }
    return 0;
}