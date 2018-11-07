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

	ll dot_pair = 0, hash_pair = 0;
	ll nodot = 0, nohash = 0;

	for(ll i=0;i<n;i++)
		if(s[i] == '.')
			nodot++;
		else
			nohash++;

	if(nodot == n){
		cout << 0 << "\n";
		return;
	}

	if(nohash == n){
		cout << 0 << "\n";
		return;
	}

	for(ll i=0;i<n;i++){
		if(s[i] == '.'){
			s = s.substr(i, n-i);
			break;
		}
	}

	n = s.length();
	// cout << s << " " << n << "\n";

	ll start = -1;
	for(ll i=0;i<n;i++){
		if(s[i] == '#'){
			start = i;
			break;
		}
	}

	// cout << start << "-\n";

	if(start == -1){
		cout << 0 << "\n";
		return;
	}
	if(start >= n-1){
		cout << -1 << "\n";
		return;
	}

	// cout << start << "-\n";

	ll tot = start;
	ll count = 1;
	for(ll i=start+1;i<n;i++){
		if(s[i] == '#'){
			if(i == n-1){
				cout << -1 << "\n";
				return;
			}
			start += 2;
			if(start >= n-1){
				cout << -1 << "\n";
				return;
			}
			// cout << start << " " << i << " " << count << " ";
			if(i >= start){
				tot += i-count;
				start = i;
			}
			else
				tot += ((start - i) + (start - count));

			// cout << tot << "--\n";
			count++;
		}
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