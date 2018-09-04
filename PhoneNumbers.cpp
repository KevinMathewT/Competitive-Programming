#include <bits/stdc++.h>
#include <iostream>
#include <vector>
#include <set>
#include <string>
#include <utility>
typedef long long ll;
typedef long double ld;
typedef std::vector<ll> vl;
typedef std::vector<vl> vvl;
void read(ll &x){
	scanf("%lld",&x);
}
void read(ll &x,ll &y){
	scanf("%lld%lld",&x,&y);
}
void read(ll &x,ll &y,ll &z){
	scanf("%lld%lld%lld",&x,&y,&z);
}
void read(ll &x,ll &y,ll &z,ll &w){
	scanf("%lld%lld%lld%lld",&x,&y,&z,&w);
}
clock_t t_start,t_end;
void start_clock(){
	t_start = clock();
}
void end_clock(){
	t_end = clock();
	ld timeis = t_end - t_start;
    printf("\n\nTime taken : %f s", ((float)timeis)/CLOCKS_PER_SEC);
}

using namespace std;

bool endsWith(std::string str, std::string suffix)
{
  if (str.length() < suffix.length())
    return false;

  return str.substr(str.length() - suffix.length()) == suffix;
}

int main(){
	freopen("input.txt", "r", stdin);
	freopen("output.txt", "w", stdout);
	start_clock();

	ll s;
	read(s);


	std::map<string, set<string> > map;
	while(s--){
		char ch;
		cin >> ch;
		string st;
		ll n;
		cin >> st >> n;
		while(n--){
			string num;
			cin >> num;
			map[st].insert(num);
		}
	}

	for (std::map<string, set<string> >::iterator it=map.begin(); it!=map.end(); ++it){
    	std::set<string>::iterator it1;
    	std::set<string>::iterator it2;
  		for (it1 = (it->second).begin(); it1 != (it->second).end(); ++it1)
		{
			it1--;
    		for (it2 = ++it1; it2 != (it->second).end(); ++it2)
			{
    			if(endsWith(*it1, *it2)){
    				it2++;
    				const string z = *it2;
    				it->second.erase(z);
    				continue;
    				it2--;
    			}
    			if(endsWith(*it2, *it1)){
    				const string z = *it1;
    				it1++;
    				it->second.erase(z);
    				continue;
    				it1--;
    			}
			}
		}
	}

	printf("%d\n", map.size());
	for (std::map<string, set<string> >::iterator it=map.begin(); it!=map.end(); ++it){
    	cout << (it->first) << " ";
    	printf("%d ", (it->second).size());
    	std::set<string>::iterator its;
  		for (its = (it->second).begin(); its != (it->second).end(); ++its)
		{
    		cout << *its << " ";
		}
		printf("\n");
	}

	end_clock();
	return 0;
}