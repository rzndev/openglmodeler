#pragma once
#include "c3ditem.h"
class C3DBox :
	public C3DItem
{
public:
	C3DBox(void);
	virtual ~C3DBox(void);

	// Отобразить объект на сцене
	virtual void Draw(void);
	// Получить свойства объекта для отображения
	virtual CString GetProperties(void);
	// Модифицировать параметры объекта
	virtual void ModifyProperties(void);


	virtual void Serialize(CArchive& ar);
	DECLARE_SERIAL(C3DBox)
	// параметр a
	double m_a;
	// параметр b
	double m_b;
	// параметр c
	double m_c;
};

