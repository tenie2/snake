#include<iostream>
#include<sfml/Graphics.hpp>

using namespace sf;
using namespace std;

class Map
{
	int *m_map;
	int m_width;
	int m_height;
	int m_area;

	float m_x;
	float m_y;
	float m_graphicWidth;
	float m_graphicHeight;

	Texture m_tex; 

public:
	
	//constructor
	
	Map()
	{
		m_width = m_height = m_area = 0;
		m_map = NULL;
	}
	
	Map(int width, int height)
	{
		m_width = width;
		m_height = height;
		m_area = width * height;
		m_map = new int[m_area];
	}

	//destructor
	~Map()
	{
		delete[] m_map;
	}

	int getArea()
	{
		return m_area;
	}

	int WhatIsAt(int x, int y)
	{
		return m_map[y * m_width + x];
		//return *(m_map + y * m_width + x);
	}

	void SetGraphicsProprieties(float x, float y, float width, float height)
	{
		m_x = x;
		m_y = y;
		m_graphicWidth = width;
		m_graphicHeight = height;
	}

	void LoadTexture(char *filePath)
	{
		m_tex.loadFromFile(filePath);
	}

	void Draw(RenderWindow& window)
	{
		// facem un array de vertecsi, adica un array de puncte care fiecare au pozitie, culoare si coordonate de texturare
		Vertex *puncte = new Vertex[4];
		puncte[0].position.x = m_x;
		puncte[0].position.y = m_y;
		puncte[0].color = Color::White;
		puncte[0].texCoords.x = 0;
		puncte[0].texCoords.y = 0;

		puncte[1].position.x = m_x;
		puncte[1].position.y = m_y + m_graphicHeight;
		puncte[1].color = Color::White;
		puncte[1].texCoords.x = 0;
		puncte[1].texCoords.y = m_graphicHeight;


		puncte[2].position.x = m_x + m_graphicWidth;
		puncte[2].position.y = m_y + m_graphicHeight;
		puncte[2].color = Color::White;
		puncte[2].texCoords.x = m_graphicWidth;
		puncte[2].texCoords.y = m_graphicHeight;

		puncte[3].position.x = m_x + m_graphicWidth;
		puncte[3].position.y = m_y;
		puncte[3].color = Color::White;
		puncte[3].texCoords.x = m_graphicWidth;
		puncte[3].texCoords.y = 0;

		// activam posibilitatea de a avea coordonate de texturare in afara texturii, rezultatul fiind repetitia (tiling)
		m_tex.setRepeated(true);
		RenderStates state(&m_tex);
		
		window.draw(puncte, 4, Quads, state);
	}

};

struct snakeVector
{
	float x;
	float y;
};

class snake
{
	float snake_x;
	float snake_y;
	int n;
		
	snakeVector SnakeVector[200];



};
	

int main()
{
	RenderWindow mainWindow(VideoMode(1280, 1024), "Snake");

	Map* m1 = new Map(1100, 900);
	Map altaHarta(200, 150);
	Map bau;
	cout << m1->getArea();
	m1->SetGraphicsProprieties(0,0, 1100, 900);
	m1->LoadTexture("Grass.png");
	while (mainWindow.isOpen())
	{
		sf::Event event;
		while (mainWindow.pollEvent(event))
		{
			if (event.type == sf::Event::Closed)
			mainWindow.close();
		}

		mainWindow.clear();
		m1->Draw(mainWindow);
		mainWindow.display();
	}
	delete m1;
	return 0;
}