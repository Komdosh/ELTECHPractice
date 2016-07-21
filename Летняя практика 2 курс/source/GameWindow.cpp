#include "GameWindow.h"
#include "Errors.h"
#include "mainWindow.h"
#include "Display.h"

using namespace SlaSolDisplay;

GameWindow::GameWindow() {
	initStepsLabel();
	initLevelLabel();
	initClicksLeftLabel();
	initScoreLabel();
	initMenuButton();
	initGameField();
}

void GameWindow::initStepsLabel() {
	try {
		stepsLabel = (gcnew System::Windows::Forms::Label());
		stepsLabel->AutoSize = true;
		stepsLabel->Font = (gcnew System::Drawing::Font(L"Modern No. 20", 13, System::Drawing::FontStyle::Bold, System::Drawing::GraphicsUnit::Point,
			static_cast<System::Byte>(204)));
		stepsLabel->Location = System::Drawing::Point(402, 0);
		stepsLabel->Name = L"stepsLabel";
		stepsLabel->Size = System::Drawing::Size(88, 21);
		stepsLabel->TabIndex = 1;
		stepsLabel->Text = L"Ходов: 0";
		stepsLabel->Visible = false;
		gameVector.push_back(stepsLabel);
		Display::addControl(stepsLabel);
	}
	catch (System::Exception^ e) {
		System::Windows::Forms::MessageBox::Show(e->Message);
	}
	catch (...) {
		errorMessageWithGui();
	}
}

void GameWindow::initLevelLabel() {
	try {
		levelLabel = (gcnew System::Windows::Forms::Label());
		levelLabel->AutoSize = true;
		levelLabel->Font = (gcnew System::Drawing::Font(L"Modern No. 20", 13, System::Drawing::FontStyle::Bold, System::Drawing::GraphicsUnit::Point,
			static_cast<System::Byte>(204)));
		levelLabel->Location = System::Drawing::Point(382, 21);
		levelLabel->Name = L"levelLabel";
		levelLabel->Size = System::Drawing::Size(108, 21);
		levelLabel->TabIndex = 5;
		levelLabel->Text = L"Уровень: 0";
		levelLabel->Visible = false;
		Display::addControl(levelLabel);
		//gameVector.push_back(levelLabel);
	}
	catch (System::Exception^ e) {
		System::Windows::Forms::MessageBox::Show(e->Message);
	}
	catch (...) {
		errorMessageWithGui();
	}
}

void GameWindow::initClicksLeftLabel() {
	try {
		clicksLeftLabel = (gcnew System::Windows::Forms::Label());
		clicksLeftLabel->AutoSize = true;
		clicksLeftLabel->Font = (gcnew System::Drawing::Font(L"Modern No. 20", 13, System::Drawing::FontStyle::Bold, System::Drawing::GraphicsUnit::Point,
			static_cast<System::Byte>(204)));
		clicksLeftLabel->Location = System::Drawing::Point(224, 0);
		clicksLeftLabel->Name = L"clicksLeftLabel";
		clicksLeftLabel->Size = System::Drawing::Size(96, 21);
		clicksLeftLabel->TabIndex = 7;
		clicksLeftLabel->Text = L"Кликов: 0";
		clicksLeftLabel->Visible = false;
		gameVector.push_back(clicksLeftLabel);
		Display::addControl(clicksLeftLabel);
	}
	catch (System::Exception^ e) {
		System::Windows::Forms::MessageBox::Show(e->Message);
	}
	catch (...) {
		errorMessageWithGui();
	}
}

void GameWindow::initScoreLabel() {
	try
	{
		scoreLabel = (gcnew System::Windows::Forms::Label());
		scoreLabel->AutoSize = true;
		scoreLabel->Font = (gcnew System::Drawing::Font(L"Modern No. 20", 13, System::Drawing::FontStyle::Bold, System::Drawing::GraphicsUnit::Point,
			static_cast<System::Byte>(204)));
		scoreLabel->Location = System::Drawing::Point(224, 21);
		scoreLabel->Name = L"scoreLabel";
		scoreLabel->Size = System::Drawing::Size(76, 21);
		scoreLabel->TabIndex = 19;
		scoreLabel->Text = L"Очки: 0";
		scoreLabel->Visible = false;
		gameVector.push_back(scoreLabel);
		Display::addControl(scoreLabel);
	}
	catch (System::Exception^ e) {
		System::Windows::Forms::MessageBox::Show(e->Message);
	}
	catch (...) {
		errorMessageWithGui();
	}
}

