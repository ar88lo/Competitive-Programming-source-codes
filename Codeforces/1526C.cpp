#include <iostream>
#include <queue>
#include <vector>

using namespace std;

priority_queue<int,vector<int>,greater<int>> q;
int n,ans;
long long p,sum;

int main(){

	cin>>n;
	q.push(0);
	for(int i=0;i<n;i++){

		cin>>p;
		if(p+sum>=0){

			q.push(p);
			sum+=p;
			ans++;
		}
		else if(p>q.top()){

			sum-=q.top();
			sum+=p;
			q.pop();
			q.push(p);
		}
	}

	cout<<ans<<'\n';
	return 0;
}