#include "MainMenu.h"
#include "mainWindow.h"
#include "Display.h"

using namespace SlaSolDisplay;

MainMenu::MainMenu() {
	initCampaignButton();
	initChooseGameButton();
	initRandomGameButton();
	initQuitButton();
}

void MainMenu::initCampaignButton() {
	try {
		campaignButton = (gcnew System::Windows::Forms::Button());
		campaignButton->BackColor = System::Drawing::Color::MediumSeaGreen;
		campaignButton->Cursor = System::Windows::Forms::Cursors::Hand;
		campaignButton->FlatAppearance->BorderColor = System::Drawing::Color::Turquoise;
		campaignButton->FlatStyle = System::Windows::Forms::FlatStyle::Flat;
		campaignButton->Font = (gcnew System::Drawing::Font(L"Modern No. 20", 15,
			static_cast<System::Drawing::FontStyle>((System::Drawing::FontStyle::Bold | System::Drawing::FontStyle::Italic)),
			System::Drawing::GraphicsUnit::Point, static_cast<System::Byte>(0)));
		campaignButton->ForeColor = System::Drawing::SystemColors::ControlText;
		campaignButton->Location = System::Drawing::Point(198, 60);
		campaignButton->Name = L"campaignButton";
		campaignButton->Size = System::Drawing::Size(138, 40);
		campaignButton->TabIndex = 2;
		campaignButton->Text = L"Кампания";
		campaignButton->UseVisualStyleBackColor = false;
		mainMenuVector.push_back(campaignButton);
		Display::addControl(campaignButton);
		campaignButton->Click += gcnew System::EventHandler(Display::mainWindow, &SlaSol::mainWindow::campaignButton_Click);
	}
	catch (System::Exception^ e) {
		System::Windows::Forms::MessageBox::Show(e->Message);
	}
	catch (...) {
		errorMessageWithGui();
	}
}

void MainMenu::initChooseGameButton() {
	try {
		settedGameButton = (gcnew System::Windows::Forms::Button());
		settedGameButton->BackColor = System::Drawing::Color::MediumSeaGreen;
		settedGameButton->Cursor = System::Windows::Forms::Cursors::Hand;
		settedGameButton->FlatAppearance->BorderColor = System::Drawing::Color::Turquoise;
		settedGameButton->FlatStyle = System::Windows::Forms::FlatStyle::Flat;
		settedGameButton->Font = (gcnew System::Drawing::Font(L"Modern No. 20", 15,
			static_cast<System::Drawing::FontStyle>((System::Drawing::FontStyle::Bold | System::Drawing::FontStyle::Italic)),
			System::Drawing::GraphicsUnit::Point, static_cast<System::Byte>(0)));
		settedGameButton->ForeColor = System::Drawing::SystemColors::ControlText;
		settedGameButton->Location = System::Drawing::Point(198, 106);
		settedGameButton->Name = L"chooseGameButton";
		settedGameButton->Size = System::Drawing::Size(138, 40);
		settedGameButton->TabIndex = 4;
		settedGameButton->Text = L"На выбор";
		settedGameButton->UseVisualStyleBackColor = false;
		mainMenuVector.push_back(settedGameButton);
		Display::addControl(settedGameButton);
		settedGameButton->Click += gcnew System::EventHandler(Display::mainWindow, &SlaSol::mainWindow::settedGameButton_Click);
	}
	catch (System::Exception^ e) {
		System::Windows::Forms::MessageBox::Show(e->Message);
	}
	catch (...) {
		errorMessageWithGui();
	}
}

void MainMenu::initRandomGameButton() {
	try {
		randomGameButton = (gcnew System::Windows::Forms::Button());
		randomGameButton->BackColor = System::Drawing::Color::MediumSeaGreen;
		randomGameButton->Cursor = System::Windows::Forms::Cursors::Hand;
		randomGameButton->FlatAppearance->BorderColor = System::Drawing::Color::Turquoise;
		randomGameButton->FlatStyle = System::Windows::Forms::FlatStyle::Flat;
		randomGameButton->Font = (gcnew System::Drawing::Font(L"Modern No. 20", 15,
			static_cast<System::Drawing::FontStyle>((System::Drawing::FontStyle::Bold | System::Drawing::FontStyle::Italic)),
			System::Drawing::GraphicsUnit::Point, static_cast<System::Byte>(0)));
		randomGameButton->ForeColor = System::Drawing::SystemColors::ControlText;
		randomGameButton->Location = System::Drawing::Point(198, 152);
		randomGameButton->Name = L"randomGameButton";
		randomGameButton->Size = System::Drawing::Size(138, 40);
		randomGameButton->TabIndex = 6;
		randomGameButton->Text = L"Случайная";
		randomGameButton->UseVisualStyleBackColor = false;
		mainMenuVector.push_back(randomGameButton);
		Display::addControl(randomGameButton);
		randomGameButton->Click += gcnew System::EventHandler(Display::mainWindow, &SlaSol::mainWindow::randomGameButton_Click);
	}
	catch (System::Exception^ e) {
		System::Windows::Forms::MessageBox::Show(e->Message);
	}
	catch (...) {
		errorMessageWithGui();
	}
}

void MainMenu::initQuitButton() {
	try {
		quitButton = (gcnew System::Windows::Forms::Button());
		quitButton->BackColor = System::Drawing::Color::MediumSeaGreen;
		quitButton->Cursor = System::Windows::Forms::Cursors::Hand;
		quitButton->FlatAppearance->BorderColor = System::Drawing::Color::Turquoise;
		quitButton->FlatStyle = System::Windows::Forms::FlatStyle::Flat;
		quitButton->Font = (gcnew System::Drawing::Font(L"Modern No. 20", 15,
			static_cast<System::Drawing::FontStyle>((System::Drawing::FontStyle::Bold | System::Drawing::FontStyle::Italic)),
			System::Drawing::GraphicsUnit::Point, static_cast<System::Byte>(0)));
		quitButton->ForeColor = System::Drawing::SystemColors::ControlText;
		quitButton->Location = System::Drawing::Point(198, 290);
		quitButton->Name = L"quitButton";
		quitButton->Size = System::Drawing::Size(138, 40);
		quitButton->TabIndex = 3;
		quitButton->Text = L"Выход";
		quitButton->UseVisualStyleBackColor = false;
		mainMenuVector.push_back(quitButton);
		Display::addControl(quitButton);
		quitButton->Click += gcnew System::EventHandler(Display::mainWindow, &SlaSol::mainWindow::quitButton_Click);
	}
	catch (System::Exception^ e) {
		System::Windows::Forms::MessageBox::Show(e->Message);
	}
	catch (...) {
		errorMessageWithGui();
	}
}

void MainMenu::show() {
	Display::setVisibleVector(mainMenuVector, true);
}

void MainMenu::hide() {
	Display::setVisibleVector(mainMenuVector, false);
}
