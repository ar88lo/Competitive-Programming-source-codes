#include <iostream>

using namespace std;

int n,key,temp;

bool check(int x,bool ch){

    int in;
    if(ch){

        cout<<"? "<<x<<" "<<key<<endl;
    }
    else{

        cout<<"? "<<key<<" "<<x<<endl;
    }
    cin>>in;
    if(in==key) return 1;
    return 0;
}
void solve(int l,int r,bool ch){

    while(r-l>1){

        int m=l+(r-l)/2;
        if((check(m,ch)^ch)){
            r=m;
        }
        else{
            l=m;
        }
    }
    if(ch){
        cout<<"! "<<l<<endl;
    }
    else{

        cout<<"! "<<r<<endl;
    }
}
int main(){

    cin>>n;
    cout<<"? "<<1<<" "<<n<<endl;
    cin>>key;
    if(n==2){

        if(key==2) cout<<"! "<<1<<endl; else cout<<"! "<<2<<endl;
        return 0;
    }
    if(key==n){

        solve(1,key,1);
    }
    cout<<"? "<<key<<" "<<n<<endl;
    cin>>temp;
    if(temp==key){

        solve(key,n,0);
    }
    else{

        solve(1,key,1);
    }
    return 0;
}
//missed corner cases in the first check for key.