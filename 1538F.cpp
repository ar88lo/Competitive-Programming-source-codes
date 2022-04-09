#include <iostream>

using namespace std;

long long x[10]={1,10,100,1000,10000,100000,1000000,10000000,100000000,1000000000};
long long y[10]={1,11,111,1111,11111,111111,1111111,11111111,111111111,1111111111};
long long l,r;
int t;

long long f(long long a){

	long long ans=0;
	for(long long i=9;i>=0;i--){

		while(a>=x[i]){

			a-=x[i];
			ans+=y[i];
		}
	}
	return ans;
}
int main(){

	cin>>t;
	while(t){

		cin>>l>>r;
		cout<<f(r)-f(l)<<'\n';
		t--;
	}
	return 0;
}