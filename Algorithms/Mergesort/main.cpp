/* Enunciado:

In this challenge you need to print the string that accompanies each integer in a list sorted by the integers. 
If two strings are associated with the same integer, they must be printed in their original order so your sorting algorithm should be stable. 
There is one other twist. The first half of the strings encountered in the inputs are to be replaced with the character "-".

Insertion Sort and the simple version of Quicksort are stable, but the faster in-place version of Quicksort is not since it scrambles
around elements while sorting. 

In this challenge, you will use counting sort to sort a list while keeping the order of the strings preserved. 

For example, if your inputs are[ [0,a], [1,b], [0, c], [1,d]]
 
you could set up a helper array with three empty arrays as elements. The following shows the insertions:

The result is then printed: -c, -d

More info about the exercise: https://www.hackerrank.com/challenges/countingsort4/problem
*/

#include <iostream>
#include <algorithm>
#include "mergesort.hpp"

int main(void)
{

    std::vector<std::tuple<int, std::string>> ex5 = {{0, "ab"}, {6, "cd"}, {0, "ef"}, {6, "gh"}, {4, "ij"}, {0, "ab"}, {6, "cd"}, {0, "ef"}, {6, "gh"}, {0, "ij"}, 
                              {4, "that"}, {3, "be"}, {0, "to"}, {1, "be"}, {5, "question"}, {1, "or"}, {2, "not"}, {4, "is"}, {2, "to"}, {4, "the"}};
    std::vector<int> array = {0,7, 8,22, 135, 155,  2, 9, 11, 20,3, 3, 5, 14 , 30, 120, 85, 15, 1, 12, 28,5, 16};

    Mergesort<TuplesArray> mergesort = Mergesort<TuplesArray>(ex5);

    ex5 = mergesort.sort(0, ex5.size() - 1);

    std::cout << std::endl << "Sort completed" << std::endl;

    for (auto el : ex5)
    {
        std::cout << std::get<1>(el) << ", ";
    }


    std::sort(array.begin(), array.end());

        for (auto el : array)
    {
        std::cout << (el) << ", ";
    }

    return 0;
}
