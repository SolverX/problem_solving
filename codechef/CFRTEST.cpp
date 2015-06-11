#include <iostream>
#include <cstring>
#include <cstdio>
#include <string>
#include <algorithm>
#include <map>
#include <cstdlib>
#include <cmath>
#include <utility>
#include <cctype>
#include <stack>
#include <queue>
#include <list>
#include <vector>
using namespace std;

#define FILE_INPUT false

typedef pair<int,int> ii;
typedef vector<int> vi;
typedef vector<ii> vii;

int main(){
    if(FILE_INPUT)
        freopen("in.txt","r",stdin);
    int T;
    cin>>T;
    while(T--){
        int N;
        cin>>N;
        int minVal = 0;
        map<int,bool> val;
        while(N--){
            int tmp;
            cin>>tmp;

            minVal+= !val[tmp];
            val[tmp]=true;
        }
        cout<<minVal<<endl;
    }
    return 0;
}