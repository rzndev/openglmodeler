// C3DScene.cpp: ���� ����������
//

#include "stdafx.h"

#include <gl\GL.h>
#include <gl\GLU.h>
#include "OpenGLModel.h"
#include "C3DScene.h"

#include "BoxProperties.h"
#include "SphereProperties.h"

// C3DScene

IMPLEMENT_SERIAL(C3DScene, CObject,1)

C3DScene::C3DScene()
{
}

C3DScene::~C3DScene()
{
	Clear();
}


// �������-����� C3DScene


void C3DScene::Serialize(CArchive& ar)
{
	int nElems; // ������� ������� �������
	int i; // ��������������� ����������
	int kind_object; // ��� �������
	CObject::Serialize(ar);
	if (ar.IsStoring())
	{	// storing code
		nElems = m_object_list.GetUpperBound(); 
		ar << nElems;
		for(i = 0; i <= nElems; i++)
		{
		   C3DItem* obj = m_object_list.GetAt(i);
		   kind_object = 0; // ������ �� ������������ ����������
		   if (obj->IsKindOf(RUNTIME_CLASS(C3DBox))) kind_object = 1;
		   if (obj->IsKindOf(RUNTIME_CLASS(C3DPyramid))) kind_object = 2;
		   if (obj->IsKindOf(RUNTIME_CLASS(C3DSphere))) kind_object = 3;
		   ar << kind_object;
		   obj->Serialize(ar);
		}
	}
	else
	{	
		ar >> nElems;
		for(i = 0; i <= nElems; i++)
		{
		   C3DBox* box = NULL; // ��������������
		   C3DPyramid* pyramid = NULL; // ��������
		   C3DSphere* sphere = NULL; // ���
		   ar >> kind_object;
		   if (0 == kind_object) continue; // ���� ������ �� ������������ ���������� - ���������� ����
		   switch(kind_object)
		   {
		   case 1: // ��������������
			   box = new C3DBox();
			   box->Serialize(ar);
			   m_object_list.Add(box);
			   break;
		   case 2: // ��������
			   pyramid = new C3DPyramid();
			   pyramid->Serialize(ar);
			   m_object_list.Add(pyramid);
			   break;
		   case 3: // ���
			   sphere = new C3DSphere();
			   sphere->Serialize(ar);
			   m_object_list.Add(sphere);
			   break;
		   }
		}
	}
}


// �������� �� ����� ��������������
void C3DScene::AddBox(C3DBox* box)
{
	m_object_list.Add(box);
}


// ������� �� ����� ��������������
void C3DScene::RemoveObject(int idx)
{
	if (idx < 0) return;
	if (idx > m_object_list.GetUpperBound()) return;
	C3DItem* obj = m_object_list.GetAt(idx);
	delete obj;
	m_object_list.RemoveAt(idx);
}


// �������� �������������� ����� ������
C3DBox* C3DScene::AddBoxViaDialog(void)
{
	C3DBox* box = NULL;
	CBoxProperties propDlg;
	if (propDlg.DoModal() == IDOK)
	{
		box = new C3DBox();
		box->m_X = propDlg.m_x;
		box->m_Y = propDlg.m_y;
		box->m_Z = propDlg.m_z;
		box->m_rX = propDlg.m_rx;
		box->m_rY = propDlg.m_ry;
		box->m_rZ = propDlg.m_rz;
		box->m_a = propDlg.m_a;
		box->m_b = propDlg.m_b;
		box->m_c = propDlg.m_c;
		box->m_name = propDlg.m_name;
		box->m_color = propDlg.m_color;
		AddBox(box);
	}
	return box;
}


// ������������ ��������, ���������� �������
void C3DScene::Clear(void)
{
	int nElems = m_object_list.GetUpperBound(); // ������� ������� �������
	int i; // ��������������� ����������
	for(i = 0; i <= nElems; i++)
	{
		C3DItem* obj = m_object_list.GetAt(i);
	   delete obj;
	}
	m_object_list.RemoveAll();
}


