#define _CRT_SECURE_NO_WARNINGS  // Отключение предупреждений о небезопасных функциях (только Visual Studio)
#define PATH_TO_FILE "students.db" // Выбор файла с базой данных

// Импортирование библиотек
#include <iostream> 
#include <fstream> 
#include <cmath>
#include <windows.h> 

using namespace std;


class Program
{

public:
	void print(int val)
	{
		cout << val;
	}

	void print(char val)
	{
		cout << val;
	}

	void print(string val)
	{
		cout << val;
	}

	void cin_cl_srt()
	{
		cin.seekg(0, ios::end);
		cin.clear();
	}

	void cin_cl_int()
	{
		cin.clear();
		cin.ignore(INT_MAX, '\n');
	}

	char defend_gender()
	{
		char value;
		while (true) {
			cin >> value;

			if (value == 'M' || value == 'F')
			{
				cin_cl_srt();
				return value;
			}

			print("Не верные данные! Пожалуйста введите M для женщины или F для мужщины");
			print("\n");
			cin_cl_srt();
		}
	}

	int defend_year_of_receipt()
	{
		int value;
		while (true)
		{
			cin >> value;

			if (value > 0)
			{
				cin_cl_int();
				return value;
			}

			print("Не верные данные! Вводите только int данные");
			print("\n");

			cin_cl_int();
		}
	}

	int defend_session_count()
	{
		int value;

		while (true)
		{
			cin >> value;

			if (value >= 1 && value <= 9)
			{
				cin_cl_int();
				return value;
			}

			print("Не верные данные! Вводите значения от 1 до 9");
			print("\n");

			cin_cl_int();
		}
	}

	int defend_subject_count()
	{
		int value;

		while (true)
		{
			cin >> value;

			if (value >= 1 && value <= 10)
			{
				cin_cl_int();
				return value;
			}

			print("Не верные данные! Вводите значения от 1 до 10");
			print("\n");

			cin_cl_int();
		}
	}

	int defend_subject_mark()
	{
		int value;

		while (true)
		{
			cin >> value;

			if (value >= 2 && value <= 5 || value == 0) {
				cin_cl_int();

				return value;
			}

			print("Не верные данные! Вводите значения от 2 до 5. Если не указано введите 0");
			print("\n");
			cin_cl_int();
		}
	}

	bool check_date(int day, int month, int year)
	{
		if (day != 0 && month != 0 && year != 0)
		{
			if (year >= 1900 && year <= 2021)
			{
				if (month >= 1 && month <= 12)
				{
					switch (month)
					{

					case 1: case 3: case 5: case 7: case 8: case 10: case 12:
						if (day >= 1 && day <= 31)
						{
							return true;
						}
						break;

					case 2:
						if (year % 4 != 0 || year % 100 == 0 && year % 400 != 0)
						{
							if (day >= 1 && day <= 28) {
								return true;
							}
						}

						else {
							if (day >= 1 && day <= 29)
							{
								return true;
							}
						}

						break;

					case 4: case 6: case 9: case 11:
						if (day >= 1 && day <= 30)
						{
							return true;
						}

						break;

					default:
						print("[ERROR] - Введена неверная дата");
						print("\n");
						break;
					}
				}

				else
				{
					print("[ERROR] - Месяц должен быть от 1 до 12");
					print("\n");
				}
			}

			else
			{
				print("[ERROR] - Год должен быть от 1900 до 2021");
				print("\n");
			}
		}
		print("[ERROR] - Неверная дата");
		print("\n");


		return false;
	}

	int str_len(char* s)
	{
		int i = 0;
		for (i = 0; s[i] != '\0'; i++);
		return i;
	}

	bool character_array_comparison(char* s1, char* s2)
	{
		int n1, n2;
		for (n1 = 0; s1[n1] != '\0'; n1++) {}
		for (n2 = 0; s2[n2] != '\0'; n2++) {}

		if (n1 != n2)
		{
			return false;
		}

		else
		{
			for (int i = 0; i < n1; i++) {
				if (s1[i] != s2[i]) {
					return false;
				}
			}
			return true;
		}
	}
};


class Student : Program
{

public:
	friend class File;
	friend class Task;

	Student()
	{
		surname = new char[31]();
		name = new char[31]();
		patronymic = new char[31]();
		day = new int(0);
		month = new int(0);
		year = new int(0);
		gender = new char('\0');
		year_of_receipt = new int(0);
		faculty = new char[21];
		department = new char[21];
		group = new char[21];
		zachetka_num = new char[21];
	}

	~Student()
	{
		delete surname;
		delete name;
		delete patronymic;
		delete day;
		delete month;
		delete year;
		delete gender;
		delete year_of_receipt;
		delete faculty;
		delete department;
		delete group;
		delete zachetka_num;
	}

	void set()
	{
		set_surname();
		set_name();
		set_patronymic();
		set_data();
		set_gender();
		set_year_of_receipt();
		set_faculty();
		set_department();
		set_group();
		set_zachetka_num();
	}

	void get()
	{
		get_surname();
		get_name();
		get_patronymic();
		get_data();
		get_gender();
		get_year_of_receipt();
		get_faculty();
		get_department();
		get_group();
		get_zachetka_num();
	}

	void set_surname()
	{
		print("Введите Фамилию (30 символов) ");
		cin.get(surname, 31);
		cin_cl_srt();
	}

	void get_surname()
	{
		print("Фамилия = ");
		print(surname);
		print("\n");
	}

	void set_name()
	{
		print("Введите Имя (30 символов) ");
		cin.get(name, 31);
		cin_cl_srt();
	}

	void get_name()
	{
		print("Имя = ");
		print(name);
		print("\n");
	}

	void set_patronymic()
	{
		print("Введите Отчество (30 символов) ");
		cin.get(patronymic, 31);
		cin_cl_srt();
	}

	void get_patronymic()
	{
		print("Отчество = ");
		print(patronymic);
		print("\n");
	}

	void set_data()
	{
		print("Дата Рождения (дд.мм.гггг) ");
		char* array = new char[11];

		*day = 0;
		*month = 0;
		*year = 0;

		cin.get(array, 11);

		cin_cl_int();

		for (int i = 0; *(array + i) != '\0'; i++)
		{
			if (*(array + i) >= 48 && *(array + i) <= 57 && ((i >= 0 && i <= 1) || (i >= 3 && i <= 4) || (i >= 6 && i <= 9))) {
				switch (i) {

				case 0: case 1:
					*day = *day * 10 + *(array + i) - 0x30;
					break;

				case 3: case 4:
					*month = *month * 10 + *(array + i) - 0x30;
					break;

				case 6: case 7: case 8: case 9:
					*year = *year * 10 + *(array + i) - 0x30;
					break;
				}
			}
		}
		delete[] array;

		if (!check_date(*day, *month, *year))
		{
			*day = 0;
			*month = 0;
			*year = 0;

			set_data();
		}
	}

	void get_data()
	{
		print("День = ");
		print(*day);
		print("\n");
		print("Месяц = ");
		print(*month);
		print("\n");
		print("Год = ");
		print(*year);
		print("\n");
	}

	void set_gender()
	{
		print("Пол (M-мужчина / F-женщина) ");
		*gender = defend_gender();
	}

	void get_gender()
	{
		print("Пол = ");
		print(*gender);
		print("\n");
	}

	void set_year_of_receipt()
	{
		print("Год Поступления (1900-2021) ");
		*year_of_receipt = defend_year_of_receipt();

		if (*year_of_receipt <= *year)
		{
			print("Год поступления не может равняться или быть меньше года рождения");
			print("\n");
			set_year_of_receipt();
		}
	}

	void get_year_of_receipt()
	{
		print("Год Поступления = ");
		print(*year_of_receipt);
		print("\n");
	}

	void set_faculty()
	{
		print("Введите Факультет (20 символов): ");
		cin.get(faculty, 21);
		cin_cl_srt();
	}

	void get_faculty()
	{
		print("Факультет = ");
		print(faculty);
		print("\n");
	}

	void set_department()
	{
		print("Введите Кафедру (20 символов): ");
		cin.get(department, 21);
		cin_cl_srt();
	}

	void get_department()
	{
		print("Кафедра = ");
		print(department);
		print("\n");
	}

	void set_group()
	{
		print("Введите Группу (20 символов) ");
		cin.get(group, 21);
		cin_cl_srt();
	}

