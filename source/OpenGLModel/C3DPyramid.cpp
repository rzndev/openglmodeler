#include "StdAfx.h"
#include "C3DPyramid.h"

#include <math.h>
#include "Shapes.h"

IMPLEMENT_SERIAL(C3DPyramid, C3DItem, 1)


C3DPyramid::C3DPyramid(void)
: m_a(0)
, m_b(0)
, m_c(0)
{
}


C3DPyramid::~C3DPyramid(void)
{
}


void C3DPyramid::Serialize(CArchive& ar)
{
	C3DItem::Serialize(ar);
	if (ar.IsStoring())
	{	// storing code
		ar << m_a << m_b << m_c;
	}
	else
	{	// loading code
		ar >> m_a >> m_b >> m_c;
	}
}

// Отобразить объект на сцене
void C3DPyramid::Draw(void)
{
	CShapes shape; // подключаем класс, содержащий отображаемые формы
	glScalef(m_a, m_b, m_c);
	shape.Pyramid(GL_TRIANGLES);
};

// Получить свойства объекта для отображения
CString C3DPyramid::GetProperties(void)
	{
		CString val;
		CString parameters = C3DItem::GetProperties();
		parameters.Append(_T("\r\n"));
		parameters.Append(_T("a="));
		val.Format(_T("%f"),m_a);
		parameters.Append(val);
		parameters.Append(_T(" "));
		parameters.Append(_T("b="));
		val.Format(_T("%f"),m_b);
		parameters.Append(val);
		parameters.Append(_T(" "));

		parameters.Append(_T("c="));
		val.Format(_T("%f"),m_c);
		parameters.Append(val);
		parameters.Append(_T("\r\n"));
		return parameters;
};
// Модифицировать параметры объекта
void C3DPyramid::ModifyProperties(void)
	{
};


