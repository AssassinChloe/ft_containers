// #include "binary_search_tree.hpp"
// using namespace ft;
// int main()
// {
//   std::cout << std::endl;

//   Node<int> *node = new Node<int>(45);
//   Node<int> plop(42);
//   node = node->insert(node, 9);
//   node = node->insert(node, 11); 
//   node = node->insert(node, 13);
//   node = node->insert(node, 21);
//   node = node->insert(node, 33);
//   node = node->insert(node, 53);
//   node = node->insert(node, 61);
//   node = node->insert(node, 12);
//   node = node->insert(node, 14);
//   node = node->insert(node, 15);
//   node = node->insert(node, 16);

//   //doublon
//   node = node->insert(node, 16);
//   node = node->insert(node, 61);


//   Node<int> *tmp = node->search(node, 8);
//   if (tmp)
//     std::cout << "search " << tmp->getKey() << std::endl;
//   else
//     std::cout << "search fails " << std::endl;
  
//   tmp = node->search(node, 61);
//   if (tmp)
//     std::cout << "search " << tmp->getKey() << std::endl;
//   else
//     std::cout << "search fails " << std::endl;
//   std::cout << std::endl;

//   node->printTree(node , "", true );
//   std::cout << std::endl;
//   node = node->deleteNode(node, 16);
//   node = node->deleteNode(node, 61);
//   node = node->deleteNode(node, 8);
//   std::cout << "After deleting 16" << std::endl;
//   std::cout << std::endl;
//   node->printTree(node , "", true );
//   delete (node);
// }