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
typedef vector<long> vi;
typedef pair<int,int> ii;
typedef vector<ii> vii;

int cmp(long a,long b){
    return a>b;
}
// int total(vi list){
//     if(list.size()<=0) return 0;

//     vi a = list;
//     vi b = list;

//     sort(a.begin(),a.end());

//     long val =b[i]/2;
//     b[i] -= val;
//     b.push_back(val);
//     sort(b.begin(),b.end());
// }
vi pancakes;
int main(){
    freopen("in.txt","rt",stdin);
    freopen("out.txt","wt",stdout);
    int T,tcase=1;
    cin>>T;
    while(T--){
        int N;
        cin>>N;
        long MaxValue =0;
        map<int,bool> TEST;
        for(int i=0;i<N;i++){
            long tmp;
            cin>>tmp;
            if(!TEST[tmp]){
                // TEST[tmp]=true;
                pancakes.push_back(tmp);
            }
            MaxValue = max(MaxValue,tmp);

        }
        long result = 0;
        sort(pancakes.begin(),pancakes.end(),cmp);
       while(pancakes.size()){
            result++;
            // for(int i=0;i<pancakes.size();i++){
            //     cout<<pancakes[i]<<" ";
            // }
            // cout<<endl;
            if(pancakes[pancakes.size()-1]<=2){
                for(int i=pancakes.size()-1;i>=0;i--){
                    pancakes[i]--;
                    if(!pancakes[i]){
                        pancakes.pop_back();
                    }
                }
            }else{
                int i=0;
                long val =pancakes[i]/2;
                pancakes[i] -= val;
                pancakes.push_back(val);
                
            }
            sort(pancakes.begin(),pancakes.end(),cmp);
        }
        pancakes.clear();
        if(result>MaxValue)
            result = MaxValue;
        printf("Case #%d: %ld\n",tcase++,result);
    }
    return 0;
}