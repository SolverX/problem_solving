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
typedef unsigned long long ul;
typedef vector<int> vi;
typedef pair<int,int> ii;
typedef vector<ii> vii;

#define SIZE 10000000


int getLargestPrime(int number) {
    int factor = number; // assumes that the largest prime factor is the number itself
    for (int i = 2; (i*i) <= number; i++) { // iterates to the square root of the number till it finds the first(smallest) factor
        if (number % i == 0) { // checks if the current number(i) is a factor
            factor = max(i, number / i); // stores the larger number among the factors
            break; // breaks the loop on when a factor is found
        }
    }
    if (factor == number) // base case of recursion
        return number;
    return getLargestPrime(factor); // recursively calls itself
}

int main(){
	freopen("in.txt","rt",stdin);
	//sieve();
	int T;
	cin>>T;
	while(T--){
		int N;
		char c;
		cin>>N>>c;
		switch(c){
			case 'n':
				cout<<N-getLargestPrime(N)<<endl;
				break;
			case 'y':
				int temp = N;
				int val=0;
				int total=0;
				int prev=0;
				do{
					val=getLargestPrime(N);
					
					N-=val;
					total+=val;
					// prev=val;
					cout<<val<<endl;
					//val=getLargestPrime(N);
				}while(val>1);
				cout<<temp+val-total<<endl;
				break;
		}
	}
	return 0;
}