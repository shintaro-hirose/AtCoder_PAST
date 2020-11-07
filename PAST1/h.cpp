#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
typedef unsigned long long ull;
typedef pair<ll, ll> l_l;
typedef pair<int, int> i_i;
typedef vector<int> vi;
typedef vector<vi> vii;
#define rep(i, n) for (int i = 0; i < (int)(n); i++)
#define EPS (1e-7)
#define INF (1e9)
#define PI (acos(-1))
const ll mod = 1000000007;

int main() {
    int N, Q, oddN;
    ll oddMin, allMin, ans, oddRed, allRed;
    cin >> N;
    oddN = (N + 1) / 2;
    vector<ll> C(N);
    oddMin = INF;
    allMin = INF;
    rep(i, N) {
        cin >> C[i];
        if(i % 2 == 0) oddMin = min(oddMin, C[i]);
        allMin = min(allMin, C[i]);
    }
    cin >> Q;

    oddRed = 0;
    allRed = 0;
    ans = 0;

    rep(i, Q){
        int op; cin >> op;
        if(op == 1){
            int x, a; cin >> x >> a;
            x--;
            int cx = C[x] - allRed;
            if(x % 2 == 0) cx -= oddRed;
            if(cx < a) continue;
            C[x] -= a;
            ans += a;
            if(x % 2 == 0) oddMin = min(oddMin, C[x]- oddRed - allRed);
            allMin = min(allMin, C[x]- oddRed - allRed);
        }
        if(op == 2){
            int a; cin >> a;
            if(oddMin < a) continue;
            ans += a * oddN;
            oddRed += a;
            oddMin -= a;
            allMin = min(oddMin, allMin);
        }
        if(op == 3){
            int a; cin >> a;
            if(allMin < a) continue;
            ans += a * N;
            allRed += a;
            allMin -= a;
            oddMin -= a;
        }
    }
    cout << ans << endl;
    return 0;
}