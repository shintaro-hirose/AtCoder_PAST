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
    vector<int> solve_cnt(M);
    vector<vector<int>> toita(N, vector<int>(0));


    rep(i, Q){
        int n;
        cin >> n;
        if(n == 1){
            int c1, point;
            cin >> c1;
            point = 0;
            for(int x: toita[c1 - 1]){
                point += N - solve_cnt[x];
            }
            cout << point << endl;

        } else {
            int c1, c2;
            cin >> c1 >> c2;
            solve_cnt[c2 - 1]++;
            toita[c1 - 1].push_back(c2 - 1);
        }
    }

    return 0;
}
