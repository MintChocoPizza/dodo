#include <cstdio>
#include <algorithm>
#include <cstring>
#include <iostream>

char wbuf[1<<20];
char rbuf[1<<20];
int ridx, nidx, widx;

inline char read(){
    if(ridx == nidx){
        nidx = fread(rbuf, 1, 1<<20, stdin);
        if(!nidx) return 0;
        ridx = 0;
    }
    return rbuf[ridx++];
}

inline int readInt(){
    int sum = 0;
    char now = read();
    
    while(now <= 32) now = read();
    while(now >= 48) sum = sum * 10 + now - '0', now = read();
    
    return sum;
}

inline void readChar(char c[51]){
    char now = read();
    char tmp[51];
    int idx = 0;
    while(now <= 32) now = read();
    while(now >= 48) tmp[idx++] = now, now = read();
    
    tmp[idx] = '\0';
    strcpy(c, tmp);
}

inline void bflush(){
    fwrite(wbuf, 1, widx, stdout);
    widx = 0;
}

inline void write(char c){
    if(widx == (1<<20)) bflush();
    wbuf[widx++] = c;
}

inline void writeChar(char c[51]){
    int isz = 1;
    while(c[isz] != '\0') isz++;
    if(isz + widx >= (1<<20)) bflush();
    
    for(int i = 0; i<isz; i++){
        wbuf[widx++] = c[i];
    }
    write('\n');
}

struct Word {
    int length;
    char word[51];
};

bool compare(const Word& a, const Word& b) {
    if(a.length == b.length){
        if(strcmp(a.word, b.word) <0) return true;
        else return false;
    }
    return a.length < b.length;
}

Word w[20001];

int main(void) {
    int N = readInt();
    char tmp[51];
    for (int i = 0; i < N; i++) {
        readChar(w[i].word);
        w[i].length = strlen(w[i].word);
    }
    std::sort(w, w + N, compare);
    writeChar(w[0].word);
    for (int i = 1; i < N; i++) {
        if (strcmp(w[i].word, w[i - 1].word)) writeChar(w[i].word);
    }
    bflush();
}
