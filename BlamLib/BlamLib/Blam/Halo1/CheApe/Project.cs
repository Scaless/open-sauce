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
using System;
using System.Collections.Generic;
using System.Text;

namespace BlamLib.Blam.Halo1.CheApe
{
	/// <summary>
	/// Halo 1 Project interface implementation details
	/// </summary>
	internal static class Project
	{
		/// <summary>
		/// Halo 1 project state implementation
		/// </summary>
		public sealed class ProjectState : BlamLib.CheApe.ProjectState
		{
			/// <summary>
			/// Implementation constructor
			/// </summary>
			/// <param name="proj">Project which this state will work with</param>
			public ProjectState(BlamLib.CheApe.Project proj) : base(BlamVersion.Halo1_CE, proj)
			{
				importer = new Import();
				compiler = new Compiler(this);
			}
		};

		#region Interface
		/// <summary>
		/// Halo 1 specific implementation interface for CheApe projects
		/// </summary>
		public sealed class Interface : BlamLib.CheApe.Project.Interface
		{
			/// <summary>
			/// Create a new project file and object
			/// </summary>
			/// <param name="file">Path to the project file</param>
			/// <returns>Read to use Project object</returns>
			public BlamLib.CheApe.Project Create(string file)					{ return Project.Create(file); }
			/// <summary>
			/// Open an existing project file
			/// </summary>
			/// <param name="file">Path to the project file</param>
			/// <returns>Project using data loaded from <paramref name="file"/></returns>
			public BlamLib.CheApe.Project Open(string file)						{ return Project.Open(file); }
			/// <summary>
			/// Save an existing project
			/// </summary>
			/// <param name="save_as">If not null, then it saves the project to this file and updates the project settings</param>
			/// <param name="project">Project object in question</param>
			public void Save(string save_as, BlamLib.CheApe.Project project)	{ Project.Save(save_as, project); }
			/// <summary>
			/// Close an existing project
			/// </summary>
			/// <param name="save">Should we save the project data before closing?</param>
			/// <param name="project">Project object in question</param>
			public void Close(bool save, BlamLib.CheApe.Project project)		{ Project.Close(save, project); }
		};


		/// <summary>
		/// Create a new project file and object
		/// </summary>
		/// <param name="file">Path to the project file</param>
		/// <returns>Read to use Project object</returns>
		private static BlamLib.CheApe.Project Create(string file)
		{
			BlamLib.CheApe.Project proj = new BlamLib.CheApe.Project(BlamVersion.Halo1_CE, file);
			Managers.FileManager fm = new Managers.FileManager(file);
			fm.CreateForWrite();
			fm.Manage(proj);
			fm.Write();
			fm.Close();

			return new ProjectState(proj).Project;
		}

		/// <summary>
		/// Open an existing project file
		/// </summary>
		/// <param name="file">Path to the project file</param>
		/// <returns>Project using data loaded from <paramref name="file"/></returns>
		private static BlamLib.CheApe.Project Open(string file)
		{
			BlamLib.CheApe.Project proj = new BlamLib.CheApe.Project(BlamVersion.Halo1_CE, file);
			Managers.FileManager fm = new Managers.FileManager(file);
			fm.OpenForRead();
			fm.Manage(proj);
			fm.Read();
			fm.Close();

			return new ProjectState(proj).Project;
		}

		/// <summary>
		/// Save an existing project
		/// </summary>
		/// <param name="save_as">If not null, then it saves the project to this file and updates the project settings</param>
		/// <param name="proj">Project object in question</param>
		private static void Save(string save_as, BlamLib.CheApe.Project proj)
		{
			Managers.FileManager fm;

			if(save_as == null)
			{
				fm = new Managers.FileManager(proj.FileName);
				fm.OpenForWrite();
			}
			else
			{
				fm = new Managers.FileManager(proj.FileName = save_as);
				fm.CreateForWrite();
			}

			fm.Manage(proj);
			fm.Write();
			fm.Close();
		}

		/// <summary>
		/// Close an existing project
		/// </summary>
		/// <param name="save">Should we save the project data before closing?</param>
		/// <param name="proj">Project object in question</param>
		private static void Close(bool save, BlamLib.CheApe.Project proj)
		{
			if(save) Save(null, proj);
			proj.Dispose();
		}
		#endregion
	};
}