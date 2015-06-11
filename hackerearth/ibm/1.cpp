#include <iostream>
#include <cstdio>
#include <algorithm>
#include <cmath>
using namespace std;
int main(){
    freopen("in.txt","r",stdin);
    long N;
    long maxSpeedDom=0,maxSpeedBrain=0;
    cin>>N;
    long current=0,prev;
    for(int i=0;i<N;i++){
        prev=current;
        cin>>current;
        if(i==0)
            continue;
        maxSpeedDom = max(maxSpeedDom ,abs(current-prev));
    }
    for(int i=0;i<N;i++){
        prev=current;
        cin>>current;
        if(i==0)
            continue;
        maxSpeedBrain = max(maxSpeedBrain ,abs(current-prev));
    }

    if(maxSpeedBrain==maxSpeedDom){
        cout<<"Tie"<<endl<<maxSpeedDom;
    }else if(maxSpeedDom>maxSpeedBrain){
        cout<<"Dom"<<endl<<maxSpeedDom;
    }else {
        cout<<"Brain"<<endl<<maxSpeedBrain;
    }
    cout<<endl;
    return 0;
}