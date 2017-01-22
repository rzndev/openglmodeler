#include "StdAfx.h"

#include <gl/GL.h>
#include <gl/GLU.h>
#include "C3DBox.h"
#include "Shapes.h"


IMPLEMENT_SERIAL(C3DBox, C3DItem, 1)

C3DBox::C3DBox(void)
: m_a(0)
, m_b(0)
, m_c(0)
{
}


C3DBox::~C3DBox(void)
{
}


void C3DBox::Serialize(CArchive& ar)
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
void C3DBox::Draw(void)
{
	  CShapes shape; // для отображения испольузем класс, содержащий набор команд отображения примитивов
	  GLfloat size = 1;
	  glScalef(m_a, m_b, m_c);
	  shape.Box(1);
};

// Получить свойства объекта для отображения
CString C3DBox::GetProperties(void)
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
void C3DBox::ModifyProperties(void)
	{
};
