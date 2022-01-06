#pragma once
#include <SFML/Graphics.hpp>
#include <map>
#include <string>
using std::map;
using std::string;

class TextureManager
{
	static map<string, sf::Texture> textures;
	static void LoadTexture(string textureName);
public:
	static sf::Texture& GetTexture(string textureName);
	static void Clear();
};
