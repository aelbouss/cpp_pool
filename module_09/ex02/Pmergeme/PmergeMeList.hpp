#ifndef PMERGEMELIST_HPP
#define PMERGEMELIST_HPP

#include <list>
#include <vector>
#include <cstddef>

class PmergeMeList
{
    private:
        struct Element {
            int value;
            std::list<Element*> defeated;
            Element(int val);
        };
    
        std::list<Element*> _sortingContainer;
        std::list<Element*> _allocationLog;
    
        // Internal engine helpers
        void _recursiveSort(std::list<Element*>& current_stage);
        std::list<size_t> _buildInsertionOrder(size_t pend_size) const;
        void _clearAllocations();
    
        static bool _compareElements(const Element* a, const Element* b);
    
    public:
        PmergeMeList();                                   // Canonical: Default Constructor
        PmergeMeList(const std::list<int>& rawInput);     // Custom Initialization Constructor
        PmergeMeList(const PmergeMeList& other);          // Canonical: Copy Constructor
        PmergeMeList& operator=(const PmergeMeList& rhs); // Canonical: Assignment Operator
        ~PmergeMeList();                                  // Canonical: Destructor
    
        void runSort();
        void printContainer() const;
};

#endif