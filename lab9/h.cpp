#include <iostream>
#include <vector>
using namespace std;

vector <long long> prefixFunction(string s){
    vector <long long> pi(s.size());
    for(int i=1;i<s.size();i++){
        long long j=pi[i-1];
        while(j>0 && s[j]!=s[i]){
            j=pi[j-1];
        }
        if(s[j]==s[i]){
            pi[i]=j+1;
        }
        else{
            pi[i]=0;
        }
    }
    return pi;
}

bool kmp(string s,string t){
    s=t+'#'+s;
    vector <long long> res;
    vector <long long> pi=prefixFunction(s);
    for(int i=0;i<s.size();i++){
        if(pi[i]==t.size()){
            return true;
        }
    }
    return false;
}

int main(){
    string s; cin>>s;
    vector <long long> ans;
    int cnt=0;
    vector <long long> pi=prefixFunction(s);
    for(int i=0;i<pi.size();i++){
        ans.push_back(pi[i]);
    }
    for(int i=1;i<s.size()-1;i=i+2){
        long long temp=i+1;
        long long len = temp-ans[i];
        long long isEven = temp/len;
        if(isEven % 2==0){
            cnt++;
        } 
    }
    // S = A + B + C
    // A + C = B + C
    // A = B
    // cnt = 0
    // Find the LPS array
    // Period:  p(n-1) !=0 => k = n - p(n-1) => n % k == 0 => ok
    // ab | abababcx => x
    // abab | ababcx => n = 4 => P(n-1) = 2 => 4 % 2 == 0 ==> cnt = 1;
    // ababab|abcx => n = 6 => P(n-1) = 4 => 6 % 2 == 0 ==> not even 
    // abababab | cx => n = 8 => P(n-1) = 6 => 8 % 2 == 0 ==> cnt = 2;
    cout<<cnt<<endl;
}