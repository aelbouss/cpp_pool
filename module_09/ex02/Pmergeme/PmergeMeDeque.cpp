#include "PmergeMeDeque.hpp"
#include <iostream>
#include <algorithm>

PmergeMeDeque::Element::Element(int val) : value(val) {}

// Canonical: Default Constructor
PmergeMeDeque::PmergeMeDeque() {}

// Custom Initialization Constructor
PmergeMeDeque::PmergeMeDeque(const std::deque<int>& rawInput) {
    for (size_t i = 0; i < rawInput.size(); ++i) {
        Element* el = new Element(rawInput[i]);
        _sortingContainer.push_back(el);
        _allocationLog.push_back(el);
    }
}

// Canonical: Copy Constructor
PmergeMeDeque::PmergeMeDeque(const PmergeMeDeque& other) {
    *this = other;
}

// Canonical: Assignment Operator
PmergeMeDeque& PmergeMeDeque::operator=(const PmergeMeDeque& rhs) {
    if (this != &rhs) {
        _clearAllocations();
        for (size_t i = 0; i < rhs._sortingContainer.size(); ++i) {
            Element* el = new Element(rhs._sortingContainer[i]->value);
            _sortingContainer.push_back(el);
            _allocationLog.push_back(el);
        }
    }
    return *this;
}

// Canonical: Destructor
PmergeMeDeque::~PmergeMeDeque() {
    _clearAllocations();
}

void PmergeMeDeque::_clearAllocations() {
    for (size_t i = 0; i < _allocationLog.size(); ++i) {
        delete _allocationLog[i];
    }
    _allocationLog.clear();
    _sortingContainer.clear();
}

bool PmergeMeDeque::_compareElements(const Element* a, const Element* b) {
    return a->value < b->value;
}

std::deque<size_t> PmergeMeDeque::_generateJacobsthal(size_t max_len) const {
    std::deque<size_t> jacob;
    if (max_len == 0) return jacob;
    jacob.push_back(1);
    jacob.push_back(3);
    while (jacob.back() < max_len) {
        jacob.push_back(jacob[jacob.size() - 1] + 2 * jacob[jacob.size() - 2]);
    }
    return jacob;
}

std::deque<size_t> PmergeMeDeque::_buildInsertionOrder(size_t pend_size) const {
    std::deque<size_t> order;
    if (pend_size <= 1) return order;

    std::deque<size_t> jacob = _generateJacobsthal(pend_size);
    std::deque<bool> visited(pend_size, false);
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

void PmergeMeDeque::_recursiveSort(std::deque<Element*>& current_stage) {
    if (current_stage.size() <= 1) return;

    Element* straggler = NULL;
    if (current_stage.size() % 2 != 0) {
        straggler = current_stage.back();
        current_stage.pop_back();
    }

    std::deque<Element*> winners_list;
    for (size_t i = 0; i < current_stage.size(); i += 2) {
        Element* first = current_stage[i];
        Element* second = current_stage[i + 1];

        if (first->value > second->value) {
            first->defeated.push_back(second);
            winners_list.push_back(first);
        } else {
            second->defeated.push_back(first);
            winners_list.push_back(second);
        }
    }

    _recursiveSort(winners_list);

    std::deque<Element*> main_chain = winners_list;
    std::deque<Element*> pend;

    for (size_t i = 0; i < main_chain.size(); ++i) {
        Element* winner = main_chain[i];
        Element* loser = winner->defeated.back();
        winner->defeated.pop_back();
        pend.push_back(loser);
    }

    main_chain.insert(main_chain.begin(), pend[0]);
    std::deque<size_t> insertion_indices = _buildInsertionOrder(pend.size());

    for (size_t i = 0; i < insertion_indices.size(); ++i) {
        size_t idx = insertion_indices[i];
        Element* target = pend[idx];

        std::deque<Element*>::iterator search_end = main_chain.end();
        for (std::deque<Element*>::iterator it = main_chain.begin(); it != main_chain.end(); ++it) {
            if (!(*it)->defeated.empty() && (*it)->defeated.back() == target) {
                search_end = it;
                break;
            }
        }

        std::deque<Element*>::iterator insert_pos = std::lower_bound(
            main_chain.begin(), search_end, target, _compareElements
        );
        main_chain.insert(insert_pos, target);
    }

    if (straggler != NULL) {
        std::deque<Element*>::iterator insert_pos = std::lower_bound(
            main_chain.begin(), main_chain.end(), straggler, _compareElements
        );
        main_chain.insert(insert_pos, straggler);
    }

    current_stage = main_chain;
}

void PmergeMeDeque::runSort() {
    _recursiveSort(_sortingContainer);
}

void PmergeMeDeque::printContainer() const {
    for (size_t i = 0; i < _sortingContainer.size(); ++i) {
        std::cout << _sortingContainer[i]->value << " ";
    }
    std::cout << "\n";
}