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

int main() {
    int N; cin >> N;
    vi A(N+1);
    rep(i, N) cin >> A[i+1];
    rep(i, N){
        int ni = i + 1;
        int curx = ni;
        int ans = 0;
        while(1){
            ans++;
            curx = A[curx];
            if(curx == ni) {
                cout << ans << " ";
                break;
            }
        }
    }
    cout << endl;
    return 0;
}