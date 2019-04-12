#include "semaphore.hpp"
#include <unistd.h>


void __timeout__(unsigned int __timeoutms,void (*callback)()){
    usleep(__timeoutms);
    callback();
}

class Semaphore_c : semaphore{
public:
    Semaphore_c(unsigned int __timeoutms, void (*callback));

private:
    unsigned int _timeoutms;
};