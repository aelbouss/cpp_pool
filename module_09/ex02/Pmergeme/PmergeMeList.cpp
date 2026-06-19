#include "PmergeMeList.hpp"
#include <iostream>
#include <algorithm>

PmergeMeList::Element::Element(int val) : value(val) {}

// Canonical: Default Constructor
PmergeMeList::PmergeMeList() {}

// Custom Initialization Constructor
PmergeMeList::PmergeMeList(const std::list<int>& rawInput)
{
    for (std::list<int>::const_iterator it = rawInput.begin(); it != rawInput.end(); ++it) {
        Element* el = new Element(*it);
        _sortingContainer.push_back(el);
        _allocationLog.push_back(el);
    }
}

// Canonical: Copy Constructor
PmergeMeList::PmergeMeList(const PmergeMeList& other)
{
    *this = other;
}

// Canonical: Assignment Operator
PmergeMeList& PmergeMeList::operator=(const PmergeMeList& rhs)
{
    if (this != &rhs) {
        _clearAllocations();
        for (std::list<Element*>::const_iterator it = rhs._sortingContainer.begin(); it != rhs._sortingContainer.end(); ++it) {
            Element* el = new Element((*it)->value);
            _sortingContainer.push_back(el);
            _allocationLog.push_back(el);
        }
    }
    return *this;
}

// Canonical: Destructor
PmergeMeList::~PmergeMeList()
{
    _clearAllocations();
}

void PmergeMeList::_clearAllocations()
{
    for (std::list<Element*>::iterator it = _allocationLog.begin(); it != _allocationLog.end(); ++it) {
        delete *it;
    }
    _allocationLog.clear();
    _sortingContainer.clear();
}

bool PmergeMeList::_compareElements(const Element* a, const Element* b)
{
    return a->value < b->value;
}

std::list<size_t> PmergeMeList::_buildInsertionOrder(size_t pend_size) const
{
    std::list<size_t> order;
    if (pend_size <= 1) return order;

    std::vector<size_t> jacob;
    jacob.push_back(1); jacob.push_back(3);
    while (jacob.back() < pend_size) {
        jacob.push_back(jacob[jacob.size() - 1] + 2 * jacob[jacob.size() - 2]);
    }

    std::vector<bool> visited(pend_size, false);
    visited[0] = true;

    for (size_t i = 0; i < jacob.size(); ++i) {
        size_t target_idx = jacob[i] - 1;
        if (target_idx >= pend_size) target_idx = pend_size - 1;

        for (size_t j = target_idx; j > 0; --j) {
            if (!visited[j]) {
                order.push_back(j);
                visited[j] = true;
            }
        }
    }
    return order;
}

void PmergeMeList::_recursiveSort(std::list<Element*>& current_stage)
{
    if (current_stage.size() <= 1) return;

    Element* straggler = NULL;
    if (current_stage.size() % 2 != 0) {
        straggler = current_stage.back();
        current_stage.pop_back();
    }

    std::list<Element*> winners_list;
    std::list<Element*>::iterator it = current_stage.begin();
    while (it != current_stage.end())
    {
        Element* first = *it; ++it;
        Element* second = *it; ++it;

        if (first->value > second->value) {
            first->defeated.push_back(second);
            winners_list.push_back(first);
        } else {
            second->defeated.push_back(first);
            winners_list.push_back(second);
        }
    }
    _recursiveSort(winners_list);

    std::list<Element*> main_chain = winners_list;
    std::list<Element*> pend;

    for (std::list<Element*>::iterator mit = main_chain.begin(); mit != main_chain.end(); ++mit) {
        Element* winner = *mit;
        Element* loser = winner->defeated.back();
        winner->defeated.pop_back();
        pend.push_back(loser);
    }

    main_chain.push_front(pend.front());
    std::list<size_t> insertion_indices = _buildInsertionOrder(pend.size());

    for (std::list<size_t>::iterator iit = insertion_indices.begin(); iit != insertion_indices.end(); ++iit) {
        size_t idx = *iit;
        std::list<Element*>::iterator pit = pend.begin();
        std::advance(pit, idx);
        Element* target = *pit;

        std::list<Element*>::iterator search_end = main_chain.end();
        for (std::list<Element*>::iterator mc_it = main_chain.begin(); mc_it != main_chain.end(); ++mc_it) {
            if (!(*mc_it)->defeated.empty() && (*mc_it)->defeated.back() == target) {
                search_end = mc_it;
                break;
            }
        }

        std::list<Element*>::iterator insert_pos = std::lower_bound(
            main_chain.begin(), search_end, target, _compareElements
        );
        main_chain.insert(insert_pos, target);
    }

    if (straggler != NULL) {
        std::list<Element*>::iterator insert_pos = std::lower_bound(
            main_chain.begin(), main_chain.end(), straggler, _compareElements
        );
        main_chain.insert(insert_pos, straggler);
    }

    current_stage = main_chain;
}

void PmergeMeList::runSort()
{
    _recursiveSort(_sortingContainer);
}

void PmergeMeList::printContainer() const
{
    for (std::list<Element*>::const_iterator it = _sortingContainer.begin(); it != _sortingContainer.end(); ++it) {
        std::cout << (*it)->value << " ";
    }
    std::cout << "\n";
}