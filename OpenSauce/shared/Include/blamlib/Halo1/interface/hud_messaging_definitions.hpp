/*
	Yelo: Open Sauce SDK
		Halo 1 (CE) Edition

	See license\OpenSauce\Halo1_CE for specific license information
*/
#pragma once

#include <blamlib/Halo1/tag_files/tag_groups.hpp>

namespace Yelo
{
	namespace Enums
	{
		enum {
			k_max_state_messages = 1024,
			k_max_state_text_panels = 8,
		};
	};

	namespace TagGroups
	{
		struct hud_state_message_element
		{
			sbyte type;
			sbyte data;
		}; BOOST_STATIC_ASSERT( sizeof(hud_state_message_element) == 0x2 );

		struct hud_state_message_definition
		{
			tag_string name;
			int16 start_index_into_text_blob;
			int16 start_index_of_message_block;
			sbyte panel_count; PAD24;
			TAG_PAD(int32, 6);
		}; BOOST_STATIC_ASSERT( sizeof(hud_state_message_definition) == 0x40 );

		struct hud_state_messages
		{
			enum { k_group_tag = 'hmt ' };

			tag_data text_data;
			TAG_TBLOCK(message_elements, hud_state_message_element);
			TAG_TBLOCK(messages, hud_state_message_definition);
			TAG_PAD(int32, 21);
		}; BOOST_STATIC_ASSERT( sizeof(hud_state_messages) == 0x80 );
	};
};