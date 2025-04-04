#include <bits/stdc++.h>
using namespace std;
string deccimalToBinaray(int n){
    string result="";
    while(n>0){
        if(n%2==0){
            result='0'+result;
        }
        else{
            result='1'+result;
        }
        n=n>>1;
    }
    return result;
}
int main(){
    int x;
    cin>>x;
    cout<<deccimalToBinaray(x)<<endl;
    return 0;
}
