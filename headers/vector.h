
#include <iostream>

#define VECTEUR_H

template <class O>
class Vector
{
public:
    Vector(int c = 2);
    ~Vector();
    
    int getCapacity();
    int getSize();
    
    void doubleSize();
    void purge();
    
    bool isEmpty();
    
    void copyList(O **element, O **list);
    void printTo(std::ostream &s);
    
    O *getElement(int index);
    O *removeElement(int index);
    bool addElement(O *element);

    O *operator[](int index);
    bool operator+=(O *element);

    friend std::ostream& operator<<(std::ostream &s, Vector<O> &vector) {
        vector.printTo(s);
        return s;
    }

    friend std::ofstream& operator<<(std::ofstream &s, Vector<O> &vector) {
        vector.printTo(s);
        return s;
    }

    friend std::ostringstream& operator<<(std::ostringstream &s, Vector<O> &vector) {
        vector.printTo(s);
        return s;
    }


    friend std::istream& operator>>(std::istream &s, Vector<O> &vector) {
        for (int i = 0; i < vector.capacity; i++) {
            O *element;
            s >> element;
            vector.addElement(element);
        }
        return s;
    }

    friend std::ifstream& operator>>(std::ifstream &s, Vector<O> &vector) {
        for (int i = 0; i < vector.capacity; i++) {
            O *element;
            s >> element;
            vector.addElement(element);
        }
        return s;
    }

    friend std::istringstream& operator>>(std::istringstream &s, Vector<O> &vector) {
        for (int i = 0; i < vector.capacity; i++) {
            O *element;
            s >> element;
            vector.addElement(element);
        }
        return s;
    }

    void operator++(); 
    void operator--();

private:
    O **list;
    int size;
    int capacity;
    int current = 0;
};

template <class O>
Vector<O>::Vector(int c)
{
    capacity = c;
    size = 0;

    list = new O *[capacity];
    for (int i = 0; i < capacity; i++) { list[i] = nullptr; }
}

template <class O>
Vector<O>::~Vector() { 
    for (int i = 0; i < capacity; i++) { delete list[i]; }
    delete list;
}

template <class O>
int Vector<O>::getCapacity() { return capacity; }

template <class O>
int Vector<O>::getSize() { return size; }

template <class O>
void Vector<O>::doubleSize()
{
    O **temp_list = new O *[capacity * 2];

    copyList(list, temp_list);

    capacity *= 2;

    delete list;
    list = temp_list;
    
}

template <class O>
void Vector<O>::purge()
{
    for (int i = 0; i < capacity; i++) { list[i] = nullptr; }
    size = 0;
}

template <class O>
bool Vector<O>::isEmpty()
{
    for (int i = 0; i < capacity; i++) {

        if (list[i] != nullptr) { return false; }

    }

    return true;
}

template <class O>
void Vector<O>::copyList(O **source, O **destination)
{
    
    for (int i = 0; i < capacity; i++) { 
        destination[i] = source[i];
    }

    destination = source;
}

template <class O>
void Vector<O>::printTo(std::ostream &s)
{
    for (int i = 0; i < capacity; i++)
    {
        if (list[i] != nullptr) { s << *list[i] << std::endl; }
        else { s << "null" << std::endl; }
    }
}

template <class O>
O *Vector<O>::getElement(int index)
{
    if (list[index] == nullptr || index < 0 || index > capacity - 1) { return nullptr; }
    return list[index];
}

template <class O>
O *Vector<O>::removeElement(int index)
{
    if (index < 0 || index > capacity - 1) { return nullptr; }

    O *element = list[index];

    list[index] = nullptr;

    O **temp_list = new O *[capacity];

    int cnt = 0;

    for (int i = 0; i < capacity; i++)
    {
        if (list[i] == nullptr) { continue; }

        temp_list[cnt] = list[i];
        cnt++;
    }

    copyList(temp_list, list);

    size--;

    return element;
}

template <class O>
bool Vector<O>::addElement(O *element)
{
    if (size == capacity) { doubleSize(); }

    list[size] = element;
    size++;

    return true;
}

template <class O>
O *Vector<O>::operator[](int index)
{
    if (list[index] == nullptr || index < 0 || index > capacity - 1) { return nullptr; }
    return list[index];
}

template <class O>
bool Vector<O>::operator+=(O *element)
{
    if (size == capacity) { doubleSize(); }

    list[size] = element;
    size++;

    return true;
}

template <class O>
void Vector<O>::operator++() { if (current < capacity) current++; }

template <class O>
void Vector<O>::operator--() { if (current > 0)current--; }

