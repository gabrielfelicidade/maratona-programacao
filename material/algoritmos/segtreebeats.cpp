#include <bits/stdc++.h>

using namespace std;

const int N = 112345;

int t[4*N], lzs[4*N], lzm[4*N];

int a[4*N], b[4*N];

void build(int i, int l, int r){
	if(l == r){
		a[i] = b[i] = l;
	}else{
		int m = (l+r)/2;
		build(2*i, l, m);
		build(2*i+1, m+1, r);
		a[i] = l;
		b[i] = r;
	}
}

void push(int i, int l, int r){
	if(lzs[i]){
		t[i] += lzs[i] * (r-l+1);
		if(l != r){
			lzs[2*i] += lzs[i];
			lzs[2*i+1] += lzs[i];
		}
		lzs[i] = 0;
	}
	if(lzm[i]){
		a[i] = b[i] = lzm[i];
		if(l != r){
			lzm[2*i] = lzm[i];
			lzm[2*i+1] = lzm[i];
		}
		lzm[i] = 0;
	}
}

int query(int i, int l, int r, int ql, int qr){
	if(ql <= l && r <= qr) return t[i];
	if(qr < l || r < ql) return 0;
	int m = (l+r)/2;
	return query(2*i, l, m, ql, qr) + query(2*i+1, m+1, r, ql, qr);
}

void update(int i, int l, int r, int ql, int qr, int x){
	push(i, l, r);
	if(qr < l || r < ql) return;
	if(ql <= l && r <= qr && a[i] == b[i]){
		lzs[i] += abs(x-a[i]);
		lzm[i] = x;
		push(i, l, r);
	}else{
		int m = (l+r)/2;
		update(2*i, l, m, ql, qr, x);
		update(2*i+1, m+1, r, ql, qr, x);
		t[i] = t[2*i] + t[2*i+1];
		a[i] = min(a[2*i], a[2*i+1]);
		b[i] = max(b[2*i], b[2*i+1]);
	}
}

int main(){
	return 0;
}
