//
// Created by xshx on 2023/6/5.
// system/core/libutils/include/utils/RefBase.h
//

#ifndef UNTITLED1_REFBASE_H
#define UNTITLED1_REFBASE_H
class RefBase
{
public:
    void            incStrong(const void* id) const;
    void            decStrong(const void* id) const;

    void            forceIncStrong(const void* id) const;

    //! DEBUGGING ONLY: Get current strong ref count.
    int32_t         getStrongCount() const;
};
#endif //UNTITLED1_REFBASE_H
