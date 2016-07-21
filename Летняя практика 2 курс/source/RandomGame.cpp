#include "RandomGame.h"
#include "mainWindow.h"

using namespace SlaSolGame;

void RandomGame::start() {
	clearCounters();
	try {
		SlaSol::mainWindow::display->setStepsLabel(getSteps(), true);
		SlaSol::mainWindow::display->setClicksLeftLabel(getClicks(), true);
		SlaSol::mainWindow::display->setScoreLabel(getScores(), true);
		setFieldSize(rand() % 14 + 2);
		setColors(rand() % 10 + 1);
		SlaSol::mainWindow::display->updateGameField(getFieldSize(), getFieldSize());
		setClicks(getFieldSize() - 1);

		SlaSol::mainWindow::display->setClicksLeftLabel(getClicks(), false);
		SlaSol::mainWindow::display->setStepsLabel(getSteps(), false);

		SlaSol::mainWindow::display->showGameField();
		SlaSol::mainWindow::display->hideMainMenu();

		SlaSol::mainWindow::display->fillGameField(getColors());
	}
	catch (System::Exception^ e) {
		System::Windows::Forms::MessageBox::Show(e->Message);
	}
	catch (...) {
		errorMessageWithGui();
	}
};