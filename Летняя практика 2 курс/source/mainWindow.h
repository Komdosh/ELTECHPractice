#pragma once
#include "Errors.h"
#include "Game.h"
#include "Display.h"
#include "Campaign.h"
#include "SettedGame.h"
#include "RandomGame.h"

namespace SlaSol {
	using namespace SlaSolDisplay;
	using namespace SlaSolGame;
	using namespace System;
	using namespace System::Windows::Forms;

	/// <summary>
	/// Сводка для mainWindow
	/// </summary>
	public ref class mainWindow : public System::Windows::Forms::Form {

	private: AbstractGame *game;
	public: static Display^ display;

	public:
		mainWindow(void)
		{
			InitializeComponent();
			Display::mainWindow = this;
			display = gcnew Display();
		}

	protected:
		/// <summary>
		/// Освободить все используемые ресурсы.
		/// </summary>
		~mainWindow()
		{
			if (components)
			{
				delete components;
			}
		}

	private:
		/// <summary>
		/// Обязательная переменная конструктора.
		/// </summary>
		System::ComponentModel::Container ^components;

#pragma region Windows Form Designer generated code
		/// <summary>
		/// Требуемый метод для поддержки конструктора — не изменяйте 
		/// содержимое этого метода с помощью редактора кода.
		/// </summary>
		void InitializeComponent(void)
		{
			System::ComponentModel::ComponentResourceManager^  resources = (gcnew System::ComponentModel::ComponentResourceManager(mainWindow::typeid));
			// 
			// mainWindow
			// 
			this->SuspendLayout();
			this->AutoScaleDimensions = System::Drawing::SizeF(6, 13);
			this->AutoScaleMode = System::Windows::Forms::AutoScaleMode::Font;
			this->BackColor = System::Drawing::Color::MediumTurquoise;
			this->ClientSize = System::Drawing::Size(534, 462);
			this->FormBorderStyle = System::Windows::Forms::FormBorderStyle::FixedDialog;
			this->Icon = (cli::safe_cast<System::Drawing::Icon^>(resources->GetObject(L"$this.Icon")));
			this->MaximizeBox = false;
			this->Name = L"mainWindow";
			this->Text = L"SlaSol";
			this->ResumeLayout(false);
			this->PerformLayout();

		}
#pragma endregion
	public: System::Void newGameButton_Click(System::Object^  sender, System::EventArgs^  e) {
		try {
			String^ message = "Вы уверены, что хотите начать новую игру?";
			String^ caption = "Новая игра?";
			MessageBoxButtons buttons = MessageBoxButtons::YesNo;
			System::Windows::Forms::DialogResult result;
			result = MessageBox::Show(this, message, caption, buttons, MessageBoxIcon::Question, MessageBoxDefaultButton::Button1);
			if (result == System::Windows::Forms::DialogResult::Yes) {
				delete game;
				display->hideGameField();
				display->showMainMenu();
			}
		}
		catch (Exception^ e) {
			MessageBox::Show(e->Message);
		}
		catch (...) {
			errorMessageWithGui();
		}
	}
	public: System::Void campaignButton_Click(System::Object^  sender, System::EventArgs^  e) {
		game = new Campaign();
		game->start();
	}

	public: System::Void settedGameButton_Click(System::Object^  sender, System::EventArgs^  e) {
		display->hideMainMenu();
		display->showLevelMenu();
	}

	public: System::Void lightLevelButton_Click(System::Object^  sender, System::EventArgs^  e) {
		display->hideLevelMenu();
		game = new SettedGame(2, 2, 4);
		game->start();
	}
	public: System::Void middleLevelButton_Click(System::Object^  sender, System::EventArgs^  e) {
		display->hideLevelMenu();
		game = new SettedGame(3, 3, 5);
		game->start();
	}

	public: System::Void hardLevelButton_Click(System::Object^  sender, System::EventArgs^  e) {
		display->hideLevelMenu();
		game = new SettedGame(7, 7, 14);
		game->start();
	}

	public: System::Void startSettedGameButton_Click(System::Object^  sender, System::EventArgs^  e) {
		display->hideLevelSetMenu();
		game = new SettedGame(display->getFieldSizeFromLevelMenuDomain(), display->getCountOfColorsFromLevelMenuDomain());
		game->start();
	}

	public: System::Void randomGameButton_Click(System::Object^  sender, System::EventArgs^  e) {
		game = new RandomGame();
		game->start();
	}

	public: System::Void quitButton_Click(System::Object^  sender, System::EventArgs^  e) {
		String^ message = "Вы уверены, что хотите выйти? ";
		String^ caption = "Закрыть игру?";
		MessageBoxButtons buttons = MessageBoxButtons::YesNo;
		System::Windows::Forms::DialogResult result;
		result = MessageBox::Show(this, message, caption, buttons, MessageBoxIcon::Exclamation, MessageBoxDefaultButton::Button1);
		if (result == System::Windows::Forms::DialogResult::Yes) {
			Application::Exit();
		}
	}

	public: System::Void block_Click(System::Object^ sender, System::EventArgs^  e) {
		game->end(sender);
	}

	public: System::Void setGameButton_Click(System::Object^  sender, System::EventArgs^  e) {
		display->hideLevelMenu();
		display->showLevelSetMenu();
	}

	public: System::Void mainMenuButton_Click(System::Object^  sender, System::EventArgs^  e) {
		display->hideLevelMenu();
		display->hideLevelSetMenu();
		display->showMainMenu();
	}
	};
}