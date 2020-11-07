#include <bits/stdc++.h>
#include <math.h>
using namespace std;
typedef long long ll;
typedef unsigned long long ull;
typedef pair<ll, ll> l_l;
typedef pair<int, int> i_i;
#define rep(i, n) for (int i = 0; i < (int)(n); i++)
#define EPS (1e-7)
#define INF (1e9)
#define PI (acos(-1))

const ll mod = 1000000007;

int main() {
    ll a,r,n; cin >> a >> r >> n;
    ll k = 0;
    if(r == 1){
        cout << a << endl;
    } else {
        while(1){
            if(a > INF){
                cout << "large" << endl;
                return 0;
            }
            if(n - 1 == k){
                cout << a << endl;
                return 0;
            }
            a *= r;
            k++;
        }
    }
    return 0;
}