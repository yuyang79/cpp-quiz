// Example program
#include <iostream>

namespace Number
{
class Complex
{
public:

    Complex( float r, float i )
    :real_( r ), img_( i )
    {
    }
    
    Complex( const Complex & other )
    :real_( other.real_ ), img_( other.img_ )
    {
    }

    Complex( Complex && o )
    :real_( o.real_ ), img_( o.img_ )
    {
    }
    
    operator float()
    {
        return real_;
    }

    Complex& increment()
    {
        this->real_++;
        this->img_++;
        return *this;
    }

    friend class PrintA;
    friend class PrintB;
    friend Complex operator+( const Complex &, const Complex & );
    friend std::ostream & operator<<( std::ostream &, const Complex & );

        
private:
    float real_;
    float img_;
};

Complex operator+( const Complex & a, const Complex & b )
{
    float r = a.real_ + b.real_;
    float i = a.img_ + b.img_;
    return Complex( r, i );
}

std::ostream & operator<<( std::ostream & stream, const Complex & n )
{
    stream<<"("<<n.real_<<","<<n.img_<<")";
    return stream;
}

class PrintA
{
public:
    void print( float a ) { std::cout<< a <<" "; }
};

class PrintB : public PrintA
{
public:
    void print( const Complex & c ) { std::cout<< c; }
};

};

int main()
{
  Number::Complex a = Number::Complex( 1, 2 );
  Number::PrintB p = Number::PrintB();
  p.print( static_cast<float>( a ) );
  std::cout<<a.increment()<<" "<<a.increment()<<" ";
  p.print( a );
  flush( std::cout );
  
  //expecting:1 (2,3) (3,4) (3,4), do not worry about the spaces in between.
}
