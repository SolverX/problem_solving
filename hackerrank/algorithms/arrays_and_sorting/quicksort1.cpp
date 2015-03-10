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
int N;
vector<int> A;
int partition(int low,int high){
    int pivotIndex = low;//(low+(high-low))/2;
    int pivotValue = A[pivotIndex];
    int tmp = A[high];
    A[high] = A[pivotIndex];
    A[pivotIndex] = tmp;
    int stored =low;

    for(int i=low;i<=high;i++){
        if(A[i]<pivotValue){
            tmp = A[i];
            A[i]=A[stored];
            A[stored] = tmp;
            stored++;
        }
    }
    // for(int j=high;j>stored;j--){
    //     A[j]=A[j-1];
    // }
    // A[stored]=pivotValue;
    return stored;

}
void quick_sort(int low,int high){
    if(low>=high)
        return;
    // cout<<low<<" "<<high<<endl;
    
    int mid = partition(low,high);
    quick_sort(low,mid-1);
    quick_sort(mid+1,high);

}
int main(){
    freopen("in.txt","rt",stdin);
    cin>>N;
    while(N--){
        int tmp;
        cin>>tmp;
        A.push_back(tmp);
    }
    A.push_back(0);
    partition(0,A.size()-1);
    bool printed = false;
    for(int i=1;i<A.size();i++){
        // if(!printed && A[i])
        cout<<A[i]<<" ";
    }
    cout<<endl;
    return 0;
}