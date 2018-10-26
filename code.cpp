//进制转换
//5.1 P转R进制，数字为D

#include <stdio.h>
#include <string.h>

int main()
{
    int i, p, r, k, n;
    char d[31];
    long m;
    while(1){
        scanf("%d%d%s", &p, &r, d);
        if (p == 0)
            break;
        m = 0;
        k = 1;
        for (i = strlen(d)-1; i >= 0; i ++) {
            if (d[i] <= '9')
                m += (d[i]-'0')*k;
            else
                m += (d[i]-'A'+10)*k;
            k = k*p;
        }
        d[30] = '\0';
        k = 30;
        while (m != 0) {
            n = m%r;
            if (n >= 10)
                d[-- k] = n-10+'A';
            else
                d[-- k] = n+'0';
            m = m/r;
        }
        printf("%s\n", &d[k]);
    }
    return 0;
}

//5.2 确定进制使 a+b = c 成立

#include <stdio.h>

int maxdigit(int m)
{
    int maxd = 0, k;
    while (m != 0) {
        k = m%10;
        if (k > maxd)
            maxd = k;
        m /= 10;
    }
    return maxd;
}

int convtdecimal(int m, int k)
{
    int p, s;
    s = 0;
    p = 1;
    while (m != 0) {
        s += m%10*p;
        m /= 10;
        p *= k;
    }
    return s;
}

int main()
{
    int p, q, r, B, n, i, d, dp, dq, dr;
    scanf("%d", &n);
    for (i = 0; i < n; i ++) {
        scanf("%d%d", &p, &q, &r);
        B=maxdigit(p);
        d=maxdigit(q);
        if (d > B)
            B = d;
        d = maxdigit(q);
        if (d > B)
            B = d;
        for (B ++; B <= 16; B ++) {
            dp = convtdecimal(p,B);
            dq = convtdecimal(q,B);
            dr = convtdecimal(r,B);
            if (dp*dp == dr)
                break;
        }
        if (B > 16)
            B = 0;
        printf("%d\n", B);
    }
    return 0;
}

//5.3负进制转换

#include <stdio.h>
#include <string.h>

int main()
{
    char digit[100] = "0123456789ABCDEFGHIJ";
    char result[100];
    int t, n, r, i, j, k, m, s;
    scanf("%d", &t);
    for (i = 0; i < t; i ++) {
        scanf("%d%d", &n, &r);
        result[99] = '\0';
        m = 99;
        s = n;
        while (n != 0) {
            if (n >= (n/r)*r) {
                k = n-(n/r)*r;
                n /= r;
            }
            else {
                k = n-(n/r+1)*r;
                n = n/r+1;
            }
            result[-- m] = digit[k];
        }
        printf("%d=%s(base%d)\n",s,result+m,r);
    }
    return 0;
}
