/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   binary_search_tree.hpp                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cassassi <cassassi@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/05/09 14:18:58 by cassassi          #+#    #+#             */
/*   Updated: 2022/05/09 17:27:22 by cassassi         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef BINARY_SEARCH_TREE_HPP
#define BINARY_SEARCH_TREE_HPP

#include <iostream>
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


        public :
        Node() : _key(NULL), _left(NULL), _right(NULL), _height(0)
        {}
        
        Node(T key) : _key(key), _left(NULL), _right(NULL), _height(1)
        {}
        
        Node *newNode(T key)
        {
            Node *node = new Node(key);
            return (node);
        }

        Node* search(Node* root, T key)
        {
            if (root == NULL || root->getKey() == key)
                return (root);
            if (root->getKey() < key)
                return (search(root->getRight(), key));
            return (search(root->getLeft(), key));
        }

        Node *insert(Node *node, T key)
        {
            std::cout << "plop insert" <<std::endl;
            int balanceFactor;
            if (node == NULL)
                return (newNode(key));
            if (key < node->getKey())
                node->setLeft(insert(node->getLeft(), key));
            else if (key > node->getKey())
                node->setRight(insert(node->getRight(), key));
            else
                return (node);
            node->setHeight(1 + max(node->getLeft()->getHeight(), node->getRight()->getHeight()));
            balanceFactor = getBalanceFactor(node);
            if (balanceFactor > 1)
            {
                if (key < node->getLeft()->getKey())
                {
                    return rightRotate(node);
                } 
                else if (key > node->getLeft()->getKey()) 
                {
                    node->setLeft(leftRotate(node->getLeft()));
                    return rightRotate(node);
                }
            }
            if (balanceFactor < -1) 
            {
                if (key > node->getRight()->getKey()) 
                {
                    return leftRotate(node);
                } 
                else if (key < node->getRight()->getKey()) 
                {
                    node->setRight(rightRotate(node->getRight()));
                    return leftRotate(node);
                }
            }
            return node;
        }

        Node *minValueNode(Node *node) 
        {
            Node *current = node;

            while (current && current->getLeft() != NULL)
                current = current->getLeft();
            return current;
        }

        Node *deleteNode(Node *root, T key) 
        {
            int balanceFactor;

            if (root == NULL)
                return (root);
            if (key < root->getKey())
                root->setLeft(deleteNode(root->getLeft(), key));
            else if (key > root->getKey())
                root->setRight(deleteNode(root->getRight(), key));
            else 
            {
                if (root->getLeft() == NULL) 
                {
                    Node *temp = root->getRight();
                    delete(root);
                    return (temp);
                }
                else if (root->getRight() == NULL) 
                {
                    Node *temp = root->getLeft();
                    delete(root);
                    return (temp);
                }
                Node *temp = minValueNode(root->getRight());
                root->setKey(temp->getKey());
                root->setRight(deleteNode(root->getRight(), temp->getKey()));
            }
            if (root == NULL)
                return root;
            root->setHeight(1 + max(root->getLeft()->getHeight(), root->getRight()->getHeight()));
            balanceFactor = getBalanceFactor(root);
            if (balanceFactor > 1)
            {
                if (key < root->getLeft()->getKey())
                {
                    return rightRotate(root);
                } 
                else if (key > root->getLeft()->getKey()) 
                {
                    root->setLeft(leftRotate(root->getLeft()));
                    return rightRotate(root);
                }
            }
            if (balanceFactor < -1) 
            {
                if (key > root->getRight()->getKey()) 
                {
                    return leftRotate(root);
                } 
                else if (key < root->getRight()->getKey()) 
                {
                    root->setRight(rightRotate(root->getRight()));
                    return leftRotate(root);
                }
            }
            return (root);
        }

        Node *rightRotate(Node *y) 
        {
            Node *x = y->getLeft();
            Node *T2 = x->getRight();
            x->setRight(y);
            y->setLeft(T2);
            y->setHeight(max(y->getLeft()->getHeight(), y->getRight()->getHeight()) + 1);
            x->setHeight(max(x->getLeft()->getHeight(), x->getRight()->getHeight()) + 1);
            return x;
        }

        // Rotate left
        Node *leftRotate(Node *x)
        {
        Node *y = x->getRight();
        Node *T2 = y->getLeft();
        y->setLeft(x);
        x->setRight(T2);
        x->setHeight(max(x->getLeft()->getHeight(), x->getRight()->getHeight()) + 1);
        y->setHeight(max(y->getLeft()->getHeight(), y->getRight()->getHeight()) + 1);
        return y;
        }

        int getBalanceFactor(Node *N) 
        {
            if (N == NULL)
                return 0;
            return (N->getLeft()->getHeight() - N->getRight()->getHeight());
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
        
        void setLeft(Node *newleft)
        {
            delete (this->_left);
            this->_left = newleft;
        }

        void setRight(Node *newright)
        {
            delete (this->_right);
            this->_right = newright;
        }

        void setKey(T newkey)
        {
            this->_key = newkey;
        }
        
        int max(int a, int b)
        {
            if (a > b)
                return (a);
            return (b);
        }

        // Print the tree
        void printTree(Node *root, std::string indent, bool last)
        {
            if (root != nullptr) 
            {
                std::cout << indent;
                if (last) 
                {
                    std::cout << "R----";
                    indent += "   ";
                }
                else
                {
                    std::cout << "L----";
                    indent += "|  ";
                }
                std::cout << root->getKey() << std::endl;
                printTree(root->getLeft(), indent, false);
                printTree(root->getRight(), indent, true);
            }
        }        
    };

}
#endif