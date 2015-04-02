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

#define MOD 1000000007
typedef unsigned long long ull;
typedef unsigned long ul;
typedef vector<int> vi;
typedef pair<int,int> ii;
typedef vector<ii> vii;

int main(){
    freopen("in.txt","rt",stdin);
    string s;
    map<char,ull> OCCURANCE;
    map<char,ull> SUM;
    map<int,ull> COUNT;
    cin>>s;
    ull total=0;
    for(int i=0;i<s.length();i++){
        char c = s[i];
        // if(COUNT[i]!=0){
            SUM[c] = (SUM[c]+OCCURANCE[c])%MOD;
            COUNT[c] = (SUM[c]+COUNT[c])%MOD;
        // }
        OCCURANCE[c]++;
    }
    for(int i='a';i<='z';i++){
         total = (total+COUNT[i])%MOD;
    }
    cout<<total<<endl;
    return 0;
}