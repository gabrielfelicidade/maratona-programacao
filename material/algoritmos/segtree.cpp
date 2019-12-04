#include <bits/stdc++.h>

using namespace std;

const int N = 112345;

int t[4*N];

int a[N];

void build(int i, int l, int r){
	if(l == r){
		t[i] = a[l];
	}else{
		int m = (l+r)/2;
		build(2*i, l, m);
		build(2*i+1, m+1, r);
		t[i] = t[2*i] + t[2*i+1];
	}
}

/* Busca em intervalo e update em um elemento */

int query(int i, int l, int r, int ql, int qr){
	if(ql <= l && r <= qr) return t[i];
	if(qr < l || r < qr) return 0;
	int n = (l+r)/2;
	return query(2*i, l, m, ql, qr) + query(2*i+1, m+1, r, ql, qr);
}

void update(int i, int l, int r, int p, int x){
	if(l == r){
		t[i] = x;
	}else{
		int m = (l+r)/2;
		if(p <= m) update(2*i, l, m, p, x);
		else update(2*i+1, m+1, r, p, x);
		t[i] = t[2*i] + t[2*i+1];
	}
}

/* Busca de um elemento e update em um intervalo */

void update(int i, int l, int r, int ql, int qr, int x){
	if(ql <= l && r <= qr){
		t[i] += x;
		return;
	}
	if(qr < l || r < qr) return;
	int n = (l+r)/2;
	update(2*i, l, m, ql, qr, x);
	update(2*i+1, m+1, r, ql, qr, x);
}

int query(int i, int l, int r, int p){
	if(l == r) return t[i];
	int m = (l+r)/2;
	if(p <= m){
		return t[i] + query(2*i, l, m, p);
	}else{
		return t[i] + query(2*i+1, m+1, r, p);
	}
}

int main(){
	return 0;
}
