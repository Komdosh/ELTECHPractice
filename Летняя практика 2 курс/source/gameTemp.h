#pragma once
#include <vector>
#include <cliext/vector> 
#define MAXLEVEL 15
class Game {
	int steps; //Количество ходов в текущей игре
	int level; //Уровень в текущей игре
	int clicks; //Количество кликов которые остались
	bool campaing;
	int campaignFieldSize[MAXLEVEL] = { 2, 3, 4, 4, 5, 5, 5, 6, 6, 6, 7, 7, 7, 8, 8 };
	int campaignColors[MAXLEVEL] = { 1, 2, 2, 3, 2, 3, 4, 2, 3, 4, 2, 3, 4, 2, 3 };
	int maxLevel;
	int scores;

public:
	Game():steps(0), level(0), maxLevel(MAXLEVEL), scores(0) {}

	int getSteps();
	void setSteps(int count);
	void incSteps(System::Windows::Forms::Label^);
	int getLevel();
	void setLevel(int count);
	void incLevel(System::Windows::Forms::Label^);
	int getClicks();
	void setClicks(int count);
	void decClicks(System::Windows::Forms::Label^);
	bool isCampaign();
	void setCampaign(bool value);
	int getFieldSizeByLevel(int level);
	int getCountColorByLevel(int level);
	int getMaxLevel();
	int getScores();
	void setScores(int value);
	void addScores(System::Windows::Forms::Label^ label, int value);
	void startCampaign(int count);
	void startOnChoose(int count);
	void startRandom(int count);
	void clearCounters();
	void clear(cliext::vector<System::Object^>);
	int checkerFinishRound(System::Windows::Forms::TableLayoutPanel^);

	void win(int);
	};

int changeColorOnRowColumn(System::Windows::Forms::TableLayoutPanel^, System::Windows::Forms::Control^);
void writeLabel(System::Windows::Forms::Label^, int);
System::Windows::Forms::TableLayoutPanel^ createGameField(int row, int col);
void setVisibleVector(cliext::vector<System::Object^> vector, bool value);