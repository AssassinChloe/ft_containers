#include "binary_search_tree.hpp"
using namespace ft;
int main()
{
  Node<int> *root;

  root = (*root).insert(root, 33);

(*root).printTree(root, "", true);

  root = (*root).insert(root, 13);

(*root).printTree(root, "", true);

root = (*root).insert(root, 53);

(*root).printTree(root, "", true);
  root = (*root).insert(root, 9);
(*root).printTree(root, "", true);
  root = (*root).insert(root, 21);
(*root).printTree(root, "", true);
  root = (*root).insert(root, 61);
(*root).printTree(root, "", true);
  root = (*root).insert(root, 8);
(*root).printTree(root, "", true);
  root = (*root).insert(root, 11);

  (*root).printTree(root, "", true);
  root = (*root).deleteNode(root, 13);
  std::cout << "After deleting " << std::endl;
(*root).printTree(root, "", true);
}