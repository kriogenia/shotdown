#include "Scenario.h"
#include "tinyxml2.h"

Scenario::Scenario(int code, Game* game) :
	code(code)
{
	// Create the map
	scenario_map = new Map(game);
	// Load scenario info
	loadScenario("res/scenarios/scenario" + to_string(code) + ".tmx");
}

Scenario::~Scenario()
{
	delete scenario_map;
	playerSpawns.clear();
}

void Scenario::render()
{
	scenario_map->render();
}

void Scenario::play()
{
	scenario_map->addToSpace();
	printf("New match on scenario %i\n", code);
}

/* Reads and loads the XML content */
void Scenario::loadScenario(string filename)
{
	tinyxml2::XMLDocument doc;
	doc.LoadFile(filename.c_str());

	tinyxml2::XMLNode* map = doc.FirstChildElement("map");
	tinyxml2::XMLNode* c;		// Map Child
	c = map->FirstChild();
	// Process map childs (layers)
	for (c = c->NextSibling(); c != NULL; c = c->NextSibling()) {
		string name = c->ToElement()->Attribute("name");
		// Map tiles
		if (name.find("Background") != string::npos
			|| name.find("Static") != string::npos) {

			bool physic = false;
			if (name.rfind("Static") != string::npos) {
				physic = true;
			}
			// Tile childs
			string tilesLayer1 = c->FirstChildElement("data")->GetText();
			string delimiterDoc = "\n";
			string delimiterLine = ",";
			size_t posLine = 0;
			string line, tileNum;

			for (int i = 0; posLine != string::npos; i++) {
				posLine = tilesLayer1.find(delimiterDoc);
				line = tilesLayer1.substr(0, posLine);

				if (line == "") {
					i--;
				}

				size_t posCharacter = 0;
				for (int j = 0; posCharacter != string::npos; j++) {
					posCharacter = line.find(delimiterLine);
					tileNum = line.substr(0, posCharacter);
					// Tile position
					float x = static_cast<float>(TILE_SIZE / 2 + j * TILE_SIZE);
					float y = static_cast<float>(TILE_SIZE / 2 + i * TILE_SIZE);

					if (tileNum != "" && tileNum != "0") {
						scenario_map->loadTMXTile(stoi(tileNum), x, y, physic);
					}
					line.erase(0, posCharacter + delimiterLine.length());
				}
				tilesLayer1.erase(0, posLine + delimiterDoc.length());
			}
		}

		// Player spawn points
		else if (name == "Player") {
			tinyxml2::XMLNode* n;
			for (n = c->FirstChild(); n != NULL; n = n->NextSibling()) {
				string objectX = n->ToElement()->Attribute("x");
				string objectY = n->ToElement()->Attribute("y");
				playerSpawns.push_back({ stof(objectX), stof(objectY) });
			}
		}

		// WeaponSpawners spawn points
		else if (name == "Spawner") {
			tinyxml2::XMLNode* n;
			for (n = c->FirstChild(); n != NULL; n = n->NextSibling()) {
				string objectX = n->ToElement()->Attribute("x");
				string objectY = n->ToElement()->Attribute("y");
				wsSpawns.push_back({ stof(objectX), stof(objectY) });
			}
		}
	}
}