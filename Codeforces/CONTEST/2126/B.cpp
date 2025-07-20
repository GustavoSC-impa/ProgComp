#include <bits/stdc++.h>
using namespace std;    
#define ll long long
 
int main(){
 
    int t; cin >> t;
 
    while (t--){

        

        int n, k; cin >> n >> k;

        vector<int> a (n, 0);

        for ( int i = 0 ; i < n; i++) cin >> a[i];

        int hike = 0, ans = 0;

        for ( int i = 0; i < n; i++){
            if ( a[i] == 0){ // clima está bom
                hike++;

                if ( hike == k ){
                    ans++; hike = 0; i++;
                }
            } else{
                    hike = 0;
            }
        }

        cout << ans << '\n';




    }
    return 0;
}


