
#include <iostream>

using namespace std;

int main()
{
	setlocale(LC_ALL, "Russian");
	
	unsigned int a, b, c;
	cout << "Введите два числа A и B: ";
	cin >> a >> b;

	unsigned int r, s;
	cout << "Введите два числа R и S: ";
	cin >> r >> s;
	
	unsigned int result1 = 0, result2 = 0, Final, Last;
	
	__asm {
	; start
		mov eax, a;		Делимое 16bit
		cdq;			eax > edx:eax
		mov ebx, b;		Делитель

		div ebx;		Деление
		mov Last, edx;	
		push eax;
		push edx;		Остаток от деления
		mov eax, r;		Число для сравнения 1
		mov ebx, s;		Число для сравнения 2

	; compare_r
		pop ecx;
		cmp eax, ecx;			Сравниваем r и остаток
		jz write_one;		
	
	compare_s:
		cmp ebx, ecx;			Сравниваем s и остаток
		jz write_two;
		jmp end_asm;
	
	write_one:
		mov result1, 1;		Пишем результат в result1
		jmp compare_s

	write_two:
		mov result2, 1;		Пишем результат в result2
		jmp end_asm
	
	end_asm:
		pop Final;
	}

	cout << "Частное: " << Final << endl;
	cout << "Остаток: " << Last << endl;

	if (result1 == 1)
		cout << "Остаток от деления равен R" << endl;
	else
		cout << "Остаток от деления не равен R" << endl;

	if (result2 == 1)
		cout << "Остаток от деления равен S" << endl;
	else
		cout << "Остаток от деления не равен S" << endl;
}