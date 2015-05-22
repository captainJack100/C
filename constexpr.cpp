#include <iostream>
#include <string>

using namespace std;

constexpr bool is_prime_rec(size_t number, size_t c)
{
    return (c*c > number) ? true: 
        (number % c == 0) ? false:
            is_prime_rec(number, c+1);
}

constexpr bool is_prime_func(size_t number)
{
    return (number <=1) ? false:
        is_prime_rec(number,2);
}

int main(void)
{

    cout << is_prime_func(86028121) << endl;

    return 0;
}