	void get_group()
	{
		print("Группа = ");
		print(group);
		print("\n");
	}

	void set_zachetka_num()
	{
		print("Введите Зачетку (20 символов) ");
		cin.get(zachetka_num, 21);
		cin_cl_srt();

		if (!checkZachetki()) {
			print("Такой номер зачетной книжки уже существует");
			print("\n");
			set_zachetka_num();
		}
	}

	void get_zachetka_num()
	{
		print("Зачетка = ");
		print(zachetka_num);
		print("\n");
	}

	bool checkZachetki()
	{
		char* zachetka_number = new char[21];
		int* length = new int(0);
		int* len = new int(0);

		ifstream FILE;

		FILE.open(PATH_TO_FILE, ios::binary);
		FILE.seekg(0, ios::end);
		*length = FILE.tellg();
		FILE.seekg(0, ios::beg);

		while (*length != *len)
		{
			if (*length == -1)
			{
				print("[ERROR] - Файла не существует");
				print("\n");
				return true;
			}

			if (*length == 0)
			{
				print("[ERROR] - В файле нет данных");
				print("\n");
				return true;
			}

			FILE.seekg(178, ios::cur); *len = *len + 178;
			FILE.read(zachetka_number, 21);
			*len = *len + 21;

			if (character_array_comparison(zachetka_num, zachetka_number))
			{
				return false;
			}

			int* session_count = new int(0);
			int* subject_count = new int(0);
			int* sum = new int(0);

			FILE.read((char*)&*session_count, sizeof(*session_count));
			FILE.seekg(1, ios::cur); *len = *len + 5;

			*len = *len + *session_count * 5;

			for (int i = 0; i < *session_count; i++) {
				FILE.read((char*)&*subject_count, sizeof(*subject_count));
				FILE.seekg(1, ios::cur);
				*sum = *sum + *subject_count;
			}

			FILE.seekg((*sum * 26) + 1, ios::cur);
			*len = *len + (*sum * 26) + 1;
		}

		FILE.close();
		return true;
	}

private:
	char* surname = nullptr;
	char* name = nullptr;
	char* patronymic = nullptr;
	int* day = nullptr;
	int* month = nullptr;
	int* year = nullptr;
	char* gender = nullptr;
	int* year_of_receipt = nullptr;
	char* faculty = nullptr;
	char* department = nullptr;
	char* group = nullptr;
	char* zachetka_num = nullptr;
};


class Session : Program
{

public:
	friend class File;
	friend class Task;

	Session()
	{
		session_count = new int(0);
		subject_count = nullptr;
		subject_name = nullptr;
		subject_mark = nullptr;
	}

	~Session()
	{
		delete session_count;
		delete subject_count;
		delete subject_name;
		delete subject_mark;
	}

	void set()
	{
		set_session_count();
		set_subject_count();
		set_subject();
	}

	void get()
	{
		get_session_count();
		get_subject_count();
		get_subject();
	}

	void set_session_count()
	{
		print("Количество семестров (от 1 до 9) ");
		*session_count = defend_session_count();
	}

	void get_session_count()
	{
		print("Количество семестров = ");
		print(*session_count);
		print("\n");
	}

	void set_subject_count()
	{
		subject_count = new int[*session_count];

		for (int i = 0; i < *session_count; i++)
		{
			print("Введите количество предметов в ");
			print(i + 1);
			print(" семестре (от 1 до 9) ");
			*(subject_count + i) = defend_subject_count();
		}

	}

	void get_subject_count() {
		for (int i = 0; i < *session_count; i++)
		{
			print("Предметов в ");
			print(i + 1);
			print(" семестре = ");
			print(subject_count[i]);
			print("\n");
		}
	}

	void set_subject()
	{
		int* sum = new int(0);
		for (int i = 0; i < *session_count; i++)
		{
			*sum = *sum + *(subject_count + i);
		}

		subject_name = new char* [*sum];
		subject_mark = new int[*sum];

		int* session_num = new int(0);
		int* subject_num = new int(0);

		for (int i = 0; i < *sum; i++) {
			if (*subject_num >= subject_count[*session_num]) {
				(*session_num)++;
				*subject_num = 0;
			}

			(*subject_num)++;
			*(subject_name + i) = new char[21];

			print("Сессия ");
			print(*session_num + 1);
			print(" предмет ");
			print(*subject_num);
			print(" название предмета (20 символов) ");

			cin.get(*(subject_name + i), 21);
			cin.seekg(0, ios::end);
			cin.clear();

			print("Сессия ");
			print(*session_num + 1);
			print(" предмет ");
			print(*subject_num);
			print(" оценка (от 2 до 5 или 0 если не указано): ");

			*(subject_mark + i) = defend_subject_mark();
		}
		delete sum;
		delete session_num;
		delete subject_num;
	}

	void get_subject()
	{
		int* sum = new int(0);

		for (int i = 0; i < *session_count; i++) {
			*sum = *sum + *(subject_count + i);
		}

		int* session_num = new int(0);
		int* subject_num = new int(0);

		for (int i = 0; i < *sum; i++)
		{
			if (*subject_num >= subject_count[*session_num]) {
				(*session_num)++;
				*subject_num = 0;
			}

			(*subject_num)++;
			print("Сессия ");
			print(*session_num + 1);
			print(" предмет ");
			print(*subject_num);
			print(" предмет = ");
			print(*(subject_name + i));
			print("\n");
			print("Сессия ");
			print(*session_num + 1);
			print(" предмет ");
			print(*subject_num);
			print(" оценка = ");
			print(*(subject_mark + i));
			print("\n");
		}
		delete sum;
		delete session_num;
		delete subject_num;
	}

private:
	int* session_count = nullptr;
	int* subject_count = nullptr;
	char** subject_name = nullptr;
	int* subject_mark = nullptr;
};

class File : public Program {

public:
	File()
	{
		length = new int(0);
		len = new int(0);
		pos = new int(0);
		count = new int(0);
		sum = new int(0);
		zachetka_num = new char[21];
		zachetka_num_t = new char[21];
	}

	~File()
	{
		delete length;
		delete len;
		delete pos;
		delete sum;
		delete zachetka_num;
		delete zachetka_num_t;
	}

	int FileRecords()
	{
		ifstream FILE;

		FILE.open(PATH_TO_FILE, ios::binary);

		*len = 0;
		*count = 0;

		FILE.seekg(0, ios::end);

		*length = FILE.tellg();

		FILE.seekg(0, ios::beg);

		while (*length != *len)
		{
			if (*length == -1)
			{
				print("[ERROR] - Файла не существует");
				print("\n");
				return -1;
			}

			if (*length == 0) {
				print("[ERROR] - В файле нет данных");
				print("\n");
				return 0;
			}

			FILE.seekg(199, ios::cur); *len = *len + 199;

			int* session_count = new int(0);
			int* subject_count = new int(0);

			FILE.read((char*)&*session_count, sizeof(*session_count));
			FILE.seekg(1, ios::cur); *len = *len + 5;

			*len = *len + *session_count * 5;
			*sum = 0;

			for (int i = 0; i < *session_count; i++)
			{
				FILE.read((char*)&*subject_count, sizeof(*subject_count));
				FILE.seekg(1, ios::cur);
				*sum = *sum + *subject_count;
			}

			FILE.seekg((*sum * 26) + 1, ios::cur);

			*len = *len + (*sum * 26) + 1;
			(*count)++;
		}

		FILE.close();

		return *count;
	}

