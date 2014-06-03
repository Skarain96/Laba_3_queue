/**
@class queue
@brief  
Класс, реализующий очередь элементов.
@note
Содержит методы добавления элемента в конец очереди, удаления вершины, получения значения вершины и вывода всех элементов очереди на экран.
*/

#include <iostream>
using namespace std;

class queue
{
private:
	class item
	{
	private:
		int info;
	public:
		item* next;
		item(int info_, item* next_)
		{
			this->info = info_;
			this->next = next_;
		}
		~item()
		{
		}
		int get()
		{
			return this->info;
		}
	};
	item* head;
	item* tail;
public:
	queue();
	~queue();
	void push(int a);
	void pop();
	int peek();
	void print();
};

/**
@brief
Конструктор.
*/
queue::queue()
{
	this->head = nullptr;
	this->tail = nullptr;
}

/**
@brief
Деструктор.
*/

queue::~queue()
{
	while (this->head != nullptr)
	{
		this->pop();
	}
}

/**
@brief
Добавление элемента в конец очереди.
@param a
Значение элемента.
*/

void queue::push(int a)
{
	if (this->head != nullptr)
	{
		this->tail->next = new item(a, nullptr);
		this->tail = this->tail->next;
	}
	else
	{
		this->tail = new item(a, nullptr);
		this->head = this->tail;
	}
}

/**
@brief
Удаление элемента из очереди.
@brief  p
Вспомогательный указатель.
*/

void queue::pop()
{
	item* p = this->head;
	this->head = p->next;
	p->~item();
}

/**
@brief
Получение значения первого элемента очереди.
*/

int queue::peek()
{
	return this->head->get();
}

/**
@brief
Вывод очереди на экран.
*/

void queue::print()
{
	while (this->head != nullptr)
	{
		cout << this->peek() << " ";
		this->pop();
	}
}

void main()
{
	int N, ak;
	cin >> N;
	queue A = queue();
	for (int i = 0; i < N; i++)
	{
		cin >> ak;
		A.push(ak);
	}
	A.print();
}