#include "StdAfx.h"
#include "C3DSphere.h"
#include "Shapes.h"

IMPLEMENT_SERIAL(C3DSphere, C3DItem, 1)

C3DSphere::C3DSphere(void)
: m_r(0)
, m_slices(0)
, m_stacks(0)
{
}


C3DSphere::~C3DSphere(void)
{
}


void C3DSphere::Serialize(CArchive& ar)
{
	C3DItem::Serialize(ar);
	if (ar.IsStoring())
	{	// storing code
		ar << m_r << m_slices << m_stacks;
	}
	else
	{	// loading code
		ar >> m_r >> m_slices >> m_stacks;
	}
}


// Отобразить объект на сцене
void C3DSphere::Draw(void)
{
	  CShapes shape; // для отображения испольузем класс, содержащий набор команд отображения примитивов
	  shape.Sphere(m_r, m_slices, m_stacks);
};

// Получить свойства объекта для отображения
CString C3DSphere::GetProperties(void)
{
		CString val;
		CString parameters;

		parameters.Append(_T("Имя: <"));
		parameters.Append(m_name);
		parameters.Append(_T(">\r\n"));

		parameters.Append(_T("x="));
		val.Format(_T("%f"),m_X);
		parameters.Append(val);
		parameters.Append(_T(" "));
		parameters.Append(_T("y="));
		val.Format(_T("%f"),m_Y);
		parameters.Append(val);
		parameters.Append(_T(" "));

		parameters.Append(_T("z="));
		val.Format(_T("%f"),m_Z);
		parameters.Append(val);
		parameters.Append(_T("\r\ncolor="));
	    val.Format(_T("%08X"),m_color);
	    parameters.Append(val);

		parameters.Append(_T("\r\n"));
		parameters.Append(_T("r="));
		val.Format(_T("%f"),m_r);
		parameters.Append(val);
		parameters.Append(_T(" "));
		parameters.Append(_T("slices="));
		val.Format(_T("%d"),m_slices);
		parameters.Append(val);
		parameters.Append(_T("\r\n"));

		parameters.Append(_T("stacks="));
		val.Format(_T("%d"),m_stacks);
		parameters.Append(val);
		parameters.Append(_T("\r\n"));
		return parameters;
};
// Модифицировать параметры объекта
void C3DSphere::ModifyProperties(void)
	{
};