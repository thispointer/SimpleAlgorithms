#include <iostream>
#include <vector>
using std::vector;
//------------------

const unsigned int PISANO = 60;

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

long long get_lastDigitFibonacci_huge(long long n, long long m) {
    // long long remainder = n % get_pisano_period(m);
    long long remainder = n % PISANO;

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

long long get_fibonacci_partial_sum_naive(long long from, long long to) {
    long long sum = 0;

    long long current = 0;
    long long next  = 1;

    // std::cout << "current next sum" << std::endl;
    for (long long i = 0; i <= to; ++i) {
        if (i >= from) {
            sum += current;
        }

        // std::cout << i << ". " << current << "     " <<  next << "  " << sum << std::endl;

        long long new_current = next;
        next = next + current;
        current = new_current;
    }
    
    return sum % 10;
}

void init_pisano_fib_sum (unsigned int sequenceModulo[], unsigned int len)
{
    sequenceModulo[0] = 0;
    sequenceModulo[1] = 1;

    for (unsigned int i = 2; i < len; ++i) {
        sequenceModulo[i] = (sequenceModulo[i-2] + sequenceModulo[i-1]) % 10;
    }   
}

long long get_fibonacci_last_digit_partial_sum(long long from, long long to, unsigned int sequenceModulo[], unsigned int len) {
    long long left = from % PISANO;
    long long right = to % PISANO;
    long long sum = 0;

    if (right < left)
        right += PISANO;

    for (long long i = left; i < right + 1; i++) {
        sum += sequenceModulo[i % PISANO];
    }
    
    return sum % 10;
}

int main() { 
    long long from, to = 0;
    unsigned int sequencePisano[PISANO];

     std::cin >> from >> to;

/*
    std::cout << get_fibonacci_partial_sum_naive(from, to) << '\n';

    std::cout << std::endl << std::endl;
    std::cout << "-------------------- LAST DIGIT PARTIAL SUM -------------------- "  << std::endl;
    std::cout << std::endl; */

    init_pisano_fib_sum (sequencePisano, PISANO);

/*     std::cout << std::endl << std::endl;
    std::cout << "       ------- Pisano Sequence Sums ----------------- "  << std::endl;
    std::cout << std::endl;

    for (unsigned int i = 0; i < PISANO; i++) {
         std::cout << i << ". " << sequencePisano[i] << std::endl;
    }

    std::cout << std::endl << std::endl;
     */
    
    std::cout <<  get_fibonacci_last_digit_partial_sum(from, to, sequencePisano, PISANO) << std::endl;
}
