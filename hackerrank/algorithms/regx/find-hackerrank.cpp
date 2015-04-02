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
    char dummy[2];
    cin>>T;
    gets(dummy);
    while(T--){
        char c[500],first[100],last[100];
        int result=0;
        gets(c);
        char *pch=strtok(c," ");
        strcpy(first,pch);
        result = !(strcmp(first,"hackerrank"));
        while(pch!=NULL){
            strcpy(last,pch);
            pch=strtok(NULL," ");
        }
        result += !(strcmp(last,"hackerrank")) * 2;
        if(result==0)
            cout<<-1<<endl;
        else
            cout<<result%3<<endl;
        // cout<<first<<" "<<last<<endl;
        // cout<<result<<endl;
    }
    return 0;
}