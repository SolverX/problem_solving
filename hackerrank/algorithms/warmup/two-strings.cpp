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
        string a,b;
        cin>>a>>b;
        map<char,bool> isExists;
        for(int i=0;i<a.length();i++)
            isExists[a[i]]=true;
        bool result = false;
        for(int j=0;j<b.length();j++)
            if(isExists[b[j]]){
                cout<<"YES"<<endl;
                result=true;
                break;
            }
        if(!result)
            cout<<"NO"<<endl;
    }
    return 0;
}