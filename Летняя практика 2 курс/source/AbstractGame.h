#pragma once
namespace SlaSolGame {
	class AbstractGame {

	public:
		virtual int getSteps() = 0;
		virtual void setSteps(int count) = 0;
		virtual void incSteps() = 0;
		virtual int getClicks() = 0;
		virtual void setClicks(int count) = 0;
		virtual void decClicks() = 0;
		virtual int getScores() = 0;
		virtual void setScores(int value) = 0;
		virtual void addScores(int value) = 0;
		virtual int getFieldSize() = 0;
		virtual void setFieldSize(int value) = 0;
		virtual int getColors() = 0;
		virtual void setColors(int value) = 0;
		virtual void clearCounters() = 0;
		virtual int checkerFinishRound(bool check) = 0;
		virtual void win() = 0;
		virtual void loose() = 0;
		virtual void start() = 0;
		virtual void end(System::Object^ sender) = 0;
		virtual ~AbstractGame() {};
	};
}