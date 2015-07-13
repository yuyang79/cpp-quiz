#include <string>
#include <iostream>
#include <memory>

template<typename T>
class Cleaner {
public:
    void operator()(T * p) const {
        std::cout << "Call delete for object..." <<std::endl;
        delete p;
    }
};

class Pool{
public:
    template<typename T> std::shared_ptr<T> get() {
        return std::shared_ptr<T>(new int(42), Cleaner<T>());
    };
};

template<typename P>
void test( P& p )
{
    int * p1 = p.get<int>();
};

int main()
{
    Pool p;
    test(p);
}
