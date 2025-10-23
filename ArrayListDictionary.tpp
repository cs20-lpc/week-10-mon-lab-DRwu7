template <typename Key, typename Val>
unsigned ArrayListDictionary<Key, Val>::numComps = 0;

template <typename Key, typename Val>
ArrayListDictionary<Key, Val>::ArrayListDictionary(int i)
: list(new ArrayList<Record>(i)) { }

template <typename Key, typename Val>
ArrayListDictionary<Key, Val>::ArrayListDictionary(const ArrayListDictionary<Key, Val>& copyObj) {
    copy(copyObj);
}

template <typename Key, typename Val>
ArrayListDictionary<Key, Val>& ArrayListDictionary<Key, Val>::operator=(const ArrayListDictionary<Key, Val>& rightObj) {
    if (this != &rightObj) {
        clear();
        copy(rightObj);
    }
    return *this;
}

template <typename Key, typename Val>
ArrayListDictionary<Key, Val>::~ArrayListDictionary() {
    delete list;
}
// BRANCH MODIFIED: Binary Search (Iterative)
template <typename Key, typename Val>
Val ArrayListDictionary<Key, Val>::binSearchIter(const Key& target, int left, int right) const {
    while (left <= right) {
        int mid = left + (right - left) / 2; // Avoids potential overflow
        
        // Increment comparison count for the comparison against the middle element
        numComps++;
        if (list->getElement(mid).k == target) {
            // Target found
            return list->getElement(mid).v;
        }
        
        // Use an else-if structure to avoid double-counting numComps
        numComps++;
        if (list->getElement(mid).k < target) {
            // Target is in the right half
            left = mid + 1;
        } else { // list->getElement(mid).k > target
            // Target is in the left half
            right = mid - 1;
        }
    }
    // Search range is exhausted
    throw -1; 
}

// BRANCH MODIFIED: Binary Search (Recursive)
template <typename Key, typename Val>
Val ArrayListDictionary<Key, Val>::binSearchRec(const Key& target, int left, int right) const {
    // Base case 1: Search range is empty (target not found)
    if (left > right) {
        throw -1;
    }
    
    int mid = left + (right - left) / 2; // Avoids potential overflow
    
    // Check if the current middle element matches the target
    numComps++;
    if (list->getElement(mid).k == target) {
        // Base case 2: Target found
        return list->getElement(mid).v;
    }
    
    // Recursive step
    // Use an else-if structure to avoid double-counting numComps
    numComps++;
    if (list->getElement(mid).k < target) {
        // Target is in the right half
        return binSearchRec(target, mid + 1, right);
    } else { // list->getElement(mid).k > target
        // Target is in the left half
        return binSearchRec(target, left, mid - 1);
    }
}

template <typename Key, typename Val>
void ArrayListDictionary<Key, Val>::clear() {
    list->clear();
}

template <typename Key, typename Val>
void ArrayListDictionary<Key, Val>::copy(const ArrayListDictionary<Key, Val>& copyObj) {
    list = new ArrayList<Record>(*copyObj.list);
}
// BRANCH MODIFIED: Find (to select the search algorithm)
template <typename Key, typename Val>
Val ArrayListDictionary<Key, Val>::find(const Key& k) const {
    numComps = 0;
    try {
        return seqSearchIter(k); // <-- Currently set for Sequential Iterative
        // return seqSearchRec(k);
        // return binSearchIter(k, 0, list->getLength() - 1);
        // return binSearchRec(k, 0, list->getLength() - 1);
    }
    catch (...) {
        throw string("find: error, unsuccessful search, target key not found");
    }
}

template <typename Key, typename Val>
unsigned ArrayListDictionary<Key, Val>::getNumComps() {
    return numComps;
}

template <typename Key, typename Val>
void ArrayListDictionary<Key, Val>::insert(const Key& k, const Val& v) {
    list->append(Record(k, v));
}

template <typename Key, typename Val>
void ArrayListDictionary<Key, Val>::remove(const Key& k) {
    bool flag = false;
    for (int i = 0; i < list->getLength(); i++) {
        if (list->getElement(i).k == k) {
            list->remove(i);
            flag = true;
            break;
        }
    }

    if (!flag) {
        throw string("remove: error, unable to find record with matching key to remove");
    }
}

// BRANCH MODIFIED: Sequential Search (Iterative)
template <typename Key, typename Val>
Val ArrayListDictionary<Key, Val>::seqSearchIter(const Key& target) const {
    int length = list->getLength();
    for (int i = 0; i < length; i++) {
        numComps++;
        // Access the key of the Record at index i
        if (list->getElement(i).k == target) {
            // Return the value if the key matches
            return list->getElement(i).v;
        }
    }
    // If loop finishes without a match, throw an exception
    throw -1; 
}

// BRANCH MODIFIED: Sequential Search (Recursive)
template <typename Key, typename Val>
Val ArrayListDictionary<Key, Val>::seqSearchRec(const Key& target, int i) const {
    int length = list->getLength();
    
    // Base case 1: Target not found (index out of bounds)
    if (i >= length) {
        throw -1;
    }
    
    // Increment comparison count and check if the current element matches the target
    numComps++;
    if (list->getElement(i).k == target) {
        // Base case 2: Target found
        return list->getElement(i).v;
    }
    
    // Recursive step: Search the rest of the list
    return seqSearchRec(target, i + 1);
}

template <typename Key, typename Val>
int ArrayListDictionary<Key, Val>::size() const {
    return list->getLength();
}
