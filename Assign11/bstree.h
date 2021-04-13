#ifndef BSTREE
#define BSTREE

#include <cstdlib>

template <class K, class V>
struct node
{
    K key;
    V value;
    node<K, V> *left;
    node<K, V> *right;

    node<K, V>(const K &k = K(),const V &v = V(), node<K, V> *l = nullptr, node<K, V> *r = nullptr)
    {
        key = k;
        value = v;
        left = l;
        right = r;
    }
};

template <class K, class V>
class bstree
{
private:
    node<K, V> *root;
    size_t size;
public:
    bstree();
};

bstree<K, V>::bstree()
{
    root = nullptr;
    size = 0;
}

#endif