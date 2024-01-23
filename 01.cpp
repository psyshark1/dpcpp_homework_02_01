#include"Decorator.h"

int main()
{
	auto rev = new Reversed(new Text());
	auto link = new Link(new Text());
	rev->render("Hello!");
	std::cout << std::endl;
	link->render("netology.ru", "Hello world");
	return 0;
}
