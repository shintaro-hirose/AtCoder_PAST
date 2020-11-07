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
    ll N;
    int Q;
    cin >> N >> Q;
    vector<vector<ll>> data(N, vector<ll>(N));

    rep(i, N){
        rep(j, N){
            data[i][j] = N * i + j;
        }
    }

    rep(i, Q){
        int order;
        cin >> order;
        if(order == 1){
            int a, b;
            cin >> a >> b;
            
        }
    }
    
    return 0;
}