	void AddToFile()
	{
		ofstream FILE;

		FILE.open(PATH_TO_FILE, ofstream::app | ios::binary);

		Student* student = new Student;
		Session* session = new Session;

		student->set();
		session->set();

		FILE.write(student->surname, 31);
		FILE.write(student->name, 31);
		FILE.write(student->patronymic, 31);
		FILE.write((char*)student->day, 4);
		FILE.write((char*)("\0"), 1);
		FILE.write((char*)student->month, 4);
		FILE.write((char*)("\0"), 1);
		FILE.write((char*)student->year, 4);
		FILE.write((char*)("\0"), 1);
		FILE.write(student->gender, 1);
		FILE.write((char*)("\0"), 1);
		FILE.write((char*)student->year_of_receipt, 4);
		FILE.write((char*)("\0"), 1);
		FILE.write(student->faculty, 21);
		FILE.write(student->department, 21);
		FILE.write(student->group, 21);
		FILE.write(student->zachetka_num, 21);

		delete student;

		FILE.write((char*)session->session_count, 4);
		FILE.write((char*)("\0"), 1);

		for (int i = 0; i < *session->session_count; i++)
		{
			FILE.write((char*)&session->subject_count[i], 4);
			FILE.write((char*)("\0"), 1);
		}

		*sum = 0;

		for (int i = 0; i < *session->session_count; i++)
		{
			*sum = *sum + *(session->subject_count + i);
		}

		for (int i = 0; i < *sum; i++)
		{
			FILE.write((char*)&*(*(session->subject_name + i)), 21);
			FILE.write((char*)&(*(session->subject_mark + i)), 4);
			FILE.write((char*)("\0"), 1);
		}
		delete session;

		FILE.write("\n", 1);
		FILE.close();
	}

	void ReadAllFile()
	{
		ifstream FILE;

		FILE.open(PATH_TO_FILE, ios::binary);
		FILE.seekg(0, ios::end);

		*length = FILE.tellg();

		FILE.seekg(0, ios::beg);

		while (*length != *len)
		{
			if (*length == -1)
			{
				print("[ERROR] - Файла не существует");
				print("\n");
				return;
			}

			if (*length == 0)
			{
				print("[ERROR] - В файле нет данных");
				print("\n");
				return;
			}

			Student* student = new Student;
			Session* session = new Session;

			FILE.read(student->surname, 31);
			FILE.read(student->name, 31);
			FILE.read(student->patronymic, 31);
			FILE.read((char*)student->day, 4);
			FILE.seekg(1, ios::cur);
			FILE.read((char*)student->month, 4);
			FILE.seekg(1, ios::cur);
			FILE.read((char*)student->year, 4);
			FILE.seekg(1, ios::cur);
			FILE.read(student->gender, 1);
			FILE.seekg(1, ios::cur);
			FILE.read((char*)student->year_of_receipt, 4);
			FILE.seekg(1, ios::cur);
			FILE.read(student->faculty, 21);
			FILE.read(student->department, 21);
			FILE.read(student->group, 21);
			FILE.read(student->zachetka_num, 21);

			*len = *len + 199;

			FILE.read((char*)session->session_count, 4);
			FILE.seekg(1, ios::cur);

			session->subject_count = new int[*session->session_count];

			*len = *len + 5;
			*sum = 0;

			for (int i = 0; i < *session->session_count; i++)
			{
				FILE.read((char*)&*(session->subject_count + i), sizeof(*(session->subject_count + i)));
				FILE.seekg(1, ios::cur);

				*sum = *sum + *(session->subject_count + i);
			}

			*len = *len + *session->session_count * 5;
			*len = *len + *sum * 26;

			session->subject_name = new char* [*sum];
			session->subject_mark = new int[*sum];

			for (int i = 0; i < *sum; i++)
			{
				*(session->subject_name + i) = new char[21];
				FILE.read((char*)&*(*(session->subject_name + i)), 21);
				FILE.read((char*)&*(session->subject_mark + i), sizeof(*(session->subject_mark + i)));
				FILE.seekg(1, ios::cur);
			}

			*len = *len + 1;

			FILE.seekg(1, ios::cur);

			print("\n"); for (int i = 1; i < 120; i++) { print("-"); } print("\n");
			print("|           ФАМИЛИЯ            |             ИМЯ              |           ОТЧЕСТВО           |  ЗАЧЕТНАЯ КНИЖКА   |\n");
			print("|");
			print(student->surname);

			for (int i = 0; i < 30 - str_len(student->surname); i++)
			{
				print(" ");
			}

			print("|");
			print(student->name);

			for (int i = 0; i < 30 - str_len(student->name); i++)
			{
				print(" ");
			}

			print("|");
			print(student->patronymic);

			for (int i = 0; i < 30 - str_len(student->patronymic); i++)
			{
				print(" ");
			}

			print("|");
			print(student->zachetka_num);

			for (int i = 0; i < 20 - str_len(student->zachetka_num); i++)
			{
				print(" ");
			}

			print("|");
			print("\n"); for (int i = 1; i < 120; i++) { print("-"); } print("\n");
			print("|Д |М | Г  |П|Г.П |     ФАКУЛЬТЕТ      |      КАФЕДРА       |       ГРУППА       |\n");
			print("|");
			print(*student->day);

			if (*student->day <= 9)
			{
				print(" ");
			}

			print("|");
			print(*student->month);

			if (*student->month <= 9)
			{
				print(" ");
			}

			print("|");
			print(*student->year);
			print("|");
			print(*student->gender);
			print("|");
			print(*student->year_of_receipt);
			print("|");
			print(student->faculty);

			for (int i = 0; i < 20 - str_len(student->faculty); i++)
			{
				print(" ");
			}

			print("|");
			print(student->department);

			for (int i = 0; i < 20 - str_len(student->department); i++)
			{
				print(" ");
			}

			print("|");
			print(student->group);

			for (int i = 0; i < 20 - str_len(student->group); i++)
			{
				print(" ");
			}

			print("|");

			int* temp = new int(0);

			print("\n"); for (int i = 1; i < 120; i++) { print("-"); } print("\n");

			for (int i = 0; i < *session->session_count; i++)
			{
				print("|С|     ПРЕДМЕТ 1      |O|     ПРЕДМЕТ 2      |O|     ПРЕДМЕТ 3      |O|     ПРЕДМЕТ 4      |O|     ПРЕДМЕТ 5      |O|\n");
				cout << "|" << i + 1 << "|";

				int* tmp = new int(0);
				*tmp = *(session->subject_count + i);

				for (int j = 0; j < 5; j++) {
					if (j < *tmp)
					{
						print(*(session->subject_name + (*temp + j)));

						for (int k = 0; k < 20 - str_len(*(session->subject_name + *temp + j)); k++)
						{
							print(" ");
						}

						print("|");
						print(*(session->subject_mark + (*temp + j)));
						print("|");
					}

					else
					{
						print("********************|#|");
					}
				}

				print("\n");
				print("|№|     ПРЕДМЕТ 6      |O|     ПРЕДМЕТ 7      |O|     ПРЕДМЕТ 8      |O|     ПРЕДМЕТ 9      |O|     ПРЕДМЕТ 10     |O|\n");
				cout << "|" << i + 1 << "|";

				for (int j = 0; j < 5; j++)
				{
					if (j + 5 < *tmp)
					{
						print(*(session->subject_name + (*temp + j + 5)));

						for (int k = 0; k < 20 - str_len(*(session->subject_name + (*temp + j + 5))); k++)
						{
							print(" ");
						}

						print("|");
						print(*(session->subject_mark + (*temp + j + 5)));
						print("|");
					}

					else
					{
						print("********************|#|");
					}
				}
				print("\n");

				for (int i = 1; i < 120; i++) { print("-"); } print("\n");

				*temp = *temp + *(session->subject_count + i);

				delete tmp;
			}
			delete temp;
			delete student;
			delete session;
		}
		FILE.close();
	}

