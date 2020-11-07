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
    int N, L, T1, T2, T3;
    cin >> N >> L;
    vector<int> Hs(L+1);
    rep(i, N) {
        int H;
        cin >> H;
        Hs[H] = 1;
    }
    cin >> T1 >> T2 >> T3;
    vector<int> dp(L+1, INF);
    dp[0] = 0;
    rep(i, L){

        dp[i + 1] = min(dp[i + 1], dp[i] + T1 + Hs[i + 1] * T3);
        if(i + 1 == L){
            dp[L] = min(dp[L], dp[i] + T1/2 + T2/2);
        }
        else if(i + 2 == L){
            dp[L] = min(dp[L], dp[i] + T1 + T2);
            dp[L] = min(dp[L], dp[i] + T1/2 + T2 + T2/2);
        }
        else if(i + 3 == L){
            dp[i + 2] = min(dp[i + 2], dp[i] + T1 + T2 + Hs[i + 2] * T3);
            dp[L] = min(dp[L], dp[i] + T1/2 + T2 * 2 + T2/2);
        } else {
            dp[i + 2] = min(dp[i + 2], dp[i] + T1 + T2 + Hs[i + 2] * T3);
            dp[i + 4] = min(dp[i + 4], dp[i] + T1 + 3 * T2 + Hs[i + 4] * T3);
        }
    }
    cout << dp[L] << endl;
    return 0;
}