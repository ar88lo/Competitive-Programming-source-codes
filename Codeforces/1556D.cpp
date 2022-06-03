#include <algorithm>
#include <iostream>
#include <vector>

using namespace std;

vector<int> g;
int n,k;

int calc(int a,int b){

    int x,y;
    cout<<"or "<<a<<" "<<b<<endl;
    cin>>x;
    cout<<"and "<<a<<" "<<b<<endl;
    cin>>y;
    return (x+y);
}
int main(){

    cin>>n>>k;

    for(int i=2;i<=n;i++){

        int temp=calc(1,i);
        g.push_back(temp);
    }
    int temp=calc(2,3);
    int x=(g[0]+g[1]-temp)/2;
    g.push_back(2*x);
    sort(g.begin(),g.end());
    cout<<"finish "<<g[k-1]-x<<endl;
    return 0;
}