	void ReadAllFile_min()
	{
		ifstream FILE;

		FILE.open(PATH_TO_FILE, ios::binary);
		FILE.seekg(0, ios::end);

		*length = FILE.tellg();

		FILE.seekg(0, ios::beg);

		print("|           ФАМИЛИЯ            |             ИМЯ              |  ЗАЧЕТНАЯ КНИЖКА   |П|\n");

		while (*length != *len)
		{
			if (*length == -1)
			{
				print("[ERROR] - Файла не существует");
				print("\n");
				return;
			}

			if (*length == 0)
			{
				print("[ERROR] - В файле нет данных");
				print("\n");
				return;
			}

			Student* student = new Student;
			Session* session = new Session;

			FILE.read(student->surname, 31);
			FILE.read(student->name, 31);
			FILE.read(student->patronymic, 31);
			FILE.read((char*)student->day, 4);
			FILE.seekg(1, ios::cur);
			FILE.read((char*)student->month, 4);
			FILE.seekg(1, ios::cur);
			FILE.read((char*)student->year, 4);
			FILE.seekg(1, ios::cur);
			FILE.read(student->gender, 1);
			FILE.seekg(1, ios::cur);
			FILE.read((char*)student->year_of_receipt, 4);
			FILE.seekg(1, ios::cur);
			FILE.read(student->faculty, 21);
			FILE.read(student->department, 21);
			FILE.read(student->group, 21);
			FILE.read(student->zachetka_num, 21);

			*len = *len + 199;

			FILE.read((char*)session->session_count, 4);
			FILE.seekg(1, ios::cur);

			session->subject_count = new int[*session->session_count];

			*len = *len + 5;
			*sum = 0;

			for (int i = 0; i < *session->session_count; i++)
			{
				FILE.read((char*)&*(session->subject_count + i), sizeof(*(session->subject_count + i)));
				FILE.seekg(1, ios::cur);

				*sum = *sum + *(session->subject_count + i);
			}

			*len = *len + *session->session_count * 5;
			*len = *len + *sum * 26;

			session->subject_name = new char* [*sum];
			session->subject_mark = new int[*sum];

			for (int i = 0; i < *sum; i++)
			{
				*(session->subject_name + i) = new char[21];
				FILE.read((char*)&*(*(session->subject_name + i)), 21);
				FILE.read((char*)&*(session->subject_mark + i), sizeof(*(session->subject_mark + i)));
				FILE.seekg(1, ios::cur);
			}

			*len = *len + 1;

			FILE.seekg(1, ios::cur);
			print("|");
			print(student->surname);

			for (int i = 0; i < 30 - str_len(student->surname); i++)
			{
				print(" ");
			}

			print("|");
			print(student->name);

			for (int i = 0; i < 30 - str_len(student->name); i++)
			{
				print(" ");
			}

			print("|");
			print(student->zachetka_num);

			for (int i = 0; i < 20 - str_len(student->zachetka_num); i++)
			{
				print(" ");
			}

			print("|");
			print(*student->gender);
			print("|\n");

			delete student;
			delete session;
		}
		print("\n");

		FILE.close();
	}

	void ReadByPos(int position)
	{
		ifstream FILE;

		FILE.open(PATH_TO_FILE, ios::binary);

		*pos = 0;

		FILE.seekg(0, ios::end);

		*length = FILE.tellg();
		*len = 0;

		FILE.seekg(0, ios::beg);

		while (*length != *len)
		{
			(*pos)++;

			if (*length == -1)
			{
				print("[ERROR] - Файла не существует");
				print("\n");
				return;
			}

			if (*length == 0)
			{
				print("[ERROR] - В файле нет данных");
				print("\n");
				return;
			}

			Student* student = new Student;
			Session* session = new Session;

			FILE.read(student->surname, 31);
			FILE.read(student->name, 31);
			FILE.read(student->patronymic, 31);
			FILE.read((char*)student->day, 4);
			FILE.seekg(1, ios::cur);
			FILE.read((char*)student->month, 4);
			FILE.seekg(1, ios::cur);
			FILE.read((char*)student->year, 4);
			FILE.seekg(1, ios::cur);
			FILE.read(student->gender, 1);
			FILE.seekg(1, ios::cur);
			FILE.read((char*)student->year_of_receipt, 4);
			FILE.seekg(1, ios::cur);
			FILE.read(student->faculty, 21);
			FILE.read(student->department, 21);
			FILE.read(student->group, 21);
			FILE.read(student->zachetka_num, 21);

			*len = *len + 199;

			FILE.read((char*)session->session_count, 4);
			FILE.seekg(1, ios::cur);

			session->subject_count = new int[*session->session_count];

			*len = *len + 5;
			*sum = 0;

			for (int i = 0; i < *session->session_count; i++)
			{
				FILE.read((char*)&*(session->subject_count + i), sizeof(*(session->subject_count + i)));
				FILE.seekg(1, ios::cur);

				*sum = *sum + *(session->subject_count + i);
			}

			*len = *len + *session->session_count * 5;
			*len = *len + *sum * 26;

			session->subject_name = new char* [*sum];
			session->subject_mark = new int[*sum];

			for (int i = 0; i < *sum; i++)
			{
				*(session->subject_name + i) = new char[21];
				FILE.read((char*)&*(*(session->subject_name + i)), 21);
				FILE.read((char*)&*(session->subject_mark + i), sizeof(*(session->subject_mark + i)));
				FILE.seekg(1, ios::cur);
			}

			*len = *len + 1;

			FILE.seekg(1, ios::cur);

			if (*pos == position)
			{
				student->get();
				session->get();
			}
			delete student;
			delete session;
		}
		FILE.close();
	}

	void ReadByPosTask(int position, int* q, int* w, bool joooo)
	{
		ifstream FILE;

		FILE.open(PATH_TO_FILE, ios::binary);

		*pos = 0;

		FILE.seekg(0, ios::end);

		*length = FILE.tellg();
		*len = 0;

		FILE.seekg(0, ios::beg);

		while (*length != *len)
		{
			(*pos)++;

			if (*length == -1)
			{
				print("[ERROR] - Файла не существует");
				print("\n");
				return;
			}

			if (*length == 0)
			{
				print("[ERROR] - В файле нет данных");
				print("\n");
				return;
			}

			Student* student = new Student;
			Session* session = new Session;

			FILE.read(student->surname, 31);
			FILE.read(student->name, 31);
			FILE.read(student->patronymic, 31);
			FILE.read((char*)student->day, 4);
			FILE.seekg(1, ios::cur);
			FILE.read((char*)student->month, 4);
			FILE.seekg(1, ios::cur);
			FILE.read((char*)student->year, 4);
			FILE.seekg(1, ios::cur);
			FILE.read(student->gender, 1);
			FILE.seekg(1, ios::cur);
			FILE.read((char*)student->year_of_receipt, 4);
			FILE.seekg(1, ios::cur);
			FILE.read(student->faculty, 21);
			FILE.read(student->department, 21);
			FILE.read(student->group, 21);
			FILE.read(student->zachetka_num, 21);

			*len = *len + 199;

			FILE.read((char*)session->session_count, 4);
			FILE.seekg(1, ios::cur);

			session->subject_count = new int[*session->session_count];

			*len = *len + 5;
			*sum = 0;

			for (int i = 0; i < *session->session_count; i++)
			{
				FILE.read((char*)&*(session->subject_count + i), sizeof(*(session->subject_count + i)));
				FILE.seekg(1, ios::cur);

				*sum = *sum + *(session->subject_count + i);
			}

			*len = *len + *session->session_count * 5;
			*len = *len + *sum * 26;

			session->subject_name = new char* [*sum];
			session->subject_mark = new int[*sum];

			for (int i = 0; i < *sum; i++)
			{
				*(session->subject_name + i) = new char[21];
				FILE.read((char*)&*(*(session->subject_name + i)), 21);
				FILE.read((char*)&*(session->subject_mark + i), sizeof(*(session->subject_mark + i)));
				FILE.seekg(1, ios::cur);
			}

			*len = *len + 1;

			FILE.seekg(1, ios::cur);

			if ((*pos == position && (*student->year >= *q && *student->year <= *w) && joooo == true) || (*pos == position && (*student->year < *q || *student->year > *w) && joooo == false))
			{
				print("\n"); for (int i = 1; i < 120; i++) { print("*"); } print("\n");
				print("|           ФАМИЛИЯ            |             ИМЯ              |           ОТЧЕСТВО           |  ЗАЧЕТНАЯ КНИЖКА   |\n");
				print("|");
				print(student->surname);

				for (int i = 0; i < 30 - str_len(student->surname); i++)
				{
					print(" ");
				}

				print("|");
				print(student->name);

				for (int i = 0; i < 30 - str_len(student->name); i++)
				{
					print(" ");
				}

				print("|");
				print(student->patronymic);

				for (int i = 0; i < 30 - str_len(student->patronymic); i++)
				{
					print(" ");
				}

				print("|");
				print(student->zachetka_num);

				for (int i = 0; i < 20 - str_len(student->zachetka_num); i++)
				{
					print(" ");
				}

				print("|");
				print("\n"); for (int i = 1; i < 120; i++) { print("*"); } print("\n");
				print("|Д |М | Г  |П|Г.П |     ФАКУЛЬТЕТ      |      КАФЕДРА       |       ГРУППА       |\n");
				print("|");
				print(*student->day);

				if (*student->day <= 9)
				{
					print(" ");
				}

				print("|");
				print(*student->month);

				if (*student->month <= 9)
				{
					print(" ");
				}

				print("|");
				print(*student->year);
				print("|");
				print(*student->gender);
				print("|");
				print(*student->year_of_receipt);
				print("|");
				print(student->faculty);

				for (int i = 0; i < 20 - str_len(student->faculty); i++)
				{
					print(" ");
				}

				print("|");
				print(student->department);

				for (int i = 0; i < 20 - str_len(student->department); i++)
				{
					print(" ");
				}

				print("|");
				print(student->group);

				for (int i = 0; i < 20 - str_len(student->group); i++)
				{
					print(" ");
				}

				print("|");

				int* temp = new int(0);

				print("\n"); for (int i = 1; i < 120; i++) { print("*"); } print("\n");

				for (int i = 0; i < *session->session_count; i++)
				{
					print("|С|     ПРЕДМЕТ 1      |O|     ПРЕДМЕТ 2      |O|     ПРЕДМЕТ 3      |O|     ПРЕДМЕТ 4      |O|     ПРЕДМЕТ 5      |O|\n");

					cout << "|" << i + 1 << "|";

					int* tmp = new int(0);
					*tmp = *(session->subject_count + i);

					for (int j = 0; j < 5; j++)
					{
						if (j < *tmp)
						{
							print(*(session->subject_name + (*temp + j)));

							for (int k = 0; k < 20 - str_len(*(session->subject_name + *temp + j)); k++)
							{
								print(" ");
							}

							print("|");
							print(*(session->subject_mark + (*temp + j)));
							print("|");
						}

						else
						{
							print("********************|#|");
						}
					}

					print("\n");

					print("|№|     ПРЕДМЕТ 6      |O|     ПРЕДМЕТ 7      |O|     ПРЕДМЕТ 8      |O|     ПРЕДМЕТ 9      |O|     ПРЕДМЕТ 10     |O|\n");

					cout << "|" << i + 1 << "|";

					for (int j = 0; j < 5; j++)
					{
						if (j + 5 < *tmp)
						{
							print(*(session->subject_name + (*temp + j + 5)));

							for (int k = 0; k < 20 - str_len(*(session->subject_name + (*temp + j + 5))); k++)
							{
								print(" ");
							}

							print("|");
							print(*(session->subject_mark + (*temp + j + 5)));
							print("|");
						}

						else
						{
							print("********************|#|");
						}
					}

					print("\n");

					for (int i = 1; i < 120; i++) { print("-"); } print("\n");

					*temp = *temp + *(session->subject_count + i);

					delete tmp;
				}
				delete temp;
			}
			delete student;
			delete session;
		}
		FILE.close();
	}

