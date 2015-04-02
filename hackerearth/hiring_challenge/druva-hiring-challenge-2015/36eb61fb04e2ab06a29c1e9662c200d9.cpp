#include <iostream>
#include <cstdio>
using namespace std;
 
int main(){
    freopen("in.txt","rt",stdin);
    uint_t  T;
    cin>>T;
    while(T--){
        uint64_t  N;
        
        cin>>N;
        N--;
        uint64_t  tmp=N,num=N;
        uint64_t cnt=0;
        while(tmp>0){
            if(!(tmp&1)){
                num = num|(1<<cnt);
            }
            tmp = tmp >>1;
            cnt++;
        }
        cnt--;
        uint64_t  number = num>>1;
        number++;
        // cout<<number<<endl;
        if(num!=0){
            N=(N-number+1)<<1;
        }else{
            N=1;
        }
        cout<<num<<" "<<N<<endl;
    }
    return 0;
}