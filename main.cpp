#include <iostream>
#include <string>

int main()
{
  int a{1};
  std::string mystring{"haha"};

  std::getline(std::cin, mystring);

  std::cout << "Hello World!" << a << mystring << std::endl;
}