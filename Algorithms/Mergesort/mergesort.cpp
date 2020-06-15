#include "mergesort.hpp"
#include <iostream>

VectorInt Mergesort<VectorInt>::sort(int lowIndex, int highIndex)
{
    std::cout << "LowIndex: " << lowIndex << "HighIndex: " << highIndex << std::endl;
    if (lowIndex < highIndex)
    {
        int midIndex = (highIndex + lowIndex) / 2;
        std::cout << "Mid Index: " << midIndex << std::endl;

        sort(lowIndex, midIndex);
        sort(midIndex + 1, highIndex);
        merge(lowIndex, midIndex, highIndex);
    }
    return elements_;
}

void Mergesort<VectorInt>::merge(int lowIndex, int midIndex, int highIndex)
{
    const int max_size_lowvector = midIndex - lowIndex + 1;
    const int max_size_highvector = highIndex - midIndex;
    std::vector<int> lowVector;
    std::vector<int> highVector;

    std::cout << "Merge" << std::endl;
    std::cout << "LowIndex: " << lowIndex << " MidIndex: " << midIndex << " HighIndex: " << highIndex << std::endl;
    for (int i = 0; i < max_size_lowvector; i++)
    {
        lowVector.push_back(elements_.at(lowIndex + i));
    }

    for (int i = 0; i < max_size_highvector; i++)
    {
        highVector.push_back(elements_.at(midIndex + 1 + i));
    }
    std::cout << std::endl;
    std::cout << "Size Low Vector: " << lowVector.size() << std::endl;
    std::cout << "Size High Vector: " << highVector.size() << std::endl;

    int indexLow = 0;
    int indexHigh = 0;
    int index = lowIndex;

    while (indexLow < max_size_lowvector && indexHigh < max_size_highvector)
    {
        std::cout << "IndexLow: " << indexLow << " Index: " << index << " IndexHigh: " << indexHigh << std::endl;
        std::cout << lowVector.at(indexLow) << " " << highVector.at(indexHigh) << std::endl;
        if (lowVector.at(indexLow) <= highVector.at(indexHigh))
        {
            elements_.at(index) = lowVector.at(indexLow);
            indexLow++;
        }
        else
        {
            elements_.at(index) = highVector.at(indexHigh);
            indexHigh++;
        }
        index++;
    }

    while (indexLow < max_size_lowvector)
    {
        elements_.at(index) = lowVector.at(indexLow);
        indexLow++;
        index++;
    }

    while (indexHigh < max_size_highvector)
    {
        elements_.at(index) = highVector.at(indexHigh);
        indexHigh++;
        index++;
    }
}

TuplesArray Mergesort<TuplesArray>::sort(int lowIndex, int highIndex)
{
    std::cout << "LowIndex: " << lowIndex << "HighIndex: " << highIndex << std::endl;
    if (lowIndex < highIndex)
    {
        int midIndex = (highIndex + lowIndex) / 2;
        std::cout << "Mid Index: " << midIndex << std::endl;

        sort(lowIndex, midIndex);
        sort(midIndex + 1, highIndex);
        merge(lowIndex, midIndex, highIndex);
    }
    return elements_;
}

void Mergesort<TuplesArray>::merge(int lowIndex, int midIndex, int highIndex)
{
    const int max_size_lowvector = midIndex - lowIndex + 1;
    const int max_size_highvector = highIndex - midIndex;
    TuplesArray lowVector;
    TuplesArray highVector;

    std::cout << "Merge" << std::endl;
    std::cout << "LowIndex: " << lowIndex << " MidIndex: " << midIndex << " HighIndex: " << highIndex << std::endl;
    std::cout << "Elements size" << elements_.size() << std::endl;
    for (int i = 0; i < max_size_lowvector; i++)
    {
        std::cout << "Index Low: " << lowIndex + i << std::endl;
        lowVector.push_back(elements_.at(lowIndex + i));
    }

    for (int i = 0; i < max_size_highvector; i++)
    {
        std::cout << "Index High: " << midIndex + 1 + i << std::endl;
        highVector.push_back(elements_.at(midIndex + 1 + i));
    }
    std::cout << std::endl;
    std::cout << "Size Low Vector: " << lowVector.size() << std::endl;
    std::cout << "Size High Vector: " << highVector.size() << std::endl;

    int indexLow = 0;
    int indexHigh = 0;
    int index = lowIndex;

    while (indexLow < max_size_lowvector && indexHigh < max_size_highvector)
    {
        std::cout << "IndexLow: " << indexLow << " Index: " << index << " IndexHigh: " << indexHigh << std::endl;
        std::cout << std::get<0>(lowVector.at(indexLow)) << " " << std::get<0>(highVector.at(indexHigh)) << std::endl;
        if (std::get<0>(lowVector.at(indexLow)) <= std::get<0>(highVector.at(indexHigh)))
        {
            elements_.at(index) = lowVector.at(indexLow);
            indexLow++;
        }
        else
        {
            elements_.at(index) = highVector.at(indexHigh);
            indexHigh++;
        }
        index++;
    }

    while (indexLow < max_size_lowvector)
    {
        elements_.at(index) = lowVector.at(indexLow);
        indexLow++;
        index++;
    }

    while (indexHigh < max_size_highvector)
    {
        elements_.at(index) = highVector.at(indexHigh);
        indexHigh++;
        index++;
    }
}