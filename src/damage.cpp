#include "stdinc.hpp"
#include "damage.h"
#include "loader/component_loader.hpp"
#include "game/game.hpp"
#include "game/structs.hpp"
#include <utils/hook.hpp>
#include <utils/string.hpp>


namespace Divity
{
	namespace
	{
	
		utils::hook::detour BG_GetSurfacePenetrationDepth;
		float penetration(int a1, int a2)
		{
			printf("wallbang work ing\n");
			return 999999999999.f;
		}
	}
	class component final : public component_interface
	{
	public:
		void post_unpack() override
		{
				utils::hook::nop(0x5D8D05, 2);
				BG_GetSurfacePenetrationDepth.create(0x622CE0, penetration);
		}
	};

}


REGISTER_COMPONENT(Divity::component)
