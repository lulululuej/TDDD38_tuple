#include <ostream>
#include <iterator>
#include <utility>
#include <iostream>
#include <vector>
#include <map>
#include <tuple>
#include <array>
#include <string>

/* This should give the following output (or something similar at least):
5
{1, 2, 3}
{(1 1), (2 2), (3 3)}
(5 3.14)
{hello, world}
{{ab, c}, {def, g, hi}}
SFINAE
string literal
 */

template <typename T>
void print(std::ostream& os, T const& data);

namespace details {

  /*template <typename T>
  void print(ostream& os, T const& data) {

  }*/

  template <typename T, int N>
  void print_tuple(std::ostream& os, T const& data, std::integer_sequence<int, N>) {
    std::cout << "4" << std::endl;
    ::print(os, std::get<N>(data));
  }

  // recursive print tuple
  template <typename T, int N, int ... Ns>
  void print_tuple(std::ostream& os, T const& data, std::integer_sequence<int, N, Ns...>) {
    std::cout << "3" << std::endl;
    ::print(os, std::get<N>(data));
    os << ' ';
    print_tuple(os, data, std::integer_sequence<int, Ns...>{});
  }

  /* print all tuple types */
  template <typename T>
  auto print(std::ostream& os, T const& data, int) 
    -> decltype(std::get<0>(data), std::tuple_size<T>::value, std::declval<void>()) // return void is first two are valid;
                                                                                    // converts any type of T to reference type;
  {
    std::cout << "2" << std::endl;
    os << '(';
    print_tuple(os, data, std::make_integer_sequence<int, std::tuple_size<T>::value>{}); // tuple_size detect how many elements in tuple and make_integer_sequence make the index for std::get<N>;
    os << ')';
  }

  template <typename T>
  void print(std::ostream& os, T const& data, double)
  {
    os << data;
  }
}

template <typename T>
void print(std::ostream& os, T const& data)
{
  details::print(os, data, 0);
  std::cout << "1" << std::endl;
}

int main()
{
  /*print(std::cout, 5);
  std::cout << std::endl;
  
  std::vector<int> v {1, 2, 3};
  print(std::cout, v);
  std::cout << std::endl;

  std::map<int, int> m { {1, 1}, {2, 2}, {3, 3} };
  print(std::cout, m);
  std::cout << std::endl;*/

  std::tuple<int, double> t { 5, 3.14 };
  print(std::cout, t);
  std::cout << std::endl;

  /*std::string s[] { "hello", "world" };
  print(std::cout, s);
  std::cout << std::endl;
  
  std::array<std::vector<std::string>, 2> a {
    std::vector<std::string>{ "ab", "c" },
    std::vector<std::string>{"def", "g", "hi"}
  };
  
  print(std::cout, a);
  std::cout << std::endl;

  char const* str {"SFINAE"};
  print(std::cout, str);
  std::cout << std::endl;

  print(std::cout, "string literal");
  std::cout << std::endl;*/
  
}
