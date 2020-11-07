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

int myctoi(char c){
    int num;
    if(c == 'S') num = 0;
    else if(c == 'G') num = 10;
    else num = c - '0';
    return num;
}

int main() {
    int N, M;
    cin >> N >> M;
    vs Field(N);
    rep(i, N) cin >> Field[i];

    vvi Numbering(N, vi(M));
    rep(i, N) rep(j, M) Numbering[i][j] = (i * M) + j;
    vector<vector<i_i>> adj(N*M, vector<i_i>(0));

    int si=0, sj=0, gi=0, gj=0;
    rep(i, N)rep(j, M){
        if(Field[i][j] == 'S'){
            si = i;
            sj = j;
        } else if(Field[i][j] == 'G'){
            gi = i;
            gj = j;
        }
    }
    // bfs
    int di[4] = {0,1,0,-1};
    int dj[4] = {1,0,-1,0};
    rep(i, N) rep(j, M){
        vvl dist(N, vl(M, -1));
        dist[i][j] = 0;
        queue<i_i> q;
        q.push(make_pair(i,j));
        char c = Field[i][j];
        if(c == 'G') continue;
        int num = myctoi(c);
        while(!q.empty()){
            i_i p = q.front();
            q.pop();
            int pi = p.first;
            int pj = p.second;
            rep(k, 4){
                int ni, nj;
                ni = pi + di[k];
                nj = pj + dj[k];
                if(ni>=0 && nj>=0 && ni<N && nj<M && dist[ni][nj]==-1){
                    int nextnum = myctoi(Field[ni][nj]);
                    dist[ni][nj] = dist[pi][pj] + 1;
                    if(nextnum == num + 1) {
                        adj[Numbering[i][j]].push_back(make_pair(Numbering[ni][nj], dist[ni][nj]));
                        continue;
                    }
                    q.push(make_pair(ni,nj));
                }
            }
        }
    }
    
    vl ans(N*M, INF);
    ans[Numbering[si][sj]] = 0;
    // vector<bool> seen(N*M, false);
    queue<int> q;
    q.push(Numbering[si][sj]);
    while(!q.empty()){
        int curLab = q.front();
        q.pop();
        for(i_i np: adj[curLab]){
            int nextLab = np.first;
            int cost = np.second;
            if(ans[nextLab] > ans[curLab]+cost){
                ans[nextLab] = min(ans[nextLab], ans[curLab]+cost);
                q.push(nextLab);
            }
        }
    }
    if(ans[Numbering[gi][gj]] == INF) cout << -1 << endl;
    else cout << ans[Numbering[gi][gj]] << endl;

    // rep(i, N*M){
    //     for(i_i p: adj[i]){
    //         cout << "num, cost: " << p.first << ", " << p.second << endl;
    //     }
    //     cout << endl;
    // }
    // rep(i, N*M){
    //     cout << "ans " << i << ": " << ans[i] << endl;
    // }
    return 0;
}