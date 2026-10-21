#ifndef SPRITE_MANAGER_H
#define SPRITE_MANAGER_H

#include "sprite.h"
#include <SFML/Graphics.hpp>
#include <unordered_map> 

using SpriteID = size_t;

class SpriteManager {
public:
        sf::Texture& registerTexture(const std::string& filepath){
           auto it = mTextures.find(filepath);
           if(it != mTextures.end()){
                return it->second;
           } else{
                auto result = mTextures.try_emplace(filepath, filepath);
                return result.first->second;
           }
        }

        template <typename... Args>
        SpriteID createSprite(Args&&... args){
            mSprites.emplace_back(std::forward<Args>(args)...);
            return mSprites.size()-1;
        }

        Sprite& getSprite(SpriteID id){
            return mSprites[id];
        }
    
private:
        std::unordered_map<std::string, sf::Texture> mTextures;
        std::vector<Sprite> mSprites;

};

#endif  // SPRITE_MANAGER_H
