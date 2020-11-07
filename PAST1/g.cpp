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
#define PI 3.141592653589

const ll mod = 1000000007;

int main() {
    int N;
    cin >> N;
    vector<vector<int>> As(N, vector<int>(N));
    rep(i, N - 1) for(int j = i + 1; j < N; j++){
        int a; cin >> a;
        As[i][j] = a;
        As[j][i] = a;
    }
    // 組み分け i桁目のmod3をi番目が入る組とする
    ll ans = -1e11;
    rep(i, pow(3, N)){
        int k = i;
        vector<vector<int>> G(3, vector<int>(0));
        rep(j, N){
            G[k%3].push_back(j);
            k /= 3; 
        }
        ll Acnt = 0LL;
        for(vector<int> gr: G){
            int grsize = gr.size();
            rep(gri, grsize - 1)for(int grj = gri + 1; grj < grsize; grj++){
                Acnt += (ll)As[gr[gri]][gr[grj]];
            }
        }
        // cout << "Acnt, i: " << Acnt << ", " << i << endl;
        if(ans < Acnt) ans = Acnt;
    }
    cout << ans << endl;
    return 0;
}
