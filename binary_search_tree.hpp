/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   binary_search_tree.hpp                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cassassi <cassassi@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/05/09 14:18:58 by cassassi          #+#    #+#             */
/*   Updated: 2022/05/12 16:57:59 by cassassi         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef BINARY_SEARCH_TREE_HPP
#define BINARY_SEARCH_TREE_HPP
#include "pair.hpp"

#include <iostream>
namespace ft
{
    template <class Key, class T> 
    class Node
    {
        private:
            ft::pair<Key, T>    _key;
            Node                *_left;
            Node                *_right;
            int                 _height;
            Node                *_parent;


        Node() :_left(NULL), _right(NULL), _height(0), _parent(NULL)
        {}
        
        public :
        
        Node(ft::pair<Key, T> key) : _key(key), _left(NULL), _right(NULL), _height(1), _parent(NULL)
        {}

        virtual ~Node()
        {
            clear();
        }

        void clear()
        {
            if (this->_left != NULL)
            {
                delete (this->_left);
                this->_left = NULL;
            }
            if (this->_right != NULL)
            {
                delete(this->_right);
                this->_right = NULL;
            }
        }
        
        void setParent(Node *node)
        {
            this->_parent = node;
        }
        
        void setAllParents(Node *node)
        {
            if (node->getRight())
            {
                node->getRight()->setParent(node);
                node->setAllParents(node->getRight());
            }
            if (node->getLeft())
            {
                node->getLeft()->setParent(node);
                node->setAllParents(node->getLeft());
            }
        }
        
        Node *newNode(ft::pair<Key, T> key)
        {
            Node *node = new Node(key);
            return (node);
        }

        Node* search(Node *node, ft::pair<Key, T> key)
        {
            if (node)
            {
                if (node->getKey().first == key.first)
                    return (node);
                if (node->getKey().first < key.first)
                    return (search(node->getRight(), key));
                return (search(node->getLeft(), key));
            }
            return NULL;
        }

        Node *insert(Node *node, ft::pair<Key, T> key)
        {
            if (node == NULL)
                return (newNode(key));
                
            if (key.first < node->getKey().first)
                node->setLeft(insert(node->getLeft(), key));
            else if (key.first > node->getKey().first)
                node->setRight(insert(node->getRight(), key));
            else
                return (node);
            node = balanceTreeInsert(node, key);
            setAllParents(node);
            return node;
        }

        Node *minValueNode(Node *node) 
        {
            Node *current = node;

            while (current && current->getLeft() != NULL)
                current = current->getLeft();
            return current;
        }

        Node *maxValueNode(Node *node) 
        {
            Node *current = node;

            while (current && current->getRight() != NULL)
                current = current->getRight();
            return current;
        }

        Node *deleteNode(Node *root, ft::pair<Key, T> key) 
        {
            Node *temp;
            if (root == NULL)
                return (root);
            if (key.first < root->getKey().first)
                root->setLeft(deleteNode(root->getLeft(), key));
            else if (key.first > root->getKey().first)
                root->setRight(deleteNode(root->getRight(), key));
            else
            {
                if ((root->getLeft() == NULL) || (root->getRight() == NULL))
                {
                    
                    if (root->getLeft())
                        temp = root->getLeft();
                    else
                        temp = root->getRight();
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
                    temp = minValueNode(root->getRight());
                    root->setKey(temp->getKey());
                    root->setRight(deleteNode(root->getRight(), temp->getKey()));
                }
            }
            root = balanceTreeDelete(root);
            setAllParents(root);
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

        ft::pair<Key, T> getKey() const
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

        void setKey(ft::pair<Key, T> newkey)
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
            if (N->getLeft() == NULL)
            {
                if (N->getRight() == NULL)
                    return (0);
                else
                    return (0 - N->getRight()->getHeight());
            }
            else
            {
                if (N->getRight() == NULL)
                    return (N->getLeft()->getHeight());
            }
            return (N->getLeft()->getHeight() - N->getRight()->getHeight());
        }

        void modifHeight(Node *node)
        {
            if (node->getLeft() == NULL || node->getRight() == NULL)
            {
                if (node->getLeft() == NULL && node->getRight() == NULL)
                    node->setHeight(0);
                else if (node->getLeft() == NULL)
                    node->setHeight(1 + max(0, node->getRight()->getHeight()));
                else if (node->getRight() == NULL)
                    node->setHeight(1 + max(node->getLeft()->getHeight(), 0));
            }
            else
                node->setHeight(1 + max(node->getLeft()->getHeight(), node->getRight()->getHeight()));   
        }
        
        Node *balanceTreeInsert(Node *node, ft::pair<Key, T> key)
        {
            modifHeight(node);
            int balanceFactor = getBalanceFactor(node);
            if (balanceFactor > 1)
            {
                if (key.first > node->getLeft()->getKey().first)
                    node->setLeft(leftRotate(node->getLeft()));
                return rightRotate(node);
            }
            if (balanceFactor < -1 && key.first > node->getRight()->getKey().first)
            {
                if (key < node->getRight()->getKey())
                    node->setRight(rightRotate(node->getRight()));
                return leftRotate(node);
            }
            return (node);
        }
        
        Node *balanceTreeDelete(Node *root)
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

        void inorder_traversal(Node* root)
        {
            if(root != NULL) 
            {
                inorder_traversal(root->getLeft());
                std::cout << root->getKey().first << std::endl;          
                inorder_traversal(root->getRight());
            }
        }

    };

}
#endif