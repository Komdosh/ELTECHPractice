#include "gameTemp.h"
#include "mainWindow.h"
#include <cliext/vector> 
int Game::getSteps() {
	return steps;
}

void Game::setSteps(int count) {
	steps = count;
}

void Game::incSteps(System::Windows::Forms::Label^ label) {
	writeLabel(label, ++steps);
}

int Game::getLevel() {
	return level;
}

void Game::setLevel(int count) {
	level = count;
}

void Game::incLevel(System::Windows::Forms::Label^ label) {
	writeLabel(label, ++level);
}

int Game::getClicks() {
	return clicks;
}
void  Game::setClicks(int count) {
	clicks = count;
}

void  Game::decClicks(System::Windows::Forms::Label^ label) {
	writeLabel(label, --clicks);
}

bool Game::isCampaign() {
	return campaing;
}
void Game::setCampaign(bool value) {
	campaing = value;
}

int Game::getFieldSizeByLevel(int level) {
	return campaignFieldSize[level];
}

int Game::getCountColorByLevel(int level) {
	return campaignColors[level];
}

int Game::getMaxLevel() {
	return maxLevel;
}

int Game::getScores() {
	return scores;
}

void Game::setScores(int value) {
	scores = value;
}

void Game::addScores(System::Windows::Forms::Label^ label, int value) {
	scores += value;
	writeLabel(label, scores);
}

void Game::clearCounters() {
	level = 0;
	steps = 0;
	scores = 0;
	clicks = 0;
}

void Game::clear(cliext::vector<System::Object^> labels) {
	clearCounters();
	for (auto it = labels.begin(); it != labels.end(); ++it) {
		if ((*it)->GetType()->ToString() == "System.Windows.Forms.Label") {
			writeLabel((cli::safe_cast<System::Windows::Forms::Label^>(*it)), 0);
		}
	}
}

void Game::startCampaign(int count) {
	clearCounters();
	clicks = count;
}


void Game::startOnChoose(int count) {
	clearCounters();
	clicks = count;
}

void Game::startRandom(int count) {
	clearCounters();
	clicks = count;
}

int Game::checkerFinishRound(System::Windows::Forms::TableLayoutPanel^ tableLayout) {
	
	int check = 2;
	System::Drawing::Color block = tableLayout->GetControlFromPosition(0, 0)->BackColor;
	for (int i = 0; i < tableLayout->ColumnCount && check; ++i) {
		for (int j = 0; j < tableLayout->RowCount && check; ++j) {
			if (block != tableLayout->GetControlFromPosition(i, j)->BackColor)
				check = 0;
		}
	}
	if (check) {
		if (!isCampaign()) {
			System::String^ message = "Вы выиграли!";
			System::String^ caption = "Раунд закончен!";
			System::Windows::Forms::MessageBoxButtons buttons = System::Windows::Forms::MessageBoxButtons::OK;
			System::Windows::Forms::MessageBox::Show(message, caption, buttons, System::Windows::Forms::MessageBoxIcon::None, System::Windows::Forms::MessageBoxDefaultButton::Button1);
		}
		return check;
	}
	if (clicks == 0) {
		System::String^ message = "Вы проиграли!";
		System::String^ caption = "Раунд закончен!";
		System::Windows::Forms::MessageBoxButtons buttons = System::Windows::Forms::MessageBoxButtons::OK;
		System::Windows::Forms::MessageBox::Show(message, caption, buttons, System::Windows::Forms::MessageBoxIcon::Error, System::Windows::Forms::MessageBoxDefaultButton::Button1);
		return 1;
	}
	return check;
}

