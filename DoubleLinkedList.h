#ifndef __DOUBLE_LINKED_LIST
#define __DOUBLE_LINKED_LIST

#include <ostream>

//  DoubleLinkedList.h - ������ ������� ������ ����� �����
//
class DoubleLinkedList
{
private:
    // ���  Node ������������ ��� �������� �������� ������, ���������� �� 
    // ��������� � ������� ���� next_ � �������������� � ������� ���� prev_
    struct Node         // ����� ��������������  ������ � ������ DoubleLinkedList
    {
        int item_;        // �������� �������� ������
        Node* next_;      // ��������� �� ��������� ������� ������
        Node* prev_;      // ��������� �� �������������� ������� ������

        // ����������� ��� �������� ������ �������� ������. 
        Node(int item, Node* next = nullptr, Node* prev = nullptr) : item_(item), next_(next), prev_(prev) { }
    };

    int count_;         // ������� ����� ���������
    Node* head_;        // ������ ������� ������
    Node* tail_;        // ��������� ������� ������
    
  // ������ � ��������� ���� ������
    Node* head() const { return head_; }

    // ������ � ���������� ���� ������
    Node* tail() const { return tail_; }

    // ������� �������������� ���� � ����� ������
    void insertTail(Node* x);

    // �������� �������������� ���� � ������ ������
    void insertHead(Node* x); // (int item);

  // �������� ��������� ����
    void deleteNode(Node* x);

    // ����� ���� (�����) � �������� ���������
    int searchNode(int item);

    // ������ ���������� ���� �� �����
    Node* replaceNode(Node* x, int item);

    DoubleLinkedList::Node* getSetNode(int index) ;

public:

    // ����������� "�� ���������" - �������� ������� ������
    DoubleLinkedList() : count_(0), head_(nullptr), tail_(nullptr) {  }

    DoubleLinkedList( DoubleLinkedList&& src)  ;

    // ����������� "�����������" � �������� ����� ���������� ������
    DoubleLinkedList(const DoubleLinkedList& src);

    // ���������� ��������� ������
    int count()const { return count_; }

    // ������ � ���������� ��������� ���� ������
    int headItem() const;
    int& headItem();

    // ������ � ���������� ���������� ���� ������
    int tailItem() const;
    int& tailItem();

    // �������� ������� � ������ ������
    void insertHead(int item);

    // �������� ������� � ����� ������
    void insertTail(int item);

    // ������� ������� � ������ ������
    bool deleteHead();

    // ������� ������� �� ������ ������
    bool deleteTail();

    // �������� ���� � �������� ���������
    bool deleteItem(const int item);

    // ����� ������ � �������� ���������
    int searchItem(int item);

    // ������ ���������� ���� �� �����
    bool replaceItem(int itemOld, int itemNew);

    // ����� ��������� ������ � ��������� ���� � ����������� �������� �����


    int& operator[](int index) const;
    // ���������� ������
    virtual ~DoubleLinkedList();

    friend std::ostream &operator<<(std::ostream &os, const DoubleLinkedList &list);

    DoubleLinkedList& operator=(const DoubleLinkedList& rhs);

    DoubleLinkedList& operator=( DoubleLinkedList&& list);

    void swap(const DoubleLinkedList &rhs);

};
#endif

