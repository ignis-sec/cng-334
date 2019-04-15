class User;

//Bank account class that is being accessed from the user
class BankAccount{
public:
    BankAccount(int balance, User* owner);
    float changeBalance(float difference);

private:
    unsigned int __id;//unique id
    float accountBalance;
    User* _owner;
};

