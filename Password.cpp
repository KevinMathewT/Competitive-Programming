#include <bits/stdc++.h>
using namespace std;
typedef long long ll;

// Author - Kevin Mathew
// Birla Institute of Technology, Mesra

string s;
const ll p = 31, m = 1e9 + 9;
vector<ll> sizes;
vector<ll> hashes;

long long compute_hash(string const& s) {
    const int p = 31;
    const int m = 1e9 + 9;
    long long hash_value = 0;
    long long p_pow = 1;
    for (char c : s) {
        hash_value = (hash_value + (c - 'a' + 1) * p_pow) % m;
        p_pow = (p_pow * p) % m;
    }
    return hash_value;
}

ll findHash(ll size, ll h){
	ll hash = 0;
	ll p_pow = 1;

	for(ll i=s.size()-1;i>s.size()-size-1;i--){
		hash =  (((hash * p) % m) + (s[i] - 'a' + 1)) % m;
		if(i != s.size()-size)
			p_pow = (p_pow * p) % m;
		// cout << p_pow << "\n";
	}

	ll end = s.size()-1;
	for(ll i=s.size()-size-1;i>=1;i--){
		// cout << hash << "-\n";
		// cout << s[i] << " " << s[end] << "--\n";
		// cout << p_pow << "---\n";
		hash = (hash - ((s[end] - 'a' + 1) * p_pow) + m) % m;
		hash = (hash * p) % m;
		hash = (((hash + (s[i] - 'a' + 1)) % m) + m) % m;
		// cout << hash << "----\n";
		end--;

		if(hash == h)
			return 1;
	}

	return 0;
}

void te(){
	// cout << compute_hash("ffi") << "\n";
	cin >> s;

	ll pre = 0, suff = 0, p_pow = 1;
	for(ll i=0;i<s.size()-1;i++){
		pre = (pre + ((s[i] - 'a' + 1) * p_pow) % m) % m;
		p_pow = (p_pow * p) % m;
		suff =  (((suff * p) % m) + (s[s.size()-1-i] - 'a' + 1)) % m;

		// cout << i << " " << pre << " " << suff << "\n";

		if(pre == suff){
			// cout << i << "\n";
			sizes.push_back(i + 1);
			hashes.push_back(pre);
		}
	}

	// for(ll i=0;i<sizes.size();i++){
	// 	cout << sizes[i] << " " << hashes[i] << "\n";
	// }

	if(sizes.size() == 0){
		cout << "Just a legend\n";
		return;
	}

	ll l = 0, r = sizes.size()-1;

	ll mid, flag = 0, end_flag = 0, ans = -1;

	// cout << findHash(3, 23349) << "\n";

	while(l <= r){
		mid = (l + r) / 2;
		// cout << mid << "-\n";

		// cout << sizes[mid] << " " << hashes[mid] << "\n";

		ll found = findHash(sizes[mid], hashes[mid]);
		// cout << found << "--\n";
		if(found == 1 && sizes[mid] > ans){
			ans = sizes[mid];
			flag = 1;
		}

		if(found == 1)
			l = mid + 1;
		else
			r = mid - 1;

		// break;
	}

	// cout << ans << "\n";

	if(ans == -1){
		cout << "Just a legend\n";
		return;
	}
	string z = (s.substr(0, ans));

	cout << z << "\n";
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