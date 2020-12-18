#include "List.h"

template<typename T>
List<T>::List() {
    m_head = nullptr;
}

template<typename T>
List<T>::~List() {
    if(begin() != end()) {
		Node<T>* it;					// Временный указатель используемый в качестве итератора 
		it = begin();					// Записываем итератору адрес первого элемента
		while (it->m_next != end()) {	// Проходимся до конца списка
			pop_front();				// Удаляем первый элемент
			it = m_head->m_next;		// Записываем итератору адрес следующего звена
		}
	}
}

template<typename T>
Node<T>* List<T>::erase(Node<T>* it) {

	// Вспомогательный указатель для записи адреса перед удаляемым узлом
	Node<T>* temp = begin();	

	// Вспомогательный указатель для записи адреса \
		 перед temp, для возможности обратной связки списка \
		 после удаления узла из адреса it
	Node<T>* prev = nullptr;	

	// Если адрес удаляемого узла является головой, \
		 то без лишних заморочек удаляем его, заранее \
		 передав в temp адрес на следующий узел списка
	if(it == begin()) {
		temp = it->m_next;
		pop_front();
	}

	// Иначе идём по списку. Ищем позиции до и после \
		 удаляемого узла.
	else {  // Проходимся циклом до тех пор, пока не найдём \
			 адрес перед узлом, который хотим удалить
		while (temp->m_next != it) {
			// Переходим на следующий адрес
			temp = temp->m_next;
			// Если дошли до нужного нам адреса
			if(temp->m_next == it) {
				// Запоминаем адрес перед удаляемым узлом
				prev = temp;
				break; // Выходим из цикла
			}
		}

		// Запоминаем адрес после узла, который хотим удалить
		prev->m_next = it->m_next;

		// Связываем цепочку
		temp = it->m_next;

		// Удаляем узел 
		delete it;
	} 
		
	// Готово!
	return temp; // Возвращаем адрес уже следующего в очереди узла
}

template<typename T>
void List<T>::swap(Node<T>* ptr1, Node<T>* ptr2) {
	Node<T>* temp = ptr1;
	ptr1 = ptr2;
	ptr2 = temp;
}

template<typename T>
Node<T>* List<T>::begin() const{
	return m_head;
}

template<typename T>
Node<T>* List<T>::end() const {
	return nullptr;
}

template<typename T>
size_t List<T>::size() const {
	size_t value = 0;		// Счётчик звеньев списка
	Node<T>* it = begin();	// Временный указатель используемый в качестве итератора
	while(it != end()) {	// Проходимся до конца списка
		it = it->m_next;		// Записываем в итератор адрес следующего звена
		value++;			// Увеличиваем счётчик
	}
	return value;
}

template<typename T>
void List<T>::pop_front() {
	Node<T>* it = begin();	// Временный указатель для хранения адреса на следующий элемент
	if(it != end()) {		// Если список не пуст (если head не указывает на nullptr)
		it = m_head->m_next;	// Переводим указатель на следующий узел
		delete m_head;		// Освобождаем память первого элемента
		m_head = it;			// Превращаем первый элемент в элемент следующего звена, записанного в итератор
	}
}

template<typename T>
void List<T>::push_back(const T& data) {
	if(m_head == end()) {
		m_head = new Node<T>(data);
	}
	else {
		Node<T>* it = m_head;
		while (it->m_next != end()) {
			it = it->m_next;
		}
		it->m_next = new Node<T>(data);
	}
}

template<typename T>
void List<T>::push_front(const T& data) {
	Node<T>* add = new Node<T>(data);
	Node<T>* temp = m_head;
	add->m_next = temp;
	m_head = add;
}

template<typename T>
bool List<T>::empty() const {
	return m_head == end();
}

template<typename T>
void List<T>::splice(Node<T>* splistbegin, const bool is_left) {

	if(m_head == splistbegin) {
		cout << "Warning! The passed argument is itself. \nHead = tail of the snake is prohibited! This will lead to a loop ..." << endl;
	}
	else {
		while (splistbegin != nullptr)
		{
			if(is_left) push_front(splistbegin->m_data);
			else push_back(splistbegin->m_data);
			splistbegin = splistbegin->m_next;
		}
	}
}

template<typename T>
Node<T>* List<T>::insert(Node<T>* ptr_pos, const T& data) {
    if(ptr_pos == begin()) {
    	push_back(data);
    }
    else {
    	Node<T>* follow = ptr_pos->m_next; 
    	Node<T>* add = new Node<T>(data);
        ptr_pos->m_next = add;
    	add->m_next = follow;
		return add;
    }
	return ptr_pos;
}

template<typename T>
void List<T>::clear() {
	pop_front();
	while (m_head != nullptr) {
		m_head = m_head->m_next;
		pop_front();
	}
}
