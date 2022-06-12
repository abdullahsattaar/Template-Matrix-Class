#include<iostream>
using namespace std;


template <typename T>
class Matrix
{
private:

	int rows;
	int cols;
	T** matrix;

public:

	Matrix()
	{
		matrix = nullptr;
	}
	template < typename T > 
	Matrix(T rs, T cs)
	{
		rows = rs;
		cols = cs;
		matrix = new T*[rs];
		for (int i = 0; i < rows;i++)
	    *matrix[i] = new T**[cs];
	}
	template < typename T >
	Matrix(Matrix const & obj)
	{
		rows = obj.rows;
		cols = obj.cols;
		matrix = new T*[rs];
		for (int i = 0; i < rows; i++)
			*matrix[i] = new T**[cs];
		for (int i = 0; i < rows; i++)
		{
			for (int j = 0; j < cols; j++)
				matrix[i][j] = obj[i][j];
		}
	}

	void insertElement(T const & element, int rowNo, int colNo)
	{
		matrix[rowNo][colNo] = element;
	}
	Matrix <T> operator +(Matrix const& obj)
	{
		if (rows = obj.rows&&cols = obj.cols)
		{
			resultmatrix = new T*[rows];
			for (int i = 0; i < rows; i++)
			*resultmatrix[i] = new T**[cols];
			for (int i = 0; i < rows; i++)
			{
				for (int j = 0; j < cols; j++)
					resultmatrix[i][j] = this.matrix[i][j] + obj[i][j];
			}
			return resultmatrix;
		}
		else
			cout << "ERROR";
	}

	void print()
	{
		for (int i = 0; i < rows; i++)
		{
			for (int j = 0; j < cols; j++)
				cout << matrix[i][j] << " ";
			cout << endl;
		}
	}

	void transpose()
	{
		T**newmatrix;
		newmatrix = new T*[cols];
		for (int i = 0; i < rows; i++)
		*newmatrix[i] = new T**[rows];
		for (int i = 0; i < rows; i++)
		{
			for (int j = 0; j < cols; j++)
				newmatrix[i][j] = matrix[j][i];
		}
		matrix = new T*[cols];
		for (int i = 0; i < rows; i++)
		*matrix[i] = new T**[rows];
		for (int i = 0; i < rows; i++)
		{
			for (int j = 0; j < cols; j++)
				matrix[i][j] = newmatrix[i][j];
		}
		delete newmatrix;

	}

	~Matrix()
	{
		delete matrix;
	}
};

template<class T>
class Matrix < char* >
{
	T***Deps;
	int rows;
	int cols;
	int x = 1;
public:

	Matrix<char>(int rows, int cols)
	{
		Deps = new T[x];
		for (int i = 0; i < x; i++)
		{
			*Deps[i] = new T[rows];
			for (int j = 0; j < rows; j++)
				**Deps[i][j] = new T***[cols];
		}
	}
	template<typename T>
	Matrix operator+(Matrix const& obj) 
	{
		T*** newdep = new T **[x];
		for (int i = 0; i < x; i++) {
			newdep[i] = new T *[obj[i] + rows];
			for (int j = 0; j < col; ++j)
				newdep[i][j] = new T[obj[j] + cols];
		}
		for (int i = 0; i < x; i++) {
			for (int j = 0; j < cols; ++j) {
				strcat(newdep[i][j], dep[i][j]);
				strcat(newdep[i][j], obj[i][j-cols]);
			}
		}
		return newdep;
	}
	template<typename T>
	Matrix<char*> operator=(Matrix<char*> const& obj) {
		for (int i = 0; i < obj.rows; ++i)
			for (int j = 0; j < obj.colmns; ++j)
				*dep[i][j] = obj[i][j];
	}
	template<typename T>
	bool operator==(Matrix<char*> const& obj) {
		if (rows == obj.rows && cols = obj.cols)
			for (int i = 0; i < rows; ++i)
				for (int j = 0; j < cols; ++j)
					if (matrix[i][j] == obj[i][j])
						cout << "Equal matrix" << endl;
					else
						cout << "Not Equal matrix " << endl;
		else
			cout << "Not equal matrix" << endl;
	}
};



int main()
{
	Matrix<int> m1(2, 3);
	m1.insertElement(1, 0, 0);
	m1.insertElement(1, 0, 1);
	m1.insertElement(1, 0, 2);
	m1.insertElement(0, 1, 0);
	m1.insertElement(0, 1, 1);
	m1.insertElement(0, 1, 2);
	m1.transpose();
	Matrix<int> m2(2, 3);
	m2.insertElement(-1, 0, 0);
	m2.insertElement(-1, 0, 1);
	m2.insertElement(-1, 0, 2);
	m2.insertElement(10, 1, 0);
	m2.insertElement(5, 1, 1);
	m2.insertElement(1, 1, 2);
	m2.transpose();
	Matrix<int> m3(m2);
	Matrix<int> m4(m1 + m3);
	m4.transpose();
	m4.print();

	Matrix<char*> mA(2, 2);
	mA.insertElement((char*)"Computer", 0, 0);
	mA.insertElement((char*)"Electrical", 0, 1);
	mA.insertElement((char*)"Business", 1, 0);
	mA.insertElement((char*)"Civil", 1, 1);

	Matrix<char*> mB(2, 2);
	mB.insertElement((char*)"Science", 0, 0);
	mB.insertElement((char*)"Engineering", 0, 1);
	mB.insertElement((char*)"Administration", 1, 0);
	mB.insertElement((char*)"Engineering", 1, 1);

	Matrix<char*> mC(1, 1);
	Matrix<char*> mD(1, 1);
	mC = mA + mB;
	mD = mA + mB;

	mC.transpose();
	mC.print();
	mC == mD;


	system("pause");
	return 0;
}