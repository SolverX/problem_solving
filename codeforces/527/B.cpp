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
    int len;
    string s,t;
    cin>>len;
    cin>>s>>t;
    ull sum=0;
    int a[27],b[27],pos[27];
    // cout<<s<<" "<<t<<endl;
    int ax=-1,ay=-1;
    memset(a,0,sizeof(a));
    memset(b,0,sizeof(b));
    // memset(pos,-1,sizeof(pos));
    for(int i=0;i<len;i++){
        int c1=s[i]-'a';
        int c2=t[i]-'a';
        // if(s[i])
        
            if(b[c1]!=0 && a[c2]!=0  && c1!=c2){
                ax=i+1;
                ay=b[c1];
                // if(s[ax-1]!=t[ay-1])
                //     sum=-2;
                break;
            }
            else if(c1!=c2){
                if(b[c1]!=0 && b[c1] != a[c2]){
                    ax=i+1;
                    ay=b[c1];
                    // sum=-1;
                }
            }
        a[c1]=i+1;
        b[c2]=i+1;
        
    }
    int result[27];
    if(ax>=0){
        int tmp = s[ax-1];
        s[ax-1] = s[ay-1];
        s[ay-1] = tmp;
    }
    memset(result,0,sizeof(result));
    for(int i=0;i<len;i++){
        sum += s[i]!=t[i];
    }

    cout<<sum<<endl;
    cout<<ax<<" "<<ay<<endl;
    return 0;
}