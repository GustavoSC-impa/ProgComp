#include <bits/stdc++.h>
using namespace std;    
#define ll long long
 
int main(){
 
    int t; cin >> t;
 
    while (t--){
        ll a, b, c, d; cin >> a >> b >> c >> d;
 
        ll gelly = min(a, c), flower = min(b, d);
 
        if ( gelly >= flower ) cout << "Gellyfish" << '\n';
        else cout << "Flower" << '\n';
    }
    return 0;
}