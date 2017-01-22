
// OpenGLModelView.cpp : ���������� ������ COpenGLModelView
//

//#pragma comment(lib, "opengl32.lib")
//#pragma comment(lib, "glu32.lib")

#include "stdafx.h"
// SHARED_HANDLERS ����� ���������� � ������������ �������� ��������� ���������� ������� ATL, �������
// � ������; ��������� ��������� ������������ ��� ��������� � ������ �������.
#ifndef SHARED_HANDLERS
#include "OpenGLModel.h"
#endif

#include "OpenGLWnd.h"

#ifdef _DEBUG
#define new DEBUG_NEW
#endif

// COpenGLModelView

IMPLEMENT_DYNCREATE(COpenGLWnd, CWnd)

BEGIN_MESSAGE_MAP(COpenGLWnd, CWnd)
	// ����������� ������� ������
	ON_WM_CONTEXTMENU()
	ON_WM_RBUTTONUP()
	ON_WM_LBUTTONDOWN()
	ON_WM_MOUSEMOVE()
	ON_WM_PAINT()
	ON_WM_LBUTTONUP()
END_MESSAGE_MAP()

// ��������/����������� COpenGLModelView

COpenGLWnd::COpenGLWnd()
	: wX(0)
	, wY(0)
	, rX(0)
	, rY(0)
	, rotate(false)
	, m_pScene(NULL)
{
	// TODO: �������� ��� ��������

}

COpenGLWnd::~COpenGLWnd()
{
}

BOOL COpenGLWnd::PreCreateWindow(CREATESTRUCT& cs)
{
	// TODO: �������� ����� Window ��� ����� ����������� ���������
	//  CREATESTRUCT cs

	return CWnd::PreCreateWindow(cs);
}

// ��������� COpenGLModelView

//void COpenGLWnd::OnDraw(CDC* pDC)
//{
//	HGLRC hrc;
//	HDC hdc = pDC->GetSafeHdc();
//	hrc = wglCreateContext(pDC->GetSafeHdc());
//	//DWORD LERR = GetLastError();
//    wglMakeCurrent(pDC->GetSafeHdc(), hrc);
//
//	glClearColor(0.0,0.0,0.0,0);
//	glClear (GL_COLOR_BUFFER_BIT | GL_DEPTH_BUFFER_BIT);
//	
//	glPushMatrix();
//	glRotatef(rX, 0.0, 1.0, 0.0);
//	glRotatef(rY, 1.0, 0.0 ,0.0);
//
//	glColor3f (1.0, 1.0, 1.0);
//	glBegin(GL_TRIANGLES);
//		//glColor3f(1.0,0.0,0.0);
//		glVertex3f(0.0,1.0,0.0);
//
//		//glColor3f(0.0,1.0,0.0);
//		glVertex3f(-1.0,-1.0,1.0);
//
//		//glColor3f(0.0,0.0,1.0);
//		glVertex3f(1.0,-1.0,1.0);
//		//����������� ������ �������
//
//		//glColor3f(1.0,0.0,0.0);
//		glVertex3f(0.0,1.0,0.0);
//
//		//glColor3f(0.0,0.0,1.0);
//		glVertex3f(1.0,-1.0,1.0);
//
//		//glColor3f(0.0,1.0,0.0);
//		glVertex3f(1.0,-1.0,-1.0);
//		//����������� ������ �������
//
//		//glColor3f(1.0,0.0,0.0);
//		glVertex3f(0.0,1.0,0.0);
//
//		//glColor3f(0.0,1.0,0.0);
//		glVertex3f(1.0,-1.0,-1.0);
//
//		//glColor3f(0.0,0.0,1.0);
//		glVertex3f(-1.0,-1.0,-1.0);
//		//����������� ����� �������.
//
//		//glColor3f(1.0,0.0,0.0);
//		glVertex3f(0.0,1.0,0.0);
//
//		//glColor3f(0.0,0.0,1.0);
//		glVertex3f(-1.0,-1.0,-1.0);
//
//		//glColor3f(0.0,1.0,0.0);
//		glVertex3f(-1.0,-1.0,1.0);
//	glEnd();
//
//	glPopMatrix();
//	glFinish();
//
//	wglMakeCurrent(NULL, NULL);
//	wglDeleteContext(hrc);
//}

