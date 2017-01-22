#pragma once

// ��������� ���������������
// ���������� ���� CBoxProperties

class CBoxProperties : public CDialog
{
	DECLARE_DYNAMIC(CBoxProperties)

public:
	CBoxProperties(CWnd* pParent = NULL);   // ����������� �����������
	virtual ~CBoxProperties();

// ������ ����������� ����
	enum { IDD = IDD_BOXPROPERTIES };

protected:
	virtual void DoDataExchange(CDataExchange* pDX);    // ��������� DDX/DDV

	DECLARE_MESSAGE_MAP()
public:
	// �������� �� x
	double m_x;
	// �������� �� y
	double m_y;
	// �������� �� z
	double m_z;
	// ������� ������������ oX
	double m_rx;
	// ������� ������������ oY
	double m_ry;
	// ������� ������������ oZ
	double m_rz;
	// �������� a
	double m_a;
	// �������� b
	double m_b;
	// �������� c
	double m_c;
	afx_msg void OnBnClickedOk();
	virtual BOOL OnInitDialog();
	// ������������ �������
	CString m_name;
	// ���������� ��������� ����������� ����
	void SetTtitle(CString tittle);
	CString m_title;
	// ���������� ����
	void SetColor(DWORD color);
	DWORD m_color;
	afx_msg void OnPaint();
	afx_msg void OnBnClickedButtonColor();
};