	void ReadByzachetka_num()
	{
		ifstream FILE;

		FILE.open(PATH_TO_FILE, ios::binary);

		FILE.seekg(0, ios::end);
		*length = FILE.tellg();
		FILE.seekg(0, ios::beg);

		print("Введите Зачетку (20 символов) ");

		cin.get(zachetka_num, 21);
		cin_cl_srt();

		*len = 0;

		while (*length != *len)
		{
			if (*length == -1)
			{
				print("[ERROR] - Файла не существует");
				print("\n");
				return;
			}

			if (*length == 0)
			{
				print("[ERROR] - В файле нет данных");
				print("\n");
				return;
			}

			FILE.seekg(178, ios::cur); *len = *len + 178;
			FILE.read((char*)&*zachetka_num_t, 21);

			*len = *len + 21;

			if (character_array_comparison(zachetka_num, zachetka_num_t))
			{
				FILE.seekg(-199, ios::cur);

				Student* student = new Student;
				Session* session = new Session;

				print("\n"); for (int i = 1; i < 120; i++) { print("-"); } print("\n");

				FILE.read(student->surname, 31);
				FILE.read(student->name, 31);
				FILE.read(student->patronymic, 31);
				FILE.read((char*)student->day, 4);
				FILE.seekg(1, ios::cur);
				FILE.read((char*)student->month, 4);
				FILE.seekg(1, ios::cur);
				FILE.read((char*)student->year, 4);
				FILE.seekg(1, ios::cur);
				FILE.read(student->gender, 1);
				FILE.seekg(1, ios::cur);
				FILE.read((char*)student->year_of_receipt, 4);
				FILE.seekg(1, ios::cur);
				FILE.read(student->faculty, 21);
				FILE.read(student->department, 21);
				FILE.read(student->group, 21);
				FILE.read(student->zachetka_num, 21);
				FILE.read((char*)session->session_count, 4);
				FILE.seekg(1, ios::cur);
				session->subject_count = new int[*session->session_count];

				*sum = 0;

				int* sum = new int(0);

				for (int i = 0; i < *session->session_count; i++)
				{
					FILE.read((char*)&*(session->subject_count + i), sizeof(*(session->subject_count + i)));
					FILE.seekg(1, ios::cur);
					*sum = *sum + *(session->subject_count + i);
				}

				session->subject_name = new char* [*sum];
				session->subject_mark = new int[*sum];

				for (int i = 0; i < *sum; i++)
				{
					*(session->subject_name + i) = new char[21];
					FILE.read((char*)&*(*(session->subject_name + i)), 21);
					FILE.read((char*)&*(session->subject_mark + i), sizeof(*(session->subject_mark + i)));
					FILE.seekg(1, ios::cur);
				}

				FILE.seekg(1, ios::cur);

				print("\n"); for (int i = 1; i < 120; i++) { print("-"); } print("\n");
				print("|           ФАМИЛИЯ            |             ИМЯ              |           ОТЧЕСТВО           |  ЗАЧЕТНАЯ КНИЖКА   |\n");
				print("|");
				print(student->surname);

				for (int i = 0; i < 30 - str_len(student->surname); i++)
				{
					print(" ");
				}

				print("|");
				print(student->name);

				for (int i = 0; i < 30 - str_len(student->name); i++)
				{
					print(" ");
				}

				print("|");
				print(student->patronymic);

				for (int i = 0; i < 30 - str_len(student->patronymic); i++)
				{
					print(" ");
				}

				print("|");
				print(student->zachetka_num);

				for (int i = 0; i < 20 - str_len(student->zachetka_num); i++)
				{
					print(" ");
				}

				print("|");
				print("\n"); for (int i = 1; i < 120; i++) { print("-"); } print("\n");
				print("|Д |М | Г  |П|Г.П |     ФАКУЛЬТЕТ      |      КАФЕДРА       |       ГРУППА       |\n");
				print("|");
				print(*student->day);

				if (*student->day <= 9)
				{
					print(" ");
				}

				print("|");
				print(*student->month);

				if (*student->month <= 9)
				{
					print(" ");
				}

				print("|");
				print(*student->year);
				print("|");
				print(*student->gender);
				print("|");
				print(*student->year_of_receipt);
				print("|");
				print(student->faculty);

				for (int i = 0; i < 20 - str_len(student->faculty); i++)
				{
					print(" ");
				}

				print("|");
				print(student->department);

				for (int i = 0; i < 20 - str_len(student->department); i++)
				{
					print(" ");
				}

				print("|");

				print(student->group);

				for (int i = 0; i < 20 - str_len(student->group); i++)
				{
					print(" ");
				}

				print("|");

				int* temp = new int(0);

				print("\n"); for (int i = 1; i < 120; i++) { print("-"); } print("\n");

				for (int i = 0; i < *session->session_count; i++)
				{
					print("|С|     ПРЕДМЕТ 1      |O|     ПРЕДМЕТ 2      |O|     ПРЕДМЕТ 3      |O|     ПРЕДМЕТ 4      |O|     ПРЕДМЕТ 5      |O|\n");

					cout << "|" << i + 1 << "|";

					int* tmp = new int(0);

					*tmp = *(session->subject_count + i);

					for (int j = 0; j < 5; j++)
					{
						if (j < *tmp)
						{
							print(*(session->subject_name + (*temp + j)));
							for (int k = 0; k < 20 - str_len(*(session->subject_name + *temp + j)); k++)
							{
								print(" ");
							}

							print("|");
							print(*(session->subject_mark + (*temp + j)));
							print("|");
						}

						else
						{
							print("********************|#|");
						}
					}

					print("\n");

					print("|№|     ПРЕДМЕТ 6      |O|     ПРЕДМЕТ 7      |O|     ПРЕДМЕТ 8      |O|     ПРЕДМЕТ 9      |O|     ПРЕДМЕТ 10     |O|\n");

					cout << "|" << i + 1 << "|";

					for (int j = 0; j < 5; j++)
					{
						if (j + 5 < *tmp)
						{
							print(*(session->subject_name + (*temp + j + 5)));

							for (int k = 0; k < 20 - str_len(*(session->subject_name + (*temp + j + 5))); k++)
							{
								print(" ");
							}

							print("|");
							print(*(session->subject_mark + (*temp + j + 5)));
							print("|");
						}

						else
						{
							print("********************|#|");
						}
					}

					print("\n");

					for (int i = 1; i < 120; i++) { print("-"); } print("\n");

					*temp = *temp + *(session->subject_count + i);
					delete tmp;
				}
				delete temp;
				delete student;
				delete session;

				return;
			}

			int* session_count = new int(0);
			int* subject_count = new int(0);

			FILE.read((char*)&*session_count, sizeof(*session_count));
			FILE.seekg(1, ios::cur); *len = *len + 5;

			*len = *len + *session_count * 5;
			*sum = 0;

			for (int i = 0; i < *session_count; i++)
			{
				FILE.read((char*)&*subject_count, sizeof(*subject_count));
				FILE.seekg(1, ios::cur);

				*sum = *sum + *subject_count;
			}

			FILE.seekg((*sum * 26) + 1, ios::cur);

			*len = *len + (*sum * 26) + 1;
		}
		print("[ERROR] - Такого студента не существует");
		print("\n");
	}

