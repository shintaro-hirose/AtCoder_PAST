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
#define PI (acos(-1))

const ll mod = 1000000007;

int main() {
    int n,m,q; cin >> n >> m >> q;
    vector<int> solve_cnt(m,0);
    vector<vector<int>> solved_problem(n, vector<int>(0));
    rep(i,q){
        int x; cin >> x;
        if(x==1){
            int y; cin >> y;
            int res = 0;
            for(int sp: solved_problem.at(y-1)){
                res += n - solve_cnt.at(sp);
            }
            cout << res << endl;
        } else {
            int y,z; cin >> y >> z;
            solve_cnt.at(z-1)++;
            solved_problem.at(y-1).push_back(z-1);
        }
    }
    return 0;
}