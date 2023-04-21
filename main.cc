#include <iostream>
#include <iterator>
#include <algorithm>
#include <set>
#include <map>
#include <queue>

template <typename T>
struct less
{
    public:
        less(){};
        ~less(){};
        /*bool operator(T const& lhs, T const& rhs) {
            return lhs < rhs;
        }*/
};

template <typename Container, typename Compare>
bool is_sorted(Container const& c, Compare const& comp) {
    auto it{c.begin()};
    auto prev{it++};
    for(; it != c.end(); ++it){
        if(!comp(*prev, *it))
            return false;
        prev = it;
    }
    return true;
}

int main() {
    std::vector<int> v{1,2,3};
    auto it{v.begin()};
    std::cout << *++it << std::endl;
    std::cout << *it << std::endl;

    /* Lambda Expression */
    std::vector<int> vector{10, -1, 12};
    is_sorted(v, [](int a, int b) -> bool {
        return abs(a-10) < abs(b-10);
    });

    auto f = [n=0]() mutable {return ++n;};
    auto g = f;
    std::cout << f() << std::endl;
    std::cout << f() << std::endl;
    std::cout << g() << std::endl;
    /*


    less<int> obj();
    std::cout << obj() << std::endl;*/
    /*
    std::vector<int> v1{1, 2, 3};
    std::multiset<int> v2{1, 2, 3};
    // vector
    std::fill_n(std::inserter(v1, std::next(v1.begin())), 3, 6);
    // multiset (auto sorted)
    std::fill_n(std::inserter(v2, std::next(v2.begin())), 3, 6);
 
    for (int n : v1)
        std::cout << n << ' ';
    std::cout << '\n';

    for (int n : v2)
        std::cout << n << ' ';
    std::cout << '\n';

    std::vector<int> v{};
    auto it{std::inserter(v, v.end())};
    
    for(int i{0}; i < 10; ++i) {
        v.insert(v.end(), i);
    }
    for (auto i: v) {
        std::cout << i << ' ';
    }
    std::cout << '\n';*/
    /*
    std::vector<int> vector{1, 3};
    *std::back_inserter(vector)++ = 7;
    for(auto i: vector) {
        std::cout << i << ' ';
    }
    std::cout << '\n';
    int value{ ++(*vector.begin()) };
    std::cout << value << '\n';
    for(auto i: vector) {
        std::cout << i << ' ';
    }
    std::cout << '\n';
    std::inserter(vector, vector.begin()+1 ) = value;
    for(auto i: vector) {
        std::cout << i << ' ';
    }
    std::cout << '\n';
    */
   /*std::map<std::string, int> words{};
   std::string str;
   while (std::cin >> str)
   {
    words[str]++;
   }
   for(std::pair<std::string, int> const& p: words) {
    std::cout << p.first << ' ' << p.second << std::endl;
   }
   std::cout << '\n';*/
   /*std::priority_queue<float, std::vector<float>, std::less<float>> q{};
   float val;
   while (std::cin >> val)
   {
    q.push(val);
   }

   float sum{0.0};
   while (!q.empty())
   {
    sum += q.top();
    std::cout << "q.top = " << q.top() << std::endl;
    std::cout << "sum = " << sum << std::endl;
    q.pop();
   }
   std::cout << sum << std::endl;*/

   
}