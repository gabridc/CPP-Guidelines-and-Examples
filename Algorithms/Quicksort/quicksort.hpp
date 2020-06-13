#ifndef QUICKSORT_H
#define QUICKSORT_H
#include <vector>
#include <string>
#include <iostream>
#include <tuple>
typedef std::vector<std::tuple<int, std::string>> TuplesArray;
typedef std::vector<int> VectorInt;
template <class T>
class Quicksort
{

public:
    Quicksort() : pivote_(0){};
    Quicksort(T elements) : pivote_(0), elements_(elements){};
    int pivote_;
    T sort(int first, int last);

private:
    T elements_;
    int partition(int lowIndex, int highIndex);
    int getPivot(int first, int last);
};

template <>
class Quicksort<VectorInt>
{

public:
    Quicksort() : pivote_(0){};
    Quicksort(VectorInt elements) : pivote_(0), elements_(elements){};
    int pivote_;
    VectorInt sort(int first, int last);

private:
    VectorInt elements_;
    int partition(int lowIndex, int highIndex);
    int getPivot(int first, int last);
};

template <>
class Quicksort<TuplesArray>
{

public:
    Quicksort() : pivote_(0){};
    Quicksort(TuplesArray elements) : pivote_(0), elements_(elements)
    {
        for (int i = 0; i < (elements_.size() / 2); i++)
        {
            std::get<1>(elements_[i]) = "-";
        }
    };
    int pivote_;
    TuplesArray sort(int first, int last);

private:
    TuplesArray elements_;
    int partition(int lowIndex, int highIndex);
    int getPivot(int first, int last);
};

#endif