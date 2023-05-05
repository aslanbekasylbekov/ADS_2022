#include <iostream>
#include <vector>
using namespace std;
long long workTime(vector <long long> island, long long bagsize){
    long long timeWork = 0;
    for(auto i:island){
        timeWork += (i/bagsize);
        if(i % bagsize!=0) timeWork++;
    }
    return timeWork;
}
int main(){
    long long n,f;
    cin>>n>>f;
    vector<long long> island(n);
    for(long long i=0;i<n;i++){
        cin>>island[i];
    }
    long long l=0,r=1e9+420;
    while(l+1<r){
        long long mid=(l+r)/2;
        long long timeToSanta = workTime(island,mid);
        if(timeToSanta <= f) r = mid;
        else l=mid;
    }
    cout<<r<<endl;
}