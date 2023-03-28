#include <cstdio>
#define MAX 1<<16

char wbuf[MAX];
int widx, result[8], N, M;
bool check[8]{};

inline void bflush() {
    fwrite(wbuf, 1, widx, stdout);
    widx = 0;
}

inline void write(int c) {
    if (widx + 2 * c >= MAX) bflush();

    for (int i = 0; i < c - 1; i++) wbuf[widx++] = result[i] + '0', wbuf[widx++] = ' ';
    wbuf[widx++] = result[c - 1] + '0', wbuf[widx++] = '\n';
}

void dfs(int count) {
    if (count == M) { write(count); return; }
    
    for (int i = 0; i < N; i++) {
        if (check[i]) continue;
        check[i] = true;
        result[count] = i + 1;
        dfs(count + 1);
        check[i] = false;
    }
}

int main(void) {
    scanf("%d %d", &N, &M);
    dfs(0);
    bflush();
}
