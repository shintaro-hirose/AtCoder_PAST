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
typedef vector<bool> vb;
typedef vector<vb> vvb;
#define rep(i, n) for (int i = 0; i < (int)(n); i++)
#define EPS (1e-7)
#define INF (1e9)
#define PI (acos(-1))
const ll mod = 1000000007;

int main() {
    int N;
    string S;
    cin >> N >> S;
    int left = 0;
    int right = 0;
    N = S.size();
    rep(i, N){
        if(S[i] == '.')left++;
        else break;
    }
    rep(i, N){
        if(S[N - 1 - i] == '.')right++;
        else break;
    }
    int maxRow = 0;
    int cnt = 0;
    rep(i,N){
        if(S[i] == '.')cnt++;
        else {
            maxRow = max(maxRow, cnt);
            cnt = 0;
        }
    }
    right += max(0, maxRow - (right+left));
    cout << left << " " << right << endl;
    return 0;
}