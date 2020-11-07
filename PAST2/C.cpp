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
#define INF (1e9)
#define PI (acos(-1))
const ll mod = 1000000007;

int main() {
    int N;
    cin >> N;
    vs G(N);
    rep(i, N) cin >> G[i];
    for(int i = N-2; i >= 0; i--){
        for(int j = 1; j < 2 * N - 2; j++){
            char cur = G[i][j];
            if(cur != '#') continue;
            bool hadX = false;
            for(int k = -1; k <= 1; k++){
                if(G[i+1][j+k] == 'X') hadX = true;
            }
            if(hadX) G[i][j] = 'X';
        }
    }
    rep(i, N) cout << G[i] << endl;
    return 0;
}