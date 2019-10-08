
// MFCHelloWorldDlg.cpp : implementation file
//

#include "pch.h"
#include "framework.h"
#include "MFCHelloWorld.h"
#include "MFCHelloWorldDlg.h"
#include "afxdialogex.h"
#include <string>

#ifdef _DEBUG
#define new DEBUG_NEW
#endif

// CAboutDlg dialog used for App About

class CAboutDlg : public CDialogEx
{
public:
	CAboutDlg();

// Dialog Data
#ifdef AFX_DESIGN_TIME
	enum { IDD = IDD_ABOUTBOX };
#endif

	protected:
	virtual void DoDataExchange(CDataExchange* pDX);    // DDX/DDV support

// Implementation
protected:
	DECLARE_MESSAGE_MAP()
};

CAboutDlg::CAboutDlg() : CDialogEx(IDD_ABOUTBOX)
{
}

void CAboutDlg::DoDataExchange(CDataExchange* pDX)
{
	CDialogEx::DoDataExchange(pDX);
}

BEGIN_MESSAGE_MAP(CAboutDlg, CDialogEx)
END_MESSAGE_MAP()


// CMFCHelloWorldDlg dialog



CMFCHelloWorldDlg::CMFCHelloWorldDlg(CWnd* pParent /*=nullptr*/)
	: CDialogEx(IDD_MFCHELLOWORLD_DIALOG, pParent)
{
	m_hIcon = AfxGetApp()->LoadIcon(IDR_MAINFRAME);
}

void CMFCHelloWorldDlg::DoDataExchange(CDataExchange* pDX)
{
	CDialogEx::DoDataExchange(pDX);
	DDX_Control(pDX, ID_STATIC_RESULT, m_result);
}

BEGIN_MESSAGE_MAP(CMFCHelloWorldDlg, CDialogEx)
	ON_WM_SYSCOMMAND()
	ON_WM_PAINT()
	ON_WM_QUERYDRAGICON()
	ON_COMMAND_RANGE(ID_BUTTON_0, ID_BUTTON_9, &CMFCHelloWorldDlg::OnBnClickedCalculatorButton)
END_MESSAGE_MAP()


// CMFCHelloWorldDlg message handlers

BOOL CMFCHelloWorldDlg::OnInitDialog()
{
	CDialogEx::OnInitDialog();

	// Add "About..." menu item to system menu.

	// IDM_ABOUTBOX must be in the system command range.
	ASSERT((IDM_ABOUTBOX & 0xFFF0) == IDM_ABOUTBOX);
	ASSERT(IDM_ABOUTBOX < 0xF000);

	CMenu* pSysMenu = GetSystemMenu(FALSE);
	if (pSysMenu != nullptr)
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

	// Set the icon for this dialog.  The framework does this automatically
	//  when the application's main window is not a dialog
	SetIcon(m_hIcon, TRUE);			// Set big icon
	SetIcon(m_hIcon, FALSE);		// Set small icon

	// TODO: Add extra initialization here

	return TRUE;  // return TRUE  unless you set the focus to a control
}

void CMFCHelloWorldDlg::OnSysCommand(UINT nID, LPARAM lParam)
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

// If you add a minimize button to your dialog, you will need the code below
//  to draw the icon.  For MFC applications using the document/view model,
//  this is automatically done for you by the framework.

void CMFCHelloWorldDlg::OnPaint()
{
	if (IsIconic())
	{
		CPaintDC dc(this); // device context for painting

		SendMessage(WM_ICONERASEBKGND, reinterpret_cast<WPARAM>(dc.GetSafeHdc()), 0);

		// Center icon in client rectangle
		int cxIcon = GetSystemMetrics(SM_CXICON);
		int cyIcon = GetSystemMetrics(SM_CYICON);
		CRect rect;
		GetClientRect(&rect);
		int x = (rect.Width() - cxIcon + 1) / 2;
		int y = (rect.Height() - cyIcon + 1) / 2;

		// Draw the icon
		dc.DrawIcon(x, y, m_hIcon);
	}
	else
	{
		CDialogEx::OnPaint();
	}
}

// The system calls this function to obtain the cursor to display while the user drags
//  the minimized window.
HCURSOR CMFCHelloWorldDlg::OnQueryDragIcon()
{
	return static_cast<HCURSOR>(m_hIcon);
}

int ButtonIdToInt(UINT nID) {
	switch (nID) {
	case ID_BUTTON_0: return 0;
	case ID_BUTTON_1: return 1;
	case ID_BUTTON_2: return 2;
	case ID_BUTTON_3: return 3;
	case ID_BUTTON_4: return 4;
	case ID_BUTTON_5: return 5;
	case ID_BUTTON_6: return 6;
	case ID_BUTTON_7: return 7;
	case ID_BUTTON_8: return 8;
	case ID_BUTTON_9: return 9;
	default: return 0;
	}
}

void CMFCHelloWorldDlg::OnBnClickedCalculatorButton(UINT nID)
{
	int val = ButtonIdToInt(nID);
	CString str;
	str.Format(L"%d", val);
	m_result.SetWindowTextW(str);
}