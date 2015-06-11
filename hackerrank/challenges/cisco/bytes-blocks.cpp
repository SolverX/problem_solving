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

bool isPalindrome(string s){
    int len = s.length();
    for(int i=0;i<len/2;i++){
        if(s[i]!=s[len-i-1]){
            return false;
        }
    }
    return true;
}
int N;
bool visited[1001];
int DP[1001];
map<int,vi> chance;
int findMinmumSize(int u){
    if(u>=N){ return 0;}
    // if(DP[u]!=0) return DP[u];
    if(visited[u]) return findMinmumSize(u+1);
    visited[u]=true;
    int maxValue =99999999;
    for(int i=0;i<chance[u].size();i++){
        int v = chance[u][i];
        if(!visited[v]){
            visited[v]=true;
            maxValue = min(maxValue, 1+findMinmumSize(u+1));
            visited[v]=false;
        }
        
    }
    maxValue = min(maxValue, 1+findMinmumSize(u+1));
    visited[u]=false;
    return DP[u]=maxValue;
}
int main(){
    freopen("in.txt","rt",stdin);
    
    string s[1001];
    while(scanf("%d\n",&N)!=EOF){
        for(int i=0;i<N;i++){
            cin>>s[i];
        }
        int cnt=0;
        chance.clear();
        for(int i=0;i<N;i++){
                visited[i]=false;
                DP[i]=0;
                int found;
                for(int j=i+1;j<N;j++){
                        found = isPalindrome(s[i]+s[j]) || isPalindrome(s[j]+s[i]);
                        if(found){
                            chance[i].push_back(j);
                            // chance[j].push_back(i);
                        }
                        // found = isPalindrome(s[j]+s[i]);
                        // if(found){
                        //     chance[j].push_back(i);
                        // }
                }
        }
        for(int i=0;i<N;i++){
            cout<<i<<" : ";
             for(int j=0;j<chance[i].size();j++){
                cout<<chance[i][j]<<" ";
             }
             cout<<endl;

        }
        for(int i=0;i<N;i++){
            for(int j=0;j<N;j++){
                
            }
        }
        cout<<findMinmumSize(0)<<endl;
    }
    return 0;
}