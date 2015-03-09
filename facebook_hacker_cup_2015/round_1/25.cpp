#include <iostream>
#include <cstring>
#include <cstdio>
#include <cstdlib>
#include <cmath>
#include <vector>
#include <algorithm>
#include <map>
#include <stack>
using namespace std;
int leftMax = 3,rightMax=2;
int stressfull[2002][2002];
void backtrack(int a,int b){
	if(a>=leftMax || b>=rightMax)
		return;
	cout<<a<<" "<<b<<endl;
	if(a>b)
		stressfull[a][b]++;
	backtrack(a+1,b);
	backtrack(a,b+1);
}

int main(){
	memset(stressfull,0,sizeof(stressfull));
	backtrack(0,0);
	cout<<stressfull[3][1]<<endl;
	return 0;
}