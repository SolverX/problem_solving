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

class Process{
public:
    int Batch;
    int person;
bool operator <(const Process o) const{
    return Batch<o.Batch;
}

};
int main()
{
    freopen("in.txt","rt",stdin);
    int T;
    cin>>T;
    Process A[T];
    int MAP[T];
    long sum = 0;
    for(int i=0;i<T;i++){
        cin>>A[i].Batch;
        A[i].person=0;
        sum+=A[i].Batch;
    }
    sort(A,A+T);
    int Q;
    cin>>Q;
    long total = 0;
    while(Q--){
        int N;
        cin>>N;
        int tmp,tmpTotal=0;
        for(int i=0;i<N;i++){
            cin>>tmp;
            tmpTotal +=tmp;
        }
        int profit;
        cin>>profit;
        if(tmpTotal <= profit+1){
            total+=profit;
        }
        cout<<total<<" "<<sum<<endl;
    }
    
    if(total>sum){
        cout<<total-sum<<endl;
    }else{
        cout<<0<<endl;
    }

    return 0;
}