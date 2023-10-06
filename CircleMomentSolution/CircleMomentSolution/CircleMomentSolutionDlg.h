// CircleMomentSolutionDlg.h : header file
//

#pragma once
#include "afxwin.h"
#include "ballbouncer.h"


// CCircleMomentSolutionDlg dialog
class CCircleMomentSolutionDlg : public CDialog
{
// Construction
public:
	CCircleMomentSolutionDlg(CWnd* pParent = NULL);	// standard constructor

// Dialog Data
	enum { IDD = IDD_CircleMomentSolution_DIALOG };

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
	CBallBouncer m_CircleMake;
	afx_msg void OnBnClickedButton1();
	CButton m_btnStart;
	CEdit m_EditRound;
	CEdit m_EditCnt;
};
