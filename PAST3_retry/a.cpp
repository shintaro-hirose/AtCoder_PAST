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
    string s,t,sl,tl; cin >> s >> t;
    sl=s; tl=t;
    transform(sl.begin(), sl.end(), sl.begin(), ::tolower);
    transform(tl.begin(), tl.end(), tl.begin(), ::tolower);

    string ans;
    if(s == t){
        ans = "same";
    } else if(sl == tl){
        ans = "case-insensitive";
    } else {
        ans = "different";
    }
    cout << ans << endl;
    return 0;
}