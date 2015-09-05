#include <iostream>
#include <algorithm>

using namespace std;
typedef long long lli;

const lli N = 150;

int main(){
	lli H, W;
	cin >> H >> W;
	lli C[N][N];
	for(lli i=0;i<H;i++){
		for(lli j=0;j<W;j++){
			cin >> C[i][j];
		}
	}
	lli yoko[2][N][N];
	fill(yoko[0][0], yoko[2][0], 0);
	for(lli i=0;i<H;i++){
		for(lli j=0;j<W;j++){
			for(lli k=0;k<2;k++){
				lli tmp = (((i + j) % 2 == k) ? C[i][j] : 0);
				if(j == 0){
					yoko[k][i][j] = tmp;
				}else{
					yoko[k][i][j] = yoko[k][i][j-1] + tmp;
				}
			}
		}
	}
	lli sum[2][N][N];
	fill(sum[0][0], sum[2][0], 0);
	for(lli j=0;j<W;j++){
		for(lli i=0;i<H;i++){
			for(lli k=0;k<2;k++){
				if(i == 0){
					sum[k][i][j] = yoko[k][i][j];
				}else{
					sum[k][i][j] = sum[k][i-1][j] + yoko[k][i][j];
				}
			}
		}
	}
	lli ans = 0;
	for(lli i1=0;i1<H;i1++){
		for(lli j1=0;j1<W;j1++){
			for(lli i2=i1;i2<H;i2++){
				for(lli j2=j1;j2<W;j2++){
					lli a = sum[0][i2][j2];
					lli b = sum[1][i2][j2];
					if(i1 > 0 && j1 > 0){
						a -= sum[0][i2][j1-1];
						b -= sum[1][i2][j1-1];
						a -= sum[0][i1-1][j2];
						b -= sum[1][i1-1][j2];
						a += sum[0][i1-1][j1-1];
						b += sum[1][i1-1][j1-1];
					}else if(i1 > 0){
						a -= sum[0][i1-1][j2];
						b -= sum[1][i1-1][j2];
					}else if(j1 > 0){
						a -= sum[0][i2][j1-1];
						b -= sum[1][i2][j1-1];
					}
					if(a == b){
						ans = max(ans, (i2 - i1 +  1) * (j2 - j1 + 1));
					}
				}
			}
		}
	}
	cout << ans << endl;
	return 0;
}
