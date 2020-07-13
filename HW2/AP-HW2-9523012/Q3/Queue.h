#include<string>
#include<fstream>
#include<iostream>

class Queue
{
public:
	Queue(const std::string&);
	~Queue();
	
	void Queue::displayQueue();
	void Queue::enQueue(double);
	double Queue::deQueue();
private:
	size_t N{}, tail{}, cnt{};
	double *p;
};

