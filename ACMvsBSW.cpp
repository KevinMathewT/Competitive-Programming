#include <bits/stdc++.h>
using namespace std;
typedef long long ll;

// Author - Kevin Mathew
// Birla Institute of Technology, Mesra

string s;
vector<string> ans;

void te(){
	ans.clear();
	cin >> s;
	// cout << s << "-\n";
	ll point = s.size()-1;
	string last = "";
	string total = last;
	string curr = "";
	ll flag;

	// cout << last << " " << total << " " << curr << " " << point << "\n";

	while(point >= 0){
		cout << last << " " << total << " " << curr << " " << point << "\n";
		flag = 0;
		curr = s[point] + curr;
		cout << last << " " << total << " " << curr << " " << point << "\n";
		if(curr.size() > total.size()){
			total = curr + total;
			ans.push_back(curr);
			last = curr;
			curr = "";
			flag = 1;
		}
		if(curr.size() < total.size()){
			for(ll i=0;i<total.size()-curr.size();i++)
				curr = "0" + curr;
		}
		if(curr.size() == total.size()){
			for(ll i=0;i<curr.size();i++)
				if(curr[i] >= total[i]){
					total = curr + total;
					ans.push_back(curr);
					last = curr;
					curr = "";
					flag = 1;
					break;
				}
				else
					break;
		}

		// cout << flag << "-\n";

		if(point == 0 && flag == 0){
			ans[ans.size()-1] = curr + ans[ans.size()-1];
			break;
		}
		point--;
	}

	cout << ans.size() << "\n";
	for(ll i=ans.size()-1;i>=0;i--)
		cout << ans[i] << " ";
	cout << "\n";
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