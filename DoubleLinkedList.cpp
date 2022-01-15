#include "DoubleLinkedList.h"
//  DoubleLinkedList.cpp - Дважды связный список целых чисел - реализация методов класса  
//
#include <iostream>

// Конструктор "по умолчанию" - создание пустого списка - см. Описание класса
// DoubleLinkedList::DoubleLinkedList(): count_(0), head_(nullptr), tail_(nullptr) {  }

// Конструктор "копирования" – создание копии имеющегося списка
DoubleLinkedList::DoubleLinkedList (const DoubleLinkedList & src) {
    insertHead(src.head_->item_);
    Node *node = src.head_;
    for (int i = 0; i < src.count_ - 1 ; ++i) {
        node = node->next_;
        insertTail(node->item_ );
    }
    this->count_ = src.count_;
}

// Вставить сформированный узел в хвост списка
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

// Вставить сформированный узел в начало списка
void DoubleLinkedList::insertHead(Node *x) {   // x->prev_ == nullptr,  x->next_ == nullptr
    x->next_ = head_;
    if (head_ != nullptr) {
        // список был НЕ пуст – новый элемент будет и первым, и последним
        head_->prev_ = x;
    } else {
        // список был пуст – новый элемент будет и первым, и последним
        tail_ = x;
    }
    head_ = x;
    count_++;  // число элементов списка увеличилось
}

// Удаление заданного узла 
void DoubleLinkedList::deleteNode(Node *x) {
    if (x == nullptr) {
        throw ("DoubleLinkedList::deleteNode  - неверно задан адрес удаляемого узла");
    }
    if (x->prev_ != nullptr) {
        // удаляется НЕ голова списка
        (x->prev_)->next_ = x->next_;
    } else {
        // удаляется голова списка,  второй элемент становится первым
        head_ = x->next_;
    }
    if (x->next_ != nullptr) {
        // удаляется НЕ хвост
        (x->next_)->prev_ = x->prev_;
    } else {
        // удаляется хвост
        tail_ = x->prev_;
    }
    delete x;      //
    count_--;     // число элементов списка уменьшилось
}

// Поиск узла (адрес) с заданным значением  
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

// Замена информации узла на новое 
DoubleLinkedList::Node *DoubleLinkedList::replaceNode(DoubleLinkedList::Node *x, int item) {
    if (searchItem(x->item_) == -1)
        return nullptr;
    getSetNode(searchItem(x->item_))->item_ = item;
    return getSetNode(searchItem(item)); // !!!!!
}

// количество элементов списка
//nt DoubleLinkedList::сount()const{ return count_; }

// Доступ к информации головного узла списка
int DoubleLinkedList::headItem() const {
    if (head_ != nullptr) {
        return head_->item_;
    }
    throw ("headItem - список пуст!");
}

int &DoubleLinkedList::headItem() {
    if (head_ != nullptr) {
        return head_->item_;
    }
    throw ("headItem - список пуст!");
}

// Доступ к информации хвостового узла списка
int DoubleLinkedList::tailItem() const {
    if (tail_ != nullptr) {
        return tail_->item_;
    }
    throw ("tailItem - список пуст!");
}

int &DoubleLinkedList::tailItem() {
    if (tail_ != nullptr) {
        return tail_->item_;
    }
    throw ("tailItem - список пуст!");
}

// Вставить элемент в голову списка
void DoubleLinkedList::insertHead(int item) {   // создаем новый элемент списка и добавляем в голову
    insertHead(new Node(item));
}


// Вставить элемент в хвост списка
void DoubleLinkedList::insertTail(int item) {   // создаем новый элемент списка и добавляем в хвост
    insertTail(new Node(item));
}

// Удалить элемент с головы списка
bool DoubleLinkedList::deleteHead() {
    if (head_ == nullptr) {
        return 0;  // список пуст, удалений нет
    }
    deleteNode(head_);
    return 1;      // список был НЕ пуст, удаление головы
}

// Удалить элемент из хвоста списка
bool DoubleLinkedList::deleteTail() {
    if (tail_ == nullptr){
        return 0;
    }
    deleteNode(tail_);
    return 1;
}

// Удаление узла с заданным значением  
bool DoubleLinkedList::deleteItem(const int item) {
    if (searchItem(item) != -1) {
        Node *to_delete = getSetNode(searchNode(item));
        deleteNode(to_delete);
        return 1;
    } else { return 0; }
}

// Поиск записи с заданным значением  
int DoubleLinkedList::searchItem(int item) {   // возвращаем TRUE, если узел найден
    return searchNode(item);
}


// Замена информации узла на новое 
bool DoubleLinkedList::replaceItem(int itemOld, int itemNew) {
    replaceNode(getSetNode(searchItem(itemOld)), itemNew);
    return 0;
}



// Деструктор списка	
DoubleLinkedList::~DoubleLinkedList() {
    Node *current = nullptr;   // указатель на элемент, подлежащий удалению
    Node *next = head_;        // указатель на следующий элемент
    while (next != nullptr) {  // пока есть еще элементы в списке
        current = next;
        next = next->next_;    // переход к следующему элементу
        delete current;        // освобождение памяти
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









