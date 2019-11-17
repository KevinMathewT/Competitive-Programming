#include <bits/stdc++.h>
using namespace std;
typedef long long ll;

// Author - Kevin Mathew
// Birla Institute of Technology, Mesra

ll n, sx, sy, x[100], y[100];
vector<pair<ll, ll>> q1, q2, q3, q4, final;

void te(){
	cin >> n;
	for(ll i=0;i<n+1;i++)
		cin >> x[i] >> y[i];

	sx = x[0];
	sy = y[0];	

	for(ll i=0;i<n+1;i++){
		if(x[i] >= 0 && y[i] > 0)
			q1.push_back(make_pair(x[i], -y[i]));
		if(x[i] > 0 && y[i] <= 0)
			q2.push_back(make_pair(-x[i], -y[i]));
		if(x[i] <= 0 && y[i] < 0)
			q3.push_back(make_pair(-x[i], y[i]));
		if(x[i] < 0 && y[i] >= 0)
			q4.push_back(make_pair(x[i], y[i]));
	}

	sort(q1.begin(), q1.end());
	sort(q2.begin(), q2.end());
	sort(q3.begin(), q3.end());
	sort(q4.begin(), q4.end());

	for(ll i=0;i<q1.size();i++)
		final.push_back(make_pair(q1[i].first, -q1[i].second));
	for(ll i=0;i<q2.size();i++)
		final.push_back(make_pair(-q2[i].first, -q2[i].second));
	for(ll i=0;i<q3.size();i++)
		final.push_back(make_pair(-q3[i].first, q3[i].second));
	for(ll i=0;i<q4.size();i++)
		final.push_back(make_pair(q4[i].first, q4[i].second));

	for(ll i=0;i<final.size();i++)
		if(final[i].first == sx && final[i].second == sy){
			ll j = (i + 1) % final.size();
			while(true){
				if(j == i)
					break;
				cout << final[j].first << " " << final[j].second << "\n";
				j = (j + 1) % final.size();
			}
			break;
		}


	// for(ll i=0;i<final.size();i++)
	// 	cout << final[i].first << " " << final[i].second << "\n";
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