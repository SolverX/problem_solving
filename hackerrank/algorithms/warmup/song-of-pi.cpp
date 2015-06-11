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
#define len(x) sizeof(x)
#define null NULL
#define nil NULL

typedef unsigned long long ull;
typedef unsigned long ul;
typedef vector<int> vi;
typedef pair<int,int> ii;
typedef vector<ii> vii;


int main(){
    freopen("in.txt","rt",stdin);
    int T;
    scanf("%d\n",&T);
    while(T--){
        char s[501];
        gets(s);
        int seq[]={3,1,4,1,5,9,2,6,5,3,5,8,9,7,9,3,2,3,8,4,6,2,6,4,3,3,8,3,3};
        int length = len(seq)/len(int),pos=0;
        bool isPiSong=true;
        char *pch=strtok(s," ");
        while(pch!=NULL){
            int _len = strlen(pch);
            if(_len!=seq[pos++]){ isPiSong=false;break;}
            pch = strtok(NULL," ");
        }
        if(!isPiSong){
            cout<<"It's not a pi song."<<endl;
        }else{
            cout<<"It's a pi song."<<endl;
        }

    }
    return 0;
}