// BallBouncer.cpp : implementation file
//

#include "stdafx.h"
#include "CircleMomentSolution.h"
#include "BallBouncer.h"
#include "BufferDC.h"

// CBallBouncer

IMPLEMENT_DYNAMIC(CBallBouncer, CStatic)

int Round(float x)
{
	float xx = fabs(x);
	float r = xx - int(xx);
	if (r >= 0.5)
		xx++;
	return x > 0 ? int(xx) : -(int)xx;
}

CBallBouncer::CBallBouncer()
{
}

CBallBouncer::~CBallBouncer()
{
}


BEGIN_MESSAGE_MAP(CBallBouncer, CStatic)
	ON_WM_PAINT()
	ON_WM_TIMER()
END_MESSAGE_MAP()

void CBallBouncer::Start(int m_CircleRound)
{
	CPaintDC dc(this);

	CRect rc = { 0 };
	GetClientRect(&rc);

	CRect gRc = rc;
	//���� ������(m_CircleRound) ���� ���� ���� �����ϰ� ������ ������ �κ�   by jppark 20231005
	RadialGradientFill(&dc, &gRc, RGB(255, 255, 0), ::GetSysColor(COLOR_BTNFACE), m_CircleRound); 
}

afx_msg void CBallBouncer::OnPaint()
{
}

afx_msg void CBallBouncer::OnTimer( UINT_PTR nIDEvent )
{
}

void CBallBouncer::OnDraw( LPDRAWITEMSTRUCT lpDraw )
{

}

void CBallBouncer::PreSubclassWindow()
{
	ModifyStyle(0, BS_OWNERDRAW | SS_NOTIFY);
}

void CBallBouncer::RadialGradientFill( CDC* pDC, CRect lpRectBounds, COLORREF cr1, COLORREF cr2, int m_CircleRound)
{
	CPoint point(m_CircleRound + rand() % (lpRectBounds.Width() - 2 * m_CircleRound), m_CircleRound + rand() % (lpRectBounds.Height() - 2 * m_CircleRound));

	//���� ������ ��ġ�� ����   by jppark 20231005
	x = float(point.x); y = float(point.y);
	vx = float(-4 + rand() % 9); vy = float(-4 + rand() % 9);

	CPen CircleOutSideArea(PS_SOLID, 3, RGB(255, 255, 0)); //�� �ٱ� �׵θ� ���� ��������� ĥ�� by jppark 20231005

	CRect m_rectEllipse;
	m_rectEllipse.SetRect(Round(x) - m_CircleRound, Round(y) - m_CircleRound, Round(x) + m_CircleRound, Round(y) + m_CircleRound);

	CPen *p_old_pen = pDC->SelectObject(&CircleOutSideArea);
	pDC->Ellipse(m_rectEllipse);

	CPen m_Center(PS_SOLID, 3, RGB(255, 0, 0));
	CPen *p_old_pen1 = pDC->SelectObject(&m_Center); //�� ���� �����߽��� ���� ��ġ���� Cross ���� ������ ���� ĥ�� by jppark 20231005

	CPoint m_Center1 = m_rectEllipse.CenterPoint(); //�� ���� �����߽��� ���� by jppark 20231005

	//�� ���� �����߽� ���� X��ǥ �������� ���� �� �׸� by jppark 20231005
	pDC->MoveTo(m_Center1.x, m_Center1.y);
	pDC->LineTo(m_rectEllipse.left, (m_rectEllipse.top + m_rectEllipse.bottom)/2);
	pDC->MoveTo(m_Center1.x, m_Center1.y);
	pDC->LineTo(m_rectEllipse.right, (m_rectEllipse.top + m_rectEllipse.bottom) / 2);

	//�� ���� �����߽� ���� Y��ǥ �������� ���� �� �׸� by jppark 20231005
	pDC->MoveTo(m_Center1.x, m_Center1.y);
	pDC->LineTo((m_rectEllipse.left + m_rectEllipse.right) / 2 , m_rectEllipse.top);
	pDC->MoveTo(m_Center1.x, m_Center1.y);
	pDC->LineTo((m_rectEllipse.left + m_rectEllipse.right) / 2, m_rectEllipse.bottom);
	pDC->SelectObject(m_rectEllipse);
	
	Invalidate();
}