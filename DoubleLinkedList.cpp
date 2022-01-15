#include "DoubleLinkedList.h"
//  DoubleLinkedList.cpp - ������ ������� ������ ����� ����� - ���������� ������� ������  
//
#include <iostream>

// ����������� "�� ���������" - �������� ������� ������ - ��. �������� ������
// DoubleLinkedList::DoubleLinkedList(): count_(0), head_(nullptr), tail_(nullptr) {  }

// ����������� "�����������" � �������� ����� ���������� ������
DoubleLinkedList::DoubleLinkedList (const DoubleLinkedList & src) {
    insertHead(src.head_->item_);
    Node *node = src.head_;
    for (int i = 0; i < src.count_ - 1 ; ++i) {
        node = node->next_;
        insertTail(node->item_ );
    }
    this->count_ = src.count_;
}

// �������� �������������� ���� � ����� ������
void DoubleLinkedList::insertTail(Node *x) {
    x->prev_ = tail_;
    if (tail_ != nullptr) {
        tail_->next_ = x;
    }else{
        head_ = x;
    }
    tail_ = x;
    count_++;
}

// �������� �������������� ���� � ������ ������
void DoubleLinkedList::insertHead(Node *x) {   // x->prev_ == nullptr,  x->next_ == nullptr
    x->next_ = head_;
    if (head_ != nullptr) {
        // ������ ��� �� ���� � ����� ������� ����� � ������, � ���������
        head_->prev_ = x;
    } else {
        // ������ ��� ���� � ����� ������� ����� � ������, � ���������
        tail_ = x;
    }
    head_ = x;
    count_++;  // ����� ��������� ������ �����������
}

// �������� ��������� ���� 
void DoubleLinkedList::deleteNode(Node *x) {
    if (x == nullptr) {
        throw ("DoubleLinkedList::deleteNode  - ������� ����� ����� ���������� ����");
    }
    if (x->prev_ != nullptr) {
        // ��������� �� ������ ������
        (x->prev_)->next_ = x->next_;
    } else {
        // ��������� ������ ������,  ������ ������� ���������� ������
        head_ = x->next_;
    }
    if (x->next_ != nullptr) {
        // ��������� �� �����
        (x->next_)->prev_ = x->prev_;
    } else {
        // ��������� �����
        tail_ = x->prev_;
    }
    delete x;      //
    count_--;     // ����� ��������� ������ �����������
}

// ����� ���� (�����) � �������� ���������  
int DoubleLinkedList::searchNode(int item) {
    Node *x = head_;
    int count = 0;
    while (x != nullptr) {
        if (x->item_ == item)
            return count;
        x = x->next_;
        count++;
    }
    return -1;
}

// ������ ���������� ���� �� ����� 
DoubleLinkedList::Node *DoubleLinkedList::replaceNode(DoubleLinkedList::Node *x, int item) {
    if (searchItem(x->item_) == -1)
        return nullptr;
    getSetNode(searchItem(x->item_))->item_ = item;
    return getSetNode(searchItem(item)); // !!!!!
}

// ���������� ��������� ������
//nt DoubleLinkedList::�ount()const{ return count_; }

// ������ � ���������� ��������� ���� ������
int DoubleLinkedList::headItem() const {
    if (head_ != nullptr) {
        return head_->item_;
    }
    throw ("headItem - ������ ����!");
}

int &DoubleLinkedList::headItem() {
    if (head_ != nullptr) {
        return head_->item_;
    }
    throw ("headItem - ������ ����!");
}

// ������ � ���������� ���������� ���� ������
int DoubleLinkedList::tailItem() const {
    if (tail_ != nullptr) {
        return tail_->item_;
    }
    throw ("tailItem - ������ ����!");
}

int &DoubleLinkedList::tailItem() {
    if (tail_ != nullptr) {
        return tail_->item_;
    }
    throw ("tailItem - ������ ����!");
}

