#include <iostream>
#include <string>
#include <fstream>

#define EXIT 'e'
#define WRITE 'w'
#define READ 'r'

void appendLine(std::string filename, std::string content);
void menu(char &c);
void writeMenu();
void showFile(); 
void readFile(std::string filename);

int main() {
	char c{};

	while (c != EXIT) {
		menu(c);

		switch (c) {
			case WRITE:
				writeMenu();
				break;
			case READ:
				showFile();
				break;
			default:
				break;
		}

	}

	return 0;
}

void appendLine(std::string filename, std::string content) {
	std::ofstream file(filename, std::ios_base::app);

	if (!file.good()) {
		std::cout << "Error opening file!" << std::endl;
		return;
	}

	file << std::endl << content;

	file.close();
}

void menu(char &c) {
	int option = 0;
	system("cls");
	std::cout <<
		"1 - Write line to file\n" <<
		"2 - Show file content\n" <<
		"0 - EXIT\n";
	std::cin >> option;
	if (option == 1) c = WRITE;
	else if (option == 2) c = READ;
	else if (option == 0) c = EXIT;
}

void writeMenu() {
	std::string filename{}, content{};
	system("cls");
	std::cout << "Type filename: ";
	std::cin >> filename;
	std::cout << "Type text to file: ";
	std::cin >> content;
	appendLine(filename, content);
}

void showFile() {
	std::string filename{}; 
	system("cls");
	std::cout << "Type filename: ";
	std::cin >> filename;
	readFile(filename);
	std::cout << std::endl;
	system("pause");
}

void readFile(std::string filename) {
	std::ifstream file(filename);
	char c;

	if (!file.good()) {
		std::cout << "Error opening file!" << std::endl;
		return;
	}
	file >> std::noskipws;

	while (true) {
		file >> c;
		if (file.eof())
			break;
		std::cout << c;
	}

	file.close();
}