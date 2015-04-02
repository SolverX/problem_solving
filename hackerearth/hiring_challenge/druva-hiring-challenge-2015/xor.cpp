#include <iostream>
#include <algorithm>
using namespace std;

int main() {
    int N = 10000000;
    int maxN=0;

    for(int i=1;i<N;i++){
        maxN = max(maxN, N^i);
    }
int cnt = 0;
    for(int i=0;i<N;i++){
        for(int j=0;j<N;j++){
            if( (i^j) == maxN){
                cnt++;
            }
        }
    }
    cout<<maxN<<" "<<cnt<<endl;
    return 0;
}