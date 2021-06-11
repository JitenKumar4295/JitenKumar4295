#include <iostream>
#include <math.h>
using namespace std;
class Vector
{
  private:
	int Coefficients[3];
	char v[3] = {'i', 'j','k'};
	char char_plus = '+';
	const static int VECTOR_PLUS = 63373;
	static const int VECTOR_MINUS = 7337;
	const static int VECTOR_DOT_PRODUCT = 23443;
	static const int VECTOR_CROSS_PRODUCT = 93437;

  public:
	Vector()
	{
		for (int i = 0; i < 3; i++)
			Coefficients[i] = 0;
	}
	Vector(int i, int j, int k)
	{
		Coefficients[0] = i;
		Coefficients[1] = j;
		Coefficients[2] = k;
	}
	Vector(int coefficients[3])
	{
		for (int i = 0; i < 3; i++)
			Coefficients[i] = coefficients[i];
	}
	void print()
	{
		cout<<toString ();
	}

	Vector static add(Vector a, Vector b)
	{
		Vector v;
		return v.operation(a, b, VECTOR_PLUS);
	}
	Vector static sub(Vector a, Vector b)
	{
		Vector v;
		return v.operation(a, b, VECTOR_MINUS);
	}
	double Magnitude()
	{
		int return_data = 0;
		for (int i = 0; i < 3; i++)
		{
			return_data += pow(Coefficients[i], 2);
		}
		return sqrt(return_data);
	}

	static int dot_product(Vector a, Vector b)
	{
		//VECTOR_DOT_PRODUCT:
		int scalar_value = 0;
		for (int i = 0; i < 3; i++)
		{
			scalar_value += a.Coefficients[i] * b.Coefficients[i];
		}
		return scalar_value;
	}
	static Vector cross_product(Vector a, Vector b)
	{
		//VECTOR_CROSS_PRODUCT:
		Vector v;
		return v.operation(a, b, VECTOR_CROSS_PRODUCT);
	}
	string toString()
	{
		string re = "";
		for (int i = 0; i < 3; i++)
		{
			re += to_string(Coefficients[i]) + v[i];
			if (i < 2)
			{
				if (Coefficients[i + 1] >= 0)
				re+=char_plus;
			}
			else
			re+='\n';
		}
		return re;
	}

  private:
	Vector operation(Vector a, Vector b, int operation_type)
	{
		int mag[3];
		switch (operation_type)
		{
		case VECTOR_PLUS:
		{
			for (int i = 0; i < 3; i++)
				mag[i] = a.Coefficients[i] + b.Coefficients[i];
			break;
		}

		case VECTOR_MINUS:
		{
			for (int i = 0; i < 3; i++)
				mag[i] = a.Coefficients[i] - b.Coefficients[i];
			break;
		}
		case VECTOR_CROSS_PRODUCT:
		{
			mag[0] = a.Coefficients[1] * b.Coefficients[2] -
					 a.Coefficients[2] * b.Coefficients[1];

			mag[1] = -(a.Coefficients[0] * b.Coefficients[2] -
					   a.Coefficients[2] * b.Coefficients[0]);

			mag[2] = a.Coefficients[0] * b.Coefficients[1] -
					 a.Coefficients[1] * b.Coefficients[0];
			break;
		}
		}
		Vector r(mag);
		return r;
	}
};
