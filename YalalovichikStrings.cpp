#include <bits/stdc++.h>
using namespace std;
typedef long long ll;

// Author - Kevin Mathew
// Birla Institute of Technology, Mesra

void te(){
	ll n;
	cin >> n;
	string s;
	cin >> s;
	n = s.size();

	char last = s[0];

	vector<pair<char, ll> > chars;
	map<ll, ll> mx;
	ll count = 1;

	for(ll i=1;i<n;i++){
		if(s[i] == last){
			count++;
		}
		else{
			chars.push_back(make_pair(last, count));
			mx[last - 'a'] = max(mx[last - 'a'], count);

			last = s[i];
			count = 1;
		}
	}

	chars.push_back(make_pair(last, count));
	mx[last - 'a'] = max(mx[last - 'a'], count);

	map<ll, map<ll, vector<pair<ll, ll> > > > pairs;

	ll tot = 0;

	for(ll i=0;i<26;i++){
		tot += mx[i];
	}

	for(ll i=0;i<chars.size()-1;i++){
		ll a = (ll) (chars[i].first - 'a');
		ll b = (ll) (chars[i+1].first - 'a');

		// cout << a << " " << b << "\n";
		pairs[a][b].push_back(make_pair(chars[i].second, chars[i+1].second));
	}

	for(ll i=0;i<26;i++)
		for(ll j=0;j<26;j++)
			if(pairs[i][j].size() != 0){
				// cout << i << " " << j << "-\n";
				sort(pairs[i][j].begin(), pairs[i][j].end());

				// if(pairs[i][j].size() == 1){
					tot += pairs[i][j][0].first * pairs[i][j][0].second;
				// }
				// else{
					for(ll k=0;k<pairs[i][j].size()-1;k++){
						if(pairs[i][j][k].first <= pairs[i][j][k+1].first && pairs[i][j][k].second <= pairs[i][j][k+1].second){
							tot -= pairs[i][j][k].first * pairs[i][j][k].second;
							tot += pairs[i][j][k+1].first * pairs[i][j][k+1].second;
							// cout << tot << "-\n";
						}
						else{
							// tot += pairs[i][j][k].first * pairs[i][j][k].second;
							// cout << tot << "--\n";
							tot += (pairs[i][j][k+1].first - pairs[i][j][k].first) * pairs[i][j][k+1].second;
							// cout << tot << "---\n";
						}
					}
				// }
			}

	cout << tot << "\n";
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