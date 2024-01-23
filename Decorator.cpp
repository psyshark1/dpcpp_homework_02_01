#include"Decorator.h"

Text::Text()
{
}

void Text::render(const std::string& data) const
{
	std::cout << data;
}

void Text::render(std::string&& data) const
{
	std::cout << data;
}

void Text::render(const std::string& data1, const std::string& data2) const
{
	std::cout << data1 << '>' << data2;
}

Text::~Text()
{
}

DecoratedText::DecoratedText(Text* text) : text_(text) 
{
}

DecoratedText::~DecoratedText()
{
}

void Paragraph::render(const std::string& data) const
{
	std::cout << "<p>";
	text_->render(data);
	std::cout << "</p>";
}

Paragraph::~Paragraph()
{
}

Reversed::Reversed(Text* text) : DecoratedText(text)
{
}

void Reversed::render(std::string&& data) const
{
	//std::string dt = data;
	std::reverse(data.begin(), data.end());
	text_->render(std::move(data));
}

Reversed::~Reversed()
{
}

Link::Link(Text* text) : DecoratedText(text)
{
}

void Link::render(const std::string& data1, const std::string& data2) const
{
	std::cout << "<a href=";
	text_->render(data1,data2);
	std::cout << "</a>";
}

Link::~Link()
{
}