#pragma once

#include "OpenGLWnd.h"


// представление формы CUserGui

class CUserGui : public CFormView
{
	DECLARE_DYNCREATE(CUserGui)

public:
	CUserGui();           // конструктор, используемый при динамическом создании
protected:
	virtual ~CUserGui();

public:
	enum { IDD = IDD_USERGUI };
#ifdef _DEBUG
	virtual void AssertValid() const;
#ifndef _WIN32_WCE
	virtual void Dump(CDumpContext& dc) const;
#endif
#endif

protected:
	virtual void DoDataExchange(CDataExchange* pDX);    // поддержка DDX/DDV

	DECLARE_MESSAGE_MAP()
public:
	afx_msg void OnBnClickedButtonParal();
	afx_msg void OnBnClickedButtonPyramid();
	afx_msg void OnBnClickedButtonSphere();
	afx_msg void OnBnClickedButtonRemove();
	afx_msg void OnBnClickedButtonModify();
	afx_msg void OnBnClickedButtonViewFront();
	afx_msg void OnBnClickedButtonViewBack();
	afx_msg void OnBnClickedButtonViewLeft();
	afx_msg void OnBnClickedButtonRight();
	afx_msg void OnBnClickedButtonViewTop();
	afx_msg void OnBnClickedButtonViewBottom();
	virtual void OnInitialUpdate();
	COpenGLWnd m_opengl;
	afx_msg void OnDestroy();
	// Отобразить свойства объекта, выделенного в списке
	void ShowPropertiesCurrentObject(void);
	afx_msg void OnSelchangeList1();
};


