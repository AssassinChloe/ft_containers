/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   map.hpp                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cassassi <cassassi@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/04/26 11:12:42 by cassassi          #+#    #+#             */
/*   Updated: 2022/05/13 12:15:21 by cassassi         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef MAP_H
#define MAP_H

# include <iostream>
# include <functional>
# include <memory>
# include "pair.hpp"
# include "is_integral.hpp"
# include "enable_if.hpp"
# include "map_iterator.hpp"
# include "reverse_iterator.hpp"
# include "binary_search_tree.hpp"

namespace ft
{
    template < class Key,
           class T,
           class Compare = std::less<Key>,
           class Alloc = std::allocator<ft::pair<const Key,T> >
           >
    class map
    {
        public :
        
        typedef Key                                                     key_type;
        typedef T                                                       mapped_type;
        typedef ft::pair<const key_type, mapped_type>                   value_type;
        typedef Compare                                                 key_compare;
        typedef Alloc                                                   allocator_type;
        
        class map::value_compare: binary_function<value_type, value_type, bool>
        {
            friend class map<key_type, mapped_type, key_compare, allocator_type>
            
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
        typedef typename ft::map_iterator<value_type>                   iterator;
        typedef typename ft::map_iterator<const value_type>             const_iterator;
        typedef typename ft::reverse_iterator<iterator>                 reverse_iterator;
        typedef typename ft::reverse_iterator<const_iterator>           const_reverse_iterator;
        typedef typename ft::iterator_traits<iterator>::difference_type difference_type;
        typedef typename allocator_type::size_type                      size_type;
        
        //                  PUBLIC MEMBER FUNCTION

    //
        // Constructors
        explicit map (const key_compare& comp = key_compare(), const allocator_type& alloc = allocator_type()) :
        _alloc(alloc)
        {}
                     
        template <class InputIterator>
        map(InputIterator first, InputIterator last,
            const key_compare& comp = key_compare(),
            const allocator_type& alloc = allocator_type())
            {}
            
        map (const map& x)
        {}
        
        // destructor
        ~map()
        {}

        // operator=
        map& operator= (const map& x)
        {}

    //ITERATORS
        
        // begin
        iterator begin()
        {
            return (this->_node.minValueNode(_node));
        }
        const_iterator begin() const
        {
            return (this->_node.minValueNode(_node));
        }
        
        // end
        iterator end()
        {
            return (this->_node.maxValueNode(_node));
        }
        const_iterator end() const
        {
            return (this->_node.maxValueNode(_node));
        }
        
        // rbegin     
        reverse_iterator rbegin()
        {
            return (reverse_iterator(this->end());
        }
        const_reverse_iterator rbegin() const
        {
            return (reverse_iterator(this->end());
        }
        
        // rend
        reverse_iterator rend()
        {
            return (reverse_iterator(this->begin()));
        }
        const_reverse_iterator rend() const
        {
            return (reverse_iterator(this->begin()));
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
            Node<value_type> tmp = tmp.search(k);
            return (tmp.getKey().second)
        }
    
    //MODIFIERS
    
        // insert
        pair<iterator,bool> insert (const value_type& val)
        {}
        
        iterator insert (iterator position, const value_type& val)
        {}
        
        template <class InputIterator>
        void insert (iterator position, InputIterator first, 
        typename ft::enable_if<!ft::is_integral<InputIterator>::value, InputIterator>::type last)
        {
            
        }

        // erase
        void erase (iterator position)
        {
            this->_node.deleteNode()
        }
        
        size_type erase (const key_type& k)
        {}
        
        void erase (iterator first, iterator last)
        {}
        
        // swap
        void swap (map& x)
        {}
        
        // clear
        void clear()
        {
            this->_node.clear();
            this->_size = 0;
        }
        
    //OBSERVERS
    
        // key_comp
        key_compare key_comp() const
        {}
        
        // value_comp
        value_compare value_comp() const
        {}
        
    //OPERATION
    
        // find
        iterator find (const key_type& k)
        {}
        const_iterator find (const key_type& k) const
        {}
        
        // count
        size_type count (const key_type& k) const
        {}
        
        // lower_bound
        iterator lower_bound (const key_type& k)
        {}
        const_iterator lower_bound (const key_type& k) const
        {}
        
        // upper_bond
        iterator upper_bound (const key_type& k)
        {}
        const_iterator upper_bound (const key_type& k) const
        {}
        
        // equal_range
        pair<const_iterator,const_iterator> equal_range (const key_type& k) const
        {}
        
        pair<iterator,iterator> equal_range (const key_type& k)
        {}
        
    //ALLOCATOR
    
        // get_allocator
        allocator_type get_allocator() const
        {
            return (this->_alloc);
        }
    

    private:

        allocator_type  _alloc;
        Node<T>         _node;
        size_type       _size;  
      
    };
}

#endif