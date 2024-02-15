#include <iostream>
#include <time.h>
#include <stdio.h>

#include "Framework.h"
using namespace std;

constexpr int kNumColumnsX{ 100 };
constexpr int kNumRowsY{ 100 };

// Screen dimensions
int gScreenWidth{ 1000 };
int gScreenHeight{ 1000 };

int cellSizeX = gScreenWidth / kNumColumnsX;
int cellSizeY = gScreenHeight / kNumRowsY;


bool gMapA[kNumColumnsX][kNumRowsY];
bool gMapB[kNumColumnsX][kNumRowsY];

bool lPressed;

void DrawMap();

// Delay to slow things down
int gTimeDelayMS{ 10 };


int main()
{
	memset(gMapA, 0, kNumColumnsX * kNumRowsY * sizeof(bool));
	memcpy(gMapB, gMapA, kNumColumnsX * kNumRowsY * sizeof(bool));

	bool running{ false };

	/*for (int y = 0; y < kNumRowsY; y++)
	{
		for (int x = 0; x < kNumColumnsX; x++)
		{
			if (x == 50)
			{
				gMapA[y][x] = true;
			}
			else
			{
				gMapA[y][x] = false;
			}
		}
	}*/

	while (UpdateFramework())
	{
		if (running == true)//code while game is live
		{

		}
		else//paused
		{
			DrawMap();
		}

		int mX, mY;
		GetMousePosition(mX, mY);
		

		if (IsButtonPressed(EButton::eLeft)&&lPressed == false)
		{
			lPressed = true;
			int mouseCellX = mX - (mX % 10);
			int mouseCellY = mY - (mY % 10);

			gMapA[mouseCellY / cellSizeY][mouseCellX / cellSizeX] = !gMapA[mouseCellY / cellSizeY][mouseCellX / cellSizeX];
		}
		if (!IsButtonPressed(EButton::eLeft))
		{
			lPressed = false;
		}
		
	}

	return 0;
}


void DrawMap()
{
	for (int y = 0; y < kNumRowsY; y++)
	{
		for (int x = 0; x < kNumColumnsX; x++)
		{
			if (gMapA[y][x] == true)
			{
				ChangeColour(255, 255, 255, 255);
			}
			else
			{
				ChangeColour(0, 0, 0, 0);
			}
			DrawRectangle((x * cellSizeX) + 0.05f, (y * cellSizeY) + 0.05f, cellSizeX - 0.1f, cellSizeY - 0.1f);
			//DrawRectangle(x * cellSizeX, y * cellSizeY, cellSizeX, cellSizeY);
		}
	}
}