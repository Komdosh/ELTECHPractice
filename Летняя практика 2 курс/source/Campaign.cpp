#include "Campaign.h"
#include "mainWindow.h"

using namespace SlaSolGame;

Campaign::~Campaign() {
	SlaSol::mainWindow::display->setLevelLabel(0, false);
}

int Campaign::getFieldSizeByLevel(int level) {
	return campaignFieldSize[level];
}

int Campaign::getCountColorByLevel(int level) {
	return campaignColors[level];
}

int Campaign::getMaxLevel() {
	return maxLevel;
}

int Campaign::getLevel() {
	return level;
}

void Campaign::setLevel(int value) {
	level = value;
}

void Campaign::incLevel() {
	++level;
}

void Campaign::start() {
	clearCounters();
	try {
		SlaSol::mainWindow::display->setStepsLabel(getSteps(), true);
		SlaSol::mainWindow::display->setClicksLeftLabel(getClicks(), true);
		SlaSol::mainWindow::display->setScoreLabel(getScores(), true);
		SlaSol::mainWindow::display->setLevelLabel(level, true);
		setFieldSize(campaignFieldSize[level]);
		setColors(campaignColors[level]);
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
void Campaign::end(System::Object^ sender) {
	try {
		incSteps();
		SlaSol::mainWindow::display->setStepsLabel(getSteps(), true);
		decClicks();
		SlaSol::mainWindow::display->setClicksLeftLabel(getClicks(), true);
		addScores(SlaSol::mainWindow::display->changeColorOnRowColumn((cli::safe_cast<System::Windows::Forms::Control^>(sender))));
		SlaSol::mainWindow::display->setScoreLabel(getScores(), true);

		int result = checkerFinishRound(SlaSol::mainWindow::display->isOneColor());
		if (result != 0) {
			if (result > 0) {
				if (level == maxLevel) {
					SlaSol::mainWindow::display->hideGameField();
					SlaSol::mainWindow::display->showMainMenu();
					delete this;
				}
				else {
					addScores(getClicks() * 5000);
					incLevel();
					start();
				}
			}
			else {
				SlaSol::mainWindow::display->hideGameField();
				SlaSol::mainWindow::display->showMainMenu();
				delete this;
			}
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
};

void Campaign::win() {
	if (level != maxLevel && level % 3 != 0 || level == 0)
		return;

	System::String^ message;
	System::String^ caption;

	switch (level)
	{
	case (MAXLEVEL - 1):
		caption = L"ПОБЕДА!";
		message = L"Поздравляю, Вы прошли кампанию!\nВам нет равных ведь эта кампания непроходима.\n" + \
			"Вы одержали победу над беспощадной судьбой, теперь Вы способны делать ВСЁ! \n" + \
			"Параметр вашей личной удачи повышен на " + (rand() % 20 + 40) + "%\n" + \
			"Логика развита на " + (rand() % 20 + 30) + "%\n" + \
			"Поздравляем!\nХотите повысить ваши параметры ещё? Предлагаю пройти кампанию снова!";
		break;
	case 3:
		caption = L"КМБ";
		message = L"Ого! Вы прошли 3 уровня, чтож, дальше так просто не будет.";
		break;
	case 6:
		caption = L"Высоко";
		message = L"Значит Вы уже прошли 6 уровней? Не думаю что осилите дальше.";
		break;
	case 9:
		caption = L"Всё дальше в лес";
		message = L"Так, Вы преодолели 9 уровней, мозги закипают, да?";
		break;
	case 12:
		caption = L"Под землёй";
		message = L"Хорошо, 12 уровней позади, может стоит остановиться на достигнутом?";
		break;
	default:
		break;
	}

	System::Windows::Forms::MessageBoxButtons buttons = System::Windows::Forms::MessageBoxButtons::OK;
	System::Windows::Forms::MessageBox::Show(message, caption, buttons, System::Windows::Forms::MessageBoxIcon::Exclamation, System::Windows::Forms::MessageBoxDefaultButton::Button1);
}

void Campaign::loose() {
	System::String^ message = "Вы проиграли!";
	System::String^ caption = "Раунд закончен!";
	System::Windows::Forms::MessageBoxButtons buttons = System::Windows::Forms::MessageBoxButtons::OK;
	System::Windows::Forms::MessageBox::Show(message, caption, buttons, System::Windows::Forms::MessageBoxIcon::Error, System::Windows::Forms::MessageBoxDefaultButton::Button1);
};