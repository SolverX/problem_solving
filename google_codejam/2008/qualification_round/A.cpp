/*
CORRECT: Small & Large 
INCORRECT:
Score : 5 + 20 = 25 
*/
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

int main(){
	freopen("in.txt","r",stdin);
	freopen("out.txt","w",stdout);
	int T,testCase=0;
	scanf("%d\n",&T);
	while(T--){
		map<string,int> searchEngineRequests;
		searchEngineRequests.clear();
		int S;
		scanf("%d\n",&S);

		char searchEngineName[1024];
		for(int i=0;i<S;i++){
			gets(searchEngineName);
			searchEngineRequests[searchEngineName] = 1;
			//cout<<searchEngineName<<endl;
		}

		int Q;
		scanf("%d\n",&Q);

		int swaps = 0;
		int uniqueCount = 0;
		char query[1024];
		for(int i=0;i<Q;i++){
			gets(query);

			if(uniqueCount<S){
				if(searchEngineRequests[query]==1){
					searchEngineRequests[query]=2;
					uniqueCount++;
				}				
			}
			if(uniqueCount>=S){
				uniqueCount=1;
				swaps++;
				for(map<string,int>::iterator it=searchEngineRequests.begin();it!=searchEngineRequests.end();it++){
					searchEngineRequests[it->first]=1;
				}
				searchEngineRequests[query]=2;
			}
		}
		printf("Case #%d: %d\n",++testCase,swaps);
	}
	
	return 0;
}