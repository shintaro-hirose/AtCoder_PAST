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
typedef vector<bool> vb;
typedef vector<vb> vvb;
#define rep(i, n) for (int i = 0; i < (int)(n); i++)
#define EPS (1e-7)
#define INF (1e9)
#define PI (acos(-1))
const ll mod = 1000000007;

int my_ctoi(char c){
    return c - '0';
}

int main() {
    int N, M, K; cin >> N >> M >> K;
    vs A(N);
    rep(i, N) cin >> A[i];

    int S = min(N, M);
    for(int si = S; si >= 1; si--){
        rep(nsi,N - si + 1){
            rep(msi, M - si + 1){
                int total = si*si;
                vi memo(10);
                int maxCnt = 0;
                for(int ni = nsi; ni < nsi + si; ni++){
                    for(int mi = msi; mi < msi + si; mi++){
                        memo[my_ctoi(A[ni][mi])]++;
                        maxCnt = max(maxCnt, memo[my_ctoi(A[ni][mi])]);
                    }
                }
                if(total - maxCnt <= K){
                    cout << si << endl;
                    return 0;
                }

            }
        }
    }
    return 0;
}