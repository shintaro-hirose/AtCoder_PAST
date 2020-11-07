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
    int N, M, Q;
    cin >> N >> M >> Q;
    vector<vector<int>> data(N, vector<int>(0));
    vector<int> colors(N);
    
    rep(i, M){
        int u, v;
        cin >> u >> v;
        data[u - 1].push_back(v - 1);
        data[v - 1].push_back(u - 1);
    }
    rep(i, N){
        int c;
        cin >> c;
        colors[i] = c;
    }
    rep(i, Q){
        int order;
        cin >> order;
        if(order == 1){
            int ob;
            cin >> ob;
            cout << colors[ob - 1] << endl;
            for(int x: data[ob - 1]){
                colors[x] = colors[ob - 1];
            }
        } else {
            int ob, color;
            cin >> ob >> color;
            cout << colors[ob - 1] << endl;
            colors[ob - 1] = color;
        }
    }

    return 0;
}
