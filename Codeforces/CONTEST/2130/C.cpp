#include <bits/stdc++.h>
using namespace std;    
#define ll long long
 
int main(){

    ios::sync_with_stdio(false); cin.tie(nullptr);
 
    int t; cin >> t;
 
    while (t--){

        int n; cin >> n;

        vector<   pair<ll,pair<ll,ll>>   > S;

        for ( int i = 1; i <= n; i++){
            ll a, b; cin >> a >> b;
            S.push_back({i, {a, b}});
        }
        

    }
    return 0;
}


