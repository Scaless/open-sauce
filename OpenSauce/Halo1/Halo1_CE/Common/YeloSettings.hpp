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

#include <Common/Halo1/YeloSettingsDefinitions.hpp>
#include <Common/Halo1/YeloSharedSettings.hpp>

namespace Yelo
{
//////////////////////////////////////////////////////////////////////////
// Interface

	namespace Settings
	{
		typedef void (API_FUNC* proc_settings_read)(TiXmlElement* element);
		typedef void (API_FUNC* proc_settings_save)(TiXmlElement* element);


		void Initialize();
		void Dispose();

		void LoadSettings();
		void SaveSettings();
	};
};