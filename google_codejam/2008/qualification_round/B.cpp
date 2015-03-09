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

class Station{
public:
	int from,to;
	int pos;
	Station(int _from,int _to){
		from = _from;
		to = _to;
	}

	Station(int _from,int _to,int _pos){
		from = _from;
		to = _to;
		pos = _pos;
	}	
	bool operator < (const Station &s)const{
		if(from < s.from){
			return true;
		}else if(from == s.from){
			return to<s.to;
		}
		return false;
	}
};

int main(){
	freopen("in.txt","r",stdin);
	freopen("out.txt","w",stdout);
	int T,testCase=0;
	scanf("%d\n",&T);
	while(T--){
		int turnAroundTime;
		scanf("%d\n",&turnAroundTime);
		int NA,NB;
		scanf("%d %d\n",&NA,&NB);
		vector<Station> A,B,C;
		for(int i=0;i<NA;i++){
			int sh,sm,eh,em;
			scanf("%d:%d %d:%d\n",&sh,&sm,&eh,&em);
			sh*=(60);

			eh*=(60);
			em+=turnAroundTime;

			A.push_back(Station(sh+sm,eh+em));
			C.push_back(Station(sh+sm,eh+em,1));
		}
		for(int i=0;i<NB;i++){
			int sh,sm,eh,em;
			scanf("%d:%d %d:%d\n",&sh,&sm,&eh,&em);
			sh*=(60);

			eh*=(60);
			em+=turnAroundTime;

			B.push_back(Station(sh+sm,eh+em));
			C.push_back(Station(sh+sm,eh+em,2));
		}

		sort(A.begin(),A.end());
		sort(B.begin(),B.end());
		sort(C.begin(),C.end());

		bool StationA[A.size()];
		bool StationB[B.size()];
		memset(StationA,true,sizeof(StationA));
		memset(StationB,true,sizeof(StationB));



		int tripsLeftA = NA;
		int tripsLeftB = NB;

		int trainsFromA = 0;
		int trainsFromB = 0;

		int go_pos = 0;
		int a_pos = 0;
		int b_pos = 0;
		int start = 0;

		while(tripsLeftA || tripsLeftB){
			int trainArivalTime =0;
			
			while(start < NA+NB){
				int tmp = C[start].pos;
				if(tmp==1){
					start++;
					if(StationA[a_pos++]){
						//cout<<A[a_pos-1].from<<endl;
						go_pos = 1;
						break;
					}

				}else{
					start++;
					if(StationB[b_pos++]){
						//cout<<B[b_pos-1].from<<endl;
						go_pos = 2;
						break;
					}
				}
			}
			
			if(tripsLeftA && go_pos==1){
				trainsFromA++;
				//cout<<trainsFromA<<endl;
				int pos =0;
				while(pos!=-1){
					pos=-1;
					//cout<<NA<<NB<<endl;
					for(int i=0;i<NA;i++){
						if(StationA[i] &&  A[i].from >= trainArivalTime){
							tripsLeftA--;
							StationA[i]= false;
							pos = i;
							trainArivalTime = A[i].to;
							break;
						}
					}


					if(pos==-1)
						break;

					pos = -1;
					for(int i=0;i<NB;i++){
						if(StationB[i] && B[i].from >= trainArivalTime )
						{
							pos = i;
							tripsLeftB--;
							StationB[i] = false;
							trainArivalTime = B[i].to;
							break;
						}
					}
				}

				continue;
			}


			if(tripsLeftB && go_pos==2){
				trainsFromB++;
				//cout<<trainsFromB<<endl;
				int pos =0;
				while(pos!=-1){
					pos=-1;
					for(int i=0;i<NB;i++){
						if(StationB[i] &&  B[i].from >= trainArivalTime){
							tripsLeftB--;
							StationB[i]= false;
							pos = i;
							trainArivalTime = B[i].to;
							break;
						}
					}
					if(pos==-1)
						break;
					pos = -1;
					for(int i=0;i<NA;i++){
						if(StationA[i] && A[i].from >= trainArivalTime )
						{
							pos = i;
							tripsLeftA--;
							StationA[i] = false;
							trainArivalTime = A[i].to;
							break;
						}
					}
					
				}

			}
		}
		printf("Case #%d: %d %d\n",++testCase,trainsFromA,trainsFromB);
	}
	return 0;

}