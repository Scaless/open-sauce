/*
    Yelo: Open Sauce SDK

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

namespace Yelo
{
	namespace Enums
	{
		enum {
			// character count in a [tag_string] type
			k_tag_string_length = 31,

			k_string_64_length = 63,
			k_string_128_length = 127,
			k_string_256_length = 255,
		};
	};


	// System Initialize function pointer
	typedef void (* proc_initialize)();
	// System Dispose function pointer
	typedef void (* proc_dispose)();
	// System Initialize for new map function pointer
	typedef void (* proc_initialize_for_new_map)();
	// System Dispose from old map function pointer
	typedef void (* proc_dispose_from_old_map)();
	// System Update function pointer
	typedef void (* proc_update)();


	/// Template class for defining an interface for blocks of data whose memory format is not entirely mapped out
	template<size_t _SIZE> struct TStruct {

	protected:
		unsigned char _data[_SIZE];
		
		template<typename T, size_t offset> API_INLINE T GetData()					{ return *( CAST_PTR(T*, &_data[offset]) ); }
		template<typename T, size_t offset> API_INLINE T GetData() const			{ return *( CAST_PTR(const T*, &_data[offset]) ); }
		template<typename T, size_t offset> API_INLINE T* GetDataPtr()				{ return CAST_PTR(T*, &_data[offset]); }
//		template<typename T, size_t offset> API_INLINE const T* GetDataPtr() const	{ return CAST_PTR(const T*, &_data[offset]); }

		//inline * Get() { return GetDataPtr<, 0x>(); }

		// Usage - "struct some_object : TStructImpl(0x40) {};"
#define TStructImpl(size) public TStruct< size >

#define TStructGetImpl(type, name, offset)															\
	API_INLINE type Get##name()				{ return GetData<type, offset>(); }						\
	API_INLINE type Get##name() const		{ return GetData<type, offset>(); }
#define TStructGetPtrImpl(type, name, offset)														\
	API_INLINE type* Get##name()			{ return GetDataPtr<type, offset>(); }					\
//	API_INLINE const type* Get##name() const{ return GetDataPtr<type, offset>(); }

#define TStructSubGetImpl(type, name, offset)														\
	API_INLINE type Get##name()				{ return GetData<type, offset - DATA_OFFSET>(); }		\
	API_INLINE type Get##name() const		{ return GetData<type, offset - DATA_OFFSET>(); }
#define TStructSubGetPtrImpl(type, name, offset)													\
	API_INLINE type* Get##name()			{ return GetDataPtr<type, offset - DATA_OFFSET>(); }	\
//	API_INLINE const type* Get##name() const{ return GetDataPtr<type, offset - DATA_OFFSET>(); }
	};


#pragma region Numeral types

#define pad_bool PAD8

	// # from 0 to 255
	typedef unsigned char byte;
	// # from -128 to 127
	typedef signed char sbyte;
#define pad_byte PAD8

	// # from 0 to 65,535
	typedef unsigned short uint16;
	// # from -32,768 to 32,767
	typedef signed short int16;
#define pad_int16 PAD16

	// # from 0 to 4,294,967,295
	typedef unsigned long uint32;
#define pad_uint32 PAD32
	// # from -2147483648 to 2147483647
	typedef signed long int32;
#define pad_int32 PAD32

	// # from 0 to 18,446,744,073,709,551,615
	typedef unsigned __int64 uint64;
	// # from -9,223,372,036,854,775,808 to 9,223,372,036,854,775,807
	typedef signed __int64 int64;
#define pad_int64 PAD32

	// a floating-point # from 1.175494351e-38F to 3.402823466e+38F
	typedef float real;
#define pad_real PAD32

	// min value for a [sbyte]
	extern const sbyte K_SBYTE_MIN;
	// max value for a [sbyte]
	extern const sbyte K_SBYTE_MAX;
	// min value for a [byte]
	extern const byte K_BYTE_MIN;
	// max value for a [byte]
	extern const byte K_BYTE_MAX;
	// min value for a [int16]
	extern const int16 K_INT16_MIN;
	// max value for a [int16]
	extern const int16 K_INT16_MAX;
	// min value for a [uint16]
	extern const uint16 K_UINT16_MIN;
	// max value for a [uint16]
	extern const uint16 K_UINT16_MAX;
	// min value for a [int32]
	extern const int32 K_INT32_MIN;
	// max value for a [int32]
	extern const int32 K_INT32_MAX;
	// min value for a [uint32]
	extern const uint32 K_UINT32_MIN;
	// max value for a [uint32]
	extern const uint32 K_UINT32_MAX;
	// min value for a [int64]
	extern const int64 K_INT64_MIN;
	// max value for a [int64]
	extern const int64 K_INT64_MAX;
	// min value for a [uint64]
	extern const uint64 K_UINT64_MIN;
	// max value for a [uint64]
	extern const uint64 K_UINT64_MAX;
	// min value for a [real]
	extern const real K_REAL_MIN;
	// max value for a [real]
	extern const real K_REAL_MAX;
#pragma endregion


#pragma region String types / utils
	// Constant '\0' terminated ascii string
	typedef const char* cstring;
	// '\0\0' terminated unicode string
	typedef wchar_t* wstring;
	// Constant '\0\0' terminated unicode string
	typedef const wchar_t* wcstring;

	// null value for a [string] or [cstring]
#define CSTRING_NULL	"\0"
	// null value for a [wstring] or [wcstring]
#define WSTRING_NULL	L"\0"

	// Takes [wide] and converts it to an ascii string, to be held in [string]. If [wide_length] is not -1, the string
	// is assumed to be null terminated
	// Returns [string] if successful
	char* wstring_to_string(char* string, int32 string_length, wcstring wide, int32 wide_length = -1);

	char* wstring_to_string_lazy(char* string, int32 string_length, wcstring wide);

	// Takes [string] and converts it to an unicode string, to be held in [wide]. If [string_length] is not -1, the string
	// is assumed to be null terminated
	// Returns [wide] if successful
	wstring string_to_wstring(wstring wide, int32 wide_length, cstring string, int32 string_length = -1);

	wstring string_to_wstring_lazy(wstring string, int32 string_length, cstring ascii);

	// 32 character ASCII string, with null terminator
	typedef char tag_string[Yelo::Enums::k_tag_string_length+1];
#define pad_tag_string PAD32 PAD32 PAD32 PAD32 PAD32 PAD32 PAD32 PAD32

	// 128 character ASCII string, with null terminator
	typedef char string128[Yelo::Enums::k_string_128_length+1];
	// 256 character ASCII string, with null terminator
	typedef char string256[Yelo::Enums::k_string_256_length+1];

	// 64 character UNICODE string (128 bytes), with null terminator
	typedef wchar_t wstring64[Yelo::Enums::k_string_64_length+1];
	// 256 character UNICODE string (512 bytes), with null terminator
	typedef wchar_t wstring256[Yelo::Enums::k_string_256_length+1];

#pragma endregion

#pragma region tag type definitions
	// a floating number in degrees
	typedef float angle;
#define pad_angle PAD32

	// a tag group id
	typedef unsigned long tag;

	// an enumerated value in a 1 byte range
	typedef unsigned char byte_enum;
#define pad_byte_enum PAD8

	// an enumerated value in a 2 byte range
	typedef unsigned short _enum;
#define pad_enum PAD16

	// an enumerated value in a 4 byte range (not an officially used type in halo 1 tags, at least not up front anyway)
	typedef unsigned long long_enum;

	// bit flags in a 1 byte range
	typedef unsigned char byte_flags;
#define pad_byte_flags PAD8

	// bit flags in a 2 byte range
	typedef unsigned short word_flags;
#define pad_word_flags PAD16

	// bit flags in a 4 byte range
	typedef unsigned long long_flags;
#define pad_long_flags PAD32


	// 2 shorts representing 'x' and 'y'
	struct point2d
	{
		int16 x;
		int16 y;

		OVERRIDE_OPERATOR_CAST_THIS(int16);
	};
#define pad_point2d PAD16 PAD16

	// 4 shorts, Top, Left, Bottom, Right
	struct rectangle2d
	{
		// Top
		int16 top;

		// Left
		int16 left;

		// Botom
		int16 bottom;

		// Right
		int16 right;

		OVERRIDE_OPERATOR_CAST_THIS(int16);
	};
#define pad_rectangle2d PAD16 PAD16 PAD16 PAD16


	struct argb_color;
	// 0 - 255, represents a color
	struct rgb_color
	{
		PAD8;
		byte red;
		byte green;
		byte blue;

		OVERRIDE_OPERATOR_CAST_THIS(argb_color);
		OVERRIDE_OPERATOR_CAST_THIS(uint32);
	};
#define pad_rgb_color PAD32

	// 0 - 255, represents a color
	struct argb_color
	{
		byte alpha;
		byte red;
		byte green;
		byte blue;

		OVERRIDE_OPERATOR_CAST_THIS(rgb_color);
		OVERRIDE_OPERATOR_CAST_THIS(uint32);
	};
#define pad_argb_color PAD32

	// bounding in short integer values
	struct short_bounds
	{
		int16 lower;
		int16 upper;

		OVERRIDE_OPERATOR_CAST_THIS(int16);
	};

#pragma endregion


#pragma region 'real' type based definitions
	// a fraction represented in a floating-point number
	typedef float real_fraction;

	#define pad_real_point2d PAD32 PAD32
	#define pad_real_point3d PAD32 PAD32 PAD32
	#define pad_real_vector2d PAD32 PAD32
	#define pad_real_vector3d PAD32 PAD32 PAD32
	#define pad_real_quaternion PAD32 PAD32 PAD32 PAD32
	#define pad_real_euler_angles2d PAD32 PAD32
	#define pad_real_euler_angles3d PAD32 PAD32 PAD32
	#define pad_real_plane2d PAD32 PAD32 PAD32
	#define pad_real_plane3d PAD32 PAD32 PAD32 PAD32
	#define pad_real_matrix3x3	PAD_TYPE(real_vector3d) \
								PAD_TYPE(real_vector3d) \
								PAD_TYPE(real_vector3d) \
	#define pad_real_matrix4x3	PAD32 \
								PAD_TYPE(real_vector3d) \
								PAD_TYPE(real_vector3d) \
								PAD_TYPE(real_vector3d) \
								PAD_TYPE(real_point3d)

	/*union*/ struct real_rectangle2d
	{
		real x0, x1;
		real y0, y1;
	};
	#define pad_real_rectangle2d	PAD32 PAD32 \
									PAD32 PAD32

	/*union*/ struct real_rectangle3d
	{
		real x0, x1;
		real y0, y1;
		real z0, z1;
	};
	#define pad_real_rectangle3d	PAD32 PAD32 \
									PAD32 PAD32 \
									PAD32 PAD32

	#define pad_real_orientation3d	PAD_TYPE(real_quaternion)	\
									PAD_TYPE(real_point3d)		\
									PAD32

	// represents a color, range: 0 - 1
	struct real_rgb_color
	{
		real red;
		real green;
		real blue;

		OVERRIDE_OPERATOR_CAST_THIS(float);
	};
	#define pad_real_rgb_color PAD32 PAD32 PAD32

	// represents a color, range: 0 - 1
	struct real_argb_color
	{
		real alpha;
		real red;
		real green;
		real blue;

		OVERRIDE_OPERATOR_CAST_THIS(float);
		OVERRIDE_OPERATOR_CAST_THIS_BY_FIELD(real_rgb_color, red);
	};
	#define pad_real_argb_color PAD32 PAD32 PAD32 PAD32

	// bounding in real angle values
	struct angle_bounds
	{
		angle lower;
		angle upper;

		OVERRIDE_OPERATOR_CAST_THIS(float);
	};

	// bounding in real values
	struct real_bounds
	{
		real lower;
		real upper;

		OVERRIDE_OPERATOR_CAST_THIS(float);
	};
	#define pad_real_bounds PAD32 PAD32

	// bounding in real values
	struct real_fraction_bounds
	{
		real lower;
		real upper;

		OVERRIDE_OPERATOR_CAST_THIS(float);
	};

