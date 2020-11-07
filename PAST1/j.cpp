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

int H, W;
vvi As, dist;

int dx[4] = {0, 0, 1, -1};
int dy[4] = {1, -1, 0, 0};

void dijkstra(int sx, int sy){
    dist = vvi(H, vi(W, INF));
    dist[sx][sy] = 0;
    priority_queue<pair<int, i_i>, vector<pair<int, i_i>>, greater<pair<int, i_i>> > pq;
    pq.push(pair<int, i_i>(dist[sx][sy], i_i(sx, sy)));
    while (!pq.empty()) {
        pair<int, i_i> p = pq.top();
        pq.pop();
        int c = p.first;
        int vx = p.second.first, vy = p.second.second;

        rep (i, 4) {
            int nx, ny;
            nx = vx + dx[i], ny = vy + dy[i];
            if (nx < 0 || ny < 0 || nx >= H || ny >= W) continue;
            if (dist[nx][ny] <= As[nx][ny] + c) continue;
            dist[nx][ny] = As[nx][ny] + c;
            pq.push(pair<int, i_i>(dist[nx][ny], i_i(nx, ny)));
        } 
    }
}

int main() {
    cin >> H >> W;
    As = vvi(H, vi(W));
    rep(hi, H) rep(wi, W) cin >> As[hi][wi];
    int ans = INF;
    rep(hi, H) rep(wi, W){
        int sum = 0;
        dijkstra(hi, wi);
        sum += As[hi][wi];
        sum += dist[H - 1][0];
        sum += dist[H - 1][W - 1];
        sum += dist[0][W - 1];
        ans = min(ans, sum);
    }
    cout << ans << endl;

    return 0;
}