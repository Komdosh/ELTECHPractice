#pragma once
#include <cliext/vector> 
#include "Display.h"
#include "AbstractGame.h"

namespace SlaSolGame {
	class Game : public AbstractGame {
		int steps; //���������� ����� � ������� ����
		int clicks; //���������� ������ ������� ��������
		int scores; //���� � ����
		int fieldSize; //������ �������� ����
		int colors; //���������� ������ ��� ���������

	public:
		Game() :steps(0), scores(0), fieldSize(0), colors(0) {}
		Game(int iFieldSize, int iColors);
		virtual ~Game() {};

		int getSteps();
		void setSteps(int value);
		void incSteps();
		int getClicks();
		void setClicks(int value);
		void decClicks();
		int getScores();
		void setScores(int value);
		void addScores(int value);
		int getFieldSize();
		void setFieldSize(int value);
		int getColors();
		void setColors(int value);

		void clearCounters();
		int checkerFinishRound(bool check);

		virtual void win() = 0;
		virtual void loose() = 0;
		virtual void start() = 0;
		virtual void end(System::Object^ sender) = 0;
	};
}