void COpenGLWnd::OnDraw(CDC* pDC)
{
    wglMakeCurrent(pDC->GetSafeHdc(), hrc);

	CRect rect;
	GetClientRect(&rect);
	reshape(rect.right, rect.bottom);

	display();

	wglMakeCurrent(NULL, NULL);
}


void COpenGLWnd::OnRButtonUp(UINT /* nFlags */, CPoint point)
{
	ClientToScreen(&point);
	OnContextMenu(this, point);
}

void COpenGLWnd::OnContextMenu(CWnd* /* pWnd */, CPoint point)
{
#ifndef SHARED_HANDLERS
	theApp.GetContextMenuManager()->ShowPopupMenu(IDR_POPUP_EDIT, point.x, point.y, this, TRUE);
#endif
}


// ����������� COpenGLModelView

#ifdef _DEBUG
void COpenGLWnd::AssertValid() const
{
	CWnd::AssertValid();
}

void COpenGLWnd::Dump(CDumpContext& dc) const
{
	CWnd::Dump(dc);
}

#endif //_DEBUG


// ����������� ��������� COpenGLModelView


void COpenGLWnd::OnLButtonDown(UINT nFlags, CPoint point)
{
	CWnd::OnLButtonDown(nFlags, point);
	wX = point.x;
	wY = point.y;
	rotate = true;
}


void COpenGLWnd::OnMouseMove(UINT nFlags, CPoint point)
{
	CWnd::OnMouseMove(nFlags, point);
	if (rotate)
	{
       rX = rX + (point.x - wX) / 2;
       rY = rY + (point.y - wY) / 2;
       wX = point.x;
       wY = point.y;
       Invalidate(FALSE);
	}
}


void COpenGLWnd::OnPaint()
{
	CPaintDC dc(this); // device context for painting
	
	OnDraw(&dc);

	// �� �������� CWnd::OnPaint() ��� ��������� ���������
}


// �������������� ������������� �������� ����������
void COpenGLWnd::InitWindow(void)
{
	HDC hdc;

	PIXELFORMATDESCRIPTOR pfd;
    int nPixelFormat;
    memset (&pfd, 0, sizeof (pfd));
	hdc = GetDC()->GetSafeHdc();
    nPixelFormat = ChoosePixelFormat (hdc, &pfd);
    SetPixelFormat (hdc, nPixelFormat, &pfd);

	hrc = wglCreateContext(hdc);
	wglMakeCurrent (hdc, hrc);
	init();
	wglMakeCurrent(NULL,NULL);
}


// ����������� 3D �����
void COpenGLWnd::display(void)
{
	glClearColor(0.0,0.0,0.0,0);
	glClear (GL_COLOR_BUFFER_BIT | GL_DEPTH_BUFFER_BIT);

	glPushMatrix();
	glRotatef(rX, 0.0, 1.0, 0.0);
	glRotatef(rY, 1.0, 0.0 ,0.0);

	glColor3f (1.0, 1.0, 1.0);
	
	if (NULL != m_pScene)
		m_pScene->Draw();


	glPopMatrix();
	glFinish();
}


// ������������� ��������� OpenGL
void COpenGLWnd::init(void)
{
	glEnable(GL_DEPTH_TEST);
    //glEnable (GL_AUTO_NORMAL);
    glEnable (GL_NORMALIZE);


    //// �������� �����
	GLfloat ambient[] = { 0.0, 0.0, 0.0, 1.0 };
    GLfloat diffuse[] = { 1.0, 1.0, 1.0, 1.0 };
    GLfloat position[] = { 0.0, 0.0, -2.0, 0.0 };
    GLfloat lmodel_ambient[] = { 0.4, 0.4, 0.4, 1.0 };
    GLfloat local_view[] = { 0.0 };
    glLightfv(GL_LIGHT0, GL_AMBIENT, ambient);
    glLightfv(GL_LIGHT0, GL_DIFFUSE, diffuse);
    glLightfv(GL_LIGHT0, GL_POSITION, position);
    glLightModelfv(GL_LIGHT_MODEL_AMBIENT, lmodel_ambient);
    glLightModelfv(GL_LIGHT_MODEL_LOCAL_VIEWER, local_view);

    glEnable(GL_LIGHTING);
    glEnable(GL_LIGHT0);


}


// ���������� ��������� ����
void COpenGLWnd::reshape(int w, int h)
{

}


void COpenGLWnd::OnLButtonUp(UINT nFlags, CPoint point)
{
	rotate = false;
	CWnd::OnLButtonUp(nFlags, point);
}
