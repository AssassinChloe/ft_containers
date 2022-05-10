#include "binary_search_tree.hpp"
using namespace ft;
int main()
{
  Node<int> *root = new Node<int>(33);

  root = root->insert(root, 13);
  root = root->insert(root, 53);
  root = root->insert(root, 9);
  root = root->insert(root, 21);
  root = root->insert(root, 61);
  root = root->insert(root, 8);
  root = root->insert(root, 11);
  std::cout << "search " << root->search(61)->getKey() << std::endl;
  root->printTree(root, "", true);

  root = root->deleteNode(root, 13);
  std::cout << "After deleting " << std::endl;
 (*root).printTree(root, "", true);
  delete (root);
}