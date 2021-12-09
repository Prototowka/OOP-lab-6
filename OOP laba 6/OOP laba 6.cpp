
#include <iostream>
#include <string>
#include <locale>
#include <time.h>
#include <list>

using namespace std;

class polinom
{
public:
	float sum(float factor1, string polinom1, float degree1, float factor2, string polinom2, float degree2)
	{
		string answer;
		if ((polinom1 == polinom2) && (degree1 == degree2))
		{
			cout << factor1 + factor2 << polinom1 << "^" << degree1 << endl;
		}
		else
		{
			cout << factor1 << polinom1 << "^" << degree1 << "+" << factor2 << polinom2 << "^" << degree2 << endl;
		}
		return 0;
	}

	float umn(float a, string b, float c, string d)
	{
		if (b != d)
		{
			cout << a * c << b << "*" << d << endl;
		}
		if (b == d)
		{
			cout << a * c << b << "^2" << endl;
		}
		return 0;
	}
};

class Matrix
{
public:
	float create(float a, float b)
	{
		srand(time(NULL));
		float* matrix = new float[a, b];
		int i, j;
		for (i = 0; i < a; i++)
		{
			for (j = 0; j < b; j++)
			{
				matrix[i, j] = rand() % 100;
				cout << matrix[i, j] << " ";
			}
			cout << endl;
		}
		return 0;
	}

	float copy(float matrix[], float length, float width)
	{
		float* matrixThree = new float[length, width];
		int i, j;
		for (i = 0; i < length; i++)
		{
			for (j = 0; j < width; j++)
			{
				matrixThree[i, j] = matrix[i, j];
				cout << matrixThree[i, j] << " ";
			}
			cout << endl;
		}
		return 0;
	}

	float sum(float matrix1[], float matrix2[], int length, int width)
	{
		float* matrixSum = new float[length, width];
		int i, j;
		for (i = 0; i < length; i++)
		{
			for (j = 0; j < width; j++)
			{
				matrixSum[i, j] = matrix1[i, j] + matrix2[i, j];
				cout << matrixSum[i, j] << " ";
			}
			cout << endl;
		}
		return 0;
	}

	float maximum(float matrix[], float  length, float width)
	{
		float max = -1;
		int i, j;
		for (i = 0; i < length; i++)
		{
			for (j = 0; j < width; j++)
			{
				if (matrix[i, j] > max) max = matrix[i, j];
			}
		}
		cout << "Максимальный элемент матрицы=" << max << endl;
		return 0;
	}
};

int main()
{
	srand(time(NULL));
	setlocale(LC_ALL, "RUSSIAN");

	int length = 5, width = 5;//Значения размера матрицы
	int i, j;
	polinom test;

	test.sum(2, "ab", 5, 5, "ab", 5);//Сумма при равных полиномах и их степенях
	test.sum(3, "abc", 2, 7, "def", 3);//Все остальные случаи(равные полиномы и неравные степени, неравные полиномы и равные степени, неравные полиномы и неравные степени)


	Matrix x;
	cout << endl << "Создание матрицы по заданным параметрам" << endl;
	x.create(5, 5);

	//Переписать выделение памяти

	float* matrixTwo = new float[length, width];
	for (i = 0; i < length; i++)
	{
		for (j = 0; j < width; j++)
		{
			matrixTwo[i, j] = rand() % 150;
			cout << matrixTwo[i, j] << " ";
		}
		cout << endl;
	}
	cout << endl << "Создание матрицы копированием другой матрицы" << endl;
	x.copy(matrixTwo, length, width);

	float* matrixFour = new float[length, width];
	float* matrixFive = new float[length, width];
	for (i = 0; i < length; i++)
	{
		for (j = 0; j < width; j++)
		{
			matrixFour[i, j] = rand() % 200;
			matrixFive[i, j] = rand() % 50;
		}
	}
	cout << endl << "Сумма матриц" << endl;
	x.sum(matrixFour, matrixFive, length, width);
	x.maximum(matrixTwo, length, width);

	//Задание 3
	list<int> list1{ 1, 15,62,2,75,332,22,124 }, list2;
	int Pos=1,maxPos,max = -1, size = list1.size();

	cout << endl << "Всего элементов в списке list1:" << size << endl;
	for (i = 0; i < size; i++)
	{
		if (list1.front() > max)
		{
			max = list1.front();
			maxPos = Pos;
		}
		Pos++;
		list1.pop_front();
	}
	list2.push_front(maxPos);
	cout << "Максимальный элемент списка list1 находится на " << maxPos << " позиции" << endl;
}

