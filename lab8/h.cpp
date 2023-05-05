#include <bits/stdc++.h>
using namespace std;
long long MOD = 1e9;
long long Da = 256;
long long P=31;
long long N=1e5;

int a[N];
string search(vector<string> s){
    string m="";
    int mxn=0, l;
    ll ht1=0, curX = 1;
    a[N]={0};
    for(int i=0; i<s[1].size(); i++){
        ll ht =0;
        ht1 = (s[1][i]-'a'+1)*curX%MOD; 
        ll p_pow=1;
        pair<ll, string> hash;
        for(int j=s[0].size()-1; j>=0; j--){
            ht=(s[0][j] - 'a' + 1)*p_pow%MOD;
            if(ht==ht1) a[j+1]=a[j]+1; 
            else a[j+1]=0;
            if(a[j+1]>mxn){
                mxn=a[j+1];
                l=j-mxn+1;
            }
        }
    }
    if(mxn==0)return "";
    return s[0].substr(l, mxn);
}

int main(){
    int n; cin>>n;
    string str, s1; cin>>str;
    for(int i=0; i<n-1; i++){
        cin>>s1;
        vector<string> s;
        s.push_back(str); s.push_back(s1);
        str = find(s);
    }
    cout<<str;
}
