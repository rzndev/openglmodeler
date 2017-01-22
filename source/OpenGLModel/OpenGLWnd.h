
// OpenGLModelView.h : интерфейс класса COpenGLModelView
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

// Атрибуты
public:

// Операции
public:

// Переопределение
public:
	void OnDraw(CDC* pDC);  // определено для отрисовки этого окна
	virtual BOOL PreCreateWindow(CREATESTRUCT& cs);
protected:

// Реализация
public:
	virtual ~COpenGLWnd();
#ifdef _DEBUG
	virtual void AssertValid() const;
	virtual void Dump(CDumpContext& dc) const;
#endif

protected:

// Созданные функции схемы сообщений
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
	// контекст opengl
	HGLRC hrc; 
	afx_msg void OnPaint();
	// Первоначальная инициализация элемента управления
	void InitWindow(void);
	// указатель на модель сцены
	C3DScene* m_pScene;
	// Отображение 3D сцены
	void display(void);
	// инициализация контекста OpenGL
	void init(void);
	// установить параметры окна
	void reshape(int w, int h);
	afx_msg void OnLButtonUp(UINT nFlags, CPoint point);
};


