#pragma once

// параметры параллелепипеда
// диалоговое окно CBoxProperties

class CBoxProperties : public CDialog
{
	DECLARE_DYNAMIC(CBoxProperties)

public:
	CBoxProperties(CWnd* pParent = NULL);   // стандартный конструктор
	virtual ~CBoxProperties();

// Данные диалогового окна
	enum { IDD = IDD_BOXPROPERTIES };

protected:
	virtual void DoDataExchange(CDataExchange* pDX);    // поддержка DDX/DDV

	DECLARE_MESSAGE_MAP()
public:
	// Смещение по x
	double m_x;
	// смещение по y
	double m_y;
	// смещение по z
	double m_z;
	// поворот относительно oX
	double m_rx;
	// поворот относительно oY
	double m_ry;
	// поворот относительно oZ
	double m_rz;
	// параметр a
	double m_a;
	// параметр b
	double m_b;
	// параметр c
	double m_c;
	afx_msg void OnBnClickedOk();
	virtual BOOL OnInitDialog();
	// наименование объекта
	CString m_name;
	// Установить заголовок диалогового окна
	void SetTtitle(CString tittle);
	CString m_title;
	// Установить цвет
	void SetColor(DWORD color);
	DWORD m_color;
	afx_msg void OnPaint();
	afx_msg void OnBnClickedButtonColor();
};
