#include <bits/stdc++.h>
using namespace std;
int main() {
    int n;
    cin>>n;
    map<string,string>names;
    map<string,string>origNames;
    vector<string>origs;
    for(int i = 0;i < n;i++) {
        string oldName,newName;cin>>oldName>>newName;
        names[oldName] = newName;
        origNames[newName] = oldName;
        if(origNames[oldName] == "") origs.push_back(oldName);
    }
    vector< pair < string,string > > sorted;
    for(auto i: origs) {
        string orig = i;
        while(names[i]!="") {
            if(names[i] == orig) {i = names[i];break;}
            i = names[i];
        }
        sorted.push_back(make_pair(orig,i));
    } 
    cout << sorted.size() << '\n';  
    for(int i = sorted.size()-1;i >= 0;i--) {
        cout << sorted[i].first <<" "<< sorted[i].second << "\n";
    }   
}