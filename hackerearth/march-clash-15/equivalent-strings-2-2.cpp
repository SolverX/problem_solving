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
        int Q;
        cin>>Q;
        while(Q--){
            int i,j,k;
            cin>>i>>j>>k;
            i--;j--;
            bool isAEqual = true,isBEqual=true;
            bool isANOTEqual = true,isBNOTEqual=true;
            int limit = i+k; 
            for(;i<limit-1 && (isAEqual || isBEqual || isANOTEqual || isBNOTEqual);i++,j++){
                if(a[i]!=a[i+1]){
                    isAEqual=false;
                }
                if(a[i]==a[i+1]){
                    isANOTEqual=false;
                }
                if(b[j]!=b[j+1]){
                    isBEqual=false;
                }
                if(b[j]==b[j+1]){
                    isBNOTEqual=false;
                }
                // cout<<"came"<<endl;

            }
            if((isANOTEqual && isBNOTEqual) || (isAEqual && isBEqual)){
                cout<<"yes"<<endl;
                // cout<<isAEqual<<" "<<isBEqual<<endl;
            }else{
                cout<<"no"<<endl;
            }
        }
    }
    return 0;
}