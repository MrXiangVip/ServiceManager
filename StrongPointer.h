//
// Created by xshx on 2023/6/5.
// system/core/include/utils/StrongPointer.h
//

#ifndef UNTITLED1_STRONGPOINTER_H
#define UNTITLED1_STRONGPOINTER_H
template <typename T>

class sp
{
public:
    inline sp() : m_ptr(nullptr) { }

    sp(T* other);  // NOLINT, implicit
    sp(const sp<T>& other);
    ~sp();
    inline  T*      operator-> () const { return m_ptr;  }

private:
    T* m_ptr;

};

template<typename T>
sp<T>::sp(T* other)
        : m_ptr(other)
{
//    if (other) other->incStrong(this);
}

template<typename T>
sp<T>::sp(const sp<T>& other)
        : m_ptr(other.m_ptr)
{
//    if (m_ptr) m_ptr->incStrong(this);
}

template<typename T>
sp<T>::~sp()
{
//    if (m_ptr) m_ptr->decStrong(this);
}
#endif //UNTITLED1_STRONGPOINTER_H
