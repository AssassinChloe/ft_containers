/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   map.hpp                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cassassi <cassassi@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/04/26 11:12:42 by cassassi          #+#    #+#             */
/*   Updated: 2022/05/23 12:30:45 by cassassi         ###   ########.fr       */
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
        public :
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
          this->_root = this->_node.allocate(1);
          this->_root->_first = true;
        }
                     
        template <class InputIterator>
        map(InputIterator first, 
        typename ft::enable_if<!ft::is_integral<InputIterator>::value, InputIterator>::type last,
        const key_compare& comp = key_compare(),
        const allocator_type& alloc = allocator_type()) :
        _alloc(alloc), _comp(comp), _size(0)
        {
            this->_root = this->_node.allocate(1);
            this->_root->_first = true;
            this->insert(first, last);
        }
            
        map(const map& x) : _alloc(allocator_type()), _comp(key_compare()), _size(0)
        {
            this->_root = this->_node.allocate(1);
            this->_root->_first = true;
            if (&x != this)
                *this = x;
        }
        
        // destructor
        ~map()
        {
            if (this->_size == 0)
               this->_node.deallocate(this->_root, 1);
            else
                this->_root->clear();
        }

        // operator=
        map& operator= (const map& x)
        {
            if (this->_size > 0)
                this->clear();
            this->insert(x.begin(), x.end());
            return (*this);
        }

    //ITERATORS
        
        // begin
        iterator begin()
        {
            if (this->_size == 0)
                return(iterator(this->_root));
            return (iterator(this->_root->minValueNode(this->_root)));
        }
        const_iterator begin() const
        {
            if (this->_size == 0)
                return(const_iterator(this->_root));
            return (const_iterator(this->_root->minValueNode(this->_root)));
        }
        
        // end
        iterator end()
        {
            if (this->_size == 0)
                return(iterator(this->_root));
            return (iterator(this->_root->maxValueNode(this->_root)));
        }
        const_iterator end() const
        {
            if (this->_size == 0)
                return(const_iterator(this->_root));
            return (const_iterator(this->_root->maxValueNode(this->_root)));
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
            const size_type diffmax = PTRDIFF_MAX / sizeof(ft::Node<key_type, mapped_type>);
            const size_type allocmax = _node.max_size();
            return (std::min(diffmax, allocmax));
        }

    //ELEMENT ACCESS
    
        //operator[]
        mapped_type& operator[] (const key_type& k)
        {
            Node<key_type, mapped_type> *tmp = this->_root->search(this->_root, k);
            if (tmp)
                return (tmp->_key->second);
            return ((*((this->insert(make_pair(k,mapped_type()))).first)).second);
        }
    
    //MODIFIERS
    
        // insert
        pair<iterator,bool> insert(const value_type& val)
        {
            bool insert_valid = true;
            if (this->_size == 0)
            {
                Node<key_type, mapped_type> *tmp;
                tmp = this->_root->insert(this->_root, val, &insert_valid);
               this->_node.deallocate(this->_root, 1);
                this->_root = tmp;
                if (insert_valid == true)
                    this->_size++;
                return (ft::make_pair(iterator(this->_root), true));
            }
            iterator ite = this->end();
            iterator it = this->begin();
            while (it != ite && *it != val)
            {
                if (*it == val)
                    return (ft::make_pair(it, false));
                it++;
            }
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
            if (this->_size == 0)
            {
                Node<key_type, mapped_type> *tmp;
                tmp = this->_root->insert(this->_root, val, &insert_valid);
               this->_node.deallocate(this->_root, 1);
                this->_root = tmp;
                if (insert_valid == true)
                    this->_size++;
                return (iterator(this->_root->search(this->_root, val.first)));
            }
            else
                this->_root = this->_root->insert(this->_root, val, &insert_valid);

            if (insert_valid == true)
                this->_size++;
            return (iterator(this->_root->search(this->_root, val.first)));
        }
        
        template <class InputIterator>
        void insert (InputIterator first, 
        typename ft::enable_if<!ft::is_integral<InputIterator>::value, InputIterator>::type last)
        {
            bool insert_valid = true;
            if (this->_size == 0)
            {
                Node<key_type, mapped_type> *tmp;
                tmp = this->_root->insert(this->_root, *first, &insert_valid);
                this->_node.deallocate(this->_root, 1);
                this->_root = tmp;
                if (insert_valid == true)
                    this->_size++;
                first++;
            }
            for(; first != last; first++)
            {
                insert_valid = true;
                this->_root = this->_root->insert(this->_root, *first, &insert_valid);
                if (insert_valid == true)
                    this->_size++;
            }
            insert_valid = true;
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
            if (!this->_root)
            {
                this->_root = this->_node.allocate(1);
                this->_root->_first = true;
            }
            if (this->_size > 0)
                this->_root->setAllParents(this->_root);
        }
        
        size_type erase (const key_type& k)
        {
            Node<Key, T> *tmp = this->_root->search(this->_root, k);
            if (tmp != NULL)
            {
                this->_root = this->_root->deleteNode(this->_root, *(tmp->_key));
                this->_size--;
            }
            if (!this->_root)
            {
                this->_root = this->_node.allocate(1);
                this->_root->_first = true;
            }
            if (this->_size > 0)
                this->_root->setAllParents(this->_root);
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
            if (this->_root->search(this->_root, (*first).first))
            {
                this->_root = this->_root->deleteNode(this->_root, *first);
                this->_size--;
            }
            if (!this->_root)
            {
                this->_root = this->_node.allocate(1);
                this->_root->_first = true;   
            }
            if (this->_size > 0)
                this->_root->setAllParents(this->_root);
        }
        
        // swap
        // void swap (map& x)
        // {
            
        // }
        
        // clear
        void clear()
        {
            this->_root->clear();
            this->_root = this->_node.allocate(1);
            this->_root->_first = true;
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
                if (k == (*it).first)
                    return(it);
            }
            return (ite);
        }
		
        const_iterator find (const key_type& k) const
        {
            const_iterator ite = this->end();
            for(const_iterator it = this->begin(); it != ite; it++)
            {
                if (k == *(*it).first)
                    return(it);
            }
            return (ite);
        }
        
        // count
        size_type count (const key_type& k) const
        {
            if (this->_root->search(this->_root, k))
                return (1);
            return (0);
        }
        
        // lower_bound
        iterator lower_bound (const key_type& k)
        {
            iterator ite = this->end();
            for (iterator it = this->begin(); it != ite; it++)
            {
                if (!this->_comp((*it).first, k))
                return (it);
            }
            return (ite);
        }
		
        const_iterator lower_bound (const key_type& k) const
        {
            const_iterator ite = this->end();
            for (const_iterator it = this->begin(); it != ite; it++)
            {
                if (!this->_comp((*it).first, k))
                return (it);
            }
            return (ite);
        }
        
        // upper_bond
        iterator upper_bound (const key_type& k)
        {
            Node<Key, T> *tmp = this->_root->search(this->_root, k);
            if (tmp == NULL  || tmp == _root->maxValueNode(this->_root))
                return (this->lower_bound(k));
            else
                return (++this->lower_bound(k));

        }
		
        const_iterator upper_bound (const key_type& k) const
        {
            Node<Key, T> *tmp = this->_root->search(this->_root, k);
            if (tmp == NULL || tmp == _root->maxValueNode(this->_root))
                return (this->lower_bound(k));
            else
                return (++this->lower_bound(k));
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

        
        private:

            typedef std::allocator<Node<key_type, mapped_type> > node_alloc;

            node_alloc                      _node;
            allocator_type  				_alloc;
            key_compare     				_comp;
            ft::Node<key_type, mapped_type>	*_root;
            size_type       				_size;  
    };
}

#endif