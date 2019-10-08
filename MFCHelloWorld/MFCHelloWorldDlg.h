
// MFCHelloWorldDlg.h : header file
//

#pragma once


// CMFCHelloWorldDlg dialog
class CMFCHelloWorldDlg : public CDialogEx
{
// Construction
public:
	CMFCHelloWorldDlg(CWnd* pParent = nullptr);	// standard constructor

// Dialog Data
#ifdef AFX_DESIGN_TIME
	enum { IDD = IDD_MFCHELLOWORLD_DIALOG };
#endif

	protected:
	virtual void DoDataExchange(CDataExchange* pDX);	// DDX/DDV support


// Implementation
protected:
	HICON m_hIcon;

	// Generated message map functions
	virtual BOOL OnInitDialog();
	afx_msg void OnSysCommand(UINT nID, LPARAM lParam);
	afx_msg void OnPaint();
	afx_msg HCURSOR OnQueryDragIcon();
	DECLARE_MESSAGE_MAP()
public:
	afx_msg void OnBnClickedCalculatorButton(UINT nID);
	CStatic m_result;
};
