#pragma GCC optimize("O3")
#pragma GCC target("avx2")
#include <bits/stdc++.h>
#include <sys/stat.h>
#include <sys/mman.h>
#include <unistd.h>
using namespace std;

/////////////////////////////////////////////////////////////////////////////////////////////
/*
 * Author : jinhan814
 * Date : 2021-05-06
 * Source : https://blog.naver.com/jinhan814/222266396476
 * Description : FastIO implementation for cin, cout. (mmap ver.)
 */
constexpr int SZ = 1 << 20;

class INPUT {
private:
	char* p;
	bool __END_FLAG__, __GETLINE_FLAG__;
public:
	explicit operator bool() { return !__END_FLAG__; }
    INPUT() {
        struct stat st; fstat(0, &st);
        p = (char*)mmap(0, st.st_size, PROT_READ, MAP_SHARED, 0, 0);
    }
	bool IsBlank(char c) { return c == ' ' || c == '\n'; }
	bool IsEnd(char c) { return c == '\0'; }
	char _ReadChar() { return *p++; }
	char ReadChar() {
		char ret = _ReadChar();
		for (; IsBlank(ret); ret = _ReadChar());
		return ret;
	}
	template<typename T> T ReadInt() {
		T ret = 0; char cur = _ReadChar(); bool flag = 0;
		for (; IsBlank(cur); cur = _ReadChar());
		if (cur == '-') flag = 1, cur = _ReadChar();
		for (; !IsBlank(cur) && !IsEnd(cur); cur = _ReadChar()) ret = 10 * ret + (cur & 15);
		if (IsEnd(cur)) __END_FLAG__ = 1;
		return flag ? -ret : ret;
	}
	string ReadString() {
		string ret; char cur = _ReadChar();
		for (; IsBlank(cur); cur = _ReadChar());
		for (; !IsBlank(cur) && !IsEnd(cur); cur = _ReadChar()) ret.push_back(cur);
		if (IsEnd(cur)) __END_FLAG__ = 1;
		return ret;
	}
	double ReadDouble() {
		string ret = ReadString();
		return stod(ret);
	}
	string getline() {
		string ret; char cur = _ReadChar();
		for (; cur != '\n' && !IsEnd(cur); cur = _ReadChar()) ret.push_back(cur);
		if (__GETLINE_FLAG__) __END_FLAG__ = 1;
		if (IsEnd(cur)) __GETLINE_FLAG__ = 1;
		return ret;
	}
	friend INPUT& getline(INPUT& in, string& s) { s = in.getline(); return in; }
} _in;

class OUTPUT {
private:
	char write_buf[SZ];
	int write_idx;
public:
	~OUTPUT() { Flush(); }
	explicit operator bool() { return 1; }
	void Flush() {
        write(1, write_buf, write_idx);
		write_idx = 0;
	}
	void WriteChar(char c) {
		if (write_idx == SZ) Flush();
		write_buf[write_idx++] = c;
	}
	template<typename T> int GetSize(T n) {
		int ret = 1;
		for (n = n >= 0 ? n : -n; n >= 10; n /= 10) ret++;
		return ret;
	}
	template<typename T> void WriteInt(T n) {
		int sz = GetSize(n);
		if (write_idx + sz >= SZ) Flush();
		if (n < 0) write_buf[write_idx++] = '-', n = -n;
		for (int i = sz; i --> 0; n /= 10) write_buf[write_idx + i] = n % 10 | 48;
		write_idx += sz;
	}
	void WriteString(string s) { for (auto& c : s) WriteChar(c); }
	void WriteDouble(double d) { WriteString(to_string(d)); }
} _out;

/* operators */
INPUT& operator>> (INPUT& in, char& i) { i = in.ReadChar(); return in; }
INPUT& operator>> (INPUT& in, string& i) { i = in.ReadString(); return in; }
template<typename T, typename std::enable_if_t<is_arithmetic_v<T>>* = nullptr>
INPUT& operator>> (INPUT& in, T& i) {
	if constexpr (is_floating_point_v<T>) i = in.ReadDouble();
	else if constexpr (is_integral_v<T>) i = in.ReadInt<T>(); return in; }

OUTPUT& operator<< (OUTPUT& out, char i) { out.WriteChar(i); return out; }
OUTPUT& operator<< (OUTPUT& out, string i) { out.WriteString(i); return out; }
template<typename T, typename std::enable_if_t<is_arithmetic_v<T>>* = nullptr>
OUTPUT& operator<< (OUTPUT& out, T i) {
	if constexpr (is_floating_point_v<T>) out.WriteDouble(i);
	else if constexpr (is_integral_v<T>) out.WriteInt<T>(i); return out; }

/* macros */
#define fastio 1
#define cin _in
#define cout _out
#define istream INPUT
#define ostream OUTPUT
/////////////////////////////////////////////////////////////////////////////////////////////

namespace kx { //reference : https://github.com/voutcn/kxsort
    static const int kRadixBits = 4;
    static const size_t kInsertSortThreshold = 64;
    static const int kRadixMask = (1 << kRadixBits) - 1;
    static const int kRadixBin = 1 << kRadixBits;

    //================= HELPING FUNCTIONS ====================

