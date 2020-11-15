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

int main(){
    int N;
    string S;
    cin >> N >> S;
    string R = S;
    reverse(R.begin(), R.end());

    string cur = S;
    sort(cur.begin(), cur.end());
    do{
        if(cur != S && cur != R) {
            cout << cur << endl;
            return 0;
        }
    }while(next_permutation(cur.begin(), cur.end()));

    cout << "None" << endl;
    return 0;
}