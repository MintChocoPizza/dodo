#include<unistd.h>
#include<algorithm>
using namespace std;

namespace fio {
    const int BSIZE = 1000000;
    char buffer[BSIZE + 1];
    int p = BSIZE;
    inline unsigned char readChar() {
        if(p == BSIZE) {
            buffer[syscall(0x00, 0, buffer, BSIZE)] = '\n';
            p = 0;
        }
        return buffer[p++];
    }
    int readInt() {
        unsigned char c = readChar();
        while (c < '-') {
            c = readChar();
        }
        unsigned ret = 0; bool neg = c == '-';
        if (neg) c = readChar();
        while (c >= '0' && c <= '9') {
            ret = ret * 10 + c - '0';
            c = readChar();
        }
        return neg ? -(int)ret : (int)ret;
    }
    char outbuf[20000005];
    int p2;
    void writeInt(int x) {
        if (x < 0) {
            outbuf[p2++] = '-';
            x = -x;
        }
        int p3 = p2;
        unsigned y = x;
        do {
            outbuf[p2++] = y % 10 + '0';
        } while (y /= 10);
        reverse(outbuf + p3, outbuf + p2);
        outbuf[p2++] = '\n';
    }
}
bool s[2000005];
int main()
{
    int n = fio::readInt();
    for(int i=0;i<n;i++)
    {
        int x = fio::readInt();
        s[x+1000000] = true;
    }
    for(int i=0;i<=2000000;i++)
        if(s[i]) fio::writeInt(i - 1000000);
    syscall(0x01, 1, fio::outbuf, fio::p2);
}
