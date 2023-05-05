#include <bits/stdc++.h> 
using namespace std; 
bool comp(pair<pair<int, int>, int>p1, pair<pair<int, int>, int>p2) { 
    if(p1.second < p2.second) return true; 
    if(p1.second == p2.second && p1.first.second < p2.first.second) return true; 
    if(p1.second == p2.second && p1.first.second == p2.first.second && p1.first.first < p2.first.first) return true; 
    return false; 
} 
int partition(vector <pair<pair<int, int>, int>>& v, int l, int r) { 
    pair<pair<int, int>, int> pivot = v[r]; 
    int i = (l - 1); 
    for(int j = l; j <= r - 1; j++) { 
        if(comp(v[j],pivot)) { 
            i++; 
            swap(v[i],v[j]); 
        } 
    } 
    swap(v[i + 1], v[r]); 
    return (i+1); 
} 
 void quickSort(vector <pair<pair<int, int>, int>>& v, int l, int r) { 
    if(l < r) { 
        int p = partition(v, l, r); 
        quickSort(v, l, p - 1); 
        quickSort(v, p + 1, r); 
    } 
} 
// void print(vector <pair<pair<int, int>, int>>& v) { 
//     for(int i = 0; i < v.size(); i++) { 
//         if(v[i].first.first < 10 && v[i].first.second < 10) cout << "0" << v[i].first.first <<"-0"<<v[i].first.second<<"-"<<v[i].second<<endl; 
//         else if(v[i].first.first < 10 && v[i].first.second >= 10) cout << "0" << v[i].first.first <<"-"<<v[i].first.second<<"-"<<v[i].second<<endl; 
//         else if(v[i].first.first >= 10 && v[i].first.second < 10) cout << v[i].first.first <<"-0"<<v[i].first.second<<"-"<<v[i].second<<endl; 
//         else cout << v[i].first.first <<"-"<<v[i].first.second<<"-"<<v[i].second<<endl; 
//     } 
// } 
int convert(string a, int l, int r) { 
    int beg = 1; 
    int res = 0; 
    for(int i = l; i < r; i++) { 
        if(a[i] == '0' && i == 0) { 
            res = a[i + 1] - '0'; 
            break;  
        } 
        else { 
            res = beg * res + (a[i] - '0'); 
            beg = 10; 
        } 
    } 
    return res; 
} 
int main(){ 
    int n; 
    cin >> n; 
    vector <pair<pair<int, int>, int>> v; 
    for(int i = 0; i < n; i++) { 
        string s; cin >> s; 
        int day = convert(s, 0, 2); 
        int month = convert(s, 3, 5); 
        int year = convert(s, 6, 10); 
        pair<pair<int, int>, int> para; 
        para.first.first = day; 
        para.first.second = month; 
        para.second = year; 
        v.push_back(para); 
    } 
    quickSort(v,0, n - 1); 
    for(int i = 0; i < v.size(); i++) { 
        if(v[i].first.first < 10 && v[i].first.second < 10) cout << "0" << v[i].first.first <<"-0"<<v[i].first.second<<"-"<<v[i].second<<endl; 
        else if(v[i].first.first < 10 && v[i].first.second >= 10) cout << "0" << v[i].first.first <<"-"<<v[i].first.second<<"-"<<v[i].second<<endl; 
        else if(v[i].first.first >= 10 && v[i].first.second < 10) cout << v[i].first.first <<"-0"<<v[i].first.second<<"-"<<v[i].second<<endl; 
        else cout << v[i].first.first <<"-"<<v[i].first.second<<"-"<<v[i].second<<endl; 
    } 
 
}