# include <iostream>
# include <cstdio>
# include <cstdlib>
# include <algorithm>
# include <map>
# include <vector>
using namespace std;
typedef long long ull;
int N;
class Piece{
public:
    ull h,w;
const bool operator < (Piece o)const{
    // if(h<o.h)
    //     return true;
    // else if(h==o.h){
    //     return w<o.w;
    // }else{
    //     return false;
    // }
    return (h<o.h && w<o.w);
}
};
int tmp(Piece a,Piece b){
    if(a.h<b.h)
        return true;
    else if(a.h==b.h){
        return a.w<b.w;
    }
    return false;
}
Piece pieces[201];
static ull DP[200];
ull maxiHeight(int pos){
    if(pos==0) return pieces[0].h;
    if(DP[pos]!=0) return DP[pos];
    ull height = pieces[pos].h;
    ull add =0;
    for(int i=0;i<pos;i++){
        if(pieces[i] < pieces[pos]){
           // add = pieces[i].h;
           height = max(height,pieces[pos].h+maxiHeight(i));
            // cout<<pos<<" "<<add<<endl;
        }
        
        // cout<<height<<endl;
    }
    // height = max(height,maxiHeight(pos+1));
    // cout<<height<<endl;
    return DP[pos]=height;
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
            DP[i]=0;
            cin>>pieces[i].w>>pieces[i].h;
        }
        sort(pieces,pieces+N,tmp);
        // for(int i=0;i<N;i++) {
        //     cout<<pieces[i].h<<" "<<pieces[i].w<<endl;
        // }
        // cout<<endl;
        ull maxH = 0;
        for(int i=N-1;i>=0;i--){
            maxH= max(maxiHeight(i),maxH);
        }
        cout<<maxH<<endl;
    }
    return 0;
}