#include <iostream>
using namespace std;
//example 1
class Base {
protected:
	int dat;
	double a[5] = { 9,2,8,1,4 };
public:
	Base() : dat(1) {}
	Base(int d) : dat(d) {}
};
class D: protected Base{
protected:
	int datd;
public:
	D() : datd(1) {}
	D(int d) : datd(d) {}
	D(int dat, int datd) : Base(dat),datd(datd) {}
};
class D2 :protected D {
protected:
	int d2;
public:
	D2() : d2(1) {}
	D2(int d) : d2(d) {}
	D2(int datd1, int datd2, int d2) : D(datd1,datd2), d2(d2) {}
};
class D1 :protected D, protected D2 {
protected:
	int d1;
public:
	D1() : d1(1) {}
	D1(int d) : d1(d) {}
	D1(int datd1,int datd2,int d2a,int d2b,int d2c,int d1) : D(datd1,datd2), D2(d2a,d2b,d2c), d1(d1) {}
};
class BD :protected Base, protected D {
protected:
	int bd;
public:
	BD() : bd(1) {}
	BD(int d) : bd(d) {}
	BD(int dat, int b, int c, int d) : Base(dat), D(b,c), bd(d) {}
};
class R1 : protected BD {
protected:
	int r1;
public:
	R1() : r1(1) {}
	R1(int d) : r1(d) {}
	R1(int dat, int b, int c, int d, int r1) : BD(dat, b, c, d), r1(r1 + 1.) {}
};
class R2 :protected D1,protected D2{
protected:
	int r2;
public:
	R2() : r2(1) {}
	R2(int d) : r2(d) {}
	R2(int datd1, int datd2, int d2a, int d2b, int d2c, int d1,int d1a,int d1b,int d1c, int r2) : D1(datd1, datd2, d2a, d2b, d2c, d1), D2(d1a, d1b, d1c), r2(r2 + 1.) {}
};

