/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   map.hpp                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cassassi <cassassi@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/04/26 11:12:42 by cassassi          #+#    #+#             */
/*   Updated: 2022/05/25 18:33:44 by cassassi         ###   ########.fr       */
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
        _alloc(alloc), _comp(comp), _root(NULL), _size(0)
        {}
                     
        template <class InputIterator>
        map(InputIterator first, 
        typename ft::enable_if<!ft::is_integral<InputIterator>::value, InputIterator>::type last,
        const key_compare& comp = key_compare(),
        const allocator_type& alloc = allocator_type()) :
        _alloc(alloc), _comp(comp), _root(NULL), _size(0)
        {
            this->insert(first, last);
        }
            
        map(const map& x) : _alloc(allocator_type()), _comp(key_compare()), _root(NULL), _size(0)
        {
            if (&x != this)
                *this = x;
        }
        
        // destructor
        ~map()
        {
            if (this->_size > 0)
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
                return(iterator(this->_root, this->_root));
            return (iterator(this->_root->minValueNode(this->_root), this->_root));
        }
        const_iterator begin() const
        {
            if (this->_size == 0)
                return(const_iterator(this->_root, this->_root));
            return (const_iterator(this->_root->minValueNode(this->_root), this->_root));
        }
        
        // end
        iterator end()
        {
            if (this->_size == 0)
                return(iterator(this->_root, this->_root));
            return (iterator(this->_root->maxValueNode(this->_root)->_right, this->_root));
        }
        const_iterator end() const
        {
            if (this->_size == 0)
                return(const_iterator(this->_root, this->_root));
            return (const_iterator(this->_root->maxValueNode(this->_root)->_right, this->_root));
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
            Node *tmp = this->_root->search(this->_root, k);
            if (tmp)
                return (tmp->_key.second);
            return ((*((insert(make_pair(k, mapped_type()))).first)).second);
        }
    
    //MODIFIERS
    
        // insert
        pair<iterator,bool> insert(const value_type& val)
        {
            bool insert_valid = true;
            Node *tmp = NULL;
            this->_root = this->_root->insert(this->_root, val, &insert_valid, &tmp);
            if (insert_valid == true)
            {
                this->_size++;
                this->_root->_modify = true;
            }
            return (ft::make_pair(iterator(tmp, this->_root), insert_valid));
        }
        
        iterator insert (iterator position, const value_type& val)
        {
            (void)position;
            return (insert(val).first);            
        }
        
        template <class InputIterator>
        void insert (InputIterator first, 
        typename ft::enable_if<!ft::is_integral<InputIterator>::value, InputIterator>::type last)
        {
            for(; first != last; first++)
            {
                insert((*first));
            }
        }

        // erase
        
        size_type erase(const key_type& k)
        {
            Node *tmp = this->_root->search(this->_root, k);
            if (tmp)
            {
                this->_root = this->_root->deleteNode(this->_root, tmp->_key);
                this->_size--;
                this->_root->_modify = true;
                return (1);
            }
            return (0);
        }
        
        void erase (iterator position)
        {
            erase((*position).first);
        }
        
        void erase (iterator first, iterator last)
        {
            for(; first != last; first++)
            {
                erase((*first));
            }
        }
        
        // swap
        void swap (map& x)
        {
            node_alloc      tmp_node = x._node;
            allocator_type  tmp_alloc = x._alloc;
            key_compare     tmp_comp = x._comp;
            Node	        *tmp_root = x._root;
            size_type       tmp_size = x._size;

            x._node = this->_node;
            x._alloc = this->_alloc;
            x._comp = this->_comp;
            x._root = this->_root;
            x._size = this->_size;
            
            this->_node = tmp_node;
            this->_alloc = tmp_alloc;
            this->_comp = tmp_comp;
            this->_root = tmp_root;
            this->_size = tmp_size;
        }
        
        // clear
        void clear()
        {
            this->_root->clear();
            this->_size = 0;
            this->_root = NULL;
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
            Node *tmp = this->_root->search(this->_root, k);
            if (!tmp)
                return (this->end());
            return (iterator(tmp, this->_root));
        }
		
        const_iterator find (const key_type& k) const
        {
            Node *tmp = this->_root->search(this->_root, k);
            if (!tmp)
                return (this->end());
            return (const_iterator(tmp, this->_root));
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
            Node *tmp = this->_root->search(this->_root, k);
            if (tmp == NULL  || tmp == _root->maxValueNode(this->_root))
                return (this->lower_bound(k));
            else
                return (++this->lower_bound(k));

        }
		
        const_iterator upper_bound (const key_type& k) const
        {
            Node *tmp = this->_root->search(this->_root, k);
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

            typedef ft::Node<key_type, mapped_type> Node;
            typedef std::allocator<Node> node_alloc;
            
            node_alloc      _node;
            allocator_type  _alloc;
            key_compare     _comp;
            Node	        *_root;
            size_type       _size;

    };

    //NON-MEMBER OVERLOADS

    //relationnal operators
    template <class Key, class T, class Compare, class Alloc>
    bool operator== ( const map<Key,T,Compare,Alloc>& lhs, const map<Key,T,Compare,Alloc>& rhs )
    {
        if (lhs.size() != rhs.size())
            return (false);
        return (equal(lhs.begin(), lhs.end(), rhs.begin()));
    }

    template <class Key, class T, class Compare, class Alloc>
    bool operator!= ( const map<Key,T,Compare,Alloc>& lhs, const map<Key,T,Compare,Alloc>& rhs )
    {
        return (!(lhs == rhs));
    }

    template <class Key, class T, class Compare, class Alloc>
    bool operator<  ( const map<Key,T,Compare,Alloc>& lhs, const map<Key,T,Compare,Alloc>& rhs )
    {
        return (lexicographical_compare(lhs.begin(), lhs.end(), rhs.begin(), rhs.end()));
    }
        
    template <class Key, class T, class Compare, class Alloc>
    bool operator<= ( const map<Key,T,Compare,Alloc>& lhs, const map<Key,T,Compare,Alloc>& rhs )
    {
        return (lhs < rhs || lhs == rhs);
    }

    template <class Key, class T, class Compare, class Alloc>
    bool operator>  ( const map<Key,T,Compare,Alloc>& lhs, const map<Key,T,Compare,Alloc>& rhs )
    {
        return (rhs < lhs);
    }

    template <class Key, class T, class Compare, class Alloc>
    bool operator>= ( const map<Key,T,Compare,Alloc>& lhs, const map<Key,T,Compare,Alloc>& rhs )
    {
        return (lhs > rhs || lhs == rhs);
    }
    
    //swap
    template <class Key, class T, class Compare, class Alloc>
    void swap (map<Key,T,Compare,Alloc>& x, map<Key,T,Compare,Alloc>& y)
    {
        return (x.swap(y));
    }                
}

#endif