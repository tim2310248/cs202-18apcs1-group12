﻿#include"CGAME.h"
CGAME::~CGAME()
{
	if (player)
		delete[]player;
	player = nullptr;

}

CGAME::CGAME()
{
	player = new cPeople;
	Bear b;
	Owl o;
	VB.push_back(b);
	VO.push_back(o);
}
cPeople* CGAME::getPeople()
{
	return this->player;
}
void CGAME::updatePosPeople(char key)
{
	player->display();
		
	if (key == 'a' || key == 'A')
	{
		player->Left(3);
		player->xClear(player->getX() + 3);
		player->display();
	}
	else if (key == 'w' || key == 'W')
	{
		player->Up(6);
		player->yClear(player->getY() + 6);
		player->display();
	}
	else if (key == 'd' || key == 'D')
	{
		player->Right(3);
		player->xClear(player->getX() - 3);
		player->display();
	}
	else if (key == 's' || key == 'S')
	{
		player->Down(6);
		player->yClear(player->getY() - 6);
		player->display();
	}
	
}
//void updatePosVehicle(); //Thực hiện cho CTRUCK & CCAR di chuyển
void CGAME::updatePosAnimal()//Thực hiện cho CDINAUSOR & CBIRD di chuyển
{
	updatePosBear();
	updatePosOwl();
}

void CGAME::updatePosBear()
{
	if (rand() % 23 == 1 && VB.size()<=4)
	{
		Bear b;
		VB.push_back(b);
	}
	for (unsigned int i = 0; i < VB.size(); ++i)
	{
		if (VB[i].getX() == 105)
		{
			VB[i].erase(VB[i].getX());
			VB.pop_front();
		}
		else if (i == 0)
		{
			VB[i].move();
			VB[i].erase(VB[i].getX() - 1);
			VB[i].display();
		}
		else
		{
			if (i - 1 >= 0 && VB[i - 1].getX() - VB[i].getX()>16)
			{
				
				VB[i].move();
				VB[i].erase(VB[i].getX() - 1);
				VB[i].display();
			}
		}
	}
}

void CGAME::updatePosOwl()
{
	
	if (rand() % 18 == 1 && VO.size()<=4)
	{
		Owl o;
		VO.push_back(o);
	}
	for (unsigned int i = 0; i < VO.size(); ++i)
	{
		if (VO[i].getX() == 105)
		{
			VO[i].erase(VO[i].getX());
			VO.pop_front();
		}
		else if (i == 0)
		{
			VO[i].move();
			VO[i].erase(VO[i].getX() - 1);
			VO[i].display();
		}
		else
		{
			if (i - 1 >= 0 && VO[i - 1].getX() - VO[i].getX()>14)
			{
				VO[i].move();
				VO[i].erase(VO[i].getX() - 1);
				VO[i].display();
			}
		}
	}
}

void CGAME::exitGame(HANDLE)
{
	exit(0);
}

vector<Animal*> CGAME::getAnimal()
{
	vector<Animal*> res;
	Animal *pA;
	unsigned int i = 0;
	for (i; i < VB.size() && i < VO.size(); ++i)
	{
		pA = &VB[i];
		res.push_back(pA);
		pA = &VO[i];
		res.push_back(pA);
	}
	for (i; i < VB.size(); ++i)
	{
		pA = &VB[i];
		res.push_back(pA);
	}
	for (i; i < VO.size(); ++i)
	{
		pA = &VO[i];
		res.push_back(pA);
	}
	return res;
}