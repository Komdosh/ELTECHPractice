#pragma once
class WrongParams {
public:
	int first, second;
	WrongParams(int iFirst, int iSecond) :first(iFirst), second(iSecond) {}
	void getMessage();
};

void errorMessageWithGui();