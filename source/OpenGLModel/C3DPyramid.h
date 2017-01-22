#pragma once
#include "c3ditem.h"
class C3DPyramid :
	public C3DItem
{
public:
	C3DPyramid(void);
	virtual ~C3DPyramid(void);
	virtual void Serialize(CArchive& ar);

	// Отобразить объект на сцене
	virtual void Draw(void);
	// Получить свойства объекта для отображения
	virtual CString GetProperties(void);
	// Модифицировать параметры объекта
	virtual void ModifyProperties(void);

	DECLARE_SERIAL(C3DPyramid)
	// параметр a
	double m_a;
	// параметр b
	double m_b;
	// параметр c
	double m_c;

};

