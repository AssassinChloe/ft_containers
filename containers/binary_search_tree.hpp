/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   binary_search_tree.hpp                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cassassi <cassassi@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/05/09 14:18:58 by cassassi          #+#    #+#             */
/*   Updated: 2022/05/20 15:20:29 by cassassi         ###   ########.fr       */
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
        typedef std::allocator<value_type> alloc_val;

        
        Node()
        : alloc(alloc_type()), _key(NULL), _left(NULL), _right(NULL), _height(1), _parent(NULL), _first(true)
        {}
        
        Node(value_type key)
        : alloc(alloc_type()), _key(constructKey(key)), _left(NULL), _right(NULL), _height(1), _parent(NULL), _first(false)
        {}

        value_type *constructKey(value_type key)
        {
            this->_key = _all_pair.allocate(1);
            _all_pair.construct(this->_key, key);
            return (this->_key);
        }

        void destroyKey()
        {
            if (this->_key)
            {
                _all_pair.destroy(this->_key);
                _all_pair.deallocate(this->_key, 1);
                this->_key = NULL;
            }
        }
        
        Node *newNode(value_type key)
        {
            Node *node = alloc.allocate(1);
            alloc.construct(node, key);
            node->_first = false;
            return (node);
        }
        
        virtual ~Node()
        {}

        void clear()
        {
            if (this->_key)
                this->destroyKey();
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
        
        void setParent(Node *node)
        {
            this->_parent = node;
        }
        
        void setAllParents(Node *node)
        {
            if (node->_right)
            {
                node->_right->_parent = node;
                node->setAllParents(node->_right);
            }
            if (node->_left)
            {
                node->_left->_parent = node;
                node->setAllParents(node->_left);
            }
        }
        

        Node* search(Node *node, Key key)
        {
            if (node)
            {
                if (node->_key->first == key)
                    return (node);
                if (node->_key->first < key)
                    return (search(node->_right, key));
                return (search(node->_left, key));
            }
            return NULL;
        }

        Node *insert(Node *node, value_type key, bool *is_insert)
        {
            if (node == NULL || this->_first == true)
            {
                return (newNode(key));
            }
            if (key.first < node->_key->first)
                node->_left = insert(node->_left, key, is_insert);
            else if (key.first > node->_key->first)
                node->_right = insert(node->_right, key, is_insert);
            else
            {
                *is_insert = false;
                return (node);
            }
            node = balanceTree(node);
            setAllParents(node);
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

            while (current && current->_right != NULL)
                current = current->_right;
            return current;
        }

        Node *deleteNode(Node *node, value_type key) 
        {
            Node *temp;
            if (node == NULL)
                return (node);
            if (key.first < node->_key->first)
                node->_left = deleteNode(node->_left, key);
            else if (key.first > node->_key->first)
                node->_right = deleteNode(node->_right, key);
            else
            {
                if ((node->_left == NULL) || (node->_right == NULL))
                {
                    if (node->_left)
                        temp = node->_left;
                    else
                        temp = node->_right;
                    node->destroyKey();
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
                    node->destroyKey();
                    node->_key = node->constructKey(*(temp->_key));
                    node->_right = deleteNode(node->_right, *(node->_key));
                }
            }
            node = balanceTree(node);
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
        alloc_val     _all_pair;
        value_type    *_key;
        Node          *_left;
        Node          *_right;
        int           _height;
        Node          *_parent;
        bool          _first;        

    };

}
#endif