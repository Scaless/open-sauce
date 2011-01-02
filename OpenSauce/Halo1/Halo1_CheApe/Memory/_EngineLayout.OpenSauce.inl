/*
    Yelo: Open Sauce SDK
		Halo 1 (Editing Kit) Edition
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


//////////////////////////////////////////////////////////////////////////
// .cpp
#if __EL_INCLUDE_FILE_ID == __EL_COMMON_YELO_SETTINGS

//////////////////////////////////////////////////////////////////////////
// CheApeCore.cpp
#elif __EL_INCLUDE_FILE_ID == __EL_MEMORY_CHE_APE_INTERFACE
	namespace CheApe
	{
		static const uint32 TagGroupDefinitionsRefs0[] = { // &tag_groups[x]
			PLATFORM_VALUE(0x434B06, 0x433116, 0x4F9BC6),	PLATFORM_VALUE(0x434B22, 0x433132, 0x4F9BE2),	PLATFORM_VALUE(0x434B3E, 0x43314E, 0x4F9BFE),
			PLATFORM_VALUE(0x434B57, 0x433167, 0x4F9C17),	PLATFORM_VALUE(0x434EE6, 0x433476, 0x4F9FA6),	PLATFORM_VALUE(0x434F09, 0x433499, 0x4F9FC9),
			PLATFORM_VALUE(0x434F19, 0x4334A9, 0x4F9FD6),	PLATFORM_VALUE(0x4350F3, 0x433623, 0x4FA1B3),	PLATFORM_VALUE(0x4351F6, 0x433726, 0x4FA2B6),
			//									^check this
			PLATFORM_VALUE(0x435213, 0x433743, 0x4FA2D3),	PLATFORM_VALUE(0x435983, 0x433EB3, 0x4FAA43),	PLATFORM_VALUE(0x4359C6, 0x433EF6, 0x4FAA86),
			PLATFORM_VALUE(0x4359F9, 0x433F29, 0x4FAAB9),	PLATFORM_VALUE(0x435A6B, 0x433F9B, 0x4FAB2B),	PLATFORM_VALUE(0x435A79, 0x433FA9, 0x4FAB39),
			PLATFORM_VALUE(0x435CB6, 0x4341E6, 0x4FAD76),	PLATFORM_VALUE(0x435CF3, 0x434223, 0x4FADB3),	PLATFORM_VALUE(0x435D1A, 0x43424A, 0x4FADDA),
			PLATFORM_VALUE(0x435D43, 0x434273, 0x4FAE03),	PLATFORM_VALUE(0x435D6A, 0x43429A, 0x4FAE2A),	PLATFORM_VALUE(0x4362C3, 0x4347F3, 0x4FB383),
			PLATFORM_VALUE(0x4362EA, 0x43481A, 0x4FB3AA),	PLATFORM_VALUE(0x437853, 0x435BF3, 0x4FC913),	PLATFORM_VALUE(0x4378B6, 0x435C56, 0x4FC976),
		};

		static const uint32 TagGroupDefinitionsRefs1[] = { // &tag_groups[1+x]
			PLATFORM_VALUE(0x434B1B, 0x43312B, 0x4F9BDB),	PLATFORM_VALUE(0x434B6C, 0x43317C, 0x4F9C2C),	PLATFORM_VALUE(0x43520B, 0x43373B, 0x4FA2CB),
			PLATFORM_VALUE(0x4359DB, 0x433F0B, 0x4FAA9B),	PLATFORM_VALUE(0x435A8E, 0x433FBE, 0x4FAB4E),	PLATFORM_VALUE(0x435CCB, 0x4341FB, 0x4FAD8B),
			PLATFORM_VALUE(0x435D2F, 0x43425F, 0x4FADEF),	PLATFORM_VALUE(0x435D7F, 0x4342AF, 0x4FAE3F),	PLATFORM_VALUE(0x4362FF, 0x43482F, 0x4FB3BF),
			PLATFORM_VALUE(0x4378CB, 0x435C6B, 0x4FC98B),
		};

		static const uint32 TagGroupDefinitionsCountRefs8bitPlus1[] = { // CMP esi, 53h
			PLATFORM_VALUE(0x434EF2, 0x433482, 0x4F9FB2),
		};

		static const uint32 TagGroupDefinitionsCountRefs16bit[] = { // CMP ax, 52h
			PLATFORM_VALUE(0x4351FF, 0x43372F, 0x4FA2BF),	PLATFORM_VALUE(0x4359CF, 0x433EFF, 0x4FAA8F),	PLATFORM_VALUE(0x435A82, 0x433FB2, 0x4FAB42),
			PLATFORM_VALUE(0x435CBF, 0x4341EF, 0x4FAD7F),	PLATFORM_VALUE(0x435D23, 0x434253, 0x4FADE3),	PLATFORM_VALUE(0x435D73, 0x4342A3, 0x4FAE33),
			PLATFORM_VALUE(0x4362F3, 0x434823, 0x4FB3B3),	PLATFORM_VALUE(0x4378BF, 0x435C5F, 0x4FC97F),
		};

		static const uint32 TagGroupDefinitionsCountRefs8bit[] = { // CMP cx, 52h
			PLATFORM_VALUE(0x434B10, 0x433120, 0x4F9BD0),	PLATFORM_VALUE(0x434B61, 0x433171, 0x4F9C21),
		};


		enum {
			kTagGroupDefinitionsAddress =	PLATFORM_VALUE(0x9B8D88, 0x6B8A08, 0xA295D0),
			kTagGroupDefinitionsCount =		0x53,

			kPhysicalMemoryMapAddress =		PLATFORM_VALUE(0x50000000, 0x50000000, 0x50000000),
			kPhysicalMemoryMapSize =		PLATFORM_VALUE(0x00600000, 0x00600000, 0x00600000),

			kExeBaseAddress =				PLATFORM_VALUE(0x400000, 0x400000, 0x400000),
			kExeSize =						PLATFORM_VALUE(0x9B4000, 0x6AC000, 0xC81200),
		};
	};

#else
	#error Undefined engine layout include for: __EL_INCLUDE_OPEN_SAUCE
#endif