#pragma once
#include "c3ditem.h"
class C3DSphere :
	public C3DItem
{
public:
	C3DSphere(void);
	virtual ~C3DSphere(void);
	virtual void Serialize(CArchive& ar);
	// ���������� ������ �� �����
	virtual void Draw(void);
	// �������� �������� ������� ��� �����������
	virtual CString GetProperties(void);
	// �������������� ��������� �������
	virtual void ModifyProperties(void);


	DECLARE_SERIAL(C3DSphere)
	// ������ �����
	double m_r;
	// ���������� ������� ������ ��� oZ
	int m_slices;
	// ���������� ������� ����� ��� oZ
	int m_stacks;
};

