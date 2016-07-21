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
		caption = L"������!";
		message = L"����������, �� ������ ��������!\n��� ��� ������ ���� ��� �������� �����������.\n" + \
			"�� �������� ������ ��� ����������� �������, ������ �� �������� ������ �Ѩ! \n" + \
			"�������� ����� ������ ����� ������� �� " + (rand() % 20 + 40) + "%\n" + \
			"������ ������� �� " + (rand() % 20 + 30) + "%\n" + \
			"�����������!\n������ �������� ���� ��������� ���? ��������� ������ �������� �����!";
		break;
	case 3:
		caption = L"���";
		message = L"���! �� ������ 3 ������, ����, ������ ��� ������ �� �����.";
		break;
	case 6:
		caption = L"������";
		message = L"������ �� ��� ������ 6 �������? �� ����� ��� ������� ������.";
		break;
	case 9:
		caption = L"�� ������ � ���";
		message = L"���, �� ���������� 9 �������, ����� ��������, ��?";
		break;
	case 12:
		caption = L"��� �����";
		message = L"������, 12 ������� ������, ����� ����� ������������ �� �����������?";
		break;
	default:
		break;
	}

	System::Windows::Forms::MessageBoxButtons buttons = System::Windows::Forms::MessageBoxButtons::OK;
	System::Windows::Forms::MessageBox::Show(message, caption, buttons, System::Windows::Forms::MessageBoxIcon::Exclamation, System::Windows::Forms::MessageBoxDefaultButton::Button1);
}

void Campaign::loose() {
	System::String^ message = "�� ���������!";
	System::String^ caption = "����� ��������!";
	System::Windows::Forms::MessageBoxButtons buttons = System::Windows::Forms::MessageBoxButtons::OK;
	System::Windows::Forms::MessageBox::Show(message, caption, buttons, System::Windows::Forms::MessageBoxIcon::Error, System::Windows::Forms::MessageBoxDefaultButton::Button1);
};