void GameWindow::setStepsLabel(int steps, bool visible) {
	stepsLabel->Visible = visible;
	writeLabel(stepsLabel, steps);
}

void GameWindow::setLevelLabel(int level, bool visible) {
	levelLabel->Visible = visible;
	writeLabel(levelLabel, level);
}

void GameWindow::setClicksLeftLabel(int clicks, bool visible) {
	clicksLeftLabel->Visible = visible;
	writeLabel(clicksLeftLabel, clicks);
}

void GameWindow::setScoreLabel(int scores, bool visible) {
	scoreLabel->Visible = visible;
	writeLabel(scoreLabel, scores);
}

void GameWindow::initMenuButton() {
	try {
		menuButton = (gcnew System::Windows::Forms::Button());
		menuButton->BackColor = System::Drawing::Color::MediumSeaGreen;
		menuButton->Cursor = System::Windows::Forms::Cursors::Hand;
		menuButton->FlatAppearance->BorderColor = System::Drawing::Color::Turquoise;
		menuButton->FlatStyle = System::Windows::Forms::FlatStyle::Flat;
		menuButton->Font = (gcnew System::Drawing::Font(L"Modern No. 20", 15,
			static_cast<System::Drawing::FontStyle>((System::Drawing::FontStyle::Bold | System::Drawing::FontStyle::Italic)),
			System::Drawing::GraphicsUnit::Point, static_cast<System::Byte>(0)));
		menuButton->ForeColor = System::Drawing::SystemColors::ControlText;
		menuButton->Location = System::Drawing::Point(-1, 0);
		menuButton->Name = L"menuButton";
		menuButton->Size = System::Drawing::Size(138, 40);
		menuButton->TabIndex = 0;
		menuButton->Text = L"Меню";
		menuButton->UseVisualStyleBackColor = false;
		menuButton->Visible = false;
		gameVector.push_back(menuButton);
		Display::addControl(menuButton);
		menuButton->Click += gcnew System::EventHandler(Display::mainWindow, &SlaSol::mainWindow::newGameButton_Click);

	}
	catch (System::Exception^ e) {
		System::Windows::Forms::MessageBox::Show(e->Message);
	}
	catch (...) {
		errorMessageWithGui();
	}
}

void GameWindow::initGameField() {
	gameField = gcnew System::Windows::Forms::TableLayoutPanel();
	gameVector.push_back(gameField);
	Display::addControl(gameField);
}

void GameWindow::updateGameField(int row, int col) {
	gameField->Controls->Clear();
	gameField->ColumnStyles->Clear();
	gameField->RowStyles->Clear();

	gameField->SuspendLayout();

	float size = (float)100 / col;
	gameField->Size = System::Drawing::Size(370, 370);
	gameField->ColumnCount = col;
	for (int i = 0; i < col; ++i)
		gameField->ColumnStyles->Add((gcnew System::Windows::Forms::ColumnStyle(System::Windows::Forms::SizeType::Percent, size)));
	gameField->Location = System::Drawing::Point(70, 45);
	gameField->Name = L"gameFieldLayout";
	gameField->RowCount = row;
	for (int i = 0; i < row; ++i)
		gameField->RowStyles->Add((gcnew System::Windows::Forms::RowStyle(System::Windows::Forms::SizeType::Percent, size)));
	gameField->TabIndex = 6;
	gameField->ResumeLayout(false);
	gameField->PerformLayout();
}

void GameWindow::showGameField() {
	Display::setVisibleVector(gameVector, true);
}

void GameWindow::hideGameField() {
	Display::setVisibleVector(gameVector, false);
}