//VIRTUAL
class DV :virtual protected Base {
protected:
	int d1;
public:
	DV() : d1(1) {}
	DV(int d) : d1(d) {}
	DV(int d, int dt) : Base(d), d1(dt) {}
};
class D2V :virtual protected DV {
protected:
	int d2v;
public:
	D2V() : d2v(1) {}
	D2V(int d) : d2v(d) {}
	D2V(int d1,int d2, int dt) : DV(d1,d2), d2v(dt) {}
};
class D1V :virtual public DV, virtual protected D2V{
protected:
	int d1;
public:
	D1V() : d1(1) {}
	D1V(int d) : d1(d) {}
	D1V(int datd1, int datd2, int d2a, int d2b, int d2c, int d1) : DV(datd1, datd2), D2V(d2a, d2b, d2c), d1(d1) {}
};
class BDV :virtual public DV, virtual public Base {
protected:
	int bdv;
public:
	BDV() : bdv(1) {}
	BDV(int d) : bdv(d) {}
	BDV(int dat, int b, int c, int d) :Base(dat), DV(b, c), bdv(d) {}
};
class R1V :virtual protected BDV {
protected:
	int r1;
public:
	R1V() : r1(1) {}
	R1V(int d) : r1(d) {}
	R1V(int dat, int b, int c, int d, int r1) :BDV(dat, b, c, d), r1(r1 + 1.) {}
	void showDat()
	{
		cout << "  bdv =  " << bdv << endl;
		cout << "BDV::Base::dat =  " << BDV::Base::dat << endl;
		cout << "BDV::DV::Base::dat =  " << BDV::DV::Base::dat << endl;
	}
};
	class R2V :virtual protected D1V, virtual protected D2V {
	protected:
		int r2;
	public:
		R2V() : r2(1) {}
		R2V(int d) : r2(d) {}
		R2V(int datd1, int datd2, int d2a, int d2b, int d2c, int d1, int d1a, int d1b, int d1c, int r2) : D1V(datd1, datd2, d2a, d2b, d2c, d1), D2V(d1a, d1b, d1c), r2(r2 + 1.) {}
		void showDat()
		{
			cout << "  d1 =  " << d1 << endl;
			cout << "  d2v =  " << d2v << endl;
			cout << "D1V::DV::Base::dat =  " << D1V::DV::Base::dat << endl;
			cout << "D2V::DV::Base::dat =  " << D2V::DV::Base::dat << endl;
			cout << "D1V::D2V::DV::Base::dat =  " << D1V::D2V::DV::Base::dat << endl;
		}
	};

	void MenuExample() {
		cout << "     Menu Example   \n";
		cout << "    1   Example 1  \n";
		cout << "    2   Example 2  \n";
		cout << "    3   Example 3  \n";

		cout << "    4 or e  Exit \n";

	}
	//Exercise 2
	class Korin {
	public:
		virtual void Rivnya() = 0;
	};
	class Lin : public Korin {
	private:
		double a;
		double b;
		double x;
	public:
		Lin() :a(2), b(10) { cout << "Linear equation of the form: " << a << "x = " << b << endl; }
		Lin(double ai, double bi) : a(ai), b(bi) { cout << "Linear equation of the form: " << a << "x = " << b << endl; }

		void Rivnya() override {
			x = b / a;
			cout << "x = " << x << endl;
		}
	};
	class Kvad :public Korin {
	private:
		double a, b, c;
		double x1, x2;
	public:
		Kvad() :a(1), b(2), c(1)
		{
			if (b > 0)
			{
				cout << "Quadratic equation of the form: " << a << "x^2+" << b << "x";
			}
			else cout << "Quadratic equation of the form: " << a << "x^2" << b << "x";
			if (c > 0)
			{
				cout << "+" << c << " = 0" << endl;
			}
			else cout << c << " = 0" << endl;
		}
		Kvad(double ai, double bi, double ci) :a(ai), b(bi), c(ci)
		{
			if (b > 0)
			{
				cout << "Quadratic equation of the form: " << a << "x^2+" << b << "x";
			}
			else cout << "Quadratic equation of the form: " << a << "x^2" << b << "x";
			if (c > 0)
			{
				cout << "+" << c << " = 0" << endl;
			}
			else cout << c << " = 0" << endl;
		}
		void Rivnya() override {
			double d;
			d = b * b - 4 * a * c;
			if (d < 0)
			{
				cout << "There is no solution" << endl;
			}
			else
			{
				x1 = (-b - sqrt(d)) / (2 * a);
				x2 = (-b + sqrt(d)) / (2 * a);
				cout << "x1 = " << x1 << ";\tx2 = " << x2 << endl;
			}
		}
	};
	class Bikvad : public Korin {
	private:
		double a, b, c;
		double x1, x2, x3;
	public:
		Bikvad() :a(1), b(-5), c(-36)
		{
			if (b > 0)
			{
				cout << "BiQuadratic equation of the form: " << a << "x^4+" << b << "x^2";
			}
			else cout << "BiQuadratic equation of the form: " << a << "x^4" << b << "x^2";
			if (c > 0)
			{
				cout << " +" << c << endl;
			}
			else cout << " " << c << endl;
		}
		Bikvad(double ai, double bi, double ci) :a(ai), b(bi), c(ci)
		{
			if (b > 0)
			{
				cout << "BiQuadratic equation of the form: " << a << "x^4+" << b << "x^2";
			}
			else cout << "BiaQuadratic equation of the form: " << a << "x^4" << b << "x^2";
			if (c > 0)
			{
				cout << "+" << c << " = 0" << endl;
			}
			else cout << c << " = 0" << endl;
		}
		void Rivnya() override {
			double d;
			double x1x, x2x;
			d = b * b - 4 * a * c;
			x1x = (-b - sqrt(d)) / 2 * a;
			x2x = (-b + sqrt(d)) / 2 * a;
			if (x1x > 0)
			{
				cout << "x1 = " << sqrt(x1x) << "; x2 = " << -sqrt(x1x) << endl;
			}
			if (x2x > 0)
			{
				cout << " x3 = " << sqrt(x2x) << "; x4 = " << -sqrt(x2x) << endl;
			}
			if (x1x < 0 && x2x < 0)
			{
				cout << "Not solution" << endl;
			}
		}
	};
	class Rozv
	{
	public:
		void Rivnya(Korin* korin)
		{
			korin->Rivnya();
		}
	};
	//Exersis 3
	class Transport {
	public:
		virtual void Ryx() = 0;
	};

	class Korabel :virtual public Transport {
	public:
		void Ryx() override
		{
			cout << "Tyyy TYYYyyy!" << endl;
		}
	};

	class Pass_Transport : virtual public Transport {
	public:
		void People()
		{
			cout << "Bla Bla Bla!" << endl;
		}
		void Ryx() override
		{
			cout << "Bi Biip!" << endl;
		}
	};

	class Pass_Korabel : public Korabel, public Pass_Transport
	{
	public:
		void Music()
		{
			cout << "Bymc BymC Bymc!" << endl;
		}
		void Ryx() override
		{
			cout << "Tyyy Bymcc TYYYyyy TyyyYy!" << endl;
		}
	};

	class Shym
	{
	public:
		void Ryx(Transport* t)
		{
			t->Ryx();
		}
	};
	int main()
	{
		cout << "OOP. Example for laboratory work #6.\n";

		char ch = '5';
		do {
			system("cls");
			MenuExample();
			ch = cin.get();

			cin.get();

			switch (ch) {
			case '1': {
				cout << " Example1  \n";
				R1 a1, b1(1, 2, 3, 4.5, 52);
				R2 a2, b2(1, 2, 3, 4.5, 5, 6, 7, 8, 9, 10);
				R1V a1v, b1v(1, 2, 3, 4.5, 52);
				R2V a2v, b2v(1, 2, 3, 4.5, 5, 6, 7, 8, 9, 10);

				cout << "Test !\n";
				cout << "Size for Base " << sizeof(Base) << endl;
				cout << "Size for D " << sizeof(D) << endl;
				cout << "Size for D1 " << sizeof(D1) << endl;
				cout << "Size for D2 " << sizeof(D2) << endl;
				cout << "Size for BD " << sizeof(BD) << endl;
				cout << "Size for R1 " << sizeof(R1) << endl;
				cout << "Size for R2 " << sizeof(R2) << endl;
				cout << "\n" << endl;
				cout << "Size for Base " << sizeof(Base) << endl;
				cout << "Size for DV " << sizeof(DV) << endl;
				cout << "Size for D1V " << sizeof(D1V) << endl;
				cout << "Size for D2V " << sizeof(D2V) << endl;
				cout << "Size for BDV " << sizeof(BDV) << endl;
				cout << "Size for R1V " << sizeof(R1V) << endl;
				cout << "Size for R2V " << sizeof(R2V) << endl;

				cout << "Size for object class R1 " << sizeof(R1) << " or  "
					<< sizeof(a1) << " or  " << sizeof(b1) << endl;
				cout << "Size for object class R2 " << sizeof(R2) << " or  "
					<< sizeof(a2) << " or  " << sizeof(b2) << endl;
				cout << "Size for object class R1V " << sizeof(R1V) << " or  "
					<< sizeof(a1v) << " or  " << sizeof(b1v) << endl;
				cout << "Size for object class R2V " << sizeof(R2V) << " or  "
					<< sizeof(a2v) << " or  " << sizeof(b2v) << endl;
				b1v.showDat();
				b2v.showDat();
				return 0;
				break;
			}
			case '2': {
				cout << " Example2  \n";
				Rozv rivnyan;
				cout << "Test Linear equation" << endl;
				Lin La(2, 14);
				rivnyan.Rivnya(&La);
				cout << "Constructor ()" << endl;
				Lin Lb;
				rivnyan.Rivnya(&Lb);
				cout << "Test Quadratic equation" << endl;
				Kvad Kc(2, 9, -18);
				rivnyan.Rivnya(&Kc);
				Kvad Ke(2, -5, -25);
				rivnyan.Rivnya(&Ke);
				Kvad Kj(1, -1, 1);
				rivnyan.Rivnya(&Kj);
				cout << "Constructor ()" << endl;
				Kvad Kd;
				rivnyan.Rivnya(&Kd);
				cout << "Test BiQuadratic equation" << endl;
				Bikvad Bt(1, 1, -30);
				rivnyan.Rivnya(&Bt);
				cout << "Constructor ()" << endl;
				Bikvad By;
				rivnyan.Rivnya(&By);
				break;
			}
			case '3': {
				Shym f;
				Korabel kor;
				Pass_Korabel pkor;
				Pass_Transport pt;
				f.Ryx(&kor);
				f.Ryx(&pkor);
				pkor.People();
				f.Ryx(&pt);
				pt.People();

				break;
			}
			case '4':  return 0;
			case 'e':  return 0;
			}
			cout << " Press any key and enter\n";
			ch = cin.get();
		} while (ch != '6');


	}
