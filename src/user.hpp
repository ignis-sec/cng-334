#include <string>

unsigned int maxid=0;

class user{
public:
    user(std::string name);

    const unsigned int _userid;

private:
   std::string _name;
};