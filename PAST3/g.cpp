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
    X += 201;
    Y += 201;
    vector<vector<int>> field(403, vector<int>(403));
    vector<vector<int>> d(403, vector<int>(403, -1));
    

    rep(i, N){
        int x, y;
        cin >> x >> y;
        field[y + 201][x + 201] = 1;
    }
    int sx, sy;
    sx = 201;
    sy = 201;

    queue<i_i> q;
    int x,y,nx,ny;
    bool hasAns = false;

    q.push(make_pair(sy, sx));
    vector<int> dx = {1,0,-1,0,1,-1};
    vector<int> dy = {0,-1,0,1,1,1};
    d[sy][sx] = 0;

    while(!q.empty()){
        y = q.front().first;
        x = q.front().second;
        q.pop();
        if(x == X && y == Y){
            hasAns = true;
            break;
        }
        else{
            for(int i=0; i<6; i++){
                
                nx = x + dx[i];
                ny = y + dy[i];
                
                if(nx>=0 && ny>=0 && nx<=402 && ny<=402 && field[ny][nx] == 0 && d[ny][nx]==-1){
                    q.push(make_pair(ny,nx));
                    d[ny][nx] = d[y][x] + 1;
                }
            }
        }
    }
    if(hasAns){
        cout << d[Y][X] << endl;
    } else {
        cout << "-1" << endl;
    }

    

    return 0;
}
