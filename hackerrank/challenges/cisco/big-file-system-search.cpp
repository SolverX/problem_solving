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
typedef pair<long,long> ii;
typedef vector<ii> vii;

map< long , vi > SET;
long SUM[400];
vector<long> LIST;
bool query_all(long pos){
    int curpos =0;
    int found = 0;
    for(long i=0;i<LIST.size();i++){
        long item = LIST[i];
        if(curpos>=SUM[pos]){
            return false;
        }
        for(;curpos<SUM[pos];curpos++){
            if(item == SET[pos][curpos]){
                curpos++;
                found++;
                break;
            }
            if(item < SET[pos][curpos]){
                break;
            }
        }
    }
    return found==LIST.size();
}

bool query_any(long pos){
    int curpos = 0;
    for(long i=0;i<LIST.size();i++){
        long item = LIST[i];
        if(curpos>=SUM[pos]){
            return false;
        }
        for(;curpos<SUM[pos];curpos++){
            if(item == SET[pos][curpos]){
                return true;
            }
            if(item < SET[pos][curpos]){
                break;
            }
        }
    }
    return false;
}

bool query_some(long pos){
    return !query_all(pos) && query_any(pos);
}
int main(){
    freopen("in.txt","rt",stdin);
    long T,N;
    cin>>N;
    for(long i=0;i<N;i++){
        cin>>T;
        while(T--){
            long tmp;
            cin>>tmp;
            SET[i].push_back(tmp);
        }
        SUM[i]=SET[i].size();
        sort(SET[i].begin(),SET[i].end());
    }
    long Q;
    cin>>Q;
    while(Q--){
        long type,number;
        cin>>type>>number;
        LIST.clear();
        while(number--){
            long tmp;
            cin>>tmp;
            LIST.push_back(tmp);
        }
        sort(LIST.begin(),LIST.end());
        long cnt = 0;
        switch(type){
            case 1:
                for(long i=0;i<N;i++){
                    cnt += query_all(i);
                }
                break;
            case 2:
                for(long i=0;i<N;i++){
                    cnt += query_any(i);
                }
                break;
            case 3:
                for(long i=0;i<N;i++){
                    cnt += query_some(i);
                }
                break;
        }
        cout<<cnt<<endl;

    }

    return 0;
}