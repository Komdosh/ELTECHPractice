#include "Errors.h"

void WrongParams::getMessage() {
	System::String^ message = "Первый параметр: " + first + "\nВторой параметр: " + second;
	System::String^ caption = "Неправильный параметр";
	System::Windows::Forms::MessageBoxButtons buttons = System::Windows::Forms::MessageBoxButtons::OK;
	System::Windows::Forms::MessageBox::Show(message, caption, buttons, System::Windows::Forms::MessageBoxIcon::Error, System::Windows::Forms::MessageBoxDefaultButton::Button1);
}

void errorMessageWithGui() {
	System::String^ message = "Произошла ошибка. Повторите действие";
	System::String^ caption = "Повторите действие";
	System::Windows::Forms::MessageBoxButtons buttons = System::Windows::Forms::MessageBoxButtons::OK;
	System::Windows::Forms::MessageBox::Show(message, caption, buttons, System::Windows::Forms::MessageBoxIcon::Error, System::Windows::Forms::MessageBoxDefaultButton::Button1);
}