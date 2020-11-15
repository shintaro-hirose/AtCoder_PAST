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
    vs V(N);
    rep(i, N) cin >> V[i];
    int si=0, sj=0;
    vector<i_i> Walls(0);
    int notWallCnt = 0;
    rep(i, N)rep(j, M){
        if(V[i][j] == '.'){
            si = i;
            sj = j;
            notWallCnt++;
        } else {
            Walls.push_back(i_i(i, j));
        }
    }
    notWallCnt++;
    int imove[4] = {0,1,0,-1};
    int jmove[4] = {1,0,-1,0};
    int ans = 0;
    // bfs
    for(i_i p: Walls){
        int i_to_change = p.first;
        int j_to_change = p.second;
        int cnt = 1;

        queue<i_i> q;
        q.push(i_i(si,sj));

        vvb seen(N, vb(M, false));
        seen[si][sj] = true;
        while(!q.empty()){
            i_i cur_p = q.front();
            q.pop();
            int cur_i = cur_p.first;
            int cur_j = cur_p.second;

            rep(k, 4){
                int next_i = cur_i + imove[k];
                int next_j = cur_j + jmove[k];
                if(next_i>=0 && next_j>=0 && next_i<N && next_j<M && !seen[next_i][next_j]){
                    seen[next_i][next_j] = true;
                    if(V[next_i][next_j] == '.' || i_i(next_i, next_j) == i_i(i_to_change, j_to_change)){
                        q.push(i_i(next_i, next_j));
                        cnt++;
                    }
                }
            }
        }
        if(cnt == notWallCnt)ans++;
    }
    cout << ans << endl;
    return 0;
}