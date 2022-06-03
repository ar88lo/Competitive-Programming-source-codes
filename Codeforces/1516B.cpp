#include <iostream>

using namespace std;

const int max_n=2010;

int pre[max_n];
int n,t,a;
bool ch;

int main(){

	cin>>t;
	while(t){

		cin>>n;
		cin>>pre[0];
		for(int i=1;i<n;i++){

			cin>>a;
			pre[i]=pre[i-1]^a;
		}

		for(int i=0;i<n-1;i++){

			if(pre[i]==(pre[n-1]^pre[i])) ch=1;
		}

		for(int i=0;i<n-1;i++){

			for(int j=i+1;j<n-1;j++){

				if(pre[i]==(pre[j]^pre[i])&&pre[i]==(pre[n-1]^pre[j])) ch=1;
			}
		}

		if(ch){

			cout<<"YES\n";
			ch=0;
		}
		else{

			cout<<"NO\n";
		}
		t--;
	}
}