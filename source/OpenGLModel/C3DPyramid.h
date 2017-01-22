#pragma once
#include "c3ditem.h"
class C3DPyramid :
	public C3DItem
{
public:
	C3DPyramid(void);
	virtual ~C3DPyramid(void);
	virtual void Serialize(CArchive& ar);

	// ���������� ������ �� �����
	virtual void Draw(void);
	// �������� �������� ������� ��� �����������
	virtual CString GetProperties(void);
	// �������������� ��������� �������
	virtual void ModifyProperties(void);

	DECLARE_SERIAL(C3DPyramid)
	// �������� a
	double m_a;
	// �������� b
	double m_b;
	// �������� c
	double m_c;

};

