#pragma once

namespace fw {
	struct SpriteInfo
	{
		std::string name ="";
		float x = 0;
		float y = 0;
		float W = 0;
		float H = 0;
	};
class SpriteSheet
{
public:
	SpriteSheet(const char* filename);
	~SpriteSheet();

	SpriteInfo GetSpriteInfo(std::string pSprite);
	float GetHeight() { return m_Height; }
	float GetWidth() { return m_Width; }
	
private:
	SpriteInfo m_SpriteInfo;
	float m_Width = 0;
	float m_Height = 0;

	std::vector<SpriteInfo> m_Sprites;
};

} // namespace fw
