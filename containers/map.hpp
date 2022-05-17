/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   map.hpp                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cassassi <cassassi@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/04/26 11:12:42 by cassassi          #+#    #+#             */
/*   Updated: 2022/05/17 15:35:42 by cassassi         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef MAP_H
#define MAP_H

# include <iostream>
# include <functional>
# include <memory>
# include <stdint.h> 
# include "pair.hpp"
# include "is_integral.hpp"
# include "enable_if.hpp"
# include "map_iterator.hpp"
# include "reverse_iterator.hpp"
# include "binary_search_tree.hpp"

namespace ft
{
    
    template <class Arg1, class Arg2, class Result>
    struct binary_function 
    {
        typedef Arg1 first_argument_type;
        typedef Arg2 second_argument_type;
        typedef Result result_type;
    };
    
    template <class T> 
    class less : ft::binary_function<T,T,bool>
    {
        bool operator() (const T& x, const T& y) const 
        {
            return x<y;
        }
    };

    
    template < class Key, class T, class Compare = ft::less<Key>, class Alloc = std::allocator<ft::pair<const Key,T> > >
    class map
    {
        public :
        
        typedef Key                                                     key_type;
        typedef T                                                       mapped_type;
        typedef ft::pair<const key_type, mapped_type>                   value_type;
        typedef Compare                                                 key_compare;
        typedef Alloc                                                   allocator_type;
        
        class value_compare: binary_function<value_type, value_type, bool>
        {
            friend class map<key_type, mapped_type, key_compare, allocator_type>;
            
            protected:
                Compare comp;
                value_compare (Compare c) : comp(c) {}
            public:
                bool operator()(const value_type& x, const value_type& y) const
                {
                    return comp(x.first, y.first);
                }
        };
                
        typedef typename allocator_type::reference                      reference;
        typedef typename allocator_type::const_reference                const_reference;
        typedef typename allocator_type::pointer                        pointer;
        typedef typename allocator_type::const_pointer                  const_pointer;
        typedef typename ft::map_iterator<Node<key_type, mapped_type>, value_type>                   iterator;
        typedef typename ft::map_iterator<Node<key_type, mapped_type>, const value_type>             const_iterator;
        typedef typename ft::reverse_iterator<iterator>                 reverse_iterator;
        typedef typename ft::reverse_iterator<const_iterator>           const_reverse_iterator;
        typedef typename ft::iterator_traits<iterator>::difference_type difference_type;
        typedef typename allocator_type::size_type                      size_type;
        
        //                  PUBLIC MEMBER FUNCTION

    //
        // Constructors
        explicit map (const key_compare& comp = key_compare(), const allocator_type& alloc = allocator_type()) :
        _alloc(alloc), _comp(comp), _size(0)
        {
            std::allocator<Node<key_type, mapped_type> > tmp;
            _root = tmp.allocate(1);
            _root->setStatus(true);
        }
                     
        template <class InputIterator>
        map(InputIterator first, 
        typename ft::enable_if<!ft::is_integral<InputIterator>::value, InputIterator>::type last,
        const key_compare& comp = key_compare(),
        const allocator_type& alloc = allocator_type()) :
        _alloc(alloc), _comp(comp), _size(0)
        {
            std::allocator<Node<key_type, mapped_type> > tmp;
            _root = tmp.allocate(1);
            _root->setStatus(true);
            this->insert(this->begin(), first, last);
        }
            
        map(const map& x) :
        _alloc(allocator_type()), _comp(key_compare()), _size(0)
        {
            std::allocator<Node<key_type, mapped_type> > tmp;
            _root = tmp.allocate(1);
            _root->setStatus(true);
            if (&x != this)
                *this = x;
        }
        
        // destructor
        ~map()
        {
			this->_root->clear();
        }

        // operator=
        map& operator= (const map& x)
        {
            if (this->_size > 0)
            {
                this->clear();
                std::allocator<Node<key_type, mapped_type> > tmp;
                _root = tmp.allocate(1);
                _root->setStatus(true);
            }
            this->insert(this->begin(), x.begin(), x.end());
            return (*this);
        }

    //ITERATORS
        
        // begin
        iterator begin()
        {
            if (this->_size == 0)
                return(iterator(this->_root));
            return (iterator(this->_root->minValueNode(_root)));
        }
        const_iterator begin() const
        {
                        if (this->_size == 0)
                return(const_iterator(this->_root));
            return (const_iterator(this->_root->minValueNode(_root)));
        }
        
        // end
        iterator end()
        {
            if (this->_size == 0)
                return(iterator(this->_root));
            return (iterator(this->_root->maxValueNode(_root)));
        }
        const_iterator end() const
        {
            if (this->_size == 0)
                return(const_iterator(this->_root));
            return (const_iterator(this->_root->maxValueNode(_root)));
        }
        
        // rbegin     
        reverse_iterator rbegin()
        {
            return (reverse_iterator(this->end()));
        }
        const_reverse_iterator rbegin() const
        {
            return (const_reverse_iterator(this->end()));
        }
        
        // rend
        reverse_iterator rend()
        {
            return (reverse_iterator(this->begin()));
        }
        const_reverse_iterator rend() const
        {
            return (const_reverse_iterator(this->begin()));
        }

    //CAPACITY
        
        // empty
        bool empty() const
        {
            if (this->_size == 0)
                return (true);
            return (false);
        }
        
        // size
        size_type size() const
        {
            return (this->_size);
        }
        
        // max_size
        size_type max_size() const
        {
            const size_type diffmax = PTRDIFF_MAX / sizeof(value_type);
            const size_type allocmax = _alloc.max_size();
            return (std::min(diffmax, allocmax));
        }

    //ELEMENT ACCESS
    
        //operator[]
        mapped_type& operator[] (const key_type& k)
        {
            return (this->_root->search(this->_root, k)->getKeyPtr()->second);
        }
    
    //MODIFIERS
    
        // insert
        pair<iterator,bool> insert(const value_type& val)
        {
            if (this->_size == 0)
            {
                bool insert_valid = true;
                this->_root = this->_root->insert(this->_root, val, &insert_valid);
                if (insert_valid == true)
                    this->_size++;
                return (ft::make_pair(iterator(_root), true));
            }
            iterator ite = this->end();
            iterator it = this->begin();
            while (it != ite && *it != val)
            {
                if (*it == val)
                    return (ft::make_pair(it, false));
                it++;
            }
            bool insert_valid = true;
            this->_root = this->_root->insert(this->_root, val, &insert_valid);
            if (insert_valid == true)
                this->_size++;
            ite = this->end();
            it = this->begin();
            while (it != ite && *it != val)
            {
                it++;
            }
            return (ft::make_pair(it, true));
        }
        
        iterator insert (iterator position, const value_type& val)
        {
            (void)position;
            bool insert_valid = true;
            this->_root = this->_root->insert(this->_root, val, &insert_valid);
            if (insert_valid == true)
                this->_size++;
            return (iterator(this->_root->search(this->_root, val.first)));
        }
        
        template <class InputIterator>
        void insert (iterator position, InputIterator first, 
        typename ft::enable_if<!ft::is_integral<InputIterator>::value, InputIterator>::type last)
        {
            (void)position;
            for(; first != last; first++)
            {
                bool insert_valid = true;
                this->_root = this->_root->insert(this->_root, *first, &insert_valid);
                if (insert_valid == true)
                    this->_size++;
            }
            bool insert_valid = true;
            this->_root = this->_root->insert(this->_root, *first, &insert_valid);
            if (insert_valid == true)
                this->_size++;
        }

        // erase
        void erase (iterator position)
        {
            if (this->_root->search(this->_root, (*position).first))
            {
                this->_root = this->_root->deleteNode(this->_root, (*position));
                this->_size--;
            }
        }
        
        size_type erase (const key_type& k)
        {
            Node<Key, T> *tmp = this->_root->search(this->_root, k);
            if (tmp != NULL)
            {
                this->_root = this->_root->deleteNode(this->_root, tmp->getKey());
                this->_size--;
            }
            return (1);
        }
        
        void erase (iterator first, iterator last)
        {
            for(; first != last; first++)
            {
                if (this->_root->search(this->_root, (*first).first))
                {
                    this->_root = this->_root->deleteNode(this->_root, *first);
                    this->_size--;
                }
            }
        }
        
        // swap
        // void swap (map& x)
        // {}
        
        // clear
        void clear()
        {
            this->_root->clear();
            this->_size = 0;
        }
        
    //OBSERVERS
    
        // key_comp
        key_compare key_comp() const
        {
            return (this->_comp);
        }
        
        // value_comp
        value_compare value_comp() const
        {
            return(this->value_compare());
        }
        
    //OPERATION
    
        // find
        iterator find (const key_type& k)
        {
            iterator ite = this->end();
            for(iterator it = this->begin(); it != ite; it++)
            {
                if (k == *it->getKey()->first)
                    return(it);
            }
            return (ite);
        }
		
        const_iterator find (const key_type& k) const
        {
            const_iterator ite = this->end();
            for(const_iterator it = this->begin(); it != ite; it++)
            {
                if (k == *it->getKey()->first)
                    return(it);
            }
            return (ite);
        }
        
        // count
        size_type count (const key_type& k) const
        {
            if(this->_root.search(this->root, k))
                return (1);
            return (0);
        }
        
        // lower_bound
        iterator lower_bound (const key_type& k)
        {
            iterator ite = this->end();
            for (iterator it = this->begin(); it != ite; it++)
            {
                if (!this->_comp(*it->getKey()->first, k))
                return (it);
            }
            return (ite);
        }
		
        const_iterator lower_bound (const key_type& k) const
        {
            const_iterator ite = this->end();
            for (const_iterator it = this->begin(); it != ite; it++)
            {
                if (!this->_comp(*it->getKey()->first, k))
                return (it);
            }
            return (ite);
        }
        
        // upper_bond
        iterator upper_bound (const key_type& k)
        {
            iterator ite = this->end();
            for (iterator it = this->begin(); it != ite; it++)
            {
                if (!this->_comp(k, *it->getKey()->first))
                    return (it);
            }
            return (ite);
        }
		
        const_iterator upper_bound (const key_type& k) const
        {
            const_iterator ite = this->end();
            for (const_iterator it = this->begin(); it != ite; it++)
            {
                if (!this->_comp(k, *it->getKey()->first))
                return (+it);
            }
            return (ite);
        }
        
        // equal_range
        pair<const_iterator,const_iterator> equal_range (const key_type& k) const
        {
            return(ft::make_pair(lower_bond(k), upper_bound(k)));
        }
        
        pair<iterator,iterator> equal_range (const key_type& k)
        {
            return(ft::make_pair(lower_bond(k), upper_bound(k)));
        }
        
    //ALLOCATOR
    
        // get_allocator
        allocator_type get_allocator() const
        {
            return (this->_alloc);
		}

        //FONCTION POUR TEST
        ft::Node<key_type, mapped_type>	*getRoot()const
        {return (_root);}

        void printMap()
        {
            iterator ite = this->end();
            iterator it = this->begin();
            std::cout << "Map print start" << std::endl;   
            for (;it != ite; it++)
            {
                std::cout << (*it).first << std::endl;   
            }
            std::cout << (*it).first << std::endl;
            std::cout << "Map print end" << std::endl;   

        }

        
        private:

            allocator_type  				_alloc;
            key_compare     				_comp;
            ft::Node<key_type, mapped_type>	*_root;
            size_type       				_size;  
        
            value_type *increase(value_type pos) 
            {
                Node<key_type, mapped_type> *node = _root->search(_root, pos.first);
                if (node->getRight())
                {
                    node = node->getRight();
                    while (node->getLeft())
                        node = node->getLeft();
                }
                else 
                {
                    Node<key_type, mapped_type> *temp = node;
                    node = node->getParent();
                    while (node->getLeft() != temp)
                    {
                        temp = node;
                        node = node->getParent();
                    }
                }

                return (node);
            }
    };
}

#endif