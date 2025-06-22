#include <bits/stdc++.h>
using namespace std;    
#define ll long long



int main(){

    vector<pair<ll,ll>> core;

    core.push_back({1,2}); // 0
    core.push_back({1,3}); // 1
    core.push_back({2,2}); // 2
    core.push_back({3,2}); // 3
    core.push_back({3,3}); // 4
    core.push_back({4,2}); // 5
    core.push_back({4,4}); // 6
    core.push_back({4,6}); // 7
    core.push_back({8,1}); // 8

    ll pos; cin >> pos;

    ll a = 0, b = 9, mid;
    while ( a < b){
        mid = (a+b)/2;
        if ( core[mid].first > pos) b = mid - 1;
        if ( core[mid].first < pos) a = mid + 1;
        if ( core[mid].first == pos) {a == mid;break;}
    }

    cout << a;

}