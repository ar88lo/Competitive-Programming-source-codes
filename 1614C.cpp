    #include <iostream>
    #include <math.h>
     
    using namespace std;
     
    const long long mod=1e9+7;
    long long ans;
    long long a;
    int t,n,m;
     
    long long modpow(long long a,int b){
     
    	if(b==0) return 1ll;
     
    	return (b%2)?(modpow(a,b/2)*modpow(a,b/2)*a)%mod : (modpow(a,b/2)*modpow(a,b/2))%mod;
    }
    int main(){
     
    	ios_base::sync_with_stdio(false);
    	cin.tie(0); cout.tie(0);
    	
    	cin>>t;
    	while(t){
     
    		a=0;
    		cin>>n>>m;
    		for(int i=0;i<m;i++){
     
    			long long l,r,temp;
    			cin>>l>>r>>temp;
    			a|=temp;
    		}

            long long x=modpow(2ll,n-1);
            long long j=1;
            while(j<=mod){

                ans+=(a&j)*x;
                ans%=mod;
                j*=2ll;
            }
            cout<<ans<<'\n';
            ans=0;
    		t--;
    	}
    	return 0;
    }