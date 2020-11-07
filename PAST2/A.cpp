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

int stair(string s){
    int ret;
    if(s[0] == 'B'){
        ret = s[1] - '0';
        ret *= -1;
        ret++;
    } else {
        ret = s[0] - '0';
    }

    return ret;
}

int main() {
    string S, T;
    cin >> S >> T;
    cout << abs(stair(S) - stair(T)) << endl;
    return 0;
}