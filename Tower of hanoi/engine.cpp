#include<iostream>
#include<engine.h>
#include<cmath>
#include<iostream>
#include <SFML/Graphics.hpp>
#include<vector>
#include<graphics.h>
#include<SFML/Window.hpp>
#include<string>


Answer::Answer(char f, char t, int n) :from(f), to(t), no(n) {}
Moves::Moves(int x, int y, int n) : x(x), y(y), no(n) {}
 int aCount, bCount, cCount;

int getx(char s, char d)
{
	if (s=='A'&& d=='B')
	{
		aCount--;
		bCount++;
		return 425;
	}
		else if (s == 'B'&& d == 'A')
		{
			aCount++;
			bCount--;
			return -425;
		}
			else if (s == 'A'&& d == 'C')
			{
				cCount++;
				aCount--;
				return 850;
			}
				else if (s == 'C'&& d == 'A')
				{
					aCount++;
					cCount--;
					return -850;
				}
					else if (s == 'C'&& d == 'B')
					{
						bCount++;
						cCount--;
						return -425;
					}
						else if (s == 'B'&& d == 'C')
						{
							cCount++;
							bCount--;
							return 425;
						}

}
int gety(char s, char d)
{
	if (s == 'A'&& d == 'B')
	{
		
		return (aCount - bCount-1)*15 - 100;
	}
	else if (s == 'B'&& d == 'A')
	{
		return (bCount - aCount-1) * 15 + 100;
	}
	else if (s == 'A'&& d == 'C')
	{
		return (aCount - cCount-1) * 15;
	}
	else if (s == 'C'&& d == 'A')
	{
		return (cCount - aCount-1) * 15 ;
	}
	else if (s == 'C'&& d == 'B')
	{
		return (cCount - bCount-1) * 15 - 100;
	}
	else if (s == 'B'&& d == 'C')
	{
		return(bCount - cCount-1) * 15 + 100;
	}


}
void getTowerSolution(int n, char sourcePeg, char destPeg, char auxPeg)
{

	if (n == 1)
	{
		
		answer.push_back(Answer(sourcePeg, destPeg, n));
		moves.push_back(Moves(getx(sourcePeg, destPeg), gety(sourcePeg, destPeg), n));
		return;

		
	}
	getTowerSolution(n - 1, sourcePeg, auxPeg, destPeg);

	
	answer.push_back(Answer(sourcePeg, destPeg, n));
	moves.push_back(Moves(getx(sourcePeg, destPeg), gety(sourcePeg, destPeg), n));
	getTowerSolution(n - 1, auxPeg, destPeg, sourcePeg);


}

void display(int n)
{
	
	for (int i = 0; i < n; i++)
	{
		std::cout << answer[i].no << answer[i].from << answer[i].to << std::endl;
		std::cout << moves[i].x <<"   " << moves[i].y << "   " << moves[i].no  << std::endl;
	}
	std::cout << moves.size ()<< std::endl;
}

void checkSolution(int n)
{
	int no;
	char from, to;
	for(int i=0; i<n;i++)
	{
		while (true)
		{
			std::cout << "enter the move: disk ,from peg and to peg" << std::endl;
			std::cin >> no;
			std::cin >> from;
			std::cin >> to;
			if (no == answer[i].no &&from == answer[i].from &&to == answer[i].to)
				break;
			std::cout << "Wrong move" << std::endl;
		}
		std::cout << "disk " << no << "from " << from << "to " << to << std::endl;
	}
	
}
void menu()
{
	sf::RenderWindow menu(sf::VideoMode(400, 400), "TOWER OF HANOI", sf::Style::Default);
	sf::Font font;
	if (!font.loadFromFile("IMPRISHA.ttf"))
	{
		std::cout << "error";
		system("pause");

	}
	sf::Text text;

	text.setFont(font);
	text.setString("Enter no. disks to continue");
	text.setFillColor(sf::Color::Red);
	text.setCharacterSize(60);
	text.setPosition(20.0f, 100.0f);

	while (menu.isOpen())
	{
		sf::Event event;
		while (menu.pollEvent(event))
		{

			if (event.type == sf::Event::Closed)
				menu.close();
			if (event.type == sf::Event::KeyPressed)
			{
				if (event.key.code == sf::Keyboard::Num1)
				{
					np = 1;
					menu.close();
				}
				if (event.key.code == sf::Keyboard::Num2)
				{
					np = 2;
					menu.close();
				}
				if (event.key.code == sf::Keyboard::Num3)
				{
					np = 3;
					menu.close();
				}

				if (event.key.code == sf::Keyboard::Num4)
				{
					np = 4;
					menu.close();
				}
				if (event.key.code == sf::Keyboard::Num5)
				{
					np = 5;
					menu.close();
				}
				if (event.key.code == sf::Keyboard::Num6)
				{
					np = 6;
					menu.close();
				}

				if (event.key.code == sf::Keyboard::Num7)
				{
					np = 7;
					menu.close();
				}

				if (event.key.code == sf::Keyboard::Num8)
				{
					np = 8;
					menu.close();
				}
				if (event.key.code == sf::Keyboard::Num9)
				{
					np = 9;
					menu.close();
				}
			}

		}
		menu.clear(sf::Color(0, 10, 20));
		menu.draw(text);
		menu.display();

	}
}
