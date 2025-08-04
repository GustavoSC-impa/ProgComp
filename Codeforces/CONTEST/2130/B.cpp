#include <bits/stdc++.h>
using namespace std;    
#define ll long long
 
int main(){

    ios::sync_with_stdio(false); cin.tie(nullptr);
 
    int t; cin >> t;
 
    while (t--){

        int n, s; cin >> n >> s;
        vector<ll> a ( n, 0);

        ll total = 0;

        ll q[3];

        q[0] = 0; q[1] = 0; q[2] = 0;

        for ( int i = 0; i < n; i++) {
            cin >> a[i];
            total += a[i];
            q[a[i]]++;
        }

        // se o total for maior que o target, couta o atual

        // aqui eu tenho a quantidade de cada um
        if ( s < total){
            for ( ll k : a) cout << k << ' ';
            cout << '\n';
        }
        
        else if ( s == total) {
            cout << "-1\n";
        } 
        
        else{
            if ( s == total + 1){
                while(q[0]--) cout << "0 ";
                while(q[2]--) cout << "2 ";
                while(q[1]--) cout << "1 ";
                cout << '\n';
            } 
            
            else cout << "-1\n";
        }



    }
    return 0;
}


