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
    int N, K; cin >> N >> K;
    unordered_map<string, int> ump;
    vi cnt(0);
    rep(i, N){
        string s;
        cin >> s;
        ump[s]++;
    }
    for(auto itr = ump.begin(); itr != ump.end(); itr++){
        cnt.push_back((*itr).second);
    }
    sort(cnt.begin(), cnt.end(), greater<int>());
    K--;
    int target = cnt[K];
    if((K - 1 >=0 && cnt[K - 1] == target) || (K + 1 < (int)cnt.size() && cnt[K + 1] == target)){
        cout << "AMBIGUOUS" << endl;
        return 0;
    }
    for(auto itr = ump.begin(); itr != ump.end(); itr++){
        if((*itr).second == target){
            cout << (*itr).first << endl;
            break;
        }
    }
    return 0;
}