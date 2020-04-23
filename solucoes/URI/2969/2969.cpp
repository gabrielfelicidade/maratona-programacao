#include <bits/stdc++.h>

const int MAX = 440;
const int INF = 1e9;

using namespace std;

int temp[MAX], tempord[MAX], ma_max[MAX][MAX][MAX], n;

void floyd(){
	for(int k = 0; k < n; k++){
		for(int i = 0; i < n; i++){
			for(int j = 0; j < n; j++){
				ma_max[i][j][i+1] = ma_max[i][j][i];
				if(temp[k] >= tempord[k]){
					ma_max[i][j][i+1] = min(ma_max[i][j][i+1], ma_max[i][k][i] + ma_max[k][j][i]);
				}
			}
		}
	}
}

int main(){
	
	int r, q;
	
	cin >> n >> r;
	
	for(int i = 0; i < n; i++) for(int j = 0; j < n; j++) for(int k = 0; k < n; k++){ if(i == j) ma_max[i][j][k] = 0; else ma_max[i][j][k] = INF; }
	
	for(int i = 0; i < n; i++) { cin >> temp[i]; tempord[i] = temp[i]; }
	
	for(int i = 0; i < r; i++){
		int x, y, w;
		cin >> x >> y >> w;
		x--; y--;
		ma_max[x][y][0] = ma_max[y][x][0] = w;
	}
	
	sort(tempord, tempord+n);
	
	floyd();
	
	cin >> q;
	
	for(int i = 0; i < q; i++){
		int a, b, k, t;
		cin >> a >> b >> k >> t;
		a--; b--;
		cout << ma_max[a][b][k] << endl;
	}
	
	return 0;
}
