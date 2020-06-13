#include "quicksort.hpp"

VectorInt Quicksort<VectorInt>::sort(int first, int last)
{
    pivote_ = elements_[last];

    std::cout << "Pivote: " << pivote_ << " first: " << first << " last: " << last << std::endl;

    if (first < last)
    {
        for (auto el : elements_)
        {
            std::cout << el << ",";
        }
         std::cout << std::endl;
        int middleIndex = partition(first, last);
        sort(first, middleIndex-1);
        sort(middleIndex, last);
    }

    return elements_;
}

TuplesArray Quicksort<TuplesArray>::sort(int first, int last)
{
    pivote_ = std::get<0>(elements_[last]);

    std::cout << "Pivote: " << pivote_ << " first: " << first << " last: " << last << std::endl;

    if (first < last)
    {
        for (auto el : elements_)
        {
            std::cout << std::get<0>(el) << ",";
        }
         std::cout << std::endl;
        int middleIndex = partition(first, last);
        sort(first, middleIndex-1);
        sort(middleIndex, last);
    }

    return elements_;
}

int Quicksort<VectorInt>::partition(int lowIndex, int highIndex)
{
    while (lowIndex < highIndex)
    {
        std::cout << "Particiono" << std::endl;
        while (elements_[lowIndex] < pivote_)
            lowIndex++;
        while (elements_[highIndex] > pivote_)
            highIndex--;
        if (lowIndex < highIndex)
        {
            std::cout << lowIndex << "<=" << highIndex << " Values: " << elements_[lowIndex] << "," << elements_[highIndex] << std::endl;
            int auxElement = elements_[highIndex];
            elements_[highIndex] = elements_[lowIndex];
            elements_[lowIndex] = auxElement;
            lowIndex++;
            highIndex--;
        }
    }


    if( lowIndex == highIndex && elements_[highIndex] < elements_[highIndex-1])
    {
        std::cout << lowIndex << "<=" << highIndex << " Values: " << elements_[lowIndex] << "," << elements_[highIndex] << std::endl;
        int auxElement = elements_[highIndex];
        elements_[highIndex] = elements_[highIndex - 1];
        elements_[highIndex - 1 ] = auxElement;
    }
     std::cout << lowIndex << "<=" << highIndex << std::endl;

    for (auto el : elements_)
    {
        std::cout << el << ",";
    }
             std::cout << std::endl;
    return lowIndex;
}

int Quicksort<TuplesArray>::partition(int lowIndex, int highIndex)
{
    while (lowIndex < highIndex)
    {
        std::cout << "Particiono" << std::endl;
        while (std::get<0>(elements_[lowIndex]) < pivote_)
            lowIndex++;
        while (std::get<0>(elements_[highIndex]) > pivote_)
            highIndex--;
        if (lowIndex < highIndex)
        {
            std::cout << lowIndex << "<=" << highIndex << " Values: " << std::get<1>(elements_[lowIndex]) << "," << std::get<1>(elements_[highIndex]) << std::endl;
            auto auxElement = elements_[highIndex];
            elements_[highIndex] = elements_[lowIndex];
            elements_[lowIndex] = auxElement;
            lowIndex++;
            highIndex--;
        }
    }


    if( lowIndex == highIndex && elements_[highIndex] < elements_[highIndex-1])
    {
        std::cout << lowIndex << "<=" << highIndex << " Values: " << std::get<1>(elements_[lowIndex]) << "," << std::get<1>(elements_[highIndex]) << std::endl;
        auto auxElement = elements_[highIndex];
        elements_[highIndex] = elements_[highIndex - 1];
        elements_[highIndex - 1 ] = auxElement;
    }
     std::cout << lowIndex << "<=" << highIndex << std::endl;

    for (auto el : elements_)
    {
        std::cout << std::get<1>(el) << ",";
    }
             std::cout << std::endl;
    return lowIndex;
}

int Quicksort<VectorInt>::getPivot(int first, int last)
{
    int sum = 0;

    for (int i = first; i < last; i++)
    {
        sum = sum + elements_[i];
    }
    return ((sum / elements_.size()) + 1);
}

int Quicksort<TuplesArray>::getPivot(int first, int last)
{
    int sum = 0;

    for (int i = first; i < last; i++)
    {
        sum = sum + std::get<0>(elements_ [i]);
    }
    return ((sum / elements_.size()) + 1);
}


