#include <bits/stdc++.h>

using namespace std;

const int N = 15;
	
vector<vector<int>> hash_table(N);

int hash_function(int n){
	return n % N;
}

void insert(int n){
	hash_table[hash_function(n)].push_back(n);
}

int query(int n){
	int index = hash_function(n);
	for(int i = 0; i < hash_table[index].size(); i++) if(hash_table[index][i] == n) return n;
	return -1;
}

void del(int n){
	int index = hash_function(n);
	for(int i = 0; i < hash_table[index].size(); i++) if(hash_table[index][i] == n) hash_table[index].erase(hash_table[index].begin()+i);
}

int main(){
	
	insert(10);
	insert(12);
	insert(5);
	insert(16);
	insert(7);
	insert(2);
	insert(1);
	insert(19);
	insert(22);
	insert(125);
	
	cout << (query(5) == -1 ? "N 5" : "S 5") << endl;
	cout << (query(99) == -1 ? "N 99" : "S 99") << endl;
	cout << (query(1) == -1 ? "N 1" : "S 1") << endl;
	cout << (query(12) == -1 ? "N 12" : "S 12") << endl;
	
	del(5);
	
	cout << (query(5) == -1 ? "N 5" : "S 5") << endl;
	
	return 0;
}
