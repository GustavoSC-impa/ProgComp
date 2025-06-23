#include <bits/stdc++.h>
using namespace std;    
#define ll long long
#define pll pair<ll,ll>
#define pii pair<int, int>
 
int main(){

    ios::sync_with_stdio(false); cin.tie(nullptr);

    int n; cin >> n;

    string isolated, normal; cin >> isolated >> normal;

    double iso = 0, colaps = 0;

    for ( int i = 0; i < n; i++){
        if ( isolated[i] == '*') iso++;
        if ( isolated[i] == '*' and normal[i] != '*') colaps++;
    }

    double ans = colaps/iso;

    std::cout << std::fixed << std::setprecision(2) << ans << std::endl;




    return 0;
}
