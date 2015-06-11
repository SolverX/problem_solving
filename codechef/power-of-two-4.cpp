# include <iostream>
# include <cstdio>
# include <cstdlib>
# include <algorithm>
# include <map>
# include <vector>
using namespace std;
typedef long long ull;
ull A[2000];
int N;
bool isPossible(int pos,ull res){
    if( res!=0 && (res & res-1)   == 0) return true;
    if(pos>=N) return false;
    bool result =isPossible(pos+1,A[pos]);
    if(result)
        return true;
    result = isPossible(pos+1,res+A[pos]);
    if(result)
        return true;
    result = isPossible(pos+1,res);
    if(result)
        return true;
    

    return false;
}
int main(){
    freopen("in.txt","r",stdin);
    int T;
    cin>>T;
    while(T--){
        
        cin>>N;
        bool found = false;
        ull result = 0;
        for(int i=0;i<N;i++){
            cin>>A[i];
        }
        if(isPossible(0,A[0])){
            cout<<"YES"<<endl;
        }else{
            cout<<"NO"<<endl;
        }
    }
    return 0;
}