/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   binary_search_tree.hpp                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cassassi <cassassi@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/05/09 14:18:58 by cassassi          #+#    #+#             */
/*   Updated: 2022/06/02 16:26:37 by cassassi         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef BINARY_SEARCH_TREE_HPP
#define BINARY_SEARCH_TREE_HPP
# include "pair.hpp"
# include "compare.hpp"
# include <iostream>

namespace ft
{   
    template <class Key, class T> 
    class Node
    {
        private :

        Node()
        {}

        Node& operator=(Node const & x)
        {
            Node *tmp = newNode(x->_key);
            tmp->_left = x->_left;
            tmp->_right = x->_right;
            tmp->_end = x->_end;
            tmp->_height = x->_height;
            tmp->_modify = x->_modify;
            alloc.deallocate(this, 1);
            this = tmp;
            return (*this);
        }
        
        public :

        typedef ft::pair<const Key, T>  value_type;
        typedef std::allocator<Node>    alloc_type;
        typedef ft::less<Key>           Compare;
            
        Node(value_type key)
        : alloc(alloc_type()), _comp(Compare()), _key(key), _left(NULL), _right(NULL),
        _height(1), _parent(NULL), _modify(false), _end(false)
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
        
        void setAllParents(Node *node)
        {
            if (node->_right)
            {
                if (node->_right->_parent != node)
                    node->_right->_parent = node;
                node->setAllParents(node->_right);
            }
            if (node->_left)
            {
                if (node->_left->_parent != node)
                    node->_left->_parent = node;
                node->setAllParents(node->_left);
            }
        }

        void setEnd(Node *node)
        {
            node = node->maxValueNode(node);
            if (!node->_right)
            {
                node->_right = newNode(value_type());
                node->_right->_end = true;
            }
            
        }

        Node* search(Node *node, Key key)
        {
            if (node && node->_end == false)
            {
                if (node->_key.first == key)
                    return (node);
                if (this->_comp(node->_key.first, key))
                    return (search(node->_right, key));
                return (search(node->_left, key));
            }
            return NULL;
        }

        Node *insert(Node *node, value_type key, bool *is_insert, Node **tmp)
        {
            if (node == NULL || node->_end == true)
            {
                if (node)
                    alloc.deallocate(node, 1);
                node = newNode(key);
                *tmp = node;
                return (node);
            }
            if (this->_comp(key.first, node->_key.first))
                node->_left = insert(node->_left, key, is_insert, tmp);
            else if (this->_comp(node->_key.first, key.first))
                node->_right = insert(node->_right, key, is_insert, tmp);
            else
            {
                *is_insert = false;
                *tmp = node;
                return (node);
            }
            node = balanceTree(node);
            return node;
        }

        Node *minValueNode(Node *node) 
        {
            Node *current = node;

            while (current && (current->_left && current->_left->_end == false))
                current = current->_left;
            return current;
        }

        Node *maxValueNode(Node *node) 
        {
            Node *current = node;
            while (current && (current->_right && current->_right->_end == false))
                current = current->_right;
            return current;
        }

        Node *deleteNode(Node *node, value_type key) 
        {
            Node *temp;
            if (node == NULL || node->_end == true)
                return (NULL);
            if (this->_comp(key.first, node->_key.first))
                node->_left = deleteNode(node->_left, key);
            else if (this->_comp(node->_key.first, key.first))
                node->_right = deleteNode(node->_right, key);
            else
            {
                
                if (!node->_left || !node->_right || node->_right->_end == true)
                {
                    if (node->_left)
                    {
                        temp = node->_left;
                        if (node->_right && node->_right->_end == true)
                        alloc.deallocate(node->_right, 1);   
                    }
                    else
                        temp = node->_right;
                    if (temp == NULL)
                    {
                        temp = node;
                        node = NULL;
                    }
                    else if (temp->_end == true)
                    {
                        alloc.deallocate(temp, 1);
                        alloc.deallocate(node, 1);
                        return (NULL);
                    }
                    else
                    {
                        Node *tmp = newNode(temp->_key);
                        tmp->_left = temp->_left;
                        tmp->_right = temp->_right;
                        tmp->_end = temp->_end;
                        tmp->_height = temp->_height;
                        tmp->_modify = temp->_modify;
                        alloc.deallocate(node, 1);
                        node = tmp;
                    }
                    alloc.deallocate(temp, 1);
                }
                else
                {
                    temp = minValueNode(node->_right);
                    Node *tmp = newNode(temp->_key);
                    tmp->_left = node->_left;
                    tmp->_right = node->_right;
                    tmp->_end = node->_end;
                    tmp->_height = node->_height;
                    tmp->_modify = node->_modify;
                    alloc.deallocate(node, 1);
                    node = tmp;
                    node->_right = deleteNode(node->_right, node->_key);

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
            y->_height = (1 + max(y->height(y->_left), y->height(y->_right)));
            x->_height = (1 + max(x->height(x->_left), x->height(x->_right)));
            return x;
        }

        Node *leftRotate(Node *x)
        {
            Node *y = x->_right;
            Node *T2 = y->_left;
            y->_left = x;
            x->_right = T2;
            y->_height = (1 + max(y->height(y->_left), y->height(y->_right)));
            x->_height = (1 + max(x->height(x->_left), x->height(x->_right)));
            return y;
        }

        int getBalanceFactor(Node *N) 
        {
            if (N == NULL || N->_end == true)
                return 0;
            return (N->height(N->_left) - N->height(N->_right));
        }

        int height(Node *N)
        {
            if (!N || N->_end == true)
                return 0;
            return N->_height;
        }
            
        Node *balanceTree(Node *node)
        {
            if (node == NULL || node->_end == true)
                return node;
            node->_height = (1 + max(node->height(node->_left), node->height(node->_right)));
            int balanceFactor = getBalanceFactor(node);
            if (balanceFactor > 1)
            {
                if (getBalanceFactor(node->_left) >=  0) 
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
    
        Node *increase(Node *node) 
        {
            if (node->_right)
            {
                node = node->_right;
                while (node->_left && node->_left->_end != true)
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
        
        Node *decrease(Node *node) 
        {
            if (node->_left && node->_left->_end != true) 
            {
                node = node->_left;
                while (node->_right && node->_right->_end != true)
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
        
        alloc_type  alloc;
        Compare     _comp;
        value_type  _key;
        Node        *_left;
        Node        *_right;
        int         _height;
        Node        *_parent;
        bool        _modify;
        bool        _end;
    };

}
#endif