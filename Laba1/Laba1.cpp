#include <iostream>
#include <iomanip>
#include <string>
#include <cstdint>
#include <bitset>
using namespace std;

// 1. Размеры типов
void showSizes() {
	cout << "Размеры типов данных (в байтах):" << endl;
	cout << "bool " << sizeof(bool) << endl;
	cout << "char " << sizeof(char) << endl;
	cout << "short int " << sizeof(short int) << endl;
	cout << "int " << sizeof(int) << endl;
	cout << "long int " << sizeof(long int) << endl;
	cout << "float " << sizeof(float) << endl;
	cout << "double " << sizeof(double) << endl;
	cout << "long double " << sizeof(long double) << endl;
}

// 2. Биты целого числа

void printIntBits(int num) {
	cout << "Число:" << num << endl;
	cout << "Биты: [знак]";
	unsigned int u = (unsigned int)num;
	for (int i = 31; i >= 0; i--) {
		if (i != 31 && (i + 1) % 8 == 0) cout << " ";
		cout << ((u >> i) & 1);
	}
	cout << endl;
}
// Для пользователя
void printIntBitsInteractive() {
	int num;
	cout << "Введите целое число:";
	cin >> num;
	printIntBits(num);
}

// 3. Биты float
void printFloatBits(float f) {
	uint32_t bits;
	memcpy(&bits, &f, sizeof(bits));

	cout << "Float: " << f << endl;
	cout << "[знак] [порядок] [мантисса]" << endl;

	for (int i = 31; i >= 0; i--) {
		cout << ((bits >> i) & 1);
		if (i != 0 && i % 8 == 0) cout << " ";
	}
	cout << endl;
}
// Для пользователя
void printFloatBitsInteractive() {
	float f;
	cout << "Введите число (float): ";
	cin >> f;
	printFloatBits(f);
}

// 4. Биты double
void printDoubleBits(float d) {
	uint64_t bits;
	memcpy(&bits, &d, sizeof(bits));

	cout << "Double: " << d << endl;
	cout << "[знак] [порядок] [мантисса]" << endl;

	for (int i = 63; i >= 0; i--) {
		cout << ((bits >> i) & 1);
		if (i != 0 && i % 8 == 0) cout << " ";
	}
	cout << endl;
}

// Для пользователя
void printDoubleBitsInteractive() {
	float d;
	cout << "Введите число (double): ";
	cin >> d;
	printDoubleBits(d);
}

// 5. Манипуляция с битами
void bitManipulations(int num, int pos) {
	cout << "Исходное число: " << num << " (бит " << pos << ")" << endl;
	int setBit = num | (1 << pos);
	cout << "Установить в 1: " << setBit << endl;
	int clearBit = num & ~(1 << pos);
	cout << "Сбросить в 0: " << clearBit << endl;
	int invertBit = num ^ (1 << pos);
	cout << "Инвертировать: " << invertBit << endl;
}
// Для пользователя
void bitManipulationsInteractive() {
	int num,pos;
	cout << "Введите целое число: ";
	cin >> num;
	cout << "Введите номер бита (от 0 до 31): ";
	cin >> pos;
	if (pos < 0 || pos >31) {
		cout << "Ошибка, бит должен быть от 0 до 31" << endl;
		return;
	}
	bitManipulations(num,pos);
}

// 6. Умножение на 2
void individualTask(int num) {
	cout << "Исходное число: " << num << endl;
	int result = num << 1;
	cout << "Результат умножения на 2: " << result << endl;
}

// Для пользователя
void individualTaskInteractive() {
	int num;
	cout << "Введите число: ";
	cin >> num;
	individualTask(num);
}

// 7. Главная функция main
int main() {
	setlocale(LC_ALL, "Russian");
	showSizes();

	cout << "\n2. ЦЕЛЫЕ " << endl;
	printIntBits(42);
	printIntBits(-42);
	cout << "\n3. FLOAT " << endl;
	printFloatBits(3.14f);
	printFloatBits(-2.5f);
	cout << "\n4. DOUBLE " << endl;
	printDoubleBits(3.14);
	cout << endl;

	int choice = -1; 

	while (choice != 0) {
		cout << "\n----ИНТЕРАКТИВНЫЙ РЕЖИМ----" << endl;
		cout << "2 - Ввести целое число" << endl;
		cout << "3 - Ввести float" << endl;
		cout << "4 - Ввести double" << endl;
		cout << "5 - Манипуляции с битами" << endl;
		cout << "6 - Умножение на 2 (индивидуальное)" << endl;
		cout << "0 - Выход из программы" << endl; 
		cout << "Ваш выбор: ";

		cin >> choice;

		if (choice == 2) {
			int n;
			cout << "Введите целое число: ";
			cin >> n;
			printIntBits(n);
		}
		else if (choice == 3) {
			float f;
			cout << "Введите число (float): ";
			cin >> f;
			printFloatBits(f);
		}
		else if (choice == 4) {
			double d;
			cout << "Введите число (double): ";
			cin >> d;
			printDoubleBits(d);
		}
		else if (choice == 5) {
			bitManipulationsInteractive();
		}
		else if (choice == 6) {
			individualTaskInteractive();
		}
		else if (choice == 0) {
			cout << "Выход из программы. До свидания!" << endl;
		}
		else {
			cout << "Неверный пункт. Попробуйте снова." << endl;
		}
	}

	return 0;
}