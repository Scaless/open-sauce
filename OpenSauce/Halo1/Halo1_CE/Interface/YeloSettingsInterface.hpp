/*
    Yelo: Open Sauce SDK
		Halo 1 (CE) Edition
    Copyright (C) 2005-2010  Kornner Studios (http://kornner.com)

    This program is free software: you can redistribute it and/or modify
    it under the terms of the GNU General Public License as published by
    the Free Software Foundation, either version 3 of the License, or
    (at your option) any later version.

    This program is distributed in the hope that it will be useful,
    but WITHOUT ANY WARRANTY; without even the implied warranty of
    MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE.  See the
    GNU General Public License for more details.

    You should have received a copy of the GNU General Public License
    along with this program.  If not, see <http://www.gnu.org/licenses/>.
*/
#pragma once
#if !PLATFORM_IS_DEDI

#include "Interface/ControlTypes.hpp"

namespace Yelo
{
	namespace Enums
	{
		enum settings_menu : int32 {
			_settings_menu_off = NONE,
			_settings_menu_on = 0,

			_settings_menu_fov = 1,
			_settings_menu_weapons,
			_settings_menu_hud,
			_settings_menu_vehicles,
			_settings_menu,

			_settings_menu__first_catagory = _settings_menu_fov,
			_settings_menu__last_catagory = _settings_menu-1,
		};

		enum settings_menu_key {
			k_settings_menu_key = Enums::_KeyF7,

			k_settings_menu_base_key =		Enums::_Key1-1, // base key used in figuring out the catagory selection
			k_settings_menu_fov_key,		// +1
			k_settings_menu_weapons_key,	// +2
			k_settings_menu_hud_key,		// +3
			k_settings_menu_vehicles_key,	// +4
			k_settings_menu_last_key,

			k_settings_menu_key_first_catagory = k_settings_menu_base_key+1,
			k_settings_menu_key_last_catagory = k_settings_menu_last_key-1,
		};
	};
};
#endif