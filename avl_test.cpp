#include "binary_search_tree.hpp"
using namespace ft;
int main()
{
  std::cout << std::endl;

  Node<int> *root = new Node<int>(45);
  Node<int> plop(42);
  root = root->insert(root, 9);
  root = root->insert(root, 11); 
  root = root->insert(root, 13);
  root = root->insert(root, 21);
  root = root->insert(root, 33);
  root = root->insert(root, 53);
  root = root->insert(root, 61);
  root = root->insert(root, 12);
  root = root->insert(root, 14);
  root = root->insert(root, 15);
  root = root->insert(root, 16);

  //doublon
  root = root->insert(root, 16);
  root = root->insert(root, 61);


  Node<int> *tmp = root->search(root, 8);
  if (tmp)
    std::cout << "search " << tmp->getKey() << std::endl;
  else
    std::cout << "search fails " << std::endl;
  
  tmp = root->search(root, 61);
  if (tmp)
    std::cout << "search " << tmp->getKey() << std::endl;
  else
    std::cout << "search fails " << std::endl;
  std::cout << std::endl;

  root->printTree(root , "", true );
  std::cout << std::endl;
  root = root->deleteNode(root, 16);
  root = root->deleteNode(root, 61);
  root = root->deleteNode(root, 8);
  std::cout << "After deleting 16" << std::endl;
  std::cout << std::endl;
  root->printTree(root , "", true );
  delete (root);
}