	void DeleteByzachetka_num()
	{
		int* records = new int(0);

		*records = FileRecords();

		*pos = 0;

		char oldname[] = "students.db";
		char newname[] = "students.old.db";

		if (rename(oldname, newname) != 0)
		{
			print("[ERROR] - Ошибка при переименовании файла");
			print("\n");
		}

		ifstream FILE_OLD;
		ofstream FILE_NEW;

		FILE_OLD.open(newname, ios::binary);
		FILE_OLD.seekg(0, ios::end);
		*length = FILE_OLD.tellg();
		FILE_OLD.seekg(0, ios::beg);

		*len = 0;

		print("Введите Зачетку (20 символов) ");
		cin.get(zachetka_num, 21);
		cin_cl_srt();

		while (*length != *len)
		{
			if (*length == -1)
			{
				print("[ERROR] - Файла не существует");
				print("\n");
				return;
			}

			if (*length == 0)
			{
				print("[ERROR] - В файле нет данных");
				print("\n");
				return;
			}

			(*pos)++;

			FILE_OLD.seekg(178, ios::cur); *len = *len + 178;
			FILE_OLD.read((char*)&*zachetka_num_t, 21);

			*len = *len + 21;

			if (character_array_comparison(zachetka_num, zachetka_num_t))
			{
				FILE_OLD.seekg(0, ios::beg);
				FILE_NEW.open(oldname, ios::binary);

				for (int i = 0; i < *records; i++)
				{
					Student* student = new Student;
					Session* session = new Session;

					FILE_OLD.read(student->surname, 31);
					FILE_OLD.read(student->name, 31);
					FILE_OLD.read(student->patronymic, 31);
					FILE_OLD.read((char*)student->day, 4);
					FILE_OLD.seekg(1, ios::cur);
					FILE_OLD.read((char*)student->month, 4);
					FILE_OLD.seekg(1, ios::cur);
					FILE_OLD.read((char*)student->year, 4);
					FILE_OLD.seekg(1, ios::cur);
					FILE_OLD.read(student->gender, 1);
					FILE_OLD.seekg(1, ios::cur);
					FILE_OLD.read((char*)student->year_of_receipt, 4);
					FILE_OLD.seekg(1, ios::cur);
					FILE_OLD.read(student->faculty, 21);
					FILE_OLD.read(student->department, 21);
					FILE_OLD.read(student->group, 21);
					FILE_OLD.read(student->zachetka_num, 21);

					*len = *len + 199;

					FILE_OLD.read((char*)session->session_count, 4);
					FILE_OLD.seekg(1, ios::cur);
					session->subject_count = new int[*session->session_count];

					*len = *len + 5;
					*sum = 0;

					for (int i = 0; i < *session->session_count; i++)
					{
						FILE_OLD.read((char*)&*(session->subject_count + i), sizeof(*(session->subject_count + i)));
						FILE_OLD.seekg(1, ios::cur);

						*sum = *sum + *(session->subject_count + i);
					}

					*len = *len + *session->session_count * 5;
					*len = *len + *sum * 26;

					session->subject_name = new char* [*sum];
					session->subject_mark = new int[*sum];

					for (int i = 0; i < *sum; i++)
					{
						*(session->subject_name + i) = new char[21];
						FILE_OLD.read((char*)&*(*(session->subject_name + i)), 21);
						FILE_OLD.read((char*)&*(session->subject_mark + i), sizeof(*(session->subject_mark + i)));
						FILE_OLD.seekg(1, ios::cur);
					}

					*len = *len + 1;
					FILE_OLD.seekg(1, ios::cur);

					if (i + 1 != *pos)
					{
						FILE_NEW.write(student->surname, 31);
						FILE_NEW.write(student->name, 31);
						FILE_NEW.write(student->patronymic, 31);
						FILE_NEW.write((char*)student->day, 4);
						FILE_NEW.write((char*)("\0"), 1);
						FILE_NEW.write((char*)student->month, 4);
						FILE_NEW.write((char*)("\0"), 1);
						FILE_NEW.write((char*)student->year, 4);
						FILE_NEW.write((char*)("\0"), 1);
						FILE_NEW.write(student->gender, 1);
						FILE_NEW.write((char*)("\0"), 1);
						FILE_NEW.write((char*)student->year_of_receipt, 4);
						FILE_NEW.write((char*)("\0"), 1);
						FILE_NEW.write(student->faculty, 21);
						FILE_NEW.write(student->department, 21);
						FILE_NEW.write(student->group, 21);
						FILE_NEW.write(student->zachetka_num, 21);
						FILE_NEW.write((char*)session->session_count, 4);
						FILE_NEW.write((char*)("\0"), 1);

						for (int i = 0; i < *session->session_count; i++)
						{
							FILE_NEW.write((char*)&session->subject_count[i], 4);
							FILE_NEW.write((char*)("\0"), 1);
						}

						*sum = 0;

						for (int i = 0; i < *session->session_count; i++)
						{
							*sum = *sum + *(session->subject_count + i);
						}

						for (int i = 0; i < *sum; i++)
						{
							FILE_NEW.write((char*)&*(*(session->subject_name + i)), 21);
							FILE_NEW.write((char*)&(*(session->subject_mark + i)), 4);
							FILE_NEW.write((char*)("\0"), 1);
						}
						FILE_NEW.write("\n", 1);
					}
				}

				FILE_OLD.close();
				FILE_NEW.close();

				if (remove(newname) != 0)
				{
					print("[ERROR] - Ошибка при удалении файла");
					print("\n");
				}

				if (rename(newname, oldname) != 0)
				{
					print("[ERROR] - Ошибка при переименовании файла");
					print("\n");
				}

				return;
			}

			int* session_count = new int(0);
			int* subject_count = new int(0);

			*sum = 0;

			FILE_OLD.read((char*)&*session_count, sizeof(*session_count));
			FILE_OLD.seekg(1, ios::cur); *len = *len + 5;

			*len = *len + *session_count * 5;

			for (int i = 0; i < *session_count; i++)
			{
				FILE_OLD.read((char*)&*subject_count, sizeof(*subject_count));
				FILE_OLD.seekg(1, ios::cur);

				*sum = *sum + *subject_count;
			}

			FILE_OLD.seekg((*sum * 26) + 1, ios::cur);

			*len = *len + (*sum * 26) + 1;
		}

		FILE_OLD.close();
		print("[ERROR] - Такого студента не существует");
		print("\n");
	}

