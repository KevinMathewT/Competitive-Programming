#include <bits/stdc++.h>
#include <ext/pb_ds/assoc_container.hpp>
#include <ext/pb_ds/tree_policy.hpp>
#include <functional>
#include <iostream>
using namespace __gnu_pbds;
using namespace std;
typedef long long ll;

// Author - Kevin Mathew
// Birla Institute of Technology, Mesra

typedef tree<ll, null_type, less<ll>, rb_tree_tag, tree_order_statistics_node_update> pbds; 

void te(){
	pbds p;

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

	ll sum = 0;
	ll point = n-1;
	ll no;
	for(ll i=n-1;i>=0;i--){
		cout << left[i] << " " << right[point] << "\n";
		if(i != n-1 && left[i] == left[i+1])
			continue;
		while(point >= 0 && right[point] >= left[i]){
			p.insert(pr[point].second);
			no = p.order_of_key(left[i]);
			cout << "-" << no + 1 << "-\n";
			if(no >= k-1){
				sum = max(sum, right[point--]-left[i]);
				break;
			}
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