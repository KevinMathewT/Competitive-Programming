#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
typedef double ld;

// Kevin Mathew T
// Birla Institute of Technology, Mesra
// GitHub - https://github.com/KevinMathewT
// CodeForces - https://codeforces.com/profile/KevinMathew
// CodeChef - https://www.codechef.com/users/KevinMathew
// HackerRank - https://www.hackerrank.com/KevinMathew?

ll n, d, a[200010], pos[200010], vis[200010];
vector<vector<ll> > v;

pair<vector<ll>, ll> count_inversions(const vector<ll> &v){
    if (v.size() == 1) return make_pair(vector<ll>(v.begin(), v.end()), 0);
    ll mid = (v.size()) / 2;
    vector<ll> l_half(v.begin(), v.begin() + mid);
    vector<ll> r_half(v.begin() + mid, v.end());
    auto l_ans = count_inversions(l_half);
    auto r_ans = count_inversions(r_half);
    vector<ll> mem(v.size(), 0);
    ll i{0};
    ll j{0};
    ll inv{0};
    for (ll k = 0; k < mem.size(); ++k){
        if (i < l_ans.first.size() && j < r_ans.first.size()){
            if (l_ans.first.at(i) <= r_ans.first.at(j)){
                mem.at(k) = l_ans.first.at(i);
                ++i;
            }
            else{
                mem.at(k) = r_ans.first.at(j);
                ++j;
                inv = inv + l_ans.first.size() - i;
            }
        } 
        else if (i < l_ans.first.size()){
            mem.at(k) = l_ans.first.at(i);
            ++i;
        } 
        else if (j < r_ans.first.size()){
            mem.at(k) = r_ans.first.at(j);
            ++j;
        }
    }
    
    return make_pair(mem, inv + l_ans.second + r_ans.second);
}

ll getCycleLen(vector<ll>& b){
	return count_inversions(b).second;
}

void solve(){
	v.clear();
	cin >> n >> d;
	for(ll i=0;i<n;i++)
		cin >> a[i];

	for(ll i=0;i<n+1;i++)
		pos[i] = vis[i] = 0;

	for(ll i=0;i<n;i++){
		if(abs(a[i] - (i + 1)) % d != 0){
			cout << -1 << "\n";
			return;
		}
	}

	for(ll i=0;i<d;i++)
		v.push_back(vector<ll>(0));

	for(ll i=0;i<n;i++){
		v[a[i] % d].push_back(a[i]);
	}

	ll out = 0;
	for(ll i=0;i<v.size();i++){
		out += getCycleLen(v[i]);
		// cout << out << "---\n";
	}

	cout << out << "\n";
}

int main()
{
	freopen("input.txt", "r", stdin);		//Comment
	freopen("output.txt", "w", stdout);		//this out.
	ios::sync_with_stdio(false);			//Not
	cin.tie(NULL);							//this.
	cout.tie(0);							//or this.

	ll T;
	cin >> T;
	while(T--)
		solve();

	return 0;
}