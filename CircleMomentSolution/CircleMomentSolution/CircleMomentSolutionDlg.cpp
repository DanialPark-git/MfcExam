// CircleMomentSolutionDlg.cpp : implementation file
//

#include "stdafx.h"
#include "CircleMomentSolution.h"
#include "CircleMomentSolutionDlg.h"

#ifdef _DEBUG
#define new DEBUG_NEW
#endif


// CAboutDlg dialog used for App About

class CAboutDlg : public CDialog
{
public:
	CAboutDlg();

// Dialog Data
	enum { IDD = IDD_ABOUTBOX };

	protected:
	virtual void DoDataExchange(CDataExchange* pDX);    // DDX/DDV support

// Implementation
protected:
	DECLARE_MESSAGE_MAP()
};

CAboutDlg::CAboutDlg() : CDialog(CAboutDlg::IDD)
{
}

void CAboutDlg::DoDataExchange(CDataExchange* pDX)
{
	CDialog::DoDataExchange(pDX);
}

BEGIN_MESSAGE_MAP(CAboutDlg, CDialog)
END_MESSAGE_MAP()


// CCircleMomentSolutionDlg dialog




CCircleMomentSolutionDlg::CCircleMomentSolutionDlg(CWnd* pParent /*=NULL*/)
	: CDialog(CCircleMomentSolutionDlg::IDD, pParent)
{
	m_hIcon = AfxGetApp()->LoadIcon(IDR_MAINFRAME);
}

void CCircleMomentSolutionDlg::DoDataExchange(CDataExchange* pDX)
{
	CDialog::DoDataExchange(pDX);
	DDX_Control(pDX, IDC_BOUNCER1, m_CircleMake);
	DDX_Control(pDX, IDC_BUTTON1, m_btnStart);
	DDX_Control(pDX, IDC_EDIT_CIRCLE_ROUND, m_EditRound);
	DDX_Control(pDX, IDC_EDIT_CELL_CNT, m_EditCnt);
}

BEGIN_MESSAGE_MAP(CCircleMomentSolutionDlg, CDialog)
	ON_WM_SYSCOMMAND()
	ON_WM_PAINT()
	ON_WM_QUERYDRAGICON()
	//}}AFX_MSG_MAP
	ON_BN_CLICKED(IDC_BUTTON1, &CCircleMomentSolutionDlg::OnBnClickedButton1)
END_MESSAGE_MAP()


// CCircleMomentSolutionDlg message handlers

BOOL CCircleMomentSolutionDlg::OnInitDialog()
{
	CDialog::OnInitDialog();

	//원 반지름 기본값("5"), 원 개수 기본값("10")으로 설정 by jppark 20231005
	GetDlgItem(IDC_EDIT_CIRCLE_ROUND)->SetWindowText(_T("5"));
	GetDlgItem(IDC_EDIT_CELL_CNT)->SetWindowText(_T("10"));

	GetDlgItem(IDC_EDIT_CIRCLE_ROUND)->SetFocus();
	GetDlgItem(IDC_EDIT_CELL_CNT)->SetFocus();

	// IDM_ABOUTBOX must be in the system command range.
	ASSERT((IDM_ABOUTBOX & 0xFFF0) == IDM_ABOUTBOX);
	ASSERT(IDM_ABOUTBOX < 0xF000);

	CMenu* pSysMenu = GetSystemMenu(FALSE);
	if (pSysMenu != NULL)
	{
		CString strAboutMenu;
		strAboutMenu.LoadString(IDS_ABOUTBOX);
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

	return TRUE;  // return TRUE  unless you set the focus to a control
}

void CCircleMomentSolutionDlg::OnSysCommand(UINT nID, LPARAM lParam)
{
	if ((nID & 0xFFF0) == IDM_ABOUTBOX)
	{
		CAboutDlg dlgAbout;
		dlgAbout.DoModal();
	}
	else
	{
		CDialog::OnSysCommand(nID, lParam);
	}
}

// If you add a minimize button to your dialog, you will need the code below
//  to draw the icon.  For MFC applications using the document/view model,
//  this is automatically done for you by the framework.

void CCircleMomentSolutionDlg::OnPaint()
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
		CDialog::OnPaint();
	}
}

// The system calls this function to obtain the cursor to display while the user drags
//  the minimized window.
HCURSOR CCircleMomentSolutionDlg::OnQueryDragIcon()
{
	return static_cast<HCURSOR>(m_hIcon);
}


void CCircleMomentSolutionDlg::OnBnClickedButton1()
{
	CString m_CircleRound = _T("");
	m_EditRound.GetWindowTextW(m_CircleRound); //원을 생성하기 위한 반지름 값을 EditBox 에서 값을 가져옴  by jppark 20231005

	CString m_CircleCnt = _T("");
	m_EditCnt.GetWindowTextW(m_CircleCnt); //원의 개수를 생성하기 위한 값을 EditBox 에서 값을 가져옴  by jppark 20231005

	int m_Rnd = _ttoi(m_CircleRound);
	int m_Cnt = _ttoi(m_CircleCnt);

	for (int i = 0; i < m_Cnt; i++) //원을 생성할 개수 만큼 반복 실행  by jppark 20231005
	{
		m_CircleMake.Start(m_Rnd);
	}
}
