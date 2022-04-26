template <class Category, class T, class Distance = ptrdiff_t,
      class Pointer = T*, class Reference = T&>
class iterator
{
    typedef T         value_type;
    typedef Distance  difference_type;
    typedef Pointer   pointer;
    typedef Reference reference;
    typedef Category  iterator_category;

    ~iterator();
    iterator(const iterator&);
    iterator& operator=(const iterator&);

    iterator& operator++();
    iterator operator++(int);

    bool operator==(const iterator&) const;
    bool operator!=(const iterator&) const;

    reference operator*() const;
    pointer operator->() const;

    iterator();

    iterator& operator--();
    iterator operator--(int);

    iterator operator+(size_type) const;
    iterator operator-(size_type) const;
//    friend iterator operator+(size_type, const iterator&); //optional
//    difference_type operator-(iterator) const;

    bool operator<(const iterator&) const;
    bool operator>(const iterator&) const;
    bool operator<=(const iterator&) const;
    bool operator>=(const iterator&) const;

    iterator& operator+=(size_type);
    iterator& operator-=(size_type);
    
    reference operator[](size_type) const;
};