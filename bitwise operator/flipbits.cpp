#include<bits/stdc++.h>
using namespace std;
int flip_bits(int x){
    int n=x;
    n=n|(n>>1);
    n=n|(n>>2);
    n=n|(n>>4);
    n=n|(n>>8);
    n=n|(n>>16);
    x=x^n;
    return x;
}
int main(){
    int x;
    cin>>x;
    cout<<flip_bits(x)<<endl;
    return 0;
}