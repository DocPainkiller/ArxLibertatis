/*
 * Copyright 2011-2012 Arx Libertatis Team (see the AUTHORS file)
 *
 * This file is part of Arx Libertatis.
 *
 * Arx Libertatis is free software: you can redistribute it and/or modify
 * it under the terms of the GNU General Public License as published by
 * the Free Software Foundation, either version 3 of the License, or
 * (at your option) any later version.
 *
 * Arx Libertatis is distributed in the hope that it will be useful,
 * but WITHOUT ANY WARRANTY; without even the implied warranty of
 * MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE.  See the
 * GNU General Public License for more details.
 *
 * You should have received a copy of the GNU General Public License
 * along with Arx Libertatis.  If not, see <http://www.gnu.org/licenses/>.
 */
/* Based on:
===========================================================================
ARX FATALIS GPL Source Code
Copyright (C) 1999-2010 Arkane Studios SA, a ZeniMax Media company.

This file is part of the Arx Fatalis GPL Source Code ('Arx Fatalis Source Code'). 

Arx Fatalis Source Code is free software: you can redistribute it and/or modify it under the terms of the GNU General Public 
License as published by the Free Software Foundation, either version 3 of the License, or (at your option) any later version.

Arx Fatalis Source Code is distributed in the hope that it will be useful, but WITHOUT ANY WARRANTY; without even the implied 
warranty of MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE. See the GNU General Public License for more details.

You should have received a copy of the GNU General Public License along with Arx Fatalis Source Code.  If not, see 
<http://www.gnu.org/licenses/>.

In addition, the Arx Fatalis Source Code is also subject to certain additional terms. You should have received a copy of these 
additional terms immediately following the terms and conditions of the GNU General Public License which accompanied the Arx 
Fatalis Source Code. If not, please request a copy in writing from Arkane Studios at the address below.

If you have questions concerning this license or the applicable additional terms, you may contact in writing Arkane Studios, c/o 
ZeniMax Media Inc., Suite 120, Rockville, Maryland 20850 USA.
===========================================================================
*/
// Copyright (c) 1999-2000 ARKANE Studios SA. All rights reserved

#ifndef ARX_GAME_SPELLS_H
#define ARX_GAME_SPELLS_H

#include <stddef.h>
#include <string>

#include "audio/AudioTypes.h"
#include "game/magic/Precast.h"
#include "game/magic/Rune.h"
#include "game/magic/RuneDraw.h"
#include "game/magic/SpellData.h"
#include "game/magic/SpellRecognition.h"
#include "math/Types.h"
#include "math/Angle.h"
#include "math/Random.h"
#include "math/Vector.h"
#include "platform/Flags.h"
#include "scene/Light.h"

class Entity;
class CSpellFx;
class TextureContainer;

const size_t MAX_SPELLS = 20;

class SpellManager {
	private:
		SpellBase m_spells[MAX_SPELLS];
		
	public:
		SpellBase & operator[] (const SpellHandle handle) {
			return m_spells[handle];
		}
};

extern SpellManager spells;


bool GetSpellPosition(Vec3f * pos, SpellHandle i);

void ARX_SPELLS_AddSpellOn(EntityHandle caster, SpellHandle spell);
void ARX_SPELLS_RemoveSpellOn(EntityHandle entityHandle, SpellHandle spellHandle);

SpellType GetSpellId(const std::string & spell);
void TryToCastSpell(Entity * io, SpellType spellid, long level, EntityHandle target, SpellcastFlags flags, long duration);

bool ARX_SPELLS_Launch(SpellType typ, EntityHandle source, SpellcastFlags flags = 0, long level = -1, EntityHandle target = InvalidEntityHandle, long duration = -1);
void ARX_SPELLS_AbortSpellSound();
void ARX_SPELLS_Init();
void ARX_SPELLS_ClearAll();
void ARX_SPELLS_Update();

SpellHandle ARX_SPELLS_GetInstance(SpellType typ);
void ARX_SPELLS_ManageMagic();

void ARX_SPELLS_UpdateSymbolDraw();
void ARX_SPELLS_ClearAllSymbolDraw();

bool ARX_SPELLS_ExistAnyInstance(SpellType typ);
void ARX_SPELLS_RemoveAllSpellsOn(Entity * io);
bool spellHandleIsValid(SpellHandle handle);
SpellHandle ARX_SPELLS_GetSpellOn(const Entity * io, SpellType spellid);
SpellHandle ARX_SPELLS_GetInstanceForThisCaster(SpellType typ, EntityHandle caster);

bool ARX_SPELLS_ExistAnyInstanceForThisCaster(SpellType typ, EntityHandle caster);

void ARX_SPELLS_CancelSpellTarget();
void ARX_SPELLS_LaunchSpellTarget(Entity * io);
float ARX_SPELLS_GetManaCost(SpellType _lNumSpell, SpellHandle _lNumSpellTab);
float ARX_SPELLS_ApplyFireProtection(Entity * io, float damages);
float ARX_SPELLS_ApplyColdProtection(Entity * io, float damages);
void ARX_SPELLS_FizzleAllSpellsFromCaster(EntityHandle num);

#endif // ARX_GAME_SPELLS_H
