#include <iostream>

/* 
void fib_fast (unsigned long long n, unsigned long long ans[])
{
    const auto MOD = 1000000007;

    if (n == 0)
    {
        ans[0] = 0;
        ans[1] = 1;
        return;
    }

    unsigned long long a = 0;
    unsigned long long b = 1;
    long long c = 0;
    unsigned long long d = 0;
    
    fib_fast ((n/2), ans);
    a = ans[0];             // F(n) 
    b = ans[1];             // F(n+1) 
    c = 2*b - a;
    if(c < 0)
        c += MOD;
    c = (a * c) % MOD;      // F(2n) 
    d = (a*a + b*b) % MOD;  // F(2n + 1) 
    if(n%2 == 0)
    {
        ans[0] = c;
        ans[1] = d;
    }
    else
    {
        ans[0] = d;
        ans[1] = c+d;
    }
}
 */
//------------------

long long get_pisano_period(long long m) {
    long long a = 0, b = 1, c = a + b;
    for (int i = 0; i < m * m; i++) {
        c = (a + b) % m;
        a = b;
        b = c;
        if (a == 0 && b == 1) return i + 1;
    }
    return 0;
}

long long get_fibonacci_huge(long long n, long long m) {
    long long remainder = n % get_pisano_period(m);

    long long first = 0;
    long long second = 1;

    long long res = remainder;

    for (int i = 1; i < remainder; i++) {
        res = (first + second) % m;
        first = second;
        second = res;
    }

    return res % m;
}


int main() {
    unsigned long long n = 0;
    //unsigned long long ans[2] = {0};

    std::cin >> n;

    //--- get huge number
    //fib_fast(n+2, ans);
    //std::cout << ans[0] << std::endl;

    int digit = get_fibonacci_huge(n + 2, 10);
    digit = digit == 0 ? 9: digit - 1; 
    std::cout <<  digit << std::endl;
}
