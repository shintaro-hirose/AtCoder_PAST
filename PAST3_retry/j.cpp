#include <bits/stdc++.h>
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
    int N, M; cin >> N >> M;
    vector<int> S(M);
    rep(i, M) {
        cin >> S[i];
        S[i] *= -1;
    }
    vector<int> C(N);
    // C[i] = i番目の子供が最後に食べた寿司の美味しさ

    rep(i, M){
        auto itr = lower_bound(C.begin(), C.end(), S[i] + 1);
        if(itr == C.end()){
            cout << -1 << endl;
            continue;
        }
        cout << itr - C.begin() + 1 << endl;
        C[itr - C.begin()] = S[i];
    }
    return 0;
}