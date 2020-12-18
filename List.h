#include <iostream>
using namespace std;

template<class T>
    class Node {
    	public:
	    // Собственно сам указатель на адрес следующего элемента
	    // Если текущий объект является последним звеном, то -
	    // - мы ему будем присваивать значение nullptr, чтобы -
	    // - определять конец списка при проверке на nullptr
	    Node* m_next;
	    // Данные объекта
	    T m_data;
	    Node(const T data = T(), Node* next = nullptr) : 
		m_data(data), m_next(next) { }
	    ~Node(){}
	};

template<class T>
class List
{
public:

    Node<T>* m_head;

    // Удаление одного звена данных указанного адреса
	Node<T>* erase(Node<T>* it);
    void swap(Node<T>* ptr1, Node<T>* ptr2);
    // Возвращает указатель на первый элемент в списке
	Node<T>* begin() const;
	// Возвращает nullptr
	Node<T>* end() const;
	// Возвращает количество элементов в списке
	size_t size() const;
    // Удаляет из списка первый элемент
	void pop_front();
	// Метод добавляющий один элемент в конец списка
	void push_back(const T& data);
	// Метод добавляющий один элемент в конец списка
	void push_front(const T& data);
	// Возвращает true, если список пуст
	bool empty() const;
	// Сращивание списков
	void splice(Node<T>* splistbegin, const bool is_left = true);
	// Очистка списка
	void clear();

	// Вставка нового узла в позицию, после указанного адреса (ptr_pos) \
		 Метод возвращает указатель на следующий элемент после вставленного \
		  ВНИМАНИЕ: Применяйте к итератору it = insert(Node<T>* ptr_pos, const T& data), \
		   если добавляете узел в цикле итерации чтобы сохранить правильную последовательность внешних итераций.
	Node<T>* insert(Node<T>* ptr_pos, const T& data);
	

    List();
    ~List();
};