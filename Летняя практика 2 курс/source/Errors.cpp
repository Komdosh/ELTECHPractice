#include "Errors.h"

void WrongParams::getMessage() {
	System::String^ message = "������ ��������: " + first + "\n������ ��������: " + second;
	System::String^ caption = "������������ ��������";
	System::Windows::Forms::MessageBoxButtons buttons = System::Windows::Forms::MessageBoxButtons::OK;
	System::Windows::Forms::MessageBox::Show(message, caption, buttons, System::Windows::Forms::MessageBoxIcon::Error, System::Windows::Forms::MessageBoxDefaultButton::Button1);
}

void errorMessageWithGui() {
	System::String^ message = "��������� ������. ��������� ��������";
	System::String^ caption = "��������� ��������";
	System::Windows::Forms::MessageBoxButtons buttons = System::Windows::Forms::MessageBoxButtons::OK;
	System::Windows::Forms::MessageBox::Show(message, caption, buttons, System::Windows::Forms::MessageBoxIcon::Error, System::Windows::Forms::MessageBoxDefaultButton::Button1);
}