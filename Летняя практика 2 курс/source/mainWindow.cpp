#include "mainWindow.h"
#include <time.h>

using namespace System;
using namespace System::Windows::Forms;

int main(array<String^>^ args) {
	srand(time(nullptr));
	Application::EnableVisualStyles();
	Application::SetCompatibleTextRenderingDefault(true);
	SlaSol::mainWindow mw;
	Application::Run(%mw);
	return 0;
}