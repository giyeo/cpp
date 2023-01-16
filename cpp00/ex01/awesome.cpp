#include <iostream>
class PhoneBook
{   
    public:
    std::string name;
    void printName()
    {
        std::cout << name << std::endl;
    }
};

int main()
{
    PhoneBook book;
    book.name = "rafa";
    book.printName();
    return(0);
}