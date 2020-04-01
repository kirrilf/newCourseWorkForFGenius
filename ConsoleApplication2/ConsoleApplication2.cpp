
#include <iostream>
#include "windows.h"
#include <conio.h>
#include <string>
#include <locale>

using namespace std;



void gotoxy(int xpos, int ypos)
{
	COORD scrn;

	HANDLE hOuput = GetStdHandle(STD_OUTPUT_HANDLE);

	scrn.X = xpos; scrn.Y = ypos;

	SetConsoleCursorPosition(hOuput, scrn);
}

struct coef
{
	int numDegree;
	int coefficient;
	coef* next = 0;

};


coef* addition(coef* firstPolinom, coef* secondPolinom) {
	coef* temp = firstPolinom;
	coef* additionPolinomFirstElement = 0;
	coef* additionPolinomLastElement = 0;

	while (temp) {
		coef* Element = new coef;
		Element->coefficient = temp->coefficient;
		Element->numDegree = temp->numDegree;
		if (additionPolinomFirstElement == 0 && additionPolinomLastElement == 0) {
			additionPolinomFirstElement = Element;
			additionPolinomLastElement = Element;
		}
		else {
			additionPolinomLastElement->next = Element;
			additionPolinomLastElement = Element;
		}
		temp = temp->next;
	}

	temp = additionPolinomFirstElement;
	while (temp) {
		coef* temp2 = secondPolinom;
		while (temp2) {
			if (temp->numDegree == temp2->numDegree) {
				temp->coefficient = temp->coefficient + temp2->coefficient;
			}	
			temp2 = temp2->next;
		}

		temp = temp->next;
	}

	temp = secondPolinom;

	while (temp) {
		bool findingFlag = false;
		coef* temp2 = additionPolinomFirstElement;
		while (temp2) {
			if (temp->numDegree == temp2->numDegree) {
				findingFlag = true;
			}
			temp2 = temp2->next;
		}
		if (!findingFlag) {
			additionPolinomLastElement->next = temp;
			additionPolinomLastElement = temp;
		}

		temp = temp->next;
	}
	return additionPolinomFirstElement;
}

coef* difference(coef* firstPolinom, coef* secondPolinom) {
	coef* temp = firstPolinom;
	coef* additionPolinomFirstElement = 0;
	coef* additionPolinomLastElement = 0;
	while (temp) {
		coef* Element = new coef;
		Element->coefficient = temp->coefficient;
		Element->numDegree = temp->numDegree;
		if (additionPolinomFirstElement == 0 && additionPolinomLastElement == 0) {
			additionPolinomFirstElement = Element;
			additionPolinomLastElement = Element;
		}
		else {
			additionPolinomLastElement->next = Element;
			additionPolinomLastElement = Element;
		}
		temp = temp->next;
	}
	temp = additionPolinomFirstElement;
	while (temp) {
		coef* temp2 = secondPolinom;
		while (temp2) {
			if (temp->numDegree == temp2->numDegree) {
				temp->coefficient = temp->coefficient - temp2->coefficient;
			}
			temp2 = temp2->next;
		}

		temp = temp->next;
	}
	temp = secondPolinom;

	while (temp) {
		bool findingFlag = false;
		coef* temp2 = additionPolinomFirstElement;
		while (temp2) {
			if (temp->numDegree == temp2->numDegree) {
				findingFlag = true;
			}
			temp2 = temp2->next;
		}
		if (!findingFlag) {
			additionPolinomLastElement->next = temp;
			additionPolinomLastElement = temp;
		}

		temp = temp->next;
	}
	return additionPolinomFirstElement;
}



