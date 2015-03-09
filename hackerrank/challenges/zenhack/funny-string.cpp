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
    int t;
    cin>>t;
    while(t--){
        string s;
        cin>>s;
        int len = s.length();
        bool isfunny = true;
        for(int i=0,j=len-1;i<len-1;i++,j--){
            if(abs(s[i]-s[i+1]) != abs(s[j]-s[j-1])){
                isfunny = false;
                break;
            }
        }
        if(isfunny){
            cout<<"Funny"<<endl;
        }else{
            cout<<"Not Funny"<<endl;
        }
    }
    return 0;
}