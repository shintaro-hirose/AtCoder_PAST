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
    int N;
    cin >> N;
    vi A(N);
    vi B(N);
    vvi C(N, vi(0));
    rep(i, N){
        cin >> A[i] >> B[i];
        C[A[i]-1].push_back(i);
    }
    int ans = 0;
    priority_queue<int> pq;
    rep(i, N){
        for(int x: C[i]){
            pq.push(B[x]);
        }
        int top = pq.top();
        pq.pop();
        ans += top;
        cout << ans << endl;
    }
    
    return 0;
}