#include "BTree.hh"

BTree::BTree(int minDegree):
    _minDegree(minDegree),
    _root(BTreeNode(minDegree, true)) {}

void BTree::traverse() {
    if (_root._degree)
        _root.traverse();
}

/*BTreeNode BTree::search(const Word &word) {
    if (_root._degree == 0)
        return _root;
    else
        return _root.search(word);
}*/

void BTree::insert(const Word &word) {
    // If tree is empty
    if (_root._degree == 0) {
        // Allocate memory for root
        _root._words.push_back(word);  // Insert key
        _root._degree = 1;  // Update number of words in root
    }
    else { // If tree is not empty
        // If root is full, then tree grows in height
        if (_root._degree == 2*_minDegree-1)
        {
            // Allocate memory for new root
            BTreeNode s(_minDegree, false);

            // Make old root as child of new root
            s._childs[0] = _root;

            // Split the old root and move 1 key to the new root
            s.splitChild(0, _root);

            // New root has two children now.  Decide which of the
            // two children is going to have new key
            int i = 0;
            if (s._words[0]._word < word._word)
                i++;
            s._childs[i].insertNonFull(word);

            // Change root
            _root = s;
        }
        else  // If root is not full, call insertNonFull for root
            _root.insertNonFull(word);
    }
}
