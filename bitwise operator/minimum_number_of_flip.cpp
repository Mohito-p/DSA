#include<bits/stdc++.h>
using namespace std;
int min_flip(int x , int y){
     x=x^y;
     return __builtin_popcount(x);
}
int main (){
    int x,y;
    cin>>x>>y;
    cout<<min_flip(x,y)<<endl;
    return 0;
}