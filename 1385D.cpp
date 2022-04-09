#include <iostream>
#include <string>

using namespace std;

const int max_n=2e5+10;
string s;
int n,t;

int solve(int l,int r,char c){

	int m=(r-l)/2;
	if(m==0){

		return bool(s[l]!=c);
	}
	if(m==1){
		
		if(s[l]==c&&s[l+m]==char(c+1)) return 0;

		if(s[l]==char(c+1)&&s[l+m]==c) return 0;

		if(s[l]==c||s[l+m]==c) return 1;

		if(s[l]==char(c+1)||s[l+m]==char(c+1)) return 1;

		return 2;
	}
	int t1,t2;
	t1=t2=0;
	for(int i=l;i<l+m;i++){

		if(s[i]!=c) t1++;
	}
	for(int i=l+m;i<r;i++){

		if(s[i]!=c) t2++;
	}

	return min(t1+solve(l+m,r,char(c+1)),t2+solve(l,l+m,char(c+1)));
}
int main(){

	ios_base::sync_with_stdio(0);
	cin.tie(0); cout.tie(0);

	cin>>t;
	while(t){

		cin>>n>>s;
		cout<<solve(0,n,'a')<<'\n';
		t--;
	}
	return 0;
}