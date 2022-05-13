#include "binary_search_tree.hpp"
#include <iostream>
#include <string>

int main ()
{
    ft::pair<int,char> bar1 (10,'c');
    ft::Node<int, char> *node = new ft::Node<int, char>(bar1);

    ft::pair<int,char> bar2 (90,'g');
    ft::pair<int,char> bar3 (45,'f');
    ft::pair<int,char> bar4 (9,'b');
    ft::pair<int,char> bar5 (19,'d');
    ft::pair<int,char> bar6 (5,'a');
    ft::pair<int,char> bar7 (20,'e');
    ft::pair<int,char> bar8 (21,'e');
    ft::pair<int,char> bar9 (22,'e');
    ft::pair<int,char> bar10(23,'e');
    ft::pair<int,char> bar11(24,'e');
    ft::pair<int,char> bar12(25,'e');
    
    node = node->insert(node, bar2);
    node = node->insert(node, bar3);
    node = node->insert(node, bar4);
    node = node->insert(node, bar5);
    node = node->insert(node, bar6);
    node = node->insert(node, bar7);
    node = node->insert(node, bar8);
    node = node->insert(node, bar9);
    node = node->insert(node, bar10);
    node = node->insert(node, bar11);
    node = node->insert(node, bar12);

    std::cout << std::endl;

    return 0;
}