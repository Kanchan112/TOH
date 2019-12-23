#pragma once
#include<vector>
#include<iostream>

struct Answer
{
	char from, to;
	int no;

	Answer(char, char, int);
};
struct Moves
{
	int x, y, no;
	Moves(int, int, int);
};
extern std::vector<Answer> answer;
extern std::vector<Moves> moves;
extern int np;



void getTowerSolution(int , char , char , char );

void display(int );
void checkSolution(int);
void menu();
