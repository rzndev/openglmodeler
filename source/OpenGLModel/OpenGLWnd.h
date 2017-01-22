
// OpenGLModelView.h : ��������� ������ COpenGLModelView
//

#pragma once

#include <gl/GL.h>
#include <gl/GLU.h>

#include "C3DScene.h"

class COpenGLWnd : public CWnd
{
public: 
	COpenGLWnd();
	DECLARE_DYNCREATE(COpenGLWnd)

// ��������
public:

// ��������
public:

// ���������������
public:
	void OnDraw(CDC* pDC);  // ���������� ��� ��������� ����� ����
	virtual BOOL PreCreateWindow(CREATESTRUCT& cs);
protected:

// ����������
public:
	virtual ~COpenGLWnd();
#ifdef _DEBUG
	virtual void AssertValid() const;
	virtual void Dump(CDumpContext& dc) const;
#endif

protected:

// ��������� ������� ����� ���������
protected:
	afx_msg void OnFilePrintPreview();
	afx_msg void OnRButtonUp(UINT nFlags, CPoint point);
	afx_msg void OnContextMenu(CWnd* pWnd, CPoint point);
	DECLARE_MESSAGE_MAP()
public:
	afx_msg void OnLButtonDown(UINT nFlags, CPoint point);
	afx_msg void OnMouseMove(UINT nFlags, CPoint point);
	GLfloat wX;
	GLfloat wY;
	GLfloat rX;
	GLfloat rY;
	bool rotate;
	// �������� opengl
	HGLRC hrc; 
	afx_msg void OnPaint();
	// �������������� ������������� �������� ����������
	void InitWindow(void);
	// ��������� �� ������ �����
	C3DScene* m_pScene;
	// ����������� 3D �����
	void display(void);
	// ������������� ��������� OpenGL
	void init(void);
	// ���������� ��������� ����
	void reshape(int w, int h);
	afx_msg void OnLButtonUp(UINT nFlags, CPoint point);
};


