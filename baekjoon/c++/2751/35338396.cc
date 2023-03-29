#include <bits/stdc++.h>
#include <sys/stat.h>
#include <sys/mman.h>
#include <unistd.h>
using namespace std;

constexpr int Bits = 8;
constexpr int SZ   = 1 << Bits;
constexpr int Mask = SZ - 1;
constexpr int MSB  = 1 << 31;

template<typename It>
void InsertionSort(const It st, const It en) {
	for (auto i = st, j = st; i < en; i++) {
		const auto val = *i;
		for (j = i - 1; j >= st; j--) {
			if (val < *j) *(j + 1) = *j;
			else break;
		}
		*(j + 1) = val;
	}
}

void RadixSort(vector<int>& v, int st, int en, int d = 3) {
	vector<int> cnt(SZ), t(en - st);
	for (int i = st; i < en; i++) cnt[((v[i] ^ MSB) >> Bits * d) & Mask]++;
	for (int i = 1; i < SZ; i++) cnt[i] += cnt[i - 1];

	for (int i = en - 1; i >= st; i--) t[--cnt[((v[i] ^ MSB) >> Bits * d) & Mask]] = v[i];
	for (int i = st; i < en; i++) v[i] = t[i - st];

	if (d) for (int i = 0; i < SZ; i++) {
		const int l = cnt[i], r = i + 1 < SZ ? cnt[i + 1] : en - st;
		if (r - l > 16) RadixSort(v, st + l, st + r, d - 1);
		else InsertionSort(v.begin() + st + l, v.begin() + st + r);
	}
}

int main() {
    struct stat st; fstat(0, &st);
	char w[1 << 16], *p = (char*)mmap(0, st.st_size, PROT_READ, MAP_SHARED, 0, 0), *q = w;
	auto ReadInt = [&]() {
		int ret = 0; char c = *p++, flag = 0;
        if (c == '-') c = *p++, flag = 1;
		for (; c & 16; ret = 10 * ret + (c & 15), c = *p++);
		return flag ? -ret : ret;
	};
    auto WriteInt = [&](int n) {
        if (n < 0) *q++ = '-', n = -n;
        int sz = 1, t = n;
        if (q - w + 10 >= 1 << 16) write(1, w, q - w), q = w;
        for (; t >= 10; t /= 10) sz++;
        for (int i = sz; i --> 0; n /= 10) q[i] = n % 10 | 48;
        q += sz; *q++ = '\n';
    };

	int n = ReadInt();
	vector<int> v(n);
	for (int i = 0; i < n; i++) v[i] = ReadInt();
	RadixSort(v, 0, n);
	for (auto& i : v) WriteInt(i);
    write(1, w, q - w);
}