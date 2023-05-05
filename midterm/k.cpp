#include <iostream>
#include <deque>
#include <algorithm>
using namespace std;
int main(){
    deque <int> foo;
    bool ok = false;
    int n; cin >> n;
    int cnt = 0;
    for(int i=0;i<n;i++){
        int t; cin >> t;
        if(t==1){
            int a; cin >> a;
            if(ok == false)
            foo.push_back(a);
            else if(ok == true)
            foo.push_front(a);

        }
        else if(t==2){
            if(ok == false)
            ok = true;
            else
            ok = false;
            cnt++;

        }
    }
    if(cnt % 2 == 1){
        while(!foo.empty()){
            cout <<foo.back() <<" ";
            foo.pop_back();
        }
    }
    else{
        while(!foo.empty()){
            cout <<foo.front() <<" ";
            foo.pop_front();
        }
    }
}