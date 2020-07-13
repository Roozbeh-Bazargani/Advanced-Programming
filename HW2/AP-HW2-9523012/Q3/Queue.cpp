#include "stdafx.h"
#include "Queue.h"


Queue::Queue(const std::string &s)
{
	std::ifstream myfile(s);
	if (myfile.is_open())
	{
		char ch{};
		myfile >> N;
		p = new double[N];
		while (myfile >> p[cnt++])
		{
			myfile >> ch;
		}
		cnt--;
	}
	else
		std::cout << "Couldn't read the file!\n";
	myfile.close();
}

Queue::~Queue()
{
	delete[] p;
}

void Queue::displayQueue()
{
	for (size_t i{}; i < cnt; i++)
	{
		std::cout << p[(tail + i) % N] << " ";
	}
	std::cout << "\n";
}

void Queue::enQueue(double d)
{
	if (cnt == N)
		std::cout << "Error: List is full\n";
	else
	{
		p[(tail + cnt) % N] = d;
		cnt++;
	}
}

double Queue::deQueue()
{
	cnt--;
	return p[tail++];
}
