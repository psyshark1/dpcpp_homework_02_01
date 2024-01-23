#pragma once
#include <iostream>

class Text
{
public:
	Text();
	virtual void render(const std::string& data) const;
	virtual void render(std::string&& data) const;
	virtual void render(const std::string& data1, const std::string& data2) const;
	~Text();

private:

};

class DecoratedText : public Text {
public:
	explicit DecoratedText(Text* text);
	Text* text_;
	~DecoratedText();
};

class Paragraph : public DecoratedText
{
public:
	void render(const std::string& data) const override;
	~Paragraph();

private:

};

class Reversed : public DecoratedText
{
public:
	explicit Reversed(Text* text);
	void render(std::string&& data) const override;
	~Reversed();

private:

};

class Link : public DecoratedText
{
public:
	explicit Link(Text* text);
	void render(const std::string& data1, const std::string& data2) const override;
	~Link();

private:

};