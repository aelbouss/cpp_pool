#include "PmergeMeDeque.hpp"
#include "PmergeMeList.hpp"

int main(int argc, char** argv)
{
    if (argc < 2) {
        std::cerr << "Error: Provide a sequence of positive integers." << std::endl;
        return 1;
    }

    std::deque<int> rawDeque;
    std::list<int> rawList;

    for (int i = 1; i < argc; ++i) {
        int val = std::atoi(argv[i]);
        if (val < 0) {
            std::cerr << "Error: Only positive integers allowed." << std::endl;
            return 1;
        }
        rawDeque.push_back(val);
        rawList.push_back(val);
    }

    std::cout << "Before:        ";
    for (size_t i = 0; i < rawDeque.size(); ++i) {
        std::cout << rawDeque[i] << " ";
    }
    std::cout << "\n";

    // 1. Time and execute std::deque sorting
    clock_t startDeque = clock();
    PmergeMeDeque sorterDeque(rawDeque);
    sorterDeque.runSort();
    clock_t endDeque = clock();

    // 2. Time and execute std::list sorting
    clock_t startList = clock();
    PmergeMeList sorterList(rawList);
    sorterList.runSort();
    clock_t endList = clock();

    // Verify both containers sorted correctly by printing their contents
    std::cout << "After (Deque): ";
    sorterDeque.printContainer();

    std::cout << "After (List):  ";
    sorterList.printContainer();

    // Calculate execution times in microseconds (us)
    double timeDeque = static_cast<double>(endDeque - startDeque) / CLOCKS_PER_SEC * 1000000;
    double timeList = static_cast<double>(endList - startList) / CLOCKS_PER_SEC * 1000000;

    std::cout << "Time to process a range of " << rawDeque.size() 
              << " elements with std::deque : " << timeDeque << " us\n";
    std::cout << "Time to process a range of " << rawList.size() 
              << " elements with std::list  : " << timeList << " us\n";

    return 0;
}