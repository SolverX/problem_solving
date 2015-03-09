#include <iostream>
#include <cstdio>
#include <cstring>
#include <string>
#include <map>
#include <vector>
#include <utility>
#include <cmath>
#include <cstdlib>
#include <cctype>
#include <stack>
#include <queue>
#include <algorithm>
using namespace std;
#define INF 999999999
typedef pair<int,int> ii;
typedef unsigned long long ull;
int N,W,R;
int SIZE = 0;
class Feed{
public:
	long times;
	int resolution;
	int points;
	Feed(){
	}
	Feed(int _time,int _points,int _resolution){
		times = _time;
		points = _points;
		resolution = _resolution;
	}
};

vector<Feed> list;
vector<int> resultVector;

int start = 0;
int DP[12001][3001];
int begin1 = 0;
ull resultPoints(int x,int resolution){
	if(DP[x][resolution]) return DP[x][resolution];
	if(x>= list.size()){
		//cout<<"resolution"<<resolution<<endl;
		return 0;
	}
	if(resolution-list[x].resolution < 0){
		return DP[x][resolution]=resultPoints(x+1,resolution);
	}
	if(list[begin1].times-list[x].times <=W){
		return DP[x][resolution]=max(list[x].points+ resultPoints(x+1,resolution-list[x].resolution),resultPoints(x+1,resolution));
	}else{
		begin1++;
		return DP[x][resolution]=resultPoints(x+1,resolution);	
	}
}

void GetPoints(int x,int resolution){
	if(x>=list.size()){
		return;
	}
	if(resolution-list[x].resolution < 0){
		GetPoints(x+1,resolution);
		return;
	}
	if(list[x].points+ resultPoints(x+1,resolution-list[x].resolution) == DP[x][resolution]){
		resultVector.push_back(x+1);
		GetPoints(x+1,resolution-list[x].resolution);
		return;
	}

	GetPoints(x+1,resolution);
}
int main()
{
	freopen("in.txt","r",stdin);
	cin>>N>>W>>R;
	list.assign(N+1,Feed());
	list.clear();
	
	while(N--){
		char c;
		int points,resolution;
		long pub_time;
		cin>>c;
		switch(c){
		case 'S':
			cin>>pub_time>>points>>resolution;
			//if(resolution <= R)
				list.push_back(Feed(pub_time,points,resolution));
			//cout<<points<<endl;
			break;
		case 'R':
			cin>>pub_time;
			memset(DP,0,sizeof(DP));
			resultVector.clear();
			//cout<<pub_time<<endl;
			while(pub_time-list[start].times > W && start < list.size()){
				start++;
			}
			ull result = resultPoints(start,R);
			GetPoints(start,R);
			cout<<result<<" "<<resultVector.size();
			for(int i=0;i<resultVector.size();i++){
				cout<<" "<<resultVector[i];
			}
			cout<<endl;
			break;
		}

	}

		memset(DP,0,sizeof(DP));
		ull result = resultPoints(start,R);
		GetPoints(1,R);
		for(int i=0;i<resultVector.size();i++){
				cout<<" "<<resultVector[i];
		}
		cout<<endl;
	return 0;
}