#include <iostream>
#include <tuple>

template <class T>
void test(T t)
{
    int a[std::tuple_size<T>::value];
 
    std::cout << std::tuple_size<T>::value << '\n';
}

template <typename T>
void print(std::ostream& os, T const& data) {
    os << '(';
    os << std::get<0>(data);
    os << ')';
}

template <typename T>
void print(std::ostream& os, T const& data, int N) {
    N = std::tuple_size<T>::value;
    os << '(';
    os << N;
    os << std::get< std::tuple_size<T>::value >(data);
    os << ')';
}

template <typename T, int N>
void print(std::ostream& os, T const& data, std::integer_sequence<int, N>) {
    std::cout << "4" << std::endl;
    ::print(os, std::get<N>(data));
}
 
int main()
{
    //test(std::make_tuple(1, 2, 3.14));
    //print(std::cout, std::make_tuple(1, 2, 3.14));
    print(std::cout, std::make_tuple(1, 2, 3.14), 0);
}