	void EditByzachetka_num_Student()
	{
		*length = 0;
		*len = 0;
		*pos = 0;
		*sum = 0;

		ifstream FILE;
		FILE.open(PATH_TO_FILE, ios::binary);

		FILE.seekg(0, ios::end);
		*length = FILE.tellg();
		FILE.seekg(0, ios::beg);

		print("Введите Зачетку (20 символов) ");
		cin.get(zachetka_num, 21);
		cin_cl_srt();

		while (*length != *len)
		{
			if (*length == -1)
			{
				print("[ERROR] - Файла не существует");
				print("\n");
				return;
			}

			if (*length == 0)
			{
				print("[ERROR] - В файле нет данных");
				print("\n");
				return;
			}

			FILE.seekg(178, ios::cur); *len = *len + 178;
			FILE.read(zachetka_num_t, 21);

			*len = *len + 21;

			if (character_array_comparison(zachetka_num_t, zachetka_num))
			{
				FILE.close();

				Student* student = new Student;

				char oldname[] = "students.db";
				char newname[] = "students.old.db";

				if (rename(oldname, newname) != 0)
				{
					print("[ERROR] - Ошибка при переименовании файла");
					print("\n");
				}

				const static int BUF_SIZE = 1;

				ifstream in(newname, ios_base::in | ios_base::binary);
				ofstream out(oldname, ios_base::out | ios_base::binary);

				char buf[BUF_SIZE];

				do
				{
					in.read(&buf[0], BUF_SIZE);
					out.write(&buf[0], in.gcount());

				} while (in.gcount() > 0);

				in.close();

				if (remove(newname) != 0)
				{
					print("[ERROR] - Ошибка при удалении файла");
					print("\n");
				}

				*len = *len - 199;

				student->set();
				out.seekp(*len);
				out.write(student->surname, 31);
				out.write(student->name, 31);
				out.write(student->patronymic, 31);
				out.write((char*)student->day, 4);
				out.write((char*)("\0"), 1);
				out.write((char*)student->month, 4);
				out.write((char*)("\0"), 1);
				out.write((char*)student->year, 4);
				out.write((char*)("\0"), 1);
				out.write(student->gender, 1);
				out.write((char*)("\0"), 1);
				out.write((char*)student->year_of_receipt, 4);
				out.write((char*)("\0"), 1);
				out.write(student->faculty, 21);
				out.write(student->department, 21);
				out.write(student->group, 21);
				out.write(student->zachetka_num, 21);
				out.close();

				return;
			}

			int* session_count = new int(0);
			int* subject_count = new int(0);

			*sum = 0;

			FILE.read((char*)&*session_count, sizeof(*session_count));
			FILE.seekg(1, ios::cur); *len = *len + 5;

			*len = *len + *session_count * 5;

			for (int i = 0; i < *session_count; i++) {
				FILE.read((char*)&*subject_count, sizeof(*subject_count));
				FILE.seekg(1, ios::cur);
				*sum = *sum + *subject_count;
			}

			FILE.seekg((*sum * 26) + 1, ios::cur);

			*len = *len + (*sum * 26) + 1;
		}

		print("Ничего не нашли :("); // ;~;
		print("\n");

		FILE.close();
	}

	void EditByzachetka_num_Session()
	{
		int* session_count;
		int* subject_count;

		ifstream FILE;

		FILE.open(PATH_TO_FILE, ios::binary);
		FILE.seekg(0, ios::end);

		*length = FILE.tellg();

		FILE.seekg(0, ios::beg);

		print("Введите Зачетку (20 символов) ");
		cin.get(zachetka_num, 21);
		cin_cl_srt();

		while (*length != *len)
		{
			if (*length == -1)
			{
				print("[ERROR] - Файла не существует");
				print("\n");
				return;
			}

			if (*length == 0)
			{
				print("[ERROR] - В файле нет данных");
				print("\n");
				return;
			}

			FILE.seekg(178, ios::cur); *len = *len + 178;
			FILE.read(zachetka_num_t, 21);

			*len = *len + 21;

			if (character_array_comparison(zachetka_num_t, zachetka_num))
			{
				Session* session = new Session;

				FILE.read((char*)session->session_count, 4);
				FILE.seekg(1, ios::cur);
				session->subject_count = new int[*session->session_count];

				*len = *len + 5;
				*sum = 0;

				for (int i = 0; i < *session->session_count; i++)
				{
					FILE.read((char*)&*(session->subject_count + i), sizeof(*(session->subject_count + i)));
					FILE.seekg(1, ios::cur);

					*sum = *sum + *(session->subject_count + i);
				}

				*len = *len + *session->session_count * 5;

				session->subject_name = new char* [*sum];
				session->subject_mark = new int[*sum];

				for (int i = 0; i < *sum; i++)
				{
					*(session->subject_name + i) = new char[21];
					FILE.read((char*)&*(*(session->subject_name + i)), 21);
					FILE.read((char*)&*(session->subject_mark + i), sizeof(*(session->subject_mark + i)));
					FILE.seekg(1, ios::cur);
				}

				FILE.seekg(1, ios::cur);

				FILE.close();

				char oldname[] = "students.db";
				char newname[] = "students.old.db";

				if (rename(oldname, newname) != 0)
				{
					print("[ERROR] - Ошибка при переименовании файла");
					print("\n");
				}

				ifstream in(newname, ios_base::in | ios_base::binary);
				ofstream out(oldname, ios_base::out | ios_base::binary);

				char buf;

				do
				{
					in.read(&buf, 1);
					out.write(&buf, in.gcount());

				} while (in.gcount() > 0);

				in.close();

				if (remove(newname) != 0)
				{
					print("[ERROR] - Ошибка при удалении файла");
					print("\n");
				}

				session->set_subject();

				out.seekp(*len);

				for (int i = 0; i < *sum; i++)
				{
					out.write((char*)&*(*(session->subject_name + i)), 21);
					out.write((char*)&(*(session->subject_mark + i)), 4);
					out.write((char*)("\0"), 1);
				}

				out.close();

				delete session;

				return;
			}

			session_count = new int(0);
			subject_count = new int(0);

			sum = new int(0);

			FILE.read((char*)&*session_count, sizeof(*session_count));
			FILE.seekg(1, ios::cur); *len = *len + 5;

			*len = *len + *session_count * 5;

			for (int i = 0; i < *session_count; i++)
			{
				FILE.read((char*)&*subject_count, sizeof(*subject_count));
				FILE.seekg(1, ios::cur);

				*sum = *sum + *subject_count;
			}

			FILE.seekg((*sum * 26) + 1, ios::cur);
			*len = *len + (*sum * 26) + 1;
		}

		print("Ничего не нашли :(");
		print("\n");

		FILE.close();
	}

	void EditByzachetka_num()
	{
		DeleteByzachetka_num();
		AddToFile();
	}

private:
	int* length;
	int* len;
	int* pos;
	int* count;
	int* sum;
	char* zachetka_num;
	char* zachetka_num_t;
	int* year1;
	int* year2;
	int* kd;
};


class Str
{

public:
	Str(const char* str)
	{
		int i = 0; for (i = 0; str[i] != '\0'; i++);

		data = new char[i + 1];

		strcpy(data, str);
	}

	~Str()
	{
		delete data;
	}

	void operator+=(Str& rvalue)
	{
		int i = 0; for (i = 0; data[i] != '\0'; i++);
		int j = 0; for (j = 0; rvalue.get_data()[j] != '\0'; j++);

		temp = new char[i + j + 1]();

		strcat(temp, data);
		strcat(temp, rvalue.get_data());

		data = new char[i + j + 1]();

		strcat(data, temp);

		delete temp;
	}

	void operator+=(const char* rvalue)
	{
		int i = 0; for (i = 0; data[i] != '\0'; i++);
		int j = 0; for (j = 0; rvalue[j] != '\0'; j++);

		temp = new char[i + j + 1]();

		strcat(temp, data);
		strcat(temp, rvalue);

		data = new char[i + j + 1]();

		strcat(data, temp);

		delete temp;
	}

	const char* get_data()
	{
		return data;
	}

	void print()
	{
		cout << data << '\n';
	}

private:
	char* data = nullptr;
	char* temp = nullptr;
};

class Task : public Program
{

public:
	Task()
	{
		male = new bool;
		female = new bool;
		length = new int(0);
		len = new int(0);
		sum = new int(0);
		year = new int(0);
		pos = new int(0);
		num = new int(0);
		year1 = new int(0); // Интервал от
		year2 = new int(0); // Интервал до
		kd = new double(0);
		sum1 = new int(0);
		kol = new int(0);
	}

