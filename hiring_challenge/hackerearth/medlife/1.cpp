#include <iostream>
#include <cstdio>
#include <cstring>
#include <cstdlib>
#include <string>
#include <algorithm>
#include <vector>
#include <map>
#include <cmath>
#include <utility>
using namespace std;

typedef pair<int,int> ii;
typedef vector<int> vi;
typedef vector<ii> vii;

#define MAX_SIZE 1000001

map<long,bool> is_prime;
vector<long> primes;

void sieve(){
	for(long i=2;i<MAX_SIZE;i++){
		if(!is_prime[i]){
			for(long j=i*i;j<MAX_SIZE;j+=i)
				is_prime[j]=true;
			primes.push_back(i);
		}
		//cout<<i<<endl;
	}

}
int main(){
	sieve();
	map<long,long> counts;
	for (int j = 0; j< primes.size(); ++j) {
  			counts[j] = 0;
  		for (int i = 4/ primes[j]; i; i /= primes[j])
    		counts[j] += i; 
	}
	cout<<counts[4]<<endl;
	return 0;
}