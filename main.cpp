//
// Тестовая функция:   проверка методов работы со списком 
//
#include "DoubleLinkedList.h"
#include <iostream>

int main() {
	DoubleLinkedList list;   // Создание пустого списка
	list.insertHead(2);      // Добавление элементов
	list.insertHead(3);
	list.insertHead(1);
	std::cout << list << "\n";       // Печать элементов

	std::cout << ((list.searchItem(1)) != -1?  "1 find" : "1 not find") << std::endl;
	std::cout << ((list.searchItem(8)) != -1? "8 find" : "8 not find") << std::endl;

	DoubleLinkedList  list1(list);  // Копирование списка
	list1.insertHead(4);         // Добавление элемента
	list1.insertHead(5);         // Добавление элемента
	list1.deleteHead();          // Удаление головного
	std::cout << list1 << "\n";
	list1.insertHead(6);
	list1.deleteHead();
	list1.replaceItem(3, 19);
	list1.deleteItem(19);
    std::cout << list1 << "\n";     // Печать результата
	return 0;
}