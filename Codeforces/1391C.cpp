#include <iostream>

using namespace std;

const long long mod=1e9+7;
long long modfac,modpow;
int n;

int main(){

    cin>>n;
    modfac=modpow=1ll;
    for(int i=1;i<=n;i++){

        modfac=(modfac*i)%mod;
    }
    for(int i=1;i<n;i++){

        modpow=(modpow*2)%mod;
    }
    cout<<modfac-modpow+bool(modfac-modpow<0)*mod<<'\n';
    return 0;
}