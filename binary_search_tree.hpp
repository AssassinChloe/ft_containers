/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   binary_search_tree.hpp                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cassassi <cassassi@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/05/09 14:18:58 by cassassi          #+#    #+#             */
/*   Updated: 2022/05/09 15:46:49 by cassassi         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef BINARY_SEARCH_TREE_HPP
#define BINARY_SEARCH_TREE_HPP
namespace ft
{
    template <class T> 
    class Node
    {
        private:
        T       _key;
        Node    *_left;
        Node    *_right;
        int     _height;

        Node() {}

        public :
        Node(T key) : _key(key), _left(NULL), _right(NULL), _height(1)
        {}
        
        Node *newNode(T key)
        {
            Node *node = new Node(key);
            return (node);
        }

        Node* search(struct node* root, T key)
        {
            if (root == NULL || root->key == key)
            return (root);
            if (root->key < key)
                return (search(root->right, key));
            return (search(root->left, key));
        }

        Node *insert(Node *node, T data)
        {
            int balanceFactor;
            if (node == NULL)
                return (newNode(data));
            if (data < node->data)
                node->left  = insert(node->left, data);
            else if (data > node->data)
                node->right = insert(node->right, data);
            else
                return (node);
            node->setHeight(1 + max(getHeight(node->left), getHeight(node->right));
            balanceFactor = getBalanceFactor(node));
            if (balanceFactor > 1)
            {
                if (key < node->left->key) {
                return rightRotate(node);
                } else if (key > node->left->key) {
                node->left = leftRotate(node->left);
                return rightRotate(node);
                }
            }
            if (balanceFactor < -1) 
            {
                if (key > node->right->key) {
                return leftRotate(node);
                } else if (key < node->right->key) {
                node->right = rightRotate(node->right);
                return leftRotate(node);
                }
            }
            return node;
        }

        Node *minValueNode(Node *node) 
        {
            Node*current = node;

            while (current && current->left != NULL)
                current = current->left;
            return current;
        }

        Node *deleteNode(Node *root, T key) 
        {
            if (root == NULL)
                return (root);
            if (key < root->key)
                root->left = deleteNode(root->left, key);
            else if (key > root->key)
                root->right = deleteNode(root->right, key);
            else 
            {
                    if (root->left == NULL) {
                    struct node *temp = root->right;
                    delete(root);
                    return temp;
                }
                else if (root->right == NULL) 
                {
                    struct node *temp = root->left;
                    delete(root);
                    return temp;
                }
                struct node *temp = minValueNode(root->right);
                root->key = temp->key;
                root->right = deleteNode(root->right, temp->key);
            }
            return root;
        }

        int getBalanceFactor(Node *N) 
        {
            if (N == NULL)
                return 0;
            return (height(N->left) -height(N->right));
        }
        int getHeight() const 
        {
            return (this->_height);
        }
        
        Node *getLeft() const
        {
            return (this->_left);
        }

        Node *getRight() const
        {
            return (this->_right);
        }

        T getKey() const
        {
            return (this->_key);
        }        
        
        void setHeight(int newheight)
        {
            this->_height = newheight;
        }

        int max(int a, int b)
        {
            if (a > b)
                return (a);
            return (b);
        }
        

    /*
    Balance Factor = (Height of Left Subtree - Height of Right Subtree)
                   = (Height of Right Subtree - Height of Left Subtree)
// Get the balance factor of each node
int getBalanceFactor(Node *N) {
  if (N == NULL)
    return 0;
  return height(N->left) -
       height(N->right);
}

    // Rotate left
Node *leftRotate(Node *x) {
  Node *y = x->right;
  Node *T2 = y->left;
  y->left = x;
  x->right = T2;
  x->height = max(height(x->left),
          height(x->right)) +
        1;
  y->height = max(height(y->left),
          height(y->right)) +
        1;
  return y;
}

    }

// Rotate right
Node *rightRotate(Node *y) {
  Node *x = y->left;
  Node *T2 = x->right;
  x->right = y;
  y->left = T2;
  y->height = max(height(y->left),
          height(y->right)) +
        1;
  x->height = max(height(x->left),
          height(x->right)) +
        1;
  return x;
}

    Left-Right Rotate

    Right-Left Rotate

*/
        
    };

}
#endif