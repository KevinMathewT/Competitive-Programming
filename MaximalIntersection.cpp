#include <bits/stdc++.h>
using namespace std;
typedef long long ll;

// Author - Kevin Mathew
// Birla Institute of Technology, Mesra

ll n;

ll max_element(ll *a){
	ll mx = a[0];
	for(ll i=1;i<n;i++)
		mx = max(mx, a[i]);

	return mx;
}

ll min_element(ll *a){
	ll mx = a[0];
	for(ll i=1;i<n;i++)
		mx = min(mx, a[i]);

	return mx;
}

void te(){
	cin >> n;

	ll l[n], r[n];

	for(ll i=0;i<n;i++)
		cin >> l[i] >> r[i];

	// for(ll i=0;i<n;i++)
	// 	cout << l[i] << " " << r[i] << "\n";

	ll max_l = (ll) max_element(l);
	ll min_r = (ll) min_element(r);

	// cout << max_l << " " << min_r << "\n";

	ll count_l = 0;
	for(ll i=0;i<n;i++)
		if(l[i] == max_l)
			count_l++;

	ll count_r = 0;
	for(ll i=0;i<n;i++)
		if(r[i] == min_r)
			count_r++;

	if(count_l > 1 && count_r > 1){
		cout << max((ll) 0, min_r - max_l);
		return;
	}

	if(count_l > 1){
		for(ll i=0;i<n;i++)
			if(r[i] == min_r)
				r[i] = LLONG_MAX;

		min_r = (ll) min_element(r);
		cout << max((ll) 0, min_r - max_l);
		return;		
	}

	if(count_r > 1){
		for(ll i=0;i<n;i++)
			if(l[i] == max_l)
				l[i] = LLONG_MIN;

		max_l = (ll) max_element(l);
		cout << max((ll) 0, min_r - max_l);
		return;		
	}

	ll temp_c;
	ll flag = 0;
	for(ll i=0;i<n;i++)
		if(l[i] == max_l){
			l[i] = LLONG_MIN;
			temp_c = i;
			if(r[i] == min_r){
				r[i] = LLONG_MAX;
				flag = 1;
			}
		}

	if(flag == 1){
		max_l = (ll) max_element(l);
		min_r = (ll) min_element(r);
		cout << max((ll)0, min_r - max_l) << "\n";
		return;
	}

	ll temp = max_l;
	max_l = (ll) max_element(l);
	min_r = (ll) min_element(r);
	ll ans1 = max((ll) 0, min_r - max_l);

	l[temp_c] = temp;

	for(ll i=0;i<n;i++)
		if(r[i] == min_r)
			r[i] = LLONG_MAX;

	max_l = (ll) max_element(l);
	min_r = (ll) min_element(r);
	ll ans2 = max((ll) 0, min_r - max_l);

	// for(ll i=0;i<n;i++)
	// 	cout << l[i] << "-" << r[i] << "\n";

	cout << max((ll)0, max(ans1, ans2));
}

int main()
{
	// freopen("input.txt", "r", stdin);		//Comment
	// freopen("output.txt", "w", stdout);		//this out.
	ios::sync_with_stdio(false);			//Not
	cin.tie(NULL);							//this.
	cout.tie(0);							//or this.

	te();

	return 0;
}