void GameWindow::writeLabel(System::Windows::Forms::Label^ label, int value) {
	label->Text = label->Text->Split(L':')[0] + ": " + value;
}

int GameWindow::changeColorOnRowColumn(System::Windows::Forms::Control^ pictureBox) {
	System::Windows::Forms::TableLayoutPanelCellPosition position = gameField->GetPositionFromControl(pictureBox);
	int scores = 0;
	if (position.Column < 0 || position.Row < 0)
		throw WrongParams(position.Column, position.Row);
	for (int i = 0; i < gameField->ColumnCount; ++i) {
		for (int j = 0; j < gameField->RowCount; ++j) {
			if (gameField->GetControlFromPosition(position.Column, j)->BackColor != pictureBox->BackColor)
				scores += 250;
			if (gameField->GetControlFromPosition(j, position.Row)->BackColor != pictureBox->BackColor)
				scores += 250;
			gameField->GetControlFromPosition(position.Column, j)->BackColor = pictureBox->BackColor;
			gameField->GetControlFromPosition(j, position.Row)->BackColor = pictureBox->BackColor;
		}
	}
	if (position.Column > 2 && position.Row > 2 && position.Column < gameField->ColumnCount - 3 && position.Row < gameField->RowCount - 3) {
		int fromWall = gameField->ColumnCount * 0.2;
		if (position.Column > fromWall && position.Row > fromWall && position.Column < gameField->ColumnCount - fromWall
			&& position.Row < gameField->RowCount - fromWall) {
			for (int i = -1; i < 2; i += 2)
				for (int j = -1; j < 2; j += 2) {
					if (gameField->GetControlFromPosition(position.Column + j, position.Row + i)->BackColor != pictureBox->BackColor)
						scores += 250;
					gameField->GetControlFromPosition(position.Column + j, position.Row + i)->BackColor = pictureBox->BackColor;
				}
		}
	}
	if (scores > 4000) return scores * 6;
	if (scores > 2000) return scores * 4;
	if (scores > 500) return scores * 2;
	return scores;
}

void GameWindow::fillGameField(int countOfColors) {
	unsigned int colors[10] = { 0xFF60004D, 0xFF159300, 0xFF0000A3, 0xFF840000, 0xFFE26FA7, 0xFFD3A900,
		0xFFA6BC56,  0xFF00605D,  0xFFA8A8A8, 0xFF0B161E };
	cliext::vector<System::Windows::Forms::Panel^> panelVector;
	int counter = 0;
	bool tableLayoutVisability = gameField->Visible;
	gameField->Visible = false;
	gameField->SuspendLayout();
	for (int i = 0; i < gameField->ColumnCount; ++i) {
		for (int j = 0; j < gameField->RowCount; ++j, ++counter) {
			System::Windows::Forms::Panel^ panel = gcnew System::Windows::Forms::Panel();
			panel->BackColor = System::Drawing::Color::FromArgb(colors[rand() % countOfColors]);
			panel->Location = System::Drawing::Point(3, 3);
			panel->Name = L"Block" + counter;
			panel->Size = System::Drawing::Size(gameField->GetColumnWidths()[0], gameField->GetRowHeights()[0]);
			panel->TabIndex = counter;
			gameField->Controls->Add(panel, i, j);
			panelVector.push_back(panel);
			panel->Click += gcnew System::EventHandler(Display::mainWindow, &SlaSol::mainWindow::block_Click);
		}
	}
	gameField->ResumeLayout(false);
	gameField->PerformLayout();
	gameField->Visible = tableLayoutVisability;
}

bool GameWindow::isOneColor() {
	bool check = true;
	System::Drawing::Color blockColor = gameField->GetControlFromPosition(0, 0)->BackColor;
	for (int i = 0; i < gameField->ColumnCount && check; ++i) {
		for (int j = 0; j < gameField->RowCount && check; ++j) {
			if (blockColor != gameField->GetControlFromPosition(i, j)->BackColor)
				check = false;
		}
	}
	return check;
}