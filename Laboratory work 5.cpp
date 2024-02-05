#include <iostream>
using namespace std;

const int N = 1000;
//int one_arr[] = { 4, 5, 6, 1, 2, 3, 7, 8, 9, 3, 6, 9, 2, 5, 8, 1, 4, 7 };
//int lenght = 18;
int one_arr[] = {5, 6, 7, 8, 1, 2, 3, 4, 9, 10, 11, 12, 4, 8, 12, 3, 7, 11, 2, 6, 10, 1, 5 ,9};
int lenght = 24;
int first_in_rows[N];
int first_in_column[N];
int first_elements[N];
int two_arr[N][N];
int width, height;
int index;
int first;

void one_arr_printer()
{
	cout << "Одномерный массив: \n";
	for (int i = 0; i < lenght; i++)
	{
		cout << one_arr[i] << " ";
	}
	cout << "\n";
}

void first_element_in_rows()
{
	//searching to first element in rows
	index = 0;
	cout << "Первые элементы строк: \n";
	for (int i = 0; i < height; i++)
	{
		first_in_rows[i] = one_arr[index];
		cout << one_arr[index] << " ";
		index = index + width;
	}
	cout << "\n";
}

void first_element_in_column()
{
	//searching to first element in column
	index = width * height;
	cout << "Первые элементы столбцов: \n";
	for (int i = 0; i < width; i++)
	{
		first_in_column[i] = one_arr[index];
		cout << one_arr[index] << " ";
		index = index + height;
	}
	cout << "\n";
}

void first_element_in_rows_and_column()
{
	//searching to first element in rows and column
	bool flag = true;
	for (int i = 0; i < height; i++)
	{
		if (flag)
			first = first_in_rows[i];
		//cout << "i = " << i << " first_in_rows[i] = " << first_in_rows[i] << "\n";
		for (int j = 0; j < width; j++)
		{
			//cout << "j = " << j << " first_in_column[j] = " << first_in_column[j] << "\n";
			if (first == first_in_column[j])
				flag = false;
		}
	}
	cout << "Первый элемент: " << first << "\n";
}

void array_with_first_row()
{
	//creating an array with the first elements
	cout << "Первая строка двумерного массива: \n";
	for (int i = 0; i < width * height; i++)
	{
		if (first == one_arr[i])
		{
			index = i;
			for (int j = 0; j < width; j++)
			{
				first_elements[j] = one_arr[index];
				two_arr[j][0] = one_arr[index];
				cout << one_arr[index] << " ";
				index++;
			}
		}
	}
	cout << "\n";
}

void two_dimensional_array(int* a)
{
	//restoration of a two-dimensional array
	for (int i = width * height; i < width * height * 2; i++)
	{
		for (int j = 0; j < width; j++)
		{
			if (a[i] == two_arr[j][0])
			{
				for (int k = 1; k < height; k++)
				{
					two_arr[j][k] = a[i + k];
					cout << "i = " << i << " j = " << j << " k = " << k << " two_arr[j][k] = " << two_arr[j][k] << "\n";
				}
			}
		}
	}
}

void two_arr_printer()
{
	//output of the reconstructed two-dimensional array
	cout << "Двумерный массив: \n";
	for (int i = 0; i < height; i++)
	{
		for (int j = 0; j < width; j++)
		{
			cout << two_arr[j][i] << '\t';
		}
		cout << "\n";
	}
}

int main()
{
	setlocale(LC_ALL, "Rus");
	one_arr_printer();
	cout << "Введите ширину и длину двухмерного массива: ";
	cin >> width >> height;
	first_element_in_rows();
	first_element_in_column();
	first_element_in_rows_and_column();
	array_with_first_row();
	two_dimensional_array(one_arr);
	two_arr_printer();
}