#include "binary_search_tree.hpp"
#include <iostream>
#include <string>

int main ()
{
    ft::pair<int,char> bar1 (10,'c');
    ft::Node<int, char> *root = new ft::Node<int, char>(bar1);

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
    
    root = root->insert(root, bar2);
    root = root->insert(root, bar3);
    root = root->insert(root, bar4);
    root = root->insert(root, bar5);
    root = root->insert(root, bar6);
    root = root->insert(root, bar7);
    root = root->insert(root, bar8);
    root = root->insert(root, bar9);
    root = root->insert(root, bar10);
    root = root->insert(root, bar11);
    root = root->insert(root, bar12);

    root->inorder_traversal(root);
    std::cout << std::endl;

    return 0;
}