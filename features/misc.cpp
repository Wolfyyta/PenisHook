#include "../globals.h"
#include "misc.h"
#include "../utility/configs/config.h"

void misc::Bunnyhop(CUserCmd* cmd)
{
	if (globals.local->IsAlive() && cfg.bunnyHop)
	{
		if (!(globals.local->GetFlags() & FL_ONGROUND))
			cmd->buttons &= ~CUserCmd::IN_JUMP;
	}
}