// �������� ������� � ������ ������
void DoubleLinkedList::insertHead(int item) {   // ������� ����� ������� ������ � ��������� � ������
    insertHead(new Node(item));
}


// �������� ������� � ����� ������
void DoubleLinkedList::insertTail(int item) {   // ������� ����� ������� ������ � ��������� � �����
    insertTail(new Node(item));
}

// ������� ������� � ������ ������
bool DoubleLinkedList::deleteHead() {
    if (head_ == nullptr) {
        return 0;  // ������ ����, �������� ���
    }
    deleteNode(head_);
    return 1;      // ������ ��� �� ����, �������� ������
}

// ������� ������� �� ������ ������
bool DoubleLinkedList::deleteTail() {
    if (tail_ == nullptr){
        return 0;
    }
    deleteNode(tail_);
    return 1;
}

// �������� ���� � �������� ���������  
bool DoubleLinkedList::deleteItem(const int item) {
    if (searchItem(item) != -1) {
        Node *to_delete = getSetNode(searchNode(item));
        deleteNode(to_delete);
        return 1;
    } else { return 0; }
}

// ����� ������ � �������� ���������  
int DoubleLinkedList::searchItem(int item) {   // ���������� TRUE, ���� ���� ������
    return searchNode(item);
}


// ������ ���������� ���� �� ����� 
bool DoubleLinkedList::replaceItem(int itemOld, int itemNew) {
    replaceNode(getSetNode(searchItem(itemOld)), itemNew);
    return 0;
}



// ���������� ������	
DoubleLinkedList::~DoubleLinkedList() {
    Node *current = nullptr;   // ��������� �� �������, ���������� ��������
    Node *next = head_;        // ��������� �� ��������� �������
    while (next != nullptr) {  // ���� ���� ��� �������� � ������
        current = next;
        next = next->next_;    // ������� � ���������� ��������
        delete current;        // ������������ ������
    }
}

int &DoubleLinkedList::operator[](int index) const {
    if (index >= count_ && index < 0)
        throw ("index out of range");
    Node *node = head_;
    for (int i = 0; i < index; ++i) {
        node = node->next_;
    }
    return node->item_;
}

DoubleLinkedList::Node* DoubleLinkedList::getSetNode(int index)  {
    if (index >= count_ && index < 0)
        throw ("index out of range");
    Node *node = head_;
    for (int i = 0; i < index; ++i) {
        node = node->next_;
    }
    return node;
}


std::ostream &operator<<(std::ostream &os, const DoubleLinkedList &list) {
    DoubleLinkedList::Node *node = list.head_;
    while (node != nullptr){
        os << node->item_ << " ";
        node = node->next_;
    }
    return os;
}

DoubleLinkedList& DoubleLinkedList::operator=(const DoubleLinkedList &rhs) {
    if (this->count_ != rhs.count_)
        throw ("lengths of lists dont equal");
    DoubleLinkedList tmp(rhs);
    this->swap(tmp);
    return *this;
}

void DoubleLinkedList::swap(const DoubleLinkedList &rhs){
    Node *node_this;
    node_this = head_;
    Node *node_another;
    node_another = rhs.head_;
    while (node_this){
        node_this->item_ = node_another->item_;
        node_this = node_this->next_;
        node_another = node_another->next_;
    }
}

DoubleLinkedList &DoubleLinkedList::operator=(DoubleLinkedList &&list) {
    this->head_ = list.head_;
    this->tail_ = list.tail_;
    this->count_ = list.count_;
    list.head_ = nullptr;
    list.tail_ = nullptr;
    list.count_ = 0;
    return *this;
}

DoubleLinkedList::DoubleLinkedList(DoubleLinkedList &&src) {
    this->head_ = src.head_;
    this->tail_ = src.tail_;
    this->count_ = src.count_;
    src.head_ = nullptr;
    src.tail_ = nullptr;
    src.count_ = 0;
}









