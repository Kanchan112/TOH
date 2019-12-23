
#include<engine.h>
#include<cmath>
#include<iostream>
#include <SFML/Graphics.hpp>
#include<vector>
#include<graphics.h>
#include<SFML/Window.hpp>
#include<string>

std::vector<Answer> answer;
std::vector<Moves> moves;

std::string temp;
std::vector<sf::Text> msg;
sf::Text txt;
int mcount;

void graphics(int num)
{
	count = 0;
	mcount = 0;
	std::vector<sf::RectangleShape> Disk;

	sf::RenderWindow window(sf::VideoMode(1350, 700), "TOWER OF HANOI", sf::Style::Default);
	sf::Font font;
	if (!font.loadFromFile("IMPRISHA.ttf"))
	{
		std::cout << "error";
		sf::RenderWindow window(sf::VideoMode(1350, 700), "TOWER OF HANOI", sf::Style::Default);
	

	}
	sf::Text again;
	again.setFont(font);
	again.setString("Press S to start over");
	again.setFillColor(sf::Color::Black);
	again.setPosition(20.0f, 10.0f);
	again.setCharacterSize(40);
	sf::Text src;

	src.setFont(font);
	src.setString("A");
	src.setFillColor(sf::Color::Red);
	src.setPosition(75.0f, 600.0f);
	src.setCharacterSize(40);
	sf::Text aux;
	aux.setFont(font);
	aux.setString("B");
	aux.setFillColor(sf::Color::Red);
	aux.setPosition(500.0f, 500.0f);
	aux.setCharacterSize(40);
	sf::Text dest;
	dest.setFont(font);
	dest.setString("C");
	dest.setFillColor(sf::Color::Red);
	dest.setPosition(925.0f, 600.0f);
	dest.setCharacterSize(40);


	int smallest = 350 / num;
	for (int i = 0; i < num; i++)
	{

		Disk.push_back(sf::RectangleShape(sf::Vector2f((i + 1)*smallest, 15.0f)));

	}

	for (int i = 0; i < num; i++)
	{

		Disk[num - i - 1].setFillColor(sf::Color::Green);
		Disk[num - i - 1].setOutlineThickness(2.0f);
		Disk[num - i - 1].setOutlineColor(sf::Color(250, 150, 100));
		Disk[num - i - 1].setPosition(75.0 + i * smallest / 2.0f, -i * 15 + 650.0f);
	}
	sf::RectangleShape srcPeg(sf::Vector2f(10.0f, num*15.0f + 25.0f));
	sf::RectangleShape auxPeg(sf::Vector2f(10.0f, num*15.0f + 25.0f));
	sf::RectangleShape destPeg(sf::Vector2f(10.0f, num*15.0f + 25.0f));
	sf::RectangleShape srcPegbase(sf::Vector2f(355.0f, 5.0f));
	sf::RectangleShape auxPegbase(sf::Vector2f(355.0f, 5.0f));
	sf::RectangleShape destPegbase(sf::Vector2f(355.0f, 5.0f));
	srcPeg.setPosition(240.0f, 670.0f - (num*15.0f + 25.0f));
	auxPeg.setPosition(665.0f, 570.0f - (num*15.0f + 25.0f));
	destPeg.setPosition(1090.5f, 670.0f - (num*15.0f + 25.0f));
	srcPegbase.setPosition(72.5f, 665.0f);
	auxPegbase.setPosition(497.5f, 565.0f);
	destPegbase.setPosition(922.5f, 665.0f);



	srcPeg.setFillColor(sf::Color(165, 42, 42));
	auxPeg.setFillColor(sf::Color(165, 42, 42));
	destPeg.setFillColor(sf::Color(165, 42, 42));
	srcPegbase.setFillColor(sf::Color(165, 42, 42));
	auxPegbase.setFillColor(sf::Color(165, 42, 42));
	destPegbase.setFillColor(sf::Color(165, 42, 42));


	while (window.isOpen())
	{
		sf::Event event;
		while (window.pollEvent(event))
		{

			if (event.type == sf::Event::Closed)
			{
				window.close();
				cont = false;
			}
			if (event.type == sf::Event::KeyPressed)
			{
				if (event.key.code == sf::Keyboard::Space)
				{
					if (count < (pow(2, num) - 1))
					{
						if (mcount%10==0)
						{
							msg.clear();
							mcount = 0;
						}
						Disk[moves[count].no - 1].move(moves[count].x, moves[count].y);
						temp = std::to_string(answer[count].no);
						txt.setString("move disk " + temp + " from " + answer[count].from + " to " + answer[count].to);
						msg.push_back(txt);
						msg[mcount].setFont(font);
						msg[mcount].setFillColor(sf::Color::Red);
						
							msg[mcount].setPosition(900.0f, 18.0f*(mcount)+2);
						
						
						msg[mcount].setCharacterSize(18);
						count++;
						mcount++;
						


					}

				}
				if (event.key.code == sf::Keyboard::S)
				{
					moves.clear();
					answer.clear();
					window.close();
				}




			}


			window.clear(sf::Color(235, 194, 60));
			window.setKeyRepeatEnabled(false);
			window.draw(srcPeg);
			window.draw(auxPeg);

			window.draw(destPeg);
			window.draw(srcPegbase);
			window.draw(auxPegbase);
			window.draw(src);
			window.draw(aux);
			window.draw(dest);
			window.draw(again);

			window.draw(destPegbase);
			for (int i = 0; i < num; i++)
			{
				window.draw(Disk[i]);
			}
			if (count > 0)
			{
				for (int i = 0; i < mcount; i++)
				{
					window.draw(msg[i]);
				}
			}

			/*if (sf::Keyboard::isKeyPressed(sf::Keyboard::Space))
			{

					Disk[moves[count].no - 1].move(moves[count].x, moves[count].y);
					count++;

		   if (count == pow(2, num) - 1)
			   return 0;
			}*/
			window.display();
		}



	}
}