void Game::win(int level) {

	if (level != MAXLEVEL && level % 3 != 0 || level == 0)
		return;
	System::String^ message;
	System::String^ caption;
	switch (level)
	{
	case MAXLEVEL:
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



void writeLabel(System::Windows::Forms::Label^ label, int count) {
	label->Text = label->Text->Split(L':')[0] + ": " + count;
}


int changeColorOnRowColumn(System::Windows::Forms::TableLayoutPanel^ tableLayout, System::Windows::Forms::Control^ pictureBox) {
	System::Windows::Forms::TableLayoutPanelCellPosition position = tableLayout->GetPositionFromControl(pictureBox);
	int scores = 0;
	if (position.Column < 0 || position.Row < 0)
		throw WrongParams(position.Column, position.Row);
	for (int i = 0; i < tableLayout->ColumnCount; ++i) {
		for (int j = 0; j < tableLayout->RowCount; ++j) {
			if (tableLayout->GetControlFromPosition(position.Column, j)->BackColor != pictureBox->BackColor)
				scores += 250;
			if (tableLayout->GetControlFromPosition(j, position.Row)->BackColor != pictureBox->BackColor)
				scores += 250;
			tableLayout->GetControlFromPosition(position.Column, j)->BackColor = pictureBox->BackColor;
			tableLayout->GetControlFromPosition(j, position.Row)->BackColor = pictureBox->BackColor;
		}
	}
	if (position.Column > 2 && position.Row > 2 && position.Column < tableLayout->ColumnCount - 3 && position.Row < tableLayout->RowCount - 3) {
		int fromWall = tableLayout->ColumnCount * 0.2;
		if (position.Column > fromWall && position.Row > fromWall && position.Column < tableLayout->ColumnCount - fromWall
			&& position.Row < tableLayout->RowCount - fromWall) {
			if (tableLayout->GetControlFromPosition(position.Column - 1, position.Row - 1)->BackColor != pictureBox->BackColor)
				scores += 250;
			if (tableLayout->GetControlFromPosition(position.Column - 1, position.Row + 1)->BackColor != pictureBox->BackColor)
				scores += 250;
			if (tableLayout->GetControlFromPosition(position.Column + 1, position.Row - 1)->BackColor != pictureBox->BackColor)
				scores += 250;
			if (tableLayout->GetControlFromPosition(position.Column + 1, position.Row + 1)->BackColor != pictureBox->BackColor)
				scores += 250;
			tableLayout->GetControlFromPosition(position.Column - 1, position.Row - 1)->BackColor = pictureBox->BackColor;
			tableLayout->GetControlFromPosition(position.Column - 1, position.Row + 1)->BackColor = pictureBox->BackColor;
			tableLayout->GetControlFromPosition(position.Column + 1, position.Row - 1)->BackColor = pictureBox->BackColor;
			tableLayout->GetControlFromPosition(position.Column + 1, position.Row + 1)->BackColor = pictureBox->BackColor;
		}
	}
	if (scores > 2000)
		return scores * 6;
	if (scores > 1000)
		return scores * 4;
	if (scores > 500)
		return scores * 2;
	return scores;
}

System::Windows::Forms::TableLayoutPanel^ createGameField(int row, int col){
	System::Windows::Forms::TableLayoutPanel^  gameFieldLayout = gcnew System::Windows::Forms::TableLayoutPanel();
	float size = (float)100 / col;
	gameFieldLayout->ColumnCount = col;
	for(int i = 0; i<col; ++i)
		gameFieldLayout->ColumnStyles->Add((gcnew System::Windows::Forms::ColumnStyle(System::Windows::Forms::SizeType::Percent,
			size)));
	size = (float)100 / row;
	gameFieldLayout->Location = System::Drawing::Point(70, 45);
	gameFieldLayout->Name = L"gameFieldLayout";
	gameFieldLayout->RowCount = row;
	for (int i = 0; i<row; ++i)
		gameFieldLayout->RowStyles->Add((gcnew System::Windows::Forms::RowStyle(System::Windows::Forms::SizeType::Percent, size)));
	gameFieldLayout->Size = System::Drawing::Size(380, 380);
	gameFieldLayout->TabIndex = 6;
	gameFieldLayout->Visible = false;

	return gameFieldLayout;
}
void setVisibleVector(cliext::vector<System::Object^> vector, bool value) {
	for (auto it = vector.begin(); it != vector.end(); ++it) {
		if ((*it)->GetType()->ToString() == "System.Windows.Forms.Button")
			(cli::safe_cast<System::Windows::Forms::Button^>(*it))->Visible = value;
		else
			if ((*it)->GetType()->ToString() == "System.Windows.Forms.Label")
				(cli::safe_cast<System::Windows::Forms::Label^>(*it))->Visible = value;
			else
				if ((*it)->GetType()->ToString() == "System.Windows.Forms.TableLayoutPanel")
					(cli::safe_cast<System::Windows::Forms::TableLayoutPanel^>(*it))->Visible = value;
				else
					if ((*it)->GetType()->ToString() == "System.Windows.Forms.DomainUpDown")
						(cli::safe_cast<System::Windows::Forms::DomainUpDown^>(*it))->Visible = value;
	}
}