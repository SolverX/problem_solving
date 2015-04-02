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
    int T;
    cin>>T;
    while(T--){
        ull A,B;
        cin>>A>>B;
        ull X,Y,Z;
        cin>>X>>Y>>Z;
        ull sum=0;
        if( (X+Z)<Y){
            sum = (X*A) + ((B)*(X+Z));
        }else if((Y+Z)<X){
            sum = (Y*B) + ((A)*(Y+Z));
        }else{
            sum = (X*A) + (Y*B);
        }
        cout<<sum<<endl;
    }
    return 0;
}