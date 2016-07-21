#include "LevelMenu.h"
#include "mainWindow.h"
#include "Display.h"

using namespace SlaSolDisplay;

LevelSetMenu::LevelSetMenu() {
	initStartSettedGameButton();
	initMainMenuButton();
	initHelpLabelColors();
	initHelpLabelFieldSize();
	initDomainColorsCount();
	initDomainFieldSize();
}

void LevelSetMenu::initStartSettedGameButton() {
	try {
		startSettedGameButton = (gcnew System::Windows::Forms::Button());
		startSettedGameButton->BackColor = System::Drawing::Color::MediumSeaGreen;
		startSettedGameButton->Cursor = System::Windows::Forms::Cursors::Hand;
		startSettedGameButton->FlatAppearance->BorderColor = System::Drawing::Color::Turquoise;
		startSettedGameButton->FlatStyle = System::Windows::Forms::FlatStyle::Flat;
		startSettedGameButton->Font = (gcnew System::Drawing::Font(L"Modern No. 20", 15,
			static_cast<System::Drawing::FontStyle>((System::Drawing::FontStyle::Bold | System::Drawing::FontStyle::Italic)),
			System::Drawing::GraphicsUnit::Point, static_cast<System::Byte>(0)));
		startSettedGameButton->ForeColor = System::Drawing::SystemColors::ControlText;
		startSettedGameButton->Location = System::Drawing::Point(198, 198);
		startSettedGameButton->Name = L"startSettedGameButton";
		startSettedGameButton->Size = System::Drawing::Size(138, 40);
		startSettedGameButton->TabIndex = 18;
		startSettedGameButton->Text = L"Начать";
		startSettedGameButton->UseVisualStyleBackColor = false;
		startSettedGameButton->Visible = false;
		levelSetMenuVector.push_back(startSettedGameButton);
		Display::addControl(startSettedGameButton);
		startSettedGameButton->Click += gcnew System::EventHandler(Display::mainWindow, &SlaSol::mainWindow::startSettedGameButton_Click);
	}
	catch (System::Exception^ e) {
		System::Windows::Forms::MessageBox::Show(e->Message);
	}
	catch (...) {
		errorMessageWithGui();
	}

}

void LevelSetMenu::initMainMenuButton() {
	try {
		mainMenuButton = (gcnew System::Windows::Forms::Button());
		mainMenuButton->BackColor = System::Drawing::Color::MediumSeaGreen;
		mainMenuButton->Cursor = System::Windows::Forms::Cursors::Hand;
		mainMenuButton->FlatAppearance->BorderColor = System::Drawing::Color::Turquoise;
		mainMenuButton->FlatStyle = System::Windows::Forms::FlatStyle::Flat;
		mainMenuButton->Font = (gcnew System::Drawing::Font(L"Modern No. 20", 13,
			static_cast<System::Drawing::FontStyle>((System::Drawing::FontStyle::Bold | System::Drawing::FontStyle::Italic)),
			System::Drawing::GraphicsUnit::Point, static_cast<System::Byte>(0)));
		mainMenuButton->ForeColor = System::Drawing::SystemColors::ControlText;
		mainMenuButton->Location = System::Drawing::Point(198, 244);
		mainMenuButton->Name = L"mainMenuButton";
		mainMenuButton->Size = System::Drawing::Size(138, 40);
		mainMenuButton->TabIndex = 20;
		mainMenuButton->Text = L"Главное меню";
		mainMenuButton->UseVisualStyleBackColor = false;
		mainMenuButton->Visible = false;
		levelSetMenuVector.push_back(mainMenuButton);
		Display::addControl(mainMenuButton);
		mainMenuButton->Click += gcnew System::EventHandler(Display::mainWindow, &SlaSol::mainWindow::mainMenuButton_Click);
	}
	catch (System::Exception^ e) {
		System::Windows::Forms::MessageBox::Show(e->Message);
	}
	catch (...) {
		errorMessageWithGui();
	}
}

