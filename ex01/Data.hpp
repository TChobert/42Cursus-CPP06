#pragma once

class Data {

	private:

	int _number;
	char _letter;

	public:

	Data(void);
	~Data(void);
	Data& operator=(const Data& other);

	int getNumber(void);
	char getLetter(void);
	void setLetter(char letter);
	void setNumber(int number);
};
