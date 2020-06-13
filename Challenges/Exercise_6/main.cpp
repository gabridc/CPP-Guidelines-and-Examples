#include <vector>
#include <chrono>
#include <iostream>
#include "quicksort.hpp"

void printVector(std::vector<int> vector);
void createVectorAllRange(std::vector<int> &vector);
void createVectorWithoutCero(std::vector<int> &vector);
void createVectorAlwaysNeg(std::vector<int> &vector);
void process(std::vector<int> vector);
void processSorting(std::vector<int> vector);
int main(void)

{
    std::vector<int> numeros;
    createVectorAllRange(numeros);
    std::cout << "--------------------------------------------" << std::endl;
    std::cout << "[Numero de elementos: " << numeros.size() << "] Positivos y Negativos Aleatorios Sin Sort" << std::endl;
    process(numeros);
    std::cout << "--------------------------------------------" << std::endl;
    std::cout << "[Numero de elementos: " << numeros.size() << "] Positivos y Negativos Aleatorios Sort" << std::endl;
    processSorting(numeros);

    numeros.clear();
    createVectorWithoutCero(numeros);
    std::cout << "--------------------------------------------" << std::endl;
    std::cout << "[Numero de elementos: " << numeros.size() << "] Positivos y Negativos Sin Cero Sin Sort" << std::endl;
    process(numeros);
    std::cout << "--------------------------------------------" << std::endl;
    std::cout << "[Numero de elementos: " << numeros.size() << "] Positivos y Negativos Sin Cero Sort" << std::endl;
    processSorting(numeros);

    numeros.clear();
    createVectorAlwaysNeg(numeros);
    std::cout << "--------------------------------------------" << std::endl;
    std::cout << "[Numero de elementos: " << numeros.size() << "] Negativos Sin Cero Sin Sort" << std::endl;
    process(numeros);
    std::cout << "--------------------------------------------" << std::endl;
    std::cout << "[Numero de elementos: " << numeros.size() << "] Negativos Sin Cero Sort" << std::endl;    
    processSorting(numeros);

    return 0;
}

void printVector(std::vector<int> vector)
{
    for (int i = 0; i < vector.size(); i++)
    {
        std::cout << vector.at(i) + " ";
    }
}

void createVectorAllRange(std::vector<int> &vector)
{
    int valor = 1;
    for (int i = 0; i < 100000; i++)
    {
        valor = -100 + rand() % (1000 - (-100));
        vector.push_back(valor);
    }
}

void createVectorWithoutCero(std::vector<int> &vector)
{
    int valor = 1;
    for (int i = 0; i < 100000; i++)
    {
        valor = -100 + rand() % (1000 - (-100));
        if (valor != 0)
        {
            vector.push_back(valor);
        }
        else
        {
            vector.push_back(-1);
        }
    }
}

void createVectorAlwaysNeg(std::vector<int> &vector)
{
    int valor = 1;
    for (int i = 0; i < 100000; i++)
    {
        valor = -1000 + rand() % (-1);
        vector.push_back(valor);
    }
}

void process(std::vector<int> vector)
{

    auto start = std::chrono::system_clock::now();

    int negCunt = 0;
    int flagCero = 0;
    int resultado = 0;
    for (int i = 0; (i < vector.size()) && (flagCero == 0); i++)
    {
        if (vector.at(i) == 0)
        {
            flagCero = 1;
        }
        else if (vector.at(i) < 0)
        {
            negCunt++;
        }
    }

    auto end = std::chrono::system_clock::now();

    std::cout << "El tiempo empelado es: " << std::chrono::duration<float, std::milli>(end - start).count() << " s " << std::endl;
    if (flagCero == 1)
    {
        std::cout << "El resultado del conteo es: 0" << std::endl;
    }
    else if (negCunt % 2 == 0)
    {
        std::cout << "El resultado del conteo es: +1" << std::endl;
    }
    else
    {
        std::cout << "El resultado del conteo es: -1" << std::endl;
    }
}

void processSorting(std::vector<int> vector)
{

    auto start = std::chrono::system_clock::now();

    Quicksort<std::vector<int>> quicksort = Quicksort<std::vector<int>>(vector);
    vector = quicksort.sort(0, vector.size());
    int negCunt = 0;
    int flagCero = 0;
    int resultado = 0;
    for (int i = 0; (i < vector.size()) && (flagCero == 0); i++)
    {
        if (vector.at(i) == 0)
        {
            flagCero = 1;
        }
        else if (vector.at(i) < 0)
        {
            negCunt++;
        }
    }

    auto end = std::chrono::system_clock::now();

    std::cout << "El tiempo empelado es: " << std::chrono::duration<float, std::milli>(end - start).count() << " s " << std::endl;
    if (flagCero == 1)
    {
        std::cout << "El resultado del conteo es: 0" << std::endl;
    }
    else if (negCunt % 2 == 0)
    {
        std::cout << "El resultado del conteo es: +1" << std::endl;
    }
    else
    {
        std::cout << "El resultado del conteo es: -1" << std::endl;
    }
}