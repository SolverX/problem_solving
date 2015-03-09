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
int A,B;
bool print = false;

class BigInteger{
public:
	int a[46953];
	int size;
	BigInteger(){
		memset(a,0,sizeof(a));

		size=0;
	}
	BigInteger(int N){
		//if(print) cout<<0<<endl;
		memset(a,0,sizeof(a));
		size=0;
		do{
			a[size++]=N%10;
			N/=10;
			//cout<<N<<endl;
		}while(N!=0);
	}
	BigInteger operator+ (const BigInteger &temp){
		// if(print) cout<<0<<endl;
		BigInteger O = temp;

		for(int i=0;i<size;i++){
				int j=i,sum=a[i];

				while(sum!=0){
					sum = sum+O.a[j];
					O.a[j]= sum%10;
					sum/=10;
					j++;
					
				}
				if(j>O.size) O.size=j;
		}
		return O; 
	}
	// BigInteger operator= (const BigInteger &temp){
	// 	BigInteger O = BigInteger(0);
	// 	O.size = temp.size;
	// 	for(int i=0;i<temp.size;i++)
	// 		O.a[i]=temp.a[i];
	// 	return O;
		
	// }
	BigInteger operator* (const BigInteger &temp){
		//return temp;
		BigInteger O = temp;
		BigInteger result = BigInteger(0);
		for(int i=0;i<size;i++){
			//BigInteger tempresult= BigInteger(0);
				int j=0,multiplication=0,reminder=0,pos=i;
				while(reminder!=0 || O.size>=j){
					multiplication = a[i]*O.a[j] + reminder;
					reminder/=10;
					int tempsum = result.a[pos] +multiplication%10;
					result.a[pos] = tempsum%10;
					reminder += multiplication/10;
					reminder += tempsum/10;
					j++;
					pos++;
					//cout<<reminder<<endl;
					//return O;
				}
				if(pos>result.size) result.size=pos;
				//result = result + tempresult;
				//return O;
		}
		while(result.a[result.size-1]==0) result.size--;
		return result; 
	}

};


BigInteger FIB[10];
BigInteger fib(int n){
	if(n == 0) return BigInteger(0);
	if(n == 1) return BigInteger(A);
	if(n == 2) return BigInteger(B);
	if(FIB[n].size!=0) return FIB[n];
	//cout<<n<<endl;
	return FIB[n]= (fib(n-1) *fib(n-1) )+ fib(n-2);
}
BigInteger fact(int n){
	if(n==0) return BigInteger(1);
	return BigInteger(n)*fact(n-1);
}
int main(){
	freopen("in.txt","rt",stdin);
	memset(FIB,0,sizeof(0));
	int N;
	cin>>A>>B>>N;
	FIB[1] = BigInteger(A);
	FIB[2] = BigInteger(B);
	//cout<<FIB[2].size<<endl;
	//BigInteger result = fib(9);
	//BigInteger test = fib(3);
	//BigInteger temp = BigInteger(2) + BigInteger(3);
	print = true;
	BigInteger result = fact(100);//+BigInteger(0);//+fib(9);
	cout<<result.size<<endl;
	for(int i=result.size-1;i>=0;i--){
		cout<<result.a[i];
	}
	cout<<endl;
	return 0;
}