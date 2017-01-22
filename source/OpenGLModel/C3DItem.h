#pragma once
#include <gl\GL.h>
#include <gl\GLU.h>
// �������� ������ ������� C3DItem

class C3DItem : public CObject
{
public:
	C3DItem();
	virtual ~C3DItem();
	virtual void Serialize(CArchive& ar);

	
	// ��������� ������� �� ��� X
	double m_X;
	// ��������� ������� �� ��� Y
	double m_Y;
	// ��������� ������� �� ��� Z
	double m_Z;
	// �������� ������� ������������ ��� X
	double m_rX;
	// �������� ������� ������������ ��� Y
	double m_rY;
	// �������� ������� ������������ ���������� Z
	double m_rZ;

	// Overridables

	// ���������� ������ �� �����
	virtual void Draw(void);
	// �������� �������� ������� ��� �����������
	virtual CString GetProperties(void);
	// �������������� ��������� �������
	virtual void ModifyProperties(void);
	// ��� �������
	CString m_name;

	// ����������� ������� ��������� ��� ����������� �������
	void PrepareCoords(void);
	// ���������� �������� �������
	void PrepareMaterial(void);
	// ���� �������
	DWORD m_color;
	DECLARE_SERIAL(C3DItem)	
};


