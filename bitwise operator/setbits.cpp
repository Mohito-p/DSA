#include<bits/stdc++.h>
using namespace std;
int count_set_bits(int n){ //in built function in c++
    return __builtin_popcount(n);
}
// function made by me to count the bits
// brian kerniglen's algorithm
int count_bits_set(int x){
    int  result =0;
    while(x>0){
        x=x&(x-1);
        result++;
    }
    return result;
}
int f(int x){
    int count=0;
    while(x>0){
        count+=(x&1);
        x>>=1;
    }
    return count;
}
int main(){
    int x;
    cin>>x;
    cout<<count_set_bits(x)<<endl;
    cout<<count_bits_set(x)<<endl;
    cout<<f(x)<<endl;
    return 0;
}