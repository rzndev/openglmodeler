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

	// ��� �������
	CString m_name;
	// �������� �� ��� oX
	double m_x;
	// �������� �� ��� oY
	double m_y;
	// �������� �� ��� oZ
	double m_z;
	// ������ ����
	double m_r;
	// ���������� ������� ������ ��� Z (������������ ���������� ����� �������)
	int m_slices;
	// ���������� ������� ����� ��� Z (������������ ���������� ����� ������)
	int m_stacks;
	afx_msg void OnBnClickedOk();
	virtual BOOL OnInitDialog();
	// ���� ����
	DWORD m_color;
	// ���������� ����
	void SetColor(DWORD color);
	afx_msg void OnPaint();
	afx_msg void OnBnClickedButtonColor();
};
