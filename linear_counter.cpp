#include <iostream>
#include <fstream>
#include <cstring>
#include <iomanip>


// Maximum number of digits
const int MAX_DIGITS = 1400 ;

// Big integer type: least significant digit at index 0
typedef int BigInt[MAX_DIGITS];

// Set BigInt to a small integer value
void set_bigint(BigInt a, long long val) {
    memset(a, 0, sizeof(int) * MAX_DIGITS);
    int i = 0;
    while (val > 0 && i < MAX_DIGITS) {
        a[i++] = val % 10;
        val /= 10;
    }
}

// Copy BigInt
void copy_bigint(BigInt dest, const BigInt src) {
    memcpy(dest, src, sizeof(int) * MAX_DIGITS);
}

// Compare BigInt to 1, returns 0 if equal, <0 if less, >0 if greater
int cmp_one(const BigInt a) {
    for (int i = MAX_DIGITS - 1; i > 0; --i) {
        if (a[i] != 0) return 1;
    }
    return a[0] - 1;
}

// Check if BigInt is even
bool is_even(const BigInt a) {
    return (a[0] % 2 == 0);
}

// Divide BigInt by 2
void div2(BigInt a) {
    int carry = 0;
    for (int i = MAX_DIGITS - 1; i >= 0; --i) {
        int cur = carry * 10 + a[i];
        a[i] = cur / 2;
        carry = cur % 2;
    }
}

// Multiply BigInt by 3
void mul3(BigInt a) {
    int carry = 0;
    for (int i = 0; i < MAX_DIGITS; ++i) {
        int prod = a[i] * 3 + carry;
        a[i] = prod % 10;
        carry = prod / 10;
    }
}

// Add 1 to BigInt
void add1(BigInt a) {
    int carry = 1;
    for (int i = 0; i < MAX_DIGITS && carry; ++i) {
        int sum = a[i] + carry;
        a[i] = sum % 10;
        carry = sum / 10;
    }
}

// Subtract 1 from BigInt
void sub1(BigInt a) {
    int i = 0;
    while (i < MAX_DIGITS) {
        if (a[i] > 0) {
            a[i] -= 1;
            break;
        } else {
            a[i] = 9;
            ++i;
        }
    }
}

// Add two BigInts: res = a + b
void add_bigint(BigInt res, const BigInt a, const BigInt b) {
    int carry = 0;
    for (int i = 0; i < MAX_DIGITS; ++i) {
        int sum = a[i] + b[i] + carry;
        res[i] = sum % 10;
        carry = sum / 10;
    }
}

// Divide BigInt by 3 (assume divisible)
void div3(BigInt a) {
    int rem = 0;
    for (int i = MAX_DIGITS - 1; i >= 0; --i) {
        int cur = rem * 10 + a[i];
        a[i] = cur / 3;
        rem = cur % 3;
    }
}

// Multiply BigInt by 4
void mul4(BigInt a) {
    int carry = 0;
    for (int i = 0; i < MAX_DIGITS; ++i) {
        int prod = a[i] * 4 + carry;
        a[i] = prod % 10;
        carry = prod / 10;
    }
}

// Print BigInt
void print_bigint(const BigInt a, std::ostream& os) {
    int i = MAX_DIGITS - 1;
    while (i > 0 && a[i] == 0) --i;
    for (; i >= 0; --i) os << a[i];
}

// Collatz steps for BigInt
int collatz_steps(const BigInt n) {
    BigInt x;
    copy_bigint(x, n);
    int steps = 0;
    while (cmp_one(x) != 0) {
        if (is_even(x)) {
            div2(x);
        } else {
            mul3(x);
            add1(x);
            div2(x);
        }
        steps++;
    }
    return steps;
}

int main() {
    std::ofstream output_file("Large_linear_AVG.txt");
    int limit = 10000 ;
    long long int Time = (limit / 10) * (limit / 10) * (limit/10) / 10 ;
    long long int n_count ;
    long long int count = 0 ;
    BigInt x;
    set_bigint(x, 3);

    for (int i = 3; i <= limit; i++) {
        mul4(x);
        div3(x);

        // Prepare x-1 and x+1
        BigInt xm1, xp1;
        copy_bigint(xm1, x);
        sub1(xm1);
        copy_bigint(xp1, x);
        add1(xp1);

        int avg = (collatz_steps(x) + collatz_steps(xm1) + collatz_steps(xp1)) / 3;
        output_file << i << " " << avg << std::endl;
        n_count = (i * 1ll * i* i) / Time ;
        if(n_count != count) {
        	count = n_count ;
        	std::cout << "\r" << std::fixed << std::setprecision(2) 
          << (count / 100.0) << " %" << std::flush;
		}
    }
    output_file.close();
    return 0;
}
