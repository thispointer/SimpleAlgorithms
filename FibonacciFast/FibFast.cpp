#include <iostream>

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

unsigned long long get_fibonacci_huge(unsigned long long n, long long m) {
    long long remainder = n % get_pisano_period(m);

    long long first = 0;
    long long second = 1;

    long long res = remainder;

    for (int i = 1; i < remainder; i++) {
        res = first + second;
        first = second;
        second = res;
    }

    return res;
}

int main() {
//    for (int i = 2; i < 100; i++) {
//        std::cout << i << " : " << get_pisano_period(i) << std::endl;
//    }
//    return 0;
    const auto m = 10;

    unsigned long long n;
    
    std::cin >> n;

    for (unsigned long long i =0; i <= n; i++)
    {
        std::cout << i << ". " << get_fibonacci_huge(i, m) << '\n';
    }
}
