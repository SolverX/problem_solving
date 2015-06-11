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

bool isFunny(string a){
    int len = a.length();
    bool isFunny = true;
    for(int i=0;i<len-1;i++){
        if( abs(a[i]-a[i+1]) != abs(a[len-i-1]-a[len-i-2]) ){
            isFunny = false;
            break;
        }
    }
    return isFunny;
}

int main(){
    freopen("in.txt","rt",stdin);
    int T;
    cin>>T;
    while(T--){
        string s;
        cin>>s;
        if(isFunny(s)){
            cout<<"Funny"<<endl;
        }else{
            cout<<"Not Funny"<<endl;
        }
    }
    return 0;
}