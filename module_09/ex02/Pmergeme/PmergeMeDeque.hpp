#ifndef PMERGEMEDEQUE_HPP
#define PMERGEMEDEQUE_HPP

#include <deque>
#include <cstddef>
#include <iostream>
#include <cstdlib>
#include <ctime>


class PmergeMeDeque
{
    private:
        struct Element {
            int value;
            std::deque<Element*> defeated;
            Element(int val);
        };

        std::deque<Element*> _sortingContainer;
        std::deque<Element*> _allocationLog;

        // Internal engine helpers
        void _recursiveSort(std::deque<Element*>& current_stage);
        std::deque<size_t> _buildInsertionOrder(size_t pend_size) const;
        std::deque<size_t> _generateJacobsthal(size_t max_len) const;
        void _clearAllocations();

        static bool _compareElements(const Element* a, const Element* b);

    public:
        PmergeMeDeque();                                    // Canonical: Default Constructor
        PmergeMeDeque(const std::deque<int>& rawInput);     // Custom Initialization Constructor
        PmergeMeDeque(const PmergeMeDeque& other);          // Canonical: Copy Constructor
        PmergeMeDeque& operator=(const PmergeMeDeque& rhs); // Canonical: Assignment Operator
        ~PmergeMeDeque();                                   // Canonical: Destructor

        void runSort();
        void printContainer() const;
};

#endif