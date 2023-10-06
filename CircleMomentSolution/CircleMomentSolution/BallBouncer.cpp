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
	//원의 반지름(m_CircleRound) 값에 따라 원을 생성하고 색깔을 입히는 부분   by jppark 20231005
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

	//원을 랜덤한 위치에 생성   by jppark 20231005
	x = float(point.x); y = float(point.y);
	vx = float(-4 + rand() % 9); vy = float(-4 + rand() % 9);

	CPen CircleOutSideArea(PS_SOLID, 3, RGB(255, 255, 0)); //원 바깥 테두리 색을 노랑색으로 칠함 by jppark 20231005

	CRect m_rectEllipse;
	m_rectEllipse.SetRect(Round(x) - m_CircleRound, Round(y) - m_CircleRound, Round(x) + m_CircleRound, Round(y) + m_CircleRound);

	CPen *p_old_pen = pDC->SelectObject(&CircleOutSideArea);
	pDC->Ellipse(m_rectEllipse);

	CPen m_Center(PS_SOLID, 3, RGB(255, 0, 0));
	CPen *p_old_pen1 = pDC->SelectObject(&m_Center); //원 안쪽 무게중심을 구한 위치에서 Cross 라인 빨강색 으로 칠함 by jppark 20231005

	CPoint m_Center1 = m_rectEllipse.CenterPoint(); //원 안쪽 무게중심을 구함 by jppark 20231005

	//원 안쪽 무게중심 에서 X좌표 방향으로 라인 을 그림 by jppark 20231005
	pDC->MoveTo(m_Center1.x, m_Center1.y);
	pDC->LineTo(m_rectEllipse.left, (m_rectEllipse.top + m_rectEllipse.bottom)/2);
	pDC->MoveTo(m_Center1.x, m_Center1.y);
	pDC->LineTo(m_rectEllipse.right, (m_rectEllipse.top + m_rectEllipse.bottom) / 2);

	//원 안쪽 무게중심 에서 Y좌표 방향으로 라인 을 그림 by jppark 20231005
	pDC->MoveTo(m_Center1.x, m_Center1.y);
	pDC->LineTo((m_rectEllipse.left + m_rectEllipse.right) / 2 , m_rectEllipse.top);
	pDC->MoveTo(m_Center1.x, m_Center1.y);
	pDC->LineTo((m_rectEllipse.left + m_rectEllipse.right) / 2, m_rectEllipse.bottom);
	pDC->SelectObject(m_rectEllipse);
	
	Invalidate();
}