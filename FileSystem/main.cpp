
#include <iostream>
#include <fstream> // file stream - ����������
// ����������� ����������������� � �������� �������� ����������
#include <string>

bool print_file(std::string file_path) {
	std::ifstream in;
	in.open(file_path);

	if (in.is_open()) {
		char sym;
		while (in.get(sym))
			std::cout << sym;
		in.close();
		std::cout << std::endl;
		return true;
	}
	return false;
}

bool clear_file(std::string file_path) {
	std::ofstream clear;
	clear.open(file_path);

	if (clear.is_open()) {
		clear.close();
		return true;
	}
	return false;
}

bool statistic(std::string word);

int main() {
	setlocale(LC_ALL, "Russian");
	int n;
	std::string path = "file.txt"; // ��������� ���� path - ����

	// ����� ofstream
	/*// ������ ������ �������� ����� - �����
	std::ofstream out; // ������ ������ ofstream ��� ������ ������ � ����
	out.open(path, std::ios::app); // �������� ����� � ������ app

	//������ ������ �������� ����� - �����������
	//std::ofstream out(path); 

	if (out.is_open()) { //�������� ����� �� ��������
		std::cout << "���� ������ ��� ������.\n";
		std::string str;
		std::cout << "������� ������ -> ";
		std::getline(std::cin, str);
		out << str << '\n'; // ���������� ���������� � ����
		std::cout << "������ ��������� � ����.\n";
	}
	else
		std::cout << "������ ������� �����.\n";


	// ��������� ������� ������ ��� �������� �����
	// 1. ������������ ��������� �������� ���� � �����;
	// 2. ��� ������� � �����;
	// 3. ���� ������ ������ �������� ��� �����������.

	out.close(); // �������� ����� � ������� ������� out. ���� �������� out.open �� � ����� ������ ����� �������� out.close */

	// ����� ifstream
	/*std::ifstream in;
	in.open(path);

	if (in.is_open()) {
		std::cout << "���� ������ ��� ������.\n";
		std::cout << "���������� �����:\n";
		std::string file_text;

	// ������������ ����������
	// char sym;
	// while (in.get(sym))
	//	std::cout << sym; // ����� ������ �� �����
	// file_text += sym;  // ����� ������ �� ����� � ������������ (�����������) ������ � ������
	// std::cout << file_text << std::endl;

	// ��������� ����������
	//	while (!in.eof()) { // eof - end of file, !if.eof - ���� �� ����� �����
	//		std::string tmp;
	//		in >> tmp;
	//		file_text += tmp + '\n';
	//	}
	//	std::cout << file_text << std::endl;

		// ���������� ����������
		std::string line;
		while (std::getline(in, line))
		file_text += line + '\n';
		std::cout << file_text << std::endl;
	
	 }
	 else
		 std::cout << "������ ������� �����.\n";

	//��������� ������� ������ ��� �������� ����� ��� ������
	// 1. ������������ ��������� �������� ���� � �����;
	// 2. ��� ������� � �����;
	// 3. ����� �� ����������.
		
	in.close();*/

	// �������� �����
	/*if (remove(path.c_str()) == 0) // ������������ ���������� char ������, �� ���� ������������ ���������
		std::cout << "���� \"" << path << "\"������.\n";
	else
		std::cout << "������ �������� �����.\n";

	//��������� ������� ������ ��� �������� ����� ��� ������
	// 1. ������������ ��������� �������� ���� � �����;
	// 2. ��� ������� � �����;
	// 3. ����� �� ����������;
	// 4. ���� ���� ������.*/

	// ������ 1-2. ����� � ����
	std::cout << "������ 1.\n";

	int action;

	do {
		std::cout << "�������� ��������: \n";
		std::cout << "1. ���������� ��������� � ����; \n";
		std::cout << "2. ����� �����; \n";
		std::cout << "3. ������� �����; \n";
		std::cout << "4. ���������� ������; \n";
		std::cout << "������� ����� �������� -> \n";
		std::cin >> action;

		std::string str1;
		
		switch (action) {
		
		case 1:
			std::cout << "������� ������ -> ";
			std::cin.ignore();
			std::getline(std::cin, str1);

			if (statistic(str1))
				std::cout << "������ ��������� � ����.\n\n";
			else
				std::cout << "������ ���������� �������.\n\n";
			break;
		case 2:
			std::cout << "���������� �����:\n";
			print_file("stats.txt");
			break;
		case 3:
			clear_file("stats.txt");
			std::cout << "���� ������.\n\n";
			break;
		case 4:
			std::cout << "��������� ���������.\n\n";
			break;
		default:
			std::cout << "������ �����.\n\n";
		}	
	} while (action != 4);

	return 0;

}

bool statistic(std::string word) {
	std::ofstream  out;
	out.open("stats.txt", std::ios::app);

	if (out.is_open()) {
		out << word << ' ' << word.length() << '\n';
		out.close();
		return true;
	}
	return false;
}