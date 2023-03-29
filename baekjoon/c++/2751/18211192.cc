#include <iostream>
#include <fstream>

using namespace std;

#include <algorithm>
namespace fio
{
	constexpr size_t BUF_SIZ = 524288, SPARE = 20;
	size_t buf_siz = 0;
	char buf_i[BUF_SIZ], *p_in = buf_i + buf_siz;

	inline char getCh(void)
	{

		while (p_in == buf_i + buf_siz) {
			cin.read( buf_i, BUF_SIZ - 100); 	p_in = buf_i;
			buf_siz = cin.gcount();
		}
		return *(p_in++);
	}

	template<typename T>
  	inline int get(void)
  	{
		int t;
		T r;
		while( (t = getCh()) < '-') 	;
		if (t == '-') {
			for (r = getCh() - '0'; (t = getCh() - '0') >= 0; r = r * 10 + t);
			return -r;
		}
		for (r = t - '0'; (t = getCh() - '0') >= 0; r = r * 10 + t);
		return r;
  	}

	char buf_o[BUF_SIZ + SPARE], *p_out = buf_o;

	template<typename T>
	void prt(T n, char ch = ' ')
	{
		if (n < 0) n = -n, *p_out++ = '-';
		char *ptr = p_out;
		do {	*ptr++ = n % 10 + '0';	n /= 10;	} while (n);
		reverse(p_out, ptr);
		*ptr++ = ch;
		if (ptr < buf_o + BUF_SIZ) p_out = ptr;
		else {	cout.write(buf_o, ptr - buf_o);		p_out = buf_o;	}
	}

	inline void prtn( void)
	{
		*p_out++ = '\n';
		if (p_out >= buf_o + BUF_SIZ)
		{	cout.write(buf_o, p_out - buf_o);		p_out = buf_o;	}
	}

	void flush(void)
	{
		cout.write(buf_o, p_out - buf_o);
	}
};
///////////////////////////
const int  MAXN   = 2'000'002;
const int  OFFSET = 1'000'001;

int N;
int num[MAXN];

int main( void)
{
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);
	cout.tie(NULL);
#ifdef JH_DEBUG
	ifstream in( "2751_input.txt");
	cin.rdbuf( in.rdbuf());
#endif

	N = fio::get<int>();
    int value;
	for(int n = 0; n < N; n++)
	{
        value = fio::get<int>();
        //cout << value << endl;
		num[value + OFFSET] = 1;
	}

	for(int n = 0; n < MAXN; n++)
	{
		if ( num[n] == 1)	fio::prt<int>( n - OFFSET, '\n');
	}
	fio::flush();

	return 0;
}