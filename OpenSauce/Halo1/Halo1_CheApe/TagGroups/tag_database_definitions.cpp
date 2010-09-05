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
#include "Common/Precompile.hpp"
#include "TagGroups/tag_database_definitions.hpp"

#include "Engine/EngineFunctions.hpp"

namespace Yelo
{
	namespace TagGroups
	{
		void s_tag_database_entry::NameToBlockNameBuffer(char formatted_buffer[Enums::k_tag_block_format_buffer_size])
		{
			if(this->name.Size > 0)
			{
				Yelo::tag_group_definition* group_definition = Yelo::tag_group_get(this->group_tag);
				if(  group_definition != NULL )
				{
					sprintf_s(formatted_buffer, Enums::k_tag_block_format_buffer_size, 
						"%s.%s", this->name.Definitions, group_definition->name);
				}
			}
		}

		void s_tag_database::Initialize()
		{
			Yelo::tag_group_definition* definition = Yelo::tag_group_get<s_tag_database>();
			if(definition == NULL)
			{
				YELO_ERROR(_error_message_priority_none, 
					"CheApe: tag_database not found!");
			}
			else if(definition->version == k_version)
			{
				//////////////////////////////////////////////////////////////////////////
				{// s_tag_database_entry block
					tag_block_definition* tag_database_entry_block_def = definition->definition->fields[0].Definition<tag_block_definition>();
					tag_database_entry_block_def->format_proc = &TagGroups::tag_database_entry_block_format;

					// child ids
					tag_block_definition* entry_reference_block_def = tag_database_entry_block_def->fields[4].Definition<tag_block_definition>();
					entry_reference_block_def->format_proc = &TagGroups::tag_database_entry_reference_block_format;

					// reference ids
					entry_reference_block_def = tag_database_entry_block_def->fields[5].Definition<tag_block_definition>();
					entry_reference_block_def->format_proc = &TagGroups::tag_database_entry_reference_block_format;
				}
			}
		}

		void s_tag_database::Dispose()
		{
		}


		cstring PLATFORM_API tag_database_entry_reference_block_format(
			datum_index tag_index, 
			tag_block* block, 
			int32 element, 
			char formatted_buffer[Enums::k_tag_block_format_buffer_size])
		{
			int32 entry = 
				*CAST_PTR(int32*, tag_block_get_element(block, element));

			formatted_buffer[0] = '\0';

			if(entry != NONE)
			{
				s_tag_database* db = tag_get<s_tag_database>(tag_index);

				db->entries[ entry ].NameToBlockNameBuffer(formatted_buffer);
			}


			return formatted_buffer;
		}

		cstring PLATFORM_API tag_database_entry_block_format(
			datum_index tag_index, 
			tag_block* block, 
			int32 element, 
			char formatted_buffer[Enums::k_tag_block_format_buffer_size])
		{
			s_tag_database_entry* elem = 
				CAST_PTR(s_tag_database_entry*, tag_block_get_element(block, element));

			formatted_buffer[0] = '\0';

			elem->NameToBlockNameBuffer(formatted_buffer);

			return formatted_buffer;
		}
	};
};