	~Task()
	{
		delete male;
		delete female;
		delete length;
		delete len;
		delete sum;
		delete year;
		delete pos;
		delete num;
		delete year1;
		delete year2;
		delete kol;
		delete sum1;
	}

	void Start(bool j)
	{
		cout << "Введите значение от:" << endl;
		cin >> *year1;

		cout << "Введите значение до:" << endl;
		cin >> *year2;

		Do(year1, year2, j);
	}

	void Do(int* q, int* w, bool joooo)
	{
		File* f = new File;
		int* sz = new int(f->FileRecords());

		year = new int[*sz];
		pos = new int[*sz];
		num = new int(-1);
		kd = new double(0);

		for (int i = 0; i < f->FileRecords(); i++)
		{
			*(year + i) = 0;
		}

		for (int i = 0; i < f->FileRecords(); i++)
		{
			*(pos + i) = i + 1;
		}

		int* j = new int(0);

		ifstream FILE;

		FILE.open(PATH_TO_FILE, ios::binary);
		FILE.seekg(0, ios::end);

		*length = FILE.tellg();

		FILE.seekg(0, ios::beg);

		while (*length != *len)
		{
			if (*length == -1)
			{
				print("[ERROR] - Файла не существует");
				print("\n");
				return;
			}

			if (*length == 0)
			{
				print("[ERROR] - В файле нет данных");
				print("\n");
				return;
			}

			Student* student = new Student;
			Session* session = new Session;

			FILE.read(student->surname, 31);
			FILE.read(student->name, 31);
			FILE.read(student->patronymic, 31);
			FILE.read((char*)student->day, 4);
			FILE.seekg(1, ios::cur);
			FILE.read((char*)student->month, 4);
			FILE.seekg(1, ios::cur);
			FILE.read((char*)student->year, 4);
			FILE.seekg(1, ios::cur);
			FILE.read(student->gender, 1);
			FILE.seekg(1, ios::cur);
			FILE.read((char*)student->year_of_receipt, 4);
			FILE.seekg(1, ios::cur);
			FILE.read(student->faculty, 21);
			FILE.read(student->department, 21);
			FILE.read(student->group, 21);
			FILE.read(student->zachetka_num, 21);

			*len = *len + 199;

			FILE.read((char*)session->session_count, 4);
			FILE.seekg(1, ios::cur);

			session->subject_count = new int[*session->session_count];

			*len = *len + 5;
			*sum = 0;

			for (int i = 0; i < *session->session_count; i++) // Подсчет ячеек сессий
			{
				FILE.read((char*)&*(session->subject_count + i), sizeof(*(session->subject_count + i)));
				FILE.seekg(1, ios::cur);

				*sum = *sum + *(session->subject_count + i);
			}

			*len = *len + *session->session_count * 5;
			*len = *len + *sum * 26;

			session->subject_name = new char* [*sum];
			session->subject_mark = new int[*sum];

			*sum1 = 0; *kol = 0;
			int sumer = 0, koler = 0;

			for (int i = 0; i < *sum; i++)
			{
				*(session->subject_name + i) = new char[21];
				FILE.read((char*)&*(*(session->subject_name + i)), 21);
				FILE.read((char*)&*(session->subject_mark + i), sizeof(*(session->subject_mark + i)));
				FILE.seekg(1, ios::cur);

				*sum1 = *sum1 + *(session->subject_mark + i);
				*kol = *kol + 1;

				sumer = sumer + *(session->subject_mark + i);

				 koler += 1;
				 *kd = (double)*sum1 / (double)*kol;
			}

			
			// cout << "КД для ученика "<< student->name << " : " << round((float) sumer / koler * 100)/100 << endl;

			*len = *len + 1;
			FILE.seekg(1, ios::cur);

			*(year + *j) = *student->year_of_receipt;
			(*j)++;

			delete student;
			delete session;
		}

		FILE.close();

		float temp;
		//cout << *sz;
		for (int i = 0; i < *sz - 1; i++)
		{
			for (int j = 0; j < *sz - i -1  ; j++)
			{

				if (*(kd + j) > *(kd + (j + 1))) {
					temp = *(kd + j);
					*(kd + j) = *(kd + (j + 1));
					*(kd + (j + 1)) = temp;
					temp = *(pos + j);
					*(pos + j) = *(pos + (j + 1));
					*(pos + (j + 1)) = temp;
				}
				
			}
		}
		
		for (int i = 0; i < f->FileRecords(); i++)
		{
			f->ReadByPosTask(*(pos + i), q, w, joooo);
		}

		delete f, sz;
	}

private:
	int* length;
	int* len;
	int* sum;
	bool* male;
	bool* female;
	int* year;
	int* pos;
	int* num;
	int* year1;
	int* year2;
	double* kd;
	int* sum1;
	int* kol;
};


class Menu : Program
{

public:
	Menu()
	{
		answer = new int;
		SetConsoleCP(1251);
		SetConsoleOutputCP(1251);
		system("cls");
		hub();
	}

	~Menu()
	{
		delete answer;
		system("cls");
	}

	void hub()
	{
		for (int i = 0; i < 119; i++, print("="));
		print("=\n");
		print("Выберите вариант\n");
		print("[1] - Добавить студента\n");
		print("[2] - Удалить студента\n");
		print("[3] - Изменить данные студента\n");
		print("[4] - Вывести всю базу студентов\n");
		print("[5] - Найти студента по зачетке\n");
		print("[6] - Выполнение задачи\n");
		print("[7] - Очистить экран\n");
		print("[0] - Выйти из программы\n");

		print("Ввод номера команды: ");
		
		
		bool joooo;
		cin >> *answer;
		for (int i = 0; i < 119; i++, print("="));
		print("=\n");
		cin_cl_int();

		File* f = new File;
		Task* t = new Task;

		switch (*answer) {
		case 1:
			f->AddToFile();

			break;

		case 2:
			f->DeleteByzachetka_num();

			break;

		case 3:
			print("Выберите вариант\n");
			print("[1] - Редактирование данных, о студенте\n");
			print("[2] - Редактирование данных, о предметах и оценках\n");
			print("[3] - Полное редактирование\n");
			print("[0] - Назад в меню\n");
			print("Ввод номера команды: ");

			cin >> *answer;

			cin_cl_int();

			switch (*answer)
			{
			case 1:
				f->EditByzachetka_num_Student();
				break;

			case 2:
				f->EditByzachetka_num_Session();
				break;

			case 3:
				f->EditByzachetka_num();
				break;

			case 0:
				system("cls");
				hub();
				return;

			default:
				system("cls");
				print("[ERROR] - Вы выбрали неверный вариант");
				print("\n");
				hub();
			}
			break;

		case 4:
			print("Выберите вариант\n");
			print("[1] - Вывести всю информацию\n");
			print("[2] - Вывести часть информации\n");
			print("[0] - Назад в меню\n");
			print("Ввод номера команды: ");

			cin >> *answer;

			cin_cl_int();

			switch (*answer)
			{
			case 1:
				f->ReadAllFile();
				break;

			case 2:
				f->ReadAllFile_min();
				break;

			case 0:
				system("cls");
				hub();
				return;

			default:
				system("cls");
				print("[ERROR] - Вы выбрали неверный вариант");
				print("\n");
				hub();
			}
			break;

		case 5:
			f->ReadByzachetka_num();
			break;

		case 6:
			print("Выберите вариант\n");
			print("[1] - Вывести студентов родившихся в интервале от и до\n");
			print("[2] - Вывести студентов родившихся вне интервала от и до\n");
			print("[0] - Назад в меню\n");
			print("Ввод номера команды: ");

			cin >> *answer;

			cin_cl_int();

			switch (*answer)
			{
			case 1:
				joooo = true;
				t->Start(joooo);
				break;

			case 2:
				joooo = false;
				t->Start(joooo);
				break;

			case 0:
				system("cls");
				hub();
				return;

			default:
				system("cls");
				hub();
			}
			break;

		case 7:
			system("cls");
			break;

		case 0:
			return;

		default:
			system("cls");
			print("[ERROR] - Вы выбрали неверный вариант");
			print("\n");
			break;
		}

		delete f;
		delete t;
		hub();
	}

private:
	int* answer;
};

int main()
{
	Menu* menu = new Menu;
	delete menu;
	return 0;
}