    template <class T>
    struct RadixTraitsUnsigned {
        static const int nBytes = sizeof(T);
        int kth_byte(const T& x, int k) { return (x >> (kRadixBits * k)) & kRadixMask; }
        bool compare(const T& x, const T& y) { return x < y; }
    };

    template<class T>
    struct RadixTraitsSigned {
        static const int nBytes = sizeof(T);
        static const T kMSB = T(0x80) << ((sizeof(T) - 1) * 8);
        int kth_byte(const T& x, int k) {
            return ((x ^ kMSB) >> (kRadixBits * k)) & kRadixMask;
        }
        bool compare(const T& x, const T& y) { return x < y; }
    };

    template <class RandomIt, class ValueType, class RadixTraits>
    inline void insert_sort_core_(RandomIt s, RandomIt e, RadixTraits radix_traits) {
        for (RandomIt i = s + 1; i < e; ++i) {
            if (radix_traits.compare(*i, *(i - 1))) {
                RandomIt j;
                ValueType tmp = *i;
                *i = *(i - 1);
                for (j = i - 1; j > s && radix_traits.compare(tmp, *(j - 1)); --j) {
                    *j = *(j - 1);
                }
                *j = tmp;
            }
        }
    }

    template <class RandomIt, class ValueType, class RadixTraits, int kWhichByte>
    inline void radix_sort_core_(RandomIt s, RandomIt e, RadixTraits radix_traits) {
        RandomIt last_[kRadixBin + 1];
        RandomIt* last = last_ + 1;
        size_t count[kRadixBin] = { 0 };

        for (RandomIt i = s; i < e; ++i) {
            ++count[radix_traits.kth_byte(*i, kWhichByte)];
        }

        last_[0] = last_[1] = s;

        for (int i = 1; i < kRadixBin; ++i) {
            last[i] = last[i - 1] + count[i - 1];
        }

        for (int i = 0; i < kRadixBin; ++i) {
            RandomIt end = last[i - 1] + count[i];
            if (end == e) { last[i] = e; break; }
            while (last[i] != end) {
                ValueType swapper = *last[i];
                int tag = radix_traits.kth_byte(swapper, kWhichByte);
                if (tag != i) {
                    do {
                        std::swap(swapper, *last[tag]++);
                    } while ((tag = radix_traits.kth_byte(swapper, kWhichByte)) != i);
                    *last[i] = swapper;
                }
                ++last[i];
            }
        }

        if (kWhichByte > 0) {
            for (int i = 0; i < kRadixBin; ++i) {
                if (count[i] > kInsertSortThreshold) {
                    radix_sort_core_<RandomIt, ValueType, RadixTraits,
                        (kWhichByte > 0 ? (kWhichByte - 1) : 0)>
                        (last[i - 1], last[i], radix_traits);
                }
                else if (count[i] > 1) {
                    insert_sort_core_<RandomIt, ValueType, RadixTraits>(last[i - 1], last[i], radix_traits);
                }
            }
        }
    }

    template <class RandomIt, class ValueType, class RadixTraits>
    inline void radix_sort_entry_(RandomIt s, RandomIt e, ValueType*, RadixTraits radix_traits) {
        if (e - s <= (int)kInsertSortThreshold)
            insert_sort_core_<RandomIt, ValueType, RadixTraits>(s, e, radix_traits);
        else
            radix_sort_core_<RandomIt, ValueType, RadixTraits, RadixTraits::nBytes - 1>(s, e, radix_traits);
    }

    template <class RandomIt, class ValueType>
    inline void radix_sort_entry_(RandomIt s, RandomIt e, ValueType*) {
        if (ValueType(-1) > ValueType(0)) {
            radix_sort_entry_(s, e, (ValueType*)(0), RadixTraitsUnsigned<ValueType>());
        }
        else {
            radix_sort_entry_(s, e, (ValueType*)(0), RadixTraitsSigned<ValueType>());
        }
    }

    //================= INTERFACES ====================

    template <class RandomIt, class RadixTraits>
    inline void radix_sort(RandomIt s, RandomIt e, RadixTraits radix_traits) {
        typename std::iterator_traits<RandomIt>::value_type* dummy(0);
        radix_sort_entry_(s, e, dummy, radix_traits);
    }

    template <class RandomIt>
    inline void radix_sort(RandomIt s, RandomIt e) {
        typename std::iterator_traits<RandomIt>::value_type* dummy(0);
        radix_sort_entry_(s, e, dummy);
    }
}

using pii = pair<int, int>;
constexpr int bias = 1e5;

struct RadixTraitsPii {
    static const int nBytes = 10;
    int kth_byte(const pair<int, int>& x, int k) {
  	    if (k >= 5) return x.first >> ((k - 5) * kx::kRadixBits) & kx::kRadixMask;
  	    return x.second >> (k * kx::kRadixBits) & kx::kRadixMask;
    }
    bool compare(const pair<int, int>& x, const pair<int, int>& y) {
    	return x < y;
    }
};

int main() {
	fastio;
	int n; cin >> n; pii v[n];
	for (int i = 0; i < n; i++)
        cin >> v[i].first >> v[i].second,
        v[i].first += bias, v[i].second += bias;

    kx::radix_sort(v, v + n, RadixTraitsPii());
	for (int i = 0; i < n; i++)
        cout << v[i].first - bias << ' '
             << v[i].second - bias << '\n';
}
