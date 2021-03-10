#include <iostream>
#include <string>

using namespace std;

/*transmiterea prin valoarea*/
void incrementeaza(int x)
{
	x = x + 1;
}

/*transmiterea prin referinta*/
void incrementeaza2(int& x)
{
	x = x + 1;
}

/*transmiterea prin pointere(adresa)*/
void incrementeaza3(int* x)
{
	*x = *x + 1;
}

/*transmitere prin valoare*/
void incrementeaza4(int* x)
{
	x = x + 1;
}

/*enumeratii*/
enum culori
{
	negru = 1, albastru = 2, verde = 3, mov = 4, galben
};

/*uniunea*/
union codProdus
{
	short codAlimente;
	int codElectronice;
	long long codNealimentare;
	double codPromotii;
};

class masina
{
public:
	string marca;
	int pret;
	double greutate;

	void schimbaModel(string schimbaModel)
	{
		if(model.length() == schimbaModel.length())
		{
			model = schimbaModel;
		}
	}

	masina()
	{
		marca = "Necunoscuta";
		model = "Necunoscut";
		pret = 0;
		greutate = 0.0;
		cout << "S-a apelata constructorul implicit !" << endl;

	}

	masina(string marca, string model, int pret, double greutate)
	{
		this->marca = marca;
		this->model = model;
		this->pret = pret;
		this->greutate = greutate;
		cout << "S-a apelat constructorul cu parametrii !" << endl;
	}

	~masina()
	{
		cout << "S-a apelat destructorul !" << endl;
	}

	string getModel()
	{
		return model;
	}

	void setModel(string model)
	{
		this->model = model;
	}

private:
	string model = "SUV";

};

int main()
{
	cout << "------transmiterea prin valoarea-------" << endl;
	int x = 10;
	incrementeaza(x);
	cout << x << endl;

	cout << "------transmiterea prin referinta-------" << endl;
	incrementeaza2(x);
	cout << x << endl;

	cout << "------transmiterea prin pointer-------" << endl;
	incrementeaza3(&x);
	cout << x << endl;

	cout << "------adresa pointer-------" << endl;
	int* pointer = &x;
	cout << pointer << endl;

	cout << "------transmiterea pointer prin valoarea-------" << endl;
	incrementeaza4(pointer);
	cout << pointer << endl;


	cout << "------enum-------" << endl;
	culori c = culori::verde;
	cout << c << endl;

	c = (culori) 1;
	cout << c << endl;

	codProdus cod;
	cod.codElectronice = 1234;
	cout << cod.codElectronice << endl;
	cout << cod.codAlimente << endl;
	cod.codPromotii = 10204;
	cout << cod.codPromotii << endl;
	cout << cod.codNealimentare << endl;

	cout << "------obiect masina-------" << endl;
	masina m;
	m.greutate = 1300;
	cout << m.greutate << endl;
	cout << m.getModel() << endl;

	m.setModel("Dacia");
	cout << m.getModel() << endl;

	cout << "------opiect masina de tip pointer-------" << endl;
	masina* pm;
	pm = &m;
	cout << pm->marca << endl;
	cout << sizeof(pm) << endl;

	cout << "------alocare dinamica obiect-------" << endl;
	pm = new masina();
	pm->schimbaModel("Mitshubishi");
	cout << pm->marca << endl;
	cout << pm->getModel() << endl;
	delete pm;

	masina m2("Honda", "Civic", 12345, 2);
	cout << m2.marca << endl;
	cout << m2.pret << endl;

	masina vector [2];

	masina* pm2 = new masina("Ferrari", "California", 400000, 1.5);
	cout<<pm2->getModel() << endl;

}
