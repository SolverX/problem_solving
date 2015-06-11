#include <iostream>
#include <cstdio>
#include <cstring>
#include <cstdlib>
#include <cmath>
using namespace std;
#define SIZE 1000001
typedef unsigned long long ull;

int main(){
    freopen("in.txt","r",stdin);
    // freopen("out.txt","w",stdout);
    int T;
    // generate();
    int tcase =0;
    cin>>T;
    while(T--){
        int R,C,W;
        cin>>R>>C>>W;
        long result= ((R*C)/W)+(W-1);
        printf("Case #%d: %ld\n",++tcase,result);
    }
    return 0;
}