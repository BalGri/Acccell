#include <iostream>
#include <tuple>
#include <iomanip>

struct date {
	int day, month, year;
};

void get(const std::tuple<int, date, int, bool> table[11]) noexcept {
	std::cout << std::setiosflags(std::ios::left)
		<< std::setw(3) << "id" << std::setw(10) << "date" << std::setw(5) << "sum" << "done" << std::endl;
	for (int i = 0; i < 11; ++i) {
		std::cout << std::setiosflags(std::ios::left)
			<< std::setw(3) << std::get<0>(table[i])
			<< std::setw(2) << std::get<1>(table[i]).day << "/" << std::get<1>(table[i]).month << "/"
			<< std::setw(5) << std::get<1>(table[i]).year
			<< std::setw(5) << std::get<2>(table[i]) << std::get<3>(table[i]) << std::endl;
	}
}

void filter(std::tuple<int, date, int, bool> table1[11], std::tuple<int, date, int, bool> table2[11]) noexcept {
	for (int m = 0; m < 11; ++m) {
		for (int n = 0; n < 11; ++n) {
			if ((std::get<1>(table1[m]).day == std::get<1>(table2[n]).day) ||
				(std::get<1>(table1[m]).day == std::get<1>(table2[n]).day + 1)) {
				if (std::get<2>(table1[m]) == std::get<2>(table2[n])) {
					std::get<3>(table1[m]) = true;
					std::get<3>(table2[n]) = true;
				}
				else if (std::get<2>(table1[m]) == std::get<2>(table2[n]) + std::get<2>(table2[n + 1])) {
					std::get<3>(table1[m]) = true;
					std::get<3>(table2[n]) = true;
					std::get<3>(table2[n + 1]) = true;
				}
			}
		}
	}
}

int main() {
	setlocale(LC_ALL, "RUS");

	std::cout << "Исходные данные:\n";
	std::tuple<int, date, int, bool> table1[11]{ { 1,{ 1,6,2018 }, 100, false },{ 2,{ 1,6,2018 }, 1500, false },{ 3,{ 1,6,2018 }, 700, false },{ 4,{ 2,6,2018 }, 300, false },{ 5,{ 3,6,2018 }, 400, false },
	{ 6,{ 3,6,2018 }, 200, false },{ 7,{ 3,6,2018 }, 1500, false },{ 8,{ 4,6,2018 }, 100, false },{ 9,{ 4,6,2018 }, 600, false },{ 10,{ 12,6,2018 }, 600, false },{ 11,{ 14,6,2018 }, 600, false } };
	std::cout << "Таблица1:\n"; get(table1); std::cout << "\n";

	std::tuple<int, date, int, bool> table2[11]{ { 1,{ 1,6,2018 }, 100, false },{ 2,{ 1,6,2018 }, 1000, false },{ 3,{ 2,6,2018 }, 500, false },{ 4,{ 3,6,2018 }, 700, false },{ 5,{ 3,6,2018 }, 200, false },
	{ 6,{ 4,6,2018 }, 300, false },{ 7,{ 5,6,2018 }, 300, false },{ 8,{ 11,6,2018 }, 600, false },{ 9,{ 12,6,2018 }, 300, false },{ 10,{ 14,6,2018 }, 500, false },{ 11,{ 15,6,2018 }, 200, false } };
	std::cout << "Таблица2:\n"; get(table2); std::cout << "\n";

	filter(table1, table2); std::cout << "\n";

	std::cout << "Результат:\n";
	std::cout << "Таблица1:\n"; get(table1); std::cout << "\n";
	std::cout << "Таблица2:\n"; get(table2); std::cout << "\n";

	system("pause");
	return 0;
}