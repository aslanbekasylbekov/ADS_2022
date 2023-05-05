#include <bits/stdc++.h>
using namespace std;
bool cmp(pair<pair<string,string>,double>p1,pair<pair<string,string>,double>p2){
    if(p1.second<p2.second) return true;
    if(p1.second==p2.second && p1.first.first<p2.first.first) return true;
    if(p1.second==p2.second&& p1.first.first==p2.first.first&& p1.first.second<p2.first.second) return true;
    return false;
}
int partition_GPA(vector<pair<pair<string, string>,double>>&v,int l,int r){
    pair<pair<string, string>,double>pivot = v[r];
    int i=l-1;
    for(int j=l;j<=r-1;j++){
        if(cmp(v[j],pivot)){
            i++;
            swap(v[i],v[j]);
        }
    }
    swap(v[i+1],v[r]);
    return (i+1);
}
void quick_sort_GPA(vector<pair<pair<string, string>,double>>&v,int l,int r){
    if(l<r){
        int pi=partition_GPA(v,l,r);
        quick_sort_GPA(v,l,pi-1);
        quick_sort_GPA(v,pi+1,r);
    }
}
void quick_sort_Surname(vector <pair<pair<string,string>,double>>&v,int l,int r){
    if(r<l+1) return;
    int mid=(l+r)/2;
    pair<pair<string, string>,double>pivot=v[mid];
    int j=l;
    swap(v[r],v[mid]);
    for(int i=l;i<=r;i++){
        if(v[i].first.first<pivot.first.first){
            swap(v[i],v[j]);
            j++;
        }
    }
    swap(v[j],v[r]);
    quick_sort_Surname(v,l,j-1);
    quick_sort_Surname(v,j+1,r);
}
void quick_sort_Name(vector <pair<pair<string,string>,double>>&v,int l,int r){
    if(r<l+1) return;
    int mid=(l+r)/2;
    pair<pair<string, string>,double>pivot=v[mid];
    int j=l;
    swap(v[r],v[mid]);
    for(int i=l;i<=r;i++){
        if(v[i].first.second<pivot.first.second){
            swap(v[i],v[j]);
            j++;
        }
    }
    swap(v[j],v[r]);
    quick_sort_Name(v,l,j-1);
    quick_sort_Name(v,j+1,r);
}
int main(){
    int n; cin>>n;
    vector<pair<pair<string,string>,double>>v;
    map <string, double> mapik {{"A+", 4.00}, {"A", 3.75}, {"B+", 3.50}, {"B", 3.00}, {"C+", 2.50}, {"C", 2.00}, {"D+", 1.50}, {"D", 1.00}, {"F", 0}};
    for(int i=0;i<n;i++){
        string s,x; cin>>s>>x;
        int k; cin>>k;
        double res=0;
        int cnt_sum=0;
        for(int i=0;i<k;i++){
            string a; cin>>a;
            int b; cin>>b;
            res+=mapik[a]*b;
            cnt_sum+=b;
        }
        res/=cnt_sum;
        pair<pair<string,string>,double> para;
        para.first.first=s;
        para.first.second=x;
        para.second=res;
        v.push_back(para);
    }
    quick_sort_GPA(v,0,v.size()-1);

    for(auto i:v){
        cout<<i.first.first<<" "<<i.first.second<<" ";
        printf("%0.3f",i.second);
        cout<<endl;
    }
}