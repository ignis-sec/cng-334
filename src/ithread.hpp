#include <thread>


//independent thread
class ithread:public std::thread{
public:
    template<typename _Callable, typename... _Args>
      explicit
    ithread(_Callable&& __f, _Args&&... __args):std::thread(__f, __args...){
        this->detach();
    }
    
private:
};