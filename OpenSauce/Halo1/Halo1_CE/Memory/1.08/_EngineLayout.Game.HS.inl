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

//////////////////////////////////////////////////////////////////////////
// Scripting.cpp
#if __EL_INCLUDE_FILE_ID == __EL_GAME_SCRIPTING
	ENGINE_DPTR(t_recorded_animations_data, recorded_animations,		0x64B878, 0x5BD6A8);
	ENGINE_DPTR(t_hs_syntax_data, hs_syntax,							0x8154D4, 0x6E13D4);
	ENGINE_DPTR(t_object_list_header_data, object_list_header,			0x8154C4, 0x6E13C4);
	ENGINE_DPTR(t_list_object_reference_data, list_object_reference,	0x8154C8, 0x6E13C8);
	ENGINE_DPTR(t_hs_globals_data, hs_globals,							0x8154CC, 0x6E13CC);
	ENGINE_DPTR(t_hs_thread_data, hs_threads,							0x8154D0, 0x6E13D0);

	FUNC_PTR(HS_UPDATE_HOOK, 0x48CF88, 0x484868);

	static uint32* K_MAX_HS_SYNTAX_NODES_PER_SCENARIO_UPGRADE_ADDRESS_LIST[] = {
		CAST_PTR(uint32*, PLATFORM_VALUE(0x485E8B, 0x47D77B)),
	};

	static uint32* K_TOTAL_SCENARIO_HS_SYNTAX_DATA_UPGRADE_ADDRESS_LIST[] = {
		//CAST_PTR(uint32*, PLATFORM_VALUE(0x485E83, 0x47D773)), // don't modify this one, modify the size check using the address below
		CAST_PTR(uint32*, PLATFORM_VALUE(0x485EDA, 0x47D7CA))
	};

	static byte* K_ADDRESS_OF_SCENARIO_HS_SYNTAX_DATA_SIZE_CHECK = CAST_PTR(byte*, PLATFORM_VALUE(0x485E87, 0x47D777));