int firstMenu() {
	system("cls");
	gotoxy(10, 5);
	//cout << endl;
	cout << "Сложение, разность, умножение, деление(с остатком) полиномов";
	gotoxy(32, 13);
	cout << "Ввод полиномом " << endl;
	gotoxy(32, 14);
	cout << "Выход" << endl;
	int positionOnArrow = 0;
	while (true) {


		gotoxy(48, positionOnArrow+13);

		cout << "<----";

		int keyNumber = _getch();

		gotoxy(48, positionOnArrow+13);

		cout << "     ";

		if (keyNumber == 224) {
			int temp = _getch();
			if (temp == 72) {

				if (positionOnArrow == 0) {
					positionOnArrow = 1;
				}
				else {
					positionOnArrow--;
				}
			}
			else if (temp == 80) {
				if (positionOnArrow == 1) {
					positionOnArrow = 0;
				}
				else {
					positionOnArrow++;
				}
			}
		}
		else if (keyNumber == 13) {
			return positionOnArrow;
		}




	}
}

int secondMenu() {
	system("cls");
	gotoxy(10, 5);
	//cout << endl;
	cout << "Сложение, разность, умножение, деление(с остатком) полиномов";
	gotoxy(32, 13);
	cout << "Сложение" << endl;
	gotoxy(32, 14);
	cout << "Вычитание" << endl;
	gotoxy(32, 15);
	cout << "Умножение" << endl;
	gotoxy(32, 16);
	cout << "Деление" << endl;
	int positionOnArrow = 0;
	while (true) {


		gotoxy(48, positionOnArrow + 13);

		cout << "<----";

		int keyNumber = _getch();

		gotoxy(48, positionOnArrow + 13);

		cout << "     ";

		if (keyNumber == 224) {
			int temp = _getch();
			if (temp == 72) {

				if (positionOnArrow == 0) {
					positionOnArrow = 3;
				}
				else {
					positionOnArrow--;
				}
			}
			else if (temp == 80) {
				if (positionOnArrow == 3) {
					positionOnArrow = 0;
				}
				else {
					positionOnArrow++;
				}
			}
		}
		else if (keyNumber == 13) {
			return positionOnArrow;
		}




	}
}


coef* enterPolinom() {
	coef* firstElement = 0;
	coef* lastElement = 0;
	string polinom;
	cin >> polinom;
	bool degreeFlag = false, stopic = false;
	int negativeFlag = 1;
	int num = 0, numDegree = 0;
	for (auto now : polinom) {
		if (now == '-' || now == '+'|| now == '=') {
			degreeFlag = false;
			//cout << num * negativeFlag<< " " << numDegree<< endl;
			coef* Element = new coef;
			Element->coefficient = num * negativeFlag;
			Element->numDegree = numDegree;
			coef* temp;
			if (firstElement == 0 && lastElement == 0) {
				firstElement = Element;
				lastElement = Element;
			}
			else {
				temp = lastElement;
				lastElement = Element;
				temp->next = Element;
			}
			num = 0;
			numDegree = 0;
			negativeFlag = 1;
			if (now == '-') {
				negativeFlag = -1;
			}
		}
		else if (int(now) > 48 && int(now) < 58 && !degreeFlag) {
			num *= 10;
			num += int(now) - 48;
		}
		else if (int(now) > 48 && int(now) < 58 && degreeFlag) {
			numDegree *= 10;
			numDegree += int(now) - 48;
		}
		else if (now == '^') {
			degreeFlag = true;
		}

	}

	

	return firstElement;
}

int start(){
	if (firstMenu() == 0) {
		system("cls");
		coef *firstPolinom = enterPolinom();
		coef *secondPolinom = enterPolinom();
		coef* temp;
		int choiceMenu = secondMenu();
		if (choiceMenu == 0) {
			system("cls");
			temp = addition(firstPolinom, secondPolinom);
			while (temp) {
				cout << temp->coefficient << " " << temp->numDegree << endl;
				temp = temp->next;
			}

		}
		else if (choiceMenu == 1) {
			system("cls");
			temp = difference(firstPolinom, secondPolinom);
			while (temp) {
				cout << temp->coefficient << " " << temp->numDegree << endl;
				temp = temp->next;
			}
		}
		else if (choiceMenu == 2) {
			system("cls");
		}
		else if (choiceMenu == 3) {
			system("cls");
		}
	}
	else {
		exit(0);
	}

}


int main()
{
	setlocale(LC_ALL, "Russian");
	start();
	
	return 0;
}