void LevelSetMenu::initHelpLabelColors() {
	try {
		helpLabelColors = (gcnew System::Windows::Forms::Label());
		helpLabelColors->AutoSize = true;
		helpLabelColors->Font = (gcnew System::Drawing::Font(L"Modern No. 20", 13, System::Drawing::FontStyle::Bold, System::Drawing::GraphicsUnit::Point,
			static_cast<System::Byte>(204)));
		helpLabelColors->Location = System::Drawing::Point(171, 82);
		helpLabelColors->Name = L"helpLabelColors";
		helpLabelColors->Size = System::Drawing::Size(192, 21);
		helpLabelColors->TabIndex = 13;
		helpLabelColors->Text = L"Количество цветов:";
		helpLabelColors->Visible = false;
		levelSetMenuVector.push_back(helpLabelColors);
		Display::addControl(helpLabelColors);
	}
	catch (System::Exception^ e) {
		System::Windows::Forms::MessageBox::Show(e->Message);
	}
	catch (...) {
		errorMessageWithGui();
	}
}

void LevelSetMenu::initHelpLabelFieldSize() {
	try {
		helpLabelFieldSize = (gcnew System::Windows::Forms::Label());
		helpLabelFieldSize->AutoSize = true;
		helpLabelFieldSize->Font = (gcnew System::Drawing::Font(L"Modern No. 20", 13, System::Drawing::FontStyle::Bold, System::Drawing::GraphicsUnit::Point,
			static_cast<System::Byte>(204)));
		helpLabelFieldSize->Location = System::Drawing::Point(237, 143);
		helpLabelFieldSize->Name = L"helpLabelFieldSize";
		helpLabelFieldSize->Size = System::Drawing::Size(63, 21);
		helpLabelFieldSize->TabIndex = 15;
		helpLabelFieldSize->Text = L"Поле:";
		helpLabelFieldSize->Visible = false;
		levelSetMenuVector.push_back(helpLabelFieldSize);
		Display::addControl(helpLabelFieldSize);
	}
	catch (System::Exception^ e) {
		System::Windows::Forms::MessageBox::Show(e->Message);
	}
	catch (...) {
		errorMessageWithGui();
	}
}

void LevelSetMenu::initDomainColorsCount() {
	try {
		domainColorsCount = (gcnew System::Windows::Forms::DomainUpDown());
		for (int i = 2; i < 11; ++i)
			domainColorsCount->Items->Add(L"" + i);
		domainColorsCount->Location = System::Drawing::Point(207, 120);
		domainColorsCount->Name = L"domainColorsCount";
		domainColorsCount->ReadOnly = true;
		domainColorsCount->SelectedIndex = 0;
		domainColorsCount->Size = System::Drawing::Size(120, 20);
		domainColorsCount->TabIndex = 16;
		domainColorsCount->Text = L"2";
		domainColorsCount->Visible = false;
		levelSetMenuVector.push_back(domainColorsCount);
		Display::addControl(domainColorsCount);
	}
	catch (System::Exception^ e) {
		System::Windows::Forms::MessageBox::Show(e->Message);
	}
	catch (...) {
		errorMessageWithGui();
	}
}

void LevelSetMenu::initDomainFieldSize() {
	try {
		domainFieldSize = (gcnew System::Windows::Forms::DomainUpDown());
		for (int i = 2; i < 21; ++i)
			domainFieldSize->Items->Add(System::Convert::ToString(i + "x" + i));
		domainFieldSize->Location = System::Drawing::Point(207, 167);
		domainFieldSize->Name = L"domainFieldSize";
		domainFieldSize->ReadOnly = true;
		domainFieldSize->SelectedIndex = 0;
		domainFieldSize->Size = System::Drawing::Size(120, 20);
		domainFieldSize->TabIndex = 17;
		domainFieldSize->Visible = false;
		levelSetMenuVector.push_back(domainFieldSize);
		Display::addControl(domainFieldSize);
	}
	catch (System::Exception^ e) {
		System::Windows::Forms::MessageBox::Show(e->Message);
	}
	catch (...) {
		errorMessageWithGui();
	}
}
//**************************************************************************************
LevelMenu::LevelMenu() {
	initLightLevelButton();
	initMiddleLevelButton();
	initHardLevelButton();
	initSetGameButton();
}

