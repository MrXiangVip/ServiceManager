//
// Created by xshx on 2023/6/5.
// system/core/include/utils/StrongPointer.h
//

#ifndef UNTITLED1_STRONGPOINTER_H
#define UNTITLED1_STRONGPOINTER_H

#include <stdio.h>
#define COMPARE(_op_)                                           \
inline bool operator _op_ (const sp<T>& o) const {              \
    return m_ptr _op_ o.m_ptr;                                  \
}                                                               \
inline bool operator _op_ (const T* o) const {                  \
    return m_ptr _op_ o;                                        \
}                                                               \
template<typename U>                                            \
inline bool operator _op_ (const sp<U>& o) const {              \
    return m_ptr _op_ o.m_ptr;                                  \
}                                                               \
template<typename U>                                            \
inline bool operator _op_ (const U* o) const {                  \
    return m_ptr _op_ o;                                        \
}                                                               \


template <typename T>
class sp
{
public:
    inline sp() : m_ptr(0) { }

    sp(T* other);  // NOLINT, implicit
    sp(const sp<T>& other);
    template<typename U> sp(U* other);
    template<typename U> sp(const sp<U>& other);

    ~sp();
    sp& operator = (T* other);
    sp& operator = (const sp<T>& other);

    template<typename U> sp& operator = (const sp<U>& other);
    template<typename U> sp& operator = (U* other);

    inline  T&      operator* () const  { return *m_ptr; }
    inline  T*      operator-> () const { return m_ptr;  }
    inline  T*      get() const         { return m_ptr; }
    // Operators

    COMPARE(==)
    COMPARE(!=)
    COMPARE(>)
    COMPARE(<)
    COMPARE(<=)
    COMPARE(>=)
public:
    T* m_ptr;

};

#undef COMPARE


template<typename T>
sp<T>::sp(T* other)
        : m_ptr(other)
{
    printf("sp<T>::sp(T* other)\n");
    //    if (other) other->incStrong(this);
}

template<typename T>
sp<T>::sp(const sp<T>& other)
        : m_ptr(other.m_ptr)
{
    printf("sp<T>::sp(const sp<T>& other)\n");
    //    if (m_ptr) m_ptr->incStrong(this);
}

template<typename T> template<typename U>
sp<T>::sp(U* other) : m_ptr(other)
{
    printf("sp<T>::sp(U* other)\n");
//    if (other) ((T*)other)->incStrong(this);
}

template<typename T> template<typename U>
sp<T>::sp(const sp<U>& other)
        : m_ptr(other.m_ptr)
{
    printf("sp<T>::sp(const sp<U>& other)\n");
//    if (m_ptr) m_ptr->incStrong(this);
}
template<typename T>
sp<T>::~sp()
{
//    if (m_ptr) m_ptr->decStrong(this);
}

template<typename T>
sp<T>& sp<T>::operator = (const sp<T>& other) {
    printf("sp<T>& sp<T>::operator = (const sp<T>& other)\n");
    T* otherPtr(other.m_ptr);
    if (otherPtr) otherPtr->incStrong(this);
    if (m_ptr) m_ptr->decStrong(this);
    m_ptr = otherPtr;
    return *this;
}

template<typename T>
sp<T>& sp<T>::operator = (T* other)
{
    printf("sp<T>& sp<T>::operator = (T* other)\n");
    if (other) other->incStrong(this);
    if (m_ptr) m_ptr->decStrong(this);
    m_ptr = other;
    return *this;
}

template<typename T> template<typename U>
sp<T>& sp<T>::operator = (const sp<U>& other)
{
    printf("sp<T>& sp<T>::operator = (const sp<U>& other)\n");
    T* otherPtr(other.m_ptr);
    m_ptr = otherPtr;
    return *this;
}

template<typename T> template<typename U>
sp<T>& sp<T>::operator = (U* other)
{
    printf("sp<T>& sp<T>::operator = (U* other)\n");
    m_ptr = other;
    return *this;
}
#endif //UNTITLED1_STRONGPOINTER_H
