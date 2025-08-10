#include <iostream>
#include <fstream>

int collatz_steps(long long n) {
    int steps = 0;
    while (n != 1) {
        if (n % 2 == 0) {
            n /= 2;
        } else {
            n = (3 * n + 1) / 2; // ترکیب دو مرحله در یک مرحله
        }
        steps++;
    }
    return steps;
}

int main() {
    std::ofstream output_file("collatz_output.txt");
    long long limit = 1000000; // تا یک میلیارد
    int s = 0 ;
    for (long long i = 1; i <= limit; i++) {
    	s = 0 ;
    	for(int j=0 ; j < 1000 ; j++){
        int steps = collatz_steps(i+j);
        s += steps ;
    }
        output_file << i+500 << " " << s / 1000 << std::endl;
        if(i%10000 == 0) std::cout << i / 10000 << std::endl;
    }
    output_file.close();
    return 0;
}
