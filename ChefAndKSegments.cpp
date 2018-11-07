#include <bits/stdc++.h>
using namespace std;
typedef long long ll;

// Author - Kevin Mathew
// Birla Institute of Technology, Mesra

void te(){
	ll n, k;
	cin >> n >> k;
	vector<ll> l, r;
	vector<ll> left, right;
	for(ll i=0;i<n;i++){
		ll a, b;
		cin >> a >> b;
		l.push_back(a);
		r.push_back(b);
		left.push_back(a);
		right.push_back(b);
	}

	if(k == 1){
		ll mx = LLONG_MIN;
		for(ll i=0;i<n;i++)
			mx = max(mx, r[i]-l[i]);

		cout << mx << "\n";
		return;
	}

	vector<pair<ll, ll> > pr;
	for(ll i=0;i<n;i++)
		pr.push_back(make_pair(r[i], l[i]));

	sort(left.begin(), left.end());
	sort(right.begin(), right.end());
	sort(pr.begin(), pr.end());

	ll point = n-1;
	map<ll, ll> sl;
	map<ll, pair<ll, vector<ll> > > gr;
	ll val = 0;

	for(ll i=0;i<n;i++){
		sl[left[i]]++;
		gr[l[i]].second.push_back(r[i]);
	}
	for(ll i=0;i<n;i++){
		gr[l[i]].first = gr[l[i]].second.size();
		sort(gr[l[i]].second.begin(), gr[l[i]].second.end());
	}
	
	ll sum = 0;
	ll x = 0;
	
	for(ll i=0;i<n;i++)
		cout << left[i] << "\t";
	cout << "\n";
	for(ll i=0;i<n;i++)
		cout << right[i] << "\t";
	cout << "\n";
	for(ll i=0;i<n;i++)
		cout << pr[i].second << "\t";
	cout << "\n";

	for(ll i=n-1;i>=0;i--){
		ll s = left[i];
		ll len = 0;
		if(i != n-1 && (l[i] != l[i+1])){
			vector<ll>::iterator lower = lower_bound(gr[l[i+1]].begin(), gr[l[i+1]].end(), r[point+1]);
			x -= max((ll)0, gr[l[i+1]].first - (ll)(lower - gr[l[i+1]].begin()));
		}

		cout << x << " ";
		cout << sum << "\n";
		while(right[point] >= s && point >= 0){
			if(x >= k){
				len = right[point--] - s;
				sum = max(sum, len);
				break;
			}
			if(pr[point].second <= s)
				x++;
			point--;
		}
	}

	cout << sum << "\n";
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
		te();

	return 0;
}