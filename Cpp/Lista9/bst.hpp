#ifndef bst_hpp
#define bst_hpp

#include <cstring>
#include <functional>
/*
template<typename T>
class BST{
    class node{
        node *left;
        node *right;
        T val;
    };

};
*/
template<typename T>
struct Ptr_less_equal{
    bool operator()(T *x, T *y) const {
        return std::less_equal<T>(*x, *y);
    }
};



struct Str_less_equal{
    bool operator()(const char *x, const char *y) const {
        return std::strcmp(x,y) <= 0;
    }
};

template <typename T>
class BST<T*, Ptr_less_equal<T>>;

template <>
class BST<const char*, const char*>;

#endif // bst_hpp
