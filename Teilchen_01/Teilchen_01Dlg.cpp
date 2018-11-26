
// Teilchen_01Dlg.cpp: Implementierungsdatei
//

#include "stdafx.h"
#include "Teilchen_01.h"
#include "Teilchen_01Dlg.h"
#include "afxdialogex.h"
#include "stdafx.h"
#include "math.h"
#include "stdafx.h"

#define PI = 3.14
#define SIG_PHI = 5.0 * (PI/180)

#ifdef _DEBUG
#define new DEBUG_NEW
#endif


// CAboutDlg-Dialogfeld f�r Anwendungsbefehl "Info"

class CAboutDlg : public CDialogEx
{
public:
	CAboutDlg();

// Dialogfelddaten
	enum { IDD = IDD_ABOUTBOX };

	protected:
	virtual void DoDataExchange(CDataExchange* pDX);    // DDX/DDV-Unterst�tzung

// Implementierung
protected:
	DECLARE_MESSAGE_MAP()
};

CAboutDlg::CAboutDlg() : CDialogEx(CAboutDlg::IDD)
{
}

void CAboutDlg::DoDataExchange(CDataExchange* pDX)
{
	CDialogEx::DoDataExchange(pDX);
}

BEGIN_MESSAGE_MAP(CAboutDlg, CDialogEx)
END_MESSAGE_MAP()


// CTeilchen_01Dlg-Dialogfeld




CTeilchen_01Dlg::CTeilchen_01Dlg(CWnd* pParent /*=NULL*/)
	: CDialogEx(CTeilchen_01Dlg::IDD, pParent)
{
	m_hIcon = AfxGetApp()->LoadIcon(IDR_MAINFRAME);
}

void CTeilchen_01Dlg::DoDataExchange(CDataExchange* pDX)
{
	CDialogEx::DoDataExchange(pDX);
}

BEGIN_MESSAGE_MAP(CTeilchen_01Dlg, CDialogEx)
	ON_WM_SYSCOMMAND()
	ON_WM_PAINT()
	ON_WM_QUERYDRAGICON()
  ON_BN_CLICKED(IDOK, &CTeilchen_01Dlg::OnBnClickedOk)
END_MESSAGE_MAP()


// CTeilchen_01Dlg-Meldungshandler

BOOL CTeilchen_01Dlg::OnInitDialog()
{
	CDialogEx::OnInitDialog();

	// Hinzuf�gen des Men�befehls "Info..." zum Systemmen�.

	// IDM_ABOUTBOX muss sich im Bereich der Systembefehle befinden.
	ASSERT((IDM_ABOUTBOX & 0xFFF0) == IDM_ABOUTBOX);
	ASSERT(IDM_ABOUTBOX < 0xF000);

	CMenu* pSysMenu = GetSystemMenu(FALSE);
	if (pSysMenu != NULL)
	{
		BOOL bNameValid;
		CString strAboutMenu;
		bNameValid = strAboutMenu.LoadString(IDS_ABOUTBOX);
		ASSERT(bNameValid);
		if (!strAboutMenu.IsEmpty())
		{
			pSysMenu->AppendMenu(MF_SEPARATOR);
			pSysMenu->AppendMenu(MF_STRING, IDM_ABOUTBOX, strAboutMenu);
		}
	}

	// Symbol f�r dieses Dialogfeld festlegen. Wird automatisch erledigt
	//  wenn das Hauptfenster der Anwendung kein Dialogfeld ist
	SetIcon(m_hIcon, TRUE);			// Gro�es Symbol verwenden
	SetIcon(m_hIcon, FALSE);		// Kleines Symbol verwenden

	// TODO: Hier zus�tzliche Initialisierung einf�gen

	return TRUE;  // TRUE zur�ckgeben, wenn der Fokus nicht auf ein Steuerelement gesetzt wird
}

void CTeilchen_01Dlg::OnSysCommand(UINT nID, LPARAM lParam)
{
	if ((nID & 0xFFF0) == IDM_ABOUTBOX)
	{
		CAboutDlg dlgAbout;
		dlgAbout.DoModal();
	}
	else
	{
		CDialogEx::OnSysCommand(nID, lParam);
	}
}

// Wenn Sie dem Dialogfeld eine Schaltfl�che "Minimieren" hinzuf�gen, ben�tigen Sie
//  den nachstehenden Code, um das Symbol zu zeichnen. F�r MFC-Anwendungen, die das 
//  Dokument/Ansicht-Modell verwenden, wird dies automatisch ausgef�hrt.

void CTeilchen_01Dlg::OnPaint()
{
	if (IsIconic())
	{
		CPaintDC dc(this); // Ger�tekontext zum Zeichnen

		SendMessage(WM_ICONERASEBKGND, reinterpret_cast<WPARAM>(dc.GetSafeHdc()), 0);

		// Symbol in Clientrechteck zentrieren
		int cxIcon = GetSystemMetrics(SM_CXICON);
		int cyIcon = GetSystemMetrics(SM_CYICON);
		CRect rect;
		GetClientRect(&rect);
		int x = (rect.Width() - cxIcon + 1) / 2;
		int y = (rect.Height() - cyIcon + 1) / 2;

		// Symbol zeichnen
		dc.DrawIcon(x, y, m_hIcon);
	}
	else
	{
		CDialogEx::OnPaint();
	}
}

// Die System ruft diese Funktion auf, um den Cursor abzufragen, der angezeigt wird, w�hrend der Benutzer
//  das minimierte Fenster mit der Maus zieht.
HCURSOR CTeilchen_01Dlg::OnQueryDragIcon()
{
	return static_cast<HCURSOR>(m_hIcon);
}



void CTeilchen_01Dlg::OnBnClickedOk()
{
  // TODO: F�gen Sie hier Ihren Kontrollbehandlungscode f�r die Benachrichtigung ein.
  //CDialogEx::OnOK();

  CClientDC dc(this);       // Funktionen f�r Zeichenfunktion
  CRect rect;
  GetClientRect(&rect);


  { 
	// main()
    int xmitte = 0;					// Startwert x-Achse
	int ymitte = rect.Height() / 2;	// Startwert y-Achse
	float l = rect.Width() / 100.0;	// L�nge pro Schritt

	dc.Rectangle(0, 0, rect.Width(), rect.Height());	// Rahmen zeichen

	for(int i=1; i <= 10; i++)		// Wiederholung f�r 10 simulationen
	{
		int x = xmitte;				// Pointer x-Achse
		int y = ymitte;				// " "	y-Achse
		float phi = 0.0;			// Verschiebungswinkel

		dc.MoveTo(x, y);			// Pointer auf Startposition

		for ( int c=1; c <= 100; c++) // Wiederholung f�r 100 Schritte
		{
			float sum = 0.0;		// Summer der Zufallszahlen

			for ( int v=1; v <= 12; v++)	// Addition von 12 Zufallszahlen (0 bis 1)
			{
				sum = sum + rand()/(float)RAND_MAX;
			}
	
			phi = phi + 5.0 * ( 3.14 /180) * (sum - 6 );	// Berechnung neuer Winkel

			x = x + l * cos(phi);	// Berechnung neuer Koordinaten x-Achse
			y = y + l * sin(phi);	// Berechnung neuer Koordinaten y-Achse

			dc.LineTo(x, y);		// Linie zechnen
			Sleep(1);				// Pause nach simulationsschritt f�r 1ms
		}
		Sleep(100);					// Pause nach vollst�ndig simuliertes Teilchen f�r 100ms
	}
    //return 0
  }




}
