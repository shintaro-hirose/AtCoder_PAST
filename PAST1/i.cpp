#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
typedef unsigned long long ull;
typedef pair<ll, ll> l_l;
typedef pair<int, int> i_i;
typedef vector<int> vi;
typedef vector<vi> vvi;
typedef vector<ll> vl;
typedef vector<vl> vvl;
typedef vector<string> vs;
typedef vector<vs> vvs;
#define rep(i, n) for (int i = 0; i < (int)(n); i++)
#define EPS (1e-7)
#define INF (1e15)
#define PI (acos(-1))
const ll mod = 1000000007;

int main() {
    int N, M;
    cin >> N >> M;
    vs S(M + 1);
    vi C(M + 1);
    vi Sbit(M + 1);
    rep(i, M) cin >> S[i + 1] >> C[i + 1];
    rep(i, M) {
        int sb = 0;
        rep(j, N){
            if(S[i + 1][j] == 'Y') sb += (1 << j);
        }
        Sbit[i + 1] = sb;
    }
    vvl dp(M + 1, vl(1 << N, INF));
    // dp[i][s]: i番目のセットまで見たとき、買えたものが集合sであるようなときのコストの最小値
    dp[0][0] = 0;
    rep(i, M){
        rep(j, 1 << N){
            int nsbit = Sbit[i + 1] | j;
            dp[i + 1][j] = min(dp[i + 1][j], dp[i][j]);
            dp[i + 1][nsbit] = min(dp[i + 1][nsbit], dp[i][j] + C[i + 1]);
        }
    }

    ll ans = dp[M][(1 << N) - 1];
    if(ans == INF) cout << "-1" << endl;
    else cout << ans << endl;

    return 0;
}