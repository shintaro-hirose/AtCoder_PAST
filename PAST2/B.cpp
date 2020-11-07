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
    string S;
    cin >> S;
    int acnt, bcnt, ccnt;
    acnt = 0; bcnt = 0; ccnt = 0;
    rep(i, (int)S.size()){
        if(S[i] == 'a') acnt++;
        else if(S[i] == 'b') bcnt++;
        else ccnt++;
    }
    char ans;
    if(acnt > max(bcnt, ccnt)) ans = 'a';
    else if(bcnt > max(acnt, ccnt)) ans = 'b';
    else ans = 'c';
    cout << ans << endl;
    return 0;
}