#include<cstdio>

const int SIZ = 1 << 20;
namespace in {
	char buf[SIZ + 1];
	int idx, ridx;

	inline char read() {
		if (idx == ridx) {
			ridx = fread(buf, 1, SIZ, stdin);
			idx = buf[ridx] = 0;
		}
		return buf[idx++];
	}
	inline int readint() {
		int res = 0;
		bool neg = 0;
		register char tmp = read();
		while (tmp < 33) tmp = read();
		if (tmp == '-') neg = 1, tmp = read();
		while (tmp >= 48 && tmp <= 57) {
			res = res * 10 + (tmp & 15);
			tmp = read();
		}
		return neg ? -res : res;
	}
}
namespace out {
	char buf[SIZ];
	int idx;

	inline void flush() {
		fwrite(buf, 1, idx, stdout);
	}
	inline void write(register char c) {
		if (idx == SIZ) {
			flush();
			idx = 0;
		}
		buf[idx++] = c;
	}
	inline void writeint(int i) {
		register char tmp[8], t = 0;
		while (i) {
			tmp[t++] = (i % 10) | 48;
			i /= 10;
		}
		while (t) {
			write(tmp[--t]);
		}
	}
}

bool p[1000001], m[1000001];
int n, x;
int main() {
#ifdef _CONSOLE
	freopen("input.txt", "r", stdin);
#endif
	n = in::readint();
	for (int i = 0; i < n; ++i) {
		x = in::readint();
		if (x < 0) m[-x] = 1;
		else p[x] = 1;
	}
	for (int i = 1000000; i; --i) {
		if (m[i]) {
			out::write('-');
			out::writeint(i);
			out::write('\n');
		}
	}
	if (p[0]) out::write('0'), out::write('\n');
	for (int i = 1; i <= 1000000; ++i) {
		if (p[i]) {
			out::writeint(i);
			out::write('\n');
		}
	}
	out::flush();
	return 0;
}