// �������������� ��������� �������
C3DItem* C3DScene::ModifyObject(int idx)
{
	C3DItem* item = NULL;
	if (idx < 0) return item;
	if (idx > m_object_list.GetUpperBound()) return item;
	item = m_object_list.GetAt(idx);
	if (NULL == item) return item;
	if (item->IsKindOf(RUNTIME_CLASS(C3DBox)))
	{
		// ���������� ��������� ��� ���������������
		CBoxProperties propDlg;
		C3DBox* box = reinterpret_cast<C3DBox*>(item);
		propDlg.m_x = box->m_X;
		propDlg.m_y = box->m_Y;
		propDlg.m_z = box->m_Z;
		propDlg.m_rx = box->m_rX;
		propDlg.m_ry = box->m_rY;
		propDlg.m_rz = box->m_rZ;
		propDlg.m_a = box->m_a;
		propDlg.m_b = box->m_b;
		propDlg.m_c = box->m_c;
		propDlg.m_name = box->m_name;
		propDlg.m_color = box->m_color;
		if (propDlg.DoModal() == IDOK)
		{
			box->m_X = propDlg.m_x;
			box->m_Y = propDlg.m_y;
			box->m_Z = propDlg.m_z;
			box->m_rX = propDlg.m_rx;
			box->m_rY = propDlg.m_ry;
			box->m_rZ = propDlg.m_rz;
			box->m_a = propDlg.m_a;
			box->m_b = propDlg.m_b;
			box->m_c = propDlg.m_c;
			box->m_name = propDlg.m_name;
			box->m_color = propDlg.m_color;
		}
	}

	if (item->IsKindOf(RUNTIME_CLASS(C3DPyramid)))
	{
		// ���������� ��������� ��� ���������
		CBoxProperties propDlg;
		C3DPyramid* pyramid = reinterpret_cast<C3DPyramid*>(item);
		propDlg.SetTtitle(_T("��������� ��������"));
		propDlg.m_x = pyramid->m_X;
		propDlg.m_y = pyramid->m_Y;
		propDlg.m_z = pyramid->m_Z;
		propDlg.m_rx = pyramid->m_rX;
		propDlg.m_ry = pyramid->m_rY;
		propDlg.m_rz = pyramid->m_rZ;
		propDlg.m_a = pyramid->m_a;
		propDlg.m_b = pyramid->m_b;
		propDlg.m_c = pyramid->m_c;
		propDlg.m_name = pyramid->m_name;
		propDlg.m_color = pyramid->m_color;
		if (propDlg.DoModal() == IDOK)
		{
			pyramid->m_X = propDlg.m_x;
			pyramid->m_Y = propDlg.m_y;
			pyramid->m_Z = propDlg.m_z;
			pyramid->m_rX = propDlg.m_rx;
			pyramid->m_rY = propDlg.m_ry;
			pyramid->m_rZ = propDlg.m_rz;
			pyramid->m_a = propDlg.m_a;
			pyramid->m_b = propDlg.m_b;
			pyramid->m_c = propDlg.m_c;
			pyramid->m_name = propDlg.m_name;
			pyramid->m_color = propDlg.m_color;
		}
	}

	if (item->IsKindOf(RUNTIME_CLASS(C3DSphere)))
	{
		// ���������� ��������� ��� ���������
		CSphereProperties propSphereDlg;
		C3DSphere* sphere = reinterpret_cast<C3DSphere*>(item);
		propSphereDlg.m_x = sphere->m_X;
		propSphereDlg.m_y = sphere->m_Y;
		propSphereDlg.m_z = sphere->m_Z;
		propSphereDlg.m_r = sphere->m_r;
		propSphereDlg.m_slices = sphere->m_slices;
		propSphereDlg.m_stacks = sphere->m_stacks;
		propSphereDlg.m_name = sphere->m_name;
		propSphereDlg.m_color = sphere->m_color;
		if (propSphereDlg.DoModal() == IDOK)
		{
			sphere->m_X = propSphereDlg.m_x;
			sphere->m_Y = propSphereDlg.m_y;
			sphere->m_Z = propSphereDlg.m_z;
			sphere->m_r = propSphereDlg.m_r;
			sphere->m_slices = propSphereDlg.m_slices;
			sphere->m_stacks = propSphereDlg.m_stacks;
			sphere->m_name = propSphereDlg.m_name;
			sphere->m_color = propSphereDlg.m_color;
		}
	}

	return item;
}


// ���������� �����
void C3DScene::Draw(void)
{
	int nElems = m_object_list.GetUpperBound(); // ������� ������� �������
	int i; // ��������������� ����������
	for(i = 0; i <= nElems; i++)
	{
	   C3DItem* obj = m_object_list.GetAt(i);
	   glPushMatrix();
	   obj->PrepareCoords(); // ������ ������������ �������
	   obj->PrepareMaterial(); // ������ �������� ��������� �������
	   obj->Draw(); // ����������� �������
	   glPopMatrix();
	}
}


// �������� �� ����� ��������
void C3DScene::AddPyramid(C3DPyramid* pyramid)
{
	m_object_list.Add(pyramid);
}


// �������� �������� ����� ������
C3DPyramid* C3DScene::AddPyramidViaDialog(void)
{
	C3DPyramid* pyramid = NULL;
	CBoxProperties propDlg;
	propDlg.SetTtitle(_T("��������� ��������"));
	if (propDlg.DoModal() == IDOK)
	{
		pyramid = new C3DPyramid();
		pyramid->m_X = propDlg.m_x;
		pyramid->m_Y = propDlg.m_y;
		pyramid->m_Z = propDlg.m_z;
		pyramid->m_rX = propDlg.m_rx;
		pyramid->m_rY = propDlg.m_ry;
		pyramid->m_rZ = propDlg.m_rz;
		pyramid->m_a = propDlg.m_a;
		pyramid->m_b = propDlg.m_b;
		pyramid->m_c = propDlg.m_c;
		pyramid->m_name = propDlg.m_name;
		pyramid->m_color = propDlg.m_color;
		pyramid->m_color = propDlg.m_color;
		AddPyramid(pyramid);
	}
	return pyramid;
}


// �������� ��� �� �����
void C3DScene::AddSphere(C3DSphere* sphere)
{
	m_object_list.Add(sphere);
}


// �������� ��� ����� ������
C3DSphere* C3DScene::AddSphereViaDialog(void)
{
	C3DSphere* sphere = NULL;
	CSphereProperties propDlg;
	if (propDlg.DoModal() == IDOK)
	{
		sphere = new C3DSphere();
		sphere->m_X = propDlg.m_x;
		sphere->m_Y = propDlg.m_y;
		sphere->m_Z = propDlg.m_z;
		sphere->m_rX = 0.0;
		sphere->m_rY = 0.0;
		sphere->m_rZ = 0.0;
		sphere->m_r = propDlg.m_r;
		sphere->m_slices = propDlg.m_slices;
		sphere->m_stacks = propDlg.m_stacks;
		sphere->m_name = propDlg.m_name;
		AddSphere(sphere);
	}
	return sphere;
}
