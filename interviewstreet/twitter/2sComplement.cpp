#include <iostream>
#include <cstdio>
#include <cstring>
#include <cstdlib>
#include <cmath>
#include <string>
#include <algorithm>
#include <vector>
#include <map>
using namespace std;
map<int,int> MAP;
long long solve(int a)
{
 if(a == 0) return 0 ;
 if(a % 2 == 0) return solve(a - 1) + __builtin_popcount(a) ;
 return ((long long)a + 1) / 2 + 2 * solve(a / 2) ;
}
 
long long solve(int a,int b)
{
 if(a >= 0)
 {
  long long ret = solve(b) ;
  if(a > 0) ret -= solve(a - 1) ;
  return ret ;
 }
 long long ret = (32LL * -(long long)a) - solve(~a) ;
 if(b > 0) ret += solve(b) ;
 else if(b < -1)
 {
  b++ ;
  ret -= (32LL * -(long long)b) - solve(~b) ;
 }
 return ret ;
}
int main(){
	freopen("in.txt","rt",stdin);
	int T;
	cin>>T;
	while(T--){
		int A,B;
		unsigned long long sum=0;
		cin>>A>>B;
		cout<<solve(A,B)<<endl;
	}
	int a= -2;
	cout<<(32LL * -(long long)a) - solve(~a) <<endl;
	return 0;
}