void LevelMenu::initLightLevelButton() {
	try {
		lightLevelButton = (gcnew System::Windows::Forms::Button());
		lightLevelButton->BackColor = System::Drawing::Color::MediumSeaGreen;
		lightLevelButton->Cursor = System::Windows::Forms::Cursors::Hand;
		lightLevelButton->FlatAppearance->BorderColor = System::Drawing::Color::Turquoise;
		lightLevelButton->FlatStyle = System::Windows::Forms::FlatStyle::Flat;
		lightLevelButton->Font = (gcnew System::Drawing::Font(L"Modern No. 20", 15,
			static_cast<System::Drawing::FontStyle>((System::Drawing::FontStyle::Bold | System::Drawing::FontStyle::Italic)),
			System::Drawing::GraphicsUnit::Point, static_cast<System::Byte>(0)));
		lightLevelButton->ForeColor = System::Drawing::SystemColors::ControlText;
		lightLevelButton->Location = System::Drawing::Point(198, 60);
		lightLevelButton->Name = L"lightLevelButton";
		lightLevelButton->Size = System::Drawing::Size(138, 40);
		lightLevelButton->TabIndex = 8;
		lightLevelButton->Text = L"Лёгкий";
		lightLevelButton->UseVisualStyleBackColor = false;
		lightLevelButton->Visible = false;
		levelMenuVector.push_back(lightLevelButton);
		Display::addControl(lightLevelButton);
		lightLevelButton->Click += gcnew System::EventHandler(Display::mainWindow, &SlaSol::mainWindow::lightLevelButton_Click);
	}
	catch (System::Exception^ e) {
		System::Windows::Forms::MessageBox::Show(e->Message);
	}
	catch (...) {
		errorMessageWithGui();
	}
}

void LevelMenu::initMiddleLevelButton() {
	try {
		middleLevelButton = (gcnew System::Windows::Forms::Button());
		middleLevelButton->BackColor = System::Drawing::Color::MediumSeaGreen;
		middleLevelButton->Cursor = System::Windows::Forms::Cursors::Hand;
		middleLevelButton->FlatAppearance->BorderColor = System::Drawing::Color::Turquoise;
		middleLevelButton->FlatStyle = System::Windows::Forms::FlatStyle::Flat;
		middleLevelButton->Font = (gcnew System::Drawing::Font(L"Modern No. 20", 15,
			static_cast<System::Drawing::FontStyle>((System::Drawing::FontStyle::Bold | System::Drawing::FontStyle::Italic)),
			System::Drawing::GraphicsUnit::Point, static_cast<System::Byte>(0)));
		middleLevelButton->ForeColor = System::Drawing::SystemColors::ControlText;
		middleLevelButton->Location = System::Drawing::Point(198, 106);
		middleLevelButton->Name = L"middleLevelButton";
		middleLevelButton->Size = System::Drawing::Size(138, 40);
		middleLevelButton->TabIndex = 9;
		middleLevelButton->Text = L"Средний";
		middleLevelButton->UseVisualStyleBackColor = false;
		middleLevelButton->Visible = false;
		levelMenuVector.push_back(middleLevelButton);
		Display::addControl(middleLevelButton);
		middleLevelButton->Click += gcnew System::EventHandler(Display::mainWindow, &SlaSol::mainWindow::middleLevelButton_Click);
	}
	catch (System::Exception^ e) {
		System::Windows::Forms::MessageBox::Show(e->Message);
	}
	catch (...) {
		errorMessageWithGui();
	}
}

