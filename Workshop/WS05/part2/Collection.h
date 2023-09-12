/*
*****************************************************************************
                          Workshop - #5 (P2)
Full Name  : Vincent Le
Student ID#: 131117228
Email      : vle21@myseneca.ca
Section    : NCC
Date       : 06/25/2023

Authenticity Declaration:
I declare this submission is the result of my own work and has not been
shared with any other student or 3rd party content provider. This submitted
piece of work is entirely of my own creation.
*****************************************************************************
*/
#ifndef SDDS_COLLECTION_H_
#define SDDS_COLLECTION_H_
#include <iostream>

namespace sdds
{
    template <typename T>
    class Collection
    {
        std::string Name{};
        T *items{};
        int Size{};
        void (*n_observer)(const Collection<T> &, const T &){};

    public:
        Collection(const std::string &name) { Name = name; }
        ~Collection() {
            delete[]items;
            items=nullptr;
        }
        Collection(const Collection &) = delete;
        Collection &operator=(const Collection &) = delete;
        const std::string &name() const { return Name; }
        size_t size() const { return Size; }
        void setObserver(void (*observer)(const Collection<T> &, const T &))
        {
            n_observer = observer;
        }
        Collection<T> &operator+=(const T &item)
        {
            bool boolean = false;
            for (int i = 0; i < Size; i++)
            {
                if (items[i].title() == item.title())
                {
                    boolean = true;
                }
            }
            if (!boolean)
            {
                
                if (Size == 0)
                {
                    items = new T[++Size];
                    items[0] = item;
                }
                else
                {
                    T *temp = new T[Size];
                    for (int i = 0; i < Size; i++)
                    {
                        temp[i] = items[i];
                    }

                    delete[] items;
                    items = new T[++Size];
                    for (int i = 0; i < Size-1; i++)
                    {
                        items[i] = temp[i];
                    }
                    items[Size - 1] = item;
                    if (n_observer)
                        n_observer(*this, item);
                    delete[]temp;
                }
            }
            
            return *this;
        }
        T &operator[](size_t idx) const
        {
            if (idx >= size())
            {
                std::string err = "Bad index [" + std::to_string(idx) + "]. Collection has [" + std::to_string(size()) + "] items.";
                throw std::out_of_range(err);
            }

            return items[idx];
        }
        T *operator[](const std::string &title) const
        {
            bool boolean=false;
            int index=0;

            for (int i = 0; i < Size ; ++i)
            {
                if (items[i].title() == title)
                {
                    index = i;
                    boolean = true;
                }
            }

            if (!boolean)
            {
                return nullptr;
            }

            return &items[index];
        }
    };
    template <typename T>
    std::ostream &operator<<(std::ostream &os, const Collection<T> &src)
    {
        for (unsigned int i = 0; i < src.size(); ++i)
            os << src[i];

        return os;
    }
}
#endif
