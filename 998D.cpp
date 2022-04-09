#include <iostream>

using namespace std;

int ans[]={0,4,10,20,35,56,83,116,155,198,244};
long long n;

int main(){

    cin>>n;
    if(n<11){
        cout<<ans[n];
        return 0;
    }
    cout<<(n-11ll)*49ll+292ll<<'\n';
    return 0;
}