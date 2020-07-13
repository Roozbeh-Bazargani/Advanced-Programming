#include<string>
#include<iostream>
#include <memory>  

Stack<std::shared_ptr<CText>> stack;
string base{"TEXT"};
for(char a{'A'}; a <= 'Z'; a++)
	stack.push(make_shared<CText>(base + a));

//Pop everything out
int N{stack.getCount()};
if (stack.isEmpty())
{
	std::cout << "Stack is empty" << std::endl;
	return -1;
}

for (int i{}; i < N; i++)
	std::cout << stack.pop()->getText() << std::endl;

if (stack.isEmpty())
	std::cout << "Stack is empty" << std::endl;