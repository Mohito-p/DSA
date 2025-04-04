#include<bits/stdc++.h>
using namespace std;
int maxpower(int n){
    int temp;
    while(n!=0){
        temp=n;
        n=n&(n-1);
    }
    return temp;
}
//another method
int powerof2(int n){
    n=n|(n>>1);
    n=n|(n>>2);
    n=n|(n>>4);
    n=n|(n>>8);
    n=n|(n>>16);
    return (n+1)>>1;
}
int main(){
    int x;
    cin>>x;
    cout<<maxpower(x)<<endl;
    cout<<powerof2(x)<<endl;
    //for just bigger power of 2
     cout<<maxpower(x)*2<<endl;
    return 0;
}