void LevelMenu::initHardLevelButton() {
	try {
		hardLevelButton = (gcnew System::Windows::Forms::Button());
		hardLevelButton->BackColor = System::Drawing::Color::MediumSeaGreen;
		hardLevelButton->Cursor = System::Windows::Forms::Cursors::Hand;
		hardLevelButton->FlatAppearance->BorderColor = System::Drawing::Color::Turquoise;
		hardLevelButton->FlatStyle = System::Windows::Forms::FlatStyle::Flat;
		hardLevelButton->Font = (gcnew System::Drawing::Font(L"Modern No. 20", 15,
			static_cast<System::Drawing::FontStyle>((System::Drawing::FontStyle::Bold | System::Drawing::FontStyle::Italic)),
			System::Drawing::GraphicsUnit::Point, static_cast<System::Byte>(0)));
		hardLevelButton->ForeColor = System::Drawing::SystemColors::ControlText;
		hardLevelButton->Location = System::Drawing::Point(198, 152);
		hardLevelButton->Name = L"hardLevelButton";
		hardLevelButton->Size = System::Drawing::Size(138, 40);
		hardLevelButton->TabIndex = 10;
		hardLevelButton->Text = L"Сложный";
		hardLevelButton->UseVisualStyleBackColor = false;
		hardLevelButton->Visible = false;
		levelMenuVector.push_back(hardLevelButton);
		Display::addControl(hardLevelButton);
		hardLevelButton->Click += gcnew System::EventHandler(Display::mainWindow, &SlaSol::mainWindow::hardLevelButton_Click);
	}
	catch (System::Exception^ e) {
		System::Windows::Forms::MessageBox::Show(e->Message);
	}
	catch (...) {
		errorMessageWithGui();
	}
}

void LevelMenu::initSetGameButton() {
	try {
		setGameButton = (gcnew System::Windows::Forms::Button());
		setGameButton->BackColor = System::Drawing::Color::MediumSeaGreen;
		setGameButton->Cursor = System::Windows::Forms::Cursors::Hand;
		setGameButton->FlatAppearance->BorderColor = System::Drawing::Color::Turquoise;
		setGameButton->FlatStyle = System::Windows::Forms::FlatStyle::Flat;
		setGameButton->Font = (gcnew System::Drawing::Font(L"Modern No. 20", 15,
			static_cast<System::Drawing::FontStyle>((System::Drawing::FontStyle::Bold | System::Drawing::FontStyle::Italic)),
			System::Drawing::GraphicsUnit::Point, static_cast<System::Byte>(0)));
		setGameButton->ForeColor = System::Drawing::SystemColors::ControlText;
		setGameButton->Location = System::Drawing::Point(198, 198);
		setGameButton->Name = L"setGameButton";
		setGameButton->Size = System::Drawing::Size(138, 40);
		setGameButton->TabIndex = 11;
		setGameButton->Text = L"Задать";
		setGameButton->UseVisualStyleBackColor = false;
		setGameButton->Visible = false;
		levelMenuVector.push_back(setGameButton);
		levelMenuVector.push_back(mainMenuButton);
		Display::addControl(setGameButton);
		Display::addControl(mainMenuButton);
		setGameButton->Click += gcnew System::EventHandler(Display::mainWindow, &SlaSol::mainWindow::setGameButton_Click);
	}
	catch (System::Exception^ e) {
		System::Windows::Forms::MessageBox::Show(e->Message);
	}
	catch (...) {
		errorMessageWithGui();
	}
}

int SlaSolDisplay::LevelMenu::getFieldSizeFromDomain() {
	return (domainFieldSize->SelectedIndex + 2);
}

int SlaSolDisplay::LevelMenu::getCountOfColorsFromDomain() {
	return (domainColorsCount->SelectedIndex + 2);
}

void LevelMenu::show() {
	Display::setVisibleVector(levelMenuVector, true);
}

void LevelMenu::hide() {
	Display::setVisibleVector(levelMenuVector, false);
}

void LevelMenu::showLevelSetMenu() {
	Display::setVisibleVector(levelSetMenuVector, true);
}
void LevelMenu::hideLevelSetMenu() {
	Display::setVisibleVector(levelSetMenuVector, false);
}
