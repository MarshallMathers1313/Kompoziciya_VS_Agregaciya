#include <iostream>
using namespace std;

//Композиция - если класс привязан жестко к другому классу, то это композиция!
//Например, в классе Human находиться в private поле класс Brain!

//Агрегация - если класс не привязан жестко к другому классу, то это агрегация!
//Например, есть класс Cap(кепка), которая может находиться в любых классах!

class Cap
{
	string color = "red";
public:
	Cap()
	{
		cout << "Cap Constructor: " << this << endl;
	}

	string getColor()
	{
		return color;
	}

	~Cap()
	{
		cout << "Cap Destructor: " << this << endl;
	}
};

class Human
{
public:
	Human()
	{
		cout << "Human Constructor: " << this << endl;
	}

	void Think()
	{
		brain.Think();
	}

	void InspectTheCap()
	{
		cout << "My cap is " << cap.getColor() << endl;
	}

	~Human()
	{
		cout << "Human Destructor: " << this << endl;
	}
private:
	class Brain
	{
	public:
		Brain()
		{
			cout << "Brain Constructor: " << this << endl;
		}

		void Think()
		{
			cout << "I think!" << endl;
		}

		~Brain()
		{
			cout << "Brain Destructor: " << this << endl;
		}
	};
	Brain brain;
	Cap cap;
};

class Model
{
	Cap cap;
public:
	Model()
	{
		cout << "Model Constructor: " << this << endl;
	}

	void InspectTheCap()
	{
		cout << "My cap is " << cap.getColor() << endl;
	}

	~Model()
	{
		cout << "Model Destructor: " << this << endl;
	}
};

int main()
{
	Human human;
	human.Think();
	human.InspectTheCap();

	Model model;
	model.InspectTheCap();
	
	return 0;
}