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


int main(){
  freopen("in.txt","rt",stdin);
  int T;
  vector<int> A;
  cin>>T;
  for(int i=0;i<T;i++){
    int tmp;
    cin>>tmp;
    A.push_back(tmp); 
  }
  for(int i=1;i<T;i++){
    int j = i;
    while(j>0 && A[j-1]>A[j]){
      int tmp = A[j];
      A[j]=A[j-1];
      A[j-1]=tmp;
      j--;
    }
    for(int k=0;k<T;k++){
      if(k!=0) cout<<" ";
      cout<<A[k];
    }
    cout<<endl;
  }
  return 0;
}