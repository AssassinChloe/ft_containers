/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   binary_search_tree.hpp                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cassassi <cassassi@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/05/09 14:18:58 by cassassi          #+#    #+#             */
/*   Updated: 2022/05/10 17:30:23 by cassassi         ###   ########.fr       */
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
        Node() :_left(nullptr), _right(nullptr), _height(0)
        {}
        
        Node(T key) : _key(key), _left(nullptr), _right(nullptr), _height(1)
        {}

        virtual ~Node()
        {}
        
        Node *newNode(T key)
        {
            Node *node = new Node(key);
            return (node);
        }

        Node* search(T key)
        {
            if (this->_key == key)
                return (this);
            if (this->_key < key)
                return (this->_right->search(key));
            return (this->_left->search(key));
        }

        Node *insert(Node *node, T key)
        {
            int balanceFactor;
            if (node == nullptr)
                return (newNode(key));
            if (key < node->getKey())
                node->setLeft(insert(node->getLeft(), key));
            else
                node->setRight(insert(node->getRight(), key));
            balanceTreeInsert(node, key);
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
            if (root == NULL)
                return (root);
            if (key < root->getKey())
                root->setLeft(deleteNode(root->getLeft(), key));
            else if (key > root->getKey())
                root->setRight(deleteNode(root->getRight(), key));
            else
            {
                if ((root->getLeft() == NULL) || (root->getRight() == NULL))
                {
                    Node *temp = root->getLeft() ? root->getLeft() : root->getRight();
                    if (temp == NULL)
                    {
                        temp = root;
                        root = NULL;
                    }
                    else
                        *root = *temp;
                    delete (temp);
                } 
                else
                {
                    Node *temp = minValueNode(root->getRight());
                    root->setKey(temp->getKey());
                    root->setRight(deleteNode(root->getRight(), temp->getKey()));
                }
            }
            root = balanceTreeDelete(root, key);
            return (root);
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
            this->_left = newleft;
        }

        void setRight(Node *newright)
        {
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

        Node *rightRotate(Node *y) 
        {
            Node *x = y->getLeft();
            Node *T2 = x->getRight();
            x->setRight(y);
            y->setLeft(T2);
            modifHeight(y);
            modifHeight(x);
            return x;
        }

        Node *leftRotate(Node *x)
        {
            Node *y = x->getRight();
            Node *T2 = y->getLeft();
            y->setLeft(x);
            x->setRight(T2);
            modifHeight(y);
            modifHeight(x);
            return y;
        }

        int getBalanceFactor(Node *N) 
        {
            if (N == NULL)
                return 0;
            if (N->getLeft() == nullptr)
            {
                if (N->getRight() == nullptr)
                    return (0);
                else
                    return (0 - N->getRight()->getHeight());
            }
            else
            {
                if (N->getRight() == nullptr)
                    return (N->getLeft()->getHeight());
            }
            return (N->getLeft()->getHeight() - N->getRight()->getHeight());
        }

        void modifHeight(Node *node)
        {
            if (node->getLeft() == nullptr || node->getRight() == nullptr)
            {
                if (node->getLeft() == nullptr && node->getRight() == nullptr)
                    node->setHeight(0);
                else if (node->getLeft() == nullptr)
                    node->setHeight(1 + node->getRight()->getHeight());
                else if (node->getRight() == nullptr)
                    node->setHeight(1 + node->getLeft()->getHeight());
            }
            else
                node->setHeight(1 + max(node->getLeft()->getHeight(), node->getRight()->getHeight()));   
        }
        
        Node *balanceTreeInsert(Node *node, T key)
        {
            modifHeight(node);
            int balanceFactor = getBalanceFactor(node);
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
            return (node);
        }
        
        Node *balanceTreeDelete(Node *root, T key)
        {
            if (root == NULL)
                return root;
            modifHeight(root);
            int balanceFactor = getBalanceFactor(root);
            if (balanceFactor > 1)
            {
                if (getBalanceFactor(root->getLeft()) >= 0) 
                    return rightRotate(root);
                root->setLeft(leftRotate(root->getLeft()));
                return rightRotate(root);
            }
            if (balanceFactor < -1) 
            {
                if (getBalanceFactor(root->getRight()) <= 0)
                    return leftRotate(root);
                root->setRight(rightRotate(root->getRight()));
                return leftRotate(root);
            }
            return (root);
        }

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
                std::cout << "key : " << root->getKey() << " " << std::endl;
                printTree(root->getLeft(), indent, false);
                printTree(root->getRight(), indent, true);
            }
        }        
    };

}
#endif