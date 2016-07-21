#include "SettedGame.h"
#include "mainWindow.h"

using namespace SlaSolGame;

SettedGame::SettedGame(int iBeginNumber, int iModForRandColor, int iModForRandFieldSize) :
	Game(rand() % iModForRandFieldSize + iBeginNumber, rand() % iModForRandColor + iBeginNumber) {}

SettedGame::SettedGame(int iFieldSize, int iColors) : Game(iFieldSize, iColors) {}


void SettedGame::start() {
	clearCounters();
	try {
		SlaSol::mainWindow::display->setStepsLabel(getSteps(), true);
		SlaSol::mainWindow::display->setClicksLeftLabel(getClicks(), true);
		SlaSol::mainWindow::display->setScoreLabel(getScores(), true);

		SlaSol::mainWindow::display->updateGameField(getFieldSize(), getFieldSize());
		SlaSol::mainWindow::display->fillGameField(getColors());
		setClicks(getFieldSize() - 1);

		SlaSol::mainWindow::display->setClicksLeftLabel(getClicks(), false);
		SlaSol::mainWindow::display->setStepsLabel(getSteps(), false);

		SlaSol::mainWindow::display->showGameField();
		SlaSol::mainWindow::display->hideMainMenu();
	}
	catch (System::Exception^ e) {
		System::Windows::Forms::MessageBox::Show(e->Message);
	}
	catch (...) {
		errorMessageWithGui();
	}
}

void SettedGame::end(System::Object^ sender) {
	try {
		incSteps();
		SlaSol::mainWindow::display->setStepsLabel(getSteps(), true);
		decClicks();
		SlaSol::mainWindow::display->setClicksLeftLabel(getClicks(), true);
		addScores(SlaSol::mainWindow::display->changeColorOnRowColumn((cli::safe_cast<System::Windows::Forms::Control^>(sender))));
		SlaSol::mainWindow::display->setScoreLabel(getScores(), true);

		if (checkerFinishRound(SlaSol::mainWindow::display->isOneColor()) != 0) {
			SlaSol::mainWindow::display->hideGameField();
			SlaSol::mainWindow::display->showMainMenu();
			delete this;
		}
	}
	catch (WrongParams& e) {
		e.getMessage();
	}
	catch (System::Exception^ e) {
		System::Windows::Forms::MessageBox::Show(e->Message);
	}
	catch (...) {
		errorMessageWithGui();
	}
}

void SettedGame::win() {
	System::String^ message = L"Поздравляю, вы выиграли!";
	System::String^ caption = L"Игра завершена";
	System::Windows::Forms::MessageBoxButtons buttons = System::Windows::Forms::MessageBoxButtons::OK;
	System::Windows::Forms::MessageBox::Show(message, caption, buttons, System::Windows::Forms::MessageBoxIcon::Exclamation, System::Windows::Forms::MessageBoxDefaultButton::Button1);
}

void SettedGame::loose() {
	System::String^ message = L"Вы проиграли! Возможно повезёт в следующий раз.";
	System::String^ caption = L"Игра завершена";
	System::Windows::Forms::MessageBoxButtons buttons = System::Windows::Forms::MessageBoxButtons::OK;
	System::Windows::Forms::MessageBox::Show(message, caption, buttons, System::Windows::Forms::MessageBoxIcon::Exclamation, System::Windows::Forms::MessageBoxDefaultButton::Button1);
};