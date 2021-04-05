#include "VerySmartPointer/Include/SmartPtr.hpp"
#include <iostream>

struct Operations
{
public:
	int32_t add(int32_t& x, int32_t& y) 
	{
		return x + y;
	}

	int32_t sub(int32_t& x, int32_t& y)
	{
		return x - y;
	}
};

struct Menu
{
public:
	int32_t showOperations() const
	{
		int32_t operation = -1;
		std::cout << "\t\t Main operations \n" << "Addition press - 1\n" << "Subtraction press - 2\n";		
		std::cin >> operation;
		return operation;
	}
};

class SuperDuperCalc 
{
private:
	//SmartPtr<Operations> _operations;
	//SmartPtr<Menu>       _menu;
	Operations _operations;
	Menu _menu;
	bool _isRunning     = false;

public:
	void start() 
	{
		_isRunning = true;
		loop();
	}

private:
	int32_t add(int32_t& x, int32_t& y)
	{
		//return _operations->add(x, y);
		return _operations.add(x, y);
	}

	int32_t sub(int32_t& x, int32_t& y)
	{
		//return _operations->sub(x, y);
		return _operations.sub(x, y);
	}

	void loop() 
	{
		while (_isRunning)
		{
			//int32_t determinatior = _menu->showOperations();
			int32_t determinatior = _menu.showOperations();

			if(determinatior == 1)
			{
				int32_t x = 0;
				int32_t y = 0;

				std::cout << "Enter x : ";
				std::cin >> x;

				std::cout << "Enter y : ";
				std::cin  >> y;

				//int32_t result = _operations->add(x, y);
				int32_t result = _operations.add(x, y);
				std::cout << "Result of operation : " << result << std::endl;

				//_menu->showOperations();
				_menu.showOperations();
			}

			else if (determinatior == 2) 
			{
				int32_t x = 0;
				int32_t y = 0;

				std::cout << "Enter x : ";
				std::cin >> x;

				std::cout << "Enter y : ";
				std::cin >> y;

				//int32_t result = _operations->sub(x, y);
				int32_t result = _operations.sub(x, y);
				std::cout << "Result of operation : " << result << std::endl;

				//_menu->showOperations();
				_menu.showOperations();
			}
		}
	}
};

int main() 
{
	SuperDuperCalc calc;
	calc.start();

	return 0;
}