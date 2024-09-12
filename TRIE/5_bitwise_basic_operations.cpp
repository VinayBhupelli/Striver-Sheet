#include<bits/stdc++.h>
using namespace std;

int getXOR(int a, int b) {
    return a^b;
}

int getBit(int c, int d) {
    int shift = 1 << c;
    return (d & shift)==0?0:1;
}

int setBit(int e, int f) {
    int shift = 1 << e;
    return (f | shift);
}