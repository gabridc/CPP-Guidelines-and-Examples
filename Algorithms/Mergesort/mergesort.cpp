#include "mergesort.hpp"
#include <iostream>

VectorInt Mergesort<VectorInt>::sort(int lowIndex, int highIndex)
{

    if (lowIndex < highIndex)
    {
        int midIndex = (highIndex + lowIndex) / 2;

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

    for (int i = 0; i < max_size_lowvector; i++)
    {
        lowVector.push_back(elements_.at(lowIndex + i));
    }

    for (int i = 0; i < max_size_highvector; i++)
    {
        highVector.push_back(elements_.at(midIndex + 1 + i));
    }

    int indexLow = 0;
    int indexHigh = 0;
    int index = lowIndex;

    while (indexLow < max_size_lowvector && indexHigh < max_size_highvector)
    {
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
    if (lowIndex < highIndex)
    {
        int midIndex = (highIndex + lowIndex) / 2;

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

    for (int i = 0; i < max_size_lowvector; i++)
    {
        lowVector.push_back(elements_.at(lowIndex + i));
    }

    for (int i = 0; i < max_size_highvector; i++)
    {
        highVector.push_back(elements_.at(midIndex + 1 + i));
    }

    int indexLow = 0;
    int indexHigh = 0;
    int index = lowIndex;

    while (indexLow < max_size_lowvector && indexHigh < max_size_highvector)
    {
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