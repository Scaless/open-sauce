/*
    BlamLib: .NET SDK for the Blam Engine

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
﻿
namespace BlamLib
{
	partial class Program
	{
		/// <summary>
		/// Halo 1 global wide values
		/// </summary>
		public static class Halo1
		{
			#region Manager
			static Blam.Halo1.GameDefinition manager = new Blam.Halo1.GameDefinition();
			/// <summary>
			/// Halo 1's specific manager instance
			/// </summary>
			public static Blam.Halo1.GameDefinition Manager { get { return manager; } }
			#endregion

			/// <summary>
			/// Initialize the resources used by the Halo 1 systems
			/// </summary>
			public static void Initialize()
			{
				manager.Read(Managers.GameManager.GetRelativePath(BlamLib.Managers.GameManager.Namespace.Halo1), "Halo1.xml");
			}

			/// <summary>
			/// Close the resources used by the Halo 1 systems
			/// </summary>
			public static void Close()
			{
				ClosePc();
				CloseCe();
				manager.Close();
			}

			#region PC
			/// <summary>
			/// Path to the HaloPC file 'bitmaps.map'
			/// </summary>
			static string PcBitmapsPath;
			/// <summary>
			/// Object for the HaloPC file 'bitmaps.map'
			/// </summary>
			public static Blam.Halo1.BitmapCacheFile PcBitmaps;

			/// <summary>
			/// Path to the HaloPC file 'sounds.map'
			/// </summary>
			static string PcSoundsPath;
			/// <summary>
			/// Object for the HaloPC file 'sounds.map'
			/// </summary>
			public static Blam.Halo1.SoundCacheFile PcSounds;

			/// <summary>
			/// Load the HaloPC files we need to fully run this library
			/// </summary>
			/// <remarks>
			/// Paths[0] = Bitmaps
			/// Paths[1] = Sounds
			/// </remarks>
			/// <param name="paths"></param>
			public static void LoadPc(params string[] paths)
			{
				Blam.DatumIndex di;

				if (paths.Length >= 1 && System.IO.File.Exists(paths[0]))
				{
					di = manager.OpenResourceCacheFile(BlamVersion.Halo1_PC, PcBitmapsPath = paths[0]);
					PcBitmaps = manager.GetCacheFile(di) as BlamLib.Blam.Halo1.BitmapCacheFile;
					PcBitmaps.ReadResourceCache();
				}

				if (paths.Length >= 2 && System.IO.File.Exists(paths[1]))
				{
					di = manager.OpenResourceCacheFile(BlamVersion.Halo1_PC, PcSoundsPath = paths[1]);
					PcSounds = manager.GetCacheFile(di) as BlamLib.Blam.Halo1.SoundCacheFile;
					PcSounds.ReadResourceCache();
				}
			}

			/// <summary>
			/// Closes the shared pc caches
			/// </summary>
			public static void ClosePc()
			{
				if (PcBitmaps != null)	manager.CloseCacheFile(PcBitmaps.CacheId);
				if (PcSounds != null)	manager.CloseCacheFile(PcSounds.CacheId);
			}
			#endregion

			#region CE
			/// <summary>
			/// Path to the HaloCE file 'bitmaps.map'
			/// </summary>
			static string CeBitmapsPath;
			/// <summary>
			/// Object for the HaloCE file 'bitmaps.map'
			/// </summary>
			public static Blam.Halo1.BitmapCacheFile CeBitmaps;

			/// <summary>
			/// Path to the HaloCE file 'sounds.map'
			/// </summary>
			static string CeSoundsPath;
			/// <summary>
			/// Object for the HaloCE file 'sounds.map'
			/// </summary>
			public static Blam.Halo1.SoundCacheFile CeSounds;

			/// <summary>
			/// Path to the HaloCE file 'loc.map'
			/// </summary>
			static string CeLocPath;
			/// <summary>
			/// Object for the HaloCE file 'loc.map'
			/// </summary>
			public static Blam.Halo1.LocCacheFile CeLoc;

			/// <summary>
			/// Load the HaloCE files we need to fully run this library
			/// </summary>
			/// <remarks>
			/// Paths[0] = Bitmaps
			/// Paths[1] = Sounds
			/// Paths[2] = Loc
			/// </remarks>
			/// <param name="paths"></param>
			public static void LoadCe(params string[] paths)
			{
				Blam.DatumIndex di;

				if (paths.Length >= 1 && System.IO.File.Exists(paths[0]))
				{
					di = manager.OpenResourceCacheFile(BlamVersion.Halo1_CE, CeBitmapsPath = paths[0]);
					CeBitmaps = manager.GetCacheFile(di) as BlamLib.Blam.Halo1.BitmapCacheFile;
					CeBitmaps.ReadResourceCache();
				}

				if (paths.Length >= 2 && System.IO.File.Exists(paths[1]))
				{
					di = manager.OpenResourceCacheFile(BlamVersion.Halo1_CE, CeSoundsPath = paths[1]);
					CeSounds = manager.GetCacheFile(di) as BlamLib.Blam.Halo1.SoundCacheFile;
					CeSounds.ReadResourceCache();
				}

				if (paths.Length >= 3 && System.IO.File.Exists(paths[2]))
				{
					di = manager.OpenResourceCacheFile(BlamVersion.Halo1_CE, CeLocPath = paths[2]);
					CeLoc = manager.GetCacheFile(di) as BlamLib.Blam.Halo1.LocCacheFile;
					CeLoc.ReadResourceCache();
				}
			}

			/// <summary>
			/// Closes the shared ce caches
			/// </summary>
			public static void CloseCe()
			{
				if (CeBitmaps != null)	manager.CloseCacheFile(CeBitmaps.CacheId);
				if (CeSounds != null)	manager.CloseCacheFile(CeSounds.CacheId);
				if (CeLoc != null)		manager.CloseCacheFile(CeLoc.CacheId);
			}
			#endregion
		};
	};
}