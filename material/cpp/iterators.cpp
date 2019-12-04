#include <bits/stdc++.h>

using namespace std;

int main(){
	
	set<int> s;
	s.insert(1);
	s.insert(2);
	
	auto it = s.begin();
	
	while(it != s.end()){
		cout << *it << endl;
		it++;
	}
	
	it = s.find(3);
	if(it == s.end()){
		cout << "nao achou\n";
	}else{
		cout << "achou\n";
	}
	
	it = s.upper_bound(3);
	cout << *it << endl;
	
	return 0;
}
