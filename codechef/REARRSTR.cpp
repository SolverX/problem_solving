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

#define FILE_INPUT true

typedef pair<int,int> ii;
typedef vector<int> vi;
typedef vector<ii> vii;
class Char{
public:
    char c;
    int cnt;

};
int cmp(Char a,Char b){
    return a.cnt>b.cnt;
}
int main(){
    if(FILE_INPUT)
        freopen("in.txt","r",stdin);
    int T;
    cin>>T;
    Char a[26];
    
    while(T--){
        string s;
        cin>>s;
        for(int i=0;i<26;i++){
        a[i].cnt=0;
    }
        for(int i=0;i<s.length();i++){

            a[s[i]-'a'].cnt++;
            a[s[i]-'a'].c = s[i];
        }
        sort(a,a+26,cmp);
        string news="";
        char prev='R';
        int sum=0;
        for(int i=1;i<26;i++){
            sum+=a[i].cnt;
        }
        if(a[0].cnt>sum+1){
            cout<<-1<<endl;
            continue;
        }
        while(a[0].cnt>0){
            if(prev!=a[0].c){
                news+=a[0].c;
                a[0].cnt--;
                // cout<<a[0].c<<" ";
                prev=a[0].c;
            }else if(a[1].cnt>0){
                news+=a[1].c;
                a[1].cnt--;
                // cout<<a[1].c<<" ";  
                prev=a[1].c; 
            }else{
                cout<<-1<<endl;
                break;
            }
            
            sort(a,a+26,cmp);
        }
        // cout<<endl;
        cout<<news<<endl;
    }
    return 0;
}