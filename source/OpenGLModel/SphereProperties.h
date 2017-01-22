#pragma once


// CSphereProperties dialog

class CSphereProperties : public CDialog
{
	DECLARE_DYNAMIC(CSphereProperties)

public:
	CSphereProperties(CWnd* pParent = NULL);   // standard constructor
	virtual ~CSphereProperties();

// Dialog Data
	enum { IDD = IDD_SPHEREPROPERTIES };

protected:
	virtual void DoDataExchange(CDataExchange* pDX);    // DDX/DDV support

	DECLARE_MESSAGE_MAP()
public:

	// Имя объекта
	CString m_name;
	// смещение по оси oX
	double m_x;
	// смещение по оси oY
	double m_y;
	// смещение по оси oZ
	double m_z;
	// радиус шара
	double m_r;
	// количество делений вокруг оси Z (эквивалентно количеству линий долготы)
	int m_slices;
	// количество делений вдоль оси Z (эквивалентно количеству линий широты)
	int m_stacks;
	afx_msg void OnBnClickedOk();
	virtual BOOL OnInitDialog();
	// цвет шара
	DWORD m_color;
	// Установить цвет
	void SetColor(DWORD color);
	afx_msg void OnPaint();
	afx_msg void OnBnClickedButtonColor();
};
