#define _USE_MATH_DEFINES

#include <iostream>
#include "Strings.h"
using namespace std;

// ¬ариант є6
// Ёта функци€ выводит сообщение, которое указываетс€ в еЄ параметрах вызова
// ѕосле чего ожидает нажатие любой клавиши дл€ исполнени€ дальнейших инструкций
static void interrupt(const char* msg="")
{
	cout << msg << endl;
	system("pause");
	system("cls");
}

class Human {
public: 
	Human(float speed, float distance) {
		this->speed = speed;
		this->distance = distance;
	};
private:
	float speed = 0.0f;
	float distance = 0.0f; // в данном случае рассто€ние до угла улицы
public:
	// »нкапсул€ци€
	float getSpeed() const { return speed; }
	float getDistance() const { return distance; }
	void setSpeed(float val) { speed = val; }
	void setDistance(float val) { distance = val; }
	float timeToReachCrossroad() const { return distance / speed; }
};

int main()
{
	setlocale(LC_ALL, "ru");

#pragma region task selector
	unsigned short activeTaskNumber = 0;
selectTask:
	cout << "¬ведите номер задани€ дл€ исполнени€ (1-4): ";
	cin >> activeTaskNumber;
	system("cls");
	switch (activeTaskNumber) {
		case 1: goto task1;
		case 2: goto task2;
		case 3: goto task3;
		case 4: goto task4;
		default: {
			interrupt("¬ведЄн некорректный номер задани€.");
			goto selectTask;
		}
	}
#pragma endregion

task1:
	{
		cout << desc_t1 << endl;
		float side_a = 0.0f;
		float side_b = 0.0f;
		float angle = 0.0f;
		cout << "¬ведите стороны параллелограмма\nA: ";
		cin >> side_a;
		cout << "B: "; 
		cin >> side_b;

		if (side_a == 0 || side_b == 0) {
			interrupt("ƒлина любой из сторон не может равн€тьс€ нулю.");
			goto task1;
		}

		cout << "¬ведите угол между этими сторонами в градусах: ";
		cin >> angle;
		if (angle > 180 || angle < 0) {
			interrupt("”казан некорректный угол между сторонами параллелограмма. ≈го значение должно находитс€ в диапазоне от 0 до 180 градусов.");
			goto task1;
		}
		float angle_rad = angle * M_PI / 180; // значение угла в радианах

		float result = side_a * side_b * sin(angle_rad);
		cout << "ѕлощадь параллелограмма = " << result;
		interrupt();
		goto selectTask;
	}

task2:
	{
		cout << desc_t2;
		cout << "¬ведите значение X: ";
		float x = 0.0f;
		cin >> x;
		if (x - 5 == 0) {
			interrupt("”казано значение X, привод€щее к делению на 0.");
			goto task2;
		}
		cout << "«начение выражени€ (x+1)/(x-5) = " << (x + 1) / (x - 5);
		interrupt();
		goto selectTask;
	}

task3:
	{
		cout << desc_t3;
		float speed = 0;
		float distance = 0;
		cout << "¬ведите скорость движени€ Ўерлока: ";
		cin >> speed;
		cout << "¬ведите рассто€ние от Ўерлока до перекрЄстка: ";
		cin >> distance;
		Human Sherlock(speed, distance);

		cout << "¬ведите скорость движени€ ¬атсона: ";
		cin >> speed;
		cout << "¬ведите рассто€ние от ¬атсона до перекрЄстка: ";
		cin >> distance;
		Human Watson(speed, distance);

		if (Sherlock.timeToReachCrossroad() != Watson.timeToReachCrossroad())
			cout << "\nЎерлок и ¬атсон –ј«ћ»Ќ”“—я на перекрЄстке";
		else
			cout << "\nЎерлок и ¬атсон ¬—“–≈“я“—я на перекрЄтске";

		interrupt();
		goto selectTask;
	}

task4:
	{
		cout << desc_t4;
		cout << "¬ведите число: ";
		int num = 0;
		cin >> num;

		if (num > 100 || num < -100) num = 0;
		else num++;
		
		cout << "–езультат: " << num;
		interrupt();
		goto selectTask;
	}

	return 0;
}