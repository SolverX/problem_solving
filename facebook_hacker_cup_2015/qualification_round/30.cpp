#include<iostream>
#include<cstdio>
#include<cstdlib>
#include<cstring>
#include<cmath>
#include<algorithm>
#include<stack>
#include<map>
using namespace std;
#define SIZE 21

int Gp,Gc,Gf;
int N;
int Tp,Tc,Tf;
int P[SIZE],C[SIZE],F[SIZE];

bool calculate(int pos){
	//cout<<pos<<endl;
	if(Tp==Gp && Gc==Tc && Tf==Gf){
		//cout<<"found Result"<<endl;
		return true;
	}
	if(Tp>Gp || Tc>Gc || Tf>Gf || pos>=N){
		return false;
	}
	
	Tp+=P[pos],Tc+=C[pos],Tf+=F[pos];
	bool result1 = calculate(pos+1);
	Tp-=P[pos],Tc-=C[pos],Tf-=F[pos];
	bool result2 = calculate(pos+1);
	return max(result1,result2);
}

int main(){
	freopen("in.txt","r",stdin);
	int T,Case=0;
	cin>>T;
	while(T--){
		cin>>Gp>>Gc>>Gf;
		cin>>N;
		for(int i=0;i<N;i++){
			cin>>P[i]>>C[i]>>F[i];			
		}
		Tp=Tc=Tf=0;
		bool possible = calculate(0);
		printf("Case #%d: %s\n",++Case,(possible?"yes":"no"));
		//cout<<(possible?"yes":"no")<<endl;
	}
	return 0;
}
