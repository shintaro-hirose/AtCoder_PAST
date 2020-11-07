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

ll mymult(ll a){
    return a*a;
}

int main() {
    int Q; cin >> Q;

    vl S(0);
    vl mS(0);
    char prevChar = '.';
    ll prevCnt = 0;
    ll sum = 0;
    ll delSum = 0;
    ll li = 0;
    rep(i, Q){
        ll a; cin >> a;
        if(a == 1){
            char b;
            ll c;
            cin >> b >> c;
            sum += c;
            ll msSize = mS.size();
            if(b != prevChar){
                S.push_back(sum);
                ll prevmS = (msSize < 1 ? 0 : mS[msSize - 1]);
                mS.push_back(prevmS + mymult((ll)c));
                prevCnt = c;
            } else {
                if(msSize >= 2){
                    mS[msSize - 1] = mS[msSize - 2] + mymult(prevCnt + c);
                } else {
                    mS[msSize - 1] = mymult(prevCnt + c);
                }
                S[(ll)S.size() - 1] += c;
                prevCnt += c;
            }
            prevChar = b;
        } else {
            ll d;
            cin >> d;
            if(S.size()==0){
                cout << 0 << endl;
            }
            else {
                ll ans;
                auto itr = lower_bound(S.begin(), S.end(), d+delSum);
                if(itr != S.end()){
                    ll ri = itr - S.begin();
                    if(li < ri){
                        ans = mS[ri-1] - mS[li] + mymult(S[li] - delSum) +mymult(d+delSum - S[ri-1]);
                    } else {
                        ans = mymult(d);
                    }
                    delSum += d;
                    li = ri;
                } else {
                    ll lasti = mS.size() - 1;
                    if(li == lasti) ans = mymult(sum - delSum);
                    else ans = mS[lasti] - mS[li] + mymult(S[li] - delSum);
                    delSum = sum;
                    li = lasti;
                    prevChar = '.';
                }
                cout << ans << endl;
            }
        }
        // cout << i << " prevChar: " << prevChar << endl;
        // cout << i << " prevCnt: " << prevCnt << endl;
        // cout << i << " sum: " << sum << endl;
        // cout << i << " delSum: " << delSum << endl;
        // cout << i << " li: " << li << endl;
        // cout << i << " Ssize: " << S.size() << endl;
        // cout << i << " mSsize: " << mS.size() << endl;
        
    }
    return 0;
}