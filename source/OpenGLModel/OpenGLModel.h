
// OpenGLModel.h : главный файл заголовка для приложения OpenGLModel
//
#pragma once

#ifndef __AFXWIN_H__
	#error "включить stdafx.h до включения этого файла в PCH"
#endif

#include "resource.h"       // основные символы


// COpenGLModelApp:
// О реализации данного класса см. OpenGLModel.cpp
//

class COpenGLModelApp : public CWinAppEx
{
public:
	COpenGLModelApp();


// Переопределение
public:
	virtual BOOL InitInstance();
	virtual int ExitInstance();

// Реализация
	UINT  m_nAppLook;
	BOOL  m_bHiColorIcons;

	virtual void PreLoadState();
	virtual void LoadCustomState();
	virtual void SaveCustomState();

	afx_msg void OnAppAbout();
	DECLARE_MESSAGE_MAP()
};

extern COpenGLModelApp theApp;
