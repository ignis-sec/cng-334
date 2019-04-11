#include "user.hpp"


user::user(std::string name):_userid(++maxid){
    _name = name;
}