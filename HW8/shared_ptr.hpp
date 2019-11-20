//
// Created by Brady Bodily on 11/19/19.
//

#ifndef HW8_SHARED_PTR_HPP
#define HW8_SHARED_PTR_HPP
#include <algorithm>
#include <iostream>

namespace usu
{
    template <typename T>
    class shared_ptr
    {
      protected:
        int* count;
        T* pointer;

      public:
        shared_ptr();
        shared_ptr(T* input_ptr);
        shared_ptr(shared_ptr<T>&& r);
        shared_ptr(const shared_ptr<T>& r);

        T operator*();
        T* operator->();
        shared_ptr& operator=(shared_ptr<T>&& r);
        shared_ptr& operator=(const shared_ptr<T>& r);


        T* get() { return pointer; };
        unsigned int use_count() { return *count; };

        ~shared_ptr();


    };

    ///
    /// Default Constructor
    ///
    /// \tparam T
    template <typename T>
    shared_ptr<T>::shared_ptr()
    {
        pointer = new T();
        count = new int(1);
    }

    /// overloaded constructor
    ///
    /// \tparam T
    /// \param input_ptr
    template <typename T>
    shared_ptr<T>::shared_ptr(T* input_ptr) :
        pointer(input_ptr)
    {
        count = new int(1);
    }


    /// Move Constructor
    ///
    /// \tparam T
    /// \param r
    template <typename T>
    shared_ptr<T>::shared_ptr(shared_ptr<T>&& r)
    {
        this->count = r.count;
        this->pointer = r.pointer;

        r.pointer = nullptr;
        r.count = new int(0);
    }

    /// Move Assignment operator
    ///
    /// \tparam T
    /// \param r
    /// \return
    template <typename T>
    shared_ptr<T>& shared_ptr<T>::operator=(shared_ptr<T>&& r)
    {
        if (this != &r)
        {
            std::swap(this->pointer, r.pointer);

            std::swap(this->count, r.count);
        }
        return *this;
    }

    /// Copy Constructor
    ///
    /// \tparam T
    /// \param r
    template <typename T>
    shared_ptr<T>::shared_ptr(const shared_ptr<T>& r) :
        pointer(r.pointer), count(r.count)
    {
        *count += 1;
    }



    /// Assignment operator
    ///
    /// \tparam T
    /// \param r
    /// \return
    template <typename T>
    shared_ptr<T>& shared_ptr<T>::operator=(const shared_ptr<T>& r)
    {
        this->count = r.count;
        this->pointer = r.pointer;
        *count += 1;
        return *this;
    }



    /// Pointer operator
    ///
    /// \tparam T
    /// \return
    template <typename T>
    T* shared_ptr<T>::operator->()
    {
        return pointer;
    }

    /// Dereference pointer
    ///
    /// \tparam T
    /// \return
    template <typename T>
    T shared_ptr<T>::operator*()
    {
        return *pointer;
    }

    /// Destructor
    ///
    /// \tparam T
    template <typename T>
    shared_ptr<T>::~shared_ptr()
    {
        *count -= 1;
    }

    template <typename T, typename... Args>
    shared_ptr<T> make_shared(Args&&... args)
    {
        return shared_ptr<T>(new T(std::forward<Args>(args)...));
    }





    /////////Second Class //////////////////////
    template <typename T>
    class shared_ptr<T[]>
    {
      protected:
        unsigned int elemnt_count;
        int* count;
        T* pointer;

      public:
        shared_ptr();
        shared_ptr(T* raw_ptr, unsigned int elements);
        shared_ptr(const shared_ptr<T[]>& r);
        shared_ptr(shared_ptr<T[]>&& r);

        shared_ptr& operator=(const shared_ptr<T[]>& r);
        shared_ptr& operator=(shared_ptr<T[]>&& r);
        T& operator[](unsigned int x);

        ~shared_ptr();

        unsigned int use_count() { return *count; };
        unsigned int size() { return elemnt_count; };
    };

    /// Default Constructor
    ///
    /// \tparam T
    template <typename T>
    shared_ptr<T[]>::shared_ptr() :
        elemnt_count(0)
    {
        pointer = new T[0];
        count = new int(1);
    }

    /// Overloaded Constructor
    ///
    /// \tparam T
    /// \param input_ptr
    /// \param elementCount
    template <typename T>
    shared_ptr<T[]>::shared_ptr(T* input_ptr, unsigned int elementCount) :
        pointer(input_ptr), elemnt_count(elementCount)
    {
        count = new int(1);
    }

    /// Copy Constructor
    ///
    /// \tparam T
    /// \param r
    template <typename T>
    shared_ptr<T[]>::shared_ptr(const shared_ptr<T[]>& r) :
        pointer(r.pointer), count(r.count), elemnt_count(r.elemnt_count)
    {
        *count += 1;
    }

    /// Move Constructor
    ///
    /// \tparam T
    /// \param r
    template <typename T>
    shared_ptr<T[]>::shared_ptr(shared_ptr<T[]>&& r)
    {
        this->pointer = r.pointer;
        r.pointer = nullptr;
        this->count = r.count;
        r.count = new int(0);
        this->elemnt_count = r.elemnt_count;
        r.elemnt_count = 0;

    }

    ///Move Assignment Operator
    ///
    /// \tparam T
    /// \param r
    /// \return
    template <typename T>
    shared_ptr<T[]>& shared_ptr<T[]>::operator=(const shared_ptr<T[]>& r)
    {
        this->pointer = r.pointer;

        this->count = r.count;
        this->elemnt_count = r.elemnt_count;
        *count += 1;


        return *this;
    }


    /// Index opperator
    ///
    /// \tparam T
    /// \param x
    /// \return
    template <typename T>
    T& shared_ptr<T[]>::operator[](unsigned int x)
    {
        return this->pointer[x];
    }

    ///Destructor
    ///
    /// \tparam T
    template <typename T>
    shared_ptr<T[]>::~shared_ptr()
    {
        *count -= 1;
        if (!*count && pointer != nullptr)
        {
            delete[] pointer;
        }
    }

    /// Move Assignment operator
    ///
    /// \tparam T
    /// \param r
    /// \return
    template <typename T>
    shared_ptr<T[]>& shared_ptr<T[]>::operator=(shared_ptr<T[]>&& r)
    {
        if (this != &r)
        {
            std::swap(this->pointer, r.pointer);
            std::swap(this->count, r.count);
            std::swap(this->elemnt_count, r.elemnt_count);
        }

        return *this;
    }

    ///
    ///
    /// \tparam T
    /// \tparam T2
    /// \return
    template <typename T, unsigned int T2>
    shared_ptr<T[]> make_shared_array()
    {
        return shared_ptr<T[]>(new T[T2], T2);
    }
} // namespace usu
#endif // HW8_SHARED_PTR_HPP
