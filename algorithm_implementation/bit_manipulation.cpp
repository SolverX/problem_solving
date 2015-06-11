#include <iostream>
using namespace std;
int main(){
    int N = 1<<10;
    int M = (1<<4) | (1<<1) | (1<<0);
    int i= 2,j=4;
    int ones = 0;
for(int i=0;i<31;i++){
    ones |= 1<<i;
}
    int left = ones << (j+1);
    int right = (1<<i) -1;
    int mask = left | right;
    int n_cleared = N&mask;
    int mshifted = M << i;
    int ret = n_cleared | mshifted;
    cout<<N<<" "<<M<<" "<<mask<<endl;
    return 0;
}