
// Teilchen_01.h: Hauptheaderdatei f�r die PROJECT_NAME-Anwendung
//

#pragma once

#ifndef __AFXWIN_H__
	#error "'stdafx.h' vor dieser Datei f�r PCH einschlie�en"
#endif

#include "resource.h"		// Hauptsymbole


// CTeilchen_01App:
// Siehe Teilchen_01.cpp f�r die Implementierung dieser Klasse
//

class CTeilchen_01App : public CWinApp
{
public:
	CTeilchen_01App();

// �berschreibungen
public:
	virtual BOOL InitInstance();

// Implementierung

	DECLARE_MESSAGE_MAP()
};

extern CTeilchen_01App theApp;