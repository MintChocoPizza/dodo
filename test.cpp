#pragma GCC optimize("O3")
#pragma GCC target("avx2,bmi2,popcnt,lzcnt,fma")

#include <stdio.h>
#include <unistd.h>
#include <inttypes.h>
#include <sys/stat.h>
#include <sys/mman.h>
// This class only aims for fast input, skipping various checks.
// This class assumes input is well-formed, which means
// every token is separated by single whitespace (ascii <=  32)
class FastIO
{
    constexpr static off_t BUF_SIZE = 1 << 20;
    char buf[BUF_SIZE];
    char *p;
    int ofd, idx;

public:
    // opens file descriptor
    explicit FastIO(int ifd = 0, int ofd = 1)
    {
        struct stat st;
        fstat(ifd, &st);
        if (S_ISREG(st.st_mode))
            p = (char *)mmap(NULL, st.st_size, PROT_READ, MAP_SHARED, ifd, 0);
        this->ofd = ofd;
        idx = 0;
    }

    ~FastIO() { flush(); }

    void flush()
    {
        write(ofd, buf, idx);
        idx = 0;
    }

    void writeI64(int64_t x, char end)
    {
        static const off_t MAX_WIDTH = 21;
        if (idx + MAX_WIDTH > BUF_SIZE)
            flush();

        char tmp[MAX_WIDTH];
        int sz = 0;

        if (x < 0)
            buf[idx++] = '-', x = -x;
        if (x == 0)
            tmp[sz++] = '0';
        while (x)
        {
            tmp[sz++] = '0' + (x % 10);
            x /= 10;
        }
        while (sz)
            buf[idx++] = tmp[--sz];
        buf[idx++] = end;
    }

    void writeU64(uint64_t x, char end)
    {
        static const off_t MAX_WIDTH = 21;
        if (idx + MAX_WIDTH > BUF_SIZE)
            flush();
        char tmp[MAX_WIDTH];
        int sz = 0;

        if (x == 0)
            tmp[sz++] = '0';
        while (x)
        {
            tmp[sz++] = '0' + (x % 10);
            x /= 10;
        }
        while (sz)
            buf[idx++] = tmp[--sz];
        buf[idx++] = end;
    }

    uint64_t readU64()
    {
        uint64_t r = 0;
        if (p)
        {
            int t;
            r = *p++ - 48;
            while ((t = *p++ - 48) >= 0)
                r = r * 10 + t;
        }
        else
            scanf("%" SCNu64, &r);
        return r;
    }

    int64_t readI64()
    {
        int64_t r = 0;
        if (p)
        {
            int t, s = 0;
            r = *p++ - 48;
            if (r < 0)
                s = 1, r = *p++ - 48;
            while ((t = *p++ - 48) >= 0)
                r = r * 10 + t;
            if (s)
                r = -r;
        }
        else
            scanf("%" SCNd64, &r);
        return r;
    }
} io;

int main()
{
    int T = io.readU64();
    while (T--)
        io.writeU64(io.readU64() + io.readU64(), '\n');
}
