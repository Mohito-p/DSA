#include<bits/stdc++.h>
using namespace std;
int binary_t0_decimal(string &binary){
    int n=binary.size();
    int result=0;
    for(int i=n-1;i>=0;i--){
        char ch=binary[i];
        int num=ch-'0';
        result=result+num*(1<<(n-i-1));
    }
    return result;
}
int main(){
    string str;
    cin>>str;
    cout<<binary_t0_decimal(str)<<endl;
    return 0;
}