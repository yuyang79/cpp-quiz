// Example program
#include <iostream>
#include <vector>
#include <array>
#include <initializer_list>
#include <iterator>

using namespace std;

template<typename T>
class Container{
public:
    Container( initializer_list<T> data ):data_(data){}

    vector<T> get(){
        return data_;
    }
    
    template<typename N>
    vector<N> get(){
        vector<N> result_(data_.size());
        copy( begin(data_), end(data_), back_inserter(result_) );
        return result_;
    }
    
    void print(){
        copy( begin(data_), end(data_), ostream_iterator<T>(cout, " ") );
        cout<<endl;
    }
private:
    vector<T> data_;
};

int main()
{
    Container<char> c{ 'a', 'b' };
    c.print();
    auto r = c.get<int>();
    copy( begin(r), end(r), ostream_iterator<int>(cout, " "));
}
