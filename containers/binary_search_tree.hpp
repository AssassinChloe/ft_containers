/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   binary_search_tree.hpp                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cassassi <cassassi@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/05/09 14:18:58 by cassassi          #+#    #+#             */
/*   Updated: 2022/05/18 15:53:41 by cassassi         ###   ########.fr       */
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
            alloc_val tmp;
            this->_key = tmp.allocate(1);
            tmp.construct(this->_key, key);
            return (this->_key);
        }

        void destroyKey()
        {
            alloc_val tmp;
            if (this->_key)
            {
                tmp.destroy(this->_key);
                tmp.deallocate(this->_key, 1);
                this->_key = NULL;
            }
        }
        
        Node *newNode(value_type key)
        {
            Node *node = alloc.allocate(1);
            alloc.construct(node, key);
            node->setStatus(false);
            return (node);
        }
        
        virtual ~Node()
        {
            
        }

        void clear()
        {
            if (this->_key)
                this->destroyKey();
            if (this->_left)
            {
                this->getLeft()->clear(); 
                this->_left = NULL;
            }
            if (this->_right)
            {
                this->getRight()->clear();
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
        

        Node* search(Node *node, Key key)
        {
            if (node)
            {
                if (node->getKey().first == key)
                    return (node);
                if (node->getKey().first < key)
                    return (search(node->getRight(), key));
                return (search(node->getLeft(), key));
            }
            return NULL;
        }

        Node *insert(Node *node, value_type key, bool *is_insert)
        {
            if (node == NULL || this->_first == true)
            {
                return (newNode(key));
            }
            if (key.first < node->getKey().first)
                node->setLeft(insert(node->getLeft(), key, is_insert));
            else if (key.first > node->getKey().first)
                node->setRight(insert(node->getRight(), key, is_insert));
            else
            {
                *is_insert = false;
                return (node);
            }
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

        Node *deleteNode(Node *node, value_type key) 
        {
            Node *temp;
            if (node == NULL)
                return (node);
            if (key.first < node->getKey().first)
                node->setLeft(deleteNode(node->getLeft(), key));
            else if (key.first > node->getKey().first)
                node->setRight(deleteNode(node->getRight(), key));
            else
            {
                if ((node->getLeft() == NULL) || (node->getRight() == NULL))
                {
                    node->destroyKey();
                    if (node->getLeft())
                        temp = node->getLeft();
                    else
                        temp = node->getRight();
                    if (temp == NULL)
                    {
                        
                        temp = node;
                        node = NULL;
                    }
                    else
                    {
                        *node = *temp;
                    }
                    alloc.destroy(temp);
                } 
                else
                {
                    alloc_val tmp;
                    temp = minValueNode(node->getRight());
                    node->setKey(temp->getKey());
                    node->setRight(deleteNode(node->getRight(), node->getKey()));
                }
            }
            node = balanceTreeDelete(node);
            return (node);
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
        
        Node *getParent() const
        {
            return (this->_parent);
        }

        value_type getKey() const
        {
            return (*this->_key);
        }

        value_type *getKeyPtr() const
        {
            return (this->_key);
        }

        bool getStatus() const
        {
            return (this->_first);
        }
        
        Node *getRoot() const
        {
            Node *tmp = this;
            while (tmp->getParent() != NULL)
                tmp = tmp->getParent();
            return (tmp);
        }      
        
        alloc_type getAlloc() const
        {
            return (this->alloc);
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

        void setKey(value_type newkey)
        {
            if (this->_key != NULL)
            {
                alloc_val tmp;
                tmp.destroy(_key);
            }
            this->_key = constructKey(newkey);
            
        }

        void setStatus(bool status)
        {
            this->_first = status;
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
        
        Node *balanceTreeInsert(Node *node, value_type key)
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
        
        Node *balanceTreeDelete(Node *node)
        {
            if (node == NULL)
                return node;
            modifHeight(node);
            int balanceFactor = getBalanceFactor(node);
            if (balanceFactor > 1)
            {
                if (getBalanceFactor(node->getLeft()) >= 0) 
                    return rightRotate(node);
                node->setLeft(leftRotate(node->getLeft()));
                return rightRotate(node);
            }
            if (balanceFactor < -1) 
            {
                if (getBalanceFactor(node->getRight()) <= 0)
                    return leftRotate(node);
                node->setRight(rightRotate(node->getRight()));
                return leftRotate(node);
            }
            return (node);
        }
    
        Node * increase(Node *node) 
        {
            if (node->getRight())
            {
                node = node->getRight();
                while (node->getLeft())
                    node = node->getLeft();
            }
            else 
            {
                Node *temp = node;
                node = node->getParent();
                while (node->getLeft() != temp)
                {
                    temp = node;
                    node = node->getParent();
                }
            }
            return (node);
        }
        
        Node * decrease(Node * node) 
        {
            if (node->getLeft()) 
            {
                node = node->getLeft();
                while (node->getRight())
                    node = node->getRight();
            }
            else 
            {
                Node *temp = node;
                node = node->getParent();
                while (node->getRight() != temp) 
                {
                    temp = node;
                    node = node->getParent();
                }
            }
            return (node);
        }
    
        private:
            alloc_type    alloc;
            value_type    *_key;
            Node          *_left;
            Node          *_right;
            int           _height;
            Node          *_parent;
            bool          _first;        

    };

}
#endif