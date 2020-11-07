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
    int N, X, Y;
    cin >> N >> X >> Y;
    vector<vector<int>> obs(402, vector<int>(402));
    vector<vector<int>> dist(402, vector<int>(402));

    rep(i, N){
        int xin, yin;
        cin >> xin >> yin;
        obs[201 + xin][201 + yin] = 1;
    }
    

    int x_move[6] = {1,0,-1,1,-1,0};
    int y_move[6] = {1,1,1,0,0,-1};
    int sx = 0, sy = 0;

    queue<i_i> q;
    q.push(make_pair(0, 0));

    while(!q.empty()){
        int fx, fy;
        fx = q.front().first;
        fy = q.front().second;
        if(fx == X && fy == Y){
            cout << dist[fx+201][fy+201] << endl;
            return 0;
        }
        q.pop();
        rep(i, 6){
            int nx, ny;
            nx = fx + x_move[i];
            ny = fy + y_move[i];
            if(nx >= -201 && ny >= -201 && nx <= 201 && ny <= 201 && obs[nx+201][ny+201] == 0){
                q.push(make_pair(nx,ny));
                obs[nx+201][ny+201] = 1;
                dist[nx+201][ny+201] = dist[fx+201][fy+201] + 1;
                
            }
        }
    }
    cout << -1 << endl;
    return 0;
}
