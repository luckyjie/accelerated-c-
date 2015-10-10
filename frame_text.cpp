#include <iostream>
#include <string>

using std::cout;
using std::cin;
using std::string;
using std::endl;

int main()
{
	cout <<"please enter your first name: ";
	
	string name;
	cin >> name;

	const string greating = "Hello," + name + "!";
	
	const int pad = 1;
    
	const int row = 2*pad + 3;
	const string::size_type col = greating.size() + 2 * pad + 2;

	
	for(int r = 0; r <row;r ++)
	{
		int c = 0;
		while(c != col)
		{
			if (r == pad + 1 && c == pad + 1)
			{
				cout << greating;
				c += greating.size();
				continue;
			}
			else{
				if (r == 0 || r == row - 1 || c == 0 || c == col - 1)
					cout << "*";
				else
					cout << ' ';
			}
			c ++;
		}
		cout << endl;
	}   
	return 0;
}