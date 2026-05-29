#ifndef _HASHTABLE_H
#define _HASHTABLE_H
#include <vector>
#include <string>
using namespace std;



template <class HashedObj>
class HashTable
{
public:
    explicit HashTable(const HashedObj & notFound, int size = 101);
    HashTable(const HashTable & rhs )
        :ITEM_NOT_FOUND(rhs.ITEM_NOT_FOUND),array(rhs.array), currentSize(rhs.currentSize) { }
    void makeEmpty();
    const HashTable & operator=(const HashTable & rhs);

    const HashedObj & find(const HashedObj & x) const;
    void insert(const HashedObj & x);
    void remove(const HashedObj & x);
    enum EntryType{ACTIVE, EMPTY, DELETED};

private:
    struct HashEntry
    {
        HashedObj element;
        EntryType info;

        HashEntry(const HashedObj & e = HashedObj( ), EntryType i = EMPTY)
            :element(e), info(i) { }
    };

    vector<HashEntry> array;
    int currentSize;
    const HashedObj ITEM_NOT_FOUND;

    bool isActive( int currentPos ) const;
    int findPos( const HashedObj & x ) const;
    void rehash( );
};

int hashfunc(const string & key, int tableSize)
{
    int hashVal = 0;
    for (int i = 0; i < key.length();i++)
        hashVal = 37 * hashVal + key[i];
    hashVal = hashVal % tableSize;
    if (hashVal < 0)
        hashVal = hashVal + tableSize;
    return(hashVal);

}

int hashfunc(int key, int tableSize)
{
    return (key % tableSize);
}

bool isPrime(int n)
{
    if(n == 2 || n == 3)
        return true;
    if(n == 1 || n % 2 == 0)
        return false;
    for(int i = 3; i * i <= n; i += 2)
        if(n % i == 0)
            return false;
    return true;
}

int nextPrime(int n)
{
    if(n % 2 == 0)
        n++;
    for( ; !isPrime(n); n += 2 )
        ;
    return n;
}

template <class HashedObj>
HashTable<HashedObj>::HashTable(const HashedObj & notFound, int size)
    :ITEM_NOT_FOUND(notFound), array(nextPrime(size)),currentSize(0)
{
    makeEmpty();
}

template <class HashedObj>
void HashTable<HashedObj>::makeEmpty()
{
    for(int j = 0; j < array.size( ); j++)
        array[j].info = EMPTY;
}

template <class HashedObj>
int HashTable<HashedObj>::findPos(const HashedObj & x) const
{
    int i = 0;
    int p = hashfunc(x, array.size());
    while(array[p].info != EMPTY && array[p].element != x)
    {
        ++p;
        if (p >= array.size())
            p = 0;
    }
    return p;
}

template <class HashedObj>
bool HashTable<HashedObj>::isActive(int currentPos) const
{
    return array[currentPos].info == ACTIVE;
}

template <class HashedObj>
void HashTable<HashedObj>::insert(const HashedObj & x)
{
    int currentPos = findPos(x);
    if(isActive(currentPos))
        return;
    array[currentPos] = HashEntry(x, ACTIVE);
    if(++currentSize >= array.size() / 2)
        rehash();
}

template <class HashedObj>
void HashTable<HashedObj>::remove(const HashedObj & x)
{
    int currentPos = findPos(x);
    if(isActive(currentPos))
        array[currentPos].info = DELETED;
}

template <class HashedObj>
const HashedObj & HashTable<HashedObj>::find(const HashedObj & x) const
{
    int currentPos = findPos(x);
    if (isActive(currentPos))
        return array[currentPos].element;
    return ITEM_NOT_FOUND;
}

template <class HashedObj>
void HashTable<HashedObj>::rehash()
{
    vector<HashEntry> oldArray = array;
    array.resize(nextPrime(2 * oldArray.size()));
    for(int j = 0; j < array.size(); j++){
        array[j].info = EMPTY;
    }
    currentSize = 0;
    for( int i = 0; i < oldArray.size(); i++)
    {
        if(oldArray[i].info == ACTIVE)
            insert(oldArray[i].element);
    }
}

#endif
