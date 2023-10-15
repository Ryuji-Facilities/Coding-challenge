#pragma GCC optimize("Ofast")
// #pragma GCC target("sse,sse2,sse3,ssse3,sse4,popcnt,abm,mmx,avx,avx2,fma") // if the machine use intel
#pragma GCC optimize("unroll-loops")
#include <bits/stdc++.h>  
 
using namespace std;

typedef long long ll;
#define fast_cin() ios_base::sync_with_stdio(false); cin.tie(NULL); cout.tie(NULL)

int main()
{
 
    #ifndef ONLINE_JUDGE
    freopen("input.in", "r", stdin);
    freopen("output.out", "w", stdout);
    #endif
 
    fast_cin();
    ll x;
    cin >> x;
    
    if(x%2==0) x-=1;

    for (int i = 1; i <= x; i++) {
        for (int j = 1; j <= x; j++) {
            if (i == j || i + j == x + 1) {
                cout << "*";
            } else {
                cout << " ";
            }

            if (j < x) {
                cout << " ";
            }
        }
        cout << endl;
    }
    return 0;
}