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

vector<bool> seen;
vi first_order, last_order;

void dfs(const vvi &G, int v, int& cnt) {
    // 行きがけ順をインクリメントしながらメモ
    first_order[v] = cnt++;

    seen[v] = true; 
    for (auto next_v : G[v]) { 
        if (seen[next_v]) continue;
        dfs(G, next_v, cnt);
    }

    // 帰りがけ順をインクリメントしながらメモ
    last_order[v] = cnt++;
}

int main() {
    int N, Q;
    cin >> N;
    vi Ps(N);
    vvi Buka(N, vi(0));
    int shacho;
    rep(i, N) {
        cin >> Ps[i];
        if(Ps[i] == -1) {
            shacho = i;
            continue;
        }
        Buka[Ps[i] - 1].push_back(i);
    }

    cin >> Q;

    seen = vector<bool>(N, false);
    first_order = vi(N);
    last_order = vi(N);

    int cnt = 0;
    dfs(Buka, shacho, cnt);

    rep(i, Q){
        int a, b;
        cin >> a >> b;
        a--;
        b--;
        if(first_order[b] < first_order[a] && first_order[a] < last_order[b]){
            cout << "Yes" << endl;
        } else {
            cout << "No" << endl;
        }
    }

    // rep(i, first_order.size()){
    //     cout << "first: " << first_order[i] << endl;
    // }
    // rep(i, last_order.size()){
    //     cout << "second: " << last_order[i] << endl;
    // }
    return 0;
}