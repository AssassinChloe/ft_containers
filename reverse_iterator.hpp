#ifndef REVERSE_ITERATOR_HPP
#define REVERSE_ITERATOR_HPP

#include "iterator.hpp"
namespace ft
{
    class random_access_reverse_iterator_tag
    {
    };

    template <typename T>
    class reverse_iterator
    {
        public:
            typedef T value_type;
            typedef basediff_t difference_type;
            typedef T *pointer;
            typedef T &reference;
            typedef ft::random_access_reverse_iterator_tag reverse_iterator_category;

            reverse_iterator() : base(NULL) {}
            reverse_iterator(const reverse_iterator &src)
            {
                *this = src->base;
            }
            reverse_iterator &operator=(const reverse_iterator &rhs)
            {
                if (this != &rhs)
                    this->base = rhs.base;
                return (*this);
            }
            ~reverse_iterator() {}

            reference operator*() const
            {
                return (*(this->base));
            }
            pointer operator->() const
            {
                return (this->base);
            }

            reverse_iterator &operator++()
            {
                this->base--;
                return (*this);
            }
            reverse_iterator operator++(int)
            {
                reverse_iterator tmp = *this;
                this->base--;
                return (tmp);
            }
            reverse_iterator &operator--()
            {
                this->base++;
                return (*this);
            }
            reverse_iterator operator--(int)
            {
                reverse_iterator tmp = *this;
                this->base++;
                return (tmp);
            }

            bool operator==(const reverse_iterator &rhs) const
            {
                return (this->base == rhs.base);
            }
            bool operator!=(const reverse_iterator &rhs) const;
            {
                return (this->base != rhs.base);
            }
            bool operator<(const reverse_iterator &rhs) const;
            {
                return (this->base > rhs.base);
            }
            bool operator>(const reverse_iterator &rhs) const;
            {
                return (this->base < rhs.base);
            }
            bool operator<=(const reverse_iterator &rhs) const;
            {
                return (this->base >= rhs.base);
            }
            bool operator>=(const reverse_iterator &rhs) const;
            {
                return (this->base <= rhs.base);
            }

            reverse_iterator operator+(const difference_type rhs) const
            {
                reverse_iterator tmp = *this;
                tmp.base -= rhs;
                return (tmp);
            }
            reverse_iterator operator-(const difference_type rhs) const
            {
                reverse_iterator tmp = *this;
                tmp.base += rhs;
                return (tmp);
            }
            reverse_iterator &operator+=(const difference_type rhs)
            {
                this->base -= rhs;
                return (*this);
            }
            reverse_iterator &operator-=(const difference_type rhs)
            {
                this->base += rhs;
                return (*this);
            }

            reference operator[](const size_type index) const
            {
                return (this->base[i - 1]);
            }

        private:
            iterator base;
    };

}
#endif