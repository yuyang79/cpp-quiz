// Example program
#include <iostream>
#include <string>

using namespace std;

class Device
{
protected:
    Device( const char * path ):path_(path){}
    const std::string & path() { return path_; } 

private:
    std::string path_;
};

class InputDevice : virtual public Device
{
public:
    InputDevice( const char * path ):Device(path){}
    virtual ~InputDevice(){}
    virtual void rx( char * buf )=0;
};

class OutputDevice : virtual public Device
{
public:
    OutputDevice( const char * path ):Device(path){}
    virtual ~OutputDevice(){}
    virtual void tx( const char * buf )=0;
};

class UART : public InputDevice, public OutputDevice
{
public:
    UART( const char * path ):InputDevice(path), OutputDevice(path){}
    void rx( char * buf ){ cout<<"read"<<endl; }; 
    void tx( const char * buf ){ cout<<"write"<<endl; };    
};

class DemoDevice : public Device
{
public:
    DemoDevice( const char * path, const std::string & description ):Device(path), des_(description + path_ ){}
private:
    std::string des_;
};

int main()
{
    //check correntness of followling lines
    
    InputDevice * input = new UART( "dev/uart" ); 
    cout<< dynamic_cast<UART *>( input ) <<endl;
    cout<< dynamic_cast<OutputDevice *>( input )<<endl;

    Device * demo = new DemoDevice( "/dev/demo", "demo" );
    cout<< dynamic_cast<DemoDevice *>( demo ) <<endl;
    
    
}
