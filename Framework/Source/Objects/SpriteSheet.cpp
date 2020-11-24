#include "FrameworkPCH.h"
#include "SpriteSheet.h"
#include "Utility/Helpers.h"

namespace fw
{
	SpriteSheet::SpriteSheet(const char* filename)
	{
		char* jsonString = fw::LoadCompleteFile(filename,nullptr);
		rapidjson::Document doc;
		doc.Parse(jsonString);
		delete[] jsonString;

		m_Width = (float)doc["Width"].GetInt();
		m_Height = (float)doc["Height"].GetInt();

		rapidjson::Value& Sprites = doc["Sprites"];
		
		for(rapidjson::SizeType i = 0;i<Sprites.Size();i++)
		{
			
			m_SpriteInfo.name = Sprites[i]["Name"].GetString();
			m_SpriteInfo.x = (float)Sprites[i]["X"].GetInt();
			m_SpriteInfo.y = (float)Sprites[i]["Y"].GetInt();
			m_SpriteInfo.W = (float)Sprites[i]["W"].GetInt();
			m_SpriteInfo.H = (float)Sprites[i]["H"].GetInt();

			m_Sprites.push_back(m_SpriteInfo);
		}
	}

	SpriteSheet::~SpriteSheet()
	{
		
	}

	SpriteInfo SpriteSheet::GetSpriteInfo(std::string pSprite)
	{
		for(rapidjson::SizeType i = 0; i<m_Sprites.size();i++)
		{
			if (m_Sprites[i].name == pSprite)
				return m_Sprites[i];
			
		}
	}
}