#pragma endregion


	// strong reference index
	struct datum_index
	{
		static const datum_index null;

		union {
			uint32 handle;
			struct {
				// absolute index
				int16 index;
				// salted index
				int16 salt;
			};
		};

		API_INLINE bool IsNull() const { return null == handle; }

		OVERRIDE_OPERATOR_CAST_THIS(uint32);
		OVERRIDE_OPERATOR(=, datum_index&, uint32 arg) { this->handle = arg; return *this; }
		OVERRIDE_OPERATOR_MATH_BOOL(datum_index, handle, ==);
		OVERRIDE_OPERATOR_MATH_BOOL(datum_index, handle, !=);
	private:
		OVERRIDE_OPERATOR_MATH_BOOL_TYPE(uint32, handle, ==);
		OVERRIDE_OPERATOR_MATH_BOOL_TYPE(uint32, handle, !=);
	}; BOOST_STATIC_ASSERT( sizeof(datum_index) == 0x4 );
#define pad_datum_index PAD16 PAD16
#define DATUM_INDEX_TO_IDENTIFIER(datum) datum & 0x0FFFF0000
#define DATUM_INDEX_ABSOLUTE(datum) ( (datum & 0xFFFF) << 5 )


	struct s_scenario_location
	{
		int32 leaf_index;
		int16 cluster_index;
		UNKNOWN_TYPE(int16); // i think this is actually padding?
	}; BOOST_STATIC_ASSERT( sizeof(s_scenario_location) == 0x8 );


	template<typename T> struct TTypeHolder
	{
		union { // t_type_interface_union
			T* pointer;

			union {// t_type_interface_pointers
				bool* boolean;
				char* character;
				Yelo::byte* byte;
				Yelo::sbyte* sbyte;
				Yelo::uint16* uint16;
				Yelo::int16* int16;
				Yelo::uint32* uint32;
				Yelo::int32* int32;
				Yelo::real* real;

				datum_index* datum;

				Yelo::cstring ascii;
				Yelo::wstring unicode;
			}ptr;

			union {// t_type_interface_arrayss
				bool boolean[1];
				char character[1];
				Yelo::byte byte[1];
				Yelo::sbyte sbyte[1];
				Yelo::uint16 uint16[1];
				Yelo::int16 int16[1];
				Yelo::uint32 uint32[1];
				Yelo::int32 int32[1];
				Yelo::real real[1];

				datum_index datum[1];

				Yelo::cstring ascii[1];
				Yelo::wstring unicode[1];
			}array;

			bool boolean;
			char character;
			Yelo::byte byte;
			Yelo::sbyte sbyte;
			Yelo::uint16 uint16;
			Yelo::int16 int16;
			Yelo::uint32 uint32;
			Yelo::int32 int32;
			Yelo::real real;

			datum_index datum;
		};
	};
	typedef TTypeHolder<void> TypeHolder;
	BOOST_STATIC_ASSERT( sizeof(TypeHolder) == 0x4 );

	template<typename t_interface> void safe_release(t_interface*& obj)
	{
		if(obj != NULL)
		{
			obj->Release();
			obj = NULL;
		}
	}
};