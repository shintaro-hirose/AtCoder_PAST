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

int main() {
    int N, M; cin >> N >> M;
    vs A(N);
    rep(i, N) cin >> A[i];

    int hmove[8] = {0,-1,-1,-1,0,1,1,1};
    int wmove[8] = {1,1,0,-1,-1,-1,0,1};

    rep(i, N){
        rep(j, M){
            int cnt = 0;
            if(A[i][j] == '#')cnt++;
            rep(k, 8){
                int ni, nj;
                ni = i + hmove[k];
                nj = j + wmove[k];
                if(ni>=0 && nj>=0 && ni<N && nj<M && A[ni][nj] == '#')cnt++;
            }
            cout << cnt;
        }
        cout << endl;
    }
    return 0;
}