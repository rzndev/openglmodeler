#pragma once

// C3DScene ������ ������������ �����
#include "C3DItem.h"
#include "C3DBox.h"
#include "C3DPyramid.h"
#include "C3DSphere.h"
#include "C3DScene.h"



class C3DScene : public CObject
{
public:
	C3DScene();
	virtual ~C3DScene();
	DECLARE_SERIAL(C3DScene)
	virtual void Serialize(CArchive& ar);
	// �������� �� ����� ��������������
	void AddBox(C3DBox* box);
	// ������� �� ����� ������
	void RemoveObject(int idx);
	// �������� ������ ����� ������
	C3DBox* AddBoxViaDialog(void);
	// ����� �������� �� �����
	CArray<C3DItem*, C3DItem*> m_object_list;
	// ������������ ��������, ���������� �������
	void Clear(void);
	// �������������� ��������� �������
	C3DItem* ModifyObject(int idx);
	// ���������� �����
	void Draw(void);
	// �������� �� ����� ��������
	void AddPyramid(C3DPyramid* pyramid);
	// �������� �������� ����� ������
	C3DPyramid* AddPyramidViaDialog(void);
	// �������� ��� �� �����
	void AddSphere(C3DSphere* sphere);
	// �������� ��� ����� ������
	C3DSphere* AddSphereViaDialog(void);
};


