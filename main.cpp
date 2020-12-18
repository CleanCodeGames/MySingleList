#include "Timer/Timer.cpp"
#include "List.cpp"
#include "Data.cpp"
// g++ -o app ./Timer/Timer.cpp List.cpp Data.cpp  main.cpp

template<typename T>
void PrintData(List<T>& lst){
	cout << "***\nShow lst:" << endl;
	cout << "Size lst: " << lst.size() << endl;
	for (auto it = lst.begin(); it != lst.end();) {
		cout << it->m_data.get()<< ": ";
		it = it->m_next;
	}
	if(lst.empty()) {
		cout << "The list is empty!" << endl;
	}
	cout << endl << endl;
}

int main() 
{
	List<Data<int>> lst;

	Timer timer;
	cout << "Add 10 nodes on lst:" << endl;
	for(size_t i = 0; i < 10; i++) lst.push_back(Data<int>(i*3));
	PrintData(lst);
	
	cout << "Remove 6 front elements:" << endl;
	for(size_t i = 0; i < 6; i++) lst.pop_front();
	PrintData(lst);

	cout << "Erase node 24 value:" << endl;
	
	for (auto it = lst.begin(); it != lst.end();) 
	{
		if(it->m_data.get() == 24) 
			it = lst.erase(it);
		else it = it->m_next;
	}
	PrintData(lst);

	cout << "Erase all:" << endl;
	for (auto it = lst.begin(); it != lst.end();)
		it = lst.erase(it);
	PrintData(lst);

	cout << "Add 10 nodes i*100 data value:" << endl;
	for(size_t i = 0; i < 10; i++) lst.push_back(Data<int>(i*100));
	PrintData(lst);

	cout << "Insert data next node adress on argument:" << endl;
	cout << "Insert to data value >= 400:" << endl;
	for (auto it = lst.begin(); it != lst.end();) {
    	if(it->m_data.get() >= 400) {
        	it = lst.insert(it, Data<int>(it->m_data.get() + 99));
    	}
		it = it->m_next;
	}
	PrintData(lst);

	cout << "Push Front 3 Elems:" << endl;
	for(size_t i = 0; i < 3; i++) {
		lst.push_front(Data<int>(777)); 
	}
	PrintData(lst);

	cout << "Create List \"lst2\" and push_front 3 datas 51*i" << endl;
	List<Data<int>> lst2;
	for(size_t i = 0; i < 3; i++) {
		lst2.push_front(Data<int>(51*i));
	}
	PrintData(lst2);
	
	cout << "Splice lst + lst2:" << endl;
	lst.splice(lst2.begin(), false);
	PrintData(lst);

	cout << "Clear lst:" << endl;
	lst.clear();
	PrintData(lst);

	cout << "Clear lst2:" << endl;
	lst2.clear();
	PrintData(lst2);

	return 0;
}