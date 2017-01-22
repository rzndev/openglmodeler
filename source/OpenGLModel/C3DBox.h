#pragma once
#include "c3ditem.h"
class C3DBox :
	public C3DItem
{
public:
	C3DBox(void);
	virtual ~C3DBox(void);

	// ���������� ������ �� �����
	virtual void Draw(void);
	// �������� �������� ������� ��� �����������
	virtual CString GetProperties(void);
	// �������������� ��������� �������
	virtual void ModifyProperties(void);


	virtual void Serialize(CArchive& ar);
	DECLARE_SERIAL(C3DBox)
	// �������� a
	double m_a;
	// �������� b
	double m_b;
	// �������� c
	double m_c;
};

