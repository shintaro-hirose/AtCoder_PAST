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
    ll A, R, N, cnt, ans;
    ll comp = 1000000000;
    bool islarge = false;
    cin >>A >> R >> N;
    
    cnt = 1;
    ans = A;
    while(1){
        if(ans > comp){
            islarge = true;
            break;
        }
        if(cnt == N){
            break;
        }
        ans *= R;
        cnt++;
    }
    if(islarge){
        cout << "large" << endl;
    } else {
        cout << ans << endl;
    }

    return 0;
}
