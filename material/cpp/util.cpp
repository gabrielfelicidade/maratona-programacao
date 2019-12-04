#include <bits/stdc++.h>

using namespace std;

int main(){
	
	pair<int, string> p(1, "teste");
	cout << p.first << " " << p.second << endl;
	
	tuple<int, int, string, double> t(1, 2, "aaaa", 3.14);
	cout << get<2>(t) << endl;
	
	int a[] = {1, 5, 6, 7, 2};
	
	sort(a, a+5);
	
	vector<int> v = {1, 5, 6, 7, 2};
	
	next_permutation(v.begin(), v.end());
	
	while(next_permutation(v.begin(), v.end())){
		cout << "mudou" << endl;
	}
	
	sort(v.begin(), v.end());
	
	auto it = lower_bound(v.begin(), v.end(), 3);
	auto it2 = unique(v.begin(), v.end());
	v.erase(it2, v.end());
	
	sort(v.begin(), v.begin()+2);
	sort(v.rbegin(), v.rend());
	
	reverse(v.begin(), v.end());
	
	it = max_element(v.begin(), v.end());
	it = min_element(v.begin(), v.end());
	
	int cont = count(v.begin(), v.end(), 2);
	
	v.erase(v.begin() + 1, v.begin() + 3);
	
	return 0;
}
