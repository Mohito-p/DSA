#include<bits/stdc++.h>
using namespace std;

void permutation(string input, string output){
    if(input.length()==0){
        cout<<output<<endl;
        return;
    }
    for(int i = 0;i<input.length();i++){
        char ch=input[i];
        string left=input.substr(0,i);
        string right=input.substr(i+1);
        string rest=left+right;
        permutation(rest, output+ch);
    }
}
void backtrackingPermutation(string input, int i){
    if(i==input.length()- 1){
        cout<<input<<endl;
        return;
    }
    unordered_set<char>s;
    for(int j=i;j<input.length();j++){
        if(s.count(input[j])) continue;
        s.insert(input[j]);
        swap(input[i], input[j]);
        backtrackingPermutation(input, i+1);
        swap(input[i], input[j]);
    }
}
int main(){
    string input;
    cin>>input;
    string output = "";
    //permutation(input, output);
    backtrackingPermutation(input,0);
    return 0;
}