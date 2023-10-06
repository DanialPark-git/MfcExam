#pragma once


// CBallBouncer

class CBallBouncer : public CStatic
{
	DECLARE_DYNAMIC(CBallBouncer)

public:
	CBallBouncer();
	virtual ~CBallBouncer();

public :
	float x, y;
	float vx, vy;

public:
	void Start(int m_CircleRound);
private:
	void RadialGradientFill(CDC* pDC, CRect lpRectBounds, COLORREF cr1, COLORREF cr2, int m_CircleRound);

protected:
	DECLARE_MESSAGE_MAP()
protected:
	afx_msg void OnPaint();
	afx_msg void OnTimer(UINT_PTR nIDEvent);

	virtual void OnDraw(LPDRAWITEMSTRUCT lpDraw);
	virtual void PreSubclassWindow();
};


