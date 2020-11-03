#include <iostream>  

const int SIZE = 10;

class HashMap {

public:
    class Node {
    public:
        Node(int key, int val) : m_key(key),
                                 m_val(val),
                                 m_nextNode(nullptr) {}

        int m_key;
        int m_val;
        Node *m_nextNode;
    };

    struct Bucket {
        int m_idx;
        Node *m_recentNode;
        int m_count;
    };

    HashMap();
    ~HashMap();
    void insert(int key, int val);
    void remove(int key); 

private:
    int hashFunc(int key) { return key % SIZE; }
    Bucket m_hashTable[SIZE] = {};
};

HashMap::HashMap() {
    // m_hashTable = new Bucket[SIZE];
    for (int i = 0; i < SIZE; i++) {
        m_hashTable[i].m_idx = i;
        m_hashTable[i].m_count = 0;
        m_hashTable[i].m_recentNode = nullptr;
    }
}

HashMap::~HashMap() {
}

void HashMap::insert(int key, int val) {
    int hashCode = hashFunc(key);
    Node *newNode = new Node(key, val);

    //new value
    if (m_hashTable[hashCode].m_count == 0) {
        m_hashTable[hashCode].m_recentNode = newNode;
    }
    //already has
    else {
        newNode->m_nextNode = m_hashTable[hashCode].m_recentNode;
        m_hashTable[hashCode].m_recentNode = newNode;
    }
    (m_hashTable[hashCode].m_count)++;
}

void HashMap::remove(int key) {
    int hashCode = hashFunc(key);
    Node* retNode = m_hashTable[hashCode].m_recentNode;

    if (!retNode) {
        std::cout << "no key found" << std::endl;
        return;
    }

    Node* parentNode = retNode;
    while (retNode != nullptr) {
        if (retNode->m_key == key) {
            if (retNode == m_hashTable[hashCode].m_recentNode) {
                m_hashTable[hashCode].m_recentNode = retNode->m_nextNode;
            }
            else {
                parentNode->m_nextNode = retNode->m_nextNode;
            }
            delete retNode;
            retNode = nullptr;
            (m_hashTable[hashCode].m_count)--;
            return;
        }
        parentNode = retNode;
        retNode = retNode->m_nextNode;
    }
    if (!retNode)
        std::cout << "no key fount" << std::endl;
}

int main()
{
    HashMap map;
    map.insert(1, 3);
    map.insert(2, 3);
    map.insert(12, 8);
    map.insert(22, 3);
    map.insert(5, 9);
    map.remove(2);
    map.remove(9);
    map.remove(32);
}