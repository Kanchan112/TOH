
#include<iostream>
#include<engine.h>
#include<cmath>
#include<iostream>
#include <SFML/Graphics.hpp>
#include<vector>
#include<graphics.h>
#include<SFML/Window.hpp>
#include<string>
int count;
int np;


bool cont;
int main()
{
	
	cont = true;
	char A = 'A', B = 'B', C = 'C';
	while (cont)
	{
		menu();
		aCount = np;
		cCount = 0;
		bCount = 0;
		

		getTowerSolution(np, A, C, B);
		graphics(np);
		
		


		
	}
	return 0;
	
}

