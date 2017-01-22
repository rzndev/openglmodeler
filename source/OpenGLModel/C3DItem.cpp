// C3DItem.cpp: файл реализации
//

#include "stdafx.h"
#include "OpenGLModel.h"
#include "C3DItem.h"
// C3DItem

IMPLEMENT_SERIAL(C3DItem, CObject, 1 )

C3DItem::C3DItem()
: m_X(0)
, m_Y(0)
, m_Z(0)
, m_rX(0)
, m_rY(0)
, m_rZ(0)
, m_name(_T(""))
, m_color(0x00FFFFFF)
{
}

C3DItem::~C3DItem()
{
}


// функции-члены C3DItem

// сохранение состояния объекта
void C3DItem::Serialize(CArchive& ar)
{
	CObject::Serialize(ar);
	if (ar.IsStoring())
	{	// storing code
		ar << m_name << m_X << m_Y << m_Z << m_rX << m_rY << m_rZ << m_color;
	}
	else
	{	// loading code
		ar >> m_name >> m_X >> m_Y >> m_Z >> m_rX >> m_rY >> m_rZ >> m_color;
	}
}


// Отобразить объект на сцене
void C3DItem::Draw(void)
{
}


// Получить свойства объекта для отображения
CString C3DItem::GetProperties(void)
{
	CString parameters;
	CString val;
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
	parameters.Append(_T("\r\n"));

	parameters.Append(_T("rx="));
	val.Format(_T("%f"),m_rX);
	parameters.Append(val);
	parameters.Append(_T(" "));
	parameters.Append(_T("ry="));
	val.Format(_T("%f"),m_rY);
	parameters.Append(val);
	parameters.Append(_T(" "));

	parameters.Append(_T("rz="));
	val.Format(_T("%f"),m_rZ);
	parameters.Append(val);
	parameters.Append(_T("\r\ncolor="));
	val.Format(_T("%08X"),m_color);
	parameters.Append(val);
	return parameters;
}


// Модифицировать параметры объекта
void C3DItem::ModifyProperties(void)
{
}


// подготовить систему координат для отображения объекта
void C3DItem::PrepareCoords(void)
{
	glTranslatef(m_X, m_Y, m_Z);
	glRotatef(m_rX, 1.0f, 0.0f, 0.0f);
	glRotatef(m_rY, 0.0f, 1.0f, 0.0f);
	glRotatef(m_rZ, 0.0f, 0.0f, 1.0f);
}


// установить материал объекта
void C3DItem::PrepareMaterial(void)
{
	GLfloat r = 1.0; // красная составляющая цвета
	GLfloat g = 1.0; // зеленая составляющая цвета
	GLfloat b = 1.0; // синяя составляющая цвета

	r = (double)GetRValue(m_color) / 255.0;
	g = (double)GetGValue(m_color) / 255.0;
	b = (double)GetBValue(m_color) / 255.0;

	//r=0.0;
	//b=0.0;

	GLfloat no_mat[] = { 0.0, 0.0, 0.0, 1.0 };
    GLfloat mat_ambient[] = { 0.7, 0.7, 0.7, 1.0 };
    GLfloat mat_ambient_color[] = { 0.8, 0.8, 0.2, 1.0 };
    GLfloat mat_diffuse[] = { 0.1, 0.5, 0.8, 1.0 };
    GLfloat mat_specular[] = { 1.0, 1.0, 1.0, 1.0 };
    GLfloat no_shininess[] = { 0.0 };
    GLfloat low_shininess[] = { 5.0 };
    GLfloat high_shininess[] = { 100.0 };
    GLfloat mat_emission[] = {0.3, 0.2, 0.2, 0.0};

	mat_diffuse[0] = r;
	mat_diffuse[1] = g;
	mat_diffuse[2] = b;

	glMaterialfv(GL_FRONT, GL_AMBIENT, no_mat);
    glMaterialfv(GL_FRONT, GL_DIFFUSE, mat_diffuse);
    glMaterialfv(GL_FRONT, GL_SPECULAR, mat_specular);
    glMaterialfv(GL_FRONT, GL_SHININESS, low_shininess);
    glMaterialfv(GL_FRONT, GL_EMISSION, no_mat);

    //glMaterialfv(GL_FRONT, GL_AMBIENT, no_mat);
    //glMaterialfv(GL_FRONT, GL_DIFFUSE, mat_diffuse);
    //glMaterialfv(GL_FRONT, GL_SPECULAR, no_mat);
    //glMaterialfv(GL_FRONT, GL_SHININESS, no_shininess);
    //glMaterialfv(GL_FRONT, GL_EMISSION, mat_emission);
    
	//glMaterialfv(GL_FRONT, GL_AMBIENT, mat_ambient);
 //   glMaterialfv(GL_FRONT, GL_DIFFUSE, mat_diffuse);
 //   glMaterialfv(GL_FRONT, GL_SPECULAR, no_mat);
 //   glMaterialfv(GL_FRONT, GL_SHININESS, no_shininess);
 //   glMaterialfv(GL_FRONT, GL_EMISSION, mat_emission);
}
