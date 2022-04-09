#include <iostream>
#include <vector>
#include <set>

using namespace std;

const int max_n=101;
int ans1,ans2,temp;
int n;

vector<pair<int,int>> g[max_n];
bool ch[max_n];

void dfs(int u,int p){

    ch[u]=1;
    if(u==1){

        ch[1]=0;
    }
    for(auto v:g[u]){

        if(v.first!=p&&ch[v.first]==0){

            temp+=v.second;
            dfs(v.first,u);
        }
    }
}
void clear(){

    for(int i=0;i<=n;i++){

        ch[i]=0;
    }
    temp=0;
}
int main(){

    cin>>n;
    for(int i=0;i<n;i++){

        int u,v,w;
        cin>>u>>v>>w;
        g[u].push_back({v,0});
        g[v].push_back({u,w});
    }


    dfs(1,g[1][0].first);
    ans1=temp;

    clear();

    dfs(1,g[1][1].first);
    ans2=temp;
    
    cout<<min(ans1,ans2)<<'\n';
    return 0;
    
}