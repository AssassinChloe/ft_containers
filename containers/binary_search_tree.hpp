/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   binary_search_tree.hpp                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cassassi <cassassi@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/05/09 14:18:58 by cassassi          #+#    #+#             */
/*   Updated: 2022/05/24 12:30:29 by cassassi         ###   ########.fr       */
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
        public :

        typedef ft::pair<const Key, T>  value_type;
        typedef std::allocator<Node>    alloc_type;
              
        Node(value_type key)
        : alloc(alloc_type()), _key(key), _left(NULL), _right(NULL),
        _height(1), _parent(NULL)
        {}

       
        Node *newNode(value_type key)
        {
            Node *node = alloc.allocate(1);
            alloc.construct(node, key);
            return (node);
        }
        
        virtual ~Node()
        {}

        void clear()
        {
            if (this->_left)
            {
                this->_left->clear(); 
                this->_left = NULL;
            }
            if (this->_right)
            {
                this->_right->clear();
                this->_right = NULL;
            }
            this->alloc.deallocate(this, 1);
        }

        Node* search(Node *node, Key key)
        {
            if (node)
            {
                if (node->_key.first == key)
                    return (node);
                if (node->_key.first < key)
                    return (search(node->_right, key));
                return (search(node->_left, key));
            }
            return NULL;
        }

        Node *insert(Node *node, value_type key, bool *is_insert, Node **tmp)
        {
            if (!node)
            {
                node = newNode(key);
                *tmp = node;
                return (node);
            }
            if (key.first < node->_key.first)
                node->_left = insert(node->_left, key, is_insert, tmp);
            else if (key.first > node->_key.first)
                node->_right = insert(node->_right, key, is_insert, tmp);
            else
            {
                *is_insert = false;
                *tmp = node;
                return (node);
            }
            node = balanceTree(node);
            if (node->_right)
                node->_right->_parent = node;
            if (node->_left)
                node->_left->_parent = node;
            return node;
        }

        Node *minValueNode(Node *node) 
        {
            Node *current = node;

            while (current && current->_left != NULL)
                current = current->_left;
            return current;
        }

        Node *maxValueNode(Node *node) 
        {
            Node *current = node;
            while (current && current->_right)
                current = current->_right;
            return current;
        }

        Node *deleteNode(Node *node, value_type key) 
        {
            Node *temp;
            if (node == NULL)
                return (node);
            if (key.first < node->_key.first)
                node->_left = deleteNode(node->_left, key);
            else if (key.first > node->_key.first)
                node->_right = deleteNode(node->_right, key);
            else
            {
                if ((node->_left == NULL) || (node->_right == NULL))
                {
                    if (node->_left)
                        temp = node->_left;
                    else
                        temp = node->_right;
                    if (temp == NULL)
                    {
                        temp = node;
                        node = NULL;
                    }
                    else
                    {
                        *node = *temp;
                    }
                    alloc.deallocate(temp, 1);
                } 
                else
                {
                    temp = minValueNode(node->_right);
                    node->_key = temp->_key;
                    node->_right = deleteNode(node->_right, node->_key);
                }
            }
            node = balanceTree(node);
            if (node->_right)
                node->_right->_parent = node;
            if (node->_left)
                node->_left->_parent = node;
            return (node);
        }
        
        int max(int a, int b)
        {
            if (a > b)
                return (a);
            return (b);
        }

        Node *rightRotate(Node *y) 
        {
            Node *x = y->_left;
            Node *T2 = x->_right;
            x->_right = y;
            y->_left = T2;
            modifHeight(y);
            modifHeight(x);
            return x;
        }

        Node *leftRotate(Node *x)
        {
            Node *y = x->_right;
            Node *T2 = y->_left;
            y->_left = x;
            x->_right = T2;
            modifHeight(y);
            modifHeight(x);
            return y;
        }

        int getBalanceFactor(Node *N) 
        {
            if (N == NULL)
                return 0;
            return (N->height(N->_left) - N->height(N->_right));
        }

        int height(Node *N)
        {
            if (N == NULL)
                return 0;
            return N->_height;
        }
        void modifHeight(Node *node)
        {
            node->_height = (1 + max(node->height(node->_left), node->height(node->_right)));   
        }
            
        Node *balanceTree(Node *node)
        {
            if (node == NULL)
                return node;
            modifHeight(node);
            int balanceFactor = getBalanceFactor(node);
            if (balanceFactor > 1)
            {
                if (getBalanceFactor(node->_left) >= 0) 
                    return rightRotate(node);
                node->_left = leftRotate(node->_left);
                return rightRotate(node);
            }
            if (balanceFactor < -1) 
            {
                if (getBalanceFactor(node->_right) <= 0)
                    return leftRotate(node);
                node->_right = rightRotate(node->_right);
                return leftRotate(node);
            }
            return (node);
        }
    
        Node * increase(Node *node) 
        {
            if (node->_right)
            {
                node = node->_right;
                while (node->_left)
                    node = node->_left;
            }
            else 
            {
                Node *temp = node;
                node = node->_parent;
                while (node->_left != temp)
                {
                    temp = node;
                    node = node->_parent;
                }
            }
            return (node);
        }
        
        Node * decrease(Node * node) 
        {
            if (node->_left) 
            {
                node = node->_left;
                while (node->_right)
                    node = node->_right;
            }
            else 
            {
                Node *temp = node;
                node = node->_parent;
                while (node->_right != temp) 
                {
                    temp = node;
                    node = node->_parent;
                }
            }
            return (node);
        }
        
        alloc_type    alloc;
        value_type    _key;
        Node          *_left;
        Node          *_right;
        int           _height;
        Node          *_parent;
    };

}
#endif