// object.project.cpp : Этот файл содержит функцию "main". Здесь начинается и заканчивается выполнение программы.
////https://jlnr.de/2011/01/04/game-object-inheritance.html
//Grass game by Encoh King OOP CONCEPTS FIRST lab work 

#include "pch.h"
#include <iostream>
#include  <vector>
#include <algorithm>
	using namespace std;

	class GameObject { virtual void update(); };
	char right, left;

	template <typename Base>
	class Moving : public Base
	{
		void update() { Base::update();              /* movement here */ }
	};

	template<typename Base>
	class HurtsPlayer : public Base
	{
		void update() { Base::update();           /* check for player collision */ }
	};

	class Player :
		public Moving <GameObject> {};
	class Bomb :
		public HurtsPlayer<GameObject> {};
	class Coin :
		public GameObject {  };
	class BadGuy :
		public HurtsPlayer<Moving<GameObject>> {  };

	//void moveObject (Obj& o, int& velX, int& velY); // defined in Moving.cpp

	template<class Base>
	class Moving :
		public Base
	{
		int velocityX, velocityY;

	public:
		void update()
		{
			Base::update();
			moveObject(*this, velocityX, velocityY);
		}
	};

	class MovingBase
	{
		int vx, vy;
	protected:
		void move();
	public:
		/* common member functions */
		void setVelocityX(int);
		void setVelocityY(int);
	};

	template<class Base>
	class Moving : public Base, public MovingBase
	{

	public:
		void update()
		{
			Base::update();
			move();
		}
	};



