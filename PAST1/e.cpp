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
    int N, Q;
    cin >> N >> Q;
    vector<vector<int>> follow(N, vector<int>(N));
    vector<vector<int>> follower(N, vector<int>(N));
    rep(i, Q){
        int n1;
        int cnt;
        int cnt2;
        cin >> n1;
        if(n1 == 1){
            int n2, n3;
            cin >> n2 >> n3;
            follow[n2 - 1][n3 - 1] = 1;
            follower[n3 - 1][n2 - 1] = 1;
        } else if(n1 == 2){
            int n2;
            cin >> n2;
            cnt = 0;
            for(int x: follower[n2 - 1]){
                if(x == 1){
                    follow[n2 - 1][cnt] = 1;
                    follower[cnt][n2 - 1] = 1;
                }
                cnt++;
            }
        } else {
            int n2;
            vector<int> data;
            cin >> n2;
            cnt = 0;
            for(int x: follow[n2 - 1]){
                if(x == 1){
                    data.push_back(cnt);
                }
                cnt++;
            }
            for(int x: data){
                cnt2 = 0;
                for(int y: follow[x]){
                    if(y == 1 && cnt2 != n2 - 1){
                        follow[n2 - 1][cnt2] = 1;
                        follower[cnt2][n2 - 1] = 1;
                    }
                    cnt2++;
                }
            }
        }
    }
    rep(i, N){
        for(int x: follow[i]){
            if(x == 1){
                cout << "Y";
            } else {
                cout << "N";
            }
        }
        cout << endl;
    }

    return 0;
}
