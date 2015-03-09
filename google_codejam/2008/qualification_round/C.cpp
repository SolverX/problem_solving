#include <iostream>
#include <cstdio>
#include <cstring>
#include <cstdlib>
#include <algorithm>
#include <vector>
#include <map>
#include <stack>
#include <queue>
#include <cmath>
#include <cctype>
#include <utility>
using namespace std;
#define PI 22.0/7.0

int main(){
	freopen("in.txt","rt",stdin);
	//freopen("out.txt","wt",stdout);
	int T,tcase=0;
	cin>>T;
	while(T--){
		printf("Case #%d: ",++tcase);
		double f,R,t,r,g;
		cin>>f>>R>>t>>r>>g;
		if(2*f >= g){
			printf("%.6lf\n",1.0);
			continue;
		}
		double radiusInside = R - t;

		double border = (2*(PI*r*r)*(radiusInside))-(r*r);

		double length = r;
		while(length<R){
			
			
		}
		printf("%.6lf\n",border );

	}
	return 0;
}