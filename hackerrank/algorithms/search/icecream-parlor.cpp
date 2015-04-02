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
    int M,N;
    cin>>T;
    while(T--){
        cin>>M>>N;
        int C[N+1];
        for(int i=0;i<N;i++)
            cin>>C[i];
        for(int i=0;i<N;i++){
            for(int j=i+1;j<N;j++){
                if(C[i]+C[j]==M){
                    cout<<i+1<<" "<<j+1<<endl;
                    i=N;
                    break;
                }
            }

        }
    }
    return 0;
}