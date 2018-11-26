
// Teilchen_01.h: Hauptheaderdatei für die PROJECT_NAME-Anwendung
//

#pragma once

#ifndef __AFXWIN_H__
	#error "'stdafx.h' vor dieser Datei für PCH einschließen"
#endif

#include "resource.h"		// Hauptsymbole


// CTeilchen_01App:
// Siehe Teilchen_01.cpp für die Implementierung dieser Klasse
//

class CTeilchen_01App : public CWinApp
{
public:
	CTeilchen_01App();

// Überschreibungen
public:
	virtual BOOL InitInstance();

// Implementierung

	DECLARE_MESSAGE_MAP()
};

extern CTeilchen_01App theApp;