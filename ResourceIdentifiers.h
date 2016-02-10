#pragma once

namespace sf {
	class Texture;
}

namespace Textures {
	enum ID { Player, Sky };
};

template <typename Resource, typename Identifier>
class ResourceManager;

typedef ResourceManager<sf::Texture, Textures::ID> TextureManager;