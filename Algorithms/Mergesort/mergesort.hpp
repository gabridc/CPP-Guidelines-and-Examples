#ifndef MERGESORT_H
#define MERGESORT_H
#include <vector>
#include <string>
#include <tuple>

typedef std::vector<std::tuple<int, std::string>> TuplesArray;
typedef std::vector<int> VectorInt;
/*
*
* Merge sort es un ordenamiento estable, paraleliza mejor, y es más eficiente manejando medios secuenciales de acceso lento. 
* Merge sort es a menudo la mejor opción para ordenar una lista enlazada: en esta situación es relativamente fácil implementar merge sort de 
* manera que sólo requiera Θ(1) espacio extra, y el mal rendimiento de las listas enlazadas ante el acceso aleatorio hace que otros algoritmos 
* (como quicksort) den un bajo rendimiento, y para otros (como heapsort) sea algo imposible. 
*
*/
template <class T>
class Mergesort
{

public:
    Mergesort();
    Mergesort(T elements) : elements_(elements){};
    T sort(int lowIndex, int highIndex);

private:
    T elements_;
    void merge(int lowIndex, int midIndex, int highIndex);
};

template <>
class Mergesort<TuplesArray>
{

public:
    Mergesort();
    Mergesort(TuplesArray elements) : elements_(elements)
    {
        for (int i = 0; i < (elements_.size() / 2); i++)
        {
            std::get<1>(elements_[i]) = "-";
        }
    };
    TuplesArray sort(int lowIndex, int highIndex);

private:
    TuplesArray elements_;
    void merge(int lowIndex, int midIndex, int highIndex);
};

template <>
class Mergesort<VectorInt>
{

public:
    Mergesort();
    Mergesort(VectorInt elements) : elements_(elements){};
    VectorInt sort(int lowIndex, int highIndex);

private:
    VectorInt elements_;
    void merge(int lowIndex, int midIndex, int highIndex);
};

#endif