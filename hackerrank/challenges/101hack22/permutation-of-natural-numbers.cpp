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

int main(){
    freopen("in.txt","rt",stdin);
    string s;
    cin>>s;
    int X[s.length()+1];
    X[0]=1;
    int minValue=1;
    for(int i=0;i<s.length()-1;i++){
        if(s[i]=='I'){
            X[i+1] = X[i]+1;
        }else{
            X[i+1]=X[i]-1;
            minValue=min(X[i+1],minValue);
        }
    }
    for(int i=0;i<s.length();i++)
        cout<<X[i]<<" ";
    cout<<endl;

    return 0;
}