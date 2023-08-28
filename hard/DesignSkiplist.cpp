#include <clocale>
#include <ctime>
#include <cstdlib>
#include <map>
#include <iostream>
#include <vector>

//
// Created by Danil on 27.08.2023.
//


class Skiplist {
private:

    struct Node {
        int _value;

        explicit Node(int value) noexcept : _value(value) {}
    };

    struct Index {
        Node * _node;
        Index * _right;
        Index * _down;

        Index(Node *node, Index *right, Index *down) : _node(node), _right(right), _down(down) {}
    };

private:
    Index* _head;
    int _level;

public:


    Skiplist() : _level(0), _head(nullptr)
    {
        srand(time(NULL));
    }

    bool search(int target)
    {
        for (Index* i = _head; i != nullptr; i = i->_down)
        {
            for (; i->_right != nullptr && i->_right->_node->_value < target; i = i->_right) {}
            if (i->_right != nullptr && i->_right->_node->_value == target) {
                return true;
            }
        }
        return false;
    }

    void add(int num)
    {
        int randNum = 1;
        for (; randNum <= _level && rand() & 1; ++randNum);

        if (randNum > _level)
        {
            ++_level;
            _head = new Index(new Node(0), nullptr, _head);
        }

        Index* currentVisitedNode = _head;
        Index* lastInsertedNode = nullptr;

        Node * insertedNode = new Node(num);
        for (int i = _level; i > 0; --i)
        {
            for (;
                currentVisitedNode->_right != nullptr && currentVisitedNode->_right->_node->_value < num;
                currentVisitedNode = currentVisitedNode->_right) {}

            if (i <= randNum)
            {
                currentVisitedNode->_right = new Index(insertedNode, currentVisitedNode->_right, nullptr);
                if (lastInsertedNode != nullptr)
                {
                    lastInsertedNode->_down = currentVisitedNode->_right;
                }
                lastInsertedNode = currentVisitedNode->_right;
            }

            currentVisitedNode = currentVisitedNode->_down;
        }
    }

    bool erase(int num)
    {
        Index* indexBeforeDelete = nullptr;
        for (Index* i = _head; i != nullptr; i = i->_down)
        {
            for (; i->_right != nullptr && i->_right->_node->_value < num; i = i->_right) {}
            if (i->_right != nullptr && i->_right->_node->_value == num) {
                indexBeforeDelete = i;
                goto findNeedToDeleteIndex;
            }
        }

        findNeedToDeleteIndex:
        if (indexBeforeDelete == nullptr)
        {
            return false;
        }


        Node* needToDeleteNode = indexBeforeDelete->_right->_node;
        for (Index* needToDelete = indexBeforeDelete->_right;
            needToDelete != nullptr;)
        {
            for (;
                indexBeforeDelete-> _right != needToDelete;
                indexBeforeDelete = indexBeforeDelete->_right) {}

            Index * tmp = needToDelete;
            indexBeforeDelete->_right = needToDelete->_right;
            needToDelete = needToDelete->_down;
            indexBeforeDelete = indexBeforeDelete->_down;
            delete tmp;
        }

        delete needToDeleteNode;
        return true;
    }
};