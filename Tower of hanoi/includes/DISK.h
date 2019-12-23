#pragma once
#include<stdio.h>
#include<vector>
#include <SFML/Graphics.hpp>
class disk
{
private:
	int num;
	std::vector<sf::RectangleShape> Disk;
public:
	disk(int n):num(n)
	{
		float smallest = 400.0f / num;
		for (int i = 0; i < num; i++)
		{

			Disk.push_back(sf::RectangleShape(sf::Vector2f((float)(i + 1)*smallest, smallest)));

		}

	}


};
