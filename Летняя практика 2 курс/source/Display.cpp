#include "Display.h"
#include "mainWindow.h"
#include "Errors.h"

using namespace SlaSolDisplay;

Display::Display() {}

void Display::addControl(System::Windows::Forms::Control^ control) {
	mainWindow->Controls->Add(control);
}

void Display::showMainMenu() {
	mainMenu.show();
}
void Display::hideMainMenu() {
	mainMenu.hide();
}
void Display::showLevelMenu() {
	levelMenu.show();
}
void Display::hideLevelMenu() {
	levelMenu.hide();
}
void Display::showLevelSetMenu() {
	levelMenu.showLevelSetMenu();
}
void Display::hideLevelSetMenu() {
	levelMenu.hideLevelSetMenu();
}
void Display::showGameField() {
	GameWindow::showGameField();
}
void Display::hideGameField() {
	GameWindow::hideGameField();
}
int Display::getFieldSizeFromLevelMenuDomain() {
	return levelMenu.getFieldSizeFromDomain();
}
int Display::getCountOfColorsFromLevelMenuDomain() {
	return levelMenu.getCountOfColorsFromDomain();
}

void Display::setVisibleVector(cliext::vector<System::Object^> vector, bool value) {
	try {
		for (auto it = vector.begin(); it != vector.end(); ++it) {
			(cli::safe_cast<System::Windows::Forms::Control^>(*it))->Visible = value;
		}
	}
	catch (System::Exception^ e) {
		System::Windows::Forms::MessageBox::Show(e->Message);
	}
	catch (...) {
		errorMessageWithGui();
	}
}
