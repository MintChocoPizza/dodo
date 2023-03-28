#pragma GCC target("arch=haswell")
#include <unistd.h>

constexpr long M = 1e6;
constexpr long BUF_SZ = 1 << 19;

__attribute__((always_inline)) inline int geti(char buf[BUF_SZ], char*& in)
{
	if(in >= buf + BUF_SZ - 32) [[unlikely]]
	{
		int i;
		for(i = 0; in[i]; ++i)
			buf[i] = in[i];
		in = buf;
		buf[i + read(0, buf + i, BUF_SZ - i)] = 0;
	}

	bool const e = *in == '-';
	in += e;
	int x = *in - '0', i;
	for(i = 1; i < 7; ++i)
	{
		int const y = in[i] - '0';
		if(y < 0)
			break;
		x = x * 10 + y;
	}
	in += i + 1;
	return e ? x + M : x;
}

__attribute__((always_inline)) inline void flush(char buf[BUF_SZ], char*& out)
{
	if(out >= buf + BUF_SZ - 256) [[unlikely]]
	{
		write(1, buf, out - buf);
		out = buf;
	}
}

int main()
{
	bool A[M * 2 + 1]{};
	char buf[BUF_SZ + 1], *in = buf + BUF_SZ, *out = buf;
	*in = 0;

	long N = geti(buf, in);
	for(int i = 0; __builtin_expect(i < N, true); i++)
		A[geti(buf, in)] = true;

	long i = M * 2;
	#define R(i, ...) \
		for(char c##i = '9'; c##i != '0' + (__VA_ARGS__ - 1); --c##i)

	if(A[i--]) { out[0] = '-'; out[1] = '1'; out[2] = '0'; out[3] = '0'; out[4] = '0'; out[5] = '0'; out[6] = '0'; out[7] = '0'; out[8] = '\n'; out += 9; }
	R(0, 1) R(1) R(2) R(3) R(4) { R(5) { out[0] = '-'; out[1] = c0; out[2] = c1; out[3] = c2; out[4] = c3; out[5] = c4; out[6] = c5; out[7] = '\n'; out += A[i--] ? 8 : 0; } flush(buf, out); }
	R(0, 1) R(1) R(2) R(3) { R(4) { out[0] = '-'; out[1] = c0; out[2] = c1; out[3] = c2; out[4] = c3; out[5] = c4; out[6] = '\n'; out += A[i--] ? 7 : 0; } flush(buf, out); }
	R(0, 1) R(1) R(2) { R(3) { out[0] = '-'; out[1] = c0; out[2] = c1; out[3] = c2; out[4] = c3; out[5] = '\n'; out += A[i--] ? 6 : 0; } flush(buf, out); }
	R(0, 1) R(1) { R(2) { out[0] = '-'; out[1] = c0; out[2] = c1; out[3] = c2; out[4] = '\n'; out += A[i--] ? 5 : 0; } flush(buf, out); }
	R(0, 1) { R(1) { out[0] = '-'; out[1] = c0; out[2] = c1; out[3] = '\n'; out += A[i--] ? 4 : 0; } flush(buf, out); }
	{ R(0, 1) { out[0] = '-'; out[1] = c0; out[2] = '\n'; out += A[i--] ? 3 : 0; } flush(buf, out); }

	i = 0;

	#define T(i, ...) \
		for(char c##i = '0' + (__VA_ARGS__ + 0); c##i != '9' + 1; ++c##i)
	{ T(0) { out[0] = c0; out[1] = '\n'; out += A[i++] ? 2 : 0; } flush(buf, out); }
	T(0, 1) { T(1) { out[0] = c0; out[1] = c1; out[2] = '\n'; out += A[i++] ? 3 : 0; } flush(buf, out); }
	T(0, 1) T(1) { T(2) { out[0] = c0; out[1] = c1; out[2] = c2; out[3] = '\n'; out += A[i++] ? 4 : 0; } flush(buf, out); }
	T(0, 1) T(1) T(2) { T(3) { out[0] = c0; out[1] = c1; out[2] = c2; out[3] = c3; out[4] = '\n'; out += A[i++] ? 5 : 0; } flush(buf, out); }
	T(0, 1) T(1) T(2) T(3) { T(4) { out[0] = c0; out[1] = c1; out[2] = c2; out[3] = c3; out[4] = c4; out[5] = '\n'; out += A[i++] ? 6 : 0; } flush(buf, out); }
	T(0, 1) T(1) T(2) T(3) T(4) { T(5) { out[0] = c0; out[1] = c1; out[2] = c2; out[3] = c3; out[4] = c4; out[5] = c5; out[6] = '\n'; out += A[i++] ? 7 : 0; } flush(buf, out); }

	if(A[i++]) { out[0] = '1'; out[1] = '0'; out[2] = '0'; out[3] = '0'; out[4] = '0'; out[5] = '0'; out[6] = '0'; out[7] = '\n'; out += 8; }

	write(1, buf, out - buf);
}