//////////////////////////////////////////////////////////////////////////
// ScriptLibrary.cpp
#elif __EL_INCLUDE_FILE_ID == __EL_GAME_SCRIPT_LIBRARY
	FUNC_PTR(HS_MACRO_FUNCTION_PARSE,		0x48A180, 0x481B10);
	FUNC_PTR(HS_COMPILE_AND_EVALUATE,		0x487140, 0x47EA20); // currently unused
	FUNC_PTR(HS_NULL_EVALUATE,				0x4824D0, 0x476130);
	FUNC_PTR(HS_NULL_WITH_PARAMS_EVALUATE,	0x480100, 0x47A5B0);

	//////////////////////////////////////////////////////////////////////////
	// script functions related
	ENGINE_PTR(int32, hs_function_table_count,				0x5F9C30, 0x5556D0);
	ENGINE_DPTR(hs_function_definition, hs_function_table,	0x624118, 0x599AD8);

	#pragma region hs function table references
	static int16* K_HS_FUNCTION_TABLE_COUNT_REFERENCES_16bit[] = {
		CAST_PTR(int16*, PLATFORM_VALUE(0x4862F1, 0x47DBE1)),
		CAST_PTR(int16*, PLATFORM_VALUE(0x487024, 0x47E904)),
	};
	static int32* K_HS_FUNCTION_TABLE_COUNT_REFERENCES_32bit[] = {
		CAST_PTR(int32*, PLATFORM_VALUE(0x48660A, 0x47DEEA)),
	};

	// really hs_function_definition***
	static void* K_HS_FUNCTION_TABLE_REFERENCES[] = { // RIVERSIDE MOTHER FUCKER! *techno beat*
#if PLATFORM_IS_USER
		CAST_PTR(void*,0x47D119), CAST_PTR(void*,0x47D178), CAST_PTR(void*,0x47D1D8), CAST_PTR(void*,0x47D229), CAST_PTR(void*,0x47D2A9), CAST_PTR(void*,0x47D309), 
		CAST_PTR(void*,0x47D368), CAST_PTR(void*,0x47D3C8), CAST_PTR(void*,0x47D428), CAST_PTR(void*,0x47D478), CAST_PTR(void*,0x47D4C8), CAST_PTR(void*,0x47D518), 
		CAST_PTR(void*,0x47D578), CAST_PTR(void*,0x47D5C8), CAST_PTR(void*,0x47D618), CAST_PTR(void*,0x47D668), CAST_PTR(void*,0x47D6B8), CAST_PTR(void*,0x47D709), 
		CAST_PTR(void*,0x47D778), CAST_PTR(void*,0x47D7C8), CAST_PTR(void*,0x47D818), CAST_PTR(void*,0x47D868), CAST_PTR(void*,0x47D8B9), CAST_PTR(void*,0x47D919), 
		CAST_PTR(void*,0x47D978), CAST_PTR(void*,0x47D9C8), CAST_PTR(void*,0x47DA28), CAST_PTR(void*,0x47DAB9), CAST_PTR(void*,0x47DB48), CAST_PTR(void*,0x47DBC8), 
		CAST_PTR(void*,0x47DC19), CAST_PTR(void*,0x47DCB8), CAST_PTR(void*,0x47DD09), CAST_PTR(void*,0x47DD69), CAST_PTR(void*,0x47DDC9), CAST_PTR(void*,0x47DE28), 
		CAST_PTR(void*,0x47DE79), CAST_PTR(void*,0x47DEE8), CAST_PTR(void*,0x47DF68), CAST_PTR(void*,0x47DFF8), CAST_PTR(void*,0x47E078), CAST_PTR(void*,0x47E0C8), 
		CAST_PTR(void*,0x47E148), CAST_PTR(void*,0x47E1E8), CAST_PTR(void*,0x47E228), CAST_PTR(void*,0x47E268), CAST_PTR(void*,0x47E2E8), CAST_PTR(void*,0x47E328), 
		CAST_PTR(void*,0x47E388), CAST_PTR(void*,0x47E3F8), CAST_PTR(void*,0x47E459), CAST_PTR(void*,0x47E4B9), CAST_PTR(void*,0x47E518), CAST_PTR(void*,0x47E568), 
		CAST_PTR(void*,0x47E5C8), CAST_PTR(void*,0x47E658), CAST_PTR(void*,0x47E6A8), CAST_PTR(void*,0x47E6F8), CAST_PTR(void*,0x47E758), CAST_PTR(void*,0x47E7B9), 
		CAST_PTR(void*,0x47E818), CAST_PTR(void*,0x47E889), CAST_PTR(void*,0x47E8F9), CAST_PTR(void*,0x47E969), CAST_PTR(void*,0x47E9D9), CAST_PTR(void*,0x47EA68), 
		CAST_PTR(void*,0x47EAF8), CAST_PTR(void*,0x47EB68), CAST_PTR(void*,0x47EBF8), CAST_PTR(void*,0x47EC49), CAST_PTR(void*,0x47ECA9), CAST_PTR(void*,0x47ED08), 
		CAST_PTR(void*,0x47ED58), CAST_PTR(void*,0x47ED99), CAST_PTR(void*,0x47EE18), CAST_PTR(void*,0x47EE68), CAST_PTR(void*,0x47EEB8), CAST_PTR(void*,0x47EF09), 
		CAST_PTR(void*,0x47EF69), CAST_PTR(void*,0x47EFC8), CAST_PTR(void*,0x47F018), CAST_PTR(void*,0x47F0B8), CAST_PTR(void*,0x47F0F8), CAST_PTR(void*,0x47F158), 
		CAST_PTR(void*,0x47F1B8), CAST_PTR(void*,0x47F238), CAST_PTR(void*,0x47F2B9), CAST_PTR(void*,0x47F339), CAST_PTR(void*,0x47F3A9), CAST_PTR(void*,0x47F408), 
		CAST_PTR(void*,0x47F448), CAST_PTR(void*,0x47F498), CAST_PTR(void*,0x47F508), CAST_PTR(void*,0x47F558), CAST_PTR(void*,0x47F5E9), CAST_PTR(void*,0x47F668), 
		CAST_PTR(void*,0x47F6E8), CAST_PTR(void*,0x47F778), CAST_PTR(void*,0x47F7F9), CAST_PTR(void*,0x47F898), CAST_PTR(void*,0x47F918), CAST_PTR(void*,0x47F998), 
		CAST_PTR(void*,0x47F9E9), CAST_PTR(void*,0x47FA48), CAST_PTR(void*,0x47FA98), CAST_PTR(void*,0x47FB18), CAST_PTR(void*,0x47FB98), CAST_PTR(void*,0x47FC98), 
		CAST_PTR(void*,0x47FCD8), CAST_PTR(void*,0x47FD28), CAST_PTR(void*,0x47FD78), CAST_PTR(void*,0x47FDB8), CAST_PTR(void*,0x47FDF8), CAST_PTR(void*,0x47FE48), 
		CAST_PTR(void*,0x47FE98), CAST_PTR(void*,0x47FEE8), CAST_PTR(void*,0x47FF58), CAST_PTR(void*,0x47FF98), CAST_PTR(void*,0x47FFE8), CAST_PTR(void*,0x480038), 
		CAST_PTR(void*,0x480088), CAST_PTR(void*,0x480108), CAST_PTR(void*,0x480148), CAST_PTR(void*,0x480198), CAST_PTR(void*,0x480228), CAST_PTR(void*,0x480298), 
		CAST_PTR(void*,0x480308), CAST_PTR(void*,0x480358), CAST_PTR(void*,0x4803A8), CAST_PTR(void*,0x4803F8), CAST_PTR(void*,0x480448), CAST_PTR(void*,0x480488), 
		CAST_PTR(void*,0x4804C8), CAST_PTR(void*,0x480508), CAST_PTR(void*,0x480548), CAST_PTR(void*,0x480588), CAST_PTR(void*,0x4805D8), CAST_PTR(void*,0x480628), 
		CAST_PTR(void*,0x4806B8), CAST_PTR(void*,0x480708), CAST_PTR(void*,0x480758), CAST_PTR(void*,0x4807B8), CAST_PTR(void*,0x480808), CAST_PTR(void*,0x480858), 
		CAST_PTR(void*,0x480898), CAST_PTR(void*,0x4808E8), CAST_PTR(void*,0x480938), CAST_PTR(void*,0x480988), CAST_PTR(void*,0x4809D8), CAST_PTR(void*,0x480A28), 
		CAST_PTR(void*,0x480A78), CAST_PTR(void*,0x480AB8), CAST_PTR(void*,0x480AF8), CAST_PTR(void*,0x480B48), CAST_PTR(void*,0x480B88), CAST_PTR(void*,0x480BD8), 
		CAST_PTR(void*,0x480C28), CAST_PTR(void*,0x480C68), CAST_PTR(void*,0x480CE8), CAST_PTR(void*,0x480D68), CAST_PTR(void*,0x480DB8), CAST_PTR(void*,0x480E08), 
		CAST_PTR(void*,0x480E58), CAST_PTR(void*,0x480EB8), CAST_PTR(void*,0x480F08), CAST_PTR(void*,0x480F68), CAST_PTR(void*,0x480FC8), CAST_PTR(void*,0x481028), 
		CAST_PTR(void*,0x481098), CAST_PTR(void*,0x4810D8), CAST_PTR(void*,0x481128), CAST_PTR(void*,0x481168), CAST_PTR(void*,0x4811B8), CAST_PTR(void*,0x481218), 
		CAST_PTR(void*,0x481278), CAST_PTR(void*,0x4812F8), CAST_PTR(void*,0x481378), CAST_PTR(void*,0x4813D8), CAST_PTR(void*,0x481428), CAST_PTR(void*,0x481478), 
		CAST_PTR(void*,0x4814D8), CAST_PTR(void*,0x481528), CAST_PTR(void*,0x481578), CAST_PTR(void*,0x4815C8), CAST_PTR(void*,0x481619), CAST_PTR(void*,0x481679), 
		CAST_PTR(void*,0x4816D9), CAST_PTR(void*,0x481739), CAST_PTR(void*,0x481798), CAST_PTR(void*,0x481828), CAST_PTR(void*,0x481889), CAST_PTR(void*,0x4818F9), 
		CAST_PTR(void*,0x481968), CAST_PTR(void*,0x4819B9), CAST_PTR(void*,0x481A19), CAST_PTR(void*,0x481A79), CAST_PTR(void*,0x481AD9), CAST_PTR(void*,0x481B39), 
		CAST_PTR(void*,0x481BD8), CAST_PTR(void*,0x481C28), CAST_PTR(void*,0x481C78), CAST_PTR(void*,0x481CC8), CAST_PTR(void*,0x481D18), CAST_PTR(void*,0x481D78), 
		CAST_PTR(void*,0x481E28), CAST_PTR(void*,0x481F08), CAST_PTR(void*,0x481F59), CAST_PTR(void*,0x482298), CAST_PTR(void*,0x482318), CAST_PTR(void*,0x482368), 
		CAST_PTR(void*,0x4823B8), CAST_PTR(void*,0x482408), CAST_PTR(void*,0x4824E8), CAST_PTR(void*,0x482568), CAST_PTR(void*,0x4826A8), CAST_PTR(void*,0x482708), 
		CAST_PTR(void*,0x482758), CAST_PTR(void*,0x4827A8), CAST_PTR(void*,0x482A18), CAST_PTR(void*,0x482A98), CAST_PTR(void*,0x482AE8), CAST_PTR(void*,0x482B58), 
		CAST_PTR(void*,0x482BD8), CAST_PTR(void*,0x482C18), CAST_PTR(void*,0x482C68), CAST_PTR(void*,0x482CA8), CAST_PTR(void*,0x482CF8), CAST_PTR(void*,0x482D48), 
		CAST_PTR(void*,0x482D98), CAST_PTR(void*,0x482DE8), CAST_PTR(void*,0x482E28), CAST_PTR(void*,0x482E98), CAST_PTR(void*,0x482F08), CAST_PTR(void*,0x482F78), 
		CAST_PTR(void*,0x483009), CAST_PTR(void*,0x483069), CAST_PTR(void*,0x4830C8), CAST_PTR(void*,0x483168), CAST_PTR(void*,0x4831D8), CAST_PTR(void*,0x483248), 
		CAST_PTR(void*,0x4832A8), CAST_PTR(void*,0x483308), CAST_PTR(void*,0x483368), CAST_PTR(void*,0x4833C8), CAST_PTR(void*,0x483418), CAST_PTR(void*,0x483489), 
		CAST_PTR(void*,0x4834E8), CAST_PTR(void*,0x483538), CAST_PTR(void*,0x483588), CAST_PTR(void*,0x4835C8), CAST_PTR(void*,0x483628), CAST_PTR(void*,0x483699), 
		CAST_PTR(void*,0x483729), CAST_PTR(void*,0x483798), CAST_PTR(void*,0x4837F8), CAST_PTR(void*,0x483858), CAST_PTR(void*,0x4838B8), CAST_PTR(void*,0x483918), 
		CAST_PTR(void*,0x483978), CAST_PTR(void*,0x4839D8), CAST_PTR(void*,0x483A68), CAST_PTR(void*,0x483AB8), CAST_PTR(void*,0x483B08), CAST_PTR(void*,0x483B58), 
		CAST_PTR(void*,0x483BB8), CAST_PTR(void*,0x483C48), CAST_PTR(void*,0x483C98), CAST_PTR(void*,0x483D58), CAST_PTR(void*,0x483DA8), CAST_PTR(void*,0x483E08), 
		CAST_PTR(void*,0x483EA8), CAST_PTR(void*,0x483F08), CAST_PTR(void*,0x483F78), CAST_PTR(void*,0x483FD8), CAST_PTR(void*,0x484038), CAST_PTR(void*,0x4840A8), 
		CAST_PTR(void*,0x484118), CAST_PTR(void*,0x484168), CAST_PTR(void*,0x4841F8), CAST_PTR(void*,0x484288), CAST_PTR(void*,0x4842C8), CAST_PTR(void*,0x484318), 
		CAST_PTR(void*,0x4843B8), CAST_PTR(void*,0x484408), CAST_PTR(void*,0x484458), CAST_PTR(void*,0x484508), CAST_PTR(void*,0x484558), CAST_PTR(void*,0x4845D9), 
		CAST_PTR(void*,0x484649), CAST_PTR(void*,0x4846D8), CAST_PTR(void*,0x484749), CAST_PTR(void*,0x4847A8), CAST_PTR(void*,0x4847E8), CAST_PTR(void*,0x484838), 
		CAST_PTR(void*,0x484888), CAST_PTR(void*,0x4848D8), CAST_PTR(void*,0x484928), CAST_PTR(void*,0x4849C8), CAST_PTR(void*,0x484A18), CAST_PTR(void*,0x484AB8), 
		CAST_PTR(void*,0x484B08), CAST_PTR(void*,0x484B68), CAST_PTR(void*,0x484BB8), CAST_PTR(void*,0x484C18), CAST_PTR(void*,0x484C68), CAST_PTR(void*,0x484CB8), 
		CAST_PTR(void*,0x484D08), CAST_PTR(void*,0x484D58), CAST_PTR(void*,0x484DA8), CAST_PTR(void*,0x484E08), CAST_PTR(void*,0x484E58), CAST_PTR(void*,0x484EB8), 
		CAST_PTR(void*,0x484F08), CAST_PTR(void*,0x484F58), CAST_PTR(void*,0x484FA8), CAST_PTR(void*,0x484FF8), CAST_PTR(void*,0x485048), CAST_PTR(void*,0x485098), 
		CAST_PTR(void*,0x4850E8), CAST_PTR(void*,0x485148), CAST_PTR(void*,0x485218), CAST_PTR(void*,0x485268), CAST_PTR(void*,0x4852A8), CAST_PTR(void*,0x4852F8), 
		CAST_PTR(void*,0x485358), CAST_PTR(void*,0x4853D8), CAST_PTR(void*,0x485458), CAST_PTR(void*,0x485498), CAST_PTR(void*,0x485558), CAST_PTR(void*,0x485598), 
		CAST_PTR(void*,0x485678), CAST_PTR(void*,0x485728), CAST_PTR(void*,0x4857B8), CAST_PTR(void*,0x4858F8), CAST_PTR(void*,0x485AD8), CAST_PTR(void*,0x485B58), 
		CAST_PTR(void*,0x485BA8), CAST_PTR(void*,0x4862D8), CAST_PTR(void*,0x486605), CAST_PTR(void*,0x486F1F), CAST_PTR(void*,0x486FD0), CAST_PTR(void*,0x487049), 
		CAST_PTR(void*,0x48744C), CAST_PTR(void*,0x487B93), CAST_PTR(void*,0x487CAE), CAST_PTR(void*,0x487DAB), CAST_PTR(void*,0x487E9B), CAST_PTR(void*,0x488109), 
		CAST_PTR(void*,0x4881A9), CAST_PTR(void*,0x488239), CAST_PTR(void*,0x4887D5), CAST_PTR(void*,0x4895F2), CAST_PTR(void*,0x48A193), CAST_PTR(void*,0x48D1C8), 
		CAST_PTR(void*,0x48D3C4),

#elif PLATFORM_IS_DEDI
		CAST_PTR(void*,0x474C89), CAST_PTR(void*,0x474CE8), CAST_PTR(void*,0x474D48), CAST_PTR(void*,0x474D99), CAST_PTR(void*,0x474E19), CAST_PTR(void*,0x474E79), 
		CAST_PTR(void*,0x474ED8), CAST_PTR(void*,0x474F38), CAST_PTR(void*,0x474F98), CAST_PTR(void*,0x474FE8), CAST_PTR(void*,0x475038), CAST_PTR(void*,0x475088), 
		CAST_PTR(void*,0x4750E8), CAST_PTR(void*,0x475138), CAST_PTR(void*,0x475188), CAST_PTR(void*,0x4751D8), CAST_PTR(void*,0x475228), CAST_PTR(void*,0x475279), 
		CAST_PTR(void*,0x4752E8), CAST_PTR(void*,0x475338), CAST_PTR(void*,0x475388), CAST_PTR(void*,0x4753D8), CAST_PTR(void*,0x475429), CAST_PTR(void*,0x475489), 
		CAST_PTR(void*,0x4754E8), CAST_PTR(void*,0x475538), CAST_PTR(void*,0x475598), CAST_PTR(void*,0x475629), CAST_PTR(void*,0x4756B8), CAST_PTR(void*,0x475738), 
		CAST_PTR(void*,0x475789), CAST_PTR(void*,0x475828), CAST_PTR(void*,0x475879), CAST_PTR(void*,0x4758D9), CAST_PTR(void*,0x475939), CAST_PTR(void*,0x475998), 
		CAST_PTR(void*,0x4759E9), CAST_PTR(void*,0x475A58), CAST_PTR(void*,0x475AD8), CAST_PTR(void*,0x475B68), CAST_PTR(void*,0x475BE8), CAST_PTR(void*,0x475C38), 
		CAST_PTR(void*,0x475CB8), CAST_PTR(void*,0x475D58), CAST_PTR(void*,0x475D98), CAST_PTR(void*,0x475DD8), CAST_PTR(void*,0x475E58), CAST_PTR(void*,0x475E98), 
		CAST_PTR(void*,0x475EF8), CAST_PTR(void*,0x475F68), CAST_PTR(void*,0x475FC9), CAST_PTR(void*,0x476029), CAST_PTR(void*,0x476088), CAST_PTR(void*,0x4760D8), 
		CAST_PTR(void*,0x476148), CAST_PTR(void*,0x4761D8), CAST_PTR(void*,0x476228), CAST_PTR(void*,0x476278), CAST_PTR(void*,0x4762D8), CAST_PTR(void*,0x476339), 
		CAST_PTR(void*,0x476398), CAST_PTR(void*,0x476409), CAST_PTR(void*,0x476479), CAST_PTR(void*,0x4764E9), CAST_PTR(void*,0x476559), CAST_PTR(void*,0x4765E8), 
		CAST_PTR(void*,0x476678), CAST_PTR(void*,0x4766E8), CAST_PTR(void*,0x476778), CAST_PTR(void*,0x4767C9), CAST_PTR(void*,0x476829), CAST_PTR(void*,0x476888), 
		CAST_PTR(void*,0x4768D8), CAST_PTR(void*,0x476919), CAST_PTR(void*,0x476998), CAST_PTR(void*,0x4769E8), CAST_PTR(void*,0x476A38), CAST_PTR(void*,0x476A89), 
		CAST_PTR(void*,0x476AE9), CAST_PTR(void*,0x476B48), CAST_PTR(void*,0x476B98), CAST_PTR(void*,0x476C38), CAST_PTR(void*,0x476C78), CAST_PTR(void*,0x476CD8), 
		CAST_PTR(void*,0x476D38), CAST_PTR(void*,0x476DB8), CAST_PTR(void*,0x476E39), CAST_PTR(void*,0x476EB9), CAST_PTR(void*,0x476F29), CAST_PTR(void*,0x476F88), 
		CAST_PTR(void*,0x476FC8), CAST_PTR(void*,0x477018), CAST_PTR(void*,0x477088), CAST_PTR(void*,0x4770D8), CAST_PTR(void*,0x477169), CAST_PTR(void*,0x4771E8), 
		CAST_PTR(void*,0x477268), CAST_PTR(void*,0x4772F8), CAST_PTR(void*,0x477379), CAST_PTR(void*,0x477418), CAST_PTR(void*,0x477498), CAST_PTR(void*,0x477518), 
		CAST_PTR(void*,0x477569), CAST_PTR(void*,0x4775C8), CAST_PTR(void*,0x477618), CAST_PTR(void*,0x477698), CAST_PTR(void*,0x477718), CAST_PTR(void*,0x477818), 
		CAST_PTR(void*,0x477858), CAST_PTR(void*,0x4778A8), CAST_PTR(void*,0x4778F8), CAST_PTR(void*,0x477938), CAST_PTR(void*,0x477978), CAST_PTR(void*,0x4779C8), 
		CAST_PTR(void*,0x477A18), CAST_PTR(void*,0x477A68), CAST_PTR(void*,0x477AD8), CAST_PTR(void*,0x477B18), CAST_PTR(void*,0x477B68), CAST_PTR(void*,0x477BB8), 
		CAST_PTR(void*,0x477C08), CAST_PTR(void*,0x477C88), CAST_PTR(void*,0x477CD8), CAST_PTR(void*,0x477D68), CAST_PTR(void*,0x477DD8), CAST_PTR(void*,0x477E48), 
		CAST_PTR(void*,0x477E98), CAST_PTR(void*,0x477EE8), CAST_PTR(void*,0x477F38), CAST_PTR(void*,0x477F88), CAST_PTR(void*,0x477FC8), CAST_PTR(void*,0x478008), 
		CAST_PTR(void*,0x478048), CAST_PTR(void*,0x478088), CAST_PTR(void*,0x4780C8), CAST_PTR(void*,0x478118), CAST_PTR(void*,0x478168), CAST_PTR(void*,0x4781F8), 
		CAST_PTR(void*,0x478248), CAST_PTR(void*,0x478298), CAST_PTR(void*,0x4782F8), CAST_PTR(void*,0x478348), CAST_PTR(void*,0x478398), CAST_PTR(void*,0x4783D8), 
		CAST_PTR(void*,0x478428), CAST_PTR(void*,0x478478), CAST_PTR(void*,0x4784C8), CAST_PTR(void*,0x478518), CAST_PTR(void*,0x478568), CAST_PTR(void*,0x4785B8), 
		CAST_PTR(void*,0x4785F8), CAST_PTR(void*,0x478638), CAST_PTR(void*,0x478688), CAST_PTR(void*,0x4786C8), CAST_PTR(void*,0x478718), CAST_PTR(void*,0x478768), 
		CAST_PTR(void*,0x4787A8), CAST_PTR(void*,0x478828), CAST_PTR(void*,0x4788A8), CAST_PTR(void*,0x4788F8), CAST_PTR(void*,0x478948), CAST_PTR(void*,0x478998), 
		CAST_PTR(void*,0x4789F8), CAST_PTR(void*,0x478A48), CAST_PTR(void*,0x478AA8), CAST_PTR(void*,0x478B08), CAST_PTR(void*,0x478B68), CAST_PTR(void*,0x478BD8), 
		CAST_PTR(void*,0x478C18), CAST_PTR(void*,0x478C68), CAST_PTR(void*,0x478CA8), CAST_PTR(void*,0x478CF8), CAST_PTR(void*,0x478D58), CAST_PTR(void*,0x478DB8), 
		CAST_PTR(void*,0x478E38), CAST_PTR(void*,0x478EB8), CAST_PTR(void*,0x478F18), CAST_PTR(void*,0x478F68), CAST_PTR(void*,0x478FB8), CAST_PTR(void*,0x479018), 
		CAST_PTR(void*,0x479068), CAST_PTR(void*,0x4790B8), CAST_PTR(void*,0x479108), CAST_PTR(void*,0x479159), CAST_PTR(void*,0x4791B9), CAST_PTR(void*,0x479219), 
		CAST_PTR(void*,0x479279), CAST_PTR(void*,0x4792D8), CAST_PTR(void*,0x479368), CAST_PTR(void*,0x4793C9), CAST_PTR(void*,0x479439), CAST_PTR(void*,0x4794A8), 
		CAST_PTR(void*,0x4794F9), CAST_PTR(void*,0x479559), CAST_PTR(void*,0x4795B9), CAST_PTR(void*,0x479619), CAST_PTR(void*,0x479679), CAST_PTR(void*,0x479718), 
		CAST_PTR(void*,0x479768), CAST_PTR(void*,0x4797B8), CAST_PTR(void*,0x479808), CAST_PTR(void*,0x479858), CAST_PTR(void*,0x4798B8), CAST_PTR(void*,0x479968), 
		CAST_PTR(void*,0x479A48), CAST_PTR(void*,0x479A99), CAST_PTR(void*,0x479DD8), CAST_PTR(void*,0x479E58), CAST_PTR(void*,0x479EA8), CAST_PTR(void*,0x479EF8), 
		CAST_PTR(void*,0x479F48), CAST_PTR(void*,0x47A008), CAST_PTR(void*,0x47A088), CAST_PTR(void*,0x47A1C8), CAST_PTR(void*,0x47A228), CAST_PTR(void*,0x47A278), 
		CAST_PTR(void*,0x47A2C8), CAST_PTR(void*,0x47A538), CAST_PTR(void*,0x47A5B8), CAST_PTR(void*,0x47A5F8), CAST_PTR(void*,0x47A648), CAST_PTR(void*,0x47A6B8), 
		CAST_PTR(void*,0x47A738), CAST_PTR(void*,0x47A7A8), CAST_PTR(void*,0x47A7F8), CAST_PTR(void*,0x47A838), CAST_PTR(void*,0x47A888), CAST_PTR(void*,0x47A8D8), 
		CAST_PTR(void*,0x47A928), CAST_PTR(void*,0x47A978), CAST_PTR(void*,0x47A9B8), CAST_PTR(void*,0x47AA28), CAST_PTR(void*,0x47AA98), CAST_PTR(void*,0x47AB08), 
		CAST_PTR(void*,0x47AB99), CAST_PTR(void*,0x47ABF9), CAST_PTR(void*,0x47AC58), CAST_PTR(void*,0x47ACF8), CAST_PTR(void*,0x47AD68), CAST_PTR(void*,0x47ADD8), 
		CAST_PTR(void*,0x47AE38), CAST_PTR(void*,0x47AE98), CAST_PTR(void*,0x47AEF8), CAST_PTR(void*,0x47AF58), CAST_PTR(void*,0x47AFA8), CAST_PTR(void*,0x47B019), 
		CAST_PTR(void*,0x47B078), CAST_PTR(void*,0x47B0C8), CAST_PTR(void*,0x47B118), CAST_PTR(void*,0x47B158), CAST_PTR(void*,0x47B1B8), CAST_PTR(void*,0x47B229), 
		CAST_PTR(void*,0x47B2B9), CAST_PTR(void*,0x47B328), CAST_PTR(void*,0x47B388), CAST_PTR(void*,0x47B3E8), CAST_PTR(void*,0x47B448), CAST_PTR(void*,0x47B4A8), 
		CAST_PTR(void*,0x47B508), CAST_PTR(void*,0x47B568), CAST_PTR(void*,0x47B5F8), CAST_PTR(void*,0x47B648), CAST_PTR(void*,0x47B698), CAST_PTR(void*,0x47B6E8), 
		CAST_PTR(void*,0x47B748), CAST_PTR(void*,0x47B7D8), CAST_PTR(void*,0x47B828), CAST_PTR(void*,0x47B918), CAST_PTR(void*,0x47B978), CAST_PTR(void*,0x47B9E8), 
		CAST_PTR(void*,0x47BA48), CAST_PTR(void*,0x47BAA8), CAST_PTR(void*,0x47BB18), CAST_PTR(void*,0x47BB88), CAST_PTR(void*,0x47BBD8), CAST_PTR(void*,0x47BC68), 
		CAST_PTR(void*,0x47BCF8), CAST_PTR(void*,0x47BD38), CAST_PTR(void*,0x47BDB9), CAST_PTR(void*,0x47BE29), CAST_PTR(void*,0x47BEB8), CAST_PTR(void*,0x47BF29), 
		CAST_PTR(void*,0x47BF88), CAST_PTR(void*,0x47BFC8), CAST_PTR(void*,0x47C018), CAST_PTR(void*,0x47C068), CAST_PTR(void*,0x47C0B8), CAST_PTR(void*,0x47C108), 
		CAST_PTR(void*,0x47C1A8), CAST_PTR(void*,0x47C1F8), CAST_PTR(void*,0x47C298), CAST_PTR(void*,0x47C2E8), CAST_PTR(void*,0x47C348), CAST_PTR(void*,0x47C398), 
		CAST_PTR(void*,0x47C3F8), CAST_PTR(void*,0x47C448), CAST_PTR(void*,0x47C498), CAST_PTR(void*,0x47C4E8), CAST_PTR(void*,0x47C538), CAST_PTR(void*,0x47C588), 
		CAST_PTR(void*,0x47C5E8), CAST_PTR(void*,0x47C638), CAST_PTR(void*,0x47C698), CAST_PTR(void*,0x47C6E8), CAST_PTR(void*,0x47C738), CAST_PTR(void*,0x47C788), 
		CAST_PTR(void*,0x47C7D8), CAST_PTR(void*,0x47C828), CAST_PTR(void*,0x47C878), CAST_PTR(void*,0x47C8C8), CAST_PTR(void*,0x47C928), CAST_PTR(void*,0x47C9F8), 
		CAST_PTR(void*,0x47CA48), CAST_PTR(void*,0x47CA88), CAST_PTR(void*,0x47CAD8), CAST_PTR(void*,0x47CB38), CAST_PTR(void*,0x47CBB8), CAST_PTR(void*,0x47CC38), 
		CAST_PTR(void*,0x47CC78), CAST_PTR(void*,0x47CD38), CAST_PTR(void*,0x47CD78), CAST_PTR(void*,0x47CE58), CAST_PTR(void*,0x47CF08), CAST_PTR(void*,0x47CF68), 
		CAST_PTR(void*,0x47D078), CAST_PTR(void*,0x47D258), CAST_PTR(void*,0x47D2B8), CAST_PTR(void*,0x47D328), CAST_PTR(void*,0x47D598), CAST_PTR(void*,0x47DBC8), 
		CAST_PTR(void*,0x47DEE5), CAST_PTR(void*,0x47E7FF), CAST_PTR(void*,0x47E8B0), CAST_PTR(void*,0x47E929), CAST_PTR(void*,0x47ED2C), CAST_PTR(void*,0x47F473), 
		CAST_PTR(void*,0x47F58E), CAST_PTR(void*,0x47F68B), CAST_PTR(void*,0x47F77B), CAST_PTR(void*,0x47F9E9), CAST_PTR(void*,0x47FA89), CAST_PTR(void*,0x47FB19), 
		CAST_PTR(void*,0x480145), CAST_PTR(void*,0x480F62), CAST_PTR(void*,0x481B03), CAST_PTR(void*,0x484AA8), CAST_PTR(void*,0x484CA4), 
#endif
	};
	#pragma endregion

	//////////////////////////////////////////////////////////////////////////
	// script globals related
	ENGINE_PTR(int32, hs_external_globals_count,			0x5F9D2C, 0x5557CC);
	ENGINE_DPTR(hs_global_definition, hs_external_globals,	0x626988, 0x59C328);

	static int16* K_HS_EXTERNAL_GLOBALS_COUNT_REFERENCES_16bit[] = {
		CAST_PTR(int16*, PLATFORM_VALUE(0x486201, 0x47DAF1)),
	};
	static int32* K_HS_EXTERNAL_GLOBALS_COUNT_REFERENCES_32bit[] = {
		CAST_PTR(int32*, PLATFORM_VALUE(0x4866BA, 0x47DF9A)), CAST_PTR(int32*, PLATFORM_VALUE(0x48BDEA, 0x4836CA)),
		CAST_PTR(int32*, PLATFORM_VALUE(0x48CC0B, 0x4844EB)), CAST_PTR(int32*, PLATFORM_VALUE(0x48CD1F, 0x4845FF)),
		CAST_PTR(int32*, PLATFORM_VALUE(0x48CD7D, 0x48465D)), CAST_PTR(int32*, PLATFORM_VALUE(0x48CE80, 0x484760)),
		CAST_PTR(int32*, PLATFORM_VALUE(0x48D49A, 0x484D7A)),
	};
	static void* K_HS_EXTERNAL_GLOBALS_REFERENCES[] = {
		CAST_PTR(void*, PLATFORM_VALUE(0x48618C, 0x47DA7C)), CAST_PTR(void*, PLATFORM_VALUE(0x4861BC, 0x47DAAC)), 
		CAST_PTR(void*, PLATFORM_VALUE(0x4861E9, 0x47DAD9)), CAST_PTR(void*, PLATFORM_VALUE(0x486520, 0x47DE00)), 
		CAST_PTR(void*, PLATFORM_VALUE(0x4866B5, 0x47DF95)), CAST_PTR(void*, PLATFORM_VALUE(0x4892F2, 0x480C62)), 
		CAST_PTR(void*, PLATFORM_VALUE(0x48BD7E, 0x48365E)), CAST_PTR(void*, PLATFORM_VALUE(0x48D2F6, 0x484BD6)), 
		CAST_PTR(void*, PLATFORM_VALUE(0x48DC2B, 0x48550B)), CAST_PTR(void*, PLATFORM_VALUE(0x48DD97, 0x485677)), 
	};

	//////////////////////////////////////////////////////////////////////////

	FUNC_PTR(HS_VALID_ACCESS_FLAGS, 0x486330, 0x47DC20);

	//////////////////////////////////////////////////////////////////////////
	// InitializeCreateScriptFunction()
	FUNC_PTR(HS_ARGUMENTS_EVALUATE,	0x48D590, 0x484E70);
	FUNC_PTR(HS_RETURN,				0x48D380, 0x484C60);

#endif