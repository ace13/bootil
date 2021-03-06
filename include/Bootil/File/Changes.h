#pragma once

#include "Bootil/Bootil.h"

namespace Bootil 
{
	namespace File 
	{
		/*

		- Declare

		ChangeMonitor mychangemonitor;


		- Set up

		mychangemonitor.WatchFolder( "blah/blah/", true );
	

		- In a loop somewhere safe

		if ( mychangemonitor.HasChanges() )
		{
			BString strFileChanged = GetChange();

			- do something here about strFileChanged being changed
		}

		*/

		class BOOTIL_EXPORT ChangeMonitor
		{
			public:

				ChangeMonitor();
				~ChangeMonitor();

				bool WatchFolder( const BString& strFolder, bool bWatchSubtree = false );
				void Stop();

				bool HasChanges();
				BString GetChange();

				const BString& FolderName(){ return m_strFolderName; }

			private:

				void NoteFileChanged( const BString& strName );
				void CheckForChanges();
				void StartWatch();
				
				void*				m_pData;
				char				m_Buffer[1024];
				void* 				m_dirHandle;
				BString				m_strFolderName;
				std::list<BString>	m_Changes;
				bool				m_bWatchSubtree;
			};
	}
}