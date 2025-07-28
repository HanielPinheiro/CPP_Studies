#include <iostream>
#include <Windows.h>
#include<conio.h>

using namespace std;

int main()
{
	cout << "Hello World";
	bool a = false;

	while (true) {
		if (GetAsyncKeyState(VK_CONTROL)) a = !a;
		if (a) {			
			INPUT inputs[4] = {};
			ZeroMemory(inputs, sizeof(inputs));

			inputs[0].type = INPUT_KEYBOARD;
			inputs[0].ki.wVk = VK_LWIN;

			inputs[1].type = INPUT_KEYBOARD;
			inputs[1].ki.wVk = 'D';

			inputs[2].type = INPUT_KEYBOARD;
			inputs[2].ki.wVk = 'D';
			inputs[2].ki.dwFlags = KEYEVENTF_KEYUP;

			inputs[3].type = INPUT_KEYBOARD;
			inputs[3].ki.wVk = VK_LWIN;
			inputs[3].ki.dwFlags = KEYEVENTF_KEYUP;

			UINT uSent = SendInput(ARRAYSIZE(inputs), inputs, sizeof(INPUT));
			if (uSent != ARRAYSIZE(inputs))
			{
				cout << "Deu ruim";
			}

			/*
			keybd_event(0x71, 0, KEYEVENTF_EXTENDEDKEY, 0);
			Sleep(500);
			keybd_event(0x71, 0, KEYEVENTF_KEYUP, 0);
			Sleep(500);
			cout << 0x71;


			keybd_event(0x63, 0, KEYEVENTF_EXTENDEDKEY, 0);
			Sleep(500);
			keybd_event(0x63, 0, KEYEVENTF_KEYUP, 0);
			Sleep(500);

			keybd_event(0x76, 0, KEYEVENTF_EXTENDEDKEY, 0);
			Sleep(500);
			keybd_event(0x76, 0, KEYEVENTF_KEYUP, 0);
			Sleep(500);		*/	
		}
	}
	return 0;
	//_getch();
}

