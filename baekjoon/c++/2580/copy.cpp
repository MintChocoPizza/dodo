// dlx를 이용한 코드는 13297851번에

#include <iostream>
#include <memory.h>
#define FULL ((1 << 9) - 1) // 1000000000 - 1
using namespace std;

int mask[9][9];
int t[9][9];

void add_elem(int i, int j, int n) {
	t[i][j] = n + 1;    // 이건 왜 하는거지??

	mask[i][j] = 0;
	for (int p = 0; p < 9; ++p) {
		mask[i][p] &= ~(1 << n);
		mask[p][j] &= ~(1 << n);
	}
	int x = i / 3 * 3, y = j / 3 * 3;
	for (int p = 0; p < 3; ++p) 
        for (int q = 0; q < 3; ++q) 
            mask[x + p][y + q] &= ~(1 << n);
}

void single() {
	int com = 0, last = 0;
	while (1) {
		if (com - last == 4) break;
		for (int i = 0; i < 9; ++i) for (int j = 0; j < 9; ++j) {
			if (mask[i][j] && !(mask[i][j] & (mask[i][j] - 1))) {
				add_elem(i, j, __builtin_ctz(mask[i][j]));
				last = com + 1;
			}
		}
		com++;

		if (com - last == 4) break;
		for (int i = 0; i < 9; ++i) {
			int check = FULL, x = 0;
			for (int j = 0; j < 9; ++j) {
				check &= ~(x & mask[i][j]);
				x |= mask[i][j];
			}
			while (check) {
				int k = __builtin_ctz(check);
				for (int j = 0; j < 9; ++j) if (mask[i][j] & (1 << k)) {
					add_elem(i, j, k);
					last = com + 1;
					break;
				}
				check &= check - 1;
			}
		}
		com++;
		
		if (com - last == 4) break;
		for (int i = 0; i < 9; ++i) {
			int check = FULL, x = 0;
			for (int j = 0; j < 9; ++j) {
				check &= ~(x & mask[j][i]);
				x |= mask[j][i];
			}
			while (check) {
				int k = __builtin_ctz(check);
				for (int j = 0; j < 9; ++j) if (mask[j][i] & (1 << k)) {
					add_elem(j, i, k);
					last = com + 1;
					break;
				}
				check &= check - 1;
			}
		}
		com++;
		
		if (com - last == 4) break;
		for (int p = 0; p < 9; p += 3) for (int q = 0; q < 9; q += 3) {
			int check = FULL, x = 0;
			for (int i = 0; i < 3; ++i) for (int j = 0; j < 3; ++j) {
				check &= ~(x & mask[p + i][q + j]);
				x |= mask[p + i][q + j];
			}
			while (check) {
				int k = __builtin_ctz(check);
				for (int i = 0; i < 3; ++i) for (int j = 0; j < 3; ++j) {
					if (mask[p + i][q + j] & (1 << k)) {
						add_elem(p + i, q + j, k);
						last = com + 1;
						goto l1;
					}
				}
				l1:;
				check &= check - 1;
			}
		}
		com++;
	}
}

int solve() {
	single();

	int mi = -1, mj;
	for (int i = 0; i < 9; ++i) {
		for (int j = 0; j < 9; ++j) {
			if (mask[i][j]) {
				mi = i;
				mj = j;
			}
			else if (!t[i][j]) return 0;
		}
	}
	if (mi == -1) return 1;

	int tt[9][9];
	int mt[9][9];
	
	memcpy(tt, t, sizeof(tt));
	memcpy(mt, mask, sizeof(mt));
	
	for (int next = 0; next < 9; ++next) {
		if (mask[mi][mj] & (1 << next)) {
			add_elem(mi, mj, next);
			if (solve()) return 1;
			else {
				memcpy(t, tt, sizeof(tt));
				memcpy(mask, mt, sizeof(mt));
			}
		}
	}
	return 0;
}

int main() {
	ios::sync_with_stdio(0);
	cin.tie(0);

	for (int i = 0; i < 9; ++i) 
        for (int j = 0; j < 9; ++j) 
            mask[i][j] = FULL;

	for (int i = 0; i < 9; ++i) 
        for (int j = 0; j < 9; ++j) 
        {
            // 값 저장
            cin >> t[i][j];
            if (t[i][j])    // 0이 아니라면
                add_elem(i, j, t[i][j] - 1);
    	}

	solve();
	for (int i = 0; i < 9; ++i) {
		for (int j = 0; j < 9; ++j) cout << t[i][j] << ' ';
		cout << '\n';
	}
}
