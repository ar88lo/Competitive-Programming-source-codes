#include <iostream>

using namespace std;

long long n,m,k;

//binary search checker function.
bool check(long long f){

    long long ch=0;
    for(long long i=1;i<=m;i++){

        ch+=min(f/i,n);
    }
    if(ch>=k) return 1;
    return 0;
}
int main(){

    cin>>n>>m>>k;
    if(n<m) swap(n,m);

    //perform nice binary search.
    long long l=n*m;
    for(long long u=n*m;u>0;u/=2){

        while(l-u>0&&check(l-u)) l-=u;
    }
    cout<<l<<'\n';
    return 0;
}

//big mistake when writing the binrary search , used if instead of while.