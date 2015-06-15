#include <iostream>
#include <algorithm>
#include <vector>
#include <cstring>
#include <iterator>

template <typename T>
class PriorityQueue{
public:
  void push( const T & val ){
    queue_.push_back( val );
    std::push_heap( begin(queue_), end(queue_) );
  }
  T pop(){
    std::pop_heap( begin(queue_), end(queue_) );
    T tmp( queue_.back() );
    queue_.pop_back();
    return tmp;
  }
  bool empty(){
    return queue_.empty();
  }
private:
  std::vector<T> queue_;
};


bool strLess( char * a, char * b ){
  return strcmp( a, b ) < 0;                                          
}

template<>
class PriorityQueue<char *>{
public:
  void push( char * pval ){
    queue_.push_back( pval );
    std::push_heap( begin( queue_ ), end( queue_ ), strLess );
  }
  const char * pop() {
    std::pop_heap( begin( queue_ ), end( queue_ ), strLess );
    const char * pv = queue_.back();
    queue_.pop_back();
    return pv;
  }
private:
  std::vector<char *> queue_;
};

template<>
void PriorityQueue<const char*>::push( const char * pval ){                            
  queue_.push_back( pval );
  std::push_heap( begin( queue_ ), end( queue_ ) );
}

template<>
const char * PriorityQueue<const char*>::pop() {
  std::pop_heap( begin( queue_ ), end( queue_ ) );
  const char * pv = queue_.back();
  queue_.pop_back();
  return pv;
}


template<typename InputIter>
void sortedPrint( InputIter first, InputIter last ){
  typedef typename InputIter::value_type T;
  PriorityQueue<T> pq;
  while( first != last ){
    pq.push( *first++ );
  }
  while( !pq.empty() ){
    std::cout<< pq.pop() << " ";
  }
  std::cout<<std::endl;
}

int main()
{
  std::vector<int> v = { 2, 3, 1, 4, 5 };
  sortedPrint( begin(v), end(v) ); //produces 5, 4, 3, 2, 1,
  std::vector<char *> c = { "c", "b", "a" };
  sortedPrint( begin(c), end(c) );
  std::vector<const char *> cc = { "c", "b", "a" };
  sortedPrint( begin(cc), end(cc) );
}
