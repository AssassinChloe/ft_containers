#include "pair.hpp"
#include <iostream>
#include <string>

int main ()
{
    // OPERATORS
    ft::pair<int,char> foo (10,'z');
    ft::pair<int,char> bar (90,'a');
    if (foo==bar) std::cout << "foo and bar are equal " << std::endl;
    if (foo!=bar) std::cout << "foo and bar are not equal " << std::endl;
    if (foo< bar) std::cout << "foo is less than bar " << std::endl;
    if (foo> bar) std::cout << "foo is greater than bar " << std::endl;
    if (foo<=bar) std::cout << "foo is less than or equal to bar " << std::endl;
    if (foo>=bar) std::cout << "foo is greater than or equal to bar " << std::endl;
    
    //COPY
    ft::pair <std::string,int> planet, homeplanet;
    planet = ft::make_pair("Earth",6371);
    homeplanet = planet;
    std::cout << "Home planet: " << homeplanet.first << '\n';
    std::cout << "Planet size: " << homeplanet.second << '\n';
    
    //CONSTRUCTOR
    ft::pair <std::string,double> product1;                     // default constructor
    ft::pair <std::string,double> product2 ("tomatoes",2.30);   // value init
    ft::pair <std::string,double> product3 (product2);          // copy constructor
    product1 = ft::make_pair(std::string("lightbulbs"),0.99);   // using make_pair (move)
    product2.first = "shoes";                  // the type of first is string
    product2.second = 39.90;                   // the type of second is double
    std::cout << "The price of " << product1.first << " is $" << product1.second << '\n';
    std::cout << "The price of " << product2.first << " is $" << product2.second << '\n';
    std::cout << "The price of " << product3.first << " is $" << product3.second << '\n';
    

    ft::pair <int,int> foo2;
    ft::pair <int,int> bar2;

    foo2 = ft::make_pair (10,20);
    bar2 = ft::make_pair (10.5,'*'); // ok: implicit conversion from pair<double,char>

    std::cout << "foo: " << foo2.first << ", " << foo2.second << '\n';
    std::cout << "bar: " << bar2.first << ", " << bar2.second << '\n';
    return 0;
}