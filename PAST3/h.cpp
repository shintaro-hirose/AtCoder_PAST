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
    int N, L;
    cin >> N >> L;
    vector<int> hurdle(L);
    rep(i, N){
        int num;
        cin >> num;
        hurdle[num] = 1;

    }
    int t1, t2, t3;
    cin >> t1 >> t2 >> t3;